# get_next_line

Get_next_line is a classical project of 42 school to implement a function which can read one line at time from a file. The bonus part allows the function to read from multiple files descriptors (FD), using buffers and controling memory leaks.

## Goals
1. Return one line (define by \n) by function call;
2. Maintain the reading state between successive function calls.
3. Support simultaneous reading drom multiples FDs.
4. Handle end-of-file and errors correctly.

## Usage
1. Clone the repository.
2. Mandatory get_next_line operates with one FD and get_next_line_bonus operates with multiples FDs.
3. Uncomment main().
4. Compile using gcc.
5. Test either with file.txt or from standard input .
