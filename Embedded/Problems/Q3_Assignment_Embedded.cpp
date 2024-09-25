/*

Implement your own deterministic malloc() and free(). Usually Malloc doesn't return an aligned address. Implement a mechanism to return a chunk of memory aligned to a particular data type size. Consider the following:



Getting a big fixed size chunk in the beginning
Determinism - always allocate fixed size blocks
Maintaining Multiple fixed size pools
Allocate from a pool which is at least as large as requested bytes
Allocating multiple consecutive chunks for larger size request
Book-keeping Overhead - list of allocated and free chunks
Where are the bookkeeping records located?
Allocating 4-byte aligned chunks - pros and cons
Fragmentation and defragmentation - Frequency of defragmentation? - may not be needed if block size is fixed

*/

