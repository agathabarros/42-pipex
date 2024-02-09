# PIPEX

Pipex is a project you’ll likely encounter on your 42 journey, and one which may give you a bit of a headache. Its purpose is to teach you some basic UNIX operations, and will greatly help you in the completion of Minishell (a mandatory project you’ll face later).

Pipex focuses on three main concepts: pipelines, child processes and execution of commands. This guide will cover all three of these topics as best as it can, and guide you through the main parts of the program.

## Installation

To get started, clone the repository and compile the project:

```bash
git clone https://github.com/agathabarros/42-pipex.git
cd pipex
make 
```

## Usage

Execute the program using the following command:
```bash
./pipex file1 cmd1 cmd2 file2
```

### Arguments:
* file1: Input file that will undergo processing by cmd1.
* cmd1: Initial command for execution.
* cmd2: Subsequent command for execution.
* file2: Output file to store the resulting data.

### <span style="font-size: 5 px;">Example:</span>

```bash
 ./pipeline input.txt "grep error" "sort" output.txt
```

In this example, the command pipeline executes the commands grep error and sort sequentially. It searches for lines containing the word "error" in the file input.txt, sorts the lines alphabetically, and then saves the result in the file output.txt.
