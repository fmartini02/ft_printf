/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prova.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:02 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/12 15:54:40 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    main()
{
    char    *str;
    char    c;
    int        i;
    float    f;
    unsigned int    ui;
    int    hex;
    int    HEX;
    void    *ptr;

    str = "ciao";
    c = 'c';
    i = +42;
    f = 3.14;
    ui = 43;
    hex = 0x2a;
    HEX = 0x2A;
    ptr = &i;

    printf("Hello World\n\n");
    printf("%s\n\n", str);
    printf("%c\n\n", c);
    printf("%d\n\n", i);
    printf("%f\n\n", f);
    printf("%u\n\n", ui);
    printf("%x\n\n", hex);
    printf("%X\n\n", HEX);
    printf("%p\n\n", ptr);
    printf("%%\n\n");
    printf("%010d\n\n", i);
    printf("%-5d\n\n", i);
    printf("%#x\n\n", hex);
    printf("%#X\n\n", HEX);
    printf("%+i\n\n", i);
    printf("%.4f\n\n", f);
}
