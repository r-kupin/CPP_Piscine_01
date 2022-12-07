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

 		Description
	- & - Specifies, that given argument must be an lvalue reference.
 		Constructor that uses &-argument is called "Copy constructor", only
 		once copies resources on which an lvalue-reference points to, and
 		assigns them to the object variable without touching the source
	- && - Specifies, that given argument must be an rvalue reference.
 		Constructor that uses &&-argument is called "Move constructor",  enables
 		the resources owned by an rvalue object to be moved into an lvalue
 		without copying
*/
#ifndef EX00_ZOMBIE_H_
#define EX00_ZOMBIE_H_

#include <string>

class Zombie{
	public:
		explicit Zombie(const std::string& name);	/* lvalue Copy constructor */
		explicit Zombie(std::string&& name);		/* rvalue Cove constructor */

		~Zombie();

		static Zombie*	newZombie(std::string name);
		static void		randomChump(std::string name);

		void	announce();
	private:
		std::string name_;
};

#endif //EX00_ZOMBIE_H_