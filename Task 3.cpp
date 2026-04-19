#include<iostream>
#include<string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    void setData(string t, double a) {
        type = t;
        amount = a;
    }
    void show() {
        cout<<type<<" : "<<amount<<endl;
    }
};
class Account {
private:
    int accNo;
    double balance;
    Transaction history[100];
    int count;
public:
    Account() {
        accNo = 0;
        balance = 0;
        count = 0;
    }
    void setAccount(int n) {
        accNo = n;
    }
    void deposit(double amount) {
        balance += amount;
        history[count].setData("Deposit", amount);
        count++;
    }
    void withdraw(double amount) {
        if(amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        history[count].setData("Withdraw", amount);
        count++;
    }
    void showBalance() {
        cout << "Balance: " << balance << endl;
    }
    void showTransactions() {
        cout << "Transaction History:\n";
        for(int i = 0; i < count; i++) {
            history[i].show();
        }
    }
};
class Customer{
private:
    string name;
    int id;
    Account acc;
public:
    void setCustomer(string n, int i, int accNo){
        name = n;
        id = i;
        acc.setAccount(accNo);
    }
    Account& getAccount(){
        return acc;
    }
    void showInfo(){
        cout<<"\nName: "<<name<<"\nID: "<<id<<endl;
        acc.showBalance();
    }
};
int main() {
    Customer c1;
    string name;
    int id, accNo;
    int choice;
    double amount;
    // User Input for Customer
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter ID: ";
    cin>>id;
    cout<<"Enter Account Number: ";
    cin>>accNo;
    c1.setCustomer(name, id, accNo);
    do {
        cout<<"\n1. Deposit\n2. Withdraw\n3. Show Info\n4. Show Transactions\n5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice) {
            case 1:{
                cout<<"Enter amount: ";
                cin>>amount;
                c1.getAccount().deposit(amount);
                break;
			}
            case 2:{
                cout << "Enter amount: ";
                cin >> amount;
                c1.getAccount().withdraw(amount);
                break;
			}
            case 3:{
                c1.showInfo();
                break;
			}
            case 4:{
                c1.getAccount().showTransactions();
                break;
			}
            case 5:{
                cout<<"Exiting...\n";
                break;
			}
            default:{
                cout<<"Invalid choice!\n";
            }
        }

    } while(choice != 5);
    return 0;
}
