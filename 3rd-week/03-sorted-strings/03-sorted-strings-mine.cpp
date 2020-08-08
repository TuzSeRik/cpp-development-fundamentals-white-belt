#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Simple example class
class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
    }

    vector<string> GetSortedStrings() {
        sort(begin(strings), end(strings));
        return strings;
    }

private:
    vector<string> strings;
};
