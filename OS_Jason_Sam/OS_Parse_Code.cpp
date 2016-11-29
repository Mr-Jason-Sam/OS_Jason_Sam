#include "OS_Parse_Code.h"

OS_Parse_Code::OS_Parse_Code():index(0){
}

void OS_Parse_Code::indexAdd(){
    index++;
}

void OS_Parse_Code::buildAst(){
    for(index = 0; index < codeStream.size();index++){
        string token = codeStream[index];

        if(token == "function"){
            parseFunc();
        }
        //statement or define variable
        else if (token == "var"){
            parseDefvar();
        }
        else if(isVariable(token)){
            string variableName = codeStream[index];
            indexAdd();
            if(codeStream[index] == "="){
                parseBinary(variableName);

            }
        }
        else if(isSystemFunc(token)){
            parseSystemFunc();
        }
        else if(token == "\n"){
            continue;
        }
    }
}

void OS_Parse_Code::parseFunc(){
    indexAdd();
    string funcName = codeStream[index];
    checkName(funcName);
    Function_AST *func = new Function_AST(funcName);
    func->codeAst();

    indexAdd();
    checkToken("(");
    indexAdd();
    while(codeStream[index] != ")"){
        indexAdd();
    }
    indexAdd();

    while(codeStream[index] != "{")
        indexAdd();
    if(codeStream[index] == "{"){
        parseBlock();
    }

}

void OS_Parse_Code::parseDefvar(){
    indexAdd();

}

bool OS_Parse_Code::isVariable(string token){

}

void OS_Parse_Code::parseBinary(string variableName){

    indexAdd();
}

bool OS_Parse_Code::isSystemFunc(string token){
    indexAdd();
    return true;
}

void OS_Parse_Code::parseSystemFunc(){

}

void OS_Parse_Code::parseBlock(){
    //indexAdd();
    while(codeStream[index] !="}"){
        indexAdd();
        if (isKeyDefine(codeStream[index])){
            parseKeyDefine();
        }
        else if (isKeyExpress(codeStream[index])){
            parseKeyExpress();
        }
        else if (isKeySystemFunc(codeStream[index])){
            parseKeySystemFunc();
        }
        else if(codeStream[index] == "\n")
            continue;
    }
   //indexAdd();
}

void OS_Parse_Code::parseKeyDefine(){
    if (codeStream[index] == "function"){
        indexAdd();
        parseFunc();
    }
    else if (codeStream[index] == "var"){
        indexAdd();
        parseKeyType();
    }
}

void OS_Parse_Code::parseKeyType(){
    string type = codeStream[index];
    indexAdd();
    string name = codeStream[index];
    checkName(name);
    indexAdd();
    if (type == "int"){
        if(codeStream[index] == "["){
            indexAdd();
            int size;
            if(checkNum(codeStream[index]))
                size = string2int(codeStream[index]);
            indexAdd();
            checkToken("]");
            indexAdd();
            if(codeStream[index] == "="){
                indexAdd();
                checkToken("{");
                vector<int> numberValues;
                indexAdd();
                while(codeStream[index] != "}"){
                    if (checkNum(codeStream[index])){
                        numberValues.push_back(string2int(codeStream[index]));
                    }
                    indexAdd();
                }
                indexAdd();
                symbolInsert(name,int_array);
                InitArrayInt_AST *intArray_ast = NULL;
                intArray_ast = new InitArrayInt_AST(name,size,numberValues);
                intArray_ast->codeAst();
            }else{

            }
        }else{
            int value;
            index--;
            Init_AST *int_ast = NULL;
            bool continuous = true;
            while(continuous){
                if(codeStream[index] == "="){
                    indexAdd();
                    if(checkNum(codeStream[index])){
                        value = string2int(codeStream[index]);
                    }
                    if(codeStream[index+1] != ",")
                        continuous = false;
                }
                else if (codeStream[index] == ","){
                    indexAdd();
                    continue;
                }
                else{
                    name = codeStream[index];
                    value = 0;
                    if(codeStream[index+1] != ",")
                        continuous = false;
                }
                int_ast = new InitInt_AST(name,value);
                int_ast->codeAst();
                indexAdd();
            }
        }
    }
    else if (type == "string"){
        if(codeStream[index] == "["){
            indexAdd();
            int size;
            if(checkNum(codeStream[index]))
                size = string2int(codeStream[index]);
            indexAdd();
            checkToken("]");
            indexAdd();
            if(codeStream[index] == "="){
                indexAdd();
                checkToken("{");
                indexAdd();
                vector<string> stringValues;
                while(codeStream[index] != "}"){
                    checkToken("\"");
                    indexAdd();
                    string values;
                    while(codeStream[index] != "\""){
                        values = codeStream[index];
                        stringValues.push_back(values);
                        indexAdd();
                    }
                    indexAdd();
                    if(codeStream[index] == "}")
                        break;
                    checkToken(",");
                    indexAdd();
                }
                indexAdd();
                InitArrayString_AST *stringArray = NULL;
                //symbolInsert(name,string_array);
                stringArray = new InitArrayString_AST(name, size, stringValues);
                stringArray->codeAst();
            }else{

             }
        }else{
            string value;
            index--;
            Init_AST *array_ast = NULL;
            bool continuous = true;
            while(continuous){
                if(codeStream[index] == "="){
                    indexAdd();
                    if(codeStream[index] == "\""){
                        indexAdd();
                        if(checkName(codeStream[index])){
                            value = string2char(codeStream[index]);
                            checkToken("\"");
                        }
                    }
                    if(codeStream[index+1] != ",")
                        continuous = false;
                }
                else if (codeStream[index] == ","){
                    indexAdd();
                    continue;
                }
                else{
                    name = codeStream[index];
                    value = "NULL";
                    if(codeStream[index+1] != ",")
                        continuous = false;
                }
                array_ast = new InitString_AST(name,value);
                array_ast->codeAst();
                indexAdd();
            }
        }
    }
}

void OS_Parse_Code::parseKeyExpress(){
    if (codeStream[index] == "while"){

    }
    else if (codeStream[index] == "for"){

    }
    else if (codeStream[index] == "if"){

    }
    else if (codeStream[index] == "else"){

    }
}

void OS_Parse_Code::parseKeySystemFunc(){
    if (codeStream[index] == "print"){

    }
}


bool OS_Parse_Code::checkToken(string token){
    if(codeStream[index] != token){
        error("Expected token " + token);
        return false;
    }
    else
        return true;
}

bool OS_Parse_Code::checkName(string token){
    for(int key_index = 0; key_index < KEYWORDNUM; key_index++){
        if(keyword[key_index] == token){
            error(token +"is a keyword" );
            return false;
        }
        if(isdigit(token[0])){
            error(token +"\'s first is Number" );
            return false;
        }
    }
    return true;
}

bool OS_Parse_Code::checkNum(string token){
    for(int num_index = 0; num_index < token.size(); num_index++){
        char character = token[num_index];
        if(!isdigit(character))
            return false;
    }
    return true;
}


bool OS_Parse_Code::isKeyDefine(string token){
    if(token == "function" || token == "var"){
        return true;
    }
    return false;
}

bool OS_Parse_Code::isKeyType(string token){
    if(token == "int" || token == "string"){
        return true;
    }
    return false;
}

bool OS_Parse_Code::isKeyExpress(string token){
    if(token == "while" || token == "if" || token == "else" || token == "for"){
        return true;
    }
    return false;
}

bool OS_Parse_Code::isKeySystemFunc(string token){
    if(token == "print"){
        return true;
    }
    return false;
}




