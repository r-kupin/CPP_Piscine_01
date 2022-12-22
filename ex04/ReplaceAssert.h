/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    ReplaceAssert.h                                    :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 12:54:08 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX04_REPLACEASSERT_H
#define EX04_REPLACEASSERT_H

#include <string>

class ReplaceAssert {
public:
	static void CheckNumberOfArgs(int ac);
	static void CheckArgValues(const std::string &filename,
			const std::string &s1, const std::string &s2);
	static void CheckInputFile(const std::ifstream &f_in);
	static void CheckOutputFile(const std::ofstream &f_out);
};


#endif //EX04_REPLACEASSERT_H
