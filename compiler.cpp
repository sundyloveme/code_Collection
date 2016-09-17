// this file is used for tutorial to build the compiler step by step
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<iostream>
using namespace std;

int token;                    // current token
int token_val;                // value of current token (mainly for number)
char *src, *old_src;          // pointer to source code string;
int poolsize;                 // default size of text/data/stack
int line;                     // line number
int *text,                    // text segment
    *old_text,                // for dump text segment
    *stack;                   // stack
char *data;                   // data segment
int *pc, *bp, *sp, ax, cycle; // virtual machine registers
int *current_id,              // current parsed ID
    *symbols;                 // symbol table
int *idmain;                  // the `main` function

enum {
  Num = 128, Fun, Sys, Glo, Loc, Id,
  Char, Else, Enum, If, Int, Return, Sizeof, While,
  Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt,
  Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak
};

//symbol表的字符 fields of identifier
enum {Token, Hash, Name, Type, Class, Value, BType, BClass, BValue, IdSize};

// types of variable/function
enum { CHAR, INT, PTR };

void next() { //词法分析
    char *last_pos;
    int hash;

    while (token = *src) {
        ++src;

            // parse identifier
         if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
                  (token == '_')) {

            last_pos = src - 1;
            hash = token;

            while ((*src >= 'a' && *src <= 'z') || (*src >= 'A' && *src <= 'Z') ||
                   (*src >= '0' && *src <= '9') || (*src == '_')) {
                hash = hash * 147 + *src;
                src++;
            }

            //遍历一遍整个symbol look for existing identifier, linear search
            current_id = symbols;
            while (current_id[Token]) {//这里有值便会执行
                if (current_id[Hash] == hash &&//哈希的目的是 对标识符进行比较
                    !memcmp( (char *)current_id[Name], last_pos, src - last_pos) ) {
                    //memcmp是比较内存区域buf1和buf2的前count个字节
                    //该函数是按字节比较的
                    //found one, return
                    token = current_id[Token];
                    return;
                }
                current_id = current_id + IdSize; //下一条信息
            }

            //遍历一遍都没找到 于是新建 store new ID
            current_id[Name] = (long long)last_pos;
            //测试
            cout<<"is:"<<(char*)current_id[Name]<<endl;

            current_id[Hash] = hash;
            token = current_id[Token] = Id;//返回给program()
            return;


        }
}
}
void expression(int level) {
    // do nothing
}

void program() {
    next(); // get next token
    while (token > 0) {
        //printf("token is: %3d('%c')\n", token, token);
        next();
    }
}


int eval() {
  return 0;
}

int main(int argc, char **argv)
{
    int i, fd;

    argc--;
    argv++;

    poolsize = 256 * 1024; // arbitrary size
    //line = 1;

    //给symbol表分配空间
    if (!(symbols = (int*)malloc(poolsize))) {
        printf("could not malloc(%d) for symbol table\n", poolsize);
        return -1;
    }
    //初始化symbol表
    memset(symbols, 0, poolsize);

    // read the source file
    if ((fd = open(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    if (!(src = old_src = (char*)malloc(poolsize))) {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }
    // read the source file
    if ((i = read(fd, src, poolsize-1)) <= 0) {
        printf("read() returned %d\n", i);
        return -1;
    }
    src[i] = 0; // add EOF character
    close(fd);

    program();

//    for(int i=0;i<=9;i++){
//        printf("%d ",symbols[i]);
//    }
//
//    printf("\n");
//    printf("%s\n",(char*)symbols[2]);
//
//    for(int i=0;i<=9;i++){
//        printf("%d ",symbols[i]);
//    }
//
//    printf("\n");
//    printf("%s\n",(char*)symbols[2]);

    return eval();

}

