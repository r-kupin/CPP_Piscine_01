/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Replacer.cpp                                       :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 15:37:36 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "Replacer.h"
#include <iosfwd>
#include <fstream>
#include <iostream>

static void ReadToBuffer(const std::string &s1,
							std::string &buffer,
							std::ifstream &inp,
							size_t &i) {
	while (i < s1.length() - 1 && buffer.at(i) == s1.at(i)) {
		inp >> std::noskipws >> buffer.at(++i);
	}
}

static void FlushTheBuffer(std::ofstream &out,
						   const size_t &i,
						   std::string &buffer) {
	size_t j = 0;

	while (j <= i) {
		out << buffer.at(j);
		buffer.at(j) = ' ';
		j++;
	}
}

static bool TryReadCharToBuffer(std::ifstream &inp,
									std::string &buffer,
									const size_t &i) {
	if (inp >> std::noskipws >> buffer.at(i))
		return true;
	return false;
}

static void FlushReplacementString(std::ofstream &out,
									const std::string &s2,
									int &repl_count) {
	out << s2;
	repl_count++;
}

static void CloseStreamsShowMessage(std::ifstream &inp,
									std::ofstream &out,
									int repl_count) {
	inp.close();
	out.close();
	std::cout << repl_count << " replacements were performed" << std::endl;
}

void Replacer::Replace(std::ifstream &inp,
						std::ofstream &out,
						const std::string &s1,
						const std::string &s2) {
	int repl_count = 0;
	size_t i = 0;

	std::string buffer(s1.length(), ' ');

	while (TryReadCharToBuffer(inp, buffer, i)) {
		ReadToBuffer(s1, buffer, inp, i);
		if (buffer == s1) {
			FlushReplacementString(out, s2, repl_count);
		} else {
			FlushTheBuffer(out, i, buffer);
		}
		i = 0;
	}
	CloseStreamsShowMessage(inp, out, repl_count);
}
