In order to execute my code, you can run testMain.exe. The main.cpp
file can also be compiled and ran. In this question, I made a 
derived class based on QueueInterface, and defined the member
functions. In order to implement the standard template library
Queue, I defined a private queue in OurQueue.h. Each of the member
functions call the functions from the standard template library
on this private queue. I used the size queue function in order
to check if the enqueue and dequeue functions were successful.
This bool result is returned to my main function. The main.cpp
file contains logic and cout statements to inform the user of 
the success or failure of the various OurQueue functions.