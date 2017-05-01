/*
** mystruct.h for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 16:32:42 2017 Remi Verny
** Last update Wed Apr 26 17:40:55 2017 Remi Verny
*/

#ifndef MYSTRUCT_H_
# define MYSTRUCT_H_$

typedef struct	s_verif
{
  char		gin;
  int		tok_map;
  int		tok_got;
  int		g_mov;
  char		other;
}		t_verif;

typedef struct	s_coords
{
  int		g_i;
  int		g_j;
  int		c_i;
  int		c_j;
}		t_coords;

#endif /* !MYSTRUCT_H_ */
