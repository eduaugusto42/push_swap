*This project has been created as part of the 42 curriculum by eduaaugu.*

# Libft
A custom standard library implementation in C.

## Description
C programming can become quite tedious without access to useful standard library functions. Through this project, I reimplemented several of these functions from scratch in order to better understand how they work internally and how to use them effectively. The result is my own custom C library, which will serve as a foundation for many future projects.

### Functions implemented
**Part 1 - Libc functions** (reimplemented with `ft_` prefix):

| Function | Description |
|---|---|
| `ft_isalpha` | checks for an alphabetic character |
| `ft_isdigit` | checks for a digit (0 through 9) |
| `ft_isalnum` | checks for an alphanumeric character |
| `ft_isascii` | checks whether c fits  into  ASCII character set |
| `ft_isprint` | checks for any printable character including space |
| `ft_strlen` | calculates the length of the string excluding null |
| `ft_memset` | fills the first n bytes of memory area with a constant byte |
| `ft_bzero` | erases the data in n bytes memory by writing zeros |
| `ft_memcpy` | copies n bytes from memory |
| `ft_memmove` | copies n bytes from memory, but the memory areas may overlap |
| `ft_strlcpy` | copies up to size - 1 characters, NUL-terminating the result |
| `ft_strlcat` | appends the NUL-terminated string src to the end of dst |
| `ft_toupper` | if c is an lowercase letter, returns its uppercase equivalent |
| `ft_tolower` | if c is an uppercase letter, returns its lowercase equivalent |
| `ft_strchr` | returns a pointer to the first occurrence of c in the string |
| `ft_strrchr` | returns a pointer to the last occurrence of the c in the string |
| `ft_strncmp` | compares two strings |
| `ft_memchr` | scans the initial n bytes of the memory for the first instance of c |
| `ft_memcmp` | compares the first n bytes of the memory |
| `ft_strnstr` | locates the first occurrence of the string little in the string big |
| `ft_atoi` | converts the initial portion of the string to int |
| `ft_calloc` | allocates size bytes and returns a pointer to the allocated memory |
| `ft_strdup` | returns a pointer to a new string which is a duplicate of string s |

**Part 2 - Additional functions**

| Function | Description |
|---|---|
| `ft_substr` | returns a substring from the string s |
| `ft_strjoin` | returns a new string, the result of concatenating s1 and s2 |
| `ft_strtrim` | returns a copy of s with characters removed from start and end |
| `ft_split` | returns an array of strings by splitting s using c as a delimiter |
| `ft_itoa` | returns a string representing the integer received as an argument |
| `ft_strmapi` | applies the function f to each character of the string s |
| `ft_striteri` | applies f to each character of s, passing index as first argument |
| `ft_putchar_fd` | outputs the character c to the specified file descriptor |
| `ft_putstr_fd` | outputs the string s to the specified file descriptor |
| `ft_putendl_fd` | outputs s to the specified file descriptor followed by a newline |
| `ft_putnbr_fd` | outputs the integer n to the specified file descriptor |

**Part 3 - Linked list functions**

| Function | Description |
|---|---|
| `ft_lstnew` | returns a new node |
| `ft_lstadd_front` | adds the new node at the beginning of the list |
| `ft_lstsize` | counts the number of nodes in the list |
| `ft_lstlast` | returns the last node of a list |
| `ft_lstadd_back` | adds the new node at the end of the list |
| `ft_lstdelone` | takes a node and frees its content using the function del |
| `ft_lstclear` | deletes and frees the given node and all its successors |
| `ft_lstiter` | applies the function f to the content of each node |
| `ft_lstmap` | applies f to the content of each node and creates a new list |

## Usage Example
```c
#include "libft.h"

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello, Libft!");
	ft_putendl_fd(str, 1);
	free(str);
	return (0);
}
```
---
## Instructions
Clone this repository and run `make` in the project root:

```bash
git clone https://github.com/eduaugusto42/libft.git
cd libft
make
```

This will generate the libft.a static library file.

### Requirements
- `gcc` compiler
- `make`
- Unix-based OS (Linux or macOS)

### Available Makefile rules
To compile the library:
```bash
make
```

To remove object files:
```bash
make clean
```

To remove object files and the compiled library:
```bash
make fclean
```

To clean and compile again:
```bash
make re
```

To compile the bonus functions:
```bash
make bonus
```

The project is compiled using:
```bash
cc -Wall -Wextra -Werror
```
---
## Resources
### Documentation & References
- en.libft.pdf — 42 Libft subject
- [C Standard Library Reference — cppreference.com](https://en.cppreference.com/w/c) — comprehensive reference for all standard C functions
- [man pages online](https://man7.org/linux/man-pages/) — official manual pages for each function reimplemented
- [42 Docs — libft subject](https://github.com/42School/norminette) — Norminette rules
- [Libdf-god](https://github.com/PLEB42/libft-god) — testing suite for the project
* Peer discussions
---
## AI Usage
**ChatGPT (OpenAI)** was used during the development of this project for the following purposes:

- **Conceptual clarification** — understanding the difference between functions such as `strlcat` vs `strcat`, `memmove` vs `memcpy`, and `strmapi` vs `striteri`
- **Debugging assistance** — identifying edge cases (e.g., handling `\0` in `strchr`, null checks in `substr`)
- **README writing** — structuring and writing this documentation file

> AI was used exclusively as a learning and support tool. All code was written and understood by the author.
