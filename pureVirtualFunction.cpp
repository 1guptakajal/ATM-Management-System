#include<iostream>
using namespace std;
class shape{
    protected:
    float l;
    public:
    void input(){
        cout<<"Enter radius/lenght of shape"<<endl;
        cin>>l;
    }
    virtual float area()=0;
};
class circle : public shape{
public:
float area(){ return (3.14*l*l);}
};
class square :public shape{
    public:
    float area(){return (l*l);}
};
int main(){
    circle c;
    c.input();
    cout<<"area of circle:"<<c.area()<<endl;
    square s;
    s.input();
    float ans=s.area();
    cout<<" area of square="<<ans;
}