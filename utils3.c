/*
** utils3.c for utils3 in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Nov 25 13:19:50 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 19:34:44 2015 berdrigue bongolo-beto
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

int		print_user_info(t_my_ls *info, struct stat *file_stats,
				char *file, t_file_info *file_info)
{
  struct passwd	*pwd;
  struct group	*grp;
  int		max;

  if ((pwd = getpwuid(file_stats->st_uid)) == NULL)
    return (0);
  grp = getgrgid(file_stats->st_gid);
  max = max_len_nlink(file_info, info);
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
     if (file[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
	 my_printf("%s %s ", pwd->pw_name, grp->gr_name);
    }
  else
    my_printf("%s %s ", pwd->pw_name, grp->gr_name);
  return (1);
}

int	print_size_info(t_my_ls *info, struct stat *file_stats,
			char *file, t_file_info *file_info)
{
  int		max;

  max = max_len_filesize(file_info, info);
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
     if (file[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
       my_printf("%*d ", max, file_stats->st_size);
    }
  else
    my_printf("%*d ", max, file_stats->st_size);
  return (1);
}

int	print_date_info(t_my_ls *info, struct stat *file_stats,
			char *file, t_file_info *file_info)
{
  int		max;
  struct tm	*tmp;
  char		buf[200];

  max = max_len_filesize(file_info, info);
  if (my_get_char_pos(info->options, 'u') == -1)
    tmp = localtime(&file_stats->st_mtime);
  else
    tmp = localtime(&file_stats->st_atime);
  strftime(buf, sizeof(buf), "%b.  %d %H:%M", tmp);
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
     if (file[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
       my_printf("%*s ", 2, upper_to_power(buf));
    }
  else
    my_printf("%*s ", 2, upper_to_power(buf));
  return (1);
}

int	print_file_name2(struct stat *file_stats, t_my_file *file, t_my_ls *info)
{
  if (get_filetype(file_stats)[0] == 'd' &&
      my_get_char_pos(info->options, 'F') != -1)
    my_printf("%s%s%s/", BBLUE, file->name, BWHITE);
  else
    {
      if (my_get_char_pos(get_file_perm(file_stats), 'x') != -1 &&
	  my_get_char_pos(info->options, 'F') != -1)
	my_printf("%s%s%s*", GREEN, file->name, WHITE);
      else if (get_filetype(file_stats)[0] == 'l' &&
	       my_get_char_pos(info->options, 'F') != -1)
	my_printf("%s%s%s@", BBLUE, file->name, WHITE);
      else if (get_filetype(file_stats)[0] == 'p' &&
	       my_get_char_pos(info->options, 'F') != -1)
	my_printf("%s%s%s|", BBLUE, file->name, WHITE);
      else
	my_printf("%s%s", BWHITE, file->name);
    }
  my_printf("\n");
}

int	print_file_name(struct stat *file_stats, t_my_file *file, t_my_ls *info)
{
  if (get_filetype(file_stats)[0] == 'd' &&
      my_get_char_pos(info->options, 'F') != -1)
    my_printf("%s%s%s/", BBLUE, file->name, BWHITE);
  else
    {
      if (my_get_char_pos(get_file_perm(file_stats), 'x') != -1 &&
	  my_get_char_pos(info->options, 'F') != -1)
	my_printf("%s%s%s*", GREEN, file->name, WHITE);
      else
	my_printf("%s%s", BWHITE, file->name);
    }
  my_printf("\n");
}
