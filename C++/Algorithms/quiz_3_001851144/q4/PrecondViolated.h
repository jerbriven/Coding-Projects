/** @file PrecondViolated.h */

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolated : public std::exception
{
private:
   string message;
public:
   PrecondViolated(const string& message_ = ""): message(message_) {};
}; // end PrecondViolated 
#endif