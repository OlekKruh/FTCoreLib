/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/01 14:21:37 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "libft.h"

typedef struct
{
	char input;
	char expected;
}
test_case_char;
typedef	struct
{
	char dst[50];
	const char *src;
	size_t size;
	char expected_dst[50];
	size_t expected_ret;
}
test_case_strlcat;
typedef struct
{
	char initial[50];
	const char *src;
	size_t size;
	const char *expected;
	size_t expected_ret;
}
test_case_strlcpy;
typedef struct
{
	int input;
	int expected;
}
test_case_int;
typedef struct
{
	char src[20];
	size_t length;
}
test_case_memcpy;
typedef struct
{
	char initial[20];
	int c;
	size_t len;
	char expected[20];
}
test_case_memset;
typedef struct
{
	char initial[30];
	size_t src_offset;
	size_t dst_offset;
	size_t length;
	char expected[30];
}
test_case_memmove;
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


void	test_ft_atoi(void)
{
	char	*overflow_str_1;
	char	*overflow_str_2;

	overflow_str_1 = "-2147483649";
	overflow_str_2 = "2147483648";
	CU_ASSERT(ft_atoi("-123") == -123);
	CU_ASSERT(ft_atoi("--123") == 0);
	CU_ASSERT(ft_atoi("++123") == 0);
	CU_ASSERT(ft_atoi("-+123") == 0);
	CU_ASSERT(ft_atoi("+-123") == 0);
	CU_ASSERT(ft_atoi("-=123") == 0);
	CU_ASSERT(ft_atoi(" 	\n123") == 123);
	CU_ASSERT(ft_atoi("123abc") == 123);
	CU_ASSERT(ft_atoi("+42") == 42);
	CU_ASSERT(ft_atoi("321") == 321);
	CU_ASSERT(ft_atoi("0") == 0);
	CU_ASSERT(ft_atoi("0042") == 42);
	CU_ASSERT(ft_atoi("0x2A") == 0);
	CU_ASSERT(ft_atoi("junk") == 0);
	CU_ASSERT_EQUAL(ft_atoi(overflow_str_1), atoi(overflow_str_1));
	CU_ASSERT_EQUAL(ft_atoi(overflow_str_2), atoi(overflow_str_2));
}

void	test_ft_memset(void)
{
	test_case_memset cases[] =
			{
					{"abcdefghij", 'A', 5, "AAAAAfghij"},
					{"1234567890", '0', 10, "0000000000"},
					{"", 'X', 0, ""},
					{"Test", '!', 2, "!!st"}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	{
		char buffer[20];
		strcpy(buffer, cases[i].initial);
		ft_memset(buffer, cases[i].c, cases[i].len);
		CU_ASSERT_NSTRING_EQUAL(buffer, cases[i].expected, strlen(cases[i].expected));
	}
}

void	test_ft_bzero(void)
{
	char buff1[10];
	char buff2[10];

	memset(buff1, 'x', 10);
	memset(buff2, 'x', 10);

	ft_bzero(buff1, 10);
	bzero(buff2, 10);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);

	memset(buff1, 'x', 10);
	memset(buff2, 'x', 10);

	ft_bzero(buff1, 5);
	bzero(buff2, 5);

	CU_ASSERT_EQUAL(0, memcmp(buff1, buff2, 10));
}

void	test_ft_calloc_full(void)
{
	unsigned int quant = 5;
	unsigned int len = sizeof(int);
	void *ptr1;
	void *ptr2;

	ptr1 = ft_calloc(quant, len);
	CU_ASSERT_PTR_NOT_NULL(ptr1);

	ptr2 = calloc(quant, len);
	CU_ASSERT_PTR_NOT_NULL(ptr2);

	CU_ASSERT_EQUAL(0, memcmp(ptr1, ptr2, (quant * len)))

	free(ptr1);
	free(ptr2);
}

void	test_ft_calloc_zero(void)
{
	CU_ASSERT_PTR_NULL(ft_calloc(0, 10));
	CU_ASSERT_PTR_NULL(ft_calloc(10, 0));
	CU_ASSERT_PTR_NULL(ft_calloc(0, 0));
}

void	test_ft_calloc_overflow()
{
	CU_ASSERT_PTR_NULL(ft_calloc(UINTMAX_MAX, UINTMAX_MAX));
}

void	test_ft_strlen(void)
{
	CU_ASSERT_EQUAL(ft_strlen(""), 0);
	CU_ASSERT_EQUAL(ft_strlen("abc"), 3);
	CU_ASSERT_EQUAL(ft_strlen("a"), 1);
	CU_ASSERT_EQUAL(ft_strlen("a b c"), 5);
	CU_ASSERT_EQUAL(ft_strlen("a b\nc"), 5);
}

void	test_ft_strdup_copy_and_not_null(void)
{
	char *dup = ft_strdup("hello");
	CU_ASSERT_PTR_NOT_NULL(dup);
	CU_ASSERT_STRING_EQUAL(dup, "hello");
	free(dup);
}

void	test_ft_strdup_different_pointer(void)
{
	const char *src;
	char *dup;

	src = "hello";
	dup = ft_strdup(src);

	CU_ASSERT_PTR_NOT_EQUAL(dup, src);
	free(dup);
}

void	test_ft_strdup_empty_string(void)
{
	char *dup;

	dup = ft_strdup("");

	CU_ASSERT_PTR_NOT_NULL(dup);
	CU_ASSERT_STRING_EQUAL(dup, "");

	free(dup);
}

void	test_ft_isalpha(void)
{
	test_case_int cases[] =
			{
					{'a', 1}, {'z', 1}, {'A', 1},
					{'Z', 1}, {'m', 1}, {'M', 1},
					{'0', 0}, {'9', 0}, {' ', 0},
					{'\n', 0}, {'!', 0}, {'`', 0},
					{'{', 0}, {'@', 0}, {'[', 0},
					{-1, 0}, {128, 0}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_isalpha(cases[i].input), cases[i].expected);
}

void	test_ft_isdigit(void)
{
	test_case_int cases[] =
			{
					{'0', 1}, {'5', 1}, {'9', 1},
					{'a', 0}, {'Z', 0}, {' ', 0},
					{'\n', 0}, {'/', 0},	{-1, 0},
					{128, 0}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_isdigit(cases[i].input), cases[i].expected);
}

void	test_ft_isascii(void)
{
	test_case_int cases[] =
			{
					{'0', 1}, {'9', 1}, {'A', 1},
					{'Z', 1}, {'a', 1}, {'z', 1},
					{' ', 1}, {'!', 1}, {'\n', 1},
					{'\t', 1}, {0, 1}, {127, 1},
					{-1, 0}, {128, 0}, {255, 0}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_isascii(cases[i].input), cases[i].expected);
}

void	test_ft_isprint(void)
{
	test_case_int cases[] =
			{
					{' ', 1}, {'!', 1}, {'+', 1},
					{'.', 1}, {'/', 1}, {':', 1},
					{'@', 1}, {'~', 1}, {'0', 1},
					{'9', 1}, {'A', 1}, {'Z', 1},
					{'a', 1}, {'z', 1}, {'\0', 0},
					{'\t', 0}, {'\n', 0}, {27, 0},
					{-1, 0}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_isprint(cases[i].input), cases[i].expected);
}

void	test_ft_isalnum(void)
{
	test_case_int cases[] =
			{
					{'0', 1}, {'5', 1}, {'9', 1},
					{'A', 1}, {'M', 1}, {'Z', 1},
					{'a', 1}, {'m', 1}, {'z', 1},
					{' ', 0}, {'!', 0}, {'@', 0},
					{'\n', 0}, {-1, 0}, {128, 0}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_isalnum(cases[i].input), cases[i].expected);
}

void	test_ft_memcpy(void)
{
	test_case_memcpy cases[] =
			{
					{"Hello, World!", 14},
					{"1234567890", 5},
					{"test", 0},
					{"abcdefghij", 10}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	{
		char dest[20] = {0};
		ft_memcpy(dest, cases[i].src, cases[i].length);
		CU_ASSERT_NSTRING_EQUAL(dest, cases[i].src, cases[i].length);
	}
}

void	test_ft_memmove(void)
{
	test_case_memmove cases[] =
			{
					{"Hello, World!", 0, 7, 6, "Hello, Hello,"},
					{"1234567890", 2, 5, 3, "1234534590"},
					{"abcdefghij", 0, 0, 5, "abcdefghij"},
					{"OverlapTest", 0, 3, 5, "OveOverlest"}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	{
		char buffer[30];
		strcpy(buffer, cases[i].initial);
		ft_memmove(buffer + cases[i].dst_offset, buffer + cases[i].src_offset, cases[i].length);
		CU_ASSERT_NSTRING_EQUAL(buffer, cases[i].expected, strlen(cases[i].expected));
	}
}

void	test_ft_strncpy_short_long_equal(void)
{
	char	dest1[10];
	char	src1[] = "kapibara";

	memset(dest1, 'S', sizeof(dest1));
	ft_strncpy(dest1, src1, sizeof(dest1));

	CU_ASSERT_NSTRING_EQUAL(dest1, src1, strlen(src1));
	for (size_t id = strlen(src1); id < sizeof(dest1); id++)
	{
		CU_ASSERT(dest1[id] == '\0');
	}

	char dest2[10];
	char src2[] = "this is a longer string";

	memset(dest2, 'L', sizeof(dest2));
	ft_strncpy(dest2, src2, sizeof(dest2));

	CU_ASSERT_NSTRING_EQUAL(dest2, src2, sizeof(dest2));

	char dest3[10];
	char src3[] = "abcdefghij";

	memset(dest3, 'E', sizeof(dest3));
	ft_strncpy(dest3, src3, sizeof(dest3));

	CU_ASSERT_NSTRING_EQUAL(dest3, src3, sizeof(dest3));
}

void	test_ft_memchr_found_not_found(void)
{
	char str[] = "Hello World!";
	char ch1 = 'o';
	char ch2 = 'x';
	char ch3 = 'e';
	char ch4 = '!';

	char *res1 = ft_memchr(str, ch1, sizeof(str));
	CU_ASSERT_PTR_NOT_NULL(res1);
	CU_ASSERT_EQUAL(*res1, ch1);
	CU_ASSERT_PTR_EQUAL(res1, &str[4]);

	char *res4 = ft_memchr(str, ch4, sizeof(str));
	CU_ASSERT_PTR_NOT_NULL(res4);
	CU_ASSERT_EQUAL(*res4, ch4);
	CU_ASSERT_PTR_EQUAL(res4, &str[11]);

	char *res2 = ft_memchr(str, ch2, sizeof(str));
	CU_ASSERT_PTR_NULL(res2);

	char *res3 = ft_memchr(str, ch3, 0);
	CU_ASSERT_PTR_NULL(res3);
}

void	test_ft_memchr_zero_empty(void)
{
	char str1[] = "Hello World!";
	char str2[] = "";
	char ch1 = 'o';
	char ch2 = 'x';

	char *res1 = ft_memchr(str1, ch1, 0);
	CU_ASSERT_PTR_NULL(res1);

	char *res2 = ft_memchr(str2, ch2, sizeof(str2));
	CU_ASSERT_PTR_NULL(res2);
}

void	test_ft_memcmp_equal_not_equal_zero(void)
{
	char str1[] = "hello world";
	char str2[] = "hello there";
	CU_ASSERT_EQUAL(ft_memcmp(str1, str2, 5), 0);
	CU_ASSERT_TRUE(ft_memcmp(str1, str2, 6) != 0);
	CU_ASSERT_EQUAL(ft_memcmp(str1, str2, 0), 0);
}

void	test_ft_memcmp_less_greater(void)
{
	char str1[] = "heLlo";
	char str2[] = "hello";
	char str3[] = "helLo";

	CU_ASSERT_TRUE(ft_memcmp(str1, str2, 5) < 0);
	CU_ASSERT_TRUE(ft_memcmp(str2, str3, 6) > 0);
}

void	test_ft_strnstr(void)
{
	char *text = "To be, or not to be, that is the question:";
	char *needles[] = {
			"",
			"To be",
			" To be",
			"not to be",
			"question:",
			"question: ",
			"?",
	};
	char *expected[] = {
			text,
			text,
			NULL,
			text + 10,
			text + 33,
			NULL,
			NULL,
	};

	size_t count = sizeof(needles) / sizeof(needles[0]);
	size_t len = strlen(text);

	for (size_t i = 0; i < count; i++)
	{
		char *res0_0 = strnstr(text, needles[i], len);
		CU_ASSERT_PTR_EQUAL(res0_0, expected[i]);
	}

	char *res0_1 = strnstr(text, needles[1], 0);
	CU_ASSERT_PTR_NULL(res0_1);

	for (size_t i = 0; i < count; i++)
	{
		char *res1_0 = ft_strnstr(text, needles[i], len);
		CU_ASSERT_PTR_EQUAL(res1_0, expected[i]);
	}

	char *res1_1 = ft_strnstr(text, needles[1], 0);
	CU_ASSERT_PTR_NULL(res1_1);
}

void	test_ft_strrchr(void)
{
	char *text = "My name is Sherlock Holmes. It is my business to know what other people do not know.";
	int needles[] = {
			'\0',
			'.',
			'w',
			'I',
			'H',
			'M',
	};
	char *expected[] = {
			text + 84,
			text + 83,
			text + 82,
			text + 28,
			text + 20,
			text,
	};

	size_t count = sizeof(needles) / sizeof(needles[0]);

	for (size_t i = 0; i < count; i++)
	{
		char *res0_0 = strrchr(text, needles[i]);
		CU_ASSERT_PTR_EQUAL(res0_0, expected[i]);
	}

	for (size_t i = 0; i < count; i++)
	{
		char *res1_0 = ft_strrchr(text, needles[i]);
		CU_ASSERT_PTR_EQUAL(res1_0, expected[i]);
	}
}

void	test_ft_strchr(void)
{
	char *text = "Curiouser and curiouser!";
	int needles[] = {
			'\0',
			'u',
			'r',
			'!',
			'c',
	};
	char *expected[] = {
			text + 24,
			text + 1,
			text + 2,
			text + 23,
			text + 14,
	};

	size_t count = sizeof(needles) / sizeof(needles[0]);

	for (size_t i = 0; i < count; i++)
	{
		char *res0_0 = strchr(text, needles[i]);
		CU_ASSERT_PTR_EQUAL(res0_0, expected[i]);
	}

	for (size_t i = 0; i < count; i++)
	{
		char *res1_0 = ft_strchr(text, needles[i]);
		CU_ASSERT_PTR_EQUAL(res1_0, expected[i]);
	}
}

void	test_ft_tolower(void)
{
	test_case_char cases[] =
			{
					{'A', 'a'},
					{'Z', 'z'},
					{'M', 'm'},
					{'a', 'a'},
					{'z', 'z'},
					{'m', 'm'},
					{'!', '!'},
					{'0', '0'},
					{' ', ' '}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_tolower(cases[i].input), cases[i].expected);
}

void	test_ft_toupper(void)
{
	test_case_char cases[] =
			{
					{'a', 'A'},
					{'z', 'Z'},
					{'m', 'M'},
					{'A', 'A'},
					{'Z', 'Z'},
					{'M', 'M'},
					{'!', '!'},
					{'0', '0'},
					{' ', ' '}
			};
	int count = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < count; i++)
	CU_ASSERT_EQUAL(ft_toupper(cases[i].input), cases[i].expected);
}

void	test_ft_strlcat(void)
{
	test_case_strlcat tests[] =
			{
					{"Hello, ", "world!", 50, "Hello, world!", strlen("Hello, ") + strlen("world!")},
					{"Hello",   "World",  0,  "Hello",         0 + strlen("World")},
					{"Hello",   "World",  7,  "HelloW",        strlen("Hello") + strlen("World")},
					{"Hello",   " World", 12, "Hello World",   strlen("Hello") + strlen(" World")},
					{"Hello",   "World",  3,  "Hello",         3 + strlen("World")}
			};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < num_tests; i++)
	{
		char buffer[50];
		strcpy(buffer, tests[i].dst);
		size_t ret = ft_strlcat(buffer, tests[i].src, tests[i].size);
		CU_ASSERT_STRING_EQUAL(buffer, tests[i].expected_dst);
		CU_ASSERT_EQUAL(ret, tests[i].expected_ret);
	}
}

void	test_ft_strlcpy(void)
{
	test_case_strlcpy cases[] =
			{
					{"", "HelloWorld", 15, "HelloWorld", strlen("HelloWorld")},
					{"Example", "Test", 10, "Test", strlen("Test")},
					{"Hello", "Hi", 5, "Hi", strlen("Hi")},
					{"NoChange", "NoCopy", 0, "NoChange", strlen("NoCopy")},
					{"Test", "LongString", 5, "Long", strlen("LongString")},
			};
	int n = sizeof(cases) / sizeof(cases[0]);
	for (int i = 0; i < n; i++) {
		char buffer[50];
		strcpy(buffer, cases[i].initial);
		size_t ret = ft_strlcpy(buffer, cases[i].src, cases[i].size);
		CU_ASSERT_STRING_EQUAL(buffer, cases[i].expected);
		CU_ASSERT_EQUAL(ret, cases[i].expected_ret);
	}
}

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

int		main(void)
{
	CU_initialize_registry();

	CU_pSuite suite = CU_add_suite("LibFT Testing", 0, 0);
	CU_add_test(suite, "ft_atoi", test_ft_atoi);
	CU_add_test(suite, "ft_memset full", test_ft_memset);
	CU_add_test(suite, "ft_bzero full", test_ft_bzero);
	CU_add_test(suite, "ft_calloc full", test_ft_calloc_full);
	CU_add_test(suite, "ft_calloc return zero", test_ft_calloc_zero);
	CU_add_test(suite, "ft_calloc overflow", test_ft_calloc_overflow);
	CU_add_test(suite, "ft_strlen", test_ft_strlen);
	CU_add_test(suite, "ft_strdup_copy_and_not_null", test_ft_strdup_copy_and_not_null);
	CU_add_test(suite, "ft_strdup_different_pointer", test_ft_strdup_different_pointer);
	CU_add_test(suite, "ft_strdup_empty_string", test_ft_strdup_empty_string);
	CU_add_test(suite, "ft_isalpha", test_ft_isalpha);
	CU_add_test(suite, "ft_isdigit", test_ft_isdigit);
	CU_add_test(suite, "ft_isascii", test_ft_isascii);
	CU_add_test(suite, "ft_isprint", test_ft_isprint);
	CU_add_test(suite, "ft_isalnum", test_ft_isalnum);
	CU_add_test(suite, "ft_memcpy", test_ft_memcpy);
	CU_add_test(suite, "ft_memmove", test_ft_memmove);
	CU_add_test(suite, "ft_strncpy_short_long_equal", test_ft_strncpy_short_long_equal);
	CU_add_test(suite, "ft_memchr_found_not_found", test_ft_memchr_found_not_found);
	CU_add_test(suite, "ft_memchr_zero_empty", test_ft_memchr_zero_empty);
	CU_add_test(suite, "ft_memcmp_equal_not_equal_zero", test_ft_memcmp_equal_not_equal_zero);
	CU_add_test(suite, "ft_memcmp_less_greater", test_ft_memcmp_less_greater);
	CU_add_test(suite, "ft_strnstr", test_ft_strnstr);
	CU_add_test(suite, "ft_strrchr", test_ft_strrchr);
	CU_add_test(suite, "ft_strchr", test_ft_strchr);
	CU_add_test(suite, "ft_tolower", test_ft_tolower);
	CU_add_test(suite, "ft_toupper", test_ft_toupper);
	CU_add_test(suite, "ft_strlcat", test_ft_strlcat);
	CU_add_test(suite, "ft_strlcpy", test_ft_strlcpy);
	CU_add_test(suite, "ft_substr", test_ft_substr);
	CU_add_test(suite, "ft_strjoin", test_ft_strjoin);
	CU_add_test(suite, "ft_strtrim", test_ft_strtrim);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (0);
}
