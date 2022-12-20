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

#include <string>
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon& weapon);

	void attack() const;
private:
	Weapon& weapon_;
	std::string name_;
};