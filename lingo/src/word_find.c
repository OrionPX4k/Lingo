/*
** EPITECH PROJECT, 2023
** word_find
** File description:
** lingo
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "word_find.h"

void init_word_find(word_find_t *w, char *word)
{
    w->line = NULL;
    w->word = strdup(word);
    w->output_word = strdup(word);
    w->found_table = strlen(word);
    w->round = 1;
}

char *hide_word(word_find_t *w)
{
    char *hide_word = NULL;

    hide_word = strdup(w->word);
    if (hide_word == NULL)
        return NULL;
    for (int i = 1; hide_word[i] != '\0'; i++)
        hide_word[i] = '*';
    return hide_word;
}

static bool find_character(word_find_t *w, char const c)
{
    for (int i = 0; w->word[i] != '\0'; i++) {
        if (c == w->word[i])
            return true;
    }
    return false;
}

void change_character(word_find_t *w, char *hide_word)
{
    for (int i = 0; w->word[i] != '\0'; i++) {
        if (find_character(w, w->line[i]) == true)
            hide_word[i] = '?';
        else
            hide_word[i] = '*';
        if (w->line[i] == w->word[i])
            hide_word[i] = w->word[i];
    }
}

void free_word_find(word_find_t *w)
{
    free(w->line);
    free(w->word);
    free(w->output_word);
}
