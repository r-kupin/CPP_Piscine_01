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

struct Replacer {
	static void Replace(std::ifstream& inp, std::ofstream& out,
                        const std::string& find, const std::string& replace);
};

#endif //EX04_REPLACER_H
