*This project has been created as part of the 42 curriculum by aitawi.*

# pipex

## Description

`pipex` reproduces, in C, the shell pipeline redirection that you write every
day in your terminal:

```bash
< file1 cmd1 | cmd2 > file2
```

The goal is to explore the UNIX process model from the inside: how a shell
creates a communication channel with `pipe()`, duplicates a process with
`fork()`, rewires the standard streams with `dup2()`, replaces a process image
with `execve()`, and collects exit statuses with `waitpid()`.

The program resolves each command through the `PATH` environment variable (or
uses it directly when it contains a `/`), reports errors the way the shell
does, and exits with the status of the **last** command in the pipeline.

### Mandatory part

```bash
./pipex file1 cmd1 cmd2 file2      # equivalent to: < file1 cmd1 | cmd2 > file2
```

### Bonus part

Multiple pipes, and here-documents:

```bash
./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
# equivalent to: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

./pipex_bonus here_doc LIMITER cmd1 ... cmdn file
# equivalent to: cmd1 << LIMITER | ... | cmdn >> file
```

Note that `here_doc` **appends** to the output file (`>>`) instead of
truncating it, exactly like the shell.

## Instructions

### Compilation

```bash
make        # builds ./pipex        (mandatory part)
make bonus  # builds ./pipex_bonus  (multiple pipes + here_doc)
make clean  # removes the object files
make fclean # removes the object files and both binaries
make re     # fclean + make
```

Everything is compiled with `cc -Wall -Wextra -Werror`. `libft` is built by its
own Makefile and linked in. The Makefile does not relink when nothing changed.

### Usage examples

```bash
./pipex infile "ls -l" "wc -l" outfile
./pipex infile "grep a1" "wc -w" outfile

./pipex_bonus infile "cat" "grep a" "sort" "uniq -c" outfile
./pipex_bonus here_doc END "cat" "wc -l" outfile
```

### Behaviour and error handling

Errors follow the shell as closely as possible:

| Situation                     | Message                                 | Exit |
|-------------------------------|-----------------------------------------|------|
| Command not in `PATH`         | `pipex: cmd: command not found`         | 127  |
| Path given, file missing      | `pipex: cmd: No such file or directory` | 127  |
| Path given, not executable    | `pipex: cmd: Permission denied`         | 126  |
| Input/output file unusable    | `pipex: file: <errno message>`          | 1    |

As in a real shell, a failing command does not abort the rest of the pipeline:
the output file is still created, the other commands still run, and the exit
status of the whole program is the status of the last command.

## Project layout

```
include/pipex.h                       include/pipex_bonus.h

src/                                  src_bonus/
  pipex.c                               pipex_bonus.c      main + orchestration
  execute.c                             execute_bonus.c    arg split + execve
  path.c                                path_bonus.c       PATH resolution
  errors.c                              errors_bonus.c     errors + exit status
                                        setup_bonus.c      parsing, files, wait
                                        heredoc_bonus.c    here_doc reader

libft/                                                     personal C library
```

The mandatory and bonus sources live in two separate directories and are
compiled into two separate object directories (`obj/` and `obj_bonus/`), so
`make` and `make bonus` never interfere with each other.

## Resources

- `man 2 pipe`, `man 2 fork`, `man 2 dup2`, `man 2 execve`, `man 2 waitpid`,
  `man 2 access`, `man 2 open`
- *Advanced Programming in the UNIX Environment* (Stevens & Rago), chapters on
  process control and interprocess communication
- POSIX specification of shell pipelines and redirections:
  https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
- Bash reference manual, "Pipelines" and "Here Documents" sections:
  https://www.gnu.org/software/bash/manual/bash.html

### Use of AI

An AI assistant was used on this project for:

- reading and summarising the subject requirements;
- discussing the process/file-descriptor design before writing it (which end of the pipe each child must close, and why a here-document needs its own writer process rather than a plain write() into the pipe);
- reviewing the code specifically for memory leaks and ensuring allocated memory was properly freed.

Every design decision, and every line that ended up in this repository, was read, understood and verified by hand against bash, valgrind (with --trace-children=yes --track-fds=yes) and norminette.
