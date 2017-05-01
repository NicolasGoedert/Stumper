/*
** my_error.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 15:53:58 2017 Remi Verny
** Last update Wed Apr 26 16:19:59 2017 Remi Verny
*/

#include <unistd.h>
#include "my.h"

int	my_error(const char *str, int err)
{
  write(2, str, my_strlen(str));
  return (err);
}

char	*my_error2(const char *str, char *err)
{
  write(2, str, my_strlen(str));
  return (err);
}
