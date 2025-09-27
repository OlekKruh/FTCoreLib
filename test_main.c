/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/27 20:59:19 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "libft.h"

void	test_ft_atoi(void);
void	test_ft_memset_variants(void);
void	test_ft_memset_same_ptr(void);
void	test_ft_bzero(void);
void	test_ft_calloc_full(void);
void	test_ft_calloc_zero(void);
void	test_ft_calloc_overflow(void);
void	test_ft_strlen(void);
void	test_ft_strdup_copy_and_not_null(void);
void	test_ft_strdup_different_pointer(void);
void	test_ft_strdup_empty_string(void);
void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_isalnum(void);
void	test_ft_memcpy(void);
void	test_ft_memmove_no_overlap_zero_len(void);
void	test_ft_memmove_overlap_right_left(void);
void	test_ft_memmove_same_ptr(void);
void	test_ft_strncpy_short_long_equal(void);
void	test_ft_memchr_found_not_found(void);
void	test_ft_memchr_zero_empty(void);
void	test_ft_memcmp_equal_not_equal_zero(void);
void	test_ft_memcmp_less_greater(void);

int		main(void)
{
	CU_initialize_registry();

	CU_pSuite suite = CU_add_suite("LibFT Testing", 0, 0);
	CU_add_test(suite, "Test ft_atoi", test_ft_atoi);
	CU_add_test(suite, "Test ft_memset full", test_ft_memset_variants);
	CU_add_test(suite, "Test ft_memset same pointer", test_ft_memset_same_ptr);
	CU_add_test(suite, "Test ft_bzero full", test_ft_bzero);
	CU_add_test(suite, "Test ft_calloc full", test_ft_calloc_full);
	CU_add_test(suite, "Test ft_calloc return zero", test_ft_calloc_zero);
	CU_add_test(suite, "Test ft_calloc overflow", test_ft_calloc_overflow);
	CU_add_test(suite, "Test ft_strlen", test_ft_strlen);
	CU_add_test(suite, "Test ft_strdup_copy_and_not_null", test_ft_strdup_copy_and_not_null);
	CU_add_test(suite, "Test ft_strdup_different_pointer", test_ft_strdup_different_pointer);
	CU_add_test(suite, "Test ft_strdup_empty_string", test_ft_strdup_empty_string);
	CU_add_test(suite, "Test ft_isalpha", test_ft_isalpha);
	CU_add_test(suite, "Test ft_isdigit", test_ft_isdigit);
	CU_add_test(suite, "Test ft_isascii", test_ft_isascii);
	CU_add_test(suite, "Test ft_isprint", test_ft_isprint);
	CU_add_test(suite, "Test ft_isalnum", test_ft_isalnum);
	CU_add_test(suite, "Test ft_memcpy", test_ft_memcpy);
	CU_add_test(suite, "Test test_ft_memmove_no_overlap_zero_len", test_ft_memmove_no_overlap_zero_len);
	CU_add_test(suite, "Test test_ft_memmove_overlap_right_left", test_ft_memmove_overlap_right_left);
	CU_add_test(suite, "Test test_ft_memmove_same_ptr", test_ft_memmove_same_ptr);
	CU_add_test(suite, "Test test_ft_strncpy_short_long_equal", test_ft_strncpy_short_long_equal);
	CU_add_test(suite, "Test test_ft_memchr_found_not_found", test_ft_memchr_found_not_found);
	CU_add_test(suite, "Test test_ft_memchr_zero_empty", test_ft_memchr_zero_empty);
	CU_add_test(suite, "Test test_ft_memcmp_equal_not_equal_zero", test_ft_memcmp_equal_not_equal_zero);
	CU_add_test(suite, "Test test_ft_memcmp_less_greater", test_ft_memcmp_less_greater);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (0);
}

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

void	test_ft_memset_variants(void)
{
	char	buff1[10];
	char	buff2[10];

	ft_memset(buff1, 'A', 10);
	memset(buff2, 'A', 10);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);

	ft_memset(buff1, 'B', 5);
	memset(buff2, 'B', 5);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);

	memset(buff1, 'Q', 10);
	memset(buff2, 'Q', 10);

	ft_memset(buff1, 'A', 0);
	memset(buff2, 'A', 0);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);
}

void	test_ft_memset_same_ptr(void)
{
	char buff[5];
	char *ptr = buff;

	CU_ASSERT_PTR_EQUAL(ft_memset(buff, 'B', 5), ptr);
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
	CU_ASSERT(ft_isalpha('a') == 1);
	CU_ASSERT(ft_isalpha('z') == 1);
	CU_ASSERT(ft_isalpha('A') == 1);
	CU_ASSERT(ft_isalpha('Z') == 1);

	CU_ASSERT(ft_isalpha('m') == 1);
	CU_ASSERT(ft_isalpha('M') == 1);

	CU_ASSERT(ft_isalpha('0') == 0);
	CU_ASSERT(ft_isalpha('9') == 0);
	CU_ASSERT(ft_isalpha(' ') == 0);
	CU_ASSERT(ft_isalpha('\n') == 0);
	CU_ASSERT(ft_isalpha('!') == 0);

	CU_ASSERT(ft_isalpha('`') == 0);
	CU_ASSERT(ft_isalpha('{') == 0);
	CU_ASSERT(ft_isalpha('@') == 0);
	CU_ASSERT(ft_isalpha('[') == 0);

	CU_ASSERT(ft_isalpha(-1) == 0);
	CU_ASSERT(ft_isalpha(128) == 0);
}

void	test_ft_isdigit(void)
{
	CU_ASSERT(ft_isdigit('0') == 1);
	CU_ASSERT(ft_isdigit('5') == 1);
	CU_ASSERT(ft_isdigit('9') == 1);

	CU_ASSERT(ft_isdigit('a') == 0);
	CU_ASSERT(ft_isdigit('Z') == 0);
	CU_ASSERT(ft_isdigit(' ') == 0);
	CU_ASSERT(ft_isdigit('\n') == 0);
	CU_ASSERT(ft_isdigit('/') == 0);

	CU_ASSERT(ft_isdigit(-1) == 0);
	CU_ASSERT(ft_isdigit(128) == 0);
}

void	test_ft_isascii(void)
{
	CU_ASSERT(ft_isascii('0') == 1);
	CU_ASSERT(ft_isascii('9') == 1);

	CU_ASSERT(ft_isascii('A') == 1);
	CU_ASSERT(ft_isascii('Z') == 1);

	CU_ASSERT(ft_isascii('a') == 1);
	CU_ASSERT(ft_isascii('z') == 1);

	CU_ASSERT(ft_isascii(' ') == 1);
	CU_ASSERT(ft_isascii('!') == 1);
	CU_ASSERT(ft_isascii('\n') == 1);
	CU_ASSERT(ft_isascii('\t') == 1);

	CU_ASSERT(ft_isascii(0) == 1);
	CU_ASSERT(ft_isascii(127) == 1);

	CU_ASSERT(ft_isascii(-1) == 0);
	CU_ASSERT(ft_isascii(128) == 0);
	CU_ASSERT(ft_isascii(255) == 0);
}

void	test_ft_isprint(void)
{
	CU_ASSERT(ft_isprint(' ') == 1);
	CU_ASSERT(ft_isprint('!') == 1);
	CU_ASSERT(ft_isprint('+') == 1);
	CU_ASSERT(ft_isprint('.') == 1);
	CU_ASSERT(ft_isprint('/') == 1);
	CU_ASSERT(ft_isprint(':') == 1);
	CU_ASSERT(ft_isprint('@') == 1);
	CU_ASSERT(ft_isprint('~') == 1);

	CU_ASSERT(ft_isprint('0') == 1);
	CU_ASSERT(ft_isprint('9') == 1);
	CU_ASSERT(ft_isprint('A') == 1);
	CU_ASSERT(ft_isprint('Z') == 1);
	CU_ASSERT(ft_isprint('a') == 1);
	CU_ASSERT(ft_isprint('z') == 1);

	CU_ASSERT(ft_isprint('\0') == 0);
	CU_ASSERT(ft_isprint('\t') == 0);
	CU_ASSERT(ft_isprint('\n') == 0);
	CU_ASSERT(ft_isprint('\x1b') == 0);
	CU_ASSERT(ft_isprint(-1) == 0)
}

void	test_ft_isalnum(void)
{
	CU_ASSERT(ft_isalnum('0') == 1);
	CU_ASSERT(ft_isalnum('5') == 1);
	CU_ASSERT(ft_isalnum('9') == 1);

	CU_ASSERT(ft_isalnum('A') == 1);
	CU_ASSERT(ft_isalnum('M') == 1);
	CU_ASSERT(ft_isalnum('Z') == 1);
	CU_ASSERT(ft_isalnum('a') == 1);
	CU_ASSERT(ft_isalnum('m') == 1);
	CU_ASSERT(ft_isalnum('z') == 1);

	CU_ASSERT(ft_isalnum(' ') == 0);
	CU_ASSERT(ft_isalnum('!') == 0);
	CU_ASSERT(ft_isalnum('@') == 0);
	CU_ASSERT(ft_isalnum('\n') == 0);
	CU_ASSERT(ft_isalnum(-1) == 0);
	CU_ASSERT(ft_isalnum(128) == 0);
}

void	test_ft_memcpy(void)
{
	char src[] = "Hello, World!";
	char dest[20];
	char dest_std[20];

	ft_memcpy(dest, src, strlen(src) + 1);
	memcpy(dest_std, src, strlen(src) + 1);
	CU_ASSERT(memcmp(dest, dest_std, strlen(src) + 1) == 0);

	ft_memcpy(dest, src, 5);
	memcpy(dest_std, src, 5);
	CU_ASSERT(memcmp(dest, dest_std, 5) == 0);

	ft_memcpy(dest, src, 0);
	memcpy(dest_std, src, 0);
	CU_ASSERT(memcmp(dest, dest_std, strlen(src) + 1) == 0);

	unsigned char arr1[] = {1, 2, 3, 4, 5};
	unsigned char arr2[5];
	ft_memcpy(arr2, arr1, 5);
	CU_ASSERT(memcmp(arr1, arr2, 5) == 0);

	CU_ASSERT(ft_memcpy(dest, src, 5) == dest);
}

void	test_ft_memmove_no_overlap_zero_len(void)
{
	char src[] = "1234567890";
	char dest[20];
	ft_memmove(dest, src, 11);
	CU_ASSERT_EQUAL(memcmp(dest, src, 11), 0);

	char buffer1[10] = "abcde";
	char buffer2[10] = "abcde";
	ft_memmove(buffer1, buffer2, 0);
	CU_ASSERT_STRING_EQUAL(buffer1, buffer2);
}

void	test_ft_memmove_overlap_right_left(void)
{
	char buffer1[20] = "Hello, World!";
	ft_memmove(buffer1 + 7, buffer1, 6);
	CU_ASSERT_NSTRING_EQUAL(buffer1 + 7, "Hello,", 6);

	char buffer2[20] = "Hello, World!";
	ft_memmove(buffer2, buffer2 + 7, 6);
	CU_ASSERT_NSTRING_EQUAL(buffer2, "World!", 6);
}

void	test_ft_memmove_same_ptr(void)
{
	char buf[10];
	char src[] = "12345";
	void* ret = ft_memmove(buf, src, 6);
	CU_ASSERT_PTR_EQUAL(ret, buf);
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
