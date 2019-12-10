To run my code you can execute radixTest.exe. You can also compile and run radixMain.cpp. My first example array bag just contains
positive integers. As can be seen, the array bag's contents are correctly sorted. I made a second array of integers that also contains
negative values. This array bag is not sorted correctly. Strange things begin to occur, like values being copied and sorted wrong. This
is because the radix algorithm is meant for positive integers by design. The counting is only based on the different digits values, and 
does not consider negatives. When creating the sorted array, the division and modulus of a negative number disrupts the counting function.
This leads to incorrect index values and some of the data being copied. The values that exist in the final bag are sorted logically, but
they do not represent the original data inserted into the bag.