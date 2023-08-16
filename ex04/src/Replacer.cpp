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

/**
 * @brief Reads from an input file stream until the end of the given string
 * is reached or the buffer is full. When this function is invoked buffer has 1
 * character read from the stream while there is still a free space in buffer
 * and while the char in buffer matches corresponding char in s2 continue
 * reading char by char.
 * @param s1 The string to read from the input file stream.
 * @param buffer A reference to the string buffer that will hold the read characters.
 * @param inp The input file stream to read from.
 * @param i The index to start reading from in the buffer.
 * @note The function modifies the given buffer and index variables.
 */
static void ReadToBuffer(const std::string &s1,
							std::string &buffer,
							std::ifstream &inp,
							size_t &i) {
	while (i < s1.length() - 1 &&
			buffer.at(i) == s1.at(i)) {
		inp >> std::noskipws >> buffer.at(++i);
	}
}
/**
 * Writes the contents of the given string buffer to an output file stream
 * up to the specified index and resets the buffer.
 * @param out The output file stream to write to.
 * @param i The index up to which to write from the buffer.
 * @param buffer A reference to the string buffer to flush.
 * @note The function modifies the given buffer variable.
 */
static void FlushTheBuffer(std::ofstream &out,
						   const size_t &i,
						   std::string &buffer) {
	for (size_t j = 0; j <= i; j++) {
		out << buffer.at(j);
		buffer.at(j) = ' ';
	}
}

/**
 * @brief Tries to read a character from an input file stream and store it in
 * the given buffer at the specified index. By default >> read operation
 * skips whitespaces, but with noskipws inline it allows us to read char by char
 * any contents of the file
 * @param inp The input file stream to read from.
 * @param buffer A reference to the string buffer that will hold the read
 *  character.
 * @param i The index in the buffer to store the read character.
 * @return True if a character was successfully read and stored in the buffer,
 *  false otherwise.
 * @note The function modifies the given buffer variable.
 */
static bool TryReadCharToBuffer(std::ifstream &inp,
									std::string &buffer,
									const size_t &i) {
	if (inp >> std::noskipws >> buffer.at(i))
		return true;
	return false;
}

/**
 * Writes the replacement string to an output file stream and increments
 * the replacement count.
 * @param out The output file stream to write to.
 * @param replace The replacement string to write.
 * @param repl_count A reference to the replacement count variable to
 * increment.
 */
static void FlushReplacementString(std::ofstream &out,
									const std::string &replace,
									int &repl_count) {
	out << replace;
	repl_count++;
}

/**
 * Closes the input and output file streams and prints the number of
 * replacements that were performed to the console.
 * @param inp The input file stream to close.
 * @param out The output file stream to close.
 * @param repl_count The number of replacements that were performed.
 */
static void CloseStreamsShowMessage(std::ifstream &inp,
									std::ofstream &out,
									int repl_count) {
	inp.close();
	out.close();
	std::cout << repl_count << " replacements were performed" << std::endl;
}

/**
 * @brief Replaces all occurrences of a substring in an input file stream
 * with a replacement string and writes the result to an output file stream.
 * 1. Creating a blank buffer of s1.size
 * 2. Attempt to read a char from input stream to buffer, if there's something to read
 * 3. Continue reading if / while input chars match with s1, and buffer isn't full
 * 4.1 If buffer is full, and it matches the s1
 * 4.2 Put s2 to file
 * 5.1 Buffer doesnt math s1
 * 5.2 Flush the contents of the buffer and erase flushed chars
 * 6. Go to 2
 * 7. Close the buffers and print statistics
 * @param inp The input file stream to read from.
 * @param out The output file stream to write to.
 * @param find The substring to search for.
 * @param replace The replacement string to use.
 */
void Replacer::Replace(std::ifstream &inp,
						std::ofstream &out,
						const std::string &find,
						const std::string &replace) {
	int repl_count = 0;
	size_t i = 0;

	std::string buffer(find.length(), ' ');

	while (TryReadCharToBuffer(inp, buffer, i)) {
		ReadToBuffer(find, buffer, inp, i);
		if (buffer == find) {
			FlushReplacementString(out, replace, repl_count);
		} else {
			FlushTheBuffer(out, i, buffer);
		}
		i = 0;
	}
	CloseStreamsShowMessage(inp, out, repl_count);
}
