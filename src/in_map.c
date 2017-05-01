/*
** in_map.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 15:57:12 2017 Remi Verny
** Last update Wed Apr 26 16:37:22 2017 Remi Verny
*/

#include <stdlib.h>
#include "my.h"
#include "mydefine.h"

static int	get_lines(const char *str)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == '\n')
	++nb;
    }
  return (nb);
}

void	loop_set_k(const char *str, int *tmp, int *k)
{
  *tmp = *k;
  while (str[*k] != '\0' && str[*k] != '\n')
    ++(*k);
}

void	map_fill_incr(int *tmp, int *j)
{
  ++(*tmp);
  ++(*j);
}

char	get_zero(int *k, int *i)
{
  ++(*k);
  ++(*i);
  return ('\0');
}

char	**in_map(char *str)
{
  int	i;
  int	j;
  int	k;
  int	tmp;
  char	**map;

  if ((map = malloc(sizeof(char *) * (get_lines(str) + 1))) == NULL)
    return ((char **) my_error2(MALLOC_MSG, NULL));
  i = 0;
  k = 0;
  while (i < get_lines(str))
    {
      loop_set_k(str, &tmp, &k);
      if ((map[i] = malloc(sizeof(char) * (k - tmp + 1))) == NULL)
	return ((char **) my_error2(MALLOC_MSG, NULL));
      j = 0;
      while (tmp < k)
	{
	  map[i][j] = str[tmp];
	  map_fill_incr(&tmp, &j);
	}
      map[i][j] = get_zero(&k, &i);
    }
  map[i] = '\0';
  return (map);
}
