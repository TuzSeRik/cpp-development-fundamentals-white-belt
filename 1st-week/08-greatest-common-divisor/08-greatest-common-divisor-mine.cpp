#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    // While any of numbers do not divide completely on other,
    // take modulo of division of the biggest number on other number and save it to the biggest number
    while (x % y != 0 && y % x != 0) {
        if (x > y)
            x %= y;
        else y %= x;
    }
    // Print the smallest number
    cout << min(x, y);

    return 0;
}
