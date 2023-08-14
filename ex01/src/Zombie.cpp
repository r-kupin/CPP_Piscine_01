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

int Zombie::zombies_created_ = 0;

Zombie::Zombie(const Zombie &zombie)
		:name_(zombie.name_), id_(zombies_created_){
	zombies_created_++;
	std::cout << "*" + name_+ " id:" << id_ <<
	" is CLONNED by the copy-constructor, parent id is:*" << zombie.id_ << std::endl;
}

Zombie::Zombie(const std::string& name)
	:name_(name), id_(zombies_created_){
	zombies_created_++;
	std::cout << "*" + name_+ " id:" << id_ <<
				" is raised up with a copied name*" << std::endl;
}

//Zombie::Zombie(Zombie &&zombie)
//        :name_(zombie.name_){
//    std::cout << "Resource from the old " << zombie.name_ << " is TRANSFERRED "
//    "to construct new zombie "<< name_ << " with move-constructor" << std::endl;
//}
//
//Zombie::Zombie(std::string &&name)
//		:name_(name), id_(zombies_created_){
//	zombies_created_++;
//	std::cout << "*" + name_+ " id:" << id_ <<
//				 " is raised up with a moved name*" << std::endl;
//}

Zombie::Zombie()
		: id_(zombies_created_){
	zombies_created_++;
	std::cout << "* noname id:" << id_ <<
				 " is raised up by the noarg-constructor*" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "*" + name_+ " id:" << id_ <<
						" finally goes to rest in peace*" << std::endl;
}

void Zombie::announce() const {
	std::cout << "*" + name_+ " id:" << id_ <<
			": BraiiiiiiinnnzzzZ..."<< std::endl;
}

void Zombie::SetName(const std::string &name) {
	name_ = name;
	std::cout << "* name " + name_+ " is assigned to the zombie with an id:" <<
	id_ << std::endl;
}

