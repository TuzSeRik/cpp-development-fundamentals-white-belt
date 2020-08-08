#include <string>
#include <map>
#include <set>

using namespace std;
// Take element from map, insert it to set. Profit!!!
set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;

    for (const auto& item : m)
        result.insert(item.second);

    return result;
}
