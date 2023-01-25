#include<iostream>
#include<fstream>
//#include<iomanip>
using namespace std;

// the class that stores data
class student{
    int rollNumber;
    char StudentName[100];
    int accounting,DBMS,OOP,MATH,Lab_oop,sql;
    int marks;
    public:
    void getdata();
    void showdata() const;
    void calculate();
    int setrollNumber() const;
    
};
void student::calculate(){
marks=accounting+DBMS+OOP+MATH+Lab_oop+sql;
}
void student::getdata(){
cout<<"Enter Student Roll Number."<<endl;
cin>>rollNumber;
cout<<"Enter Student Name ."<<endl;
cin.ignore();
cin.getline(StudentName,100);
cout<<"Enter marks of all subject."<<endl;
cout<<"Enter mark of management and accounting."<<endl;
cin>>accounting;
cout<<"Enter mark of database management system."<<endl;
cin>>DBMS;
cout<<"Enter mark of object oriented programming through c++."<<endl;
cin>>OOP;
cout<<"Enter mark of math."<<endl;
cin>>MATH;
cout<<"Enter mark of lab on object oriented programming through c++"<<endl;
cin>>Lab_oop;
cout<<"Enter mark of lab on mysql."<<endl;
cin>>sql; 
calculate();
}
void student::showdata() const{
 cout<<" Student Roll Number. "<<rollNumber<<endl;
cout<<" Student Name. "<<StudentName<<endl;
cout<<" Marks of all subject.\n"<<endl<<endl;
cout<<"Management and accounting. "<<accounting<<endl;
cout<<"database management system. "<<DBMS<<endl;
cout<<"object oriented programming through c++. "<<OOP<<endl;
cout<<"lab on object oriented programming through c++. "<<Lab_oop<<endl;
cout<<"lab on mysql. "<<sql<<endl<<endl;
cout<<"Total marks obtained="<<endl<<marks;
}
int student::setrollNumber() const{
    return rollNumber;
}
//function declaration
void create_student();
void display_sp(int);//display particular record
void display_all(); // display all records
void delete_student(int);//delete particular record
void change_student(int);//edit particular record
int main(){
    char ch;
    //cout<<setprecision(2);
    do
    {
      char ch;
      int roll;
      system("cls");
      cout<<"=========================="<<endl;
      cout<<".......MAIN MANU.........."<<endl;
      cout<<"=========================="<<endl;
      cout<<"\n\t1.Create Student Record.\n\t";
      cout<<"2.Search Student Record.\n\t";
      cout<<"3.Display All Student Record.\n\t";
      cout<<"4.Delete Student Record.\n\t";
      cout<<"5.Modify Student Record.\n\t";
      cout<<"6.Exit\n\t\n\t";
      cout<<"Enter Your Choice.\n";
      cin>>ch;
      system("cls");
      switch (ch)
      {
      case '1': create_student();
              break;
      case '2': cout<<"Enter roll number."<<endl;
              cin>>roll;
              display_sp(roll);
              break;
      case '3': display_all();
              break;
      case '4': cout<<"Enter roll number."<<endl;
              cin>>roll;
              delete_student(roll);
              break;
      case '5': cout<<"Enter roll number."<<endl;
              cin>>roll;
              change_student(roll);
              break;
      case '6': cout<<"....THANK YOU.....";
              exit(0);
              break;
      default: cout<<"Please enter correct choice."<<endl;
        break;
      }
    } while (ch!='6');
    return 0;
}
//write student details to file
void create_student()
{
student stud;
ofstream oFile;
oFile.open("student.dat",ios::binary|ios::app);
stud.getdata();
oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
oFile.close();
 cout<<"\n\nStudent record Has Been Created ";
cin.ignore();
cin.get();
}
// read file records
void display_all()
{
  system("cls");
student stud;
ifstream inFile;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be opened !! Press any Key to exit";
cin.ignore();
cin.get();
return;
}
cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
while(inFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
{
stud.showdata();
cout<<"\n\n====================================\n";
}
inFile.close();
cin.ignore();
cin.get();
}
//read specific record based on roll number
void display_sp(int n)
{
student stud;
ifstream iFile;
iFile.open("student.dat",ios::binary);
if(!iFile)
{
cout<<"File could not be opened... Press any Key to exit";
cin.ignore();
cin.get();
return;
}
bool flag=false;
while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
{
if(stud.setrollNumber()==n)
{
  stud.showdata();
flag=true;
}
}
iFile.close();
if(flag==false)
cout<<"\n\nrecord does not exist";
cin.ignore();
cin.get();
}
// modify record for specified roll number
void change_student(int n)
{
bool found=false;
student stud;
fstream fl;
fl.open("student.dat",ios::binary|ios::in|ios::out);
if(!fl)
{
cout<<"File could not be opened. Press any Key to exit...";
cin.ignore();
cin.get();
return;
}
     while(!fl.eof() && found==false)
{
fl.read(reinterpret_cast<char *> (&stud), sizeof(student));
if(stud.setrollNumber()==n)
{
stud.showdata();
cout<<"\nEnter new student details:"<<endl;
stud.getdata();
    int pos=(-1)*static_cast<int>(sizeof(stud));
    fl.seekp(pos,ios::cur);
    fl.write(reinterpret_cast<char *> (&stud), sizeof(student));
    cout<<"\n\n\t Record Updated";
    found=true;
}
}
// f1.close();
if(found==false)
cout<<"\n\n Record Not Found ";
cin.ignore();
cin.get();
}
//delete record with particular roll number
void delete_student(int n)
{
student stud;
ifstream iFile;
iFile.open("student.dat",ios::binary);
if(!iFile)
{
cout<<"File could not be opened... Press any Key to exit...";
cin.ignore();
cin.get();
return;
}
ofstream oFile;
oFile.open("Temp.dat",ios::out);
iFile.seekg(0,ios::beg);
while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
{
if(stud.setrollNumber()!=n)
{
oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
}
}
oFile.close();
iFile.close();
remove("student.dat");
rename("Temp.dat","student.dat");
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}