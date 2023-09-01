# 42_getnextline

> This project involves the creation of a custom C function called get_next_line() designed to read lines from a given file descriptor or standard input.
> This function will read and return lines one at a time, retaining the newline character as part of the line unless the end of the file is encountered without a newline.
> The goal of this project is to provide a useful way to handle input in C programs, covering both reading files and interacting via the command line.

The recoded getnextline function is called get_next_line() and has the following prototype:
```C
char *get_next_line(int fd);
```

### Usage
1. clone this repository and `cd` into it:

```zsh
git clone https://github.com/jmatheis00/42_getnextline.git && cd 42_getnextline
```
