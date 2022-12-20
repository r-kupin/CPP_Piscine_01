/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Weapon.hpp                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/20 17:33:52 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX03_WEAPON_HPP
#define EX03_WEAPON_HPP


#include <string>

class Weapon {

public:
	explicit Weapon(std::string type);

	const std::string& GetType() const;
	void setType(const std::string &type);

private:
	std::string type_;
};


#endif //EX03_WEAPON_HPP
