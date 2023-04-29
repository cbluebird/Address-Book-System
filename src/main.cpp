//
// Created by crk on 23-4-25.
//

#include"src/include/executor/Table.h"
#include"src/executor/Table.cpp"
#include "src/data/User.h"

int main(){
    Table<User,int> table=Table<User,int>("../data/data", ".txt",[](User user){return user.user_id;});
    auto ans=table.queryAll();
    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i].user_id<<ans[i].name<<ans[i].email<<ans[i].address<<std::endl;
    }
    User user("李四","23456789012");
    auto a=table.querySingleWithoutKey(user,[](User user1,User user2){return user1.name==user2.name;});
    std::cout<<a->to_string();
    return 0;
}

