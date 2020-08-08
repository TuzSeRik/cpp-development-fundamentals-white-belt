#include <string>

using namespace std;
// Simple example of argument validation by structure
struct Specialization {
    string name;

    explicit Specialization(string value) {
        name = value;
    }
};

struct Course {
    string name;

    explicit Course(string value) {
        name = value;
    }
};

struct Week {
    string name;

    explicit Week(string value) {
        name = value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization s, Course c, Week w) {
        specialization = s.name;
        course = c.name;
        week = w.name;
    }
};
