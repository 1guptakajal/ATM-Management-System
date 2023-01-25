#include<iostream>
using namespace std;
class base{
public:
virtual void print(){
    cout<<"base function:"<<endl;
}
};
class derived : public base{
public:
void print(){
    cout<<"derived function:"<<endl;
}
};
class derived1 : public base{
    public:
    void print(){
        cout<<"derived1 function:"<<endl;
    }
};
void f(base &r){
    r.print();
}
int main(){
    base b;
    derived ob;
    derived1 ob1;
    f(b);
    f(ob);
    f(ob1);
    return 0;
}