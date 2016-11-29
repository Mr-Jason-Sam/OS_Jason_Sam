#include "OS_AST.h"
#include "OS_File.h"

OS_File *file = OS_File::GetInstance();
string InitArray_AST::mArrayKind = OPINITLIST;
string InitArray_AST::mEnd   = END;
string InitCommon_AST::comKind = OPINIT;
string InitInt_AST::intKind  = AL ;
string InitString_AST::stringKind = DL;

string InitArray_AST::getKind(){
    return mArrayKind;
}

string InitArray_AST::getEnd(){
    return mEnd;
}

string InitCommon_AST::getKind(){
    return comKind;
}

string InitInt_AST::getDataKind(){
    return intKind;
}

string InitString_AST::getDataKind(){
    return stringKind;
}

void InitArrayInt_AST::setName(string name){
    mName = name;
}

string InitArrayInt_AST::getName(){
    return mName;
}

void InitArrayString_AST::setName(string name){
    mName = name;
}

string InitArrayString_AST::getName(){
    return mName;
}



void InitArray_AST::codeAst(){

}

void InitCommon_AST::codeAst(){

}

void Function_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(file->getWriteFile()), ios::app);
    fout << funcName << ":" << endl;
    fout.close();
}

void InitInt_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(file->getWriteFile()), ios::app);
    fout << mKind << "\t" << "\t"<<"\t"<<  intKind<< "\t";
    fout << mValue << endl;
    fout << mKind << "\t"<<"\t"<<  mName << "\t"<< intKind << "\t"<< endl;
    fout.close();
}

void InitString_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(file->getWriteFile()), ios::app);
    fout << mKind << "\t" << "\t"<< "\t"<< stringKind<< "\t";
    fout << mValue << endl;
    fout << mKind << "\t"<<"\t"<<  mName << "\t"<< stringKind << "\t"<< endl;
    fout.close();
}


void InitArrayInt_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(file->getWriteFile()), ios::app);
    fout << mKind << "\t" << "\t"<< mDataKind<< "\t";
    for (int values_index = 0; values_index < mNumberValues.size(); values_index++){
        fout << mNumberValues[values_index] << " ";
    }
    fout << mEnd <<endl;
    fout << mKind << "\t"<< mName << "\t"<< mDataKind << "\t"<< endl;
    fout.close();
}


void InitArrayString_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(file->getWriteFile()), ios::app);
    fout << mKind << "\t" << "\t"<< mDataKind<< "\t";
    for (int values_index = 0; values_index < mStringValues.size(); values_index++){
        fout << mStringValues[values_index] << " ";
    }
    fout << mEnd <<endl;
    fout << mKind << "\t"<< mName << "\t"<< mDataKind << "\t"<< endl;
    fout.close();
}






