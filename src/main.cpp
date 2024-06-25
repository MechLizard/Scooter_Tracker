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
    Permissions permission[3] = {ADMIN,CUSTOMER,BUSINESS};    

    for(unsigned int i = 0; i < 26;i++){
	alph[i] = 'A'+i;
    }



    for(unsigned int i = 0; i < numberOfAccounts;i++){
	Account account = {};

	account.permission = permission[rand() % 3];
	for(unsigned int i = 0; i < 10;i++){

	    account.email.push_back(alph[rand() % 26]);
	    account.password.push_back(alph[rand() % 26]);
	    if(account.permission == BUSINESS){
		account.nameOfBusiness.push_back(alph[rand() % 26]);
		Booking booking = {};
		account.bookings.push_back(booking);
	    }

	}
	vector.push_back(account);
	
    }

}


void printAccounts(std::vector<Account>& vec){
    for(auto& i: vec){
	std::cout<<"email: "<<i.email<<std::endl;
	std::cout<<"pass: "<<i.password<<std::endl;
	if(i.permission == BUSINESS){
	    std::cout<<"Business Name: "<<i.nameOfBusiness<<std::endl;
	}
    }

}


unsigned int hashPassword(std::string password){
    unsigned int hash = 0;
    for(unsigned int i = 0; i < password.length();i++){
	hash+=password[i]<<i;
    }
    return hash;
}

void giveDiscount(Account& account, unsigned int discount){
    if(account.permission !=BUSINESS){
	std::cout<<"Only Business Accounts May Apply Discounts!"<<std::endl;
	return;
    }

    for(auto& i: account.bookings){
	if(int(i.price-discount) <=0){
	    i.price = 0;
	    continue;
	}
	i.price-=discount;
    }


}

void printDiscountsTest(std::vector<Account>& vec){

    for(unsigned int i = 0; i < vec.size();i++){
	if(vec[i].permission == BUSINESS){
	    std::cout<<"Price before discount "<<vec[i].bookings[0].price<<std::endl;
	    giveDiscount(vec[i],10);
	    std::cout<<"Price after discount "<<vec[i].bookings[0].price<<std::endl;
	    break;
	}
    }

}

int main(){
    srand(time(0));
    std::cout<<"Hello World"<<std::endl;
    std::vector<Account> vec;
    generateAccounts(vec,155);

    printAccounts(vec);
    std::cout<<"Testing hash: "<<hashPassword(vec[0].password)<<std::endl;
    printDiscountsTest(vec);    

}
