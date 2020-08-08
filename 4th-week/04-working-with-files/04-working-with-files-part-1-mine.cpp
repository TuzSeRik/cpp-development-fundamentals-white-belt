#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Learning how to read
int main() {
    ifstream file("input.txt");
    string out;

    while (getline(file, out))
        cout << out << endl;

    return 0;
}
