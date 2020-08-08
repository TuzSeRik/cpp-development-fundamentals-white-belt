#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        cin >> result[i];
    }
    // Using lambda to compare absolute values of operands
    sort(begin(result), end(result), [](const int& a, const int& b) -> bool {
        return abs(a) < abs(b);
    });

    for (const auto& i : result) {
        cout << i << " ";
    }

    return 0;
}
