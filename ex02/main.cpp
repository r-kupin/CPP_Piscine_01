/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:16:08 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:16:09 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
	const std::string kString = "HI THIS IS BRAIN";
	const std::string& kReferenceString = kString;
	const std::string *ptr_string = &kString;

	std::cout << "string itself: " << kString << std::endl;
	std::cout << "reference to the string: " << kReferenceString << std::endl;
	std::cout << "pointer value of the string: " << *ptr_string << std::endl;
	std::cout << "pointer address of the string: " << ptr_string << std::endl;

	return 0;
}
