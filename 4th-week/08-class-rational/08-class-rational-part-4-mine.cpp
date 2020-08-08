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
// Tests, provided by authors
int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
