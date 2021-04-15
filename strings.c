#include "header.h"

/**
 *  _str_cmp - validate if two strings are equals.
 *  @str1: pointer to char, text one.
 *  @str2: pointer to char, text two.
 *  Return: If the texts are equal 1, or else 0.
 */
int _str_cmp(char *str1, char *str2)
{
	/* edge case */
	if (!str1 || !str2)
		return (FALSE);

	/* if case base failure*/
	if (*str1 != *str2)
		return (FALSE);

	/* if case base success*/
	if (!*str1 && !*str2)
		return (TRUE);

	/* recursion case */
	return (_str_cmp(str1 + 1, str2 + 1));
}

/**
 *  _str_include - validate if one strings is included in another.
 *  @str1: pointer to char, text one.
 *  @str2: pointer to char, text two.
 *
 *  Return: If the texts are equal 1, or else 0.
 */
int _str_include(char *str1, char *str2)
{
	/* edge case */
	if (!str1 || !str2)
		return (FALSE);

	/* if case base failure*/
	if (*str1 != *str2)
		return (FALSE);

	/* if case base success*/
	if (*str1 == '=' && *str2 == '=')
		return (TRUE);

	/* recursion case */
	return (_str_include(str1 + 1, str2 + 1));
}

/**
 * _str_len - find the length of a string.
 * @string: pointer to the string to check its length.
 *
 * Return: length of the string.
 */
size_t _str_len(char *string)
{
	/* edge case */
	if (!string)
	{
		return (0);
	}

	/* success */
	if (!*string)
	{
		return (0);
	}

	/* recursion case */
	return (1 + _str_len(string + 1));
}

/**
 * _getenv - find especific environment variable.
 *	(recursive)
 *	iterate while envp != NULL
 *		check if envp includes key chars
 *			return (pointer + key_length)
 *		else
 *			return (NULL)
 * @key: pointer to char.
 * @envp: pointer to char.
 * Return: pointer to char with environment variable.
 */
char *_getenv(char *key, char *envp[])
{
	/* edge case guard conditions */
	if (!key || !envp)
	{
		return (NULL);
	}

	/* case base failure find null value*/
	/* if path is not found */
	if (!*envp)
	{
		return (NULL);
	}

	/* case base success */
	/*match keys*/
	if (_str_include(key, *envp))
	{
		return ((strlen(key) + *envp));
	}

	/* recursion case */
	return (_getenv(key, (envp + 1)));
}

/**
 * _str_concat - Contatenate two strings.
 * @str1: string to get concatenated.
 * @str2: string to concatenate.
 *
 * Return: None.
 */
void _str_concat(char *str1, char *str2)
{
	size_t len_str1, i;

	if (!str1 || !str2)
	{
		return;
	}

	len_str1 = _str_len(str1);

	for (i = 0; str2[i]; i++)
	{
		str1[len_str1 + i] = str2[i];
	}

	str1[len_str1 + i] = '\0';
}
