/*
** EPITECH PROJECT, 2023
** prompt
** File description:
** prompt
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "word_find.h"
#include "my.h"

static void start_prompt(word_find_t *w, char const *hide_word)
{
    printf("*: invalid letter\n");
    printf("?: incorrectly placed letter\n");
    printf("Will you find the secret word ?\n");
    printf("%s\n", hide_word);
    printf("\nRound %d\n>", w->round);
}

static bool size_word(word_find_t *w)
{
    if ((int)strlen(w->line) - 1 < w->found_table) {
        printf("Word too short. Retry\n>");
        return true;
    }
    if ((int)strlen(w->line) - 1 > w->found_table) {
        printf("Word too long. Retry\n>");
        return true;
    }
    return false;
}

static int win_condition(word_find_t *w, char *hide_word)
{
    for (int i = 0; w->word[i] != '\0'; i++) {
        if (hide_word[i] != w->word[i])
            return ERROR;
    }
    printf("You won!\n");
    return SUCCESS;
}

static int lost_condition(word_find_t *w)
{
    if (w->round == w->found_table) {
        printf("You lost!\n");
        return SUCCESS;
    }
    return ERROR;
}

void prompt(word_find_t *w)
{
    size_t len = 0;
    char *hide_w = hide_word(w);

    start_prompt(w, hide_w);
    while ((getline(&w->line, &len, stdin)) != -1) {
        if (size_word(w) == 1)
            continue;
        w->round++;
        change_character(w, hide_w);
        printf("%s\n", hide_w);
        if (win_condition(w, hide_w) == SUCCESS) {
            free(hide_w);
            break;
        }
        if (lost_condition(w) == SUCCESS) {
            free(hide_w);
            break;
        }
        printf("\nRound %d\n>", w->round);
    }
}
