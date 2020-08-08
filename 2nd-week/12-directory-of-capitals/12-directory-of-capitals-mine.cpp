#include <iostream>
#include <string>
#include <map>

using namespace std;
// Map, containing all country/capital mappings
map<string, string> world;

void changeCapital(const string& country, const string& newCapital) {
    if (world[country].empty()) {
        world[country] = newCapital;
        cout << "Introduce new country " << country <<" with capital " << newCapital << endl;
    }
    else if (world[country] == newCapital)
        cout << "Country " << country <<" hasn't changed its capital" << endl;
    else {
        cout << "Country " << country << " has changed its capital from " << world[country] << " to " << newCapital << endl;
        world[country] = newCapital;
    }
}

void rename(const string& oldName, const string& newName) {
    if (world[oldName].empty() || oldName == newName || !world[newName].empty()) {
        // Deleting empty entries, created by condition
        if (world[oldName].empty())
            world.erase(oldName);
        if (world[newName].empty())
            world.erase(newName);
        cout << "Incorrect rename, skip" << endl;
    }
    else {
        world[newName] = world[oldName];
        world.erase(oldName);
        cout << "Country " << oldName << " with capital " << world[newName] <<" has been renamed to " << newName << endl;
    }
}

void about(const string& country) {
    if (world[country].empty()) {
        // Deleting empty entries, created by condition
        world.erase(country);
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else
        cout << "Country " << country << " has capital " << world[country] << endl;
}

void dump() {
    if (world.empty())
        cout << "There are no countries in the world" << endl;
    else
        for (const auto& country : world) {
            cout << country.first << "/" << country.second << " " << endl;
        }
}

int main() {
    int n;
    string command, argument1, argument2;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> command;

        if (command == "CHANGE_CAPITAL") {
            cin >> argument1 >> argument2;
            changeCapital(argument1, argument2);
        }

        if (command == "RENAME") {
            cin >> argument1 >> argument2;
            rename(argument1, argument2);
        }

        if (command == "ABOUT") {
            cin >> argument1;
            about(argument1);
        }

        if (command == "DUMP")
            dump();
    }

    return 0;
}
