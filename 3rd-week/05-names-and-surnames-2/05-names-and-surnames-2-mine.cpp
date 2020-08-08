#include <map>
#include <vector>
#include <string>

using namespace std;
// Using previous solution to provide old functionality
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        if (first_name.empty() && last_name.empty())
            return "Incognito";
        else if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name";
        else
            return first_name + " " + last_name;
    }
    // Adding functionality to retrieve full names with history of changes
    string GetFullNameWithHistory(int year) {
        vector<string> firstNames;
        vector<string> lastNames;
        string result;
        // Getting vectors of suitable name and surnames
        for (const auto& name : first_names)
            if (name.first <= year)
                firstNames.push_back(name.second);

        for (const auto& name : last_names)
            if (name.first <= year)
                lastNames.push_back(name.second);
        // If there is no changes, return simple full name
        if (firstNames.size() <= 1 && lastNames.size() <= 1)
            return GetFullName(year);
        // Otherwise, checking for special cases
        if (firstNames.empty())
            return addArchiveNames(lastNames, "") + " with unknown first name";
        else
            result = addArchiveNames(firstNames, "");

        result += " ";
        // Or returning full name with history
        if (lastNames.empty())
            return result + "with unknown last name";
        else
            result = addArchiveNames(lastNames, result);

        return result;
    }

private:
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
        // Adding unique names to returning part of full name
        for (int i = names.size() - 2; i >= 0; --i) {
            if (names[i] == names[i+1])
                continue;
            result += names[i] + ", ";
        }
        // If there are history, delete last point plus space and adding closing bracket, if there was opening one
        if (names.size() > 1) {
            result.erase(result.size() - 2, 2);
            if (result.find('(') < result.size())
                result += ")";
        }
        // Returning given string plus added part
        return income + result;
    }
};
