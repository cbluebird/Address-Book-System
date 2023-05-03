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
    std::string sex;         // 性别
    std::string postalCode;  // 邮政编码
    std::string QQNum;       // QQ号
    std::string type;        // 类型

    static int user_num;
    std::string getUserIdINString();
public:
    int getUserId();
    std::string getName();
    std::string getPhone();
    std::string getEmail();
    std::string getAddress();
    std::string getSex();
    std::string getPostalCode();
    std::string getQQNum();
    std::string getType();
    static int getNum();
    void setName(std::string name);
    void setEmail(std::string email);
    void setPhone(std::string phone);
    void setAddress(std::string address);
    void setUserId(int user_id);
    void setSex(std::string sex);
    void setPostalCode(std::string postalCode);
    void setQQNum(std::string QQNum);
    void setType(std::string type);
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
