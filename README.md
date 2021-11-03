# Dining Philosophers Problem
The solution to the problem of dining philosophers. 
The problem is that there are philosophers sitting at the table. Each philosopher has one fork. 
But philosopher need two forks to take food. Consequently, all philosophers cannot eat at the same time.

To describe it more technically, we need to solve the problem of accessing shared variables from multiple threads. 

## Solution description 
To solve this problem in Linux have been used semaphores and mutexes. 
Mutexes are used to create critical sections when different threads wants to check 
forks state (available or occupied). 
Semaphores are used to create simple event-like system. 
The main idea of this system is to lock and wake up threads when necessary. 

For example, the thread chek forks state, but forks are occupied by other thread. 
Then thread can wait. Threads that use same forks as this one can wake it up. 
