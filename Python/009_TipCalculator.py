#If the bill was $150.00, split between 5 people, with 12% tip
#Each person should pay (150.00/5)*1.12 = 33.6
#Round the result to 2 decimal places
#Example, 124.56, percentage 10, 12, or 15, number of people=7, each = $19.93

print("Welcome to Tip Calculator")
bill = float(input("What was the total bill: "))
percent = float(input("What percentage trip would like to give? 10, 12, or 15? "))
people = float(input("How many people to split the bill?"))

person = round((bill*(1+percent/100))/people,2)
print(f"Each person should pay: ${person}")