/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:16:44 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:16:46 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <utility>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
: name_(std::move(name)), weapon_(weapon) {}

void HumanA::attack() const {
	std::cout << name_ << " attacks with his " << weapon_.GetType() << std::endl;
}
