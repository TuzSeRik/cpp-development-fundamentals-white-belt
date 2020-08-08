#include <iostream>
#include <cmath>

using namespace std;
// Time to check what remains of knowledge of school math
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    // No equation
    if (a == 0 && b == 0 && c != 0) return 0;
    // Answer is zero only
    if ((a == 0 && b != 0 && c == 0) || (a != 0 && b == 0 && c == 0)) {
        cout << 0;
        return 0;
    }
    // Linear equation
    if (a ==0 & b != 0 && c != 0) {
        cout << -c / b;
        return 0;
    }
    // Answer may not exist
    if (a != 0 && b == 0 & c != 0) {
        (c > 0) ? cout << "" : cout << sqrt(-c / a);
    }
    // Standard quadratic equation
    double d = b * b - 4 * a * c;
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << x1 << " " << x2;
    }
    else if (d == 0) {
        double x1 = (-b) / (2 * a);
        cout << x1;
    }

    return 0;
}
