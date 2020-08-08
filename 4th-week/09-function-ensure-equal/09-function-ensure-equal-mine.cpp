#include <string>
#include <stdexcept>

using namespace std;
// Solving simple things by using exceptions
void EnsureEqual(const string& left, const string& right) {
    if (left != right)
        throw runtime_error(left + " != " + right);
}
