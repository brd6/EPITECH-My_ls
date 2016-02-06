/*
** utils2.c for utils2 in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Nov 23 17:51:58 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 12:42:11 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my_ls.h"

struct stat	my_stat(char *file)
{
  struct stat	file_stats;

  if (stat(file, &file_stats) != 0)
    {
      my_printf("#1 File not found");
      exit(1);
    }
  return (file_stats);
}

int	put_file_in_tab(char *file, t_my_ls *info, int *j, int *k)
{
  if (!S_ISDIR(my_stat(file).st_mode) ||
      my_get_char_pos(info->options, 'd') != -1)
    {
      info->files_s[*k] = my_strdup(file);
      *k = *k + 1;
    }
  else
    {
      info->files[*j] = my_strdup(file);
      *j = *j + 1;
    }
}

int	set_files(t_my_ls *info, int ac, char **av)
{
  int	i;
  int	j;
  int	k;

  i = 1;
  j = 0;
  k = 0;
  info->files = malloc(sizeof(*info->files) * (ac + 1));
  info->files_s = malloc(sizeof(*info->files_s) * (ac + 1));
  if (info->files == NULL || info->files_s == NULL)
    return (0);
  while (i < ac)
    {
      if (av[i][0] != '-')
	put_file_in_tab(av[i], info, &j, &k);
      i = i + 1;
    }
  set_files_scond(&j, &k, info);
  return (1);
}

char	*concat_two_str(char *str1, char *str2)
{
  char	*tmp;

  tmp = malloc(my_strlen(str1) + my_strlen(str2) + 2);
  if (tmp == NULL)
    return (0);
  tmp[0] = 0;
  if (str1[my_strlen(str1) - 1] != '/')
    {
      my_strcat(tmp, str1);
      my_strcat(tmp, "/");
    }
  else
    my_strcat(tmp, str1);
  my_strcat(tmp, str2);
  return (tmp);
}

t_file_info		*my_open_dir(char *file)
{
  int			i;
  DIR			*rep;
  struct dirent		*curr_file;
  char			**files;
  int			cp_files;
  t_file_info		*file_info;

  i = 0;
  rep = opendir(file);
  file_info = malloc(sizeof(*file_info));
  if (!my_open_dir_scond(rep, file, &cp_files, file_info))
    return (0);
  curr_file = readdir(rep);
  while (curr_file)
    {
      file_info->files[i].name = my_strdup(curr_file->d_name);
      file_info->files[i].full_name = concat_two_str(file_info->base_dir,
						     curr_file->d_name);
      file_info->files[i].type = curr_file->d_type;
      i = i + 1;
      curr_file = readdir(rep);
    }
  return ((closedir(rep) == -1) ? 0 : file_info);
}
