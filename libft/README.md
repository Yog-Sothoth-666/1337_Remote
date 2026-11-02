*This project has been created as part of the 42 curriculum by ykhaldou.*

# Libft

## Description

**Libft** is the very first project in the 42 curriculum. The goal of this project is to recreate essential functions from the standard C library (`libc`) along with additional utility functions and linked list manipulation tools.

In C programming, standard library routines provide common operations such as memory management, string manipulation, and input/output. By re-implementing these functions from scratch without relying on pre-existing library abstractions, this project provides a deep understanding of:
- Low-level memory manipulation and buffer boundaries
- Pointer arithmetic and data representation in memory
- Dynamic memory allocation (`malloc`, `free`) and leak prevention
- Robust edge-case handling (e.g., buffer overflows, integer limits, NULL pointers)
- Algorithmic implementation of fundamental data structures

The resulting static library, `libft.a`, serves as a foundational toolkit that can be reused across future c projects.

---

## Library Description

The library comprises 43 functions organized into three distinct parts: standard libc re-implementations, additional utility functions, and linked list functions.

### 1. Standard C Library Functions (`libc`)

These functions reproduce the behavior of their standard POSIX / C library counterparts:

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_isalpha` | `int ft_isalpha(int c);` | Tests whether `c` is an alphabetic character (`A-Z`, `a-z`). |
| `ft_isdigit` | `int ft_isdigit(int c);` | Tests whether `c` is a digit (`0-9`). |
| `ft_isalnum` | `int ft_isalnum(int c);` | Tests whether `c` is alphanumeric (`ft_isalpha` or `ft_isdigit`). |
| `ft_isascii` | `int ft_isascii(int c);` | Tests whether `c` fits in the ASCII range (0 to 127). |
| `ft_isprint` | `int ft_isprint(int c);` | Tests whether `c` is any printable character, including space. |
| `ft_toupper` | `int ft_toupper(int c);` | Converts a lowercase letter to its uppercase equivalent. |
| `ft_tolower` | `int ft_tolower(int c);` | Converts an uppercase letter to its lowercase equivalent. |
| `ft_strlen` | `size_t ft_strlen(const char *s);` | Computes the length of string `s` up to the terminating null byte. |
| `ft_memset` | `void *ft_memset(void *b, int c, size_t n);` | Fills the first `n` bytes of memory area `b` with constant byte `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n);` | Erases data in the first `n` bytes of memory area `s` by setting them to zero. |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from `src` to `dest` (memory areas must not overlap). |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n);` | Copies `n` bytes from `src` to `dest` safely handling overlapping regions. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copies up to `size - 1` characters from `src` to `dst`, NUL-terminating the result. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Appends `src` to `dst` ensuring total string size is at most `size - 1` and NUL-terminated. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c);` | Returns a pointer to the first occurrence of character `c` in `s`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c);` | Returns a pointer to the last occurrence of character `c` in `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares at most `n` bytes between strings `s1` and `s2`. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n);` | Scans the initial `n` bytes of memory area `s` for the first instance of byte `c`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares byte strings `s1` and `s2` over `n` bytes. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len);` | Locates the first occurrence of `little` inside `big`, searching at most `len` characters. |
| `ft_atoi` | `int ft_atoi(const char *nptr);` | Converts the initial portion of the string `nptr` to an integer. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size);` | Allocates memory for an array of `nmemb` elements of `size` bytes each, initialized to 0. |
| `ft_strdup` | `char *ft_strdup(const char *s);` | Duplicates string `s` into dynamically allocated memory. |

### 2. Additional Utility Functions

These functions provide supplemental functionality not present in standard libc, or present in a different form:

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring from string `s`, starting at index `start` with maximum length `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates and returns a new string resulting from the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Allocates and returns a copy of `s1` with characters specified in `set` trimmed from the beginning and end. |
| `ft_split` | `char **ft_split(char const *s, char c);` | Splits `s` into an array of strings using character `c` as delimiter, terminated with a `NULL` pointer. |
| `ft_itoa` | `char *ft_itoa(int n);` | Allocates and returns a string representation of integer `n`, correctly supporting negative numbers and `INT_MIN`. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Creates a new string by applying function `f` to each character of string `s` (passing its index). |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Applies function `f` in-place to each character of string `s` by passing its address and index. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Writes character `c` to the given file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Writes string `s` to the given file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Writes string `s` followed by a newline (`\n`) to the given file descriptor `fd`. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Writes integer `n` to the given file descriptor `fd`. |

### 3. Linked List Functions

These functions implement operations for manipulating linked lists based on the following node structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Allocates and returns a new list element with `content` initialized and `next` set to `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds element `new` at the beginning of the list. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst);` | Counts and returns the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Traverses and returns the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Appends element `new` at the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees the memory of the node's content using `del`, then frees the node itself. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees every node in the list using `del` and sets the list pointer to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates the list and invokes function `f` on the content of every node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates `lst`, applies `f` to create new node contents, and returns a new list (cleans up if allocation fails). |

---

## Instructions

### Requirements
- **Compiler**: `cc` / `clang`
- **Build tool**: `make`
- **Operating System**: Linux

### Compilation Rules

The included `Makefile` compiles all C source files with the compilation flags `-Wall -Wextra -Werror` and packages the object files into the archive `libft.a`:

```bash
# Build the library libft.a
make

# Equivalent to make
make all

# Delete all generated object files (.o)
make clean

# Delete object files and the compiled archive libft.a
make fclean

# Rebuild the library from scratch (runs fclean then all)
make re
```

### Linking with Libft in a Project

To use Libft in your C project, include `libft.h` in your source files and link against `libft.a`:

1. Include the header file:
   ```c
   #include "libft.h"
   ```

2. Compile your program alongside `libft.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c libft.a -o my_program
   ```

---

## Resources

### References
- **POSIX & Linux Manual Pages**
- **BSD Implementations**
- **42 School**:
  - Libft subject specifications and 42 Norminette guidelines, and peer experiences with correction and code testing and actual things to look out for and to not look out for.
- **42-cursus-gitbook**
- **Reddit/StackOverflow**

---

### AI Usage

Artificial Intelligence was utilized during the development and documentation phases of this project in the following capacities:
- **Edge Case & Boundary Analysis**: Formulating edge case scenarios for testing, such as overlapping memory buffers in `ft_memmove`, boundary tests for buffer termination in `ft_strlcat`/`ft_strlcpy`, and integer minimums (`-2147483648`) in `ft_itoa` and `ft_atoi`.
- **General c Behavior**: By asking questions about subjects I found vague and/or asking for quizes on certain parts.
- **Defensive Memory Auditing**: Reviewing my logic in allocation-heavy routines (specifically verifying leak prevention on allocation failures in `ft_split` and `ft_lstmap`).
- **Documentation & Presentation**: Structuring, drafting, and proofreading this `README.md` file to ensure comprehensive coverage, clear function categorization, and adherence to 42 submission requirements.
