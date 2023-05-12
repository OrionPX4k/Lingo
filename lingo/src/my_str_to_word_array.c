/*
** EPITECH PROJECT, 2023
** str_to_word_array
** File description:
** stumper
*/

#include <malloc.h>
#include <string.h>

int get_word_count(char *buffer)
{
    int count = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            count++;
        }
        i++;
    }
    if (buffer[i] != '\n')
        count++;
    return (count);
}

static int get_word_length(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        i++;
    }
    return (i);
}

char** my_str_to_word_array(char *buffer)
{
    int word_count = get_word_count(buffer);
    char **array = malloc(sizeof(char*) * (word_count + 1));
    int word_length = 0;

    for (int i = 0; i < word_count ; i++) {
        word_length = get_word_length(buffer);
        array[i] = malloc(word_length + 1);
        strncpy(array[i], buffer, word_length);
        array[i][word_length] = '\0';
        buffer += word_length + 1;
    }
    array[word_count] = NULL;
    return array;
}
