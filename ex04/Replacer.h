/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Replacer.h                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 15:37:36 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX04_REPLACER_H
#define EX04_REPLACER_H

#include <iosfwd>

class Replacer {
 public:
	static void Replace( std::ifstream& inp, std::ofstream& out,
							const std::string& s1, const std::string& s2);
};

#endif //EX04_REPLACER_H
