//
// Created by root on 16-9-16.
//

#ifndef WORD_MANAGE_WORD_H
#define WORD_MANAGE_WORD_H

typedef struct Word_tag{
    char *strname;
    int count;
    struct Word_tag *next;
} Word;

extern Word *wordheader;

void init_word();
void add_word(char *name);
void dump_word(FILE *fp);
void free_all();

#endif //WORD_MANAGE_WORD_H
