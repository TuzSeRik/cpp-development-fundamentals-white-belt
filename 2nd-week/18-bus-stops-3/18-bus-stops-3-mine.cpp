#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    map<set<string>, int> routes;
    int n, k;
    cin >> n;
    // Using set to treat all combinations of same stops as same key
    for (int i = 0; i < n; ++i) {
        set<string> stops;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            string temp;
            cin >> temp;
            stops.insert(temp);
        }

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
