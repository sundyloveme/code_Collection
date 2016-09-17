
#define _GNU_SOURCE
#include <stdio.h>
#include<stdlib.h>

enum {Num};
int token;
int token_val;
char *line = NULL;
char *src = " 32 * (4 + 2)";

int expr();

void next() {//token_val得到数字
    // skip white space
    while (*src == ' ' || *src == '\t') {
        src ++;
    }//去掉空格 \t:下一列

    token = *src++;//指针每次指向新的位置 没有使用的字符

    if (token >= '0' && token <= '9' ) {//这里token临时代替token_val
        token_val = token - '0';
        token = Num;//token代表数据类型

        while (*src >= '0' && *src <= '9') {
            token_val = token_val*10 + *src - '0';
            src ++;
        }
        return;
    }
}

void match(int tk) {//仅仅是封装next()
    if (token != tk) {
        printf("expected token: %d(%c), got: %d(%c)\n", tk, tk, token, token);
        exit(-1);
    }
    next();
}

int factor() {//得到数字
    int value = 0;
    if (token == '(') {
        match('(');//经过match token_val得到新的数字
        value = expr();
        match(')');
    } else {
        value = token_val;
        match(Num);
    }
    return value;
}

int term_tail(int lvalue) {//乘法系列的表达式
    if (token == '*') {
        match('*');//为了获取下一个标记么？
        int value = lvalue * factor();//match()函数获取了下一个标记 factor()返回一个数字
        return term_tail(value);
    } else if (token == '/') {
        match('/');
        int value = lvalue / factor();
        return term_tail(value);
    } else {
        return lvalue;
    }
}

int term() {
    int lvalue = factor();//得到第一个数字因子
    return term_tail(lvalue);//这个数字因子后面的符号 * | /
}

int expr_tail(int lvalue) {//加法系列
    if (token == '+') {
        match('+');
        int value = lvalue + term();
        return expr_tail(value);
    } else if (token == '-') {
        match('-');
        int value = lvalue - term();
        return expr_tail(value);
    } else {
        return lvalue;
    }
}

int expr() {
    int lvalue = term();//匹配第一个因子 并且把乘法运算掉
    return expr_tail(lvalue);
}

int main(int argc, char *argv[])
{
        next();//得到第一个数字
        printf("%d\n", expr());

    return 0;
}
