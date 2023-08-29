#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class ATM{
	private: 
		map<string, int> Money; // mapping from account to money  
		map<string, vector<string> > Accounts; // mapping from card num to accounts 
	public: 
		void newAccount(string card_id, string account_name){
			Accounts[card_id].push_back(account_name); 
			Money[account_name] = 0; 
		}
		
		int isPINCorrect(string card_id, string pin_input){
			if(card_id.length() != pin_input.length()) return 0; 
			int L = card_id.length();
			for(int i = 0; i < L ; i ++ ){
				if(card_id[i] != pin_input[L - 1 - i]) return 0; 
			}
			return 1;
		}
		
		
		void showAllAccountsForCard(string card_id){
			vector <string> V = Accounts[card_id];
			for(int i = 0; i < V.size(); i ++ ){
				cout << i + 1 << "." << V[i] << endl;  
			} 	
		}
		
		void balance(string acc){
			cout << "Account " << acc << ": " << "current balance is " << Money[acc]  << " dollar (s) " << endl; 
		}
		
		void deposit(string acc, int money){
			Money[acc] += money; 
			cout << "Account " << acc << ": " << money << " dollar (s) deposited!" << endl; 
		} 
		
		
		void withdraw(string acc, int money){
			if(Money[acc] >= money){
				Money[acc] -= money; 
				cout << "Account " << acc << ": " <<  money << " dollar (s) sucessfully withdrawn" << endl;
			}
			else cout << "Account " << acc << ": " << "Not enough money on bank!!" << endl; 
		}
		
		~ATM(){
			cout << "ATM Destructor" << endl;
		}
	
};




int main(void) { 

	// User Pool (Pre Scenario)
	ATM atm = ATM(); 
	atm.newAccount("1234", "0123"); 
	atm.deposit("0123", 100);  
	
	
	atm.newAccount("1234", "0124"); 
	atm.deposit("0124", 300); 
	
	atm.newAccount("1234", "0125"); 
	atm.deposit("0125", 400); 
	
	atm.newAccount("1235", "1123"); 
	atm.deposit("1123", 400); 
	
	atm.newAccount("1235", "1124"); 
	atm.deposit("1124", 300); 
	atm.newAccount("1235", "1125"); 
	atm.deposit("1125", 900); 

	while(1){
		string card_id;
		string pin; 
		string account;  
		string input; 
		cout << "insert card [input card number] : "; 
		cin >> card_id;  
		cout << "type PIN : "; 
		cin >> pin; 
		while(!atm.isPINCorrect(card_id, pin)){
			 cout << "wrong pin, try again" << endl;  
			 cout << "type PIN : "; 
			cin >> pin;  
		}
		cout << "choose an account :" << endl;
		atm.showAllAccountsForCard(card_id); 
		// print accounts 
		cin >> account; 
		
		int workdone = 0;
		while(!workdone){
			cout << "what do you want to do? {balance, deposit, withdraw} : "; 
			cin >> input; 
			if(input == "balance"){
				atm.balance(account); 
			}
			else if(input == "withdraw"){
				cout << "how much ? [int input]:"; 
				int m; 
				cin >> m; 
				atm.withdraw(account, m);
			}
			else if(input == "deposit"){
				cout << "how much ? [int input]:"; 
				int m; 
				cin >> m; 
				atm.deposit(account, m);		
			}
			else{
				cout << "you typed the wrong option. try again" << endl; 
			}
			cout << "do you done working with this account? [y/n]"; 
			string yn; 
			cin >> yn;
			if(yn == "y") workdone = 1;  
		}
		cout<< "do you want to exit? [y/n]"; 
		string yn;
		cin >> yn; 
		if(yn == "y") break;
		
	}
	
	cout << "-------- ATM Finished --------" << endl;
    
}


// assumption 
// 카드를 넣는 행위 : 카드 번호를 입력하는 행위로 보고, 카드 번호를 입력하도록 한다.  
// PIN 번호의 정확성 판별 기준 : (PIN 번호 ) = (카드 번호를 앞뒤로 뒤집은 번호) 의 관계가 성립한다 가정 

// PIN 틀리는 경우를 제외하고는 유저는 항상 기대되는 선택지 중에서 input한다.
// 없는 카드번호는 입력으로 들어오지 않는다.   

// Reference website
// https://coding-factory.tistory.com/697 

 
  
