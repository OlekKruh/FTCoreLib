/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:42:28 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/05 17:34:51 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>
#include "../libft.h"

typedef struct
{
	const char *src;
	unsigned int start;
	size_t len;
	const char *expected;
}
test_case_ft_substr;
typedef struct
{
	const char *s1;
	const char *s2;
	const char *expected;
}
test_case_strjoin;
typedef struct
{
	const char *input;
	const char *set;
	const char *expected;
}
test_case_srtrim;
typedef struct
{
	const char *string;
	const char separator;
	const char **expected;
}
test_case_split;
typedef struct
{
	int input;
	const char *expected;
}
itoa_test_case;

void	test_ft_substr(void)
{
	test_case_ft_substr tests[] =
			{
					{NULL, 0, 10, NULL},
					{"Hello", 10, 3, ""},
					{"Hello", 1, 0, ""},
					{"Hello", 1, 2, "el"},
					{"Hello", 3, 10, "lo"},
					{"Hello", 0, 5, "Hello"},
					{NULL, 0, 0, NULL},
			};
	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		char *res = ft_substr(tests[i].src, tests[i].start, tests[i].len);
		if (tests[i].expected == NULL)
		{
			CU_ASSERT_PTR_NULL(res);
		}
		else
		{
			CU_ASSERT_STRING_EQUAL(res, tests[i].expected);
			free(res);
		}
	}
}

void	test_ft_strjoin(void)
{
	test_case_strjoin tests[] =
			{
					{ "Hello, ", "world!", "Hello, world!" },
					{"Ababa", "galamaga", "Ababagalamaga"},
					{ NULL, "world!", "world!" },
					{ "Hello, ", NULL, "Hello, " },
					{ NULL, NULL, NULL },
					{ "", "Banana", "Banana" },
					{ "Apple", "", "Apple" },
					{ "", "", "" }
			};
	for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
	{
		char *res = ft_strjoin(tests[i].s1, tests[i].s2);
		if (tests[i].expected == NULL)
		{
			CU_ASSERT_PTR_NULL(res);
		}
		else
		{
			CU_ASSERT_PTR_NOT_NULL(res);
			if (res)
			{
				CU_ASSERT_STRING_EQUAL(res, tests[i].expected);
				free(res);
			}
		}
	}
}

void	test_ft_strtrim(void)
{
	test_case_srtrim tests[] =
			{
					{"  hello  ", " ", "hello"},
					{"  hello world  ", " ", "hello world"},
					{"\t\nhello\t\n", "\t\n", "hello"},
					{"xxhelloxx", "x", "hello"},
					{"abchelloabc", "abc", "hello"},
					{"", " ", ""},
					{NULL, " ", ""},
					{"hello", NULL, ""},
					{"aaa", "a", ""},
					{"hello", "xyz", "hello"},
					{NULL, NULL, ""}
			};

	for (int i = 0; i < sizeof(tests)/sizeof(test_case_srtrim); i++)
	{
		char *result = ft_strtrim(tests[i].input, tests[i].set);
		if (tests[i].expected == NULL)
		{
			CU_ASSERT_PTR_NULL(result);
		}
		else
			CU_ASSERT_STRING_EQUAL(result ? result : "", tests[i].expected);
		free(result);
	}
}

void	test_ft_memcmp_equal_not_equal_zero(void)
{
	char str1[] = "hello world";
	char str2[] = "hello there";
	CU_ASSERT_EQUAL(ft_memcmp(str1, str2, 5), 0);
	CU_ASSERT_EQUAL(ft_memcmp(str1, str2, 0), 0);
	CU_ASSERT_TRUE(ft_memcmp(str1, str2, 8) != 0);
}

void	test_ft_memcmp_less_greater(void)
{
	char str1[] = "heLlo";
	char str2[] = "hello";
	char str3[] = "helLo";

	CU_ASSERT_TRUE(ft_memcmp(str1, str2, 5) < 0);
	CU_ASSERT_TRUE(ft_memcmp(str2, str3, 6) > 0);
}

void	test_ft_split(void)
{
	const char *expected0[] = {"Yer", "a", "wizard", "Harry.", NULL};
	const char *expected1[] = {"I", "solemnly", "swear", "that", "I", "am",
							   "up", "to", "no", "good,", NULL};
	const char *expected2[] = {"IKnowKungFu", NULL};
	const char *expected3[] = {"OpenAI", "rocks!", NULL};
	const char *expected4[] = {"Hello", "world", NULL};
	const char *expected5[] = {NULL};

	test_case_split tests[] =
			{
					{",Yer,a,wizard,,Harry.", ',', expected0},
					{"I  solemnly  swear  that I am up   to no    good,", ' ', expected1},
					{"IKnowKungFu", ' ', expected2},
					{"  OpenAI  rocks!  ", ' ', expected3},
					{"Hello,world", ',', expected4},
					{"    ", ' ', expected5},
			};

	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		char **res = ft_split(tests[i].string, tests[i].separator);

		if (tests[i].expected[0] == NULL)
		{
			CU_ASSERT_PTR_NOT_NULL(res);
			CU_ASSERT_PTR_NULL(res[0]);
		}
		else
		{
			CU_ASSERT_PTR_NOT_NULL(res);
			size_t j = 0;
			while (tests[i].expected[j] != NULL) {
				CU_ASSERT_PTR_NOT_NULL(res[j]);
				CU_ASSERT_STRING_EQUAL(res[j], tests[i].expected[j]);
				j++;
			}
			CU_ASSERT_PTR_NULL(res[j]);

			for (size_t k = 0; k < j; k++)
				free(res[k]);
			free(res);
		}
	}
}

void	test_ft_itoa(void)
{
	itoa_test_case tests[] =
			{
			{0, "0"},
			{123, "123"},
			{-123, "-123"},
			{INT_MIN, "-2147483648"},
			{INT_MAX, "2147483647"},
			{42, "42"},
			{-42, "-42"}
			};

	size_t n_tests = sizeof(tests) / sizeof(tests[0]);

	for (size_t i = 0; i < n_tests; i++)
	{
		char *result = ft_itoa(tests[i].input);
		CU_ASSERT_PTR_NOT_NULL(result);
		if (result)
		{
			CU_ASSERT_STRING_EQUAL(result, tests[i].expected);
			free(result);
		}
	}
}

char	test_func(unsigned int i, char c)
{
	return c + i;
}

void	test_ft_strmapi(void)
{
	char *str = "abcd";
	char *expected = "aceg"; // 'a'+0, 'b'+1, 'c'+2, 'd'+3
	char *result = ft_strmapi(str, test_func);
	CU_ASSERT_STRING_EQUAL(result, expected);
	free(result);
}

void	test_func2(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c + i;
}

void	test_ft_striteri(void)
{
	char str[5] = "abcd";
	char expected[] = "aceg"; // 'a'+0, 'b'+1, 'c'+2, 'd'+3
	ft_striteri(str, test_func2);
	CU_ASSERT_STRING_EQUAL(str, expected);
}

void	test_ft_putchar_fd(void)
{
	int fd[2];
	char c = 'X';
	char read_c = 0;

	// Создаём pipe
	CU_ASSERT_EQUAL(pipe(fd), 0);

	// Пишем символ в write-end пайпа
	ft_putchar_fd(c, fd[1]);
	close(fd[1]); // Закрываем write-end

	// Читаем символ из read-end
	CU_ASSERT_EQUAL(read(fd[0], &read_c, 1), 1);
	CU_ASSERT_EQUAL(read_c, c);

	close(fd[0]);
}

void	register_suite2_tests(void)
{
	CU_pSuite suite = CU_add_suite("Suite2", 0, 0);
	CU_add_test(suite, "ft_substr", test_ft_substr);
	CU_add_test(suite, "ft_strjoin", test_ft_strjoin);
	CU_add_test(suite, "ft_strtrim", test_ft_strtrim);
	CU_add_test(suite, "ft_memcmp_equal_not_equal_zero", test_ft_memcmp_equal_not_equal_zero);
	CU_add_test(suite, "ft_memcmp_less_greater", test_ft_memcmp_less_greater);
	CU_add_test(suite, "ft_split", test_ft_split);
	CU_add_test(suite, "ft_itoa", test_ft_itoa);
	CU_add_test(suite, "ft_strmapi", test_ft_strmapi);
	CU_add_test(suite, "ft_striteri", test_ft_striteri);
	CU_add_test(suite, "ft_putchar_fd", test_ft_putchar_fd);
}
