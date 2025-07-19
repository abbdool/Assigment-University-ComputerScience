📌 Overview
Jojo is a data structure student who has been assigned to implement a Min-Heap using an array. Your task is to help him by building a program that allows inserting integers into a Min-Heap and removing the minimum value (i.e., the root), following specific rules for input and output formatting.

📥 Input Specification
The program continuously receives integer inputs from the user.

The behavior depends on the input value:

If the input is 0 → terminate the program.

If the input is the same as the current root (i.e., the smallest element in the heap) → perform delete-min (remove the root).

If the input is a number other than the root → print a "wrong number" message.

If the heap is empty, any input other than 0 will be treated as an insert.

📤 Output Specification
For every input:

Print the corresponding activity:

"add" if a number is inserted into the Min-Heap.

"delete-min" if the root is successfully removed.

"wrong number" if the number is not the root but already exists in the heap.

After every operation (insert/delete/wrong number):

Print the contents of the heap level by level, each level on a new line.
