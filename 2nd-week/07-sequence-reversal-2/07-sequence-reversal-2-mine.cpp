#include <vector>
#include <algorithm>

using namespace std;
// Returning copy now
vector<int> Reversed(const vector<int>& v) {
    vector<int> a = v;
    reverse(begin(a), end(a));

    return a;
}
