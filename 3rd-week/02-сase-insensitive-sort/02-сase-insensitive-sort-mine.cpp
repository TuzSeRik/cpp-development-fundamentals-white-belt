#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> result(n);

    for (int i = 0; i < n; ++i) {
        cin >> result[i];
    }
    // C++ doesn't have enough of string manipulation functions,
    // so we just iterate through both strings and make all characters lowercase
    sort(begin(result), end(result), [](string l, string r) {
        for(auto& i : l) {
            i = tolower(i);
        }

        for(auto& i : r) {
            i = tolower(i);
        }

        return l < r;
    });

    for (const auto& i : result)
        cout << i << " ";

    return 0;
}
