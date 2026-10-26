#include <iostream>
#include <string>
using namespace std;

struct Student
{
int roll;
string name;
Student *next;
};

Student *head = NULL;
int seats[2][10];

void addStudent()
{
Student *n = new Student;

cout << "Enter roll number: ";
cin >> n->roll;

Student *t = head;

while (t != NULL)
{
    if (t->roll == n->roll)
    {
        cout << "Roll number already exists!\n";
        delete n;
        return;
    }
    t = t->next;
}

cout << "Enter name: ";
cin >> n->name;

n->next = head;
head = n;

cout << "Student added!\n";


}

void display()
{
Student *t = head;


while (t != NULL)
{
    cout << t->roll << " " << t->name << endl;
    t = t->next;
}


}


void allocateSeats()
{
Student *a[20];
int n = 0;


Student *t = head;

while (t != NULL && n < 20)
{
    a[n++] = t;
    t = t->next;
}

if (n == 0)
{
    cout << "No students available!\n";
    return;
}

for (int i = 1; i < n; i++)
{
    Student *key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j]->roll > key->roll)
    {
        a[j + 1] = a[j];
        j--;
    }

    a[j + 1] = key;
}

cout << "\nSeating Arrangement:\n";

for (int i = 0; i < n; i++)
{
    seats[i / 10][i % 10] = a[i]->roll;

    cout << "Roll " << a[i]->roll
         << " (" << a[i]->name << ") - Row "
         << (i / 10) + 1 << ", Seat "
         << (i % 10) + 1 << endl;
}


}

void searchStudent()
{
int r;
cout << "Enter roll number: ";
cin >> r;

Student *t = head;

while (t != NULL)
{
    if (t->roll == r)
    {
        cout << "Found: " << t->name << endl;
        return;
    }
    t = t->next;
}

cout << "Student not found!\n";


}

int main()
{
int ch;

do
{
    cout << "\n1.Add Student\n2.Display Students\n";
    cout << "3.Allocate Seats\n4.Search Student\n5.Exit\n";
    cout << "Enter choice: ";
    cin >> ch;

    switch (ch)
    {
        case 1: addStudent(); break;
        case 2: display(); break;
        case 3: allocateSeats(); break;
        case 4: searchStudent(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
    }

} while (ch != 5);

return 0;


}
