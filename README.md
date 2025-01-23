# CS-235-Data-Structures
BYU CS 235 Data Structures Class in C++

## Homework 2a: Unique Lines
Reads file provided in console argument and outputs to console each unique line.

This project demonstrates i/o stream, file stream, and unordered set technologies.

## Homework 2b: VectorSet
tests.cpp was provided by BYU.
VectorSet is a data structure class that using an underlying vector and set combine functionality of both including:
- each element is unique
- contains, insert, remove, size, empty, and clear functions

This project demonstrates use of set and vector data structures as well as OOP for classes and data structures in general.

## Homework 2c: Priority Queues
input.h was provided by BYU.
This is a basic commandline queue program that supports the operations "add" and "take". You can "add" names and priority integers to the queue and then "take" the person with the highest priority out of the queue.

This project demonstrates use of priority queue and c++ cout/cin.

## Homework 2d: Text Generators
basic_text_generation.cpp: Trains by mapping each word in an input file to a list of each word that comes after it (including duplicates). It then prints a specified number of words to the console. It does this by selecting a random word from the list associated with the last word printed, starting with "".

improved_text_generation.cpp: Like basic_text_generation, but now it maps a key of 2 words to a list of the 3rd word. It also allows you to optionally specify the first word. The provided KJV Bible is recommended as a useful dataset to test with.

This project demonstrates the use of file input, console output, unordered maps, vectors, strings, and random.

## Homework 3b: Maze Solver
Grid.h was provided by BYU.
This program solves a maze of the format of the provided test files, with the first line giving the number rows, columns, and levels. The subsequent lines are divided into contiguous floors with 1 representing spaces and 0 representing walls. The first floor in the file is the bottom floor. Starting the in upper left corner of the bottom floor (at 0,0,0) the solver recursively checks until it finds a valid path to the lower right corner of the top floor. It outputs the solution from start to finish in the form of one set of coordinates per line to the output text file in the form of (row, col, floor).

This project demonstrates recursion, nested data structures, and file i/o.