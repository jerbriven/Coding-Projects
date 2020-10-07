To run my code, you can execute mainTest.exe. Compiling and running main.cpp is
an alternative approach. I used the linked stack implementation from quiz 2
question 4. Then I added an additional method called peek2. This simply finds
the next node after the head pointer and returns its value. If the number of
values within the stack is 1 or less, an exception is thrown. Since I initially
pushed 3 items to the stack, I popped 4 times. Then, I called peek2 again. This
successfully shows the exception being thrown in this situation.