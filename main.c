#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

// void	test_atoi(void)
// {
// 	char *tests[] = {
// 		"0",
// 		"42",
// 		"-42",
// 		" \t\n\v\f\r +42",  // POSIX whitespace & positive sign
// 		"  -42abc",         // Number followed by text
// 		"abc42",            // Text before number
// 		" --42",            // Double sign (should fail to 0)
// 		"2147483647",       // INT_MAX
// 		"-2147483648",      // INT_MIN
// 		"-99999999999999900000",
// Extreme Overflow (Undefined Behavior territory)
// 		NULL                // Array terminator
// 	};

// 	int i = 0;
// 	while (tests[i] != NULL)
// 	{
// 		int sys = atoi(tests[i]);
// 		int ft = ft_atoi(tests[i]);
// 		if (sys == ft)
// 			printf(GREEN "[OK] " RESET "Input: \"%s\" | sys: %d | ft: %d\n",
				tests[i], sys, ft);
				// 		else
				// 			printf(RED "[KO] " RESET "Input: \"%s\" | sys:
								%d | ft: %d\n",
				tests[i], sys, ft);
				// 		i++;
				// 	}
				// }

				// void test_ctype(void)
				// {
				// 	int errors = 0;
				// 	// Loop through EOF (-1) and the entire extended ASCII table (up to 255)
				// 	for (int i = -1; i <= 255; i++)
				// 	{
				// 		// Native libc functions return NON-ZERO for true,
							not necessarily 1.
				// 		// We normalize them to 1 or 0 using !! (double negation) to strictly compare boolean logic.
				// 		if (!!isalpha(i) != !!ft_isalpha(i)) { printf(RED "[KO] ft_isalpha failed on ASCII:
			%d\n" RESET, i); errors++; }
// 		if (!!isdigit(i) != !!ft_isdigit(i)) { printf(RED "[KO] ft_isdigit failed on ASCII:
			%d\n" RESET, i); errors++; }
// 		if (!!isalnum(i) != !!ft_isalnum(i)) { printf(RED "[KO] ft_isalnum failed on ASCII:
			%d\n" RESET, i); errors++; }
// 		if (!!isascii(i) != !!ft_isascii(i)) { printf(RED "[KO] ft_isascii failed on ASCII:
			%d\n" RESET, i); errors++; }
// 		if (!!isprint(i) != !!ft_isprint(i)) { printf(RED "[KO] ft_isprint failed on ASCII:
			%d\n" RESET, i); errors++; }
// 	}

// 	if (errors == 0)
// 		printf(GREEN "[OK] " RESET "All ctype functions (isalpha, isdigit,
			isalnum, isascii, isprint) passed for range [-1 to 255].\n");

// 	int extreme_cases[] = {1024, -42, 2147483647, -2147483648};
// 	for (int j = 0; j < 4; j++)
// 	{
// 		if (!!isalpha(extreme_cases[j]) != !!ft_isalpha(extreme_cases[j]))
// 			printf(RED "[KO] ft_isalpha failed on extreme int: %d\n" RESET,
				extreme_cases[j]);
			// 		else
			// 			printf(GREEN "[OK] " RESET "ft_isalpha handled extreme int:
							%d\n",
				extreme_cases[j]);
				// 	}
				// }

				// void	test_strlen(void)
				// {
				// 	printf("\n--- TESTING FT_STRLEN ---\n");
				// 	char *tests[] = {
				// 		"Hello World",
				// 		"",
				// 		"1337\0Hidden",
				// 		"   spaces",
				// 		NULL
				// 	};

				// 	int i = 0;
				// 	while (tests[i])
				// 	{
				// 		size_t sys_res = strlen(tests[i]);
				// 		size_t ft_res = ft_strlen(tests[i]);

				// 		if (sys_res == ft_res)
				// 			printf(GREEN "[OK] " RESET "Length: %zu\n", ft_res);
				// 		else
				// 			printf(RED "[KO] " RESET "Input: \"%s\" | sys:
								%zu | ft: %zu\n",
				tests[i], sys_res, ft_res);
				// 		i++;
				// 	}
				// }

				// void test_memset_bzero(void)
				// {
				// 	printf("\n--- TESTING MEMSET & BZERO ---\n");

				// 	// Create two identical memory blocks initialized with 'X'
				// 	char sys_buf[15] = "XXXXXXXXXXXXXX";
				// 	char ft_buf[15]  = "XXXXXXXXXXXXXX";

				// 	// TEST 1: ft_memset
				// 	// We overwrite exactly 5 bytes in the middle of the string with 'O'
				// 	void *sys_ptr = memset(sys_buf + 2, 'O', 5);
				// 	void *ft_ptr  = ft_memset(ft_buf + 2, 'O', 5);

				// 	// Compare the memory block AND the returned pointer
				// 	if (memcmp(sys_buf, ft_buf, 15) == 0 && sys_ptr == (sys_buf
							+ 2)
		&& ft_ptr == (ft_buf + 2))
// 		printf(GREEN "[OK] " RESET "ft_memset correctly overwrote memory and returned the correct pointer:
			%s\n", ft_buf);
// 	else
// 		printf(RED "[KO] " RESET "ft_memset failed. sys: %s | ft: %s\n",
			sys_buf, ft_buf);

		// 	// TEST 2: ft_bzero
		// 	// We zero out exactly 3 bytes at the start of the string
		// 	bzero(sys_buf, 3);
		// 	ft_bzero(ft_buf, 3);

		// 	if (memcmp(sys_buf, ft_buf, 15) == 0)
		// 		printf(GREEN "[OK] " RESET "ft_bzero correctly zeroed memory without buffer overflow.\n");
		// 	else
		// 		printf(RED "[KO] " RESET "ft_bzero failed memory comparison.\n");
		// }

		// // void test_memcpy(void)
		// // {
		// // 	printf("\n--- TESTING MEMCPY ---\n");
		// // 	char src[] = "1337_Network";

		// // 	// Sandbox: 20 bytes initialized to 'X'
		// // 	char sys_buf[20] = "XXXXXXXXXXXXXXXXXXX";
		// // 	char ft_buf[20]  = "XXXXXXXXXXXXXXXXXXX";

		// // 	// TEST 1: The Partial Sandbox Copy
		//
				// 	// Copy exactly 4 bytes ("1337") into the middle of the 'X' buffer
		// // 	void *sys_ptr = memcpy(sys_buf + 2, src, 4);
		// // 	void *ft_ptr  = ft_memcpy(ft_buf + 2, src, 4);

		// // 	if (memcmp(sys_buf, ft_buf, 20) == 0 && sys_ptr == (sys_buf + 2)
		&& ft_ptr == (ft_buf + 2))
//
			// 		printf(GREEN "[OK] " RESET "Standard memcpy passed (Contents & Pointer preserved).\n");
// // 	else
// // 		printf(RED "[KO] " RESET "Standard memcpy failed.\n");

// // 	// TEST 2: The Zero-Length Trap
// // 	char z_sys[5] = "AAAA";
// // 	char z_ft[5]  = "AAAA";
// // 	memcpy(z_sys, "BBBB", 0);
// // 	ft_memcpy(z_ft, "BBBB", 0);

// // 	if (memcmp(z_sys, z_ft, 5) == 0)
// // 		printf(GREEN "[OK] " RESET "Zero-length memcpy passed.\n");
// // 	else
// // 		printf(RED "[KO] " RESET "Zero-length memcpy modified memory!\n");
// // }

// void	test_memset(void)
// {
// 	char	ft[64] = {};
// 	char	sys[64] = {};
// 	ft[63] = '\0';
// 	sys[63] = '\0';

// 	ft_memset(ft, 65, 4);
// 	memset(sys, 65, 4);

// 	printf("ft : %s\nsys : %s\n", ft, sys);
// }

// void	test_bzero(void)
// {
// 	char	ft[10] = "Hello";
// 	char	sys[10] = {"hello"};

// 	ft_bzero(ft, 11);
// 	bzero(sys, 11);

// 	printf("ft: %s,\n sys: %s\n", ft, sys);
// }

// void	test_memcpy(void)
// {
// 	char	dest[10] = "asdfghjk22";
// 	char	*src = "hi there .";
// 	char	*sys_out = memcpy(NULL, NULL, 10);
// 	if (!sys_out)
// 		printf("is null");
// 	else
// 		printf("sys_out : %s", sys_out);

// }

// #include <stdio.h>

// int main()
// {
// 	char *s1 = "ba";
// 	char *s2 = "b";
// 	char *s3 = "a";
// 	printf("%d\n",memcmp(s1, s3, -1));
// 	printf("%p       %p\n", s1, s3);
// 	printf("%s       %s\n", s1, s3);

// }

// void	test_strchr(void)
// {
// 	const char *str = NULL;
// 	char	c = 'i';

// 	printf("%s\n%s\n", strchr(str, c), ft_strchr(str, c));
// 	printf("%s\n%s\n", strrchr(str, c), ft_strrchr(str, c));
// }

// void	test_strncmp(void)
// {
// 	const char	*s1 = "It was a happy smile";
// 	const char	*s2 = "It was a happy smile";
// 	printf("sys : %d\n", strncmp(s1, s2, 21));
// 	printf("ft : %d\n", ft_strncmp(s1, s2, 21));
// }

// char	*tt_strnstr(const char *big, const char *little, size_t len)
// {
// 	size_t	i = 0;
// 	size_t	j;
// 	if (!little[0])
// 		return ((char *)big);
// 	while (big[i])
// 	{
// 		j = 0;
// 		while (big[i + j] == little[j] && (i + j) < len)
// 		{
// 			j++;
// 			if (!little[j])
// 				return ((char *)&big[i]);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// #include <bsd/string.h>
// void	test_strnstr(void)
// {
// 	char *s1 = "It was a happy smile";
// 	char *s2 = "";
// 	printf("sys : %s\n", strnstr(s1, s2, 21));
// 	printf("ft : %s\n", ft_strnstr(s1, s2, 21));
// 	printf("tt : %s\n", tt_strnstr(s1, s2, 21));
// }

// size_t	tt_strlcpy(char *dst, char *src, size_t size)
// {
// 	size_t s_len = ft_strlen(src);
// 	size_t i = 0;
// 	if (size == 0)
// 		return (s_len);
// 	while (i < size - 1 && src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (s_len);
// }
// #include <bsd/string.h>
// void	test_strlcpy(void)
// {
// 	char ttdst[14] = "Celestial";
// 	char ftdst[14] = "Celestial";
// 	char sysdst[14] = "Celestial";
// 	char *src = "Lord of Mysteries";
// 	// printf("%zu : %s\n", ft_strlcpy(ftdst, src, 14), ftdst);
// 	// printf("%zu : %s\n", tt_strlcpy(ttdst, src, 14), ttdst);
// 	printf("%zu : %s\n", strlcpy(sysdst, src, 41), sysdst);
// 	printf("%s\n", src);
// 	printf("%s\n", ttdst);
// 	printf("%s\n", ftdst);
// }

// size_t	tt_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t s_len = ft_strlen(src);
// 	size_t d_len = 0;
// 	size_t i = 0;
// 	while (d_len < size && dst[d_len])
// 		d_len++;
// 	if (d_len >= size)
// 		return(size + s_len);
// 	while((d_len + i) < size - 1 && src[i])
// 	{
// 		dst[d_len + i] = src[i];
// 		i++;
// 	}
// 	dst[d_len + i] = '\0';
// 	return (d_len + s_len);
// }

// void	test_strlcat(void)
// {
// 	char ttdst[28] = "Celestial";
// 	char ftdst[28] = "Celestial";
// 	char sysdst[28] = "Celestial";
// 	char *src = "Lord of Mysteries";
// 	printf("%zu : %s\n", ft_strlcat(ftdst, src, 14), ftdst);
// 	printf("%zu : %s\n", tt_strlcat(ttdst, src, 14), ttdst);
// 	printf("%zu : %s\n", strlcat(sysdst, src, 14), sysdst);
// 	// printf("%s\n", src);
// 	// printf("%s\n", ttdst);
// 	// printf("%s\n", ftdst);
// }

//

// static int	word_count(char const *s, char c)
// {
// 	int	is_word = 0;
// 	int	count = 0;
// 	while (*s)
// 	{
// 		if (*s != c && is_word == 0)
// 		{
// 			count++;
// 			is_word = 1;
// 		}
// 		else if (*s == c && is_word == 1)
// 			is_word = 0;
// 		s++;
// 	}
// 	return (count);
// }
// static char	*make_word(char const *s, char c)
// {
// 	int	i = 0;
// 	while (s[i] && s[i] != c)
// 		i++;
// 	return (ft_substr(s, 0, i));
// }
// char	**freee(char **strs, int n)
// {
// 	int i = 0;
// 	while (i < n)
// 		free(strs[i++]);
// 	free(strs);
// 	return (NULL);
// }
// char	**tt_split(char const *s, char c)
// {
// 	int		count = word_count(s, c);
// 	int		i = 0;
// 	char	**strs = malloc(sizeof(char *) * (count + 1));
// 	if (!strs)
// 		return (NULL);
// 	strs[count] = NULL;
// 	while (i < count)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		strs[i] = make_word(s, c);
// 		if (!strs[i])
// 			return (freee(strs, i));
// 		while (*s && *s != c)
// 			s++;
// 		i++;
// 	}
// 	return (strs);
// }
// void	test_split(char const *s, char c)
// {
// 	char	**strs = ft_split(s, c);
// 	if (!strs)
// 	{
// 		printf("allocation failed nig");
// 		return ;
// 	}
// 	int		i = 0;
// 	while (strs[i])
// 	{
// 		printf("%s\n", strs[i]);
// 		free(strs[i]);
// 		i++;
// 	}
// 	free(strs);
// }

// void	test_join(char *s1, char *s2)
// {
// 	printf("%s\n", ft_strjoin(s1, s2));
// }

// void	test_trim(char *s1, char *s2)
// {
// 	char *trim = ft_strtrim(s1, s2);
// 	printf("%s\n", trim);
// 	free(trim);
// }

int	main(int ac, char **av)
		{
			(void)ac;
			// test_atoi();
			// test_ctype();
			// test_strlen();
			// test_memset_bzero();
			// test_memcpy();
			// test_bzero();
			// test_memcpy();
			// char *s1 = NULL;
			// char *s2 = "b";
			// char *s3 = NULL;
			// printf("%d\n",memcmp(s1, s3, 2));
			// printf("%p       %p\n", s1, s3);
			// printf("%s       %s\n", s1, s3);
			// test_strchr();
			// test_strncmp();
			// test_strnstr();
			// test_strlcpy();
			// test_strlcat();
			// test_substr(av[1], ft_atoi(av[2]), 10);
			(void)av;
			// test_split(" terminal ff   g", ' ');
			// test_join(av[1], NULL);
			// test_trim(av[1], NULL);
			// ft_putstr_fd("this is an error", 2);
			return (0);
		}
