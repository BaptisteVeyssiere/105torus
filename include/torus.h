/*
** 105torus.h for 105torus in /home/VEYSSI_B/rendu/105torus
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Jan  4 10:56:14 2016 Baptiste veyssiere
** Last update Sun Jan 17 16:44:10 2016 Baptiste veyssiere
*/

#ifndef TORUS_H_
# define TORUS_H_

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
  double	a0;
  double	a1;
  double	a2;
  double	a3;
  double	a4;
}		t_coeff;

# ifndef ABS
#  define ABS(x) ((x) < 0 ? -(x) : (x))
# endif /* !ABS */

#endif /* !TORUS_H_ */
