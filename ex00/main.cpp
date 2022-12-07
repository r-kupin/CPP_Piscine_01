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
/*
		Google C++ Style Guide

 		REFERENCES VS POINTERS
	- Use references when you can, and pointers when you have to.
	- References are usually preferred over pointers whenever you don't need
		"reseating". This usually means that references are most useful in a
		class's public interface. References typically appear on the skin of an
		object, and pointers on the inside.
	- The exception to the above is where a function's parameter or return
		value needs a "sentinel" reference — a reference that does not refer to
		an object. This is usually best done by returning/taking a pointer, and
		giving the NULL pointer this special significance (references must
		always alias objects, not a dereferenced NULL pointer).

		Description

	1.  std::move
 			constexpr std::remove_reference_t<T>&& move( T&& t ) noexcept;
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
				Zombie::Zombie(std::string name): name(std::move(name)) {};
					*GOOD* - std::move() doesn't actually move anything.
					It changes an expression from being an lvalue (such as a
					named variable) to being an xvalue. An xvalue tells the
					compiler: You can plunder me, move anything I'm holding and
					use it elsewhere (since I'm going to be destroyed soon
					anyway)". in other words, when you use std::move(x), you're
					allowing the compiler to cannibalize x. Thus if x has, say,
					its own buffer in memory - after std::move()ing the compiler
					can reassign it to specified object.
*/

#include "Zombie.hpp"

int main(){
	const std::string kZombieName = "Andy";
	std::string ZombieNameThatWeWillNeverNeedAfterwards = "Danny";

	/* stack-allocated */
	//	COPY constructor is used, cause constant is an lvalue and can't be converted
	//	with move() - it will cause a compile-time error
	Zombie AndyTheZombie(kZombieName);
	AndyTheZombie.announce();
	//	MOVE constructor is used, cause non-constant lvalue is explicitly converted
	//	with move() - which allows us to avoid copying
	Zombie DannyTheZombie(std::move(ZombieNameThatWeWillNeverNeedAfterwards));
	DannyTheZombie.announce();
	//	MOVE constructor is used, cause "Berty" is a temporary, so is an rvalue
	//	by default
	Zombie BertyTheTempValueNamedZombie("Berty");
	BertyTheTempValueNamedZombie.announce();

	std::string NonConstantZombieName = "Johny";

	/* heap-allocated */
	Zombie *JohnyTheHeapOne = Zombie::newZombie(NonConstantZombieName);
	JohnyTheHeapOne->announce();

//	we can still use it!
	NonConstantZombieName = "Billy";

	/* stack-allocated and removed right afterwards*/
	Zombie::randomChump(NonConstantZombieName);

	/* basically, like a free() */
	delete(JohnyTheHeapOne);
	return (0);
}
