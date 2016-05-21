/*
** my.h for my in /home/bongol_b/rendu/Piscine_C_workshoplib
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 16 01:09:57 2015 berdrigue bongolo-beto
** Last update Sat Mar 26 23:13:16 2016 Berdrigue BONGOLO BETO
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *, int);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char* dest, char *src);
char	*my_strncpy(char *dest,char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str,char *to_find);
int	my_strcmp(char *s1,char *s2);
int	my_strncmp(char *s1,char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	is_num(char c);
int	is_alpha(char c);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	is_printable(char c);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	*my_strdup(char *src);
int	my_show_wordtab(char **);
char	**my_str_to_wordtab(char *str);
int	my_getnbr_base(char *str, char *base);
int	my_putnbr_base(int nbr, char *base);
void	my_strswap(char *a, char *b);
char	*convert_base(char *nbr, char *base_from, char *base_to);
char	*my_strchr(char *s, char c);
int	my_atoi(char *);
char	**my_str_split(char *str, char *sp);
int	my_nbr_len(int nbr);
char	*my_itoa(int nbr);
int	my_check_uniq_char(char *str);
int	my_get_char_pos(char *str, char c);
int	my_wordtab_count(char **);
void	my_puterr(char *str);
char	*my_str_replace(char *search, char *replace, char *subject, int n);
int	my_str_isalphanum(char *str);
int	is_alpha(char c);
char	*my_wordtab_to_str(char **args, char sp);
int	my_wordtab_word_count(char **args);
void	my_free_wordtab(char **);
char	*my_wordtab_search(char **, char *data, int (*cmp)());
char	*my_getstr_key(char *str, char separator);
char	*my_getstr_value(char *str, char separator);
#endif /* !MY_H_ */
