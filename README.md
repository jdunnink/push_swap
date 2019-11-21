
Push_swap is a program that, given a list of unsorted integers, tries to sort that list with the least amount of instructions. The program uses two stacks, A and B
and the following list of operations:

-   Rotate A --> rotate the values in stack A one place to the right.
-   Rotate B --> rotate the values in stack B one place to the right.
-   Rotate-Rotate --> rotate both stacks one place to the right.
-   Rev-Rotate A --> rotate the values in stack A one place to the left.
-   Rev-Rotate B --> rotate the values in stack A one place to the left.
-   Rev-Rotate-Rotate --> execute rev-rotate on both stacks.
-   Swap A --> swap the value at the top of stack A with the next value in stack A.
-   Swap B --> swap the value at the top of stack B with the next value in stack B.
-   Swap-Swap --> execute swaps on both stacks.
-   Push A --> Push the value at the top of stack B to the top of stack A.
-   Push B --> Push the value at the top of stack A to the top of stack B.

Apart from the instructions listed above, no other manipulation of the two stacks is allowed.

Run the Makefile in the root of this repo to compile the push_swap binary and a checker binary. push_swap receives the list of integers as argument, either formatted as a single string, or multiple arguments. It then returns a list of instruction abbreviations that, when executed on the stacks, would sort the given list. checker is then able to read this
list of instructions from the standard output and execute them on the integer list passed as argument. checker returns OK if the list is sorted after executing all the instructions and KO if not.