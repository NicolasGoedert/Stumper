/*
** game.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 16:31:30 2017 Remi Verny
** Last update Wed Apr 26 18:09:15 2017 Remi Verny
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mydefine.h"
#include "mystruct.h"

int	fill_verif(t_verif *check, const char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == 'G')
	++(check->gin);
      else if (str[i] == 'T')
	++(check->tok_map);
      else if (str[i] != 'G' && str[i] != 'T' && str[i] != 'F'
	       && str[i] != '.')
	check->other = '0';
    }
  return (i);
}

int     play(char **map)
{
  int   i;
  int   j;

  i = -1;
  while (map[++i] != '\0')
    {
      j = -1;
      while (map[i][++j] != '\0')
	{
	  if (map[i][j] == 'G')
	    break ;
	}
      if (map[i][j] != '\0')
	break ;
    }
  return (0);
}

int		game_loop(char **map, t_verif *check)
{
  int		i;
  t_coords	*coo;

  if ((coo = malloc(sizeof(*coo))) == NULL)
    return (my_error(MALLOC_MSG, 84));
  while (check->tok_got < check->tok_map && check->g_mov >= 0)
    {
      my_putstr("Tokens: ");
      my_put_nbr(check->tok_got);
      my_putchar('/');
      my_put_nbr(check->tok_map);
      my_putchar('\n');
      my_putstr("Movement points: ");
      my_put_nbr(check->g_mov);
      my_putchar('\n');
      i = -1;
      while (map[++i] != '\0')
	{
	  my_putstr(map[i]);
	  my_putchar('\n');
	}
      my_putchar('\n');
      play(map);
      --(check->g_mov);
    }
  my_putstr("Ginger is too old for that!\n");
  return (0);
}

int		game(char **map, int mov)
{
  int		i;
  int		j;
  t_verif	*check;

  if ((check = malloc(sizeof(*check))) == NULL)
    my_error(MALLOC_MSG, 84);
  i = -1;
  check->gin = '0';
  check->tok_map = 0;
  check->other = '1';
  check->g_mov = mov;
  check->tok_got = 0;
  while (map[++i] != '\0')
    {
      if ((j = fill_verif(check, map[i])) != my_strlen(map[0]))
	return (my_error(MAP_MSG, 84));
    }
  if (check->gin != '1' || check->tok_map == '0' || check->other == '0')
    return (my_error(MAP_MSG, 84));
  return (game_loop(map, check));
}
