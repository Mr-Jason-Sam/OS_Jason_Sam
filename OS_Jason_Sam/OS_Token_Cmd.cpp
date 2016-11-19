#include "OS_Token_Cmd.h"
#include "OS_Global.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

OS_Token_Cmd::OS_Token_Cmd(string readFile):mReadFile(readFile){

}

bool OS_Token_Cmd::tokenInit(){
    ifstream fRead;
    fRead.open(string2char(mReadFile));
    if(!fRead){
        cout << "Source file " << mReadFile <<  " not find!" <<endl;
        fRead.close();
        return false;
    }
    fRead.close();
    return true;
}


char *OS_Token_Cmd::string2char(string str){
    return const_cast<char*>(str.c_str());
}


void OS_Token_Cmd::readLine(){
    int index,length;
    string line;
    ifstream code;
    code.open(mReadFile);
    if(!code){
        cout << cout << "Source file " << mReadFile <<  " not find!" <<endl;
        return;
    }

    while(getline(code,line)){
        length = int(line.length());
        index = 0;
        while(index < length){
            //number
            if(line[index] >= '0' && line[index] <= '9'){
                string token = "";
                while(line[index] >= '0' && line[index] <= '9'){
                    token += line[index];
                    index++;
                }
                codeStream.push_back(token);
            }
            //id
            else if ((line[index] >= 'a' && line[index] <= 'z') || (line[index] >= 'A' && line[index] <= 'Z')){
                string token = "";
                while((line[index] >= 'a' && line[index] <= 'z') || (line[index] >= 'A' && line[index] <= 'Z')|| (line[index] >= '0' && line[index] <= '9')){
                    token += line[index];
                    index++;
                }
                codeStream.push_back(token);
            }
            //symbol
            else if(line[index] == ';'||line[index]==','||line[index]=='"'||line[index]=='\\'){
                string token = "";
                token += line[index];
                index++;
                codeStream.push_back(token);
            }
            //oprate
            else if(line[index] == '+'||line[index]=='-'||line[index]=='*'||line[index]=='/'){
                string token = "";
                token += line[index];
                index++;
                codeStream.push_back(token);
            }
            //comparison operator
            else if(line[index] == '='||line[index]=='<'||line[index]=='>'){
                string token = "";
                token += line[index];
                index++;
                codeStream.push_back(token);
            }
            //brcket
            else if(line[index] == '['||line[index]==']'||line[index]=='{'||line[index]=='}'||line[index]=='('||line[index]==')'){
                string token = "";
                token += line[index];
                index++;
                codeStream.push_back(token);
            }
            //comments
            else if(line[index] == '#'){
                string token = "";
                token += line[index];
                index++;
                codeStream.push_back(token);
            }
            //null
            else if(line[index]=='\t'||line[index]=='\n'||line[index]==' '){
                index++;
            }
        }
        string end = "\n";
        codeStream.push_back(end);
    }
    code.close();
}










