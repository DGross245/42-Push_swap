# 42-Push_swap

PushSwap is a sorting algorithm project developed as part of the curriculum at 42. The goal of PushSwap is to sort a stack of integers using a limited set of stack manipulation operations.

## Problem Statement

Given two stacks, Stack A and Stack B, initially populated with a random sequence of integers, the task is to sort Stack A in ascending order using the following operations:

- `sa`: Swap the first two elements of Stack A.
- `sb`: Swap the first two elements of Stack B.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the first element of Stack B onto Stack A.
- `pb`: Push the first element of Stack A onto Stack B.
- `ra`: Rotate all elements of Stack A upward by one position.
- `rb`: Rotate all elements of Stack B upward by one position.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Rotate all elements of Stack A downward by one position.
- `rrb`: Rotate all elements of Stack B downward by one position.
- `rrr`: Perform `rra` and `rrb` simultaneously.

The goal is to implement an algorithm that sorts Stack A with the fewest number of operations possible.

## Usage

To run the PushSwap program, execute the following commands:

```bash
make
./push_swap [list of integers]
```

Replace `[list of integers]` with the sequence of integers you want to sort.

## Example

To sort the sequence {3, 1, 5, 4, 2}, run the following command:

```bash
./push_swap 3 1 5 4 2
```

This will output a series of instructions to sort the stack.
