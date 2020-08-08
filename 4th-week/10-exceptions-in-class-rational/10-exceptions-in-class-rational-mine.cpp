#include <iostream>
#include <sstream>
#include <numeric>
#include <stdexcept>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    // Adding exception to division by zero
    Rational(int numerator, int denominator) {
        if (denominator == 0)
            throw invalid_argument("");

        this->numerator = numerator / gcd(numerator, denominator);
        this->denominator = denominator / gcd(numerator, denominator);

        if ((this->numerator > 0 && this->denominator < 0) || this->numerator < 0 && this->denominator > 0) {
            this->numerator = -abs(this->numerator);
            this->denominator = abs(this->denominator);
        }
        else if (this->numerator < 0 && this->denominator < 0) {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
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

Rational operator +(Rational a, Rational b) {
    return Rational(a.Numerator() * lcm(a.Denominator(), b.Denominator()) / a.Denominator() + b.Numerator() * lcm(a.Denominator(), b.Denominator()) / b.Denominator(),
                    lcm(a.Denominator(), b.Denominator()));
}

Rational operator -(Rational a, Rational b) {
    return Rational(a.Numerator() * lcm(a.Denominator(), b.Denominator()) / a.Denominator() - b.Numerator() * lcm(a.Denominator(), b.Denominator()) / b.Denominator(),
                    lcm(a.Denominator(), b.Denominator()));
}

bool operator ==(Rational a, Rational b) {
    return a.Numerator() * lcm(a.Denominator(), b.Denominator()) / a.Denominator() == b.Numerator() * lcm(a.Denominator(), b.Denominator()) / b.Denominator();
}

Rational operator *(Rational a, Rational b) {
    return Rational(a.Numerator()*b.Numerator(), a.Denominator()*b.Denominator());
}
// Adding exception to division by zero
Rational operator /(Rational a, Rational b) {
    if (b.Numerator() == 0)
        throw domain_error("");
    return Rational(a.Numerator()*b.Denominator(), a.Denominator()*b.Numerator());
}

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

bool operator <(Rational a, Rational b) {
    return (b-a).Numerator() > 0;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
