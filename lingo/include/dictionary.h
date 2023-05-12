/*
** EPITECH PROJECT, 2023
** lingo
** File description:
** lingo
*/

#ifndef DICTIONARY_H
    #define DICTIONARY_H

typedef struct dictionary_s {
    char **words;
    int word_count;
} dictionary_t;

void dictionary_load(dictionary_t *d, const char *path);
void dictionary_free(dictionary_t *d);
int get_word_count(char *buffer);
char** my_str_to_word_array(char *buffer);

#endif
