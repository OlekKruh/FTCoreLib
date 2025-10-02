/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:42:28 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/02 20:56:09 by okruhlia         ###   ########.fr       */
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
typedef struct s_test
{
	const char *input;
	const char *set;
	const char *expected;
}
test_case_srtrim;

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
	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		char *res = ft_substr(tests[i].src, tests[i].start, tests[i].len);
		if (tests[i].expected == NULL) {
			CU_ASSERT_PTR_NULL(res);
		} else {
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

void	register_suite2_tests(void)
{
	CU_pSuite suite = CU_add_suite("Suite2", 0, 0);
	CU_add_test(suite, "ft_substr", test_ft_substr);
	CU_add_test(suite, "ft_strjoin", test_ft_strjoin);
	CU_add_test(suite, "ft_strtrim", test_ft_strtrim);
	CU_add_test(suite, "ft_memcmp_equal_not_equal_zero", test_ft_memcmp_equal_not_equal_zero);
	CU_add_test(suite, "ft_memcmp_less_greater", test_ft_memcmp_less_greater);
}
