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
// Only adding control part of calculator - class Rational was taken from previous tasks
int main() {
    Rational a, b;
    string command;

    try {
        cin >> a >> command >> b;

        if (command == "+")
            cout << a + b;
        if (command == "-")
            cout << a - b;
        if (command == "*")
            cout << a * b;
        if (command == "/")
            cout << a / b;
    }
    catch (invalid_argument&) {
        cout << "Invalid argument";
    }
    catch (domain_error&) {
        cout << "Division by zero";
    }

    return 0;
}
