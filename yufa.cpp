#include<iostream>
using namespace std;

char *src=" 478*79*098/21*76";//Ҫ���������
int token=0;//��ʶ��
int token_val=0;//ֵ
enum{Num};

int next(){//������һ������ ����һ�������ķ��� �� + - * /��
    while(*src==' '){//ȥ�����õĿո�
        src++;//srcָ������ָ���µġ��顱
    }

    //�ܵ���һ����˵�����ǿո��Ǹ��ַ���

    token=*src;//���token�õ������֣�token�ᱻ���� Num ����֮�Ǹ������� ( ) + - * /
    src++;//srcָ������ָ���µġ��顱

    if(token>='0' && token<='9'){//�����һ�������֣��������������� �� 987 �õ���9
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

int factor(){//����һ������
    int val=0;
    val=token_val;
//    cout<<val<<endl;
    next();

    return val;
}

int term_tail(int val){
    int value=0;

    if(token=='*'){//�����һ���ַ��� *
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
    next();//���������ʽ�ĵ�һ����

    cout<<expr();
    return 0;
}
