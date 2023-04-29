//
// Created by crk on 23-4-29.
//

#include "User.h"

#include <utility>
#include <regex>
#include <iostream>

std::istream &operator>>(std::istream &in, User &right) {
    if(typeid(in) == typeid(std::cin)) {
        std::cout << "请输入该用户的姓名：";
    }
    in>> right.user_id;
    in >> right.name;

    std::string phoneNum;
    if(typeid(in) == typeid(std::cin)) {
        std::cout << "请输入" << right.name << "的电话号码：";
    }
    while (in >> phoneNum) {
        if (regex_match(phoneNum, std::regex("[1-9][0-9]{10}"))) {
            right.phone=phoneNum;
            break;
        } else {
            std::cout << "输入的电话号码格式非法，应该为11位非0开头的纯数字，请重新输入：";
        }
    }

    if(typeid(in) == typeid(std::cin)) {
        std::cout << "请输入" << right.name << "的住址";
    }
    in >> right.address;

    std::string eMail;
    if(typeid(in) == typeid(std::cin)) {
        std::cout << "请输入" << right.email << "的电子邮箱（输入0代表为留空）：";
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

//    std::string QQNum;
//    if(typeid(in) == typeid(std::cin)) {
//        std::cout << "请输入" << right.name << "的QQ号（输入0代表为留空）：";
//    }
//    while (in >> QQNum) {
//        if (regex_match(QQNum, std::regex("[1-9][0-9]{4,}"))) {
//            right.setQqNum(QQNum);
//            break;
//        } else if (QQNum == "0") {
//            right.setQqNum("");
//            break;
//        } else {
//            std::cout << "输入的QQ号格式非法，应该为至少五位且首位非0的纯数字，请重新输入：";
//        }
//    }
//
//    std::string type;
//    if(typeid(in) == typeid(std::cin)) {
//        std::cout << "请输入" << right.name << "的类型：";
//    }
//    in >> right.type;
    return in;
}

std::ostream &operator<<(std::ostream &out, const User &right) {
    if(typeid(out) == typeid(std::cout)) {
        out <<"用户id"<<right.user_id<<'\n'
            << "姓名:" << right.name << '\n'
            << "电话:" << right.phone<< "\n"
            << "地址:" << right.address<< '\n';
    } else {
        out << right.name<< " "<< right.phone << " " << right.address;
        if(right.email.empty()) {
            out << "0" << " ";
        } else {
            out << right.email << " ";
        }
    }
    return out;
}