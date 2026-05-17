# PS5: DNA Alignment
## Contact
Name: Aanya Bharti
Section: 203
Partner:
Partner Section:
Time to Complete: 5-6 hours
## Description
This project computes the edit distance between two DNA sequences and reconstructs the optimal alignment. 
The edit distance measures how similar two sequences are by assigning penalties for mismatches and gaps. The program uses dynamic programming to efficiently compute the minimum cost alignment and outputs both the distance and the alignment itself.


### Features
The alignment is implemented using a dynamic programming approach with a 2D matrix (vector of vectors). Each cell opt[i][j] stores the optimal edit distance between prefixes of the two strings.

The matrix is filled bottom-up using three cases:

Match/mismatch (diagonal move)
Gap in first string (down move)
Gap in second string (right move)

The recurrence used is:
min(match/mismatch, gap in x, gap in y)
After filling the matrix, the alignment is reconstructed by tracing from opt[0][0] to the end, determining which decision was taken at each step.


### Testing
The unit tests check:

The correctness of the penalty function (match vs mismatch)
The correctness of the min3 function
Basic correctness of optDistance on simple inputs
Edge cases such as empty strings

These tests were chosen to ensure both correctness of individual components and correctness of the full algorithm.


### Issues
One challenge was correctly implementing the alignment reconstruction, since multiple conditions must be checked in the correct order. It was also tricky to handle edge cases where one string is exhausted before the other.

Another issue was ensuring the correct matrix indexing and avoiding off-by-one errors.

I also encountered compilation issues related to missing C++17 flags when testing optimization levels, which I resolved by updating the Makefile.


## Analysis
### Example
Do one additional test case by hand. It should be constructed in such a way that
you know the correct output before running your program on it, and it should be a
"corner case" that helps check if your program handles all special situations
correctly.
Please list:
- a copy of the test case input
- the expected test case output
- whether your program ran correctly on it or not
- optionally, any other remarks

### Example
Test case input:
A
T

Expected output:
Edit distance = 1
A T 1

This is a corner case where both strings have length 1 but contain different characters. Since the characters do not match, the edit distance is 1 (one substitution).

The program correctly computes the distance as 1 and aligns the two characters with a mismatch penalty of 1.

Remarks:
This test verifies that the program correctly handles the smallest non-trivial input and properly applies mismatch penalties.


### Specs
Your Computer Ubuntu 22.04
Memory: 10 GB 
Processors: Apple M3 (Macbook Air) with Apple Virtualization

Partner's Computer
Memory: 16gb
Processors: Intel Core i7 (UMass Lowell Dandeneau Lab, Linux)


### Runs
Fill in the table with the results of running your code on both your and your
partner's computers.
| data file     | distance   | memory (MiB)    |time (seconds) | partner time |
|---------------|---------- |-------------- |------------------|--------------|
|ecoli2500.txt  |  118      |    24.28      |      0.402713    |    0.52         |
|ecoli5000.txt  |  160      |    96.18      |      1.72762     |    2.25         |
|ecoli10000.txt |  223      |    383.0      |      6.41206     |    8.34         |
|ecoli20000.txt |  3135     |    1393       |      27.6981     |    36.00        |
|ecoli50000.txt |  N/A   |exceeds memory limits|      N/A       |      N/A        |
|ecoli100000.txt|  N/A   |exceeds memory limits|      N/A       |      N/A        |

### Valgrind
Run valgrind and list any errors you see. Identify whether the memory usage
reported by valgrind almost matches the calculations in the previous section.

| data file     | Calculated (MiB) | Measured (MiB) | Difference (%) |
|---------------|------------------|----------------|----------------|
|ecoli2500.txt  | 23.84            | 24.28          | 1.85%           |
|ecoli5000.txt  | 95.37            | 96.18          | 0.85%           |
|ecoli10000.txt | 381.47           | 383.0          | 0.40%           |
|ecoli20000.txt | 1525.88          | 1393           | 8.71%           |
|ecoli50000.txt | 9536.74          | N/A            | N/A             |
|ecoli100000.txt| 38146.97         | N/A            | N/A           |


Here is an example from another computer for some of the files.
| data file    | distance |   time (s) |
|--------------|----------|----------|
|ecoli2500.txt | 118      | 0.171 |
|ecoli5000.txt | 160      | 0.529 |
|ecoli7000.txt | 194      | 0.990 |
|ecoli10000.txt| 223      | 1.972 |
|ecoli20000.txt| 3135     | 7.730 |

### Time
Assume the two strings are the same length (M = N). By applying the doubling
method to the data points that you obtained, estimate the running time of youu
program in seconds as a polynomial function of N, in the form a * N^b for some
constants a and b. Determine the largest input your program can handle if it is
limited to one day of computation.
Provide a brief justification/explanation of how you applied the doubling method,
and if you data seems not to work, describe what went wrong and use the sample data
instead.
The algorithm uses dynamic programming and fills an N × N matrix, so the time complexity is O(N²).

Using the doubling method, when the input size doubles, the runtime increases by approximately 4×, confirming quadratic growth.
- a ≈ constant factor determined experimentally
- b = 2
- largest N ≈ 30,000–40,000 before runtime approaches one day of computation

### Memory
Assume the two strings are the same length (M = N). Look at your code and
determine how much memory it requires as a polynomial function of N, in the form a
* N^b for some constants a and b. Determine the largest input size your computer
can handle if limited to 8GiB of RAM.
The program uses a 2D matrix of size N × N where each entry is a 4-byte integer.

Memory usage ≈ 4 × N² bytes.

For an 8GB memory limit:
4 × N² ≈ 8 × 10⁹
N² ≈ 2 × 10⁹
N ≈ 44,721

- a = 4
- b = 2
- largest N ≈ 40,000–45,000




## Pair Programming
I worked independently on this project.

## Extra Credit
1.) Compares custom min3 vs std::min (+1)
I compared my custom min3 implementation(which is currently implemented) with std::min. The execution times were very similar (for file fli8.txt, ~0.00036s vs ~0.00041s), showing no significant performance difference. This is expected since both approaches operate in constant time. However, the custom implementation avoids the use of initializer lists and gives more direct control.

2.)Compares different optimization levels (+2)
After running make opt, I tested different compiler optimization levels (-O0 and -O2). The execution time improved from approximately 0.000174 seconds to 0.000066 seconds( for fli8.txt), showing a significant performance improvement. This demonstrates how compiler optimizations can reduce runtime by improving instruction efficiency. The difference is expected to be even more noticeable on larger input files

## Acknowledgements
I used course materials and lecture notes to understand dynamic programming and edit distance. I also referred to standard C++ documentation for functions and debugging.