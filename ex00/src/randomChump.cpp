/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:11:49 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:11:50 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <utility>

/** @brief Chump is stack-allocated, so will be removed automatically
*	@param name - same as with newZombie()
 */

/* naive / dumb */
void Zombie::randomChump(std::string name) {
	std::cout << "randomChump() is resurrecting " + name << std::endl;
	Zombie Chump(name);
	Chump.announce();
}

/* using std::move() */
//void Zombie::randomChump(std::string name) {
//	std::cout << "randomChump() is resurrecting " + name << std::endl;
//	Zombie Chump(std::move(name));
//	Chump.announce();
//}

/* const reference */
//void Zombie::randomChump(const std::string &name) {
//	std::cout << "randomChump() is resurrecting " + name << std::endl;
//	Zombie Chump(name);
//	Chump.announce();
//}
