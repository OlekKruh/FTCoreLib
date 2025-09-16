#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "ft_lib.h"

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
void	test_ft_memset(void)
{
	char buff1[10];
	char buff2[10];

	ft_memset(buff1, 'A', 10);
	memset(buff2, 'A', 10);

	CU_ASSERT_NSTRING_EQUAL(buff1, buff2, 10);
	CU_ASSERT_PTR_EQUAL(ft_memset(buff1, 'B', 5), buff1);
}
int		main(void)
{
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("Lib Testing", 0, 0);
	CU_add_test(suite, "Test ft_atoi", test_ft_atoi);
	CU_add_test( suite, "Test ft_memset", test_ft_memset);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (0);
}