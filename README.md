*This project has been created as part of the 42 curriculum by imhsikko.*

# ft_printf

## Description

**ft_printf** is a recreation of the C standard library function `printf`. The goal is to learn how to use **variadic functions** (`va_list`, `va_start`, `va_arg`, `va_end`) and to build a clean, extensible function that parses a format string and prints formatted output.

The function is compiled into a static library, `libftprintf.a`, and has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed or `(-1)` if it fail, just like the original `printf`.

### Supported conversions

| Specifier | Description                                   |
|-----------|-----------------------------------------------|
| `%c`      | A single character                            |
| `%s`      | A string                                      |
| `%p`      | A pointer address in hexadecimal              |
| `%d`      | A signed decimal integer                      |
| `%i`      | A signed integer (decimal)                    |
| `%u`      | An unsigned decimal integer                   |
| `%x`      | An unsigned integer in lowercase hexadecimal  |
| `%X`      | An unsigned integer in uppercase hexadecimal  |
| `%%`      | A literal percent sign                        |


### Algorithm and design

1. `ft_printf` initializes a `va_list` with `va_start`.
2. It walks through the format string character by character.
3. Regular characters are written directly to standard output.
4. When a `%` is found, the next character is read, if it's among `"cspdiuxX%"`, then dispatched to the matching handler function (`ft_print_char`, `ft_print_str`, `ft_print_digit`, `ft_print_ptr`,  `ft_printnbr_base`). Otherwise, it's directly written to standard output.
5. Each handler writes its output with `ft_print_char` which uses `write` and returns the number of bytes written.
6. After `va_end`, the total of bytes written `(count)` is returned, or `(-1)` when failure.

**Why this approach?** A dispatcher plus small single-purpose handlers keeps each function short (Norm-friendly), makes it easy to add new conversions, and avoids any buffer management. Each call to `write` is simple and predictable, at the cost of making more system calls than a buffered implementation would.

## Instructions

### Compilation

Build the library from the root of the repository:

```bash
make
```

This produces `libftprintf.a`. Other useful rules:

```bash
make clean    # remove object files
make fclean   # remove object files and libftprintf.a
make re       # fclean + make
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are number %d!\n", "world", 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

### Project structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_char  # to print characters if (format == 'c')
└── ...            # one file per conversion handler
```

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [Variable Argument Lists](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
- (https://blog.nelhage.com/2010/10/amd64-and-va_arg/)
- [printf format specifiers (cppreference)](https://en.cppreference.com/w/c/io/fprintf)


### Use of AI

AI was used for:  understanding how `va_list` works, suggesting edge cases to test.
