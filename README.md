# PIPEX

Pipex is a project you’ll likely encounter on your 42 journey, and one which may give you a bit of a headache. Its purpose is to teach you some basic UNIX operations, and will greatly help you in the completion of Minishell (a mandatory project you’ll face later).

Pipex focuses on three main concepts: pipelines, child processes and execution of commands. This guide will cover all three of these topics as best as it can, and guide you through the main parts of the program.

## Installation

Clone the repository and compile the project:

```bash
git clone <repository-url>
cd pipex
make

## Usage

Run the program with the following command:

./pipex file1 cmd1 cmd2 file2

Where:

file1: Input file whose content will be processed by cmd1.
cmd1: First command to be executed.
cmd2: Second command to be executed.
file2: Output file where the result will be saved.