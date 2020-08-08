#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> numberOfDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<vector<string>> calendar;
int currentMonth = 0;
// Don't forget to decrease index by one, because of start from zero in vector
void add(int i, const string& action) {
    i--;
    calendar[i].push_back(action);
}

void dump(int i) {
    i--;
    cout << calendar[i].size() << " ";
    for (const auto& chore : calendar[i])
        cout << chore << " ";
    cout << endl;
}

void next() {
    int before = numberOfDays[currentMonth];
    currentMonth++;
    // Overflow protection
    if (currentMonth >= 12)
        currentMonth = 0;
    int now = numberOfDays[currentMonth];
    // If current month is smaller than previous, add all excluded tasks to end of this month
    if (now < before) {
        for (int i = now; i <= before - 1; ++i) {
            for (const auto& chore : calendar[i])
                add(now, chore);
        }
    }
    calendar.resize(now, {});
}

int main() {
    int n, k;
    string command, action;
    cin >> n;
    calendar.resize(numberOfDays[currentMonth], {});

    for (int i = 0; i < n; ++i) {
        cin >> command;

        if (command == "ADD") {
            cin >> k >> action;
            add(k, action);
        }

        if (command == "DUMP") {
            cin >> k;
            dump(k);
        }

        if (command == "NEXT")
            next();
    }

    return 0;
}
