#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastIndex=-1;
        int *arr;
    public:
        Array(int);
        bool isEmpty();
        void append(int);
        void show();
        void insert(int,int);
        bool isFull();
        void userInput();
        void edit(int,int);
        void del(int);
        int getElementByIndex(int);//index se khojo
        int length();
        int findElement(int);
        ~Array();
};
Array::Array(int size){
    arr=new int[size];
}
bool Array::isEmpty(){
    return lastIndex==-1;
}
void Array::append(int value){
    if(lastIndex < capacity-1){
        lastIndex++;
        arr[lastIndex]=value;
    }
}
void Array::show(){
    cout<<"\narray is :-\n";
    for(int i=0;i<=lastIndex;i++){
        cout<<arr[i]<< " ";
    }
}
bool Array::isFull(){
    return lastIndex==capacity-1;
}
void Array::insert(int value,int index){
    if(isFull()||index>lastIndex+1||index<0){//invalid codition
        cout<<"can't insert at specified index try again";
    }
    else{
        for(int i=lastIndex;i>=index;i--){
            arr[i+1]=arr[i];

        }
        arr[index]=value;
        lastIndex++;
    }
}
void Array::userInput(){
    int n;
    int data;
    cout<<"enter how many elements to insert : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"data to add : ";
        cin>>data;
        append(data);
    }

}
void Array::edit(int update,int index){
    if(lastIndex<index || index<0){//invalid
        cout<<"can't edit at this location";
    }
    else{
        arr[index]=update;
    }
}
void Array::del(int index){
    if(isEmpty() || index>lastIndex || index<0){//invalid when we can't delete
        cout<<"can't delete at specified index";
    }
    else{
        for(int i=index;i<lastIndex;i++){
            arr[i]=arr[i+1];
        }
        lastIndex--;
    }
}
int Array::getElementByIndex(int index){
    return arr[index];
}
int Array::length(){
    return lastIndex+1;
}
int Array::findElement(int value){
    for(int i=0;i<=lastIndex;i++){
        if(arr[i]==value){
            return i;
            break;
        }
        else 
            return -1;
    }
}
Array::~Array(){
            cout<<"\ndestructor called automatically to free memory";
            delete []arr;//delete clears the memory created using dynamic memory allocation if we donot,
                            //delete then the destructor will remove object and this dyn allo memory will 
                            //,not be able to be deleted after destructor called,because pointer will not be available.

        };

int main(){
    Array a(10);
    a.append(5);
    a.append(15);
    a.append(25);
    a.append(35);
    a.append(45);
    a.insert(12,2);

   //a.userInput();
    a.show();

    //a.edit(14,2);

    a.del(2);
    a.show();

    cout<<"\n element at specified location is : "<<a.getElementByIndex(3);
    cout<<"\nlength of array is :"<<a.length();
    
    return 0;
}