To compile my code, use g++ on testToyBox.cpp. You can also
just run the executable testToy.exe from command line. 
My test instantiates a ToyBox object that holds a Blue Race 
Car. First, it outputsthe result of getColor of the 
object. It returns 2, which is the correct index 
of BLUE from the color array of the class.
Then, I utilize the inherited member function, get Item. This
outputs "Race Car", correctly inheriting Plainbox's funciton.
Then, I tested setItem, changing the object to an "Action
Figure". I tested get item again, and this shows that the
string object was correctly changed. This shows the setItem
member function was also correctly inherited in the ToyBox
class.