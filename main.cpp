#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    string rollNo;
    string course;
    string className;
    string contact;
};

vector<Student> students;

void enter() {
    int choice;
    cout<<"How many students do you want to enter: ";
    cin>>choice;

    for(int i=0; i<choice; i++) {
        Student s;
        cout<<"\nEnter data of student "<<i+1<<":\n";
        cout<<"Enter name: ";
        cin>>s.name;
        cout<<"Enter roll no: ";
        cin>>s.rollNo;
        cout<<"Enter course: ";
        cin>>s.course;
        cout<<"Enter class: ";
        cin>>s.className;
        cout<<"Enter contact: ";
        cin>>s.contact;
        students.push_back(s);
    }
}

void show() {
    if(students.empty()) {
        cout<<"No data is entered.\n";
    } else {
        for(size_t i=0;i<students.size();i++) {
            cout<<"\nData of student "<<i+1<<":\n";
            cout<<"Name: "<<students[i].name<<"\n";
            cout<<"Roll No: "<<students[i].rollNo<<"\n";
            cout<<"Course: "<<students[i].course<<"\n";
            cout<<"Class: "<<students[i].className<<"\n";
            cout<<"Contact: "<<students[i].contact<<"\n";
        }
    }
}

void search() {
    if(students.empty()) {
        cout<<"No data is entered.\n";
    } else {
        string rollNo;
        cout<<"Enter roll no of student to search: ";
        cin>>rollNo;
        bool found = false;

        for(const auto& s :students) {
            if(s.rollNo == rollNo) {
                cout<<"\nData of student:\n";
                cout<<"Name: "<<s.name<<"\n";
                cout<<"Roll No: "<<s.rollNo<<"\n";
                cout<<"Course: "<<s.course<<"\n";
                cout<<"Class: "<<s.className<<"\n";
                cout<<"Contact: "<<s.contact<<"\n";
                found = true;
                break;
            }
        }

        if(!found) {
            cout<<"Student with roll no "<<rollNo<<" not found.\n";
        }
    }
}

void update() {
    if(students.empty()) {
        cout<<"No data is entered.\n";
    } else {
        string rollNo;
        cout<<"Enter roll no of student to update: ";
        cin>>rollNo;
        bool found = false;

        for(auto& s :students) {
            if(s.rollNo == rollNo) {
                cout<<"\nPrevious data:\n";
                cout<<"Name: "<<s.name<<"\n";
                cout<<"Roll No: "<<s.rollNo<<"\n";
                cout<<"Course: "<<s.course<<"\n";
                cout<<"Class: "<<s.className<<"\n";
                cout<<"Contact: "<<s.contact<<"\n";

                cout<<"\nEnter new data:\n";
                cout<<"Enter name: ";
                cin>>s.name;
                cout<<"Enter roll no: ";
                cin>>s.rollNo;
                cout<<"Enter course: ";
                cin>>s.course;
                cout<<"Enter class: ";
                cin>>s.className;
                cout<<"Enter contact: ";
                cin>>s.contact;
                found = true;
                break;
            }
        }

        if(!found) {
            cout<<"Student with roll no "<<rollNo<<" not found.\n";
        }
    }
}

void deleteRecord() {
    if(students.empty()) {
        cout<<"No data is entered.\n";
    } else {
        int choice;
        cout<<"Press 1 to delete all records.\n";
        cout<<"Press 2 to delete a specific record.\n";
        cin>>choice;

        if(choice == 1) {
            students.clear();
            cout<<"All records deleted.\n";
        } else if(choice == 2) {
            string rollNo;
            cout<<"Enter roll no to delete: ";
            cin>>rollNo;
            auto it = remove_if(students.begin(), students.end(), [&](const Student& s) {
                return s.rollNo == rollNo;
            });

            if(it != students.end()) {
                students.erase(it, students.end());
                cout<<"Record deleted.\n";
            } else {
                cout<<"Student with roll no "<<rollNo<<" not found.\n";
            }
        } else {
            cout<<"Invalid choice.\n";
        }
    }
}

int main() {
    while(true) {
        int value;
        cout<<"\nPress 1 to enter data.\n";
        cout<<"Press 2 to show data.\n";
        cout<<"Press 3 to search data.\n";
        cout<<"Press 4 to update data.\n";
        cout<<"Press 5 to delete data.\n";
        cout<<"Press 6 to exit.\n";
        cin>>value;

        switch(value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                exit(0);
            default:
                cout<<"Invalid input.\n";
                break;
        }
    }

    return 0;
}
