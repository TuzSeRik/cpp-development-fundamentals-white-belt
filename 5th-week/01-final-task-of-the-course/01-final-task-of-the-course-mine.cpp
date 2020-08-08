#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() = default;
    // Simple structure for further needs
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    [[nodiscard]] int GetYear() const {
        return year;
    }

    [[nodiscard]] int GetMonth() const {
        return month;
    }
    [[nodiscard]] int GetDay() const {
        return day;
    }

private:
    int year, month, day;
};
// Reduce comparing of object to comparing of vectors
bool operator <(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

istream& operator >>(istream& input, Date& date) {
    stringstream ss;
    string str;
    int year, month, day;

    try {
        input >> str;
        ss << str;
        // Reading date
        ss >> year;
        if (ss.peek() != '-')
            throw exception();
        ss.ignore(1);
        ss >> month;
        if (ss.peek() != '-')
            throw exception();
        ss.ignore(1);
        ss >> day;

        if (str.back() > 57 || str.back() < 48)
            throw exception();
        if (month < 1 || month > 12)
            throw invalid_argument("Month value is invalid: " + to_string(month));
        if (day < 1 || day > 31)
            throw invalid_argument("Day value is invalid: " + to_string(day));

        date = Date(year, month, day);
    }
    catch (invalid_argument& e) {
        throw;
    }
    catch (exception&) {
        throw invalid_argument("Wrong date format: " + str);
    }

    return input;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        db[date].insert(event);
    }
    // Don't forget to delete empty entries
    bool DeleteEvent(const Date& date, const string& event) {
        auto temp = find(begin(db[date]), end(db[date]), event);
        if (temp != end(db[date])) {
            db[date].erase(temp);
            if (db[date].empty())
                db.erase(date);

            return true;
        }
        else {
            if (db[date].empty())
                db.erase(date);

            return false;
        }
    }

    int DeleteDate(const Date& date) {
        int temp = db[date].size();
        db.erase(date);

        return temp;
    }

    [[nodiscard]] set<string> Find(const Date& date) const {
        return db.at(date);
    }

    void Print() const {
        for (auto i : db) {
            for (const auto& j : i.second)
                cout << setw(4) << setfill('0') << i.first.GetYear() << "-"
                     << setw(2) << setfill('0') << i.first.GetMonth() << "-"
                     << setw(2) << setfill('0') << i.first.GetDay() << " " << j << endl;
        }
    }

private:
    map<Date, set<string>> db;
};
// Control part of database
int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        stringstream ss;
        ss << command;
        ss >> command;

        if (command.empty())
            continue;

        if (command == "Add") {
            Date date{};
            string event;

            try {
                ss >> date;
                ss >> event;
                db.AddEvent(date, event);
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
                return 0;
            }

            continue;
        }

        if (command == "Del") {
            Date date{};
            string event;

            try {
                ss >> date;
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
                return 0;
            }
            ss >> event;

            if (!event.empty())
                cout << (db.DeleteEvent(date, event)? "Deleted successfully" : "Event not found") << endl;
            else
                cout << "Deleted " << db.DeleteDate(date) << " events" << endl;

            continue;
        }

        if (command == "Find") {
            Date date{};

            try {
                ss >> date;
                auto temp = db.Find(date);
                for (const auto& i : temp)
                    cout << i << endl;
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
                return 0;
            }
            catch (out_of_range&) {
                return 0;
            }

            continue;
        }

        if (command == "Print") {
            db.Print();
            continue;
        }
        // If no command was provided, than it is time to stop a cycle
        cout << "Unknown command: " << command << endl;
        break;
    }

    return 0;
}
