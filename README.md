# Linux-Kernel-Module-for-Listing-Tasks
The file fork_process.c is for problem 3.17. 

The file list_tasks.c has the code for listing tasks. The order of how the tasks are listed as follows:

Child : pname, state, pid, 

Parent 0: Parent of the child above,

Parent 1: Grandparent of Child, Parent of Parent 0,

Parent [i]: Parent of Parent [i-1] 

and so on. 
