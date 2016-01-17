/*
** 105torus.c for 105torus in /home/VEYSSI_B/rendu/105torus
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Jan  4 10:55:22 2016 Baptiste veyssiere
** Last update Sun Jan 17 16:33:25 2016 Baptiste veyssiere
*/

#include <torus.h>

void	bissection(t_coeff coeff, double epsilon, char *phrase)
{
  double	a;
  double	b;
  double	xm;

  a = 0;
  b = 1;
  while (ABS(b - a) > epsilon)
    {
      printf(phrase, (a + b) / 2);
      xm = (coeff.a0 + coeff.a1 * ((a + b) / 2) + coeff.a2 * pow(((a + b) / 2), 2) + coeff.a3 * pow(((a + b) / 2), 3) + coeff.a4 * pow(((a + b) / 2), 4)) * (coeff.a0 + coeff.a1 * a + coeff.a2 * pow(a, 2) + coeff.a3 * pow(a, 3) + coeff.a4 * pow(a, 4));
      if (xm < 0)
	b = (a + b) / 2;
      else
	a = (a + b) / 2;
    }
}

void	newton(t_coeff coeff, double epsilon, char *phrase)
{
  double	x0;

  x0 = 0.5;
  printf(phrase, x0);
  while (ABS((coeff.a0 + coeff.a1 * x0 + coeff.a2 * pow(x0, 2) + coeff.a3 * pow(x0, 3) + coeff.a4 * pow(x0, 4))) >= epsilon)
    {
      x0 = x0 - ((coeff.a0 + coeff.a1 * x0 + coeff.a2 * pow(x0, 2) + coeff.a3 * pow(x0, 3) + coeff.a4 * pow(x0, 4)) / (coeff.a1 + 2 * coeff.a2 * x0 + 3 * coeff.a3 * pow(x0, 2) + 4 * coeff.a4 * pow(x0, 3)));
      if (ABS((coeff.a0 + coeff.a1 * x0 + coeff.a2 * pow(x0, 2) + coeff.a3 * pow(x0, 3) + coeff.a4 * pow(x0, 4))) > epsilon)
	printf(phrase, x0);
    }
  printf(phrase, x0);

}

void	secante(t_coeff coeff, double epsilon, char *phrase)
{
  double x0;
  double x1;
  double x;
  double Px;
  double Px_1;

  x0 = 0;
  x1 = 1;
  while (ABS((coeff.a0 + coeff.a1 * x1 + coeff.a2 * pow(x1, 2) + coeff.a3 * pow(x1, 3) + coeff.a4 * pow(x1, 4))) > epsilon)
    {
      x = x1;
      Px = (coeff.a0 + coeff.a1 * x1 + coeff.a2 * pow(x1, 2) + coeff.a3 * pow(x1, 3) + coeff.a4 * pow(x1, 4));
      Px_1 = (coeff.a0 + coeff.a1 * x0 + coeff.a2 * pow(x0, 2) + coeff.a3 * pow(x0, 3) + coeff.a4 * pow(x0, 4));
      x -= Px / ((Px - Px_1) / (x1 - x0));
      x0 = x1;
      x1 = x;
      printf(phrase, x1);
    }
  printf(phrase, x1);
}

int	torus(char **av)
{
  t_coeff	coeff;
  double        epsilon;
  int		opt;
  char		phrase[11] = "x = %.";
  int		i;

  i = -1;
  while (av[7][++i] != 0)
    phrase[6 + i] = av[7][i];
  phrase[6 + i] = 'g';
  phrase[7 + i] = '\n';
  phrase[8 + i] = 0;
  coeff.a0 = atof(av[2]);
  coeff.a1 = atof(av[3]);
  coeff.a2 = atof(av[4]);
  coeff.a3 = atof(av[5]);
  coeff.a4 = atof(av[6]);
  epsilon = pow(10, -atoi(av[7]));
  opt = atoi(av[1]);
  if (opt == 1)
    bissection(coeff, epsilon, phrase);
  else if (opt == 2)
    newton(coeff, epsilon, phrase);
  else if (opt == 3)
    secante(coeff, epsilon, phrase);
  return (0);
}
