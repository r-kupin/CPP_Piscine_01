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

#include "Harl.hpp"

int GetLevelPriority(const std::string& kLevel){
	if (kLevel == "ERROR")
		return kLevelError;
	else if (kLevel == "WARNING")
		return kLevelWarning;
	else if (kLevel == "INFO")
		return kLevelInfo;
	else if (kLevel == "DEBUG")
		return kLevelDebug;
	else
		return kLevelUndefined;
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
	Harl Harl;

	switch (GetLevelPriority(kLevel)){
		case kLevelUndefined : Harl.complain("UNDEFINED");
			break;
		case kLevelDebug : SysMsg("DEBUG"); Harl.complain("DEBUG"); endl();
		case kLevelInfo : SysMsg("INFO"); Harl.complain("INFO"); endl();
		case kLevelWarning : SysMsg("WARNING"); Harl.complain("WARNING"); endl();
		default : SysMsg("ERROR"); Harl.complain("ERROR"); endl();
	}
	return (0);
}
