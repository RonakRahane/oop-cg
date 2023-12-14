#include<iostream>
#include<string>
using namespace std;
class Personal;
class Database
{
     int roll_no;
     string name,class_name,dob,blood_grp,address,tel_no;
     char div;
     double lic_no;
     public:
     static int count;
     Database()
    {
        name="ABC";
        roll_no=0;
        class_name="FE";
        div='A';
    }
    void accept(string name,string class_name,char div,int roll_no)
    {
      count++;
      this->name=name;
      this->class_name=class_name;
      this->div=div;
      this->roll_no=roll_no;
    }
    inline void display()
    {
        cout<<"\n\tName : "<<name;
        cout<<"\n\tClass : "<<class_name;
        cout<<"\n\tDivision : "<<div;
        cout<<"\n\tRoll : "<<roll_no;
    }
    ~Database()
    {
    }
    static int show_count();
    friend class Personal;
};
int Database::count=0;
int Database::show_count()
{
   return count;
}
class Personal
{
  public:
    void initialize(Database *ptr)
    {
       ptr->dob="DD/MM/YYYY";
       ptr->blood_grp="o+ve";
       ptr->address="XYZ area";
       ptr->tel_no="1234567890";
       ptr->lic_no=123456;
    }
    void accept (Database *ptr)
    {
   cout<<"Enter the data of birth of the student :";
   cin>>ptr->dob;
   cout<<"Enter the Blood group of the student :";
   cin>>ptr->blood_grp;
   cout<<"Enter the contact address of the student :";
   cin>>ptr->address;
   bool flag=false ;
   while (flag==false)
   {
   try
   {
   cout<<"Enter Telephone number of the student :";
   cin>>ptr->tel_no;

   if (ptr->tel_no.length() >10 || ptr->tel_no.length() <10)
     throw 1;
   else
     break;
  }
  catch (int x)
    {
    cout<<"\n\t Invalid Number. Enter a valid Contact Number!"<<endl;
    }
  }
    cout<<"Enter the Driving License number of the student :";
    cin>>ptr->lic_no;
  }
  void display (Database *ptr)
  {
    cout<<"\n\tDate of Birth: "<<ptr->dob;
    cout<<"\n\tBlood Group : "<<ptr->blood_grp; 
    cout<<"\n\tAddress :    "<<ptr->address;
    cout<<"\n\tContact Number: "<<ptr->tel_no;
    cout<<"\n\tDriving License No. : "<<ptr->lic_no;
  }
  };
  int main()
  {
    int i, n, choice, perrno;
    string pername, perclass;
    char perdiv;
    Database *ptr=NULL,*temp=0;
    Database objd;
    Personal obj;
    cout<<"**Welcome to our Database**"<<endl;
  do
  {
    cout<<"\n\t*****MENU***\n\n\t1.Enter the records\n\t2.Display  default record\n\t3.Display all recorda\n\t4.Exit"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch (choice)
    {
      case 1: cout<<"How many records do you want to enter : "; 
      cin>>n;
      ptr=new Database [n];

      for (temp = ptr,i = 0;temp != NULL && i < n; temp++, i++)

      {
        cout<<"\n Details of Student No. "<<i+1;
        cout<<"\nEnter the Name of the student :";
        cin>>pername;
        cout<<"Enter the Class of the student :";
        cin>>perclass;
        cout<<"Enter the Division of the student :";
        cin>>perdiv;
        cout<<"Enter the Roll No. of the student :";
        cin>>perrno;
        temp ->accept (pername, perclass, perdiv, perrno);
        obj.initialize (temp);
        obj.accept(temp);
  }
  break;
  case 2:{
    cout<<"\n--------------default record ----------------"<<endl;
    objd.display();
    Database *it=&objd;
    obj.initialize(it);
    obj.display(it);
    cout<<"\n\n";
    break;
  }
  case 3: cout<<"\nThe Database has total "<< Database::show_count()<<" records";
  for(temp=ptr,i=0;temp!=NULL&&i<n;temp++,i++)
  {cout<<"\n\n-----------Details of student No"<<i+1<<"--------"<<endl;
  temp->display();
  cout<<"\n\n Personal Details :"<<endl;
  obj.display(temp);
  }
  cout<<"\n\n----------END OF RECORDS IN DATABASE------------"<<endl;
  break;
  case 4: delete[] ptr;
          cout<<"\nData in database has been deleted successfully!";
          cout<<"\n******** End Of Program *********";
          cout<<"\nThank You !";
          break;
  default: cout<<"\n You have entered a wrong choice please Enter a valid choice!";
    }
  } while(choice!=4);
  return 0;
}