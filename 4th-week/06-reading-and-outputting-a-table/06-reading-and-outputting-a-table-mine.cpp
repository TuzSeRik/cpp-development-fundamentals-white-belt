#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
// Once upon a time I was writing a whole Java library to do the same thing...
int main() {
    ifstream file("input.txt");
    int n, k;
    file >> n >> k;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int temp;
            file >> temp;
            file.ignore(1);

            if (j != k)
                cout << setw(10) << right << temp << " ";
            else if (i != n)
                cout << setw(10) << right << temp << endl;
            else
                cout << setw(10) << right << temp;
        }
    }

    return 0;
}
