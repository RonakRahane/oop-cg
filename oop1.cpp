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