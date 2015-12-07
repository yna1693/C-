/** @file TreeException.h */
#ifndef _TREE_EXCEPTION
#define _TREE_EXCEPTION

#include <stdexcept>
#include <string>
using namespace std;

class TreeLogicException : public logic_error {
	public:
	TreeLogicException(const string & Message = "") :
		logic_error(Message.c_str()) {
	}
};
#endif

