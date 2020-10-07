/** @file PrecondViolated.cpp */
#include "PrecondViolated.h"  

PrecondViolated::PrecondViolated(const string& message_): exception("Precondition Violated Exception: " + message), message(message_)
{
}  // end constructor

// End of implementation file.
