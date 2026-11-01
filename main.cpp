#include <iostream>
#include <string>
using namespace std;

class Account{
protected:
    string AccountNumber;
    double balance;
public:
    Account(string accNum , double initialBalance){
    AccountNumber = accNum;
    balance = initialBalance;
    }
    bool deposit(double amount){
     if (amount > 0 ){
        balance += amount;
        return true;
    }
     return false;
    }
    virtual bool withdraw(double amount){
     if (amount > 0 && amount <= balance){
        balance -= amount ;
        return true;
    }
     return false;
    }
      string getAccountNumber(){
         return AccountNumber;

    }
      double getBalance(){
         return balance;
    }
      virtual void displayInfo(){
        cout << "AccountNumer : " << getAccountNumber() <<endl;
        cout << "Balance : " << getBalance() <<endl;
    }
};
class SavingsAccount :public Account{
private:
    double interestRate;
public:
    SavingsAccount(string accNum , double initialBalance , double interesttRate): Account(accNum,initialBalance){
     interestRate = interesttRate;
    }
     void applyInterest(){
    balance += balance * (interestRate / 100);
    }
    void displayInfo(){
      cout << "SavingAcount"  <<  "\n\n" ;
      cout << "InterestRate : " << interestRate <<endl;
      cout << "TotalBalance : " << balance <<endl;
    }
};
class CheckingAccount:public Account{
 private:
     double overdraftlimit;
 public:
     CheckingAccount(double over,string accNum , double initialBalance):Account(accNum,initialBalance){
      overdraftlimit = over;
     }
     bool withdraw(double amount)override{
       if (balance - amount >= -overdraftlimit && amount > 0){
        balance -= amount;
        return true;
       }
       return false;
     }
     void displayInfo(){
      cout << "CheckingAccount" <<"\n\n";
      cout << "Overdraft Allowance : " << overdraftlimit <<endl;
      cout << "CurrentBalance : " << balance <<endl;
     }
};

int main()
{
    string accNum;
    double Balance;
    double interestRate;
    double initalBalance;
    double overdraftlimit;
   Account* account [1];
   int accountCount = 0;
   char choice;

   while (accountCount < 1){
    cout << "Choose Account Type (s = Savings, c = Checking): ";
   cin >> choice;
   cout <<endl;
   if(choice == 's'){
        cout << "AccountNumber : ";
        cin >> accNum;
        cout << "Balance : ";
        cin >> Balance;
        cout << "InterestRate : ";
        cin >> interestRate;
        cout << endl;
     account[accountCount] = new SavingsAccount(accNum,Balance,interestRate);
     account[accountCount] ->displayInfo();
     accountCount++;
     cout <<endl;
   }
   else if (choice == 'c'){
    cout << "AccountNumber : ";
    cin >>accNum;
    cout << "overdraftlimit : ";
    cin >>overdraftlimit;
    cout << "InitialBalance : ";
    cin >> initalBalance;
    cout <<endl;
     account [accountCount]= new CheckingAccount(overdraftlimit,accNum,initalBalance);
     account [accountCount]-> displayInfo();
     accountCount++;
     cout <<endl;
   }
   }
   while(true){
        int accountNum;
        double amount;
    cout << " Choose Account: ";
    cin >> accountNum;
    cout << "choice :" ;
    cin >> choice;
    if(choice == '1'){
        cout << "Deposit : ";
        cin >> amount;
    if(account[accountNum]->deposit(amount)){
            cout << true <<endl;
            cout << "Deposit : " << account[accountNum]->getBalance();
        }else{
         cout << false;
        }
        cout <<endl;
    }
    if(choice == '2'){
        cout << "Withdraw : ";
        cin >> amount;
        if (account[accountNum]->withdraw(amount)){
            cout << true <<endl;
        cout << " Withdraw : " << account[accountNum]->getBalance();
        }else{
         cout <<false;
        }
        cout <<endl;
    }
    if (choice == '3'){
        cout << "GetBalance : ";
        cout << account[accountNum]->getBalance();
        cout <<endl;
    }
   if (choice == '4'){
     account[accountNum]->displayInfo();

     cout <<endl;
   }
   if (choice == '5'){
    break;
      }
   }
   for (int i=0; i< accountCount ; i++){
    delete account[i];
   }
   return 0;
}
