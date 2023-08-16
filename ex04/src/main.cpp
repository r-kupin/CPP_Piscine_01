/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:18:22 by rokupin           #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iosfwd>
#include <fstream>
#include <iostream>

#include "ReplaceAssert.h"
#include "Replacer.h"

/** The args are non-empty strings:	@param input_filename
 * 									@param what_to_find
 * 									@param to_replace_with
 * @brief
 * 1. Check the arg number
 * 2. Copy ugly C-style char* to NICE C++ strings
 * 3. Check values of args
 * 4. Try to open input file
 * 5. Try to create and open output file
 * 6. Perform replacement
 */
int main(int ac, char **av) {

	ReplaceAssert::CheckNumberOfArgs(ac);

	std::string filename = av[1];
	const std::string find = av[2];
	const std::string replace = av[3];

	ReplaceAssert::CheckArgValues(filename, find, replace);

	std::ifstream f_in;
	f_in.open(filename.data());

	ReplaceAssert::CheckInputFile(f_in);

	filename.append(".replace");
	std::ofstream f_out;
	f_out.open(filename.data());

	ReplaceAssert::CheckOutputFile(f_out);

	Replacer::Replace(f_in, f_out, find, replace);
	return 0;
}
