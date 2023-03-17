/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:16:08 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:16:09 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
		Description
	So, basically, it is all about showing a difference between the pointer and
 	a reference. Here's what stackoverflow says about that:
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
#include <string>
#include <iostream>

int main() {
	const std::string kString = "HI THIS IS BRAIN";
	const std::string& kReferenceString = kString;
	const std::string *ptr_string = &kString;

	std::cout << "string itself: " << kString << std::endl;
	std::cout << "reference to the string: " << kReferenceString << std::endl;
	std::cout << "pointer value of the string: " << *ptr_string << std::endl;
	std::cout << "pointer address of the string: " << ptr_string << std::endl;

	return 0;
}
