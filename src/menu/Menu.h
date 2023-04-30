//
// Created by crk on 23-4-30.
//

#ifndef ADDRESS_BOOK_SYSTEM_MENU_H
#define ADDRESS_BOOK_SYSTEM_MENU_H

#include <iostream>

class Menu {
public:
    void displayAdminMainMenu();
    void displayDeleteMenu();
    void displayUpdateMenu();
    void displayFetchMenu();
    void displayUserMainMenu();

    void error();

    void cutRule();
};


#endif //ADDRESS_BOOK_SYSTEM_MENU_H
