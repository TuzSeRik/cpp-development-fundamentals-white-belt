#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// Minimal line is the first line in sorted vector
int main() {
    string a, b, c;
    cin >> a >> b >> c;

    vector<string> tmp = {a, b, c};
    sort(begin(tmp), end(tmp));
    cout << tmp[0];

    return 0;
}
