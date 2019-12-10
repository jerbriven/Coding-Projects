To run my code, you can execute the cityTest.exe file. You can
also compile the main.cpp file. I decided to create a class
called graph, which contained an adjacency matrix. I manipulated
the given isPath function to work with this adjacency matrix.
Since the adjaceny matrix only contains 1s and 0s, I also have
a list of cities. A city is a simple class that just contains
a name, and an index value. The index is determined when a city
is added to the graph. It represents the index of the adjacency matrix
for every city. For the tests, I expanded upon the example given.
I created 7 cities, and increased the number of direct flights.
If you run my code, you can see that the text files are read,
and the correct paths are verified. If you draw out the graph
for this setup, you can see that my function is correct. 