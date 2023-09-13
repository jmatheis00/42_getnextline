# 42_getnextline

> This project involves the creation of a custom C function called get_next_line() designed to read lines from a given file descriptor or standard input.
> This function will read and return lines one at a time, retaining the newline character as part of the line unless the end of the file is encountered without a newline.
> The goal of this project is to provide a useful way to handle input in C programs, covering both reading files and interacting via the command line.

The recoded getnextline function is called get_next_line() and has the following prototype:
```C
char *get_next_line(int fd);
```

### Usage
1. Clone this repository and `cd` into it:

```zsh
git clone https://github.com/jmatheis00/42_getnextline.git && cd 42_getnextline
```
Don't forget to add a file to be read!

#### Mandatory part
2. Uncomment the main function in get_next_line.c or add your own main.c file with header get_next_line.h and a file to be read.
3. Compile your code with the following command and replace `<size>` with the desired buffer size:
```zsh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out
```
#### Bonus part
In the Bonus part, the get_next_line() function can manage multiple file descriptors at the same time.

2. Uncomment the main function in get_next_line_bonus.c file or add your own main.c file with header get_next_line_bonus.h and files to be read.
3. Compile your code with the following command and replace `<size>` with the desired buffer size:
```zsh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line_bonus.c get_next_line_utils_bonus.c && ./a.out
```
