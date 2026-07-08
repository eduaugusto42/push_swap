
*This project has been created as part of the 42 curriculum by eduaaugu.*

# ft_printf

A custom implementation of the standard C `printf` function.

## Description

Formatted output is a fundamental feature of the C standard library. Through this project, I reimplemented a simplified version of the `printf` function from scratch using variadic functions.

The goal of this project was to gain a deeper understanding of:

* Variadic functions (`stdarg.h`)
* Type promotion in C
* Numeric base conversions
* Recursive number printing
* Formatted output handling

This implementation supports the mandatory conversion specifiers required by the 42 subject and is built on top of my own Libft library.

### Supported Conversions

| Specifier | Description                                            |
| --------- | ------------------------------------------------------ |
| `%c`      | prints a single character                              |
| `%s`      | prints a string                                        |
| `%p`      | prints a pointer address in hexadecimal format         |
| `%d`      | prints a decimal (base 10) integer                     |
| `%i`      | prints an integer in base 10                           |
| `%u`      | prints an unsigned decimal integer                     |
| `%x`      | prints a hexadecimal number using lowercase characters |
| `%X`      | prints a hexadecimal number using uppercase characters |
| `%%`      | prints a percent sign                                  |

### Implementation Notes

This implementation uses:

* A dispatcher function to route format specifiers to the appropriate printer
* Recursive printing for unsigned integers and hexadecimal values
* A shared hexadecimal printer used by `%x`, `%X`, and `%p`
* Custom output functions provided by Libft
* Variadic argument handling through `va_start`, `va_arg`, and `va_end`

Special cases handled include:

* `NULL` strings printed as `(null)`
* `NULL` pointers printed as `(nil)`
* Uppercase and lowercase hexadecimal output
* Correct return values matching the number of printed characters

## Usage Example

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "world");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hex: %x\n", 255);
	return (0);
}
```

Output:

```text
Hello world!
Number: 42
Hex: ff
```

---

## Instructions

Clone this repository and run `make` in the project root:

```bash
git clone https://github.com/eduaugusto42/ft_printf.git
cd ft_printf
make
```

This will generate the `libftprintf.a` static library.

### Requirements

* `gcc` compiler
* `make`
* Unix-based OS (Linux or macOS)

### Available Makefile Rules

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

The project is compiled using:

```bash
cc -Wall -Wextra -Werror
```

---

## Project Structure

```text
.
├── ft_printf.c
├── ft_printf.h
├── ft_print_char.c
├── ft_print_str.c
├── ft_print_dec.c
├── ft_print_unsigned.c
├── ft_print_hex.c
├── ft_print_pointer.c
├── Makefile
└── libft/
```

---

## Resources

### Documentation & References

* ft_printf subject — 42 School
* https://en.cppreference.com/w/c/io/fprintf
* https://man7.org/linux/man-pages/man3/printf.3.html
* https://en.cppreference.com/w/c/variadic
* Peer discussions
* ft_printf testers and community resources

---

## AI Usage

**ChatGPT (OpenAI)** was used during the development of this project for the following purposes:

* Conceptual clarification regarding variadic functions and argument promotion
* Understanding hexadecimal and pointer formatting
* Debugging edge cases involving `NULL`, `%p`, `%u`, and recursive printing
* README writing and documentation

> AI was used exclusively as a learning and support tool. All code was written and understood by the author.
