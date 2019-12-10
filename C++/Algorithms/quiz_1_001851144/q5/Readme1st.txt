For this question, I appended code 5 to be a doubly linked
list. You can either run doubleLinked.exe, or compile and run
main.cpp with g++. It first adds to items to the list. This
demonstrates how items are appended to the beginning of the
list. I appended to the add function and changed its name to add
first. It's very similar, but it now creates a reverse chain.
This is what makes the linked list doubly linked. I altered
the Node class so that it contains a new pointer called previous.
I also made a read forward function that will display the
contents of the bag. The most recently added item will be
displayed first. Then, I removed the first item in the list.
I created a removeFirst function. You can look to my pdf for
the explanation of how it works. The second item of the list
becomes the first, and the original first item is lost.

I also implemented a tail pointer just for fun. This wasn't asked in
the assignment, but I wanted to be able to access both sides
of my linked list. The second half of my tests attempt adding
to the end of the list, removing from the end of the list, and
reading the items in the list in reverse.