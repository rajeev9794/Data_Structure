#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Heap
{
    public:
        int *arr;
        int capacity;
        int size;
        Heap(int n)
        {
            capacity=n;
            size=0;
            arr=new int[n];

        }
        ~Heap()
        {
            delete[] arr;
        }
        int parent(int i);
        int leftchild(int );
        int rightchild(int);
        void swap(int &,int &);
        void insert(int );
        int FindMax();
        void DeleteTop();
        void Heapify(int);
};
int Heap::parent(int i)
{
    return (i-1)/2;
}
int Heap::leftchild(int i)
{
    return (2*i+1);
}
int Heap::rightchild(int i)
{
    return (2*i+2);
}
void Heap::swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}
void Heap::insert(int x)
{
    size+=1;
    int i=(size-1);
    arr[i]=x;
    while(i!=0 && arr[parent(i)]<x)
    {
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
/*
    for(int i=0;i<size;i++)
    {
        cout<<"arr["<<i<<"]="<<arr[i]<<" ";
    }
    cout<<endl;
*/
}

void Heap::DeleteTop()
{
   // swap(arr[0],arr[size-1]);

    //cout<<"size value array="<<arr[size-1]<<endl;
    arr[0]=arr[size-1];
    size--;
    Heapify(0);
/*
    for(int i=0;i<size;i++)
    {
        cout<<"arr["<<i<<"]="<<arr[i]<<" ";
    }
    cout<<endl;
  */  
}

int Heap::FindMax()
{
    return arr[0];
}

void Heap::Heapify(int i)
{
    int id=i;
    if(2*i+1<size && arr[leftchild(i)]>arr[i])
    {
        //swap(arr[leftchild(i)],arr[i]);
        //Heapify(leftchild(i));
        id=leftchild(i);
    }

    if(2*i+2<size && arr[rightchild(i)]>arr[id])
    {
        //swap(arr[rightchild(i)],arr[i]);
        //Heapify(rightchild(i));
        id=rightchild(i);
    }

    if(id!=i)
    {
        swap(arr[id],arr[i]);
        Heapify(id);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        Heap h(n);
        for(int i=0;i<n;i++)
        {
            cin>>x;
            h.insert(x);
        }
        for(int i=0;i<n;i++)
        {
            cout<<h.FindMax()<<endl;
            h.DeleteTop();
        }

    }   
}