#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    string id;

public:
    Student(string n, string i) : name(n), id(i) {}

    virtual void displayInfo() const
    {
        cout << "Name: " << name << ", ID: " << id;
    }

    virtual ~Student() = default;
};

class CollegeStudent : public Student
{
private:
    string major;
    double gpa;

public:
    CollegeStudent(string n, string i, string m, double g)
        : Student(n, i), major(m), gpa(g) {}

    void displayInfo() const override
    {
        cout << "Name: " << name << ", ID: " << id
             << ", Major: " << major << ", GPA: " << gpa;
    }
};

class GraduateStudent : public Student
{
private:
    string researchTopic;

public:
    GraduateStudent(string n, string i, string topic)
        : Student(n, i), researchTopic(topic) {}

    void displayInfo() const override
    {
        cout << "Name: " << name << ", ID: " << id
             << ", Topic: " << researchTopic;
    }
};

class Project
{
private:
    string projectName;
    GraduateStudent leader;
    CollegeStudent member;

public:
    Project(string pName, const GraduateStudent& l, const CollegeStudent& m)
        : projectName(pName), leader(l), member(m) {}

    void displayProjectInfo() const
    {
        cout << "Project: " << projectName << endl;

        cout << "Leader: ";
        leader.displayInfo();
        cout << endl;

        cout << "Member: ";
        member.displayInfo();
        cout << endl;
    }
};

int main()
{
    GraduateStudent grad("Scott", "M011", "Artificial Intelligence");
    CollegeStudent college("Tom", "CS001", "Computer Science", 3.1);

    cout << "--- Individual Student Info ---" << endl;
    grad.displayInfo();
    cout << endl;
    college.displayInfo();
    cout << endl << endl;

    Project project("AI in Agricultural Waste", grad, college);

    cout << "--- Project Info (Composition) ---" << endl;
    project.displayProjectInfo();
    cout << endl;

    cout << "--- Polymorphism Demo ---" << endl;
    Student* s1 = &grad;
    Student* s2 = &college;

    s1->displayInfo();
    cout << endl;
    s2->displayInfo();
    cout << endl;

    return 0;
}