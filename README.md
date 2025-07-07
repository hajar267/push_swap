📦 Push Swap - 42 School Project

🧑‍💻 Author
Hajar Fiqar
Student at 42 School
💻 Passionate about algorithms and clean C code

       *********************************

🧩 About the Project
Push Swap is a classic sorting algorithm project from the 42 School curriculum.
The goal is to sort a stack of integers using a limited set of operations, with the fewest moves possible.
You must write a program that outputs the sequence of operations needed to sort the stack.

This project tests your problem-solving skills, algorithmic thinking, and ability to write efficient, 
optimized code under strict constraints.

🚀 How It Works
The project is built around two stacks, A and B, and a limited set of operations:

sa / sb / ss — Swap the first two elements of a stack.

pa / pb — Push the top element from one stack to another.

ra / rb / rr — Rotate a stack upwards.

rra / rrb / rrr — Reverse rotate a stack.
The goal is to sort Stack A in ascending order, using as few operations as possible.

💡 My Approach: Chunks Algorithm
For large input sizes, I implemented a Chunks Algorithm, a popular and efficient strategy for Push Swap:

✔ The stack is divided into smaller groups, called "chunks".
✔ The algorithm iteratively pushes elements from Stack A to Stack B based on their position in the sorted sequence.
✔ Once all chunks are transferred, the elements are pushed back to Stack A in sorted order.
✔ This approach significantly reduces the total number of operations compared to brute-force methods.

📦 Why Chunks Algorithm?
Efficient for large datasets (100, 500+ numbers).

Helps maintain order when moving elements between stacks.

Simple to adapt and tune for different input sizes.
