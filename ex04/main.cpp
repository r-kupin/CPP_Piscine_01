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

#include <cassert>
#include <iosfwd>
#include <fstream>
#include <iostream>
#include "ReplaceAssert.h"

void replace(std::ifstream& inp, std::ofstream& out,
			 const std::string& s1, const std::string& s2) {
	int repl_count = 0;
	size_t i = 0;
	size_t j;

	std::string buffer(s1.length(), ' ');

	while (inp >> std::noskipws >> buffer.at(i)) {
		while ( i < s1.length() - 1 && buffer.at(i) == s1.at(i)) {
			inp >> std::noskipws >> buffer.at(++i);
		}
		if (buffer == s1) {
				out << s2;
				repl_count++;
		} else {
			j = 0;
			while (j <= i) {
				out << buffer.at(j);
				buffer.at(j) = ' ';
				j++;
			}
		}
		i = 0;
	}
	inp.close();
	out.close();
	std::cout << repl_count << " replacements were performed" << std::endl;
}

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

	replace(f_in, f_out, s1, s2);
	return 0;
}
