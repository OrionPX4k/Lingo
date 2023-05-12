/*
** EPITECH PROJECT, 2023
** unit_test
** File description:
** lingo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/my.h"

Test(lingo, missing_argument)
{
    char *args[] = {"./lingo"};
    int argc = sizeof(args) / sizeof(args[0]);
    int result = lingo(argc, args);
    cr_assert_eq(result, ERROR, "Expected ERROR, but got %d", result);
}

Test(lingo, help_option)
{
    char *args[] = {"./lingo", "-h"};
    int argc = sizeof(args) / sizeof(args[0]);
    int result = lingo(argc, args);
    cr_assert_eq(result, SUCCESS, "Expected SUCCESS, but got %d", result);
}
