#include <iostream>
#include "mystring.h"

//书上的代码数组0位置为空，从索引为1开始使用

int main()
{

}


//简单的模式匹配算法
int index(SString &s, SString &t)
{
    int i = 1,j = 1;
    while(i <= s.length && j <= t.length)
    {
        if(s.ch[i] == t.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > t.length)    return i - t.length;
    else return 0;
}



//KMP算法-求next数组

//KMP算法-主程序
int index_kmp(SString& s,SString& t,int *next)
{

    int i = 1,j = 1;
    while(i <= s.length && j <= t.length)
    {
        if()
    }



}


