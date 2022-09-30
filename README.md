# A Kernel Seedling

This kernel module creates a /proc file that shows the current number of running processes.

## Building

This kernel module is built by running the "make" command in the lab0 directory, which should contain proc_count.c and the Makefile. The module is then inserted into the kernel by running the command "sudo insmod proc_count.ko".

## Running

After building and inserting, the module is run by executing the command "cat /proc/count". This should return a single integer representing the number of processes running on the machine.

## Cleaning Up

The kernel module is removed by running the command "sudo rmmod proc_count". The lab0 directory can then be cleaned up by running the command "make clean".

## Testing

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

This module was tested on kernel version 5.14.8.

