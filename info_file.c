/*
** info_file.c for info_file in /home/bongol_b/rendu/PSU_2015_my_ls_bootstrap
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Nov 16 22:59:39 2015 berdrigue bongolo-beto
** Last update Sun Nov 29 12:51:08 2015 berdrigue bongolo-beto
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_filename(char *filename)
{
  int	i;

  i = my_get_char_pos(filename, '/');
  if (i != -1)
    return (&filename[i + 1]);
  else
    return (filename);
}

char	*get_filetype(struct stat *file_stats)
{
  if (S_ISREG(file_stats->st_mode))
    return ("f");
  else if (S_ISDIR(file_stats->st_mode))
    return ("d");
  else if (S_ISCHR(file_stats->st_mode))
    return ("c");
  else if (S_ISBLK(file_stats->st_mode))
    return ("b");
  else if (S_ISFIFO(file_stats->st_mode))
    return ("p");
  else if (S_ISLNK(file_stats->st_mode))
    return ("l");
  else if (S_ISSOCK(file_stats->st_mode))
    return ("s");
  else
    return ("?");
}

char	*get_file_perm(struct stat *file_stat)
{
  char	*tmp;

  tmp = malloc(sizeof(char) * 11);
  if (tmp == 0)
    return (0);
  tmp[0] = (S_ISDIR(file_stat->st_mode)) ? 'd' : '-';
  tmp[0] = (S_ISSOCK(file_stat->st_mode)) ? 's' : tmp[0];
  tmp[0] = (S_ISLNK(file_stat->st_mode)) ? 'l' : tmp[0];
  tmp[1] = (file_stat->st_mode & S_IRUSR) ? 'r' : '-';
  tmp[2] = (file_stat->st_mode & S_IWUSR) ? 'w' : '-';
  tmp[3] = (file_stat->st_mode & S_IXUSR) ? 'x' : '-';
  tmp[4] = (file_stat->st_mode & S_IRGRP) ? 'r' : '-';
  tmp[5] = (file_stat->st_mode & S_IWGRP) ? 'w' : '-';
  tmp[6] = (file_stat->st_mode & S_IXGRP) ? 'x' : '-';
  tmp[7] = (file_stat->st_mode & S_IROTH) ? 'r' : '-';
  tmp[8] = (file_stat->st_mode & S_IWOTH) ? 'w' : '-';
  tmp[9] = (file_stat->st_mode & S_IXOTH) ? 'x' : '-';
  tmp[10] = 0;
  return (tmp);
}
