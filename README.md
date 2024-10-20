# Octave-Simulator
This Octave Simulator implements basic functionalities of the Octave programming language using dynamic memory allocation in C. It allows users to load matrices, obtain their dimensions, perform mathematical operations (multiplication, transposition), resize and free matrices, all through a command-line interface.

## User Guide

## Loading a Matrix
   - **Command:** `L m n`
   - **Parameters:**
     - `m`: Number of rows.
     - `n`: Number of columns.
     - Followed by `m * n` integers representing the matrix elements.
   - **Example:** `L 4 7 3 51 75 3 6 27 2 3 10 20 95 19 21 100 8 4 71 3 32 50 29 40 25 5 12 49 29 40 17 63 29`
   - **Description:** This command loads a new matrix into memory, adding it to the end of the matrix list.

### Determining the Dimensions of a Matrix
   - **Command:** `D index`
   - **Parameters:**
     - `index`: The index of the matrix whose dimensions you want to determine.
   - **Example:** `D 0`
   - **Output:** Displays the number of rows and columns of the matrix at the specified index, or an error message if the index is invalid.

### Displaying a Matrix
   - **Command:** `P index`
   - **Parameters:**
     - `index`: The index of the matrix you wish to display.
   - **Example:** `P 0`
   - **Output:** Shows the elements of the matrix at the given index or an error message if the index is invalid.

### Resizing a Matrix
   - **Command:** `C index`
   - **Parameters:**
     - `index`: The index of the matrix to resize.
     - Followed by an integer indicating the number of new rows, followed by that many row indices, and then the number of new columns followed by column indices.
   - **Example:** `C 0 2 3 3 1 4 3`
   - **Description:** Resizes the specified matrix in-place, rearranging rows and columns according to the given indices.

### Multiplying Two Matrices
   - **Command:** `M index1 index2`
   - **Parameters:**
     - `index1`: The index of the first matrix.
     - `index2`: The index of the second matrix.
   - **Example:** `M 1 2`
   - **Output:** If successful, adds the resulting product matrix to the end of the matrix list. Displays an error if the multiplication cannot be performed due to dimension mismatch or if an index is invalid.

### Sorting Matrices
   - **Command:** `O`
   - **Parameters:** None
   - **Description:** Sorts the matrices in memory in ascending order based on the sum of all their elements modulo \(10^4 + 7\). 

### Transposing a Matrix
   - **Command:** `T index`
   - **Parameters:**
     - `index`: The index of the matrix to transpose.
   - **Example:** `T 0`
   - **Output:** Transposes the specified matrix in-place. Displays an error if the index is invalid.

### Raising a Matrix to a Power
   - **Command:** `R index power`
   - **Parameters:**
     - `index`: The index of the matrix to raise.
     - `power`: The exponent to which the matrix should be raised.
   - **Example:** `R 0 5`
   - **Output:** Raises the specified matrix to the given power in-place. Error messages are displayed for invalid indices or if the power is negative.

### Freeing Memory of a Matrix
   - **Command:** `F index`
   - **Parameters:**
     - `index`: The index of the matrix whose memory should be freed.
   - **Example:** `F 0`
   - **Output:** Frees the memory of the specified matrix and removes it from the matrix list. Displays an error if the index is invalid.

### Exiting the Program
   - **Command:** `Q`
   - **Parameters:** None
   - **Description:** Ends the program and frees all allocated resources.

### Error Handling
If an unrecognized command is entered, the program will display the message: **“Unrecognized command.”** 

Make sure to enter the commands and parameters correctly to avoid execution errors. The program assumes that all input is valid according to the specifications provided. Enjoy using the Octave Simulator!
