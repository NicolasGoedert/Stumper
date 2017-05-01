/*
** my.h for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Apr 26 14:22:32 2017 Remi Verny
** Last update Wed Apr 26 17:02:25 2017 Remi Verny
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(const char *str);
int	check_args(char **av, int *mov);
int	my_strcmp(const char *s1, const char *s2);
int	my_error(const char *str, int err);
int	my_getnbr(const char *str);
char	*my_error2(const char *str, char *err);
char	**get_map(int fd);
char	**in_map(char *str);
void	my_put_nbr(int nb);
int	game(char **map, int mov);

#endif /* !MY_H_ */
