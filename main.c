#include <stdio.h>
#include <string.h>
#include "getword.h"
#include "manage_word.h"

#define BUFF_SIZE 128            //定义缓冲区的大小
#define  OUT_FILE_NAME "result"  //统计的单词数据输出文件名
int main(int argc,char *argv[])
{
    char buffer[BUFF_SIZE];
    int i=0;
    int word_size = 0;

    FILE *fp;
    FILE *fpresult;
    if (argc == 1)
    {
        fprintf(stderr,"请在后面加上需要统计的文件名");
        exit(1);
    }
    init_word();
    for(i=1;i<=(argc-1);i++)
    {
        fp = fopen(argv[i],"r");
        if(fp == NULL){
            fprintf(stderr,"%s can't open %s.\n",argv[0],argv[i]);
            exit(1);
        }
        while(word_size = get_word(buffer, sizeof(buffer),fp)){
            if(word_size == 1){     //1代表为一个完整的单词
                add_word(buffer);
                //printf("单词内容为：%s\n",buffer);
                //printf("单词长度为：%d\n",word_size);
            }
        }
        fclose(fp);
    }
    fpresult = fopen(OUT_FILE_NAME,"w");
    dump_word(fpresult);      //输出统计结果到文件
    free_all();               //释放内存
    return 0;
}
