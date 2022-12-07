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

// the name argument will newer used anywhere afterwards, so it is a good idea
// to move() it to the rvalue constructor
Zombie *Zombie::newZombie(std::string name) {
	std::cout << "newZombie() is resurrecting " + name << std::endl;
	return (new Zombie(std::move(name)));
}
