*This project has been created as part of the 42 curriculum by eduaaugu, jcesar-o.*

# Table of Contents
1. Description
2. Instructions
   * Requirements
   * Compilation
   * Execution
   * Sorting Strategy Flags
   * Benchmark Mode
   * Evaluation Helpers
   * Input Validation
   * Cleaning
3. Algorithms
   * Simple Strategy — O(n²)
   * Medium Strategy — O(n√n)
   * Complex Strategy — O(n log n)
   * Adaptive Strategy
4. Resources
   * References
   * AI Usage
5. Contributions
   * eduaaugu
   * jcesar-o

# Description

**push_swap** is an algorithm design project developed as part of the 42 curriculum. Its goal is to sort a sequence of integers using two stacks and a restricted set of stack operations while minimizing the total number of operations performed.

The program receives a list of integers from the command line, validates the input, stores the values in stack-based data structures, and selects an appropriate sorting strategy according to the characteristics of the input. Throughout the project, different algorithms with distinct time complexities were implemented and compared, emphasizing algorithm analysis, data structure manipulation, and optimization under constrained rules.


# Instructions

## Requirements

This project requires a C compiler compatible with the C99 standard, **GNU Make**, and a Unix-like operating system (Linux is recommended).

## Compilation

Compile the project by running:

```bash
make
```

This command builds the project and generates the `push_swap` executable.

## Execution

Run the executable by providing a sequence of integers as command-line arguments:

```bash
./push_swap 4 67 3 87 23
```

The program prints the sequence of stack operations required to sort the input while respecting the constraints defined in the project subject.

## Sorting Strategy Flags

In addition to the mandatory behavior defined by the subject, this implementation provides optional flags that allow a specific sorting strategy to be selected manually.

Available strategies:

```bash
--simple
--medium
--complex
```

Example:

```bash
./push_swap --simple 4 67 3 87 23
```

If no strategy flag is provided, the program automatically selects the most appropriate algorithm according to the measured disorder of the input sequence.

As an optimization, inputs containing **five or fewer elements** always use a specialized sorting routine (simple_sort), regardless of the measured disorder. Since these small cases have optimal dedicated solutions, this avoids unnecessary execution of the general-purpose sorting algorithms while preserving the adaptive strategy for larger inputs.

Only **one strategy flag** may be specified at a time. Providing multiple strategy flags simultaneously results in an error.

## Benchmark Mode

The project also provides an optional benchmark mode:

```bash
--bench
```

Example:

```bash
./push_swap --bench 4 67 3 87 23
```

When enabled, the program executes normally and additionally displays benchmarking information, including:

* Measured input disorder.
* Selected sorting strategy.
* Total number of operations performed.
* Number of executions of each allowed stack operation.

The benchmark mode may be combined with any sorting strategy.

## Evaluation Helpers

The following commands may be useful during the evaluation process.

### Memory Leak Check

Run the program with **Valgrind** to verify that no memory leaks are present:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2 1 3 6 5 8 7 12 9 4
```

### Functional Test

Generate a random input, count the number of operations produced by `push_swap`, and verify the result using the official `checker_linux` program:

```bash
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
OPS=$(./push_swap ${=ARG} | wc -l)
RES=$(./push_swap ${=ARG} | ./checker_linux ${=ARG})

echo "operations: $OPS"
echo "checker: $RES"
```

## Input Validation

The program validates all command-line arguments before execution. The following situations generate an error:

* Invalid or unsupported command-line arguments.
* Duplicate integer values.
* Integer values outside the valid `int` range.
* More than one sorting strategy flag (`--simple`, `--medium`, or `--complex`).
* Duplicate mode flags.

## Cleaning

Remove object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Rebuild the project from scratch:

```bash
make re
```

# Algorithms

This project implements four sorting strategies with different computational complexities. Each strategy was selected to satisfy the requirements defined by the project specification while providing an opportunity to study different algorithmic approaches under the constraints of the *push_swap* problem.

## Simple Strategy — O(n²)

The simple strategy is based on **Selection Sort**. Before sorting, every value is assigned a rank (`rank_index`), replacing arbitrary integer values with indices ranging from `0` to `n - 1`. During each iteration, the algorithm rotates stack **A** until the smallest remaining index reaches the top, pushes it to stack **B**, and repeats the process until stack **A** is empty. Finally, all elements are pushed back to **A**, producing a sorted sequence.

For input sequences containing **three elements**, a specialized routine (`tiny_sort`) is used instead. Since every possible permutation is known, the sequence can be sorted using a minimal number of stack operations.

Selection Sort was chosen because of its simplicity and deterministic behavior. Although its time complexity is **O(n²)**, it performs well on very small inputs and provides an optimal solution for the low-disorder regime required by the project.

## Medium Strategy — O(n√n)

The medium strategy implements **Chunk Sort**. After assigning ranks to every element, the input is divided into chunks whose size is approximately equal to the ceiling of √n.

The algorithm repeatedly searches for the closest element belonging to the current chunk, rotates stack **A** in the shortest direction until that element reaches the top, and pushes it to stack **B**. Once all elements of the current chunk have been processed, the algorithm proceeds to the next chunk. After every chunk has been transferred, the elements are restored to stack **A** in descending index order.

Using chunks reduces the search space during each iteration, resulting in an overall complexity of approximately **O(n√n)** while remaining relatively simple to implement using only the operations allowed by the project.

## Complex Strategy — O(n log n)

The complex strategy is based on **Radix Sort** using the binary representation of each element's rank.

Instead of sorting the original integer values, the algorithm first assigns consecutive indices (`0` to `n - 1`). It then processes the indices one bit at a time, starting from the least significant bit. During each pass:

* Elements whose current bit is **0** are pushed to stack **B**.
* Elements whose current bit is **1** remain in stack **A** through rotation.
* Once every element has been processed for the current bit, all elements are pushed back from **B** to **A**.

This process is repeated until every significant bit has been examined.

Radix Sort was selected because it provides predictable performance, is particularly well suited to the *push_swap* operation model, and satisfies the required **O(n log n)** complexity while remaining straightforward to implement.

## Adaptive Strategy

The adaptive strategy automatically selects the most appropriate sorting algorithm according to the measured disorder of the input sequence.

The following rules are applied:

* Inputs containing **five or fewer elements** always use the specialized `simple_sort` implementation.
* If the measured disorder is **less than 0.2**, the project uses the **Simple Strategy (O(n²))**.
* If the measured disorder is **between 0.2 and 0.5**, the project uses the **Medium Strategy (O(n√n))**.
* If the measured disorder is **greater than or equal to 0.5**, the project uses the **Complex Strategy (O(n log n))**.


This adaptive approach combines the strengths of each algorithm by selecting the most appropriate strategy for the characteristics of the input while satisfying the complexity requirements established by the project specification.

# Resources

## References

The following resources were consulted during the development of this project:

* **42 push_swap Subject:** used as the primary specification for the project requirements and evaluation criteria.
* **42 Norm:** followed throughout the implementation to ensure compliance with the school's coding standard.
* **Linux Manual Pages (`man`):** consulted for C library functions and system calls.
* **GeeksforGeeks:** used to study sorting algorithms, time complexity analysis, and data structure concepts.
* **Wikipedia:** consulted for general descriptions of sorting algorithms and their theoretical properties.
* **Donald E. Knuth — *The Art of Computer Programming, Volume 3: Sorting and Searching*:** used as a classic reference for sorting algorithms and algorithm analysis.

## AI Usage

Artificial Intelligence was used exclusively as a learning and development assistant during this project. Its contributions included:

* Explaining algorithmic concepts such as Selection Sort, Chunk Sort, Radix Sort, and their computational complexities.
* Discussing implementation strategies and design alternatives.
* Reviewing code structure and suggesting refactoring opportunities.
* Assisting in debugging and identifying implementation issues.
* Reviewing and improving the project documentation.

All algorithms, data structures, project architecture, and source code were created, implemented, tested, and validated by the project authors.

# Contributions

## eduaaugu

* Designed and implemented the sorting algorithms (`Selection Sort`, `Chunk Sort`, `Radix Sort`, and the adaptive strategy).
* Implemented the stack operations (`sa`, `pb`, `ra`, `rr`, `rra`, etc.).
* Developed the project architecture and algorithm interfaces.
* Wrote and maintained a significant portion of the project documentation (`README.md`).
* Performed debugging, testing, optimization, and code refactoring.

## jcesar-o

* Implemented the command-line parser and input validation.
* Developed the command-line interface, including strategy selection and benchmark flags.
* Implemented the benchmarking system and performance metrics.
* Wrote and maintained a significant portion of the project documentation (`README.md`).
* Performed debugging, testing, optimization, and code refactoring.
