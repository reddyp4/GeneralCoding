#random module
import random

print(random.randint(1,20))

print(int(1000*random.random())) #0 to 1

list1 = [1, 8, 3, 20, 5, 6]
print(random.choice(list1))

string = "Google"
print(random.choice(string))

random.shuffle(list1)

print(random.sample(list1,2))
