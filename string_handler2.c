#include "shell.h"

/**
 * *_strcat - concatenates two strings
 * @dest: string to append to
 * @src: sring to append
 * @n: number of bytes to append
 *
 * Return: pointer to concatenated string
 */
char *_strncat(char *dest, char *src, size_t n)
{
	int src_i = 0, dest_i = 0;

	for (; dest[dest_i] != '\0';)
		dest_i++;

	for (;src_i < n && src[src_i] != '\0';)
	{
		dest[dest_i] = src[src_i];
		src_i++;
		dest_i++;
	}

	dest[dest_i] = '\0';

	return (dest);
}

/**
 * strformat - format tabs, newlines and spaces from string
 * @str: string to format
 * @str_size: size of str
 * Return: ptr to formatted str
 */
char *strformat(char *str, size_t str_size)
{
    int i =0, j = 0;
    char *formattedStr;

    formattedStr = chr_malloc(str_size);
    init_mem(formattedStr, str_size);

    while (str[i] != '\0')
    {
        if (str[i] != '\t' && str[i] != '\n')
        {
            formattedStr[j] = str[i];
            j++;
        }
        i++;
    }
    formattedStr[j] = '\0';
    free(str);
    return (formattedStr);
}

/**
 * strtok_len - len of tokens
 * @buf: str to be tokinised
 * @token: token to get len
 * @token_num: token num
 * Return: size of token
 */
size_t strtok_len(char *buf, char *token, int token_num)
{
    size_t i = 0, Numtokens = 0, token_len = 0;

    while (buf[i] != '\0')
    {
        if (buf[i] == '\t' || buf[i] == ' ')
            Numtokens++;
        if (token_num == Numtokens)
            token_len++;
        i++;
    }
    return (token_len);
}