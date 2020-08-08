#include <iostream>

using namespace std;
// Tasks continues to be self-evident
int main() {
    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;

    if (N > B) {
        N *= 1.0 - Y / 100;
    }
    else if (N > A) {
        N *= 1.0 - X / 100;
    }

    cout << N;

    return 0;
}
