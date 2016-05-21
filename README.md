# EPITECH-My_ls

This project consists of replicating the ls function of Unix system.

### Usage :

```
./my_ls [-lRdrtuFgf] [FILE]
```

### Examples :

```
$ ./my_ls -l -t
total 148
-rw-r--r-- 1 bongol_b bongol_b   173 may.  22 00:53 README.md
-rwxrwxr-x 1 bongol_b bongol_b 79480 may.  22 00:44 my_ls
-rw------- 1 bongol_b bongol_b   788 may.  22 00:44 Makefile
drwx------ 2 bongol_b bongol_b  4096 may.  22 00:41 include
drwx------ 2 bongol_b bongol_b  4096 may.  22 00:31 lib
...
```

```
$ ./my_ls -lRt
.:
total 152
-rw-r--r-- 1 bongol_b bongol_b   173 may.  22 00:53 README.md
-rwxrwxr-x 1 bongol_b bongol_b 79480 may.  22 00:44 my_ls
-rw------- 1 bongol_b bongol_b   788 may.  22 00:44 Makefile
...

./include:
total 12
-rw------- 1 bongol_b bongol_b 2331 may.  22 00:41 my_ls.h
...

./lib:
total 3672
-rw-rw-r-- 1 bongol_b bongol_b   76792 may.  22 00:36 libmyprintf.a
...
```

```
$ ls -lt -R -r
...
```

<br>

man ls for more detail.
