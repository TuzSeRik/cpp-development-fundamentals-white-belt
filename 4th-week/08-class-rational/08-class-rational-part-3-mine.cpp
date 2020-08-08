#include <iostream>
#include <sstream>
#include <numeric>

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
// Tests, provided by authors
int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
