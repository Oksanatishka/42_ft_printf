# 42_ft_printf
You have to recode the libc’s printf function.

Resources:

http://www.firmcodes.com/write-printf-function-c/

http://ftprintf.com/


HOW TO RUN:
1.	Go to the root directory.
2.	make re; gcc -L. -lftprintf *.c; ./a.out; rm a.out
OR
gcc -Wall -Werror -Wextra main.c libftprintf.a -Iincludes/

Mandatory part:

• You won’t do the buffer management in the printf function.

• You have to manage the following conversions: sSpdDioOuUxXcC

• You must manage %%

• You must manage the flags #0-+ and space

• You must manage the minimum field-width

• You must manage the precision

• You must manage the flags hh, h, l, ll, j, et z.
