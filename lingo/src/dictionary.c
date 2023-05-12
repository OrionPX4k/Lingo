/*
** EPITECH PROJECT, 2023
** dictionary_load
** File description:
** lingo
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "dictionary.h"
#include "my.h"

static void is_read_failed(int fd, char *buffer, struct stat s)
{
    if (read(fd, buffer, s.st_size) == -1) {
        free(buffer);
        close(fd);
        exit(ERROR);
    }
}

static void is_malloc_failed(int fd, char *buffer)
{
    if (buffer == NULL) {
        close(fd);
        exit(ERROR);
    }
}

static void is_good_size(int fd, int const size)
{
    if (size == 0) {
        close(fd);
        exit(ERROR);
    }
}

void dictionary_load(dictionary_t *d, char const *path)
{
    char *buffer = NULL;
    int fd = open(path, O_RDONLY);
    struct stat s;
    int size = 0;

    srand(time(NULL));
    if (fd == -1)
        exit(ERROR);
    stat(path, &s);
    size = s.st_size;
    is_good_size(fd, size);
    buffer = malloc(s.st_size + 1);
    is_malloc_failed(fd, buffer);
    is_read_failed(fd, buffer, s);
    buffer[s.st_size] = '\0';
    d->word_count = get_word_count(buffer);
    d->words = my_str_to_word_array(buffer);
    free(buffer);
    close(fd);
}

void dictionary_free(dictionary_t *d)
{
    for (int i = 0; i < d->word_count; i++) {
        free(d->words[i]);
    }
    free(d->words);
}
