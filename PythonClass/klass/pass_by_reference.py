#pass by reference
import sys

x = 10
print("id of x = ", id(x))
print(sys.getsizeof(x))


y=10
print("id of y = ", id(y))

x = 20
print("id of x = ", id(x))
