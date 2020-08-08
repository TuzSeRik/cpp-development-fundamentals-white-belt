#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    int count = -2;
    cin >> word;
    // Using "count" to store both number of occurrences and after second occurrence - position of it
    if (!word.empty()) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == 'f') count++;
            if (count == 0) {
                count = i;
                break;
            }
        }
    }

    cout << count;

    return 0;
}
