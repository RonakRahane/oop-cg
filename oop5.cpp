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