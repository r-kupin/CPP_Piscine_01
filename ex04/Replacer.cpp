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

// When this function is invoked @buffer has 1 character read from the stream
// while there is still a free space in buffer
// and while the char in buffer matches corresponding char in s2
// Coontinue reading char by char
//
static void ReadToBuffer(const std::string &s1,
							std::string &buffer,
							std::ifstream &inp,
							size_t &i) {
	while (i < s1.length() - 1 &&
			buffer.at(i) == s1.at(i)) {
		inp >> std::noskipws >> buffer.at(++i);
	}
}

static void FlushTheBuffer(std::ofstream &out,
						   const size_t &i,
						   std::string &buffer) {
	for (size_t j = 0; j <= i; j++) {
		out << buffer.at(j);
		buffer.at(j) = ' ';
	}
}

// By default >> read operation skips whitespaces, but with noskipws inline
// it allows us to read char by char any contents of the file
//
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

// The args are: 	@input_stream
//					@output_stream
// 			string	@what_to_find (s1)
// 			string	@to_replace_with (s2)
// 1. Creating a blank buffer of s1.size
// 2. Attempt to read a char from input stream to buffer, if there's something to read
// 3. Continue reading if / while input chars match with s1, and buffer isn't full
// 4.1 If buffer is full, and it matches the s1
// 4.2 Put s2 to file
// 5.1 Buffer doesnt math s1
// 5.2 Flush the contents of the buffer and erace flushed chars
// 6. Go to 2
// 7. Close the buffers and print statistics
//
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
