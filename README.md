# Pipex

I learned how to recreate pipe functionality by managing child processes and controlling how data flows between programs.

## Description

Reproduces the behavior of shell pipes (`|`), allowing command chaining between input and output files. Implements process forking and file descriptor management.

## Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

This executes the equivalent of:
```bash
< infile cmd1 | cmd2 > outfile
```

### Example
```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```
Equivalent to:
```bash
< input.txt grep hello | wc -l > output.txt
```

### Requirements
- Input file must exist and be readable
- Commands must be valid shell commands
- Use quotes for commands with parameters

