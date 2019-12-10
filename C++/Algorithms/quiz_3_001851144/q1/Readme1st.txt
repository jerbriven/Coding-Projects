For both functions, I added a global variable called count in order to keep track of the number of comparisons. In order to run my code,
you can execute mergeTest.exe and insertionTest.exe. These represent merge sort and insertion sort respectively. You can also compile
and run my main.cpp files. I used the example array given, and created an array of integers as a second test. For the string array of 6
items, insertion sort had 15 comparisons while merge sort had 7 comparisons. My second array contains 10 integers. Insertion sort had
25 comparisons for this array, while merge sort had 24 comparisons. Merge sort has a better worst case, O(nlogn). Insertion sort has a 
worst case of O(n^2). Although, insertion sort has a better best case, n, compared to Merge sorts best case of nlogn. No matter the size
of the array, nlogn will always be a smaller value than n^2. It depends more on the state of the array that is trying to be sorted.
If it is a case that is close to insertion sort's best case, then the time complexity will be smaller than merge sort. On average, and in
their worst cases, merge sort will have less comparisons and will be the better choice.