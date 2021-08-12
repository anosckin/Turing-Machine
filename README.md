# Turing-Machine
Simulates a Turing machine on a given string

## Details

# Description
## Simulate (Turing Machine)
Simulate.cpp takes a Turing Machine (standard input)

Description of a Turing Machine input:
- first line has the number of states in the machine.
- next n-1 lines contains descriptions for the edges coming out of said states.
- on ith line the first number is the number of edges going out from state with index i
- each edge is described with 4 variables.
- 
edge:
1. the symbol needed to traverse the edge
2. which state does this edge go to
3. what symbol we write on the tape
4. L or R depending if we go left or right accordingly.

next line contains a single string made uo of only 1-s and 0-s. this string will be written on the tape before starting.

on the ith line, the code outputs which state the machine will be after i readings from the tape.

if the machine has ended without going to an accept state, it prints -1.

# Usage

## Windows
run simulate.exe and input the case accordingly to the above restrictions

## Linux
TBD

## Small samples
sample test
Input:
```
2
2 0 0 0 R 1 1 1 R
0011
```
Output
```
0
0
1
```
