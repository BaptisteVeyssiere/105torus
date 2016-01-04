/*
** main.c for 105torus in /home/VEYSSI_B/rendu/105torus
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Jan  4 10:53:52 2016 Baptiste veyssiere
** Last update Mon Jan  4 13:45:24 2016 nathan scutari
*/

#include <torus.h>

int	my_strlen(char *str)
{
  int	x;

  x = -1;
  while (str[++x] != 0);
  return (x);
}

int	my_perror_arg(char *str, int arg, int output)
{
  char	argnbr;

  write(2, str, my_strlen(str));
  argnbr = arg + 48;
  write(2, &argnbr, 1);
  write(2, "\n", 1);
  return (output);
}

int	my_perror(char *str, int output)
{
  write(2, str, my_strlen(str));
  return (output);
}

int	check_arg_nbr(char *arg, int arg_nbr)
{
  int	x;
  int	letter;
  int	error;
  int	dot;
  int	double_dot;

  x = -1;
  dot = 0;
  error = 0;
  double_dot = 0;
  letter = 0;
  if (arg[0] == '-')
    if (arg[1] == 0)
      {
	my_perror_arg("Missing digits after - symbol in arg ", arg_nbr, -1);
	error = -1;
      }
    else
      x = 0;
  if (arg[0] == '-' && arg_nbr == 7)
    {
      my_perror("Arg 7 must be a positive number\n", -1);
      error = -1;
    }
  while (arg[++x] != 0)
    {
      if (arg[x] == '.')
	if (dot == 1 && double_dot == 0)
	  {
	    double_dot = 1;
	    error = -1;
	    my_perror_arg("2 or more dots in arg  ", arg_nbr, -1);
	  }
	else if (arg[x] == '.' && arg[x + 1] == 0)
	  {
	    my_perror_arg("Missing digit after last dot in arg ", arg_nbr, -1);
	    error = -1;
	  }
	else
	  ++dot;
      if ((arg[x] > '9' || arg[x] < '0') && arg[x] != '.' && letter == 0)
	{
	  error = -1;
	  my_perror_arg("Character other than digit and dot in arg ", arg_nbr, -1);
	  ++letter;
	}
    }
  return (error);
}

int	check_args(char **av)
{
  int	x;
  int	error;

  x = 1;
  error = 0;
  if ((av[1][0] != '1' && av[1][0] != '2' && av[1][0] != '3') || av[1][1] != 0)
    {
      my_perror("First arg must be 1, 2 or 3\n", 0);
      error = -1;
    }
  while (++x < 8)
    if (check_arg_nbr(av[x], x) == -1)
      error = -1;
  return (error);
}

int	main(int ac, char **av)
{
  if (ac != 8)
    return (my_perror("Usage : ./105torus opt a0 a1 a2 a3 a4 n\n", 84));
  if (check_args(av) == -1)
    return (my_perror("Syntax error\n", 84));
  torus();
  return (0);
}
