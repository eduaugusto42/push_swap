*This project has been created as part of the 42 curriculum by eduaaugu, jcesar-o.*

# Description

**push_swap** is a sorting algorithm project developed as part of the 42 curriculum. Its goal is to sort a sequence of integers using two stacks and a restricted set of stack operations while minimizing the total number of moves.

The program receives a list of integers through the command line, validates the input, stores the values in stacks, and applies an efficient sorting strategy based on the allowed operations. The project focuses on algorithm optimization, data structure manipulation, and efficient problem-solving under constrained rules.

# Instructions

## Compilation

To compile the project, run the following command in the project directory:

```bash
make
```

This will generate the executable file required to run the program.

## Execution

Run the program by providing a sequence of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

The program will output the sequence of operations required to sort the given numbers.

## Sorting Strategy Flags

The program supports three flags to manually select the sorting strategy:

```bash
--simple
--medium
--complex
```

Example:

```bash
./push_swap --simple 4 67 3 87 23
```

When one of these flags is provided, the program will execute the corresponding sorting strategy.

If none of these flags are specified, the program automatically selects the most appropriate strategy based on the level of disorder of the input sequence.

The program accepts only **one strategy flag** at a time. Providing two or more strategy flags simultaneously will result in an error.

## Benchmark Mode

The program also supports a benchmark flag:

```bash
--bench
```

Example:

```bash
./push_swap --bench 4 67 3 87 23
```

When enabled, the program will execute normally and, in addition to displaying the sorting operations, it will output performance metrics collected during execution.

## Input Validation

The program validates all command-line arguments. The following situations will generate an error:

- Providing more than one strategy selection flag (`--simple`, `--medium`, `--complex`).
- Using duplicated branch/mode flags.
- Providing invalid input values or unsupported arguments.

## Cleaning

To remove generated object files:

```bash
make clean
```

To remove all compiled files and rebuild the project from scratch:

```bash
make fclean
make
```
# Resources

The following resources were consulted during the development of this project:

- **42 push_swap Subject:** used as the main specification for the project requirements and evaluation criteria.
- **42 Norm:** followed to ensure compliance with the coding standard.
- **Linux Manual Pages (`man`):** consulted for C library functions and system calls.
- **Stack Data Structure Documentation:** used as a reference for the implementation of the stack data structure and its operations.

All source code was written specifically for this project. The resources above were used solely for study and reference purposes.

## jcesar-o

- Implemented the command-line parser and input validation.
- Developed the strategy selection and benchmark flags.
- Implemented the benchmark output.
- Contributed to the project documentation.