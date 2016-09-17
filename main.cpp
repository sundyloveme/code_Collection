#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<iostream>
using namespace std;
int ax=(256);
int num;//temp
char *src = "2*6";
int next(){
    int val = 0;
    if(*src != '*' && *src !=  '/' &&
       *src != '+' && *src != '-'){
        val = *src - '0';
        src++;
        return val;
    }
    val = *src;
    src++;
    return val;
}

int term();
int expr_tail();

int expr(){
    int value;
    value=term();
    expr_tail();

    return value;
}

int expr_tail(){
    //
    //
    //
}

int factor();

int term_tail(int value);

int term(){
 int value=0;
 value=factor();



 value=term_tail(value);
}

int factor(){
    int val = next();
    return val;
}

int term_tail(int value){
    int val;
    if(*src=='*'){
        next();
        val=value*factor();
        term_tail(val);
    }
    if(*src=='/'){
        //
    }
    else
        return val;
}




int main() {
cout<<expr();
    return 0;
}
