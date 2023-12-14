#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Employee
{
    string name, designation;
    int id;
    double salary;
    public:
        Employee ()
        {
            name="None";
            id=0;
            designation="None";
            salary=0;
        }
        void accept (int x)
        {
            cout<<"\n\nEnter the details of Employee No. "<<x+1<<":";
            cout<<"\n\tEnter the Employee Name: ";
            cin>>name;
            cout<<"\tEnter the Employee ID : ";
            cin>>id;
            cout<<"\tEnter the designation of the Employee : ";
            cin>>designation;
            cout<<"\tEnter the salary of the Employee: Rs.";
            cin>>salary;
        }
        void display(int x)
        {
        cout<<"\n\n-------- Details of Employee No. "<<x+1<<" ---------";
        cout<<"\n\tName: "<<name;
        cout<<"\n\tEmployee ID: "<<id;
        cout<<"\n\tDesignation: "<<designation;
        cout<<"\n\tSalary: Rs."<<salary;
        }
};
int main()
{
    int choice, n, i;
    cout<<"\t\tWELCOME TO EMPLOYEE DATABASE";
    cout<<"\nHow many employee records would you like to enter ?";
    cin>>n;
    Employee obj[n];
    ofstream fout;
    ifstream fin;
    do
    {
        cout<<"\n\n\t\t****** MENU ******";
        cout<<"\n\tl.Write Employee Details into File\n\t2.Read Employee Details from File\n\t3.Exit\n";
        cout<<"\nEnter your choice: ";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: fout.open("Employee Records.dat", ios:: out); 
            cout<<"\nEmployee File has been opened for writing."; 
            cout<<"\n\tWriting Employee Information to File...."; 
            for(i=0;i<n;i++)
            {
            obj[i].accept (i); 
            fout.write((char*) &obj[i], sizeof (obj[i]));
            }
            cout<<"\nEmployee Information written to File successfully !";
            fout.close(); 
            cout<<"\nEmployee File has been closed.";
            break;

            case 2: fin.open("Employee Records.dat", ios::in);
            cout<<"\nEmployee File has been opened for reading."; 
            cout<<"\n\tReading Employee Information from File....";
            for(i=0;i<n;i++)
            {
            fin.read((char*) &obj[i], sizeof (obj[i]));
            obj[i].display(i);
            }
            cout<<"\nEmployee Information read from File successfully !"; 
            fin.close();
            cout<<"\nEmployee Information written to File successfully!";
            fout.close();
            cout<<"\nEmployee File has been closed.";
            break;
            case 3: cout<<"\n\t-------- EXIT---------";
            break;
            default: cout<<"\n Your have entered an invalid choice. Enter a valid choice!";
        }  
    }
    while(choice!=3);
    cout<<"\n*** End of Program ***";
    cout<<"\nThank You !";
    return 0;
}
