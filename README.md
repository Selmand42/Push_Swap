# Push Swap

## Table of Contents
- [Description](#description)
- [Rules](#rules)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Project Structure](#project-structure)
- [Optimization](#optimization)
- [Testing](#testing)
- [Resources](#resources)

## Description

Push Swap is a sorting algorithm project from 42 School that challenges you to sort data on a stack with a limited set of instructions, using the lowest possible number of actions. To succeed, you'll need to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

The goal is to sort a stack of integers in ascending order using two stacks (A and B) and a specific set of operations.

## Rules

- You have 2 stacks named **A** and **B**
- Stack **A** contains a random amount of negative and/or positive integers which cannot be duplicated
- Stack **B** is empty
- The goal is to sort in ascending order numbers into stack **A**
- You have the following operations at your disposal:

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of stack B at the top of stack A |
| `pb` | Push the first element of stack A at the top of stack B |
| `ra` | Rotate stack A (shift up all elements by 1) |
| `rb` | Rotate stack B (shift up all elements by 1) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (shift down all elements by 1) |
| `rrb` | Reverse rotate stack B (shift down all elements by 1) |
| `rrr` | `rra` and `rrb` at the same time |

## Algorithm

This implementation uses a **Turk Algorithm** approach, which is an efficient method for solving the push_swap problem:

### Strategy Overview:
1. **Push to B**: Move all elements except 3 from stack A to stack B
2. **Sort 3 in A**: Sort the remaining 3 elements in stack A
3. **Calculate Costs**: For each element in B, calculate the cost to move it to its correct position in A
4. **Move Cheapest**: Move the element with the lowest cost from B to A
5. **Repeat**: Continue until B is empty
6. **Final Sort**: Rotate A to have the smallest element on top

### Cost Calculation:
- For each element in B, calculate how many moves are needed to:
  - Bring it to the top of B
  - Position A to receive it in the correct sorted position
  - Move it from B to A

## Installation

```bash
# Clone the repository
git clone [repository-url]
cd push_swap

# Compile
make

# Clean object files
make clean

# Remove all generated files
make fclean

# Recompile everything
make re
```

## Usage

```bash
# Basic usage
./push_swap [list of integers]

# Example
./push_swap 2 1 3 6 5 8

# Using with checker (if available)
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
```

### Input Requirements:
- Only integers
- No duplicates
- Can be negative or positive
- Arguments can be passed as separate parameters or as a quoted string

## Example

```bash
$ ./push_swap 2 1 3 6 5 8
pb
pb
pb
sa
pa
pa
pa
```

This sequence of operations will sort the stack `[2, 1, 3, 6, 5, 8]` into ascending order.

## Project Structure

```
.
├── Makefile
├── README.md
├── push_swap.h          # Header file with structures and function prototypes
├── main.c               # Main function and argument parsing
├── fill_first_stack.c   # Stack initialization functions
├── sort.c               # Main sorting algorithm
├── push_b.c             # Functions for pushing elements to stack B
├── back_to_a.c          # Functions for moving elements back to stack A
├── prepare_to_push.c    # Cost calculation and preparation functions
├── stack/               # Stack operation functions
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   └── reverse_rotate.c
└── libft/               # Custom C library (if used)
```

## Optimization

### Performance Targets:
- **3 numbers**: Maximum 3 operations
- **5 numbers**: Maximum 12 operations
- **100 numbers**: Less than 700 operations (5 points), less than 900 operations (4 points)
- **500 numbers**: Less than 5500 operations (5 points), less than 7000 operations (4 points)

### Key Optimizations:
1. **Smart element selection**: Choose the element with minimum cost to move
2. **Combined operations**: Use `rr`, `rrr`, `ss` when possible
3. **Efficient positioning**: Calculate optimal positions for elements
4. **Small stack handling**: Special cases for 2, 3, and 5 elements

## Testing

### Test with random numbers:
```bash
# Test with 100 random numbers
ARG=$(seq 1 100 | sort -R | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with checker
ARG=$(seq 1 100 | sort -R | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

### Test edge cases:
```bash
# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

# With negative numbers
./push_swap -1 -2 0 1 2

# Single number
./push_swap 42

# Two numbers
./push_swap 2 1
```

## Resources

- [42 Push Swap Subject](https://cdn.intra.42.fr/pdf/pdf/960/en.subject.pdf)
- [Turk Algorithm Explanation](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Visualizer Tool](https://github.com/o-reo/push_swap_visualizer)

## Error Handling

The program handles various error cases:
- Non-integer arguments
- Duplicate numbers
- Integer overflow
- Empty arguments
- Invalid format

All errors result in printing "Error" to stderr and exiting with status code 1.

---

**Grade**: This implementation aims for the maximum score by achieving optimal operation counts for all test cases.

**Note**: This project is part of the 42 School curriculum and follows the school's coding standards (Norm).
