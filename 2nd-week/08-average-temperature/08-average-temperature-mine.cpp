#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s = 0, c = 0;
    cin >> n;
    vector<int> numbers(n), indexes;
    // Calculating average
    for (auto& number : numbers) {
        cin >> number;
        s += number;
    }
    s /= n;
    // Saving indexes of days above average
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > s) {
            indexes.push_back(i);
        }
    }
    // Printing number of indexes
    cout << indexes.size() << endl;
    // Printing days indexes
    for (auto index : indexes) {
        cout << index << " ";
    }

    return 0;
}
