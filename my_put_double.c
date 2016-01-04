/*
** my_put_double.c for 105torus in /home/scutar_n/rendu/105torus
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Jan  4 14:56:13 2016 nathan scutari
** Last update Mon Jan  4 14:59:30 2016 nathan scutari
*/

void	my_put_double(double nbr, int dec)
{
  int	x;
  int	int_nbr;

  x = -1;
  int_nbr = (int)nbr;
  my_put_nbr(int_nbr);
  nbr -= int_nbr;
  while (++x < dec)
    {
      nbr *= 10;
      my_put_nbr((int)nbr);
      nbr -= (int)nbr;
    }
}
