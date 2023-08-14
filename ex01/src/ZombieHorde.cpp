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
/**
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
			existing software: memory leaks and double deletion – both a direct
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
			This wasn’t immediately realised – historically, C++ was invented
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
*/

#include <vector>
#include <sstream>
#include "Zombie.hpp"

    /* ugly as hell */
Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie *zombies  = new Zombie[N];

	std::stringstream ss;
	for (int i = 0; i < N; ++i, ss.str("")) {
		ss << i;
		zombies[i].SetName(name + " #" + ss.str());
	}
	return zombies;
}

/** as far as @param name is copied anyways - we can just move it
 * vector initializing with creating an object, and then filling the vector
 * with copies of this object. Then object gets discarded.
 */
//std::vector<Zombie> Zombie:: ZombieHordeAsItShouldBe(int N, std::string name) {
//	return (std::vector<Zombie> (N, Zombie(std::move(name))));
//}

