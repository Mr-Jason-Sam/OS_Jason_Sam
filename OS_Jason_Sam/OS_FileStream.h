#ifndef OS_FILESTREAM_H
#define OS_FILESTREAM_H

#include <string>
#include <iostream>
using namespace std;

class OS_FileStream
{
private:
    OS_FileStream(){}
    string mReadFile;
    string mWriteFile;
    static OS_FileStream *file;
public:
    static OS_FileStream *getInstance();
    void setReadFile (string readFile);
    void setWriteFile (string writeFile);
    string getWriteFile();
    string getReadFile();

};

#endif // OS_FILESTREAM_H
