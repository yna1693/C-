/** @file UnsupportedOperationException.h */
#ifndef _UNSUPPORTED_OPERATION_EXCEPTION
#define _UNSUPPORTED_OPERATION_EXCEPTION

#include <stdexcept>
#include <string>
using namespace std;

class UnsupportedOperationException : public logic_error {
	public:
	UnsupportedOperationException(const string & Message = "") :
		logic_error(Message.c_str()) {
	}
};
#endif
