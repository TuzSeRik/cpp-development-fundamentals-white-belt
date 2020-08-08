#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
// A little bit simplified version of previous task
int main() {
    map<vector<string>, int> routes;
    vector<string> stops;
    int n, k;
    cin >> n;
    // Read all stops
    for (int i = 0; i < n; ++i) {
        cin >> k;
        stops.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> stops[j];
        }
        // Do not deleting empty entry to start naming from "1"
        if (routes[stops] == 0) {
            int temp = routes.size();
            routes[stops] = temp;
            cout << "New bus " << temp << endl;
        }
        else
            cout << "Already exists for " << routes[stops] << endl;
    }

    return 0;
}
