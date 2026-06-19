#include <iostream>
using namespace std;



int main() {

    typedef struct
    {
        int ID;
        string name;
        string course;
        int age;

    } STUDENT;
    
    STUDENT student [5];
    student[0] = {1001, "yana", "computer science", 20 };
    student[1] = {1002, "alisa", "computer science", 20 };
    student[2] = {1003, "farzana", "computer science", 20 };
    student[3] = {1004, "menna", "computer science", 20 };
    student[04] = {1005, "zahidah", "computer science", 20 };

    //OUTPUT
    for (int i=0; i<5; i++)
    {
        cout<<"******* Student "<<i+1<<" *******"<<endl;
        cout<<"ID : "<<student[i].ID<<endl;
        cout<<"Name : "<<student[i].name<<endl;
        cout<<"Course : "<<student[i].course<<endl;
        cout<<"Age : "<<student[i].age<<endl<<endl;
    }

    int studentid;

    //Search in database
    cout<<"Search in database: "; cin>>studentid;

    for (int i=0; i<5; i++)
    {
        if (studentid == student[i].ID)
        {
            cout<<"******* Student "<<i+1<<" *******"<<endl;
            cout<<"ID : "<<student[i].ID<<endl;
            cout<<"Name : "<<student[i].name<<endl;
            cout<<"Course : "<<student[i].course<<endl;
            cout<<"Age : "<<student[i].age<<endl<<endl;
        }
    }

    //Update student record
    int x, y;
    cout<<endl<<"Update one student record: "; cin>>y;
    cout<<"1. ID"<<endl;
    cout<<"2. Name"<<endl;
    cout<<"3. Course"<<endl;
    cout<<"4. Age"<<endl;
    cout<<"What do you want to change?: "; cin>>x;

    for (int i=0; i<5; i++)
    {
        if (studentid == student[i].ID)
        {
            switch (x)
            {
                case 1: cout<<"ID : "; cin>>student[i].ID; break;
                case 2: cout<<"Name : "; cin>>student[i].name; break;
                case 3: cout<<"Course : "; cin>>student[i].course; break;
                case 4: cout<<"Age : "; cin>>student[i].age; break;
            }

            //Display updated
            cout<<endl<<"******* Student "<<i+1<<" *******"<<endl;
            cout<<"ID : "<<student[i].ID<<endl;
            cout<<"Name : "<<student[i].name<<endl;
            cout<<"Course : "<<student[i].course<<endl;
            cout<<"Age : "<<student[i].age<<endl;
        }
    }
    

    return 0;

}