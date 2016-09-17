#include<iostream>
using namespace std;

char *src=" 478*79*098/21*76";//要处理的文字
int token=0;//标识符
int token_val=0;//值
enum{Num};

int next(){//分析出一个数字 或是一个其他的符号 如 + - * /等
    while(*src==' '){//去掉无用的空格
        src++;//src指针总是指向新的“块”
    }

    //能到这一步，说明不是空格，是个字符了

    token=*src;//如果token得到了数字，token会被赋予 Num ；反之是个符号如 ( ) + - * /
    src++;//src指针总是指向新的“块”

    if(token>='0' && token<='9'){//如果第一个是数字，分析完整的数字 如 987 得到了9
        token_val=(token)-'0';
        token=Num;
        while(*src>='0' && *src<='9'){
            token_val=token_val*10+ ( (*src)-'0');
            src++;
        }
    }
//    cout<<token_val<<endl;
    return 0;
}

int expr_tail(int val){
    int value=0;
    value=val;

    return value;
}

int factor(){//返回一个数字
    int val=0;
    val=token_val;
//    cout<<val<<endl;
    next();

    return val;
}

int term_tail(int val){
    int value=0;

    if(token=='*'){//如果下一个字符是 *
        next();
        value=val*factor();
        return term_tail(value);
    }
    else if(token=='/'){
        next();
        value=val/factor();
        return term_tail(value);
    }
    else{
        return val;
    }

}

int term(){
    int val=0;

    val=factor();
    val=term_tail(val);

    return val;
}

int expr(){
    int val=0;

    val=term();
    val=expr_tail(val);

    return val;
}

int main(){
    next();//分析出表达式的第一个块

    cout<<expr();
    return 0;
}
