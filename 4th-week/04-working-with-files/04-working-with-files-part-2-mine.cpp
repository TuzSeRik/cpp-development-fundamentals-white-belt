#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Learning how to write
int main() {
    ifstream file("input.txt");
    ofstream outFile("output.txt");
    string out;

    while (getline(file, out))
        outFile << out << endl;

    return 0;
}
