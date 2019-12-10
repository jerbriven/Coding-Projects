To run my code, you can execute arrayPriorTest.exe. You can also compile and run main.cpp. I implemented the array based priority queue.
Each index represents a priority value, and contains a queue. When a given priority is inputted to the priority queue, it is pushed to
the queue that is in the index equivalent to 1 minus the priority value. I created a read function that reads every item of every queue.
This ensures that each item of the priority queue are in order in terms of their priorities. I also showed that it is functional when
two items of the same priority are added. This was done with a simple set of test strings with priorities.