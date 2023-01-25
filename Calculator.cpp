#include<iostream>
using namespace std;
template<class T>
class Calculator{
private:
T num1,num2,result;
public:
Calculator(T n1,T n2){
    num1=n1; num2=n2;
}
T addition(){  result=num1+num2; cout<<endl<<result;}
T subtract(){ result=num1-num2; cout<<endl<<result;}
T multiply(){ result=num1*num2; cout<<endl<<result;}
T divide(){ result=num1/num2; cout<<endl<<result;}
};
int main(){
    string str1,str2;
    char ch;
    int a = stoi(str1);
    int b = stoi(str2);

    double c = stof(str1);
    double d = stof(str2);
    
    cout<<"start calculating.\n";
    cin>>str1;
    
    cout<<"\t\t\t+"<<"   "<<"-"<<"   "<<"*"<<"   "<<"/";
    cin>>ch;
    cin>>str2;
    Calculator<int>input(a,b);
    Calculator<double>input(c,d);
    switch (ch)
    {
    case '+':
        input.addition();
        break;
    case '-':
        input.subtract();
        break;
    case '*':
        input.multiply();
        break;
    case '/':
        input.divide();
        break;
    default:
        cout<<"Error";
        break;
    }
}