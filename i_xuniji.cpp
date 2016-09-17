#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define POOLSIZE 1024*256   //内存尺寸
using namespace std;

int *text,
    *old_text,
    *stack;

int *sp,*bp,*pc,ax;


int eval() {

}

int main() {
    //分配内存
    if( ( text=old_text=(int*)malloc(POOLSIZE) )==0 ) {
        cout<<"分配内存给text时，不足";
    }

    if( ( stack=(int*)malloc(POOLSIZE)  )       ==0 )  {
        cout<<"分配内存给stack时，不足";
    }

    //初始化数据
    memset(text,0,POOLSIZE);
    memset(stack,0,POOLSIZE);

    sp=bp=(int*)((long long)stack+POOLSIZE);
    ax=0;

    return 0;
}
