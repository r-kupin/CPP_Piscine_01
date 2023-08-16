/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Harl.cpp                                           :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 17:50:57 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

#include <iostream>

Harl::Harl() {
	Harl_methods_[kLevelError].func = &Harl::error;
	Harl_methods_[kLevelError].level_name = "ERROR";

	Harl_methods_[kLevelWarning].func = &Harl::warning;
	Harl_methods_[kLevelWarning].level_name = "WARNING";

	Harl_methods_[kLevelInfo].func = &Harl::info;
	Harl_methods_[kLevelInfo].level_name = "INFO";

	Harl_methods_[kLevelDebug].func = &Harl::debug;
	Harl_methods_[kLevelDebug].level_name = "DEBUG";

	Harl_methods_[kLevelUndefined].func = &Harl::undefined;
	Harl_methods_[kLevelUndefined].level_name = "UNDEFINED";
}

/**
 * @brief Calls the member functions corresponding to the levels from debug
 * to the specified level inclusively.
 *
 * So, we should make Harl express herself without if()'s... fine
 * We have an array of PTMFs and corresponding level names
 * Iterate throw thw loop until we find corresponding function, or
 * till last element, which means that level doesn't match any predefined
 * level. We iterate from the most to less significant level and output the
 * Harl's message. If level is malspecified,we output all levels,
 * cause it is Harl, and she talks alot :)
 * @param level The name of the level to complain about. Can be one of the
 * following: 'debug', 'info', 'warning', 'error'.
 */
void Harl::complain(const std::string &level) {
	int i;

	for (i = 0;
         i < kLevelsAmount && Harl_methods_[i].level_name != level;
		 ++i) ;
	if (i < kLevelsAmount && Harl_methods_[i].level_name == level)
		CALL_MEM_FN_PTR_ON_OBJ(*this, Harl_methods_[i].func)();
}

void Harl::debug() const {
	std::cout << kColorDebug;
	std::cout << "Harl: I love to get extra bacon for my " <<
			  "7XL-double-cheese-triple-pickle-special-ketchup " <<
			  "burger. I just ""love it!" << kColorReset << std::endl;
}

void Harl::info() const {
    std::cout << kColorInfo;
    std::cout << "Harl: I cannot believe adding extra bacon costs more money." <<
              "You didn’t put enough bacon in my burger! If you did, I " <<
              "wouldn’t be asking for more!" << kColorReset << std::endl;
}

void Harl::warning() const {
	std::cout << kColorWarn;
	std::cout << "Harl: I think I deserve to have some extra bacon for free." <<
			  " I’ve been coming here for years and you just started working " <<
			  "here last month." << kColorReset << std::endl;
}

void Harl::error() const {
	std::cout << kColorError;
	std::cout << "Harl: This is unacceptable, I want to speak to the manager " <<
			  "now." << kColorReset << std::endl;
}

void Harl::undefined() const {
    std::cout << "Harl: *ROLLS EYES IN FRUSTRATION*" << std::endl;
}
