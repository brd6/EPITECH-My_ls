/*
** my_strcmp.c for my_strcmp in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 14:59:45 2015 berdrigue bongolo-beto
** Last update Wed Nov 18 10:32:01 2015 berdrigue bongolo-beto
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (!s2[i])
	return (1);
      if (s2[i] > s1[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i = i + 1;
    }
  if (s2[i])
    {
      return (-1);
    }
  return (0);
}
