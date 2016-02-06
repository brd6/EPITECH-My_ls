/*
** my_ls.c for my_ls in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Nov 29 11:16:41 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 20:28:38 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

int	my_ls_scond2(int *rev, int *i, t_my_ls *info, t_file_info *file_info)
{
  *rev = (my_get_char_pos(info->options, 'r') == -1);
  *i = (*rev ? (file_info->cp_files - 1) : 0);
  if (my_get_char_pos(info->options, 'f') == -1)
    sort_files_tab(file_info, &my_strcmp);
  if (my_get_char_pos(info->options, 't') != -1 &&
      my_get_char_pos(info->options, 'f') == -1)
    date_sort_files_tab(file_info);
  return (1);
}

int		my_ls(t_my_ls *info, t_file_info *file_info)
{
  int		i;
  int		j;
  int		rev;
  t_dir_bak	dir_bak;

  dir_bak.cp = 0;
  my_ls_scond2(&rev, &i, info, file_info);
  j = (rev ? -1 : file_info->cp_files);
  print_file_total(info, file_info);
  while (i != j)
    {
      if (my_get_char_pos(info->options, 'l') == -1)
	default_display(info, &file_info->files[i], file_info->base_dir);
      else
	list_display(info, &file_info->files[i], file_info);
      if (S_ISDIR(my_stat(file_info->files[i].full_name).st_mode) &&
	  file_info->files[i].name[0] != '.')
	dir_bak.cp = dir_bak.cp + 1;
      if (!rev)
	i = i + 1;
      else
      	i = i - 1;
    }
  check_R(info, &dir_bak, file_info);
  return (1);
}

int		recc2(t_my_ls info)
{
  int		i;
  t_file_info	*file_info;
  int		cp_files;

  sort_files_tab2(info.files_s, &my_strcmp);
  file_info = add_file_fileinfo(info);
  if (file_info == 0)
      return (0);
  if (!my_ls2(&info, file_info))
    return (0);
  if (info.files[0] != 0 && info.files_s[0] != 0)
    my_printf("\n");
  return (1);
}

int		recc(t_my_ls info)
{
  int		i;
  t_file_info	*file_info;

  i = 0;
  while (info.files[i])
    {
      if (info.files[1] || info.files_s[0] ||
	  my_get_char_pos(info.options, 'R') != -1)
	my_printf("%s:\n", info.files[i]);
      file_info = my_open_dir(info.files[i]);
      if (file_info == 0)
	return (0);
      if (!my_ls(&info, file_info))
      	return (0);
      if (info.files[1] && info.files[i + 1])
	my_printf("\n");
      i = i + 1;
    }
  return (1);
}

int		main(int ac, char **av)
{
  t_my_ls	info;

  reset_options(&info);
  if (!set_options(&info, ac, av))
      return (1);
  if (!set_files(&info, ac, av))
    return (1);
  stringtab_sort(&info);
  if (my_get_char_pos(info.options, 'R') == -1)
    recc2(info);
  if (info.files[0] != 0)
    recc(info);
  free(info.files);
  return (0);
}
