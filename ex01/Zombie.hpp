/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:12:00 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:12:01 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
		Google C++ Style Guide
	- A class's public API must make clear whether the class is copyable,
 		move-only, or neither copyable nor movable. Support copying and/or moving
 		if these operations are clear and meaningful for your type.
 	- Use of const
 		We strongly recommend using const in APIs (i.e., on function parameters,
 		methods, and non-local variables) wherever it is meaningful and accurate.
 		This provides consistent, mostly compiler-verified documentation of what
 		objects an operation can mutate. Having a consistent and reliable way to
 		distinguish reads from writes is critical to writing thread-safe code,
 		and is useful in many other contexts as well. In particular:
	    	If a function guarantees that it will not modify an argument passed
	    		by reference or by pointer, the corresponding function parameter
	    		should be a reference-to-const (const T&) or pointer-to-const
	    		(const T*), respectively.
    		For a function parameter passed by value, const has no effect on the
	    		caller, thus is not recommended in function declarations.
    		Declare methods to be const unless they alter the logical state of
    			the object (or enable the user to modify that state, e.g., by
    			returning a non-const reference, but that's rare), or they can't
    			safely be invoked concurrently.


 		Description
	- & - Specifies, that given argument must be an lvalue reference.
 		Constructor that uses &-argument is called "Copy constructor", only
 		once copies resources on which an lvalue-reference points to, and
 		assigns them to the object variable without touching the source
	- && - Specifies, that given argument must be an rvalue reference.
 		Constructor that uses &&-argument is called "Move constructor",  enables
 		the resources owned by an rvalue object to be moved into an lvalue
 		without copying.
	- const - after the method name states that it is functionally pure - has no
 		side-effects, which particularly means that it does not change the class's
 		internal state.
*/
#ifndef EX00_ZOMBIE_H_
#define EX00_ZOMBIE_H_

#include <string>
#include <vector>

class Zombie{
	public:
		explicit Zombie(const std::string& name);	/* lvalue arg-copy constructor */
		explicit Zombie(std::string&& name);		/* rvalue arg-move constructor */
		Zombie(const Zombie& zombie);				/* actually copy constructor */

		Zombie();
		~Zombie();

		static Zombie*	zombieHorde( int N, std::string name );
		static std::vector<Zombie> ZombieHordeAsItShouldBe(int N, std::string name);

		void	announce() const;
		void	SetName(const std::string &name);
	private:
		static int zombies_created_;

		std::string name_;
		int 		id_;
};

#endif //EX00_ZOMBIE_H_