/*
** fileinfo_util.c for fileinfo_util in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Nov 26 21:55:11 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 13:52:20 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_ls.h"

int	count_file2(t_my_ls *info)
{
  int	i;

  i = 0;
  while (info->files_s[i])
    i = i + 1;
  return (i);
}

int	bigger_than_others2(int nb, t_file_info *file_info)
{
  int	i;

  i = 0;
  while (i < file_info->cp_files - 1)
    {
      if (nb < my_stat(file_info->files[i].full_name).st_nlink)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}

int	bigger_than_others(int nb, t_file_info *file_info)
{
  int	i;

  i = 0;
  while (i < file_info->cp_files - 1)
    {
      if (nb < my_stat(file_info->files[i].full_name).st_size)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}

int	max_len_nlink(t_file_info *file_info, t_my_ls *info)
{
  int	i;
  int	max;

  i = 0;
  max = 1;
  while (i < file_info->cp_files - 1)
    {
      if (my_get_char_pos(info->options, 'd') == -1)
	{
	  if (my_get_char_pos(info->options, 'a') == -1 &&
	      file_info->files[i].name[0] == '.' &&
	      my_get_char_pos(info->options, 'f') == -1)
	    {
	      i = i + 1;
	    }
	}
      if (bigger_than_others2(my_stat(file_info->files[i].full_name).
			      st_nlink, file_info))
	max = my_nbr_len(my_stat(file_info->files[i].full_name).st_nlink);
      i = i + 1;
    }
  return (max);
}

int	max_len_filesize(t_file_info *file_info, t_my_ls *info)
{
  int	i;
  int	max;

  i = 0;
  max = 1;
  while (i < file_info->cp_files - 1)
    {
      if (my_get_char_pos(info->options, 'd') == -1)
	{
	  if (my_get_char_pos(info->options, 'a') == -1 &&
	      file_info->files[i].name[0] == '.' &&
	      my_get_char_pos(info->options, 'f') == -1)
	    {
	      i = i + 1;
	    }
	}
      if (bigger_than_others(my_stat(file_info->files[i].full_name).st_size,
			     file_info))
	{
	  max = my_nbr_len(my_stat(file_info->files[i].full_name).st_size);
	}
      i = i + 1;
    }
  return (max);
}
