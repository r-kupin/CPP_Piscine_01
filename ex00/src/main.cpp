/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:11:54 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:11:55 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
		Google C++ Style Guide

 		REFERENCES VS POINTERS
	- Use references when you can, and pointers when you have to.
	- References are usually preferred over pointers whenever you don't need
		"reseating". This usually means that references are most useful in a
		class's public interface. References typically appear on the skin of an
		object, and pointers on the inside.

		Description

		C++ Move and Copy Arguments Explained:

    Copy: When you pass an object as an argument to a function, a copy of the
    object is made. This can be inefficient for large objects, as it
    duplicates data.

    Move: Move semantics allow transferring ownership of resources (like
    memory) from one object to another efficiently, without duplicating data.
    This is particularly useful for temporary or about-to-be-discarded objects.

    R-Value and L-Value: R-value refers to temporary values (like constants
    or results of expressions). L-value refers to values that have an
    identifiable memory location (like variables). R-value references (&&)
    are used for move semantics, while l-value references (&) are used for
    regular copying.

    std::move(): std::move() is used to indicate that an object should be
    treated as an r-value, enabling move semantics. It doesn't actually move
    anything; it just casts an l-value into an r-value reference.

    Copy Constructors and Move Constructors: Objects can have both copy
    constructors (for regular copying) and move constructors (for efficient
    transferring of resources).

    Copy Assignment and Move Assignment: Similar to constructors, objects can
    have copy assignment operators (for regular assignment) and move
    assignment operators (for efficient resource transfer).

		std::move constexpr std::remove_reference_t<T>&& move( T&& t ) noexcept;

 	Is used to indicate that an object t may be "moved from", i.e. allowing
 	the efficient transfer of resources from t to another object. It is
 	widely used to initialize non-primitive value from an existing rvalue,
 	similar to creating an object with move-constructor
 			Use:
				 Zombie zombie("Andy");
 			Implementation examples:
 				 Zombie::Zombie(std::string name): name_(name){};
 					*BAD* - the "name" is allocated, then name's content
					is copied to it, then "Andy" rvalue gets destroyed.
				 Zombie::Zombie(std::string name): name(std::move(name)){};
					*GOOD* - std::move() doesn't actually move anything.
					It changes an expression from being an lvalue (such as a
					named variable) to being an xvalue. An xvalue tells the
					compiler: You can plunder me, move anything I'm holding and
					use it elsewhere (since I'm going to be destroyed soon
					anyway)". in other words, when you use std::move(x), you're
					allowing the compiler to cannibalize x. Thus if x has, say,
					its own buffer in memory - after std::move()ing the compiler
					can reassign it to specified object.

	Heap vs Stack allocation
		After a multiple articles on that topic I came to the conclusion
		that as a general case it is preferable to use stack because:
		    First, the obvious, and less important one: Heap allocations are
		    	slow. Stack allocations are fast.
    		Second, and much more important is RAII. Because the stack-allocated
    			version is automatically cleaned up, it is useful. Its destructor
    			is automatically called, which allows you to guarantee that any
    			resources allocated by the class get cleaned up. This is essentialy
    			how you avoid memory leaks in C++. You avoid them by never calling
    			delete yourself, instead wrapping it in stack-allocated objects which
    			call delete internally, typicaly in their destructor.
			Third - Return value optimization.
				Quite a complicated thing to explain, but it basically allows to
				return locally(stack)-allocated object or temporary.
				Like in C we can write:
				int val = 5;
					return(val);
					or
					return(5);
				In C++ we can write:
				return (Object(" Yo, Im on a stack ;D "));
				Which is a cleaner way that dealing with "return arguments";

		In contrary, stack size is limited to a few Mb's so it is better to use
			a heap for a really large objects, or when dealing with recursion

 	So as a general case - it is better to use stack as a general case, unless
 		you want to do some trickery such as change size of the variable(nasty),
 		or have a manual control of the allocated memory's lifetime(also nasty),
 		or to store really big chunks of data (ok, but rarely needed).
*/

#include "Zombie.hpp"

int main(){
////    -------------------- /* mandatory */
//    /**	@brief directly stack-allocated with copy-constructor
//     *	stack-allocated	COPY-ARG constructor is used, cause constant is an
//     *	lvalue and can't be converted with move() - it will cause a
//     *	compile-time error
//     */
    const std::string kZombieName = "Andy";
    Zombie AndyTheZombie(kZombieName);
	AndyTheZombie.announce();
//
////    -------------------- /* copy semantics */
    Zombie AndyTheClonedZombie(AndyTheZombie);
    AndyTheClonedZombie.announce();

//    -------------------- /* move(lvalue) semantics */
	/** @brief directly stack-allocated with move-constructor
	 *	MOVE-ARG constructor is used, cause non-constant lvalue is explicitly
	 *	converted with move() - which allows us to avoid copying
	 */
//  std::string ZombieNameThatWeWillNeverNeedAfterwards = "Danny";
//	Zombie DannyTheZombie(std::move(ZombieNameThatWeWillNeverNeedAfterwards));
//	DannyTheZombie.announce();

//    -------------------- /* move-arg - explicit rvalue semantics */
	/** @brief directly stack-allocated with move-constructor
	 *	MOVE-ARG constructor is used, cause "Berty" is a temporary, so is an
	 *	rvalue by default
	 */
//  Zombie JimmyTheZombie("Jimmy");
//	Zombie NewJimmyMadeFromTheOldOne(std::move(JimmyTheZombie));
//	NewJimmyMadeFromTheOldOne.announce();

	std::string NonConstantZombieName = "Johny";

	/* heap-allocated */
	Zombie *JohnyTheHeapOne = Zombie::newZombie(NonConstantZombieName);
	JohnyTheHeapOne->announce();

	/* we can still use it! */
	NonConstantZombieName = "Billy";

	/* stack-allocated and removed right afterwards*/
	Zombie::randomChump(NonConstantZombieName);

	/* basically, like a free() */
	delete(JohnyTheHeapOne);
	return (0);
}
