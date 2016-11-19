#ifndef OS_AST_H
#define OS_AST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "OS_Token_Cmd.h"
#include "OS_Global.h"
using namespace std;

class Function_AST{
private:
    string funcName;
public:
    Function_AST(string name):
        funcName(name){}
    void codeAst();
};

class Array_AST{
protected:
    string arrayName;
    int arraySize;
    vector<int> arrayValues;
    string end;
public:
    Array_AST(string typeName, int size, vector<int> values):
        arrayName(typeName),arraySize(size),arrayValues(values),end("$"){}
     virtual void codeAst() = 0;
};

class IntArray_AST:public Array_AST{
public:
    IntArray_AST(string typeName, int size, vector<int> values):
    Array_AST(typeName,size,values){}
    void codeAst();
};

class StringArray_AST:public Array_AST{
public:
    StringArray_AST(string typeName, int size, vector<int> values):
    Array_AST(typeName,size,values){}
    void codeAst();
};

class Common_AST{
protected:
    string commonName;
public:
    Common_AST(string name):
        commonName(name){}
    virtual void codeAst() = 0;
};

class Int_Com_Ast:public Common_AST{
public:
    Int_Com_Ast(string name):
        Common_AST(name){}
    void codeAst();
};

class String_Ast:public Common_AST{
public:
    String_Ast(string name):
        Common_AST(name){}
    void codeAst();
};

class Number_AST{
protected:
    number_type numType;
    string numName;
public:
    Number_AST(number_type type,string name):
        numType(type),numName(name){}
    virtual void codeAst() = 0;
};

class Int_Ast:public Number_AST{
public:
    Int_Ast(number_type type, string name):
        Number_AST(type,name){}
    void codeASt();
};

class Float_AST:public Number_AST{
public:
    Float_AST(number_type type, string name):
        Number_AST(type,name){}
    void codeASt();
};

class Double_AST:public Number_AST{
public:
    Double_AST(number_type type, string name):
        Number_AST(type,name){}
    void codeASt();
};

class Init_AST{
protected:
    string initName;
public:
    Init_AST(string name):
        initName(name){}
    virtual void codeAst() = 0;
};

class Id_AST{
private:
    string idName;
public:
    Id_AST(string name):idName(name){}
    void codeAst();
};

class Compare_AST{
private:
    string comLabel;
    string comOperate;
    Id_AST *comLeftValues,*comRightValues;
    Compare_AST(string lable, Id_AST* leftValues, string operate,Id_AST *rightValues):
        comLabel(lable),comLeftValues(leftValues),comOperate(operate),comRightValues(rightValues){}
    void codeAst();
};




#endif // OS_AST_H
