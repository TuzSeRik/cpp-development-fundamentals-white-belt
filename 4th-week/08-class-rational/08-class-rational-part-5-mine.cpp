#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        this->numerator = numerator / gcd(numerator, denominator);
        this->denominator = denominator / gcd(numerator, denominator);
        // Handling minus in fraction
        if ((this->numerator > 0 && this->denominator < 0) || this->numerator < 0 && this->denominator > 0) {
            this->numerator = -abs(this->numerator);
            this->denominator = abs(this->denominator);
        }
        // Handling double-negation in fraction
        else if (this->numerator < 0 && this->denominator < 0) {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
        // Casting zero fraction to standard
        else if (this->numerator == 0)
            this->denominator = 1;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator, denominator;
};
// Simple math operators, implemented by casting both numbers to same denominator
Rational operator +(Rational a, Rational b) {
    return Rational(a.Numerator() * lcm(a.Denominator(), b.Denominator()) / a.Denominator() + b.Numerator() * lcm(a.Denominator(), b.Denominator()) / b.Denominator(),
                    lcm(a.Denominator(), b.Denominator()));
}
// And returning new number with resulting fields, because constructor will reduce denominator to minimal
Rational operator -(Rational a, Rational b) {
    return Rational(a.Numerator() * lcm(a.Denominator(), b.Denominator()) / a.Denominator() - b.Numerator() * lcm(a.Denominator(), b.Denominator()) / b.Denominator(),
                    lcm(a.Denominator(), b.Denominator()));
}

bool operator ==(Rational a, Rational b) {
    return a.Numerator() * lcm(a.Denominator(), b.Denominator()) / a.Denominator() == b.Numerator() * lcm(a.Denominator(), b.Denominator()) / b.Denominator();
}
// Transferring the practical rules of multiplication and division of fractions into the program
Rational operator *(Rational a, Rational b) {
    return Rational(a.Numerator()*b.Numerator(), a.Denominator()*b.Denominator());
}

Rational operator /(Rational a, Rational b) {
    return Rational(a.Numerator()*b.Denominator(), a.Denominator()*b.Numerator());
}
// Nothing to comment in simple operators overloading
istream& operator >>(istream& input, Rational& r) {
    int numerator, denominator;
    char deliminator;
    input >> numerator >> deliminator >> denominator;
    if (input && deliminator == '/')
        r = Rational(numerator, denominator);

    return input;
}

ostream& operator <<(ostream& output, Rational r) {
    output << r.Numerator();
    output << "/";
    output << r.Denominator();

    return output;
}
// To reduce complexity, we will just look at sign of result of already overloaded minus operator
// So we do not need to once again cast fractions to same denominator and then compare them
bool operator <(Rational a, Rational b) {
    return (b-a).Numerator() > 0;
}
// Tests, provided by authors
int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
