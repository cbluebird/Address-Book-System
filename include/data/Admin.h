//
// Created by crk on 23-4-30.
//

#ifndef ADDRESS_BOOK_SYSTEM_ADMIN_H
#define ADDRESS_BOOK_SYSTEM_ADMIN_H

#include <string>
#include <fstream>
#include <iostream>

class Admin {
    public:
        Admin(std::string, std::string);

        bool login();

    private:
        std::string name;
        std::string pwd;
        std::string path;
        std::string type;

};


#endif //ADDRESS_BOOK_SYSTEM_ADMIN_H
