/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:16:54 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:16:56 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(const std::string& name, Weapon& weapon);

	void attack() const;
private:
	Weapon& weapon_;
	std::string name_;
};

#endif // HUMAN_A_HPP