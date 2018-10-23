/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:27:19 by obibik            #+#    #+#             */
/*   Updated: 2018/10/16 12:27:23 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** setlocale - natural language formatting for C (#include <locale.h>)
*/

#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    // char *string = "hello";

   // printf ("Characters: %c %c \n", 'a', 65);
   // printf ("Decimals: %d %ld\n", 1977, 650000L);
   // printf ("Preceding with blanks: %10d \n", 1977);
   // printf ("Preceding with zeros: %010d \n", 1977);
   // printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   // printf ("Width trick: %*d \n", 10, 10);
  printf ("Width trick: %*d \n", "f", 50, 10);
   // printf ("%s \n", "string");
   // printf("double  percent sign %%\n");
   // printf("Pointer address %p or %#lx\n", &string, &string );

   // ft_printf("------------------------------------------\n");

   
   ft_printf ("Characters: %c %c \n", 'a', 65);
 //   ft_printf ("Decimals: %d %D\n", 1977, 650000L);
 //   ft_printf ("Preceding with blanks: %10d \n", 1977);
 //   ft_printf ("Preceding with zeros: %010d \n", 1977);
 //   ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
 //   ft_printf ("Width trick: %*d \n", 10, 10);
 //   ft_printf ("%s \n", "string");
 //   ft_printf("double  percent sign %%\n");
 //   ft_printf("Pointer address %p or %#lx\n", &string, &string );
 //   ft_printf ("Big S %S \n", L"h");         //representation letter as wide char

 //   ft_printf("------------------------------------------\n");
 //    	//Standard printf
	// printf("%#10.7x, %#12o, % hhd, %c, %+.i, %-.i, %010u \n", 6996, 654, '*', 42, 21, -21, 99999999);

	// //my printf
	// ft_printf("%#10.7x, %#12o, % hhd, %c, %+.i, %-.i, %010u \n", 6996, 654, '*', 42, 21, -21, 99999999);

 //    ft_printf("------------------------------------------\n");

 //    ft_printf("%%\n");
 //    ft_printf("%d\n", 42);
 //    ft_printf("%d%d\n", 42, 41);
 //    ft_printf("%d%d%d\n", 42, 43, 44);
 //    ft_printf("%ld\n", 2147483647);
 //    ft_printf("%lld\n", 9223372036854775807);
 //    ft_printf("%x\n", 505);
 //    ft_printf("%X\n", 505);
 //    ft_printf("%p\n", &ft_printf);
 //    ft_printf("%20.15d\n", 54321);
 //    ft_printf("%-10d\n", 3);
 //    ft_printf("% d\n", 3);
 //    ft_printf("%+d\n", 3);
 //    ft_printf("%010d\n", 1);
 //    ft_printf("%hhd\n", 0);
 //    ft_printf("%jd\n", 9223372036854775807);
 //    ft_printf("%zd\n", 4294967295);
 //    ft_printf("%U\n", 4294967295);
 //    ft_printf("%u\n", 4294967295);
 //    ft_printf("%o\n", 40);
 //    ft_printf("%%#08x\n", 42);
 //    printf("%%#08x\n", 42);
 //    ft_printf("%x\n", 1000);
 //    ft_printf("%#X\n", 1000);
 //    ft_printf("%s\n", NULL);
 //    ft_printf("%s%s\n", "test", "test");
 //     ft_printf("%s%s%s\n", "test", "test", "test");
 //    ft_printf("%b\n",4);
 //    ft_printf("%C\n", 42);
    //printf("%S\n", L"Á±≥");
   return 0;
}
