/** @file NotFoundException.cpp */
#include "NotFoundException.h"  

NotFoundException::NotFoundException(const string& message)
         : exception("Not Found Exception: " + message), message(message_)
{
}  // end constructor

// End of implementation file.