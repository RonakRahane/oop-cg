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