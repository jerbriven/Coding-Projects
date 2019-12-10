To run my code, you can execute shellTest.exe. You can also compile and run shellMain.cpp. I used two different test arrays in order
to show the number of comparisons of shell sort versus insertion sort. The comparisons for insertion sort were 15 and 25, while it was 
9 and 11 for shell sort. It seems shell sort is more efficient for these examples. Insertion sort has a worst and average case of n^2 and 
best case of n. Shell sort has a worst case and average case of n*(logn)^2. Its best case is nlogn. At a value smaller than 0, n(logn)^2
becomes a smaller value than n^2. This means for all scenarios, it is likely that shell sort will be more efficient in terms of time
complexity. Depending on the initial sorting of the array, insertion sort will only be better in its best case.