#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
// Learning how to write precisely
int main() {
    ifstream file("input.txt");
    double out;

    cout << fixed << setprecision(3);
    while (file >> out)
        cout << out << endl;

    return 0;
}
