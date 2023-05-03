//
// Created by crk on 23-4-25.
//

#include"include/executor/Table.h"
#include"src/executor/Table.cpp"
#include "include/data/User.h"
#include "include/menu/Menu.h"
#include "include/data/Admin.h"

int main(){
    Menu menu;
    Table<User,int> userDB=Table<User,int>("../data/data", ".txt",[](User user){return user.getUserId();});
    User::setNum(userDB.getEndKey());
    int userType = 1;
    bool flagMain = true;
    bool flagMain_ = true;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "欢迎使用通讯录管理系统" << std::endl;
    std::cout << "请选择登录身份" << std::endl;
    std::cout << "1: 管理员" << std::endl;
    std::cout << "2: 用户" << std::endl;
    std::cout << "0: 退出" << std::endl;
    std::cout << ">";
    while(flagMain && std::cin >> userType && userType) {
        int typeNum;
        if(userType ==1){
            Admin admin("../data/admin", ".txt");
            if(!admin.login()) {
                flagMain_ = false;
                break;
            }
            menu.displayAdminMainMenu();
            while (flagMain_ && std::cin >> typeNum) {
                switch (typeNum) {
                    case 1: {
                        User user;
                        std::cin>>user;
                        int x=user.getNum();
                        user.setUserId(++x);
                        user.setNum(x);
                        userDB.insert(x,user);
                        break;
                    }
                    case 2: {
                        int flag=1;
                        int typeNum_=0;
                        menu.displayFetchMenu();
                        while(flag&&std::cin>>typeNum_){
                            switch (typeNum_) {
                                case 1: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要查询的姓名: ";
                                    User user;
                                    std::string name;
                                    std::cin>>name;
                                    user.setName(name);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        if(user1.getName()==user2.getName())return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"输入的名字不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 2: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要查询的电话: ";
                                    User user;
                                    std::string phone;
                                    std::cin>>phone;
                                    user.setPhone(phone);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        if(user1.getPhone()==user2.getPhone())return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"输入的电话不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 3: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要模糊查询的地址: ";
                                    User user;
                                    std::string address;
                                    std::cin>>address;
                                    user.setAddress(address);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        int f=0,flag_=0;
                                        std::string address=user2.getAddress();
                                        std::string mh=user1.getAddress();
                                        for(int i=0;i<address.size()&!flag_;i++){
                                            if(address[i]==mh[f]){
                                                f++;
                                            }
                                            if(f==mh.size()-1)flag_=1;
                                        }
                                        if(flag_)return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"用户不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    auto ans=userDB.queryAll();
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 5: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要查询的用户id: ";
                                    int userID;
                                    std::cin>>userID;
                                    auto ans=userDB.querySingleWithKey(userID);
                                    if(ans== nullptr){
                                        std::cout<<"用户不存在"<<std::endl;
                                        break;
                                    }
                                    std::cout<<*ans<<std::endl;
                                    break;
                                }
                                case 6: {
                                    menu.cutRule();
                                    std::cout<<"请输入查询的类别: ";
                                    User user;
                                    std::string l;
                                    std::cin>>l;
                                    user.setType(l);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        if(user1.getType()==user2.getType())return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"输入的类别不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 0:{
                                    flag=0;
                                    break;
                                }
                                default: {
                                    std::cout << "输入错误" << std::endl;
                                    break;
                                }
                            }
                            if(flag)menu.displayFetchMenu();
                        }
                        break;
                    }
                    case 3: {
                        int typeNum_=0;
                        menu.displayUpdateMenu();
                        std::cin>>typeNum_;
                        if(typeNum_==1){
                            menu.cutRule();
                            std::cout<<"请输入需要更新的姓名：";
                            std::string name;
                            std::cin>>name;
                            User user;
                            user.setName(name);
                            auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                if(user1.getName()==user2.getName())return true;
                                else return false;
                            });
                            if(ans.size()==0){
                                std::cout<<"输入的名字不存在"<<std::endl;
                                break;
                            }
                            for(int i=0;i<ans.size();i++){
                                std::cout<<ans[i]<<std::endl;
                            }
                            if(ans.size()==0){
                                std::cout<<"该用户不存在"<<std::endl;
                                break;
                            }
                            std::cout<<"请选择你要更新的用户信息的编号:";
                            int user_id;
                            std::cin>>user_id;
                            int flag=1;
                            for(int i=0;i<ans.size()&&flag;i++){
                                if(ans[i].getUserId()==user_id){
                                    user=ans[i];
                                    flag=0;
                                }
                            }
                            if(flag){
                                menu.error();
                                break;
                            }
                            User update_user;
                            update_user.setUserId(user_id);
                            std::cout<<"请输入你要更新的用户信息：";
                            std::cin>>update_user;
                            if(update_user.getName()=="")update_user.setName(user.getName());
                            if(update_user.getPhone()=="")update_user.setPhone(user.getPhone());
                            if(update_user.getAddress()=="")update_user.setAddress(user.getAddress());
                            if(update_user.getEmail()=="")update_user.setEmail(user.getEmail());
                            if(update_user.getQQNum()=="")update_user.setQQNum(user.getQQNum());
                            if(update_user.getPostalCode()=="")update_user.setPostalCode(user.getPostalCode());
                            if(update_user.getSex()=="")update_user.setSex(user.getSex());
                            if(update_user.getType()=="")update_user.setType(user.getType());
                            userDB.updateWithoutKey(update_user);
                        }else if(typeNum_==2){
                            std::cout<<"请选择你要更新的用户信息的编号:";
                            int user_id;
                            std::cin>>user_id;
                            auto user=userDB.querySingleWithKey(user_id);
                            if(user== nullptr){
                                std::cout<<"该用户不存在"<<std::endl;
                                break;
                            }
                            std::cout<<*user;
                            menu.cutRule();
                            User update_user;
                            update_user.setUserId(user_id);
                            std::cout<<"请输入你要更新的用户信息"<<std::endl;
                            std::cin>>update_user;
                            if(update_user.getName()=="")update_user.setName(user->getName());
                            if(update_user.getPhone()=="")update_user.setPhone(user->getPhone());
                            if(update_user.getAddress()=="")update_user.setAddress(user->getAddress());
                            if(update_user.getEmail()=="")update_user.setEmail(user->getEmail());
                            if(update_user.getQQNum()=="")update_user.setQQNum(user->getQQNum());
                            if(update_user.getPostalCode()=="")update_user.setPostalCode(user->getPostalCode());
                            if(update_user.getSex()=="")update_user.setSex(user->getSex());
                            if(update_user.getType()=="")update_user.setType(user->getType());
                            userDB.updateWithoutKey(update_user);
                        }else if(typeNum_==3){
                            menu.cutRule();
                            std::cout<<"请输入需要更新的电话：";
                            std::string phone;
                            std::cin>>phone;
                            User user;
                            user.setPhone(phone);
                            auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                if(user1.getPhone()==user2.getPhone())return true;
                                else return false;
                            });
                            if(ans.size()==0){
                                std::cout<<"输入的电话不存在"<<std::endl;
                                break;
                            }
                            for(int i=0;i<ans.size();i++){
                                std::cout<<ans[i]<<std::endl;
                            }
                            if(ans.size()==0){
                                std::cout<<"该用户不存在"<<std::endl;
                                break;
                            }
                            std::cout<<"请选择你要更新的用户信息的编号:";
                            int user_id;
                            std::cin>>user_id;
                            int flag=1;
                            for(int i=0;i<ans.size()&&flag;i++){
                                if(ans[i].getUserId()==user_id){
                                    user=ans[i];
                                    flag=0;
                                }
                            }
                            if(flag){
                                menu.error();
                                break;
                            }
                            User update_user;
                            update_user.setUserId(user_id);
                            std::cout<<"请输入你要更新的用户信息：";
                            std::cin>>update_user;
                            if(update_user.getName()=="")update_user.setName(user.getName());
                            if(update_user.getPhone()=="")update_user.setPhone(user.getPhone());
                            if(update_user.getAddress()=="")update_user.setAddress(user.getAddress());
                            if(update_user.getEmail()=="")update_user.setEmail(user.getEmail());
                            if(update_user.getQQNum()=="")update_user.setQQNum(user.getQQNum());
                            if(update_user.getPostalCode()=="")update_user.setPostalCode(user.getPostalCode());
                            if(update_user.getSex()=="")update_user.setSex(user.getSex());
                            if(update_user.getType()=="")update_user.setType(user.getType());
                            userDB.updateWithoutKey(update_user);
                        }else{
                            menu.error();
                        }
                        break;
                    }
                    case 4: {
                        int typeNum_=0;
                        menu.displayDeleteMenu();
                        std::cin>>typeNum_;
                        if(typeNum_==1){
                            menu.cutRule();
                            std::cout<<"请输入需要更新的姓名：";
                            std::string name;
                            std::cin>>name;
                            User user;
                            user.setName(name);
                            auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                if(user1.getName()==user2.getName())return true;
                                else return false;
                            });
                            if(ans.size()==0){
                                std::cout<<"输入的名字不存在"<<std::endl;
                                break;
                            }
                            for(int i=0;i<ans.size();i++){
                                std::cout<<ans[i]<<std::endl;
                            }
                            if(ans.size()==0){
                                menu.error();
                                break;
                            }
                            std::cout<<"请选择你要删除的用户信息的编号:"<<std::endl;
                            int user_id;
                            std::cin>>user_id;
                            int flag=1;
                            for(int i=0;i<ans.size()&&flag;i++){
                                if(ans[i].getUserId()==user_id){
                                    flag=0;
                                }
                            }
                            if(flag){
                                menu.error();
                                break;
                            }
                            menu.cutRule();
                            std::cout<<"确定要删除该用户信息吗，确定请输入1,取消选择2"<<std::endl<<">";
                            std::cin>>flag;
                            if(flag==1){
                                userDB.remove(user_id);
                            }
                            break;
                        }else if(typeNum_==2){
                            std::cout<<"请选择你要删除的用户信息的编号:"<<std::endl;
                            int user_id;
                            std::cin>>user_id;
                            auto user=userDB.querySingleWithKey(user_id);
                            if(user== nullptr){
                                std::cout<<"该用户不存在"<<std::endl;
                                break;
                            }
                            std::cout<<*user;
                            menu.cutRule();
                            std::cout<<"确定要删除该用户信息吗，确定请输入1,取消选择2"<<std::endl<<">";
                            int flag;
                            std::cin>>flag;
                            if(flag==1){
                                userDB.remove(user_id);
                            }
                            break;
                        }else if(typeNum_==3){
                            menu.cutRule();
                            std::cout<<"请输入需要删除的电话：";
                            std::string phone;
                            std::cin>>phone;
                            User user;
                            user.setPhone(phone);
                            auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                if(user1.getPhone()==user2.getPhone())return true;
                                else return false;
                            });
                            if(ans.size()==0){
                                std::cout<<"输入电话不存在"<<std::endl;
                                break;
                            }
                            for(int i=0;i<ans.size();i++){
                                std::cout<<ans[i]<<std::endl;
                            }
                            if(ans.size()==0){
                                menu.error();
                                break;
                            }
                            std::cout<<"请选择你要删除的用户信息的编号:"<<std::endl;
                            int user_id;
                            std::cin>>user_id;
                            int flag=1;
                            for(int i=0;i<ans.size()&&flag;i++){
                                if(ans[i].getUserId()==user_id){
                                    flag=0;
                                }
                            }
                            if(flag){
                                menu.error();
                                break;
                            }
                            menu.cutRule();
                            std::cout<<"确定要删除该用户信息吗，确定请输入1,取消选择2"<<std::endl<<">";
                            std::cin>>flag;
                            if(flag==1){
                                userDB.remove(user_id);
                            }
                            break;
                        }else{
                            menu.error();
                        }
                        break;
                    }
                    case 5:{
                        int flag=1;
                        int typeNum_=0;
                        menu.displaySortUser();
                        while(flag&&std::cin>>typeNum_) {
                            switch (typeNum_) {
                                case 1: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getName() < user2.getName())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 2: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getSex() < user2.getSex())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 3: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getPhone() < user2.getPhone())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getPostalCode() < user2.getPostalCode())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 5: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getEmail() < user2.getEmail())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 6: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getQQNum() < user2.getQQNum())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 7: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getType() < user2.getType())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 0: {
                                    flag=0;
                                    break;
                                }
                                default: {
                                    menu.error();
                                    break;
                                }
                            }
                            if(flag)menu.displaySortUser();
                        }
                        break;
                    }
                    case 0: {
                        flagMain=false;
                        flagMain_ = false;
                        break;
                    }
                    default: {
                        menu.error();
                        break;
                    }
                }
                if(flagMain)menu.displayAdminMainMenu();
            }
        }else if(userType ==2){
            menu.displayUserMainMenu();
            while (flagMain_ && std::cin >> typeNum) {
                switch (typeNum) {
                    case 1: {
                        int flag=1;
                        int typeNum_=0;
                        menu.displayFetchMenu();
                        while(flag&&std::cin>>typeNum_){
                            switch (typeNum_) {
                                case 1: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要查询的姓名: ";
                                    User user;
                                    std::string name;
                                    std::cin>>name;
                                    user.setName(name);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        if(user1.getName()==user2.getName())return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"输入的名字不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 2: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要查询的电话: ";
                                    User user;
                                    std::string phone;
                                    std::cin>>phone;
                                    user.setPhone(phone);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        if(user1.getPhone()==user2.getPhone())return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"输入的电话不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 3: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要模糊查询的地址: ";
                                    User user;
                                    std::string address;
                                    std::cin>>address;
                                    user.setAddress(address);
                                    auto ans=userDB.queryWithMatch(user,[](User user1,User user2){
                                        int f=0,flag_=0;
                                        std::string address=user2.getAddress();
                                        std::string mh=user1.getAddress();
                                        for(int i=0;i<address.size()&!flag_;i++){
                                            if(address[i]==mh[f]){
                                                f++;
                                            }
                                            if(f==mh.size()-1)flag_=1;
                                        }
                                        if(flag_)return true;
                                        else return false;
                                    });
                                    if(ans.size()==0){
                                        std::cout<<"用户不存在"<<std::endl;
                                        break;
                                    }
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    auto ans=userDB.queryAll();
                                    for(int i=0;i<ans.size();i++){
                                        std::cout<<ans[i]<<std::endl;
                                    }
                                    break;
                                }
                                case 5: {
                                    menu.cutRule();
                                    std::cout<<"请输入需要查询的用户id: ";
                                    int userID;
                                    std::cin>>userID;
                                    auto ans=userDB.querySingleWithKey(userID);
                                    std::cout<<*ans<<std::endl;
                                    break;
                                }
                                case 0:{
                                    flag=0;
                                    break;
                                }
                                default: {
                                    std::cout << "输入错误" << std::endl;
                                    break;
                                }
                            }
                            if(flag)menu.displayFetchMenu();
                        }
                        break;
                    }
                    case 2:{
                        int flag=1;
                        int typeNum_=0;
                        menu.displaySortUser();
                        while(flag&&std::cin>>typeNum_) {
                            switch (typeNum_) {
                                case 1: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getName() < user2.getName())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 2: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getSex() < user2.getSex())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 3: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getPhone() < user2.getPhone())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getPostalCode() < user2.getPostalCode())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 5: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getEmail() < user2.getEmail())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 6: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getQQNum() < user2.getQQNum())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 7: {
                                    auto ans = userDB.queryWithSort([](User user1, User user2) {
                                        if (user1.getType() < user2.getType())return true;
                                        else return false;
                                    });
                                    for (int i = 0; i < ans.size(); i++) {
                                        std::cout << ans[i] << std::endl;
                                    }
                                    break;
                                }
                                case 0: {
                                    flag=0;
                                    break;
                                }
                                default: {
                                    menu.error();
                                    break;
                                }
                            }
                            if(flag)menu.displaySortUser();
                        }
                        break;
                    }
                    case 0: {
                        flagMain=false;
                        flagMain_ = false;
                        break;
                    }
                    default: {
                        menu.error();
                        break;
                    }
                }
                if(flagMain)menu.displayUserMainMenu();
            }
        }else if(userType ==0){
            flagMain= false;
        }else{
            menu.error();
        }
    }
    return 0;
}
