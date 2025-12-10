# MSCS 632 – Multi-Paradigm Statistics Calculator

This repository contains implementations of basic statistics (mean, median, and mode) on a list of integers using three different programming paradigms.

## Languages and Paradigms

- **C (Procedural):** `stats.c`
- **OCaml (Functional):** `stats.ml`
- **Python (Object-Oriented):** `statistics_calculator.py`

All three implementations use the same sample data:

```text
[5, 3, 9, 3, 8, 3, 1, 9]
```
and compute:

Mean

Median

Mode (most frequent value)
How to Run
C (using GCC)
gcc stats.c -o stats.exe
./stats.exe

OCaml

Use a local OCaml installation or an online interpreter (for example https://try.ocamlpro.com
) and run the contents of stats.ml.

Python
python statistics_calculator.py

Sample Output
Data: 5 3 9 3 8 3 1 9
Mean: 5.125
Median: 4.000
Mode(s): 3

