#ifndef OS_TOKEN_CMD_H
#define OS_TOKEN_CMD_H
#include <iostream>
#include <string>
#include <fstream>
#include "OS_Global.h"
using namespace std;

class OS_Token_Cmd
{
private:
    string mReadFile;
public:
    OS_Token_Cmd(string readFile);
    char *string2char(string str);
    bool tokenInit();
    void readLine();
};


#endif // OS_TOKEN_CMD_H
