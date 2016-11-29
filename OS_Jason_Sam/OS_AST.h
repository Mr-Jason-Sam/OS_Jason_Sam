#ifndef OS_AST_H
#define OS_AST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "OS_Token_Cmd.h"
#include "OS_Global.h"

#define OPINITLIST "OPINITLIST"
#define OPINIT        "OPINIT"
#define AL              "AL"
#define DL              "DL"
#define END           "$"

using namespace std;

class Function_AST{
private:
    string funcName;
public:
    Function_AST(string name):
        funcName(name){}
    void codeAst();
};

/*InitArray start
   1.int
   2.string
*/
class Init_AST{
public:
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual void codeAst() = 0;
};

class InitArray_AST:public Init_AST{
private:
    static string mArrayKind;
    static string mEnd;
    string mName;
public:
    int getArraySize();
    void setArraySize(int size);
    static string getKind();
    static string getEnd();
    string getName(){
        return mName;
    }
    void setName(string name){
        mName = name;
    }
    virtual void codeAst();
};

class InitCommon_AST:public Init_AST{
private:
    static string comKind;
    string mName;
public:
    static string getKind();
    string getName(){
        return mName;
    }
    void setName(string name){
        mName = name;
    }
    virtual void codeAst();
};

class InitInt_AST:public Init_AST{
private:
    static string intKind;
    string mKind;
    string mName;
    int mValue;
public:
    InitInt_AST(string name, int value):
        mName(name), mValue(value){
        mKind = InitCommon_AST::getKind();
    }
    InitInt_AST(){}
    static string getDataKind();
    string getName(){
        return mName;
    }
    void setName(string name){
        mName = name;
    }
    virtual void codeAst();
};

class InitString_AST:public Init_AST{
private:
    static string stringKind;
    string mKind;
    string mName;
    string mValue;
public:
    InitString_AST(string name, string value):
        mName(name), mValue(value){
        mKind = InitCommon_AST::getKind();
    }
    InitString_AST(){}
    static string getDataKind();
    string getName(){
        return mName;
    }
    void setName(string name){
        mName = name;
    }
    virtual void codeAst();
};

class InitArrayInt_AST:public InitArray_AST,InitInt_AST{
private:
    vector<int> mNumberValues;
    string mName;
    int mSize;
    string mKind;
    string mDataKind;
    string mEnd;
public:
    InitArrayInt_AST(string name,int size,vector<int> values):
          mSize(size),mNumberValues(values){
        setName(name);
        mKind = InitArray_AST::getKind();
        mDataKind = InitInt_AST::getDataKind();
        mEnd =InitArray_AST::getEnd();
    }
    void setName(string name);
    string getName();
    void codeAst();
};

class InitArrayString_AST:public InitArray_AST,InitString_AST{
protected:
    vector<string> mStringValues;
    string mName;
    int mSize;
    string mKind;
    string mDataKind;
    string mEnd;
public:
    InitArrayString_AST(string name,int size, vector<string> values):
         mSize(size), mStringValues(values){
        setName(name);
        mKind = InitArray_AST::getKind();
        mDataKind = InitString_AST::getDataKind();
        mEnd =InitArray_AST::getEnd();
    }
    void setName(string name);
    string getName();
    void codeAst();
};




#endif // OS_AST_H
