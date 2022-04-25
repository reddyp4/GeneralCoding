"""
Instructions
You are going to write a program that tests the compatibility between two people.

To work out the love score between two people:

Take both people's names and check for the number of times the letters in the word TRUE occurs. 

Then check for the number of times the letters in the word LOVE occurs. 

Then combine these numbers to make a 2 digit number.

For Love Scores less than 10 or greater than 90, the message should be:

"Your score is **x**, you go together like coke and mentos."
For Love Scores between 40 and 50, the message should be:

"Your score is **y**, you are alright together."
Otherwise, the message will just be their score. e.g.:

"Your score is **z**."
e.g.

name1 = "Angela Yu"
name2 = "Jack Bauer"
T occurs 0 times

R occurs 1 time

U occurs 2 times

E occurs 2 times

Total = 5

L occurs 1 time

O occurs 0 times

V occurs 0 times

E occurs 2 times

Total = 3

Love Score = 53

Print: "Your score is 53."
"""
# 🚨 Don't change the code below 👇
print("Welcome to the Love Calculator!")
name1 = input("What is your name? \n")
name2 = input("What is their name? \n")
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
#Convert to lower
name1lower = name1.lower()
name2lower = name2.lower()
#Concatanete
name = name1lower + name2lower
#Count true
count1 = name.count("t")
count1+= name.count("r")
count1+= name.count("u")
count1+= name.count("e")
#Count love
count2 = name.count("l")
count2+= name.count("o")
count2+= name.count("v")
count2+= name.count("e")
#Make two digit number
number = count1 * 10 + count2 

if(number<10 or number>90):
    print(f"Your score is {number}, you go together like coke and mentos.")
elif (number>40 and number<50):
    print(f"Your score is {number}, you are alright together.")
else:
    print(f"Your score is {number}.")

