/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:11:43 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:11:44 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <utility>

/**	@param name created in this function is sort of wasted, cause it gets
 *	created upon the function call and destroyed after the return();
 */
Zombie *Zombie::newZombie(std::string name) {
	std::cout << "newZombie() is resurrecting " + name << std::endl;
	return (new Zombie(name));
}

/** @param name in this particular case will be moved to the newly created obj.
 * the name argument will newer used anywhere afterwards, so it is a good
 * idea to move() it to the rvalue constructor
 */
//Zombie *Zombie::newZombie(std::string name) {
//	std::cout << "newZombie() is resurrecting " + name << std::endl;
//	return (new Zombie(std::move(name)));
//}

/** @param name is a const reference - it's not getting copied upon method call
 */
//Zombie *Zombie::newZombie(const std::string &name) {
//	std::cout << "newZombie() is resurrecting " + name << std::endl;
//	return (new Zombie(name));
//}
