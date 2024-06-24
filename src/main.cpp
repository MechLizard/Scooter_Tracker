#include <iostream>
#include <string>
#include <vector>

enum Permissions{
    ADMIN,
    CUSTOMER,
    BUSINESS,
};

struct Booking{
    unsigned int price;
    std::string time;
};



struct Account{
    std::string email;
    std::string password;
    Permissions permission;
    std::string phoneNumber;
    std::string nameOfBusiness;

    std::vector<Booking> bookings;
};





void generateAccounts(std::vector<Account>& vector, unsigned int numberOfAccounts){
    char alph[26];


    for(unsigned int i = 0; i < 26;i++){
	alph[i] = 'A'+i;
    }



    for(unsigned int i = 0; i < numberOfAccounts;i++){
	Account account;
	for(unsigned int i = 0; i < 10;i++){

	    account.email.push_back(alph[rand() % 26]);
	    account.password.push_back(alph[rand() % 26]);
	    if(account.permission == BUSINESS){
		account.nameOfBusiness.push_back(alph[rand() % 26]);
	    }

	}
	vector.push_back(account);
	
    }

}


void printAccounts(std::vector<Account>& vec){
    for(auto& i: vec){
	std::cout<<i.email<<std::endl;
    }

}


int main(){
    srand(time(0));
    std::cout<<"Hello World"<<std::endl;
    std::vector<Account> vec;
    generateAccounts(vec,155);

    printAccounts(vec);
    

    

}
