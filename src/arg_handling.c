/*
** arg_handling.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 14:42:45 2017 Remi Verny
** Last update Wed Apr 26 15:27:23 2017 Remi Verny
*/

#include <fcntl.h>
#include "my.h"
#include "mydefine.h"

int	check_mov(const char *str, int *mov)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (84);
    }
  if ((*mov = my_getnbr(str)) == 0)
    return (84);
  return (0);
}

int	to_open(char **av, char flag, int *mov)
{
  int	fd;

  if (flag == 'f')
    {
      if ((fd = open(av[2], O_RDONLY)) == -1)
	return (my_error(OPEN_MSG, -1));
      if (check_mov(av[4], mov) == 84)
	return (my_error(ARG_MSG, -1));
    }
  else
    {
      if ((fd = open(av[4], O_RDONLY)) == -1)
	return (my_error(OPEN_MSG, -1));
      if (check_mov(av[2], mov) == 84)
	return (my_error(ARG_MSG, -1));
    }
  return (fd);
}

int	check_args(char **av, int *mov)
{
  char	flag;

  if (my_strcmp(av[1], "-m") == 0 || my_strcmp(av[1], "-f") == 0)
    {
      flag = av[1][1];
      if ((flag == 'm' && my_strcmp(av[3], "-f") != 0)
	  || (flag == 'f' && my_strcmp(av[3], "-m") != 0))
	return (my_error(ARG_MSG, -1));
    }
  else
    return (my_error(ARG_MSG, -1));
  return (to_open(av, flag, mov));
}
