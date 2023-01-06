//ATM  machine project
#include<iostream>
using namespace std;
//create class
class Atm{
    private:
    string name;
    long accountNumber;
    long bankBalance=0;
    long amount=0;
    string type;
    public:
    int password=123;
    void SetAccount();
    void CheckBankBalance();
    void Deposited();
    void Withdrawn();
    void Showdata();
};
//Function to Set account holder data .
void Atm::SetAccount(){
cout<<"Enter your password.";
cin>>password;
if(password==123){
    cout<<"Enter your name.\n";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter Account Number.\n";
    cin>>accountNumber;
    cout<<"Enter Account type.\n";
    cin.ignore();
    getline(cin,type);
}
else{
    cout<<"you entered incorrect password.\n";
}
}
//function to Display data of account holder .
void Atm::Showdata(){
    cout<<"Enter your password";
    cin>>password;
    if(password==123){
    cout<<"Account holder information.\n";
    cout<<"==============================\n\n\n";
    cout<<"Account holder name="<<name<<endl;
    cout<<"Account Number="<<accountNumber<<endl;
    cout<<"Account holder type="<<type<<endl;
    cout<<"Total Balance="<<bankBalance;
    }
    else{
        cout<<"You entered incorrect password.";
    }
}
//Function to check toatal balance.
void Atm::CheckBankBalance(){
    cout<<"Enter your password.";
    cin>>password;
    if(password==123){
  cout<<"Your Total Balance = "<<bankBalance<<endl; 
    }
    else{
        cout<<"Please enter correct password.\n";
    } 
}
//Function to Deposited Amount.
void Atm::Deposited(){
    cout<<"Enter your password.";
    cin>>password;
    if(password==123){
    cout<<"Enter amount to deposited.\n";
    cin>>amount;
    bankBalance=bankBalance+amount;
    cout<<"Deposited successfully.\n";
    }
    else{
        cout<<"Please enter correct password.\n";
    }
}
//Function to Withdrawn Amount.
void Atm::Withdrawn(){
    cout<<"Enter your password.";
    cin>>password;
    if(password==123){
    cout<<"Enter amount to withdrawn.\n";
    cin>>amount;
    bankBalance=bankBalance-amount;
    cout<<"Withdrawn successfully.\n";
    }
    else{
        cout<<"Please enter correct password.\n";
    }
}
//main
int main(){
    Atm k;  //object of class.
    system("cls");
    int choice;
        cout<<"\t\t\t=============================\n";
        cout<<"\t\t\t==========Welcome============\n";
    do
    {
        cout<<"\t\t\t=============================\n";
        
        cout<<"\t\t\t1.Exits\n";
        cout<<"\t\t\t2.Set account details.\n";
        cout<<"\t\t\t3.Check total balance.\n";
        cout<<"\t\t\t4.Deposited amount.\n";
        cout<<"\t\t\t5.Withdrawn amount.\n";
        cout<<"\t\t\t6.Information about account holder\n";
        cout<<"\n\tEnter Your choice.\n";
        cin>>choice;
        system("cls");
        switch (choice)
        {
        case 1:
            cout<<"Thank you.";
            exit(0);
            break;
        case 2:
            k.SetAccount();
            break;
        case 3:
            k.CheckBankBalance();
            break;
        case 4:
            k.Deposited();
            break;
        case 5:
            k.Withdrawn();
            break;
        case 6:
            k.Showdata();
            break;
        default:
            cout<<"Please enter correct choice.\n";
            break;
        }
    } while (1);
    return 0;
    
}