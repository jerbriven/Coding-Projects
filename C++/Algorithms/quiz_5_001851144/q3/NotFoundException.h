/** @file NotFoundException.h */

#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public std::exception
{
private:
   string message;
public:
   NotFoundException(const string& message_ = ""): message(message_) {};
}; // end NotFoundException 
#endif