#include <string>
#include <algorithm>

using namespace std;
// Simple wrap around standard string, to provide class functionality and in-built reverse method
class ReversibleString {
public:
    ReversibleString() {}

    ReversibleString(const string& tmp){
        str = tmp;
    }

    void Reverse() {
        reverse(begin(str), end(str));
    }

    string ToString() const {
        return str;
    }

private:
    string str;
};
