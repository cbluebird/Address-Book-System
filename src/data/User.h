//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_USER_H
#define ADDRESS_BOOK_SYSTEM_USER_H

#include<string>

class User {
private:
    int user_id;
    std::string name;
    std::string phone;
    std::string email;
    std::string address;
    static int user_num;
    std::string getUserIdINString();
public:
    int getUserId();
    std::string getName();
    std::string getPhone();
    std::string getEmail();
    std::string getAddress();
    static int getNum();
    void setName(std::string name);
    void setEmail(std::string email);
    void setPhone(std::string phone);
    void setAddress(std::string address);
    void setUserId(int user_id);
    static void setNum(int);
    std::string to_string(){
        std::string result;
        auto userID=getUserIdINString();
        result=userID+"  "+name+"  "+phone+"  "+address+" "+email;
        return result;
    }
    User(int , std::string , std::string , std::string , std::string );
    User(std::string , std::string , std::string , std::string );
    User(){}
    friend std::istream &operator>>(std::istream &in, User &right);
    friend std::ostream &operator<<(std::ostream &out, const User &right);
};




#endif //ADDRESS_BOOK_SYSTEM_USER_H
