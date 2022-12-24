/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Karen.h                                            :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2022/12/22 17:50:57 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/
/*
		Description

	So, this is all about member-function-pointers

1.“pointer-to-member-function” is different from “pointer-to-function”
	In particular class, pointer-to-function would be like:
 		void (*PTF)() const; // PTF - is the name of the variable of the type
				//	“pointer-to-function” or “pointer-to-static-member-function”
	And pointer to member function would be:
 		void (Karen::*PTMF)() const; // PTMF - is the name of the variable of
									 //	the type “pointer-to-member-function”
	The syntax is horrible, so it is convinient to use typedef's and macro's,
 	which lets us to use PTMF's just as simple variables.
2. Making a typedef
 		typedef void (Karen::*KarenF)() const;
 	So, after that we can do whatever we want with Karen's PTMF's operating with
 	them just like with common variables of type KarenF
3.	Defining a macro
		A. #define CALL_MEM_FN_PTR_ON_PTR(object, ptr) ((object)->*(ptr))
		B. #define CALL_MEM_FN_PTR_ON_OBJ(object, ptr) ((object).*(ptr))
	The reason  this macro is a good idea is because member function invocations
 	are often a lot more complex than the this simple example. The difference in
 	readability and writability is significant.
4. Assignment
	Non-static member functions have a hidden parameter that corresponds to the
 	this pointer. The this pointer points to the instance data for the object.
 	So, when assigning we have to specify a class who owns the function:
		KarenF func = &Karen::function_name;
5. Use
 	Here the written macro comes to be helpful.
 	Use with macro:
		CALL_MEM_FN_PTR_ON_PTR(this, func)(); or
		CALL_MEM_FN_PTR_ON_OBJ(*this, func)();
	Without macro:
		((this)->*(func))(); or
		((*this).*(func))();
	BDSM-way: No macro, No typedef

		void (Karen::*func)() const = &Karen::function;
		((this)->*(func))();

	Obviously, with macros and typedef it is way much comprehensible
*/
#ifndef EX05_KAREN_HPP
#define EX05_KAREN_HPP

// Levels of priority (less number - higher priority) & indexes in array
#define ERROR_N 0
#define WARNING_N 1
#define INFO_N 2
#define DEBUG_N 3
#define UNDEFINED_N 4

// Colorful output is nice :)
#define DEBUG_COLOR "\033[34m"
#define INFO_COLOR "\033[32m"
#define WARNING_COLOR "\033[33m"
#define ERROR_COLOR "\033[31m"
#define RESET_COLOR "\033[0m"

#define KAREN_LEVELS 5

//Call MPTF from the pointer of an object
#define CALL_MEM_FN_PTR_ON_PTR(object, ptr) ((object)->*(ptr))
//Call MPTF from the object itself (this should be dereferenced)
#define CALL_MEM_FN_PTR_ON_OBJ(object, ptr) ((object).*(ptr))

#include <string>
#include <array>

class Karen {
	typedef void (Karen::*KarenF)() const;
// Small "Pair" structure to store MPTFs and their names
	typedef struct MyPairT {
		KarenF func;
		std::string level_name;
	} MyPair;
// Typedef for iterator. It is convinient to use 'auto' keyword, but we can't, so
// I made this to make my code a bit less ugly
	typedef std::array<MyPair, KAREN_LEVELS>::iterator LevelsPtr;
public:
	Karen();

	void complain(const std::string &level);
private:
	std::array<MyPair, KAREN_LEVELS> karen_methods_;

	void debug() const;
	void info() const;
	void warning() const;
	void error() const;
	void undefined() const;
};

#endif //EX05_KAREN_HPP
