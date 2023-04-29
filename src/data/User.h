//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_USER_H
#define ADDRESS_BOOK_SYSTEM_USER_H

#include<string>

class User {
public:
    User(){}
    User(std::string name_,std::string phone_):name(name_),phone(phone_){}
    int user_id;
    std::string name;
    std::string phone;
    std::string email;
    std::string address;
    std::string to_string(){
        std::string result;
        result=name+" "+phone+" "+email;
        return result;
    }
    friend std::istream &operator>>(std::istream &in, User &right);
    friend std::ostream &operator<<(std::ostream &out, const User &right);
};

#endif //ADDRESS_BOOK_SYSTEM_USER_H
