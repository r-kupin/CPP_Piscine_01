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
/**
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
#ifndef EX06_KAREN_HPP
#define EX06_KAREN_HPP

/**
 * A macro that calls a member function pointer on an object pointer.
 * @param object A pointer to the object on which to call the member  function.
 * @param ptr A pointer to the member function to call on the object.
 * @note This macro is meant to be used with member function pointers that
 * take no arguments and return void.
 */
#define CALL_MEM_FN_PTR_ON_PTR(object, ptr) ((object)->*(ptr))

/**
 * A macro that calls a member function pointer on an object (this should
 * be dereferenced)
 * @param object The object on which to call the member function.
 * @param ptr A pointer to the member function to call on the object.
 * @note This macro is meant to be used with member function pointers that
 * take no arguments and return void.
 * @note This macro is different from CALL_MEM_FN_PTR_ON_PTR in that it takes an
 * object by value rather than by pointer.
 */
#define CALL_MEM_FN_PTR_ON_OBJ(object, ptr) ((object).*(ptr))

#include <string>

const static int kKarenLevelError = 0;
const static int kKarenLevelWarning = 1;
const static int kKarenLevelInfo = 2;
const static int kKarenLevelDebug = 3;
const static int kKarenLevelUndefined = 4;
const static int kKarenLevelsAmount = 5;

// Colorful output is nice :)
const static std::string kColorDebug = "\033[34m";
const static std::string kColorInfo = "\033[32m";
const static std::string kColorWarn = "\033[33m";
const static std::string kColorError = "\033[31m";
const static std::string kColorReset = "\033[0m";

class Karen {
	/**
	 * Typedef for a pointer to a const member function of the Karen class that
	 * takes no arguments and returns void.
	 * Used as a type for storing member function pointers in the MyPair structure.
	 */
	typedef void (Karen::*KarenF)() const;

	/**
	 * A structure to store a member function pointer and the corresponding
	 * level name as a pair.
	 * Used to initialize the karen_methods_array_ array in the Karen class.
	 */
	typedef struct MyPairT {
		KarenF func;
		std::string level_name;
	} MyPair;

	/**
	 * Typedef for iterator. It is convinient to use 'auto' keyword, but we
	 * can't, so I made this to make my code a bit less ugly
	 */
//	typedef std::array<MyPair, kKarenLevelsAmount>::iterator LevelsPtr;
public:
	Karen();

	void complain(const std::string &level);
private:
//	std::array<MyPair, kKarenLevelsAmount> karen_methods_array_;
	MyPair karen_methods_[kKarenLevelsAmount];

	void debug() const;
	void info() const;
	void warning() const;
	void error() const;
	void undefined() const;
};

#endif //EX06_KAREN_HPP