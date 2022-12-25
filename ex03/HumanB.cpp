/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:17:01 by rokupin           #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>
#include <utility>

HumanB::HumanB(std::string name)
: weapon_(nullptr),  name_(std::move(name)) {}

void HumanB::attack() const {
	if (!weapon_) {
		std::cout << name_ << " attacks with his shaking hands and empty words" << std::endl;
	} else {
		std::cout << name_ << " attacks with his " << weapon_->GetType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon *weapon) {
	weapon_ = weapon;
}

