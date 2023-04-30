//
// Created by crk on 23-4-29.
//

#include "User.h"

#include <utility>
#include <regex>
#include <iostream>

int User::user_num=0;

std::istream &operator>>(std::istream &in, User &right) {
    if(typeid(in) != typeid(std::cin)) {
        in >> right.user_id;
    }
    if(typeid(in) == typeid(std::cin)) {
        std::cout << "请输入该用户的姓名（输入0代表为留空）：";
    }
    in >> right.name;
    if(right.name=="0") {
        right.name = "";
    }
    std::string phoneNum;
    if(typeid(in) == typeid(std::cin)) {
        std::cout <<"请输入" << right.name << "的电话号码（输入0代表为留空）：";
    }
    while (in >> phoneNum) {
        if(right.phone=="0") {
            right.phone= "";
            break;
        }
        if (regex_match(phoneNum, std::regex("[1-9][0-9]{10}"))) {
            right.phone=phoneNum;
            break;
        } else {
            std::cout << "输入的电话号码格式非法，应该为11位非0开头的纯数字，请重新输入：";
        }
    }

    if(typeid(in) == typeid(std::cin)) {
        std::cout<< "请输入" << right.name << "的住址,注意在地址中不能带空格（输入0代表为留空）:";
    }
    while(in >> right.address){
        if(right.address=="0") {
            right.address = "";
            break;
        }
        int flag=1;
        for(int i=0;i<right.address.size()&&flag;i++)
            if(right.address[i]==' '){
                std::cout<<"输入的住址格式非法，不能包含空格,请再次输入:";
                flag=0;
            }
        if(flag)break;
    }

    std::string eMail;
    if(typeid(in) == typeid(std::cin)) {
        std::cout <<"请输入" << right.name << "的电子邮箱（输入0代表为留空）：";
    }
    while (in >> eMail) {
        if (regex_match(eMail, std::regex(R"(^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$)"))) {
            right.email=eMail;
            break;
        } else if (eMail == "0") {
            right.email="";
            break;
        } else {
            std::cout << "输入的邮箱地址格式非法，正确的样例为：123456@zjut.edu.cn，请重新输入：";
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const User &right) {
    if(typeid(out) == typeid(std::cout)) {
        out <<"用户id:"<<right.user_id<<'\n'
            << "姓名:" << right.name << '\n'
            << "电话:" << right.phone<< "\n"
            << "地址:" << right.address<< '\n'
            <<"邮箱:"<< right.email<< '\n';
    } else {
//        out << right.user_id;
//        out<<" "<<right.name;
//        out<<" "<< right.phone;
//        out <<" " << right.address;
//        out<<" "<<right.email;
        out<<right.user_id<<" ";
        if(right.name.empty()) {
            out << "0" << " ";
        } else {
            out << right.name << " ";
        }
        if(right.phone.empty()) {
            out << "0" << " ";
        } else {
            out << right.phone << " ";
        }
        if(right.address.empty()) {
            out << "0" << " ";
        } else {
            out << right.address << " ";
        }
        if(right.email.empty()) {
            out << "0" << " ";
        } else {
            out << right.email << " ";
        }
    }
    return out;
}

int User::getUserId() {
    return user_id;
}

std::string User::getName() {
    return name;
}

std::string User::getPhone() {
    return phone;
}

std::string User::getEmail() {
    return email;
}

std::string User::getAddress() {
    return address;
}

void User::setName(std::string name) {
    this->name = name;
}

void User::setEmail(std::string email_) {
    this->email = email_;
}

void User::setPhone(std::string phone) {
    this->phone = phone;
}

void User::setAddress(std::string address) {
    this->address = address;
}

User::User(int user_id, std::string name, std::string phone, std::string address, std::string email){
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

User::User(std::string name, std::string phone, std::string address, std::string email) {
    this->user_id=++User::user_num;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

int User::getNum() {
    return user_num;
}

void User::setNum(int num_) {
    user_num=num_;
}

std::string User::getUserIdINString() {
    std::string s;
    int x=user_id;
    while(x>0){
        s=std::to_string(x%10)+s;
        x/=10;
    }
    return s;
}

void User::setUserId(int user_id) {
    this->user_id=user_id;
}










