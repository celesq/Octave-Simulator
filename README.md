# Octave-Simulator
This Octave Simulator implements basic functionalities of the Octave programming language using dynamic memory allocation in C. It allows users to load matrices, obtain their dimensions, perform mathematical operations (multiplication, transposition), resize and free matrices, all through a command-line interface.

# User Guide

## Loading a Matrix
   - **Command:** `L m n`
   - **Parameters:**
     - `m`: Number of rows.
     - `n`: Number of columns.
     - Followed by `m * n` integers representing the matrix elements.
   - **Example:** `L 4 7 3 51 75 3 6 27 2 3 10 20 95 19 21 100 8 4 71 3 32 50 29 40 25 5 12 49 29 40 17 63 29`
   - **Description:** This command loads a new matrix into memory, adding it to the end of the matrix list.

## Determining the Dimensions of a Matrix
   - **Command:** `D index`
   - **Parameters:**
     - `index`: The index of the matrix whose dimensions you want to determine.
   - **Example:** `D 0`
   - **Output:** Displays the number of rows and columns of the matrix at the specified index, or an error message if the index is invalid.

## Displaying a Matrix
   - **Command:** `P index`
   - **Parameters:**
     - `index`: The index of the matrix you wish to display.
   - **Example:** `P 0`
   - **Output:** Shows the elements of the matrix at the given index or an error message if the index is invalid.

## Resizing a Matrix
   - **Command:** `C index`
   - **Parameters:**
     - `index`: The index of the matrix to resize.
     - Followed by an integer indicating the number of new rows, followed by that many row indices, and then the number of new columns followed by column indices.
   - **Example:** `C 0 2 3 3 1 4 3`
   - **Description:** Resizes the specified matrix in-place, rearranging rows and columns according to the given indices.

## Multiplying Two Matrices
   - **Command:** `M index1 index2`
   - **Parameters:**
     - `index1`: The index of the first matrix.
     - `index2`: The index of the second matrix.
   - **Example:** `M 1 2`
   - **Output:** If successful, adds the resulting product matrix to the end of the matrix list. Displays an error if the multiplication cannot be performed due to dimension mismatch or if an index is invalid.

## Sorting Matrices
   - **Command:** `O`
   - **Parameters:** None
   - **Description:** Sorts the matrices in memory in ascending order based on the sum of all their elements modulo \(10^4 + 7\). 

## Transposing a Matrix
   - **Command:** `T index`
   - **Parameters:**
     - `index`: The index of the matrix to transpose.
   - **Example:** `T 0`
   - **Output:** Transposes the specified matrix in-place. Displays an error if the index is invalid.

## Raising a Matrix to a Power
   - **Command:** `R index power`
   - **Parameters:**
     - `index`: The index of the matrix to raise.
     - `power`: The exponent to which the matrix should be raised.
   - **Example:** `R 0 5`
   - **Output:** Raises the specified matrix to the given power in-place. Error messages are displayed for invalid indices or if the power is negative.

## Freeing Memory of a Matrix
   - **Command:** `F index`
   - **Parameters:**
     - `index`: The index of the matrix whose memory should be freed.
   - **Example:** `F 0`
   - **Output:** Frees the memory of the specified matrix and removes it from the matrix list. Displays an error if the index is invalid.

## Exiting the Program
   - **Command:** `Q`
   - **Parameters:** None
   - **Description:** Ends the program and frees all allocated resources.

## Error Handling
If an unrecognized command is entered, the program will display the message: **“Unrecognized command.”** 

Make sure to enter the commands and parameters correctly to avoid execution errors. The program assumes that all input is valid according to the specifications provided. Enjoy using the Octave Simulator!

# Implementation Overview

The designed program creates a three-dimensional matrix and employs a resizable array algorithm to adjust its size whenever a new matrix needs to be added. The dimensions of the matrices are stored in dynamically allocated arrays, facilitating efficient memory management and scalability.

The core functionality is governed by a switch-case structure that processes commands read from standard input (STDIN). This structure operates within an infinite loop that continues until the command character `Q` is received, which triggers memory deallocation and terminates the program.

To enhance modularity and maintainability, each command is encapsulated within its dedicated function. This design approach allows for cleaner code organization and easier debugging.

### Key Functionalities

1. **Matrix Resizing:**
   In the resizing function, matrix dimensions are stored in arrays. A copy of the current matrix is maintained to facilitate the transfer of values into the newly resized matrix. This approach ensures that all existing data is preserved and properly managed during resizing operations.

2. **Sorting Matrices:**
   The sorting function utilizes the selection sort algorithm to order matrices based on the sum of their elements, calculated modulo 10007. This function sorts both the matrix elements and their respective dimensions concurrently, ensuring that matrices are efficiently arranged in ascending order while maintaining consistency in their properties.

3. **Transposing a Matrix:**
   For the transpose function, a dynamically allocated copy of the original matrix is created to facilitate the transfer of values into the transposed matrix. The function accurately swaps rows and columns, and once the transposition is complete, it deallocates the memory previously allocated for the temporary storage.

4. **Matrix Multiplication:**
   The matrix multiplication function employs a traditional \(O(n^3)\) algorithm, ensuring that each operation adheres to the modulo 10007 constraint to prevent overflow and maintain numerical accuracy. The resulting matrix from the multiplication is appended to the end of the three-dimensional matrix structure.

5. **Exponentiation of a Matrix:**
   To efficiently raise a matrix to a given power, the program recursively employs the matrix multiplication function. This approach reduces the computational complexity to \(O(\log n)\), enhancing performance for larger matrices.

6. **Memory Deallocation:**
   The program includes specific functions for freeing dynamically allocated memory. This process ensures that all resources are properly released when they are no longer needed, preventing memory leaks and optimizing resource management.

Overall, the implementation focuses on modular design, efficient memory handling, and the use of standard algorithms to provide a robust solution for simulating matrix operations akin to those found in the Octave programming language.
