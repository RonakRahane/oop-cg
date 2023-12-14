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
