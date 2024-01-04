//dynamic array : increase the  size of array by double if the array is full 
//and we are trying to add more values to it .
//steps:
//1.create another array having double size dynamically
//2.then point previous array pointer to this new array
//3.append the value/add the value.
#include <iostream>
using namespace std;

class DynArray{
    private:
        int *arr;
        int capacity;
        int lastIndex=-1;
    public:
        DynArray(int);
        void append(int);
        bool isFull();
        void doubleArray();
        void show();
        int capacty();
        void insert(int,int);
        void remove(int);
        void shrinkArray();
        bool isEmpty();

};


DynArray::DynArray(int size){
    arr=new int[size];
    capacity=size;

}
int DynArray::capacty(){
            return capacity;
        }
bool DynArray::isFull(){
    return lastIndex==capacity-1;
}
void DynArray::doubleArray(){
    int newSize=capacity*2;
    int *temp=new int[newSize];
    for(int i=0;i<=lastIndex;i++){
        temp[i]=arr[i];
    }
    delete []arr;
    arr=temp;
    capacity=newSize;
}
void DynArray::append(int data){
    if(isFull()){//agar full hua toh double kar do array ko
        doubleArray();
    }
    lastIndex++;
    arr[lastIndex]=data;

}
void DynArray::show(){
    cout<<"\narray is :-\n";
    for(int i=0;i<=lastIndex;i++){
        cout<<arr[i]<< " ";
    }
}
bool DynArray::isEmpty(){
    return lastIndex==-1;
}
void DynArray::remove(int index){
    if(isEmpty() || index <0 || index >lastIndex)//invalid index or array is empty
        cout<<"can't remove at this index";    
    else{
    for(int i=index;i<lastIndex;i++)
        arr[i]=arr[i+1];        
    lastIndex--;
    if(lastIndex+1==(capacity/2))
        shrinkArray();
    }

}
void DynArray::shrinkArray(){
    int newSize=capacity/2;
    int *temp=new int[newSize];
    for(int i=0;i<=lastIndex;i++){
        temp[i]=arr[i];
    }
    delete []arr;
    arr=temp;
    capacity=newSize;
}
void DynArray::insert(int data,int index){
    if(index<0 || isFull() || index >lastIndex+1)//invalid index
        cout<<"can't insert at this location";
    else{
        //insert karo lekin usse phele double array check
        if(lastIndex==capacity-1)
            doubleArray();
        
        for(int i=lastIndex;i>=index;i--)
            arr[i+1]=arr[i];        
        arr[index]=data;
        lastIndex++;
    }
    
}

int main(){
    DynArray a(3);
    a.append(5);
    a.append(15);
    a.append(25);    
    a.append(5);
    a.show();

    a.insert(34,4);
    a.show();
    a.remove(4);
    a.remove(3);

    a.show();

    cout<<"\ncapacity: "<<a.capacty();
    
    return 0;
}