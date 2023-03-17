/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:17:11 by rokupin           #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
		Description
	So, basically, it is all about showing a difference between the pointer and
 	a reference. Especially, #4!  Here's what stackoverflow says about that:
	1. A pointer can be re-assigned but reference cannot be re-bound, and must
 		be bound at initialization
	2. A pointer variable has its own identity: a distinct, visible memory
 		address that can be taken with the unary & operator and a certain amount
 		of space that can be measured with the sizeof operator. Using those
 		operators on a reference returns a value corresponding to whatever the
 		reference is bound to; the reference’s own address and size are
 		invisible. Since the reference assumes the identity of the original
 		variable in this way, it is convenient to think of a reference as another
 		name for the same variable.
	3. You can have arbitrarily nested pointers to pointers offering extra
 		levels of indirection. References only offer one level of indirection.
	4. A pointer can be assigned nullptr, whereas a reference must be bound to
 		an existing object. If you try hard enough, you can bind a reference to
 		nullptr, but this is undefined and will not behave consistently.
	5. A pointer needs to be dereferenced with * to access the memory location
 		it points to, whereas a reference can be used directly. A pointer to a
 		class/struct uses '->' to access its members whereas a reference uses a '.'
	6. References cannot be put into an array, whereas pointers can be
	7. Const references can be bound to temporaries. Pointers cannot. This makes
		const & more convenient to use in argument lists and so forth
*/

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}