//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_FILE_H
#define ADDRESS_BOOK_SYSTEM_FILE_H


#include <fstream>
#include<string>
#include<vector>
#include<unordered_map>

template<typename ValueType,typename KeyType>
class File {
    std::string path;
    std::string fileType;
public:
    File(const std::string& path, const std::string& fileType) : path(path), fileType(fileType){};
    std::unordered_map<KeyType,ValueType> init(KeyType(*getMajor)(ValueType));
    void update(std::vector<ValueType>&);
    void insert(ValueType);

};

#endif //ADDRESS_BOOK_SYSTEM_FILE_H
