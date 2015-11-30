#ifndef _QUEUE_EXCEPTION
#define _QUEUE_EXCEPTION
#include <stdexcept>
#include <string>

using namespace std;

class QueueException : public logic_error {
	public:
	QueueException(const string& message = "")
		: logic_error(message.c_str()) {
	}
};
#endif
