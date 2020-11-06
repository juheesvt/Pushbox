//
// Created by jh_svt on 19. 5. 23.
// what the file manager does
//

#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__
#include<string>
#include<fstream>
#include<vector>
#include "define.h"

#define STRING std::string
#define FILE_READER std::ifstream
#define VECTOR std::vector


class FileManager {
public:
    FileManager(IN STRING fileName);         // file name 을 받아서 멤버변수 fileContent에 한 줄 단위로 삽입.
    ~FileManager();
    STRING getLine(IN int line);            // fileContent의 특정line 을 가져옴
    STRING getFileName();
    int getLineLength();
private:
    STRING fileName;
    int lineLength;
    VECTOR<STRING> fileContent;

};


#endif //SOKOBAN_FILEMANAGER_H
