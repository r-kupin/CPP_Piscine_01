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

#include "Karen.hpp"

int main() {
	Karen karen;

	std::cout << "=====ERROR=====" << std::endl;
	karen.complain("ERROR");
	std::cout << "=====WARNING=====" << std::endl;
	karen.complain("WARNING");
	std::cout << "=====INFO=====" << std::endl;
	karen.complain("INFO");
	std::cout << "=====DEBUG=====" << std::endl;
	karen.complain("DEBUG");
	std::cout << "=====RAMPAGE=====" << std::endl;
	karen.complain("RAMPAGE");

	return (0);
}
