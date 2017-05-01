/*
** my_getnbr.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 15:10:32 2017 Remi Verny
** Last update Wed Apr 26 16:48:28 2017 Remi Verny
*/

#include "my.h"

int	my_getnbr(const char *str)
{
  int	size;
  int	limit;
  int	i;
  int	res;

  size = my_strlen(str);
  limit = 1;
  while (size > 1)
    {
      limit *= 10;
      --size;
    }
  res = 0;
  i = 0;
  while (limit >= 1)
    {
      res += (str[i] - 48) * limit;
      limit /= 10;
      ++i;
    }
  return (res);
}
