#include<iostream>
using namespace std;
class person{
    public:
    char name[10];
    void display(){
    cout<<"Enter your name: "<<endl;
    cin.getline(name,20);
    }
};
class student: public person{
public:
int studentId;
void display1(){
    cout<<"Enter your id number :"<<endl;
    cin>>studentId;
}
};
class activities: public person{
    public:
    float mark;
    void show(){
        cout<<"enter your marks"<<endl;
        cin>>mark;
    }
};
class result:public student,public activities{
    public:
    void display2(){
        if(mark>=300){
            cout<<"pass"<<endl;
        }
        else{
            cout<<"fail"<<endl;
        }
    }
};
int main(){
    result k;
    k.display1();
    k.show();
    k.display2();
}/*#include<iostream>
using namespace std;
class index{
    int value;
    public:
    index (){ value=0; }
  int getindex(){
    return value;
  }  
  index operator ++(){
    index i;
    value=value+1;
    i.value=value;
    return i;
  }
};
int main(){
    index i1,i2;
    cout<<i1.getindex()<<endl;
    cout<<i2.getindex()<<endl;
    i1=i2++;
     i2++;
     cout<<i1.getindex()<<endl;
     cout<<i2.getindex()<<endl;
}*/