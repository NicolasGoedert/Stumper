/*
** main.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 14:18:10 2017 Remi Verny
** Last update Wed Apr 26 17:49:19 2017 Remi Verny
*/

#include <stdio.h>
#include "my.h"
#include "mydefine.h"

static int	help(char *str)
{
  my_putstr(HELP1);
  my_putstr(str);
  my_putstr(HELP2);
  return (84);
}  

int	main(int ac, char **av)
{
  int	mov;
  int	fd;
  char	**map;

  mov = 0;
  if (ac != 5)
    return (help(av[0]));
  else if (ac == 5)
    {
      if ((fd = check_args(av, &mov)) == -1)
	return (84);
      if ((map = get_map(fd)) == NULL)
	return (84);
      if (game(map, mov) == 84)
	return (84);
    }
  return (0);
}
