# TSP_benchmarks
Experiments with C++ parallel programming
### Four threads, 15 Cities, old code (December Commit)
*BFS: Broken
*Recursive DFS: 2.46331s
*Iterative DFS: 6.3623s
*Parallel Iterative DFS: 11.953s
*Parallel Recursive DFS: 0.646581s
*Concurrent Queue Recursive DFS: 0.646581s
*Concurrent Stack Iterative DFS: 33.7057s

Lots of pass-by-value and raw pointers going on. Will update and see how performance is affected. 


