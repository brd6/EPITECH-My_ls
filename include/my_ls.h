/*
** my_ls.h for my_ls in /home/bongol_b/rendu/PSU_2015_my_ls
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Nov 21 10:48:31 2015 berdrigue bongolo-beto
** Last update Sun May 22 00:41:45 2016 Berdrigue BONGOLO BETO
*/

#ifndef MY_LS_H_
# define MY_LS_H_

# include <sys/stat.h>
# include "my.h"
# include "my_printf.h"

# define WHITE	"\033[0m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define BOLD	"\033[1m"
# define BWHITE	"\033[1;0m"
# define BRED	"\033[1;31m"
# define BGREEN	"\033[1;32m"
# define BBLUE	"\033[1;34m"
# define BCYAN	"\033[1;36m"

typedef	struct	s_my_ls
{
  char		options[10];
  char		**files;
  char		**files_s;
}		t_my_ls;

typedef	struct	s_dir_bak
{
  int		cp;
  char		**files;
}		t_dir_bak;

typedef	struct	s_my_file
{
  char		*name;
  char		*full_name;
  unsigned char	type;
}		t_my_file;

typedef	struct	s_file_info
{
  t_my_file	*files;
  char		*base_dir;
  int		cp_files;
}		t_file_info;

char		*my_strdup(char *src);
t_file_info	*my_open_dir(char *file);
int		my_strcmp(char *s1, char *s2);
int		sort_files_tab(t_file_info *file_f, int(*cmp)(char *, char *));
char		*get_filetype(struct stat *file_stats);
struct stat	my_stat(char *file);
char		*concat_two_str(char *str1, char *str2);
char		*my_strcpy(char *dest, char *src);
char		*get_file_perm(struct stat *file_stat);
int		stringtab_sort(t_my_ls *info);
int		is_only_lower(char *str);
char		*upper_to_power(char *str);
int		contain_number(char *str);
void		tab2_swap(t_my_file *file1, t_my_file *file2);
t_file_info	*add_file_fileinfo(t_my_ls info);
void		set_files_scond(int *j, int *k, t_my_ls *info);
int		check_R(t_my_ls *info, t_dir_bak *dir_bak, t_file_info *file_i);
int		my_ls_scond2(int *rev, int *i, t_my_ls *info, t_file_info *file);
int		date_sort_files_tab(t_file_info *file_info);
void		print_file_total(t_my_ls *info, t_file_info *file_info);
int		default_display(t_my_ls *info, t_my_file *file, char *base_dir);
int		list_display(t_my_ls *info, t_my_file *file, t_file_info *file_info);
int		sort_files_tab2(char **files, int(*cmp)(char *, char *));
int		my_ls2(t_my_ls *info, t_file_info *file_info);
void		reset_options(t_my_ls *info);
int		set_options(t_my_ls *info, int ac, char **av);

#endif /* !MY_LS_H_ */
