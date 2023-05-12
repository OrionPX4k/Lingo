/*
** EPITECH PROJECT, 2023
** linog
** File description:
** lingo
*/

#ifndef WORD_FIND_H_
    #define WORD_FIND_H_

typedef struct word_find_s {
    char *word;
    char *output_word;
    char *line;
    int found_table;
    int round;
} word_find_t;

void init_word_find(word_find_t *w, char *word);
char *hide_word(word_find_t *w);
void change_character(word_find_t *w, char *hide_word);
void free_word_find(word_find_t *w);

#endif /* !WORD_FIND_H_ */
