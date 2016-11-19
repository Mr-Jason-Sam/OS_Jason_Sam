#include "OS_AST.h"
#include "OS_File.h"

OS_File *file = OS_File::GetInstance();
string writeFile = file->getWriteFile();

void Function_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(writeFile));
    fout << funcName << ":" << endl;
    fout.close();
}

void IntArray_AST::codeAst(){
    ofstream fout;
    fout.open(string2char(writeFile));
    cout << writeFile << "nothing";
    fout << "SYINTLIST " << arrayName << " ";
    for (int values_index = 0; values_index < arrayValues.size(); values_index++){
        fout << arrayValues[values_index] << " ";
    }
    fout << end <<endl;
    fout.close();
}


