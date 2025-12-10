MSCS 632 – Multi-Paradigm Statistics Calculator

This repository contains implementations of basic statistics (mean, median, and mode) on a list of integers using three different programming paradigms: Procedural (C), Functional (OCaml), and Object-Oriented (Python).

Languages and Paradigms

C (Procedural): stats.c

OCaml (Functional): stats.ml

Python (Object-Oriented): statistics_calculator.py

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

```text

gcc stats.c -o stats.exe
./stats.exe

```

OCaml (Functional)

Use a local OCaml installation or an online interpreter, such as:
https://try.ocamlpro.com

Run the code in:

```text

ocaml stats.ml

```

Python (Object-Oriented)

```text
python statistics_calculator.py

```

Expected Output (All Three Languages)

```text
Data: 5 3 9 3 8 3 1 9
Mean: 5.125
Median: 4.000
Mode(s): 3

```

Course Information

University: University of the Cumberlands
Course: MSCS 632 – Advanced Programming Languages
Assignment: Assignment 7 – Multi-Paradigm Problem Solving

Repository Structure

```text

Multi-Paradigm-Stats-MSCS632Assignment-7/
│
├── stats.c                     # Procedural C implementation
├── stats.ml                    # Functional OCaml implementation
├── statistics_calculator.py    # OOP Python implementation
└── README.md                   # Project documentation

```
