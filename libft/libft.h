/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:29:23 by tidigov           #+#    #+#             */
/*   Updated: 2022/04/16 16:24:15 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
char	*ft_get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif