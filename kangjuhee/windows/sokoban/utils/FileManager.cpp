//
// Created by jh_svt on 19. 5. 23.
//

#include "FileManager.h"

FileManager::FileManager(const STRING fileName):fileName(fileName) {
    FILE_READER fileReader = FILE_READER(fileName);

    STRING aLineStr;
    this->lineLength = 0;

    while (getline(fileReader, aLineStr)){
        if (!aLineStr.empty()){
            // 한 줄씩 읽어서 vector에 append
            this->fileContent.push_back(aLineStr);
            this->lineLength++;
        }

        else
            break;
    }
}

FileManager::~FileManager() {}

STRING FileManager::getLine(const int line) {
    return this->fileContent[line];
}
STRING FileManager::getFileName() {
    return this->fileName;
}
int FileManager::getLineLength() {
    return this->lineLength;
}


