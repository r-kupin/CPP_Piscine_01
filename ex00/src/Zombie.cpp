/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:11:54 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:11:55 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const Zombie &zombie)
		:name_(zombie.name_){
	std::cout << "*" + name_+ " is CLONNED by the copy-constructor" << std::endl;
}

Zombie::Zombie(const std::string& name)
		:name_(name){
	std::cout << "*" + name_+
				 " is raised up with a copied name*" << std::endl;
}

//Zombie::Zombie(std::string &&name)
//		:name_(name){
//	std::cout << "*" + name_+
//				 " is raised up with a moved name*" << std::endl;
//}

Zombie::~Zombie() {
	std::cout << "*" + name_ + " finally goes to rest in peace*" << std::endl;
}

void Zombie::announce() const {
	std::cout << name_ + ": BraiiiiiiinnnzzzZ..."<< std::endl;
}

