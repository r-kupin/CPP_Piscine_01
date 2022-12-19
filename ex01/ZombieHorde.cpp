/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:15:08 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:15:09 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
		Description
 	When writing a C++ code it is a GOOD idea to use C++ approach, and not C.
 	C++ is about objects and their methods, that make code more reader-friendly.
	It is weird that task says: "Remember: You are coding in C++ now, not in C anymore."
	And then enforces us to use plain C way.

	- Pointers
 		There are TONNS of articles on why one SHOULD NOT USE C-pointers in C++
			All it boils down to the conclusion that raw(C-style) pointers are
			too general, too low-level, too unsafe and hard-to-deal-with.
		In particular, C++ has higher level abstractions and other features that
			you should use in place of pointers much of the time:
    			References, including const references.
    			Iterators.
    			Smart pointers.
    			Standard containers.
    			Move semantics.
    			Lambdas with captures.
    			As of C++20: Ranges.
		Yes, many of these use pointers under the hood. Your program, however,
		doesn't see them.

		Raw pointers must under no circumstances own memory.
			Here, “own memory” essentially means that at some point delete is
			called on that pointer (but it’s more general than that). This
			statement can safely be taken as an absolute. The only exception is
			when implementing your own smart pointer (or other memory management
			strategy). And even there you should normally still use a smart
			pointer at low level.
			The rationale for this is quite simple: raw pointers which own
			memory introduce a source of error. And these errors are prolific in
			existing software: memory leaks and double deletion – both a direct
			consequence of unclear resource ownership (but going in opposite
			direction).
			This problem can be entirely eliminated, at virtually no cost, by
			simply using smart pointers instead of raw pointers (caveat: this
			still requires thinking, of course; shared pointers can lead to
			cycles and thus once again to memory leaks – but this is easily
			avoidable).
    	Most uses of pointers in C++ are unnecessary.
			Unlike other languages, C++ has very strong support for value
			semantics and simply doesn’t need the indirection of pointers.
			This wasn’t immediately realised – historically, C++ was invented
			to facilitate easy object orientation in C, and relied heavily on
			constructing object graphs which were connected by pointers. But in
			modern C++, this paradigm is rarely the best choice, and modern C++
			idioms often don’t need pointers at all. They operate on values
			rather than pointers.

		So, YES, pointer do exist in C++, and they have their place, but
			NO, it is not used for merely anything like in C, but for some very
				specific low-level trickery.

	- C-arrays vs std::vector / std::array
 		From Bjarne Stroustrup's FAQ page:
	In terms of time and space, an array is just about the optimal construct for
 	accessing a sequence of objects in memory. It is, however, also a very low
 	level data structure with a vast potential for misuse and errors and in
 	essentially all cases there are better alternatives. By "better" I mean
 	easier to write, easier to read, less error prone, and as fast.
		The two fundamental problems with arrays are that
			an array doesn't know its own size
			the name of an array converts to a pointer to its first element at
				the slightest provocation
	Also: when creating the array of objects it is impossible to use any
 		non-default constructor,that leads us to the need of assigning the fields
 		afterwards, that consequently leads us to follow the one of the wrong ways
 		that violate the OOP incapsulation principle:
 			expose fields or create a set-method.
				--------------
 	So, basically - use std::vector as a general case, or std::array if you really
 	want, and if it's size is known at the compile time

 	- Heap vs Stack allocation
		Again, after a multiple articles on that topic I came to the conclusion
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
				Like in C we ran write:
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

#include <vector>
#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie *zombies  = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		zombies[i].SetName(name + " #" + std::to_string(i));/* ugly as hell */
	}
	return zombies;
}

// as far as $name is copied anyways - we can just move it
// vector initializing with creating an object, and then filling the vector
// with copies of this object. Then object gets discarded.
std::vector<Zombie> Zombie:: ZombieHordeAsItShouldBe(int N, std::string name) {
	return (std::vector<Zombie> (N, Zombie(std::move(name))));
}

