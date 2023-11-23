/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/08 10:59:06 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_formats(const char *s, va_list *v)
{
	const int		fd = STDOUT_FILENO;
	unsigned int	counter;

	counter = 0;
	if (*s == 'c')
		counter += ft_putchar_fd(va_arg(*v, int), fd);
	else if (*s == 's')
		counter += ft_putstr_fd(va_arg(*v, char *), fd);
	else if (*s == 'p')
		counter += ft_illtohex_fd(va_arg(*v, unsigned long long), *s, 16, fd);
	else if (*s == 'd' || *s == 'i')
		counter += ft_putnbr_fd(va_arg(*v, int), fd);
	else if (*s == 'u')
		counter += ft_putnbr_fd(va_arg(*v, unsigned int), fd);
	else if (*s == 'x' || *s == 'X')
		counter += ft_illtohex_fd(va_arg(*v, unsigned int), *s, 16, fd);
	else if (*s == '%')
		counter += ft_putchar_fd('%', fd);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	static const char	formats[] = "cspdiuxX%";
	int					counter;
	va_list				args;

	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && ft_strchr(formats, *(format + 1)) != 0)
		{
			counter += ft_print_formats(format + 1, &args);
			format++;
		}
		else if (*format == '%' && ft_strchr(formats, *(format + 1) == 0))
			ft_putstr_fd("invalid...", STDOUT_FILENO);
		else
			counter += ft_putchar_fd(*format, STDOUT_FILENO);
		format++;
	}
	va_end(args);
	return (counter);
}
