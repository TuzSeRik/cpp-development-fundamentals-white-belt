#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int x;
    string result;
    cin >> x;
    // Create string of modulo of divisions of number by two
    while (x > 0) {
        (x % 2 == 0) ? result.append("0") : result.append("1");
        x /= 2;
    }
    // Then reverse and print it
    reverse(begin(result), end(result));
    cout << result;

    return 0;
}
