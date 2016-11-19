#ifndef OS_PARSE_CODE_H
#define OS_PARSE_CODE_H
#include <iostream>
#include <string>
#include "OS_AST.h"
#include "OS_Global.h"

using namespace std;

class OS_Parse_Code
{
private:
     int index;
public:
    OS_Parse_Code();
    void indexAdd();
    void buildAst();

    //parse main func
    void parseDefvar();
    void parseFunc();
    void parseBinary(string);
    void parseSystemFunc();
    void parseBlock();

    //key parse
    void parseKeyDefine();
    void parseKeyType();
    void parseKeyExpress();
    void parseKeySystemFunc();

    //parse tool func
    bool isVariable(string);
    bool isSystemFunc(string);
    bool checkToken(string);
    bool checkName(string);
    bool checkNum(string);

    //keyword choice
    bool isKeyDefine(string);
    bool isKeyType(string);
    bool isKeyExpress(string);
    bool isKeySystemFunc(string);



};

#endif // OS_PRASE_CODE_H
