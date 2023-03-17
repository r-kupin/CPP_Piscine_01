/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Karen.cpp                                          :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 17:50:57 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "Karen.hpp"

#include <iostream>

Karen::Karen() {
	karen_methods_[kKarenLevelError].func = &Karen::error;
	karen_methods_[kKarenLevelError].level_name = "ERROR";

	karen_methods_[kKarenLevelWarning].func = &Karen::warning;
	karen_methods_[kKarenLevelWarning].level_name = "WARNING";

	karen_methods_[kKarenLevelInfo].func = &Karen::info;
	karen_methods_[kKarenLevelInfo].level_name = "INFO";

	karen_methods_[kKarenLevelDebug].func = &Karen::debug;
	karen_methods_[kKarenLevelDebug].level_name = "DEBUG";

	karen_methods_[kKarenLevelUndefined].func = &Karen::undefined;
	karen_methods_[kKarenLevelUndefined].level_name = "UNDEFINED";
}

/**
 * @brief Calls the member functions corresponding to the levels from debug
 * to the specified level inclusively.
 *
 * So, we should make Karen express herself without if()'s... fine
 * We have an array of PTMFs and corresponding level names
 * Iterate throw thw loop until we find corresponding function, or
 * till last element, which means that level doesn't match any predefined
 * level. We iterate from the most to less significant level and output the
 * Karen's message. If level is malspecified,we output all levels,
 * cause it is Karen, and she talks alot :)
 * @param level The name of the level to complain about. Can be one of the
 * following: 'debug', 'info', 'warning', 'error'.
 */
void Karen::complain(const std::string &level) {
	int i;

	for (i = 0;
		 i < kKarenLevelsAmount && karen_methods_[i].level_name != level;
		 ++i) ;
	if (i < kKarenLevelsAmount && karen_methods_[i].level_name == level)
		CALL_MEM_FN_PTR_ON_OBJ(*this, karen_methods_[i].func)();
}

void Karen::debug() const {
	std::cout << kColorDebug;
	std::cout << "Karen: I love to get extra bacon for my " <<
			  "7XL-double-cheese-triple-pickle-special-ketchup " <<
			  "burger. I just ""love it!" << kColorReset << std::endl;
}

void Karen::info() const {
	std::cout << kColorInfo;
	std::cout << "Karen: I cannot believe adding extra bacon cost more money. " <<
			  "You don’t put enough! If you did I would not have to ask " <<
			  "for it!" << kColorReset << std::endl;
}

void Karen::warning() const {
	std::cout << kColorWarn;
	std::cout << "Karen: I think I deserve to have some extra bacon for free." <<
			  " I’ve been coming here for years and you just started working " <<
			  "here last month." << kColorReset << std::endl;
}

void Karen::error() const {
	std::cout << kColorError;
	std::cout << "Karen: This is unacceptable, I want to speak to the manager " <<
			  "now." << kColorReset << std::endl;
}

void Karen::undefined() const {
	std::cout << "Karen: *ROLLS HER EYES IN FRUSTRATION*" << std::endl;
}
