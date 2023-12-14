#oop1

#include<iostream>
#include<string>
using namespace std;

class Complex
{
  float real, img;
  public:
    Complex ()
    {
       real=0.0;
       img=0.0;
    }
    Complex operator + (Complex obj)
    {
    Complex temp;
    temp.real=real+obj.real; 
    temp.img=img+obj.img;
    return temp;
    }
    Complex operator *(Complex obj)
    {
    Complex temp;
    temp.real=(real*obj.real) - (img*obj.img);
    temp.img=(real*obj.img)+(img*obj.real);
    return temp;
    }
    friend istream& operator >>(istream&, Complex&);
    friend ostream& operator <<(ostream&, Complex&);
    void display (string ch)
    {
    cout<<"\nThe "<<ch<<" number is: "<<real<<"+"<<img<<"i";
    }
};
istream& operator >>(istream& in, Complex& obj)
{
in>>obj.real;
in>>obj.img;
return in;
}
ostream& operator <<(ostream& out, Complex& obj)
{
 out<<obj.real<<"+"<<obj.img<<"i";
 return out;
}
int main()
{
  float r, i;
  int choice;
  Complex obj1, obj2, result;
  cout<<"\n-----Enter the First number----"<<endl;
  cout<<"\tEnter the real and imaginary part : ";
  cin>>obj1;
  cout<<"\n-----Enter the Second number-----"<<endl; 
  cout<<"\tEnter the real and imaginary part: ";
  cin>>obj2;
  do
  {
   cout<<"\n********* MENU *********"<<endl<<"\tl.Addition of complex numbers\n"; 
   cout<<"\t2.Multiplication of complex numbers\n\t3.Display the result\n\t4.Exit\n"; 
   cout<<"\nEnter your choice: ";
   cin>>choice;
   switch (choice)
   {
    case 1: obj1.display("first"); 
            obj2.display("second"); 
            result=obj1+obj2;
            break;

    case 2: obj1.display("first"); 
            obj2.display("second"); 
            result=obj1*obj2;
            break;
    case 3: cout<<"\nThe result is: "<<result<<endl;
            break;
   }
  }
  while (choice!=4);
  cout<<"Thank You !";
  cout<<"\n\t****** End of Program ******"<<endl;
  return 0;
}

#oop2

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

#oop3

#include<iostream>
#include<string>

using namespace std;
class Publication
{
    string name;
    float price;
    public:
        Publication ()
        {
        name="None";
        price=0.0;
        }
        void getdata (string s)
        {
            cout<<"\nEnter the name of the "<<s<<" : ";
            cin>>name;
            bool flag=false;
            while (flag==false)
            {
                cout<<"Enter the price of the "<<s<<" : Rs.";
                cin>>price;
                try
                {
                    if (price<=0)
                      throw price;
                    else
                      flag=true;
                }
                catch (float x)
                {
                    price=0.0;
                    cout<<"\nYou have entered price to be "<<x<<" which is an invalid search input."; 
                    cout<<"\nValue of Price has been set to "<<price;
                    cout<<"\nPlease enter a valid input!"<<endl;
                }
            }
        }
        inline string getname()
        {
            return name;
        }
        inline float getprice()
        {
            return price;
        }
        ~Publication ()
        {
        }
};
class Book: public Publication
{
    int pages;
    public:
        Book ()
        {
          pages=0;
        }
        void getpages()
        {
            bool flag=false; 
            while (flag==false)
            {
                cout<<"Enter the number of pages in the book: "; 
                cin>>pages;
                try
                {
                if (pages<-0)
                    throw pages;
                else
                    flag=true;
                }
                catch (int x)
                {
                  pages=0;
                  cout<<"\nYou have entered number of pages to be "<<x<<" which is an invalid search input."; 
                  cout<<"\nValue of Number of Pages has been set to "<<pages;
                  cout<<"\nPlease enter a valid input!"<<endl;
                }
            }
        }
        void display()
        {
            cout<<"\tBook Found !"<<endl;
            cout<<"\n\t Details of Book \n";
            cout<<"\n\tName of the Book: "<<getname();
            cout<<"\n\tNumber of pages : "<<pages;
            cout<<"\n\tPrice: Rs."<<getprice () <<"/-";
        }
        ~Book ()
        {
        }
};
class Tape:public Publication
{
   float time;
   public:
      Tape ()
      {
         time=0.0;
      } 
      void gettime ()
      {
        bool flag=false;
        while(flag==false)
        {
            cout<<"Enter the playing time of the tape (in minn) :";
            cin>>time;
            try
            {
                if (time<=0)
                   throw time;
                else
                   flag=true;
            }
            catch (float x)
            {
                time=0.0;
                cout<<"\nYou have entered the playing time of audio cassette to be "<<x<<" mins which is an invalid search input." ;
                cout<<"\nValue of Playing Time has been set to "<<time;
                cout<<"\nPlease enter a valid input!";
            }
        }
      }
      void display()
      {
        cout<<"\tAudio Cassette Found "<<endl;
        cout<<"\n\t -------- Details of Audio Cassette --------\n";
        cout<<"\n\tName of the Tape : "<<getname(); 
        cout<<"\n\tPlaying time :"<<time<<" mins";
        cout<<"\n\tPrice: Rs."<<getprice() <<"/-";
      }
      ~Tape ()
      {
      }
};
int main()
{
    int choice;
    string n;
    Book objb;
    Tape objt;
    cout<<"\t\tWELCOME TO OUR COMPANY'S MARKETING SITE\n"<<endl;
    do
    {
        cout<<"\n\t*** Menu ***\n";
        cout<<"\tl.Search for a Book\n\t2. Search for an Audio Cassette \n\t3.Display Book Details";
        cout<<"\n\t4.Display Audio Cassette Details\n\t5.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1: objb.getdata("book");
                objb.getpages ();
                cout<<"\n Book is being Searched ..."<<endl;
                break;

        case 2: objt.getdata ("audio cassette"); 
                objt.gettime(); 
                cout<<"\n Audio Cassette is being Searched....."<<endl;
                break;
        case 3: try
                {
                if (objb.getname()=="None")
                    throw 3;
                else
                {
                    objb.display();
                    cout<<"\n We hope you will purchase the book from our Company store soon!"<<endl;
                }
                }
                catch (int x)
                {
                    cout<<"\nNo Book has been searched yet."<<endl;
                    cout<<"Choose correct option !"<<endl;
                }
                break;
        case 4: try
                {
                if (objt.getname()=="None")
                throw 4;
                else
                {
                    objt.display();
                    cout<<"\n We hope you will purchase the audio cassette from our Company store soon!"<<endl;
                }
                }
                catch (int x)
                {
                    cout<<"\nNo Audio Cassette has been searched yet."<<endl;
                    cout<<"Choose correct option !"<<endl;
                }
                break;
        case 5: cout<<"\n->->> Visit Again <<<";
                break;
        }
    } 
    while (choice!=5);
    cout<<"\n\t*** End of Program ***";
    cout<<"\nThank You!";
    return 0;
}

#oop4

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

#oop5

#include<iostream> 
using namespace std;

template<typename T>
void display (T arr[], int n)
{
    for (int i=0;i<n;i++)
      cout<<arr[i]<<"\t";
}
template<typename T>
void selectionsort(T arr[], int no)
{
    int i,j,n=no;
    T temp;
    cout<<"\nThe array before performing Selection Sort: \t";
    display (arr,n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (arr[j]<arr[i])
            {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            arr[j]=temp;
            }
          
        }
    }
    cout<<"\nThe array after performing Selection Sort: \t";
    display (arr,n);
}
int main()
{
    int i,n;
    cout<<"\n------- SELECTION SORT FOR INTEGER ARRAY ---------"<<endl;
    cout<<"\n\tEnter the total numbers in the array: ";
    cin>>n;
    int arr1 [n];
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<"Enter the number in array at position ["<<i<<"]";
        cin>>arr1[i];
    }
    selectionsort (arr1,n);
    cout<<"\n\n------ SELECTION SORT FOR FLOAT ARRAY ------"<<endl;
    cout<<"\n\tEnter the total numbers in the array: "; 
    cin>>n;
    float arr2[n];
    cout<<"\n";
    for(i=0;i<n;i++)
    {
    cout<<"Enter the number in array at position ["<<i<<"]: ";
    cin>>arr2[i];
    }
    selectionsort (arr2, n);
    return 0;
};

#oop6

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int item_code;
class Item
{
    string name;
    int code, quantity;
    double cost;
    public:
        Item()
        {
            name="None";
            code=0;
            quantity=0;
            cost=0.0;
        }
        void accept ()
        {
            cout<<"\nEnter the Item Details ";
            cout<<"\n\tName of Item: "; 
            cin>>name;
            cout<<"\tCode of Item : #";
            cin>>code;
            cout<<"\tTotal quantity of Item: ";
            cin>>quantity;
            cout<<"\tCost of Item: Rs.";
            cin>>cost;
        }
        bool check(vector<Item>::iterator it, int x)
        {
            if(it->code==x) 
                return true; 
            else
                return false; 
        }
        int getcode ()
        {
            return code;
        }
        int getquantity()
        {
            return quantity;
        }
        double getcost ()
        {
            return cost;
        }
        void display (vector<Item>::iterator it)

        {
        cout<<"\n\n\t----- Details of Item #"<<it->code<<"---------";
        cout<<"\n\tItem Name: "<<it->name;
        cout<<"\n\tItem Code: "<<it->code;
        cout<<"\n\tItem Cost: Rs."<<it->cost<<"/-";
        cout<<"\n\tItem Quantity: "<<it->quantity;
        } 
        inline void mesg (string s)
        {
        cout<<"\nAll records have been sorted by "<<s;
        }
};
bool less_code(Item obj1, Item obj2)
{
    // Check if obj1's code is less than obj2's code
    return (obj1.getcode () <obj2.getcode ());
}
bool less_quantity (Item obj1, Item obj2)
{
    return (obj1.getquantity()<obj2.getquantity());
}
bool less_cost (Item obj1, Item obj2)
{
 return (obj1.getcost() <obj2.getcost());
}
bool isthere (Item obj)
{
if (obj.getcode()==item_code) 
    return true;
 else 
    return false;
}
int main()
{
    Item obj;
    vector <Item> v;
    vector <Item>::iterator it, it2;
    int choice,i,n;
    do
    {
        cout<<"\n\n\t\t*** MENU***";
        cout<<"\n\tl.Insert Item Record\n\t2.Sort Item Records\n\t3.Search Item Record\n\t4.Delete Item Record";
        cout<<"\n\t5.Display all Item Record\n\ts.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: obj.accept();
                    v.push_back (obj);
                    cout<<"\nItem Record inserted successfully !";
            break;

            case 2: int ch;
            cout<<"\n\n\tSort by :\n\t\tl.Item Code\n\t\t2.Item Quantity\n\t\t3.Item Cost\n"; 
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch)
            {
            case 1: sort(v.begin(), v.end(),less_code);
                    obj.mesg("Item Code") ;
                    break;
            case 2: sort(v.begin(), v.end(),less_quantity);
                    obj.mesg("Item Quantity");
                    break;
            case 3: sort(v.begin(), v.end(),less_cost);
                    obj.mesg("Item Cost"); 
                    break;
            default: cout<<"\nInvalid option selected. Select a valid option !";
            }
            break;

            case 3: cout<<"\nEnter the Item Code of the Item to be searched =";
            cin>>item_code;
            it=find_if(v.begin(), v.end(), isthere);
            if(it!=v.end())
            {
            cout<<"\nItem with Item code "<<item_code<<" found in the Records at position "<<(it-v.begin())+1;
            obj.display(it);
            }
            else
            cout<<"\nItem with Item code "<<item_code<<" not found in the Records.";
            break;
            case 4:{
                int x ;
                bool flag=false;
                cout<<"\nEnter the Item Code you would like to delete";
                cin>>x;
                for(it=v.begin(),i=0;it!=v.end(),i<=v.size();it++, i++)
                {
                if (obj.check(it,x)) 
                {
                    v.erase (v.begin()+i);
                    flag=true;
                    break;
                }
                }
                if(flag==true)
                cout<<"\nItem with Item Code "<<x<<" has been deleted successfully";
                else
                cout<<"\nItem with Item Code "<<x<<" does not exist in the Records.";
                break;
            }
            case 5:
            for(it=v.begin(); it!=v.end();it++)
            obj.display(it);
            cout<<"\nAll the Item Records have been displayed successfully";
            break;
            case 6: break;
            default: cout<<"\nInvalid option selected. Enter a valid choice!";
        }
    }
    while(choice!=6);
    cout<<"\n\t\t*** End of Program ***";
    cout<<"\nThank You!";
    return 0;
};

#oop7

#include<iostream> 
#include<string> 
#include<map> 
using namespace std;

class Map
{
    string name;
    float population;
    public:
    Map ()
    { 
        name="None";
        population=0.0;
    }
    void accept()
    {
        cout<<"\nEnter the name of the state: ";
        cin>>name;
        cout<<"Enter the population of the state (in crores): "; 
        cin>>population;
    }
    void display (map<string, float>::iterator it, int x)
    {
        cout<<"\n\t---------- Record "<<x+1<<"----------";
        cout<<"\n\t\tName of State: "<<it->first;
        cout<<"\n\t\tPopulation : "<<it->second<<" crores\n";
        cout<<"\n\t\tPopulation: "<<it->second<<" crores\n";
        } 
    inline string getname ()
    {
     return name;
    }
    inline float getpopulation()
    {
    return population;
    }
};
int main()
{
    Map obj;
    string s;
    float f;
    map <string, float> mobj;
    map <string, float>::iterator it;
    int i, choice;
    do
    {
        cout<<"\n\n\t*** MENU ***";
        cout<<"\n\tl. Insert Record\n\t2.Delete Record\n\t3. Display Record\n\t4.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: obj.accept();
                    s=obj.getname();
                    f=obj.getpopulation();
                    mobj.insert(pair<string, float>(s, f));
                    cout<<"\n\tRecord Inserted Successfully";
                    break;

            case 2: if(!mobj.empty())
            {
                    cout<<"Enter the state name whose record is to be deleted: ";
                    cin>>s;
                    it=mobj.find(s);
                    if(it!=mobj.end())
                {
                mobj.erase (s);
                cout<<"\n\tRecord of state "<<s<<" has been deleted successfully";
                }
                else
                cout<<"\n\tRecord Not Found!";
            }
            else
            cout<<"\n\tContainer is Empty. Cannot Delete Record.";
            break;

            case 3: if(!mobj.empty())
            {
            cout<<"\n\t\tDisplay of All Records\n";
            for(it=mobj.begin(),i=0;it!=mobj.end(), i<mobj.size(); it++, i++) obj.display(it, i);
            cout<<"\n\nAll Records have been displayed Successfully";
            }
            else
            cout<<"\n\tContainer is Empty. Cannot Display Records.";
            break;

            case 4: break;
            default: cout<<"\n Invalid choice entered. Enter a valid choice!";
        }
    } while(choice!=4);
    cout<<"\n\t\t*** End of Program ***";
    cout<<"\nThank You !";
    return 0;
}

#cg1

#include<graphics.h>
#include<iostream>

using namespace std;

class pt //base class
{
   protected: int x1,y1,color;
   public:
          pt()
          {
            x1=0;y1=0;color=WHITE;
          }

          void setco(int x0,int y0)
          {
            x1=x0;
            y1=y0;
          }

          void draw()
          {
            putpixel(x1,y1,color);
          }

};

class dline: public pt //derived class
{
    private: int x2,y2;
    public:
           dline():pt()
           {
             x2=0,y2=0;
           }

           void setline(int x0, int y0, int xx, int yy)
           {
             pt::setco(x0,y0);
             x2=xx;
             y2=yy;
           }

           void drawl() //DDA's Line
           {
        int x,y,dx,dy,steps,i=0;
	float xinc,yinc;
		
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
	        steps=abs(dx);
	else
	        steps=abs(dy);
	        
	xinc=dx/(float)steps;
	yinc=dy/(float)steps;
	
	x=x1;
	y=y1;
	
	pt::setco(x,y);
	pt::draw();   //putpixel(x,y,WHITE);
	
	for(i=1;i<=steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		
		pt::setco(x,y);
		pt::draw();   //putpixel(x,y,10);
				
	}
	
      	}//funciton closed

	void cal(int x1,int y1,int x3,int y3)
	{
				
		setline(x1,y1,x3,y1);   //side1
		draw1();

		setline(x3,y1,x3,y3);   //side 2
		draw1();
	
		setline(x3,y3,x1,y3);   //side 3
		draw1();


		setline(x1,y3,x1,y1);  //side 4
		draw1();
		
		
		//rectangle 2
		
		int xmid1,ymid1,xmid2,ymid2,xmid3,ymid3,xmid4,ymid4;
		
		xmid1 = (x1 + x3) / 2;
		ymid1 = y1;
		
		xmid2 = x3;
		ymid2 = (y1 + y3) / 2;
		
		setline(xmid1,ymid1,xmid2,ymid2); //side 5
		draw1();
		
		xmid3 = (x1 + x3) / 2;
		ymid3 = y3;
		
		setline(xmid2,ymid2,xmid3,ymid3); //side 6
		draw1();
		
		xmid4 = x1;
		ymid4 = (y1 + y3) / 2;
		
		setline(xmid3,ymid3,xmid4,ymid4); //side 7
		draw1();
		
		setline(xmid4,ymid4,xmid1,ymid1); //side 8
		draw1();
		
		
		///rectangle 3
		int xf1,yf1, xf2,yf2, xf3,yf3, xf4,yf4;
		
		xf1 = (xmid1 + xmid4 ) / 2;
		yf1 = (ymid1 + ymid4 ) / 2;
		xf2 = (xmid1 + xmid2 ) / 2;
		yf2 = (ymid1 + ymid2 ) / 2;
		
		setline(xf1, yf1, xf2, yf2);   //side 9
		draw1();
		
		xf3 = (xmid2 + xmid3 ) / 2;
		yf3 = (ymid2 + ymid3 ) / 2;
		setline(xf2, yf2, xf3, yf3);  //side 10
		draw1();

		xf4 = (xmid3 + xmid4 ) / 2;
		yf4 = (ymid3 + ymid4 ) / 2;		
		setline(xf3, yf3, xf4, yf4);  //side 11
		draw1();

		setline(xf4, yf4, xf1, yf1);  //side 12
		draw1(); 
		
		
			
	}
      	
      
};

int main()
{
    	int x1,y1,x3,y3,xmax,ymax,xmid,ymid;
   	char a;
    	int gd=DETECT,gm=VGAMAX;
    	initgraph(&gd,&gm,NULL);
    	
        pt p;
    	dline dda;

    	
                 cout<<"\nEnter the co-ordinates of the endpoints Below\n";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"\nEnter y1: "; cin>>y1;
                 cout<<"\nEnter x3: "; cin>>x3;
                 cout<<"\nEnter y3: "; cin>>y3;

	     dda.cal(x1,y1,x3,y3);
        
  	delay(50000);
   	closegraph();
   	return 0;


}

#cg2


# include<graphics.h>
# include<iostream>

//# include<conio.h>
//# include<dos>
using namespace std;
int main()
{
	int gd=DETECT, gm;
	initgraph (&gd,&gm,NULL);
	
	int cnt, temp,i,j,n,ymax,ymin,yscan;
	float inter_x[10], m[10], dx,dy;
	int x[10], y[10];
	
	cout<<"Enter no. of vertices of polygon: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<" vertices of polygon (as x and y) is :";
		cin>>x[i]>>y[i];
	}
	x[n]=x[0];
	y[n]=y[0];
	
	setcolor(3);		 
	for(i=0;i<n;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
		delay(100);
	}
	
	ymax=0;
	ymin=480;
	
	for(i=0;i<n;i++)
	{
		if (y[i]>ymax)
			ymax=y[i];
		if (y[i]<ymin)
			ymin=y[i];
	}
	
	for(i=0;i<n;i++)
	{
		dx= x[i+1]-x[i];
		dy= y[i+1]-y[i];
		if (dx==0)
			m[i]=0;
		else if (dx==0)
			m[i]=0;
		else 
			m[i]=(float)dy/dx;
	}
	
	for(yscan=ymax;yscan>ymin;yscan--)
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			if (y[i]>yscan && y[i+1]<=yscan || y[i]<=yscan && y[i+1]>yscan)
			{
				if (m[i]==0)
					inter_x[cnt]=x[i];
				else
					inter_x[cnt]=x[i]+ (yscan-y[i])/m[i];
					cnt++;
			}
		}
		for(j=0;j<cnt-1;j++)
		{
			if (inter_x[j]>=inter_x[j+1])
			{
				temp=inter_x[j];
				inter_x[j]=inter_x[j+1];
				inter_x[j+1]=temp;
			}
		}
		for(j=0;j<cnt-1;j=j+2)
		{
			line(inter_x[j],yscan,inter_x[j+1],yscan);
			delay(300);
		}
	}
	setcolor(5);
	getch();
	return 0;
}


#cg3

#include<iostream>
#include<graphics.h>


using namespace std;
static int x_max, y_max, x_min, y_min;


// Defining region codes
static int INSIDE = 0; // 0000
static int LEFT = 1; // 0001
static int RIGHT = 2; // 0010
static int BOTTOM = 4; // 0100
static int TOP = 8; // 1000


// Defining x_max, y_max and x_min, y_min for
// clipping rectangle. Since diagonal points are
// enough to define a rectangle
// Function to compute region code for a point(x, y)
int binaryCode(double x, double y)
{
	// initialized as being inside
	int code = INSIDE;


	if (x < x_min) // to the left of rectangle
		code |= LEFT;
	else if (x > x_max) // to the right of rectangle
		code |= RIGHT;
	if (y < y_min) // below the rectangle
		code |= BOTTOM;
	else if (y > y_max) // above the rectangle
		code |= TOP;


	return code;
}


// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x1, y1) to P2 = (x2, y2)


void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = binaryCode(x1, y1);
	int code2 = binaryCode(x2, y2);


	// Initialize line as outside the rectangular window
	bool accept = false;


	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
		// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
		// If both endpoints are outside rectangle,
		// in same region
			break;
		}
		else {
		// Some segment of line lies within the
		// rectangle
			int code_out;
			double x, y;


			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;


		// Find intersection point;
		// using formulas y = y1 + slope * (x - x1),
		// x = x1 + (1 / slope) * (y - y1)
			if (code_out & TOP) {
		// point is above the clip rectangle
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				// point is below the rectangle
			x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
			y = y_min;
			}
			else if (code_out & RIGHT) {
			// point is to the right of rectangle
			y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);	
		        x = x_max;
			}
			else if (code_out & LEFT) {
			// point is to the left of rectangle
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}


			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = binaryCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = binaryCode(x2, y2);
			}
		}
	}
	if (accept) {
	delay(1000);
	rectangle(x_min,y_min,x_max,y_max);
	line(x1,y1,x2,y2);  
	}
}
// Driver code
int main()
{
	int gdriver = DETECT,gmode =VGAMAX;
	initgraph(&gdriver,&gmode,NULL);
	
            cout<<"Enter left, top and right, bottom of window: ";
	cin>>x_min>>y_min>>x_max>>y_max;
	rectangle(x_min,y_min,x_max,y_max);
	int x1,y1,x2,y2;
	cout<<"Enter the endpoints of the line: ";
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);  
	delay(500);
	cleardevice();
	
	cohenSutherlandClip(x1,y1,x2,y2); 
	
	getch();
	return 0;
	
}

#cg4

#include <stdlib.h>
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
class Tdimen
{
int x1,y1, x2,y2,x3,y3;
public:
void translate();
void scale();
void rotate();
void operator=(const Tdimen &T)
{
x1=T.x1;
y1=T.y1;
x2=T.x2;
y2=T.y2;
y3=Ty3;
x3=T.x3;
}
void draw()
{
x1=150,y1=50,x2=100,y2=100,x3=200,y3=100;
cleardevice();
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
}
void result()
{
//x1=150,y1=50,x2=100, y2=100,x3=200,y3=100;
cleardevice();
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
}
};
void Tdimen::translate()
{
float tx,ty; cout<<"Enter tx & ty: "; cin>>tx>>ty; x1+=tx;x2+=tx;x3+=tx; 
y1+=ty:y2+=ty;y3+=ty;
}
void Tdimen::scale()
{
float sx,sy; cout<<"Enter sx & sy: "; cin>>sx>>sy; x1*=sx;x2*=sx;x3*=sx; 
y1*=sy;y2*=sy;y3*=sy;
}
void Tdimen::rotate()
{ float deg; cout<<"Enter angle: "; cin>>deg; deg = deg*3.14/180; int x,y;
x=x1;y=y1;
x1 = x*cos(deg)-y*sin(deg);
y1 = x*sin(deg)+y*cos(deg); ;
x=x2;y=y2 x2 = x*cos(deg)-y*sin(deg);
y2 = x*sin(deg)+y*cos(deg);
x=x3;y=y3;
x3 = x*cos(deg)-y*sin(deg);
y3 = x*sin(deg)+y*cos(deg);
}
int main()
{
int option;
Tdimen T;
int gdriver = DETECT,gmode; initgraph(&gdriver, &gmode, NULL);
do
{
cout<<"\n1. Translation 2.Scaling 3. Rotation 4. Exit: ";
T.draw();
cin>>option;
switch(option)
{
case 1:
//T.draw(); T.translate(); T.result(); delay(10000); break;
case 2:
//T.draw();
T.scale(); T.result(); delay(10000); break;
case 3:
//T.draw();
T.rotate(); T.result(); delay(10000); break;
case 4:
break;
default: cout<<"Invalid choice";
}
}while(option!=4);
closegraph();
}

#cg5

#include<iostream>
#include<graphics.h>
using namespace std;
void move(int j,int h,int&x,int&y)
{
	if(j==1)
		y-=h;
	else if(j==2)
		x+=h;
	else if(j==3)
		y+=h;
	else if(j==4)
		x-=h;
			lineto(x,y);
}
void hilbert(int u,int r,int d, int l,int i,int h,int &x,int &y)
	{
		if(i>0)
		{
			i--;
			hilbert(r,u,l,d,i,h,x,y);
			move(u,h,x,y);
			delay(1000);
			hilbert(u,r,d,l,i,h,x,y);
			move(d,h,x,y);
			delay(1000);
			hilbert(l,d,r,u,i,h,x,y);
			delay(1000);
		}
	}
	int main()
	{
		int n,x=50,y=150,h=10,r=2,d=3,l=4,u=1;
		int driver=DETECT,mode=0;
		initgraph(&driver,&mode,NULL);
		cout<<"Give the value of n:";
		cin>>n;
		moveto(x,y);
		hilbert(u,r,d,l,n,h,x,y);
		delay(1000);
		closegraph();
		return 0;
	}

#cg6

#include <iostream>
#include <GL/glut.h>
using namespace std;

void myInit(void)
{

    glClearColor(0.0, 0.0, 0.0, 1.0); // black
    glColor3f(1.0, 1.0, 1.0);         // white

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void myDisplay(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4.0);

    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_POLYGON);

    glVertex2i(40, 40);
    glVertex2i(320, 40);
    glVertex2i(40, 40);
    glVertex2i(40, 200);
    glVertex2i(40, 200);
    glVertex2i(320, 200);
    glVertex2i(320, 200);
    glVertex2i(320, 40);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);

    glVertex2i(220, 60);
    glVertex2i(300, 60);
    glVertex2i(220, 150);
    glVertex2i(300, 150);
    glVertex2i(220, 60);
    glVertex2i(220, 150);
    glVertex2i(300, 150);
    glVertex2i(300, 60);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);

    glVertex2i(220, 170);
    glVertex2i(300, 170);
    glVertex2i(220, 190);
    glVertex2i(300, 190);
    glVertex2i(220, 170);
    glVertex2i(220, 190);
    glVertex2i(300, 190);
    glVertex2i(300, 170);
    glEnd();

    glColor3f(0.60f, 0.42f, 0.16f);

    glBegin(GL_POLYGON);

    glVertex2i(130, 40);
    glVertex2i(130, 160);
    glVertex2i(130, 160);
    glVertex2i(180, 160);
    glVertex2i(180, 100);
    glVertex2i(180, 40);
    glVertex2i(120, 40);
    glVertex2i(170, 40);
    glEnd();

    glColor3f(0.60f, 0.42f, 0.16f);

    glBegin(GL_POLYGON);

    glVertex2i(130, 170);
    glVertex2i(130, 180);
    glVertex2i(130, 180);
    glVertex2i(180, 180);
    glVertex2i(180, 170);
    glVertex2i(180, 180);
    glVertex2i(130, 170);
    glVertex2i(180, 170);
    glEnd();

    glColor3f(1.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);

    glVertex2i(10, 200);
    glVertex2i(340, 200);
    glVertex2i(200, 390);
    glVertex2i(10, 200);
    glVertex2i(200, 390);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 740);

    glutInitWindowPosition(0, 0);

    glutCreateWindow("Basic hut like structure & quot");

    glutDisplayFunc(myDisplay);
    myInit();

    glutMainLoop();

    return 0;
}

#cg7

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main()
{
int gd=DETECT,gm, i,j;
initgraph(&gd,&gm,NULL);
line(20,380,580,380);
line(25,380,35,340);
line(45,380,35,340);
line(35,310,25,330);
line(35,380,35,340);
line(35,310,40,330);
line(35,340,35,310);
circle(35,300,10);
line(35,310,50,330);
line(50,330,50,280);
line(15,280,85,280);
arc(50,280,180,360,35);
arc(55,330,360,180,5);
delay(10000);
getch();
return 0;
}
