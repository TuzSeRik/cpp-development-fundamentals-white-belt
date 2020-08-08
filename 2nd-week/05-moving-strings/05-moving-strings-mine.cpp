#include <vector>
#include <string>

using namespace std;
// Very strange task
void MoveStrings(vector<string>& a, vector<string>& b) {
    for (auto word : a) {
        b.push_back(word);
    }

    a.clear();
}
