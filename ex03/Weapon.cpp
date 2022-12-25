/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Weapon.cpp                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/20 17:33:52 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "Weapon.hpp"

#include <utility>

Weapon::Weapon(std::string type)
:type_(std::move(type)) {}

const std::string & Weapon::GetType() const {
	return type_;
}

void Weapon::setType(const std::string &type) {
	type_ = type;
}
