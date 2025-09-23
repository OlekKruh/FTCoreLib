#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "libft.h"

void	test_ft_atoi(void);
void	test_ft_memset_full(void);
void	test_ft_memset_part(void);
void	test_ft_memset_zero_len(void);
void	test_ft_memset_same_ptr(void);
void	test_ft_bzero_full(void);
void	test_ft_bzero_part(void);
void	test_ft_calloc_full(void);
void	test_ft_calloc_zero(void);
void	test_ft_calloc_overflow(void);

int	main(void)
{
	CU_initialize_registry();

	CU_pSuite suite = CU_add_suite("LibFT Testing", 0, 0);
	CU_add_test(suite, "Test ft_atoi", test_ft_atoi);
	CU_add_test(suite, "Test ft_memset full", test_ft_memset_full);
	CU_add_test(suite, "Test ft_memset partial", test_ft_memset_part);
	CU_add_test(suite, "Test ft_memset zero length", test_ft_memset_zero_len);
	CU_add_test(suite, "Test ft_memset same pointer", test_ft_memset_same_ptr);
	CU_add_test(suite, "Test ft_bzero full", test_ft_bzero_full);
	CU_add_test(suite, "Test ft_bzero partial", test_ft_bzero_part);
	CU_add_test(suite, "Test ft_calloc full", test_ft_calloc_full);
	CU_add_test(suite, "Test ft_calloc return zero", test_ft_calloc_zero);
	CU_add_test(suite, "Test ft_calloc overflow", test_ft_calloc_overflow);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (0);
}

void	test_ft_atoi(void)
{
	CU_ASSERT(ft_atoi("-123") == -123);
	CU_ASSERT(ft_atoi("321") == 321);
	CU_ASSERT(ft_atoi("0") == 0);
	CU_ASSERT(ft_atoi("0042") == 42);
	CU_ASSERT(ft_atoi("0x2A") == 0);
	CU_ASSERT(ft_atoi("junk") == 0);
	CU_ASSERT(ft_atoi("2147483648") == -2147483648);
}

void	test_ft_memset_full(void)
{
	char buff1[10];
	char buff2[10];

	ft_memset(buff1, 'A', 10);
	memset(buff2, 'A', 10);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);
}

void	test_ft_memset_part(void)
{
	char buff1[10];
	char buff2[10];

	ft_memset(buff1, 'A', 5);
	memset(buff2, 'A', 5);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);
}

void	test_ft_memset_zero_len(void)
{
	char buff1[10];
	char buff2[10];

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

void	test_ft_bzero_full(void)
{
	char buff1[10];
	char buff2[10];

	memset(buff1, 'x', 10);
	memset(buff2, 'x', 10);

	ft_bzero(buff1, 10);
	bzero(buff2, 10);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);

}
void	test_ft_bzero_part(void)
{
	char buff1[10];
	char buff2[10];

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