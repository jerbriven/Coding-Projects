To run my code, you can execute bubbleRecurs.exe. You can also compile and run bubbleSort_recursive.cpp. I kept the original function
and test, to show that my added function works. It effectively does the same thing, but uses a recursive strategy. The first while loop
was changed to iterate using recursion. Since it is effectively the same loop, both algorithms have the same complexity. It's average
and worst case time complexity is n^2. This is because it uses a nested loop, must iterate through both no matter how sorted the input
array is. Even if the first loop already has sorted the array, it will continue the sorting until pass has reached the size of the array.
The space complexity for both algorithms is O(1). Unlike another algorithm like merge sort, no additional array is instantiated with
additional memory. The original input array's memory is the only one needed in this case.