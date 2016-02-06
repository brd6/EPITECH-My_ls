/*
** utils.c for utils in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Nov 23 15:46:03 2015 berdrigue bongolo-beto
** Last update Mon Nov 30 19:56:14 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_ls.h"

int	my_open_dir_scond(DIR *rep, char *file, int *cp_files,
			  t_file_info *file_info)
{
  if (rep == NULL)
    {
      my_printf("my_ls : cannot access %s:", file);
      my_printf(" Aucun fichier ou dossier de ce type");
      return (0);
    }
  *cp_files = count_files(file);
  file_info->files = malloc(sizeof(*file_info->files) * ((*cp_files) + 1));
  if (file_info->files == NULL)
    return (0);
  file_info->base_dir = my_strdup(file);
  file_info->cp_files = *cp_files;
  return (1);
}

int	set_info_option(char *options, char *str, int *j)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_get_char_pos("auFgflRdrt", str[i]) != -1 &&
	  my_get_char_pos(options, str[i]) == -1)
	{
	  options[*j] = str[i];
	  *j = *j + 1;
	}
      else if (my_get_char_pos("auFgflRdrt", str[i]) == -1)
	{
	  my_printf("my_ls : option invalide -- '%c'", str[i]);
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}

int	set_options(t_my_ls *info, int ac, char **av)
{
  int	i;
  int	j;
  int	pos_R;

  i = 1;
  j = 0;
  while (i < ac)
    {
      if (av[i][0] == '-' && j < 10)
	{
	  if (!set_info_option(info->options, &av[i][1], &j))
	    return (0);
	}
      i = i + 1;
    }
  info->options[j] = 0;
  pos_R = (my_get_char_pos(info->options, 'R'));
  if (my_get_char_pos(info->options, 'd') != -1 && pos_R != -1)
    {
      info->options[pos_R] = 'd';
    }
  return (1);
}

void	reset_options(t_my_ls *info)
{
  int	i;

  i = 0;
  while (i <= 10)
    {
      info->options[i] = 0;
      i = i + 1;
    }
}

int			count_files(char *file)
{
  DIR			*rep;
  int			cp;
  struct dirent		*curr_file;

  rep = opendir(file);
  cp = 0;
  curr_file = readdir(rep);
  while (curr_file)
    {
      cp = cp + 1;
      curr_file = readdir(rep);
    }
  return (cp);
}
