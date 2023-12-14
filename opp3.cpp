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