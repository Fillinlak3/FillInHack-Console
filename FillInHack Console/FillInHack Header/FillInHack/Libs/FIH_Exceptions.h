	// FIH_Exceptions Header
#pragma once
#ifndef __FIH_EXCEPTIONS_H
#define __FIH_EXCEPTIONS_H

#ifndef _IOSTREAM_
#include <iostream>
#endif

// -- FIH_Exceptions Class --
class FIH_Exceptions : public std::exception {
private:
	const char* exc;
public:
	FIH_Exceptions(const char* _msg)
		: exc(_msg)
	{ /*this->exc = _msg;*/
	}

	const char* what() const throw()
	{
		return this->exc;
	}

};

#endif // !__FIH_EXCEPTIONS_H