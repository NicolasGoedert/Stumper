/*
** get_map.c for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 15:33:00 2017 Remi Verny
** Last update Wed Apr 26 16:36:35 2017 Remi Verny
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mydefine.h"

char	*my_strcpy(char *src, char *dest, int n)
{
  int	i;

  i = -1;
  while (src[++i] != '\0')
    dest[i + n] = src[i];
  dest[i + n] = '\0';
  return (dest);
}

char	*my_strcat(char *buff, char *str)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 2)) == NULL)
    return (my_error2(MALLOC_MSG, NULL));
  if (str == NULL)
    {
      tmp = my_strcpy(buff, tmp, 0);
      return (tmp);
    }
  tmp = my_strcpy(str, tmp, 0);
  tmp = my_strcpy(buff, tmp, my_strlen(str));
  free(str);
  return (tmp);
}

void	fill_with_zeros(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    str[i] = '0';
}

char	**get_map(int fd)
{
  char	buff[READ_SIZE + 1];
  int	has_been_read;
  char	*str;
  char	state;

  state = 0;
  str = NULL;
  has_been_read = 0;
  while ((has_been_read = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[has_been_read] = '\0';
      state = 1;
      str = my_strcat(buff, str);
      fill_with_zeros(buff);
    }
  if ((state == 0 && has_been_read == 0) || has_been_read == -1
      || str[my_strlen(str) - 1] != '\n')
    return ((char **) my_error2(FILE_MSG, NULL));
  return (in_map(str));
}
