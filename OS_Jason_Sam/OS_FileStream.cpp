#include "OS_FileStream.h"

OS_FileStream *OS_FileStream::file = NULL;

OS_FileStream *OS_FileStream::getInstance(){
    if( file = NULL){
        file = new OS_FileStream();
    }
    return file;
}

void OS_FileStream::setReadFile(string readFile){
    mReadFile = readFile;
}

void OS_FileStream::setWriteFile(string writeFile){
    mWriteFile = writeFile;
}

string OS_FileStream::getReadFile(){
    return mReadFile;
}

string OS_FileStream::getWriteFile(){
    return mWriteFile;
}
