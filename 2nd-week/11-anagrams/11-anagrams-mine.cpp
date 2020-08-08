#include <iostream>
#include <string>
#include <map>

using namespace std;
// Transforming word into map of chars with their number
map<char, int> parseString(const string& str) {
    map<char, int> result;

    for (auto ch : str) {
        result[ch]++;
    }

    return result;
}
// Comparing maps
void isAnagram(const string& one, const string& another) {
    map<char, int> oneMap, anotherMap;

    oneMap = parseString(one);
    anotherMap = parseString(another);

    if (oneMap == anotherMap)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    string one, another;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> one >> another;
        isAnagram(one, another);
    }

    return 0;
}
