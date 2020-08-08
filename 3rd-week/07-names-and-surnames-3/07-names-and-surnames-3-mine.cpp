#include <map>
#include <vector>
#include <string>

using namespace std;
// Adding birth year feature - no one can have name until birth. Other functionality is not affected
class Person {
public:
    Person(const string& n, const string& f, const int& y) {
        first_names[y] = n;
        last_names[y] = f;
        birthYear = y;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year < birthYear)
            return;
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year < birthYear)
            return;
        last_names[year] = last_name;
    }

    string GetFullName(int year) const {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        if (first_name.empty() && last_name.empty()) {
            if (year < birthYear)
                return "No person";
            return "Incognito";
        }
        else if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name";
        else
            return first_name + " " + last_name;
    }

    string GetFullNameWithHistory(int year) const {
        vector<string> firstNames;
        vector<string> lastNames;
        string result;

        for (const auto& name : first_names)
            if (name.first <= year)
                firstNames.push_back(name.second);

        for (const auto& name : last_names)
            if (name.first <= year)
                lastNames.push_back(name.second);

        if (firstNames.size() <= 1 && lastNames.size() <= 1)
            return GetFullName(year);

        if (firstNames.empty())
            return addArchiveNames(lastNames, "") + " with unknown first name";
        else
            result = addArchiveNames(firstNames, "");

        result += " ";

        if (lastNames.empty())
            return result + "with unknown last name";
        else
            result = addArchiveNames(lastNames, result);

        return result;
    }

private:
    int birthYear;
    map<int, string> first_names;
    map<int, string> last_names;

    static string FindNameByYear(const map<int, string>& names, int year) {
        string name;

        for (const auto& item : names)
            if (item.first <= year)
                name = item.second;
            else
                break;

        return name;
    }

    static string addArchiveNames(vector<string> names, const string& income) {
        string result = names.back() + "";

        if (names.size() > 1)
            result += " (";

        for (int i = names.size()-2; i >= 0; --i) {
            if (names[i] == names[i+1])
                continue;
            result += names[i] + ", ";
        }

        if (names.size() > 1) {
            result.erase(result.size() - 2, 2);

            if (result.find('(') < result.size())
                result += ")";
        }

        return income + result;
    }
};
