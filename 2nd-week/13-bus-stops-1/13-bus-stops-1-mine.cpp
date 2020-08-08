#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> buses;
map<string, vector<string>> stops;

void newBus(const string& bus, const vector<string>& stopsToSet) {
    // Filling bus entry with all stops and all stops entry with bus
    for (const auto& stop : stopsToSet) {
        buses[bus].push_back(stop);
        stops[stop].push_back(bus);
    }
}
// Do not forget to erase empty entries, created by braces operator
void busesForStop(const string& stop) {
    if (stops[stop].empty()) {
        cout << "No stop";
        stops.erase(stop);
    }
    else
        for (const auto& bus : stops[stop])
            cout << bus << " ";
    cout << endl;
}

void stopsForBus(const string& bus) {
    if (buses[bus].empty()) {
        buses.erase(bus);
        cout << "No bus" << endl;
    }
    else
        for (const auto& stop : buses[bus]) {
            cout << "Stop " << stop << ": ";
            // If stop entry contains only one bus, then there is no interchange with others
            if (stops[stop].size() == 1 && stops[stop].back() == bus)
                cout << "no interchange" << endl;
            else {
                for (const auto &busItem : stops[stop])
                    if (busItem != bus)
                        cout << busItem << " ";
                cout << endl;
            }
        }
}

void allBuses() {
    if (buses.empty())
        cout << "No buses" << endl;
    else
        for (const auto& bus : buses) {
            cout << "Bus " << bus.first << ": ";
            for (const auto &stop : bus.second)
                cout << stop << " ";
            cout << endl;
        }
}

int main() {
    int n, k;
    cin >> n;
    string command, argument;
    vector<string> arguments;

    for (int i = 0; i < n; ++i) {
        cin >> command;

        if (command == "NEW_BUS") {
            cin >> argument >> k;
            arguments.resize(k);
            for (int j = 0; j < k; ++j) {
                cin >> arguments[j];
            }
            newBus(argument, arguments);
        }

        if (command == "BUSES_FOR_STOP") {
            cin >> argument;
            busesForStop(argument);
        }

        if (command == "STOPS_FOR_BUS") {
            cin >> argument;
            stopsForBus(argument);
        }

        if (command == "ALL_BUSES")
            allBuses();
    }

    return 0;
}
