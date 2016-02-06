/*
** utils4.c for utils4 in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Nov 29 19:29:07 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 20:54:55 2015 berdrigue bongolo-beto
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

int	print_permission(t_my_ls *info, struct stat *file_stats, char *file,
			 t_file_info *file_info)
{
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
     if (file[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
       my_printf("%s ", get_file_perm(file_stats));
    }
  else
    my_printf("%s ", get_file_perm(file_stats));
  return (1);
}

int	print_hard_link(t_my_ls *info, struct stat *file_stats, char *file,
			t_file_info *file_info)
{
  int		max;

  max = max_len_nlink(file_info, info);
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
     if (file[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
       my_printf("%*d ", max, file_stats->st_nlink);
    }
  else
    my_printf("%*d ", max, file_stats->st_nlink);
  return (1);
}

void		print_file_total(t_my_ls *info, t_file_info *file_info)
{
  int		i;
  int		cp;
  struct stat	file_stats;

  i = 0;
  cp = 0;
  if (my_get_char_pos(info->options, 'l') != -1)
    {
      while (i < file_info->cp_files)
	{
	  file_stats = my_stat(file_info->files[i].full_name);
	  if (my_get_char_pos(info->options, 'a') == -1)
	    {
	      if (file_info->files[i].name[0] != '.')
		cp = cp + file_stats.st_blocks;
	    }
	  else
	    cp = cp + file_stats.st_blocks;
	  i = i + 1;
	}
      my_printf("total %d\n", (cp / 2) );
    }
}
