#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
// Another simple task
int main() {
    map<string, set<string>> dictionary;
    string command, word1, word2;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> command;

        if (command == "ADD") {
            cin >> word1 >> word2;

            dictionary[word1].insert(word2);
            dictionary[word2].insert(word1);
        }

        if (command == "COUNT") {
            cin >> word1;

            cout << dictionary[word1].size() << endl;
        }

        if (command == "CHECK") {
            cin >> word1 >> word2;

            (dictionary[word1].count(word2) == 1) ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
}
