#include<iostream>
using namespace std;
#define size 10
class array{
public:
int *ptr;
int arr[size];
ptr=arr;
void input(int *arr[size],int *n);
void output();
};
void display(){
    cout<<"1.exit."<<endl;
    cout<<"2.input."<<endl;
    cout<<"3.output."<<endl;
}
int main(){
    int op;
    array ob;
    void display();
    cout<<"Enter your choice.\n";
    cin>>op;
    switch (op)
    {
    case 1:
        cout<<"thank you\n";
        break;
    case 2:
        ob->input(&arr[size],&n);
        break;
    default:
        break;
    }

}