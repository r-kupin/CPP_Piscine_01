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
#include <cassert>

#include "Karen.hpp"

int GetLevelPriority(const std::string& kLevel){
	if (kLevel == "ERROR")
		return ERROR_N;
	else if (kLevel == "WARNING")
		return WARNING_N;
	else if (kLevel == "INFO")
		return INFO_N;
	else if (kLevel == "DEBUG")
		return DEBUG_N;
	else
		return UNDEFINED_N;
}

void SysMsg(const std::string& msg){
	std::cout << "[ " << msg << " ]" << std::endl;
}

void endl(){
	std::cout << std::endl;
}

int main(int ac, char **av) {
	assert(ac == 2 && "The program should be executed with 1 argument,"
				   "and it must be a string");
	const std::string& kLevel = av[1];
	Karen karen;

	switch (GetLevelPriority(kLevel)){
		case UNDEFINED_N : karen.complain("UNDEFINED");
			break;
		case DEBUG_N : SysMsg("DEBUG"); karen.complain("DEBUG"); endl();
		case INFO_N : SysMsg("INFO"); karen.complain("INFO"); endl();
		case WARNING_N : SysMsg("WARNING"); karen.complain("WARNING"); endl();
		default : SysMsg("ERROR"); karen.complain("ERROR"); endl();
	}
	return (0);
}
