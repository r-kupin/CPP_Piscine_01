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
/**
			Description

 	assert() - is one of the simple mechanics of error handling
 		Basically, it takes boolean as an argument, and if it is false - stops
 		the execution of the program with the error.
	passing the string after && is a common way to output error message with
 		the explanations of what went wrong, because output message will contain
 		the line of failed assert, and therefore - message as well
*/
#include "ReplaceAssert.h"

#include <cassert>
#include <iosfwd>
#include <fstream>

/**
 * @brief Fails if number not 3 arguments
 * @param ac - ar count
 */
void ReplaceAssert::CheckNumberOfArgs(int ac) {
	assert(ac == 4 && "arguments must be one filename and two strings");
}

/**
 * @brief Fails if either one of the strings is empty, or replace from is the
 * same as replace to
 * @param filename
 * @param s1 what to find
 * @param s2 on what s1 should be replaced
 */
void ReplaceAssert::CheckArgValues(const std::string &filename,
		const std::string &s1, const std::string &s2) {
	assert(!s1.empty() && "none of the input strings can be empty");
	assert(!s2.empty() && "none of the input strings can be empty");
	assert(!filename.empty() && "none of the input strings can be empty");
	assert(s1 != s2 && "it makes no sense");
}

/**
 * @brief Fail if input file can't be opened
 * @param f_in input filename
 */
void ReplaceAssert::CheckInputFile(const std::ifstream &f_in) {
	assert(f_in.is_open() && "input file open() failed");
}

/**
 * @brief Fail if output file can't be created / opened
 * @param f_out output filename
 */
void ReplaceAssert::CheckOutputFile(const std::ofstream &f_out) {
	assert(f_out.is_open() && "input file open() failed");
}
