#include<iostream>
using namespace std;
#define max 10
class student{
private:
char name[50];
int roll;
float totalmarks;
public:
void inputdetails();
void outputdetails();
};
void student :: inputdetails(){
cout<<"Enter  name"<<endl;
cin.getline(name,50);
cout<<"Enter roll number"<<endl;
cin>>roll;
cout<<"Enter  total marks"<<endl;
cin>>totalmarks;
}
void student :: outputdetails(){
    cout<<"name"<<name<<"  "<<"roll"<<roll<<" "<<"totalmarks"<<totalmarks<<endl;
}
int main(){
    student s[max];
    int n,i;
    cout<<"Enter total number of student"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        s[i].inputdetails();
    }
    cout<<"student details:..."<<endl;
    for(i=0;i<n;i++){
        s[i].outputdetails();
    }
    return 0;
}/*#include<iostream>
#define size 5
using namespace std;
class array{
private:
int rollNo;
int marks[size];
public:
void input();
void output();
};
void array::input(){
cout<<"enter roll number:"<<endl;
cin>>rollNo;
for(int i=0;i<size;i++){
    cout<<"enter "<<i+1<<"  subject marks"<<endl;
    cin>>marks[i];
}
}
void array::output(){
    int total=0;
    cout<<"roll number"<<rollNo<<endl;;
    for(int i=0;i<size;i++){
        total+=marks[i];
        }
        cout<<"toatl"<<total<<endl;
}
int main(){
    array ob[3];
    for(int i=0;i<3;i++){
    ob[i].input();
    }
    for(int i=0;i<3;i++){
    ob[i].output();
    }
}*/
/*mutable*/
#include<iostream>
using namespace std;
class test{
public:
mutable int a;
mutable int b;
test(int i,int j){
a=i;
b=j;
} 
void output()const{
    cout<<"a="<<a<<" "<<"b="<<b;
}
};
int main(){
    const test t(10,20);
    t.a=30;
    t.b=40;
    t.output();
}
