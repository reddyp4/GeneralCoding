''''
How Many Binary Search Trees With N Nodes

Write a function that returns the number of distinct binary search trees that can be constructed with n nodes. For the purpose of this exercise, do solve the problem using recursion first even if you see some non-recursive approaches.

Example One
{
"n": 1
}
Output:

1
Example Two
{
"n": 2
}
Output:

2
Suppose the values are 1 and 2, then the two trees that are possible are

   (2)            (1)
  /       and       \
(1)                  (2)
Example Three
{
"n": 3
}
Output:

5
Suppose the values are 1, 2, 3 then the possible trees are

       (3)
      /
    (2)
   /
(1)

   (3)
  /
(1)
   \
   (2)

(1)
   \
    (2)
      \
       (3)

(1)
   \
    (3)
   /
(2)

   (2)
  /   \
(1)    (3)
Notes
Constraints:

1 <= n <= 16

'''

def how_many_bsts(n):
    """
    Args:
     n(int32)
    Returns:
     int64
    """
    # Write your code here.
    return 0
