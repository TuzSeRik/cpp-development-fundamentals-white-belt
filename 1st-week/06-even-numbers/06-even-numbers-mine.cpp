#include <iostream>

using namespace std;
// npm install is-even
int main() {
    int x, y;
    cin >> x >> y;

    for (int i = x; i <= y; ++i) {
        if (i % 2 == 0)
            cout << i << " ";
    }

    return 0;
}
