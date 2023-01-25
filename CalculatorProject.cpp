//CALCULATOR PROJECT
#include <iostream>
#include<string>
using namespace std;
//In this function we use both input is integer for addition.
int sum(int a, int b)
{
    cout <<"="<< a + b<<endl;
}
//In this function we use both double /one of these integer for addition
double sum(double c, double d)
{   
    cout <<"="<< c + d<<endl;
}
//In this function we use both input is integer for subtraction.
int sub(int a, int b)
{
    cout <<"="<< a - b<<endl;
}
//In this function we use both double /one of these integer for subtraction
double sub(double c, double d)
{
    cout <<"="<< c - d<<endl;
}
//In this function we use both input is integer for multiplication.
int mul(int a, int b)
{
     cout << "="<<a * b<<endl;
}
//In this function we use both double /one of these integer for multiplication
double mul(double c, double d)
{
    cout <<"="<< c * d<<endl;
}
//In this function we use both input is integer for division.
int division(int a, int b)
{
    cout <<"="<< a / b<<endl;
}
//In this function we use both double /one of these integer for division.
double division(double c, double d)
{
    cout <<"="<< c / d<<endl;
}
int main()
{   
    system("cls");
    string str1, str2;
    char ch;
    cout << " ON YOUR CALCULATOR " << endl;
    do
    {
    cin >> str1;
    cout <<ends<< " + "
         << " - "
         << " * "
         << " / "
         <<"enter 1 two time to closed the calculator"
         << endl;
    cin >> ch;
    cin >> str2;
     //convert string to integer
    int a = stoi(str1);
    int b = stoi(str2);
     //convert string to double
    double c = stod(str1);
    double d = stod(str2);
    
        switch (ch)
        {
        case '+':
            if (c >= a && d >= b)
            {
                sum(c, d);
            }
            else
            {
                sum(a, b);
            }
            break;
        case '-':
            if (c >= a && d >= b)
            {
                sub(c, d);
            }
            else
            {
                sub(a, b);
            }
            break;
        case '*':
            if (c >= a && d >= b)
            {
                mul(c, d);
            }
            else
            {
                mul(a, b);
            }
            break;
        case '/':
            if (c >=a && d >= b)
            {
                division(c, d);
            }
            else
            {
                division(a, b);
            }
            break;
        case '1':
            exit(0);
            break;
        default:
            cout << "invalid input ";
            break;
        }
    } while (1);
    return 0;
}