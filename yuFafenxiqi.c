
#define _GNU_SOURCE
#include <stdio.h>
#include<stdlib.h>

enum {Num};
int token;
int token_val;
char *line = NULL;
char *src = " 32 * (4 + 2)";

int expr();

void next() {//token_val�õ�����
    // skip white space
    while (*src == ' ' || *src == '\t') {
        src ++;
    }//ȥ���ո� \t:��һ��

    token = *src++;//ָ��ÿ��ָ���µ�λ�� û��ʹ�õ��ַ�

    if (token >= '0' && token <= '9' ) {//����token��ʱ����token_val
        token_val = token - '0';
        token = Num;//token������������

        while (*src >= '0' && *src <= '9') {
            token_val = token_val*10 + *src - '0';
            src ++;
        }
        return;
    }
}

void match(int tk) {//�����Ƿ�װnext()
    if (token != tk) {
        printf("expected token: %d(%c), got: %d(%c)\n", tk, tk, token, token);
        exit(-1);
    }
    next();
}

int factor() {//�õ�����
    int value = 0;
    if (token == '(') {
        match('(');//����match token_val�õ��µ�����
        value = expr();
        match(')');
    } else {
        value = token_val;
        match(Num);
    }
    return value;
}

int term_tail(int lvalue) {//�˷�ϵ�еı��ʽ
    if (token == '*') {
        match('*');//Ϊ�˻�ȡ��һ�����ô��
        int value = lvalue * factor();//match()������ȡ����һ����� factor()����һ������
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
    int lvalue = factor();//�õ���һ����������
    return term_tail(lvalue);//����������Ӻ���ķ��� * | /
}

int expr_tail(int lvalue) {//�ӷ�ϵ��
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
    int lvalue = term();//ƥ���һ������ ���Ұѳ˷������
    return expr_tail(lvalue);
}

int main(int argc, char *argv[])
{
        next();//�õ���һ������
        printf("%d\n", expr());

    return 0;
}
