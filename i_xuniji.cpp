#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define POOLSIZE 1024*256   //�ڴ�ߴ�
using namespace std;

int *text,
    *old_text,
    *stack;

int *sp,*bp,*pc,ax;


int eval() {

}

int main() {
    //�����ڴ�
    if( ( text=old_text=(int*)malloc(POOLSIZE) )==0 ) {
        cout<<"�����ڴ��textʱ������";
    }

    if( ( stack=(int*)malloc(POOLSIZE)  )       ==0 )  {
        cout<<"�����ڴ��stackʱ������";
    }

    //��ʼ������
    memset(text,0,POOLSIZE);
    memset(stack,0,POOLSIZE);

    sp=bp=(int*)((long long)stack+POOLSIZE);
    ax=0;

    return 0;
}
