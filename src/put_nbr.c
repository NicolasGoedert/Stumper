/*
** put_nbr.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 16:56:00 2017 Remi Verny
** Last update Wed Apr 26 17:08:32 2017 Remi Verny
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	limit;
  int	tmp;

  tmp = nb;
  limit = 1;
  if (nb == 0)
    {
      my_putchar('0');
      return ;
    }
  while (limit <= tmp)
    {
      limit *= 10; 
    }
  limit /= 10;
  while (limit > 0)
    {
      my_putchar((nb / limit) + 48);
      nb %= limit;
      limit /= 10;
    }
}
