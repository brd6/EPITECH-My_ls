/*
** info_sort.c for info_sort in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Nov 27 01:39:19 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 14:02:18 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

void	tstring_swap(char *str1[], char *str2[])
{
  char	*tmp;

  tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
}

int	stringtab_sort(t_my_ls *info)
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
      while (info->files[i + 1])
	{
	  tmp = upper_to_power(info->files[i]);
	  tmp2 = upper_to_power(info->files[i + 1]);
	  if (my_strcmp(tmp, tmp2) > 0)
	    {
	      tstring_swap(&info->files[i], &info->files[i + 1]);
	      sorted = 1;
	    }
	  i = i + 1;
	}
    }
  return (1);
}

int		date_sort_files_tab(t_file_info *file_info)
{
  int		i;
  int		sorted;
  time_t	date1;
  time_t	date2;

  i = 0;
  sorted = 1;
  while (sorted)
    {
      sorted = 0;
      i = 0;
      while (i < file_info->cp_files - 1)
	{
	  date1 = my_stat(file_info->files[i].full_name).st_mtime;
	  date2 = my_stat(file_info->files[i + 1].full_name).st_mtime;
	  if (difftime(date1, date2) > 0)
	    {
	      tab2_swap(&file_info->files[i], &file_info->files[i + 1]);
	      sorted = 1;
	    }
	  i = i + 1;
	}
    }
  return (1);
}

void	check_R_scond(char *av[4], char *full_name, t_my_ls *info)
{
  av[0] = my_strdup("./my_ls");
  av[1] = my_strdup(full_name);
  av[2] = concat_two_str("/", info->options);
  av[2][0] = '-';
  av[3] = 0;
  my_printf("\n");
  main(3, av);
}

int	check_R(t_my_ls *info, t_dir_bak *dir_bak, t_file_info *file_info)
{
  int	i;
  int	j;
  char	*av[4];

  i = file_info->cp_files - 1;
  j = 0;
  if (my_get_char_pos(info->options, 'R') != -1 && dir_bak->cp > 0)
    {
      j = j + 1;
      while (i > -1)
	{
	  if (S_ISDIR(my_stat(file_info->files[i].full_name).st_mode) &&
	      file_info->files[i].name[0] != '.')
	    {
	      check_R_scond(av, file_info->files[i].full_name, info);
	      j = j + 1;
	    }
	  i = i - 1;
	}
    }
}
