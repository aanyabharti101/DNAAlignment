# DNAAlignment

A dynamic programming–based DNA sequence alignment system written in C++ for computing edit distance and reconstructing optimal genome alignments.

This project analyzes biological DNA sequences, computes minimum alignment cost using dynamic programming, and reconstructs the optimal alignment path between two sequences. The implementation includes runtime benchmarking, memory analysis, and large-scale genome testing.

---

## Features

- Computes optimal DNA sequence alignments
- Dynamic programming edit distance algorithm
- Alignment reconstruction and traceback
- Gap and mismatch penalty handling
- Runtime benchmarking
- Memory usage analysis
- Large genome sequence support
- Built with modern C++20

---

## How It Works

The program compares two DNA sequences and determines the minimum transformation cost needed to convert one sequence into the other.

The alignment model supports:
- character matches
- mismatches (substitutions)
- insertion/deletion gaps

The implementation uses a dynamic programming matrix where:

```txt
opt[i][j]
```

stores the optimal edit distance between prefixes of the two sequences.

Each matrix cell is computed from:

- diagonal transition (match/mismatch)
- upward transition (gap)
- left transition (gap)

The algorithm selects the minimum-cost transition at every step.

After filling the matrix, the optimal alignment is reconstructed by tracing backward through the DP table.

---

## Example Usage

### Build

```bash
make
```

### Run

```bash
./DNAAlignment < example10.txt
```

- `example10.txt` contains two DNA sequences to compare

Example input:

```txt
TGGCGGAACT
TGGTGGTACT
```

### Example Output

```txt
Edit distance = 1

T T 0
G G 0
G G 0
C T 1
...
```

The output shows:
- aligned characters
- mismatch penalties
- optimal edit distance
- execution time

---

## Algorithms & Concepts

- Dynamic programming
- Edit distance computation
- Sequence alignment
- Bioinformatics algorithms
- Matrix optimization
- Traceback reconstruction
- Runtime complexity analysis
- Memory benchmarking

---

## Scoring Model

| Operation | Cost |
|---|---|
| Match | 0 |
| Mismatch | 1 |
| Gap insertion/deletion | 2 |

---

## Performance Analysis

The project includes benchmarking on large genome datasets:

| Dataset | Runtime |
|---|---|
| ecoli2500.txt | ~0.40s |
| ecoli5000.txt | ~1.73s |
| ecoli10000.txt | ~6.41s |
| ecoli20000.txt | ~27.70s |

Large datasets beyond 50k characters exceeded memory limits due to quadratic DP matrix growth.

---

## Memory Analysis

Valgrind-based memory profiling was performed to compare:
- theoretical memory complexity
- measured runtime memory usage

The measured memory closely matched expected DP matrix allocation behavior.

---

## Testing

The project includes tests for:
- penalty function correctness
- minimum-cost computation
- edit distance accuracy
- empty-string edge cases
- traceback reconstruction
- alignment validity

---

## Technologies

- C++20
- STL
- SFML timing utilities
- GNU Make
- Dynamic programming algorithms

---

## Project Structure

```txt
EDistance.cpp
EDistance.hpp
main.cpp
test.cpp
Makefile
README.md
```

| File | Purpose |
|---|---|
| `EDistance.cpp` | Dynamic programming implementation |
| `EDistance.hpp` | Class definitions |
| `main.cpp` | Input/output and benchmarking |
| `test.cpp` | Unit tests |
| `Makefile` | Build automation |

---

## Challenges

Some of the most difficult parts of the project included:
- correctly reconstructing the optimal alignment path
- handling edge cases with empty sequences
- avoiding off-by-one indexing errors
- managing quadratic memory growth for large datasets

Large genome files also revealed scalability limitations of full DP matrix storage.

---

## Bioinformatics Context

DNA sequence alignment is a fundamental problem in computational biology and bioinformatics.

Applications include:
- genome comparison
- mutation analysis
- evolutionary studies
- sequence similarity analysis
- biological database search systems

---

## Author

Aanya Bharti  
Computer Science & Mathematics  
University of Massachusetts Lowell
