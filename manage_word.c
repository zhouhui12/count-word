//
// Created by root on 16-9-16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manage_word.h"

Word *wordheader = NULL;    //链表的头指针
void init_word()            //初始化链表的头
{
    wordheader = NULL;
}
static char *my_strup(char *src)   //将单词从缓冲区保存在内存里面
{
    char *dest;
    dest = malloc(sizeof(char)*(strlen(src)+1));
    strcpy(dest,src);
    return dest;
}
static Word *creat_word(char *name)   //为新的的单词创建一个链表的节点
{
    Word *newword;
    newword = malloc(sizeof(Word));
    newword->strname = my_strup(name);
    newword->count = 1;
    newword->next = NULL;
    return newword;
}
void add_word(char *name)
{
    Word *pos = NULL;
    Word *prev = NULL;
    Word *new_word =NULL;
    int result = 0;
    for (pos = wordheader;pos != NULL;pos = pos->next){
        result = strcmp(pos->strname,name);
        if(result == 0){
            break;
        }
        prev = pos;
    }
    if(wordheader != NULL && result ==0){    //单词已经存在，计数值加1
        pos->count++;
    } else{
        new_word = creat_word(name);
        if(prev == NULL){               //为空的链表头指针赋值
            new_word->next = wordheader;
            wordheader = new_word;
        } else{                         //在链表中加入新的单词
            new_word->next = pos;
            prev->next = new_word;
        }
    }
}
void dump_word(FILE *fp)                  //打印统计结果在文件中
{
    Word *pos = NULL;
    for(pos = wordheader;pos != NULL;pos = pos->next){
        printf("%s:%d\n",pos->strname,pos->count);
        fprintf(fp,"%-20s%5d\n",pos->strname,pos->count);
    }
}
void free_all()                                   //释放内存
{
    Word *temp;
    Word *pos;
    for(pos = wordheader;pos != NULL;){
        temp = pos;
        pos = pos->next;
        free(temp->strname);
        free(temp);
    }
    printf("释放完全\n");
}