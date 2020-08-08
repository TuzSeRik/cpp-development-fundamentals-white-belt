#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// Typo is required by task
bool IsPalindrom(string subject) {
    string tcejbus = subject;
    reverse(begin(tcejbus), end(tcejbus));

    return subject == tcejbus;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;

    for (auto word : words) {
        if (IsPalindrom(word) && word.size() >= minLength)
            result.push_back(word);
    }

    return result;
}
