/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:40:57 by melghoud          #+#    #+#             */
/*   Updated: 2021/03/11 11:41:01 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H


# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# define MAX_HEIGHT 1440
# define MAX_WIDTH 2560
typedef     struct  s_args
{
    width.res;
    height.res;
    no.path;
    so.path;
    we.path;
    ea.path;
    sp.path;
    floor.r;
    floor.g;
    floor.b;
    ceil.r;
    ceil.g;
    ceil.b;
}                   t_args;

int		get_next_line(int fd, char **line);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     main(int argc, char **argv);

#endif
