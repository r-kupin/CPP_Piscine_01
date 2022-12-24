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
	karen_methods_.at(ERROR_N).func = &Karen::error;
	karen_methods_.at(ERROR_N).level_name = "ERROR";

	karen_methods_.at(WARNING_N).func = &Karen::warning;
	karen_methods_.at(WARNING_N).level_name = "WARNING";

	karen_methods_.at(INFO_N).func = &Karen::info;
	karen_methods_.at(INFO_N).level_name = "INFO";

	karen_methods_.at(DEBUG_N).func = &Karen::debug;
	karen_methods_.at(DEBUG_N).level_name = "DEBUG";

	karen_methods_.at(UNDEFINED_N).func = &Karen::undefined;
	karen_methods_.at(UNDEFINED_N).level_name = "UNDEFINED";
}

// So, we should make Karen express herself without if()'s... fine
// We have an array of PTMFs and corresponding level names
// As far as it's not C - it is convinient to use iterators,which were already
// 	introduced in d00 ex02.
// So, we are taking iterators to the first and last elements
// 	then , in first part of the for statement we move $end 1 element to beginning,
// 	cause end() returns it pointing after the last element.
// Then, we iterate throw thw loop until we find corresponding function, or till
// 	last element, which means that @param level doesn't match any predefined level.
// We iterate from the most to less significant level and output the Karen's message
// If @param level is malspecified,we output all levels, cause it is Karen,
// 	and she talks alot :)
void Karen::complain(const std::string &level) {
	LevelsPtr ptr = karen_methods_.begin();
	LevelsPtr end = karen_methods_.end();

	for (--end; ptr != end && ptr->level_name != level;	++ptr) {
		CALL_MEM_FN_PTR_ON_PTR(this, ptr->func)();
	}
	CALL_MEM_FN_PTR_ON_OBJ(*this, ptr->func)();
}

void Karen::debug() const {
	std::cout << DEBUG_COLOR;
	std::cout << "Karen: I love to get extra bacon for my " <<
			  "7XL-double-cheese-triple-pickle-special-ketchup " <<
	 "burger. I just ""love it!" << RESET_COLOR << std::endl;
}

void Karen::info() const {
	std::cout << INFO_COLOR;
	std::cout << "Karen: I cannot believe adding extra bacon cost more money. " <<
			  "You don’t put enough! If you did I would not have to ask " <<
	 "for it!" << RESET_COLOR << std::endl;
}

void Karen::warning() const {
	std::cout << WARNING_COLOR;
	std::cout << "Karen: I think I deserve to have some extra bacon for free." <<
			  " I’ve been coming here for years and you just started working " <<
	 "here last month." << RESET_COLOR << std::endl;
}

void Karen::error() const {
	std::cout << ERROR_COLOR;
	std::cout << "Karen: This is unacceptable, I want to speak to the manager " <<
			  "now." << RESET_COLOR << std::endl;
}

void Karen::undefined() const {
	std::cout << "Karen: *ROLLS HER EYES IN FRUSTRATION*" << std::endl;
}
