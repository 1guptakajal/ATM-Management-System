#include<iostream>
using namespace std;
class overloading{
    int longitude,latitude;
    public:
    overloading(){}
    overloading(int lg,int lt){
        longitude=lg;
        latitude=lt;
    }
    void show(){
        cout<<"longitude="<<longitude<<endl;
        cout<<"latitude="<<latitude<<endl;
    }
    overloading operator+(overloading op2);  
    overloading operator-(overloading op2);
    overloading operator=(overloading op2);
    overloading operator++();  
    overloading operator()(int i,int j);             //friend overloading operator++(overloading &op2)
};
overloading overloading::operator+(overloading op2){
    overloading temp;
    temp.longitude=op2.longitude+longitude;
    temp.latitude=op2.latitude+latitude;
    return temp;
}
overloading overloading::operator-(overloading op2){
    overloading temp;
    temp.longitude=op2.longitude-longitude;
    temp.latitude=op2.latitude-latitude;
    return temp;
}
overloading overloading::operator=(overloading op2){
    longitude=op2.longitude;
    latitude=op2.latitude;
    return *this;
}
overloading overloading::operator++(){  
    longitude++;                        
    latitude++;                           
    return *this;                     
}
overloading overloading::operator()(int i,int j){
    longitude=i;
    latitude=j;
    return *this;
}
int main(){
    overloading op1(10,20),op2(5,30),op3;
    op1.show();
    cout<<"\n";
    op2.show();
    cout<<"\n";
    op3=op1+op2;
    op3.show();
    op3=op1-op2;
    op3.show();
    op3=op1;
    op3.show();
    op3=++op1;
    op3.show();
    op3=op2+op1(10,10);
    op3.show();
    return 0;

}