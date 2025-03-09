# INET 3101 Lab 2 - Dynamic Memory Management

## Project Overview
This project is part of the INET 3101: C Programming Language and Applications course. The main focus of this lab is to demonstrate the use of dynamic memory management in C through the implementation of a simple in-memory database for storing records about various parts.

## Learning Objectives
1. Understand and implement dynamic memory management in C.
2. Explore the use of structures for handling multiple data types.
3. Demonstrate effective memory usage and management to prevent memory leaks.

## Features
- **Dynamic Memory Allocation**: Utilize `malloc` and `realloc` to manage memory for storing records dynamically.
- **Memory Reallocation**: Properly handle memory resizing when adding or deleting records.
- **Menu-Driven Interface**: Allows the user to add records, delete records, and view all records through a simple console menu.

## Compilation and Execution
To compile and run this project:

1. Ensure you have a C compiler installed, such as GCC or Clang.
2. Navigate to the directory containing the project files.
3. Run the following commands:
   ```bash
   gcc -o part_record main.c
   ./part_record

## Menu Options
1. Add Record: Add a new record to the database.
2. Delete Record: Remove the last record from the database.
3. Print All Records: Display all records currently stored.
4. Exit: Terminate the program.



