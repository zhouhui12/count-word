//
// Created by root on 16-9-16.
//

#include <ctype.h>
#include "getword.h"

int get_word(char *buf,int size,FILE *stream)
{
    int ch;
    int len = 0;
    while((ch = getc(stream)) != EOF && ch !=' '&& ch != '\n'){
        buf[len] = ch;
        len++;
        if(len >= size){
            fprintf(stderr,"the word too long");
            break;
        }
    }
    if(len != 0)
    {
        buf[len] = '\0';
        return 1;
    }else if(len == 0 && ch == ' '){     //跳过连续的空格
        return 2;
    }
    return 0;                       //到达文件末尾
}