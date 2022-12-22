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

int main(int ac, char **av) {

	ReplaceAssert::CheckNumberOfArgs(ac);

	std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];

	ReplaceAssert::CheckArgValues(filename, s1, s2);

	std::ifstream f_in;
	f_in.open(filename);

	ReplaceAssert::CheckInputFile(f_in);

	filename.append(".replace");
	std::ofstream f_out;
	f_out.open(filename);

	ReplaceAssert::CheckOutputFile(f_out);

	Replacer::Replace(f_in, f_out, s1, s2);
	return 0;
}
