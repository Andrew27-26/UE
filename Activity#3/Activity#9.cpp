#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> courseA, courseB;

    courseA.push("DSA");
    courseA.push("This is from A");

    courseB.push("DBMS");
    courseB.push("This is from B");

    courseA.swap(courseB);

    cout << "Course A Top: " << courseA.top() << endl;
    cout << "Course B Top: "<< courseB.top() << endl;

    return 0;
}
