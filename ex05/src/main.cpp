/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:19:44 by rokupin           #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main() {
	Harl k;

	std::cout << "=====ERROR=====" << std::endl;
	k.complain("ERROR");
	std::cout << "=====WARNING=====" << std::endl;
	k.complain("WARNING");
	std::cout << "=====INFO=====" << std::endl;
	k.complain("INFO");
	std::cout << "=====DEBUG=====" << std::endl;
	k.complain("DEBUG");
	std::cout << "=====RAMPAGE=====" << std::endl;
	k.complain("RAMPAGE");

	return (0);
}
