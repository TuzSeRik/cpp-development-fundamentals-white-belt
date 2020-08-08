#include <iostream>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstNameHistory[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        lastNameHistory[year] = last_name;
    }

    string GetFullName(int year) {
        string firstName;
        string lastName;
        // Iterating from year backwards, to find nearest names, lower than year
        for (int i = year; i >= 0 ; --i) {
            if (!firstNameHistory[i].empty() && firstName.empty())
                firstName = firstNameHistory[i];

            if (!lastNameHistory[i].empty() && lastName.empty())
                lastName = lastNameHistory[i];

            if (!firstName.empty() && !lastName.empty())
                break;
        }
        // If after iterating some of fields are empty, returning special cases
        if (firstName.empty() && lastName.empty())
            return "Incognito";

        if (lastName.empty())
            return firstName + " with unknown last name";

        if (firstName.empty())
            return lastName + " with unknown first name";

        return firstName + " " + lastName;
    }
// Storing history of names in maps
private:
    map<int, string> firstNameHistory;
    map<int, string> lastNameHistory;
};
