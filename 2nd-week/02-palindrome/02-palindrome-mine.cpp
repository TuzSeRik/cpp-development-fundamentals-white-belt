#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// Typo is required by task
bool IsPalindrom(string subject) {
    string tcejbus = subject;
    reverse(begin(tcejbus), end(tcejbus));

    return subject == tcejbus;
}

int main() {
    string subject;
    cin >> subject;

    cout << IsPalindrom(subject);

    return 0;
}
