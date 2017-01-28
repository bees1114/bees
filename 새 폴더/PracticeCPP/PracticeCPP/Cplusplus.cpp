#include <iostream>
#include <cstring>
using namespace std;

class Account {
	private :
		int account_number;
		char *name;
		int balance;
	public :
		Account() {
			
		}
		Account(int _acnt_num, char * _name, int _balance) : account_number(_acnt_num), balance(_balance) {
			name = new char[strlen(_name)+1];
			strcpy(name, _name);
		}

		void SetAccountInfo(int _acnt_num, char * _name, int _balance){
			name = new char[strlen(_name)+1];
			strcpy(name, _name);
			account_number = _acnt_num;
			balance = _balance;
		}
		void deposit(int money) {
			balance +=money;
		}
		void withdraw(int money) {
			balance -=money;
		}
		void ShowAccountInfo() const {
			cout<<"���¹�ȣ: "<<account_number<<endl;
			cout<<"��    ��: "<<name<<endl;
			cout<<"��    ��: "<<balance<<endl;
		}
		int getAccountNumber() const {
			return account_number;
		}
		int getBalance() const {
			return balance;
		}
		~Account() {

		}
};

void makeAccount(Account *AccountInfo);
void deposit(Account *AccountInfo);
void withdrawal(Account *AccountInfo);
void print(Account *AccountInfo);

int numberOfAccount;

int main(void) {
	int selector;
	Account *AccountInfo = new Account[100];
	//���ۺκ�
	
	while(1) {
		cout<<"-----------Menu-----------"<<endl;
		cout<<"1. ���°���"<<endl;
		cout<<"2. ��    ��"<<endl;
		cout<<"3. ��    ��"<<endl;
		cout<<"4. �������� ��ü ���"<<endl;
		cout<<"5. ���α׷� ����"<<endl;
		cout<<"���� :";
		cin>>selector;

		switch(selector) {
			case 1:
				makeAccount(AccountInfo);
				break; 
			case 2:
				deposit(AccountInfo);
				break;
			case 3:
				withdrawal(AccountInfo);
				break;
			case 4:
				print(AccountInfo);
				break;
			case 5:
				exit(0);
				break;
		}
	}
}


void makeAccount(Account *AccountInfo) {
	int id, money;
	char name[100];
	cout<<"------------------------------"<<endl;
	cout<<"[���� ����]"<<endl;
	cout<<"����ID: ";
	cin>>id;
	cout<<"��  ��: ";
	cin>>name;
	cout<<"�Աݾ�: ";
	cin>>money;
	AccountInfo[numberOfAccount].SetAccountInfo(id, name, money);
	numberOfAccount++;
}

void deposit(Account *AccountInfo) {
	int accountID, i, money;
	cout<<"------------------------------"<<endl;
	cout<<"[��  ��]"<<endl;
	cout<<"����ID: ";
	cin>>accountID;
	for(i = 0; i < numberOfAccount; i++) {
		if(AccountInfo[i].getAccountNumber() == accountID)
			break;
	}
	if(numberOfAccount == i)
		cout<<"�׷� ���´� �����ϴ�."<<endl;
	else {
		cout<<"�Աݾ�: ";
		cin>>money;
		AccountInfo[i].deposit(money);
	}
	cout<<"�Ա� �Ϸ�!"<<endl;
}

void withdrawal(Account *AccountInfo) {
	int accountID, i, money;
	cout<<"------------------------------"<<endl;
	cout<<"[��  ��]"<<endl;
	cout<<"����ID: ";
	cin>>accountID;
	for(i = 0; i < numberOfAccount; i++) {
		if(AccountInfo[i].getAccountNumber() == accountID)
			break;
	}
	if(numberOfAccount == i)
		cout<<"�׷� ���´� �����ϴ�."<<endl;
	else {
		cout<<"��ݾ�: ";
		cin>>money;
		if(AccountInfo[i].getBalance() < money)
			cout<<"�ܾ� ����"<<endl;
		else
		AccountInfo[i].withdraw(money);
	}
	cout<<"��� �Ϸ�!"<<endl;
}

void print(Account *AccountInfo) {
	int i;

	cout<<"------------------------------"<<endl;
	for(i = 0; i < numberOfAccount; i++) {
		AccountInfo[i].ShowAccountInfo();
	}
}