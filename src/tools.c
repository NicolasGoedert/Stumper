/*
** tools.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 14:20:25 2017 Remi Verny
** Last update Wed Apr 26 15:54:13 2017 Remi Verny
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return ;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (256);
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}
