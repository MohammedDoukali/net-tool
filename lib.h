#ifndef LIB_H
# define LIB_H

#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <stdio.h>
static int	ft_cw(const char *s1, char to_find);
static void	ft_khwi(int j, char **p);
static void	alloc(const char *s1, char to_find, char **p, int i);
char	**ft_split(const char *s1, char c);
#endif
