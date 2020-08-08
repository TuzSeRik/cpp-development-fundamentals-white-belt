#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    string date;
};
// Creating vector of simple structures and returning their fields if requested
int main() {
    vector<Student> students;
    string command, familyName, firstName, day, month, year;
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> firstName >> familyName >> day >> month >> year;
        students.push_back({firstName + " " + familyName, day + "." + month + "." + year});
    }

    cin >> n;
    for (int j = 0; j < n; ++j) {
        int k;
        cin >> command >> k;
        // Decreasing index
        k--;

        if (command == "name" && k < students.size())
            cout << students[k].name << endl;
        else if (command == "date" && k < students.size())
            cout << students[k].date << endl;
        else cout << "bad request" << endl;
    }

    return 0;
}
