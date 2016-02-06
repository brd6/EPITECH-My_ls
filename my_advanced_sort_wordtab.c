/*
** my_advanced_sort_wordtab.c for my_advanced_sort_wordtab in /home/bongol_b/rendu/Piscine_C_J10
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Oct 10 00:14:13 2015 berdrigue bongolo-beto
** Last update Sat Nov 28 13:44:39 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

void tab2_swap(t_my_file *file1, t_my_file *file2)
{
  t_my_file	tmp;

  tmp.name = file1->name;
  tmp.full_name = file1->full_name;

  file1->name = file2->name;
  file1->full_name = file2->full_name;

  file2->name = tmp.name;
  file2->full_name = tmp.full_name;
}

int	is_only_lower(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] < 'Z')
	return (0);
      i = i + 1;
    }
  return (1);
}

char	*upper_to_power(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = my_strdup(str);
  while (tmp[i])
    {
      if (tmp[i] >= 'A' && tmp[i] < 'Z')
	tmp[i] = tmp[i] + 32;
      i = i + 1;
    }
  return (tmp);
}

int	contain_number(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	return (1);
      i = i + 1;
    }
  return (0);
}

int	sort_files_tab(t_file_info *file_info, int(*cmp)(char *, char *))
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
      while (i < file_info->cp_files - 1)
	{
	  tmp = upper_to_power(file_info->files[i].name);
	  tmp2 = upper_to_power(file_info->files[i + 1].name);
	  if (cmp(tmp, tmp2) < 0)
	    {
	      tab2_swap(&file_info->files[i], &file_info->files[i + 1]);
	      sorted = 1;
	    }
	  i = i + 1;
	}
    }
  return (1);
}
