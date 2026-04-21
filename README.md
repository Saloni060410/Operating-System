# Operating System Lab Programs

This repository contains a collection of Operating System laboratory programs written in C, along with a small set of shell scripts for basic Unix/Linux file and command practice.

The programs cover common OS topics such as process scheduling, memory allocation, page replacement, disk scheduling, synchronization, and deadlock avoidance.

## Contents

### C Programs

#### Process Scheduling
- `01_fsfs.c` - FCFS scheduling exercise
- `02_nonpre_prio` - non-preemptive priority scheduling
- `03_pre-emp_sjf.c` - preemptive SJF scheduling
- `04_nonpre_sjf.c` - non-preemptive SJF scheduling
- `05_roundrobin.c` - round robin scheduling

#### Memory Management
- `06_bestfit.c` - best fit memory allocation
- `07_worstfit.c` - worst fit memory allocation
- `08_firstfit.c` - first fit memory allocation

#### Page Replacement
- `09_fifo.c` - FIFO page replacement
- `10_lru.c` - LRU page replacement
- `11_optimal.c` - optimal page replacement
- `12_paging.c` - paging-related program

#### Disk Scheduling
- `13_fcfs.c` - FCFS disk scheduling
- `14_sstf.c` - SSTF disk scheduling
- `15_scan.c` - SCAN disk scheduling
- `16_cscan.c` - C-SCAN disk scheduling
- `17_look.c` - LOOK disk scheduling
- `18_clook.c` - C-LOOK disk scheduling

#### Synchronization and Deadlock
- `19_pro-con.c` - producer-consumer problem
- `20_banker.c` - Banker's algorithm

### Shell Scripts
- `shell/01.sh` to `shell/16.sh` - shell scripting exercises for file handling, sorting, basic command usage, and related practice tasks

## Prerequisites

- A C compiler such as `gcc` or `clang`
- A Unix-like shell environment for the `.sh` scripts

## How To Run

### Compile a C program

Use `gcc` or `clang` to compile any program:

```bash
gcc 15_scan.c -o scan
```

or

```bash
clang 20_banker.c -o banker
```

### Execute the compiled program

```bash
./scan
```

Most programs are interactive and will prompt you for input such as process counts, burst times, memory blocks, page numbers, or disk request sequences.

### Run a shell script

Make the script executable if needed:

```bash
chmod +x shell/01.sh
```

Then run it:

```bash
./shell/01.sh
```

## Example

For disk scheduling programs such as `15_scan.c`, you typically enter:

- number of requests
- request sequence
- initial head position
- disk size

The program then prints the total seek time.

## Notes

- Some filenames are numbered for lab ordering.
- A few programs use direct `scanf` input and expect valid numeric values.
- If you add new lab exercises, follow the existing numbering pattern to keep the repository easy to navigate.

## Suggested Build Command

For quick testing, this pattern works well:

```bash
gcc -Wall -Wextra -std=c11 <file>.c -o <program_name>
```

Replace `<file>.c` with the source file you want to run.
