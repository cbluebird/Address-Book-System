//
// Created by crk on 23-4-30.
//

#include "include/menu/Menu.h"

void Menu::displayAdminMainMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入对应功能前的编号来操作通讯录管理系统" << std::endl
              << "1: 添加新用户信息" << std::endl
              << "2: 查询用户信息" << std::endl
              << "3: 修改用户信息" << std::endl
              << "4: 删除用户信息" << std::endl
              << "5: 对用户信息进行排序" << std::endl
              << "0: 退出系统并保存数据" << std::endl;
    std::cout << ">";
}

void Menu::displayFetchMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入对应功能前的编号来查询信息" << std::endl
              << "1: 根据用户姓名进行精确查询" << std::endl
              << "2: 根据用户电话进行精确查询" << std::endl
              << "3: 根据地址进行模糊查询" << std::endl
              << "4：查看所有的用户信息"<<std::endl
              << "5: 根据用户id进行精确查询"<<std::endl
              << "6: 根据类别查询" << std::endl
              << "0: 返回上级菜单" << std::endl;
    std::cout << ">";
}

void Menu::displayUpdateMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入对应功能前的编号来修改信息" << std::endl
              << "1: 根据用户姓名进行修改信息" << std::endl
              << "2: 根据用户id进行修改信息" << std::endl
              << "3: 根据用户电话进行修改信息" << std::endl
              << "0: 返回上级菜单" << std::endl;
    std::cout << ">";
}

void Menu::displayDeleteMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入对应功能前的编号来删除用户" << std::endl
              << "1: 根据用户姓名进行删除" << std::endl
              << "2: 根据用户id进行删除" << std::endl
              << "3: 根据用户电话进行删除信息" << std::endl
              << "0: 返回上级菜单" << std::endl;
    std::cout << ">";
}

void Menu::displayUserMainMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入对应功能前的编号来操作通讯录管理系统" << std::endl
              << "1: 查询用户信息" << std::endl
              << "2: 对用户信息进行排序" << std::endl
              << "0: 退出系统并保存数据" << std::endl;
            std::cout << ">";
}

void Menu::displaySortUser(){
    cutRule();
    std::cout << "请输入排序关键词的编号" << std::endl
            << "1: 姓名" << std::endl
            << "2: 性别" << std::endl
            << "3: 电话" << std::endl
            << "4: 邮编" << std::endl
            << "5: 邮箱" << std::endl
            << "6: QQ号" << std::endl
            << "7: 类别" << std::endl;
            std::cout << ">";
}

void Menu::error(){
    std::cout << "输入有误，请重新输入\n>";
}

void Menu::cutRule() {
    std::cout << "----------------------------------------" << std::endl;
}