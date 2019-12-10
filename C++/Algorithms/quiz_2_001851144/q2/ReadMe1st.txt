To run this code, you can execute test.exe. You can also compile
the queensMain.cpp. I used the array method discussed in class.
This utilizes two main functions. The first function just checks
if the attempted queen placement can be attacked by the other
queens. The second is a recursive function. Each recursive call
checks one of the columns. It tries to place a queen in each 
row of that column. It also implements backtracking. This prevents
placing a queen that doesn't lead to a solution. The function
recursively calls itself, and if it doesn't return true the 
queen is removed. This means that different queen combinations
will be used until a single solution is found. For my tests,
I found a solution for all eight starting positions of the first
column.