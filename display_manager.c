/*
** display_manager.c for display_manager in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Nov 25 02:07:30 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 19:51:58 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

int		default_display(t_my_ls *info, t_my_file *file, char *base_dir)
{
  struct stat	file_stats;

  if (stat(file->full_name, &file_stats) != 0)
    {
      my_printf("File not found: %s", file->full_name);
      return (0);
    }
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
      if (file->name[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
	print_file_name(&file_stats, file, info);
    }
  else
    print_file_name(&file_stats, file, info);
  return (1);
 }

int	list_display(t_my_ls *info, t_my_file *file, t_file_info *file_info)
{
  struct stat	file_stats;

  if (stat(file->full_name, &file_stats) != 0)
    {
      my_printf("File not found: %s", file->full_name);
      return (0);
    }
  print_permission(info, &file_stats, file->name, file_info);
  print_hard_link(info, &file_stats, file->name, file_info);
  print_user_info(info, &file_stats, file->name, file_info);
  print_size_info(info, &file_stats, file->name, file_info);
  print_date_info(info, &file_stats, file->name, file_info);
  if (my_get_char_pos(info->options, 'a') == -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    {
      if (file->name[0] != '.' || my_get_char_pos(info->options, 'd') != -1)
	print_file_name2(&file_stats, file, info);
    }
  else
    print_file_name2(&file_stats, file, info);
  return (1);
}
