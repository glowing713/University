#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
/*
 Expr -> Term Expr'
 Expr'-> + Term Expr' | - Term Expr' | null
 Term -> Factor Term'
 Term'-> * Factor Term' | / Factor Term' | null
 Factor-> number | id | (Expr)
 */
int cnt = 0;
string expr;

bool Expr();
bool EPrime();
bool Term();
bool TPrime();
bool Factor();

int main(void) {
    getline(cin,expr);
    expr += "\n";
    long leng = expr.length();
    
    for(;cnt<leng && !isblank(expr[cnt]);cnt++){
        if(Expr() && expr[cnt] == '\n'){
            cout << "Good" << endl;
            exit(0);
        }else{
            cout << "Error" << endl;
            exit(0);
        }
    }
    
    return 0;
}

bool Expr(){
    if(Term() == false){
        return false;
    }else
        return EPrime();
}

bool EPrime(){
    if(expr[cnt] == '+' || expr[cnt] == '-'){
        do{
            cnt++;
        }while(isblank(expr[cnt]));
        if(Term() == false){
            return false;
        }else
            return EPrime();
    }else
        return true;
}

bool Term(){
    if(Factor() == false){
        return false;
    }else
        return TPrime();
}

bool TPrime(){
    if(expr[cnt] == '*' || expr[cnt] == '/'){
        do{
            cnt++;
        }while(isblank(expr[cnt]));
        if(Factor() == false){
            return false;
        }else
            return TPrime();
    }else
        return true;
}

bool Factor(){
    if(expr[cnt] == '('){
        do{
            cnt++;
        }while(isblank(expr[cnt]));
        if(Expr() == false){
            return false;
        }else if(expr[cnt] != ')'){
            return false;
        }
    }else if(!isdigit(expr[cnt]) && !isalpha(expr[cnt])){
        return false;
    }
    do{
        cnt++;
    }while(isblank(expr[cnt]));
    return true;
}
