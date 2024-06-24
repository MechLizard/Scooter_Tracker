#include <iostream>
#include <string>

enum Permissions{
    ADMIN,
    CUSTOMER,
    BUSINESS,
};


struct Account{
    std::string email;
    std::string password;
    Permissions permission;
    std::string phoneNumber;
    std::string nameOfBusiness;
};


struct Booking{
    Account account;
    unsigned int price;
    std::string time;
};





int main(){
    std::cout<<"Hello World"<<std::endl;

    Booking booking = {};
    std::cout<<booking.account.permission<<std::endl;

}
