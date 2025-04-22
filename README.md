<p align="center"><img src="https://github.com/jerome244/holbertonschool-simple_shell/blob/main/img/images.png"></p>

# C - Simple Shell Group Project
Team: Jerome TRAN.

## INTRODUCTION
A shell is an user interface that provides access to an operating system's services. This same program can interpret and execute commands.

## GENERAL
- **Who designed and implemented the original Unix operating system:**

The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie in the early 1970s.

- **Who wrote the first version of the UNIX shell**

Ken Thompson wrote the first version of the UNIX shell.

- **Who invented the B programming language (the direct predecessor to the C programming language)**

Ken Thompson.

- **Who is Ken Thompson**

Ken Thompson is a computer scientist and one of the main developers of the Unix operating system.

- **How does a shell work?**

A shell serves as a pivotal command-line interpreter, bridging the interaction between users and the operating system.

- **What is a pid and a ppid?**

A PID is a unique numerical identifier assigned to each running process in an operating system.
It is used to distinguish one process from another.
PIDs are assigned dynamically as processes are created.

PPID refers to the PID's parent process. Every process, except for the initial or root process, has a parent process.
The PPID is used to establish the hierarchical or parent-child relationship between processes.


- **How to manipulate the environment of the current process**

The environment of the current process can be manipulated by using environment variables. Commands like `export` in Unix/Linux shells are used to set those variables.

- **What is the difference between a function and a system call**

A function is a code that performs a specific task. A system call is a request for a service from the operating system kernel.

- **How to create processes**

Processes can be created by using a system called such as the fork function in the C programming language. In this example this function initiates the creation of a new process by duplicating the existing process.

- **What are the three prototypes of main**

In c language the three prototypes of the `main` function are:
    - `int main(void)`
    - `int main(int argc, char *argv[])`
    - `int main(int argc, char *argv[], char *envp[])`

- **How does the shell use the `PATH` to find the programs**

The shell uses the PATH environment as executables library. If the user call one of them, the shell will execute the called function if found.

- **How to execute another program with the `execve` system call**

The `execve()` system call in C is used to execute another program by replacing the current process with a another one.

- **How to suspend the execution of a process until one of its children terminates**

The `wait()` can be used for this task.

- **What is `EOF` / “end-of-file”?**

It is a key-word foundable in a file or a stream of data that indicates that there is no more data to be read.

## Requirements

Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be include guarded

Use system calls only when you need to 


### Compilation

Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

## Tasks

### 0. README, man, AUTHORS
Write a README

Write a man for your shell.

You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

### 1. Betty would be proud
Write a beautiful code that passes the Betty checks

### 2. Simple shell 0.1
Write a UNIX command line interpreter.

Usage: simple_shell

Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.

The prompt is displayed again each time a command has been executed.

The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

The command lines are made only of one word. No arguments will be passed to programs.

If an executable cannot be found, print an error message and display the prompt again.

Handle errors.

You have to handle the “end of file” condition (Ctrl+D)

### 3. Simple shell 0.2
Handle command lines with arguments

### 4. Simple shell 0.3

Handle the PATH

fork must not be called if the command doesn’t exist
### 5. Simple shell 0.4

Implement the exit built-in, that exits the shell

Usage: exit

You don’t have to handle any argument to the built-in exit

### 6. Simple shell 1.0

Implement the env built-in, that prints the current environment

## Files

|File|Description|
|---|---|
|[AUTHORS](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/AUTHORS)|Contributors of this repository|
|[README.md](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/README.md)|Informations about this repository|
|[_getline.c](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/_getline.c)|Function to get user's input and write it into the buffer|
|[main.c](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/main.c)|Main function of this application|
|[tokenizer.c](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/tokenizer.c)|For splitting and parsing the user's input into an array|
|[pathfinder.c](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/pathfinder.c)|Find a function inside the library of environment variables also called the PATH|
|[man_1_simple_shell](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/man_1_simple_shell)|Manual page of this application|
|[shell.h](https://github.com/jerome244/holbertonschool-simple_shell/blob/master/shell.h)|List of used libraries and functions prototypes|

## Flowchart

<p align="center"><img src="https://github.com/jerome244/holbertonschool-simple_shell/blob/main/img/flowchart.png"></p>

## Author
*	Jerome TRAN-[Github]https://github.com/jerome244/
