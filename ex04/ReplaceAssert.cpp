/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    ReplaceAssert.cpp                                  :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 12:54:08 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/
/*
			Description

 	assert() - is one of the simple mechanics of error handling
 		Basically, it takes boolean as an argument, and if it is false - stops
 		the execution of the program with the error.
	passing the dtrong after && is a common way to output error message with
 		the explanations of what went wrong, because output message will contain
 		the line of failed assert, and therefore - message as well
*/
#include "ReplaceAssert.h"

#include <cassert>
#include <iosfwd>
#include <fstream>

void ReplaceAssert::CheckNumberOfArgs(int ac) {
	assert(ac == 4 && "arguments must be one filename and two strings");
}

void ReplaceAssert::CheckArgValues(const std::string &filename,
		const std::string &s1, const std::string &s2) {
	assert(!s1.empty() && "none of the input strings can be empty");
	assert(!s2.empty() && "none of the input strings can be empty");
	assert(!filename.empty() && "none of the input strings can be empty");
	assert(s1 != s2 && "it makes no sense");
}

void ReplaceAssert::CheckInputFile(const std::ifstream &f_in) {
	assert(f_in.is_open() && "input file open() failed");
}

void ReplaceAssert::CheckOutputFile(const std::ofstream &f_out) {
	assert(f_out.is_open() && "input file open() failed");
}
