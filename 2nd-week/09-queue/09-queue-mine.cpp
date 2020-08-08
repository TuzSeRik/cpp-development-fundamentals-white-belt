#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<bool> queue;
    string command;
    int n, arg;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> command;
        // Setting needed person to true (is worrying)
        if (command == "WORRY") {
            cin >> arg;
            queue[arg] = true;
            continue;
        }
        // Setting needed person to false (is not worrying)
        if (command == "QUIET") {
            cin >> arg;
            queue[arg] = false;
            continue;
        }
        // Adding quiet people to queue or deleting them;
        if (command == "COME") {
            cin >> arg;
            if (arg >= 0)
                for (int j = 0; j < arg; ++j) {
                    queue.push_back(false);
                }
            else
                queue.erase(end(queue) - abs(arg), end(queue));
            continue;
        }
        // Counting worried people
        if (command == "WORRY_COUNT")
            cout << count(begin(queue), end(queue), true) << endl;
    }

    return 0;
}
