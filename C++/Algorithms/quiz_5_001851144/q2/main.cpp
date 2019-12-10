#include <iostream>
#include <string>
#include <queue>

using namespace std;

void read(queue <string> currentQueue[], int size) {
    for (int i = 0; i < size; ++i) {
        while (!currentQueue[i].empty()) {
            cout << i + 1 << ". " << currentQueue[i].front()
                 << endl;
            currentQueue[i].pop();
        }
    }
}

int main() 
{
    queue <string> priorQueue[20];
    priorQueue[0].push("This has a priority of 1");
    priorQueue[4].push("This has a priority of 5");
    priorQueue[9].push("This has a priority of 10");
    priorQueue[9].push("Another priority of 10");
    read(priorQueue, 20);
}