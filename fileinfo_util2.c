/*
** fileinfo_util2.c for fileinfo_util2 in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Nov 28 12:42:10 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 12:32:11 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

t_file_info	*add_file_fileinfo(t_my_ls info)
{
  int		i;
  t_file_info	*file_info;
  int		cp_files;

  file_info = malloc(sizeof(*file_info));
  if (file_info == NULL)
    return (0);
  cp_files = (count_file2(&info) + 1);
  file_info->files = malloc(sizeof(*file_info->files) * (cp_files));
  if (file_info->files == NULL)
    return (0);
  file_info->cp_files = cp_files;
  i = 0;
  while (info.files_s[i])
    {
      file_info->files[i].name = my_strdup(info.files_s[i]);
      file_info->files[i].full_name = my_strdup(info.files_s[i]);
      i = i + 1;
    }
  return (file_info);
}

void	set_files_scond(int *j, int *k, t_my_ls *info)
{
  if (*j == 0 && *k == 0)
    {
      if (my_get_char_pos(info->options, 'd') == -1)
	{
	  info->files[*j] = my_strdup(".");
	  info->files[*j + 1] = 0;
	}
      else
	{
	  info->files_s[*k] = my_strdup(".");
	  *k = *k + 1;
	}
    }
  else
    info->files[*j] = 0;
  info->files_s[*k] = 0;
}

void	tab2_swap2(char *str1[], char *str2[])
{
  char	*tmp;

  tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
}

int	sort_files_tab2(char **files, int(*cmp)(char *, char *))
{
  int	i;
  int	sorted;
  char	*tmp;
  char	*tmp2;

  i = 0;
  sorted = 1;
  while (sorted)
    {
      sorted = 0;
      i = 0;
      while (files[i + 1] != 0)
	{
	  tmp = upper_to_power(files[i]);
	  tmp2 = upper_to_power(files[i + 1]);
	  if (cmp(tmp, tmp2) > 0)
	    {
	      tab2_swap2(&files[i], &files[i + 1]);
	      sorted = 1;
	    }
	  i = i + 1;
	}
    }
  return (1);
}

int		my_ls2(t_my_ls *info, t_file_info *file_info)
{
  int		i;
  struct stat	file_stats;
  int		rev;

  i = 0;
  while (info->files_s[i])
    {
      if (my_get_char_pos(info->options, 'l') == -1)
	default_display(info, &file_info->files[i], "./");
      else
	list_display(info, &file_info->files[i], file_info);
      i = i + 1;
    }
  return (1);
}
