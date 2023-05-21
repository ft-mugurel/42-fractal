/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:23 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef short	t_fool;

enum e_boolstruc {malse = 0, mrue = ~0};

typedef struct t_list
{
	t_fool	numbertoken;
	t_fool	numbertoken2;
	t_fool	minustoken;
	t_fool	plustoken;
	t_fool	zerotoken;
	t_fool	hastagtoken;
	t_fool	dottoken;
	t_fool	spacetoken;
	int		number;
	int		number2;
	char	*after;
	char	firstafter;
	t_fool	printed;
	int		retlen;
}			t_printf;

int		ft_printf(const char *str, ...);
void	parsing(char *str, va_list args, t_printf *printfstruct);
int		pars(va_list args, t_printf *printfstruct);
void	pars0(va_list args, t_printf *printfstruct);
void	pars1(va_list args, t_printf *printfstruct);
void	pars2(va_list args, t_printf *printfstruct);
int		c(int args, t_printf *ps);
int		s(char *str, t_printf *ps);
void	s2(char *str, t_printf *ps);
void	s3(char *str, t_printf *ps, int slen);
void	s4(char *str, t_printf *ps, int slen);
int		printnumber(int number, t_printf *printfstruct);
void	printnumber2(t_printf *ps, char *pthis, char *str, int nlen);
void	printnumber3(t_printf *ps, char *pthis, int nlen, int number);
void	printnumber4(t_printf *ps, int nlen);
void	printnumber5(t_printf *ps, int nlen, int number);
void	printnumber6(t_printf *ps, char *pthis, int nlen, int number);
void	printnumber7(t_printf *ps, char *pthis, int nlen, int number);
void	printnumber8(t_printf *ps, char *pthis, int nlen, int number);
void	printnumber9(t_printf *ps, char *pthis, int nlen, int number);
void	printnumber10(t_printf *ps, char *pthis, int nlen, int number);
void	printnumber11(t_printf *ps, char *pthis, int nlen, int number);
int		printnumber12(t_printf *ps, char *pthis, int nlen, int number);
int		u(unsigned int number, t_printf *ps);
void	u2(unsigned int number, t_printf *ps, int *nlen, char c);
void	u3(unsigned int number, t_printf *ps, int *nlen, char c);
int		x(unsigned int number, t_printf *ps);
void	x2(unsigned int number, t_printf *ps, int *nlen, char c);
void	x3(unsigned int number, t_printf *ps, int *nlen, char c);
int		h_x(unsigned int number, t_printf *ps);
void	h_x2(unsigned int number, t_printf *ps, int *nlen, char c);
void	h_x3(unsigned int number, t_printf *ps, int *nlen, char c);
int		p(unsigned long number, t_printf *ps);
void	p2(unsigned long number, t_printf *ps, int *nlen, char c);
int		ft_putstr_n(char *str, int n);
void	makeallfalse(t_printf *printfstruck);
void	numberflag1(char *number, t_printf *printfstruct);
void	numberflag2(char *number, t_printf *printfstruct);
int		putnc(int sc, char c);
int		change_sine(int n);
int		porz(int n);
int		printfsetup(char *pthis, t_printf *ps, int number);
void	dpc(t_printf *ps, char c);
void	hex_len(unsigned int nbr, char *base, int *nlen);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	hex_len_p(unsigned long nbr, char *base, int *nlen);
void	ft_putnbr_base_p(unsigned long nbr, char *base);
void	num_len(unsigned int nb, int *nlen);
void	unsigned_base(unsigned int nb);
void	ft_putchar(char c);
int		putnil(void);
int		hexprefix(void);

#endif // FT_PRINTF_H
