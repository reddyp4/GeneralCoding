#Instructions
#Make a rock, paper, scissors game.
#Inside the main.py file, you'll find the ASCII art for the hand signals 
# already saved to a corresponding variable: rock, paper, and scissors. 
# This will make it easy to print them out to the console.
#Start the game by asking the player:
#"What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors."
#From there you will need to figure out:
#How you will store the user's input.
#How you will generate a random choice for the computer.
#How you will compare the user's and the computer's choice to determine the winner (or a draw).
#And also how you will give feedback to the player.

from email.policy import strict
import random
import string

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

#Write your code below this line 👇
user_input = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors."))
if(user_input==0):
    user_choice = "Rock"
elif(user_input==1):
    user_choice = "Paper"
elif(user_input==2):
    user_choice = "Scissors"
print(user_choice + str(user_input))

comp_input = random.randint(0,2)
if(comp_input==0):
    comp_choice = "Rock"
elif(comp_input==1):
    comp_choice = "Paper"
elif(comp_input==2):
    comp_choice = "Scissors"
print(comp_choice + str(comp_input))

if(user_input==comp_input):
    print("It is a tie!!! Your choice is " + user_choice + "& computer chose" + comp_choice)
elif((user_input-comp_input)==1):
    print("You won! Your choice is " + user_choice + "& computer chose" + comp_choice)
elif((comp_input-user_input)==1):
    print("PC won! Your choice is " + user_choice + "& computer chose" + comp_choice)
elif((comp_input-user_input)==2):
    print("You won! Your choice is " + user_choice + "& computer chose" + comp_choice)
elif((user_input-comp_input)==2):
    print("PC won! Your choice is " + user_choice + "& computer chose" + comp_choice)

