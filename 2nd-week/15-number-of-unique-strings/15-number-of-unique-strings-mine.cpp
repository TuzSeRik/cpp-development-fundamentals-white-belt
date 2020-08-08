#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> st;
    string temp;
    int n;
    cin >> n;
    // Finding number by main set feature - uniqueness of elements
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        st.insert(temp);
    }

    cout << st.size();

    return 0;
}
