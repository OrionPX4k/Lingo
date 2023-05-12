/*
** EPITECH PROJECT, 2023
** lingo
** File description:
** lingo
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "dictionary.h"
#include "word_find.h"

static int helper(void)
{
    puts("USAGE:\n\t./lingo [texte file]");
    puts("DESCRIPTION:\n\tLingo is a game where a player");
    puts("\thave multiple tries to guess a word");
    return SUCCESS;
}

int lingo(int argc, char *argv[])
{
    dictionary_t dictionary;
    word_find_t find;

    if (argc != 2) {
        puts("USAGE:\t./lingo [texte file]");
        return ERROR;
    }
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return helper();
    dictionary_load(&dictionary, argv[1]);
    init_word_find(&find, dictionary.words[rand() % dictionary.word_count]);
    prompt(&find);
    free_word_find(&find);
    dictionary_free(&dictionary);
    return SUCCESS;
}
