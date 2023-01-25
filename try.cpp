#include<iostream>
#include<string>

using namespace std;

int sum(int a, int b)
{
	cout<<"on adding values we get " <<a+b;
	return 0;
}

double sum(double c, double d)
{
	cout<<"on adding values we get " <<c+d;
	return 0;
}
int main()
{
	string str1, str2;
	
	cout <<"please input the first value: " <<endl;
	cin >>str1;
	
	cout<<"please input the second value: " <<endl;
	cin >>str2;
	
	int a = stoi(str1);
	int b = stoi(str2);
	
	double c = stof(str1);
	double d = stof(str2);
	
	if (c>=a && d>=b)
	{
		sum(c, d);
	}
	else
	{
		sum(a, b);
	}
	
}