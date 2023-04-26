//
// Created by crk  23-4-25.
//

#ifndef ADDRESS_BOOK_SYSTEM_FILE_H
#define ADDRESS_BOOK_SYSTEM_FILE_H

#include <fstream>

class File {
public:
    File(const std::string, const std::string);
private:
    std::string path;
    std::string fileType;
};

#endif //ADDRESS_BOOK_SYSTEM_FILE_H
