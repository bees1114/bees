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
			cout<<"계좌번호: "<<account_number<<endl;
			cout<<"이    름: "<<name<<endl;
			cout<<"잔    액: "<<balance<<endl;
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
	//시작부분
	
	while(1) {
		cout<<"-----------Menu-----------"<<endl;
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입    금"<<endl;
		cout<<"3. 출    금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택 :";
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
	cout<<"[계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이  름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>money;
	AccountInfo[numberOfAccount].SetAccountInfo(id, name, money);
	numberOfAccount++;
}

void deposit(Account *AccountInfo) {
	int accountID, i, money;
	cout<<"------------------------------"<<endl;
	cout<<"[입  금]"<<endl;
	cout<<"계좌ID: ";
	cin>>accountID;
	for(i = 0; i < numberOfAccount; i++) {
		if(AccountInfo[i].getAccountNumber() == accountID)
			break;
	}
	if(numberOfAccount == i)
		cout<<"그런 계좌는 없습니다."<<endl;
	else {
		cout<<"입금액: ";
		cin>>money;
		AccountInfo[i].deposit(money);
	}
	cout<<"입금 완료!"<<endl;
}

void withdrawal(Account *AccountInfo) {
	int accountID, i, money;
	cout<<"------------------------------"<<endl;
	cout<<"[출  금]"<<endl;
	cout<<"계좌ID: ";
	cin>>accountID;
	for(i = 0; i < numberOfAccount; i++) {
		if(AccountInfo[i].getAccountNumber() == accountID)
			break;
	}
	if(numberOfAccount == i)
		cout<<"그런 계좌는 없습니다."<<endl;
	else {
		cout<<"출금액: ";
		cin>>money;
		if(AccountInfo[i].getBalance() < money)
			cout<<"잔액 부족"<<endl;
		else
		AccountInfo[i].withdraw(money);
	}
	cout<<"출금 완료!"<<endl;
}

void print(Account *AccountInfo) {
	int i;

	cout<<"------------------------------"<<endl;
	for(i = 0; i < numberOfAccount; i++) {
		AccountInfo[i].ShowAccountInfo();
	}
}