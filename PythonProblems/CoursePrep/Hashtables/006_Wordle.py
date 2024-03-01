# Libraries Included:
# Numpy, Scipy, Scikit, Pandas

'''

Wordle Game Implementation
You are tasked with implementing the Wordle game, where you need to create a method that takes a guess and the correct answer as input and returns the result of the guess based on the following rules:
• Use '1' to indicate that a letter appears in the correct position.
• Use '0' to indicate that a letter exists in the answer but is in a different position.
• Use '.' to indicate that the letter does not appear in the answer.
Here's an example of the method's behavior:
• If the correct answer is "apple":
	• For the guess "table," the result should be ".0.11" (the 't' and 'l' does not even exist,  'a'  is in the wrong positions, and 'e' is not in the answer).
	• For the guess "cloth," the result should be ".0..." ('c' and 'l' are in the wrong positions, and 'a', 'p', and 'e' are not in the answer).
Your task is to implement the wordle_guess function 

aaaaa
aaaba


a - 0,1,2,3,4,
1,2,3,4,5

d[a] = lookup(0)
lookup[0] = 1
lookup[1] = 1

answer[i] == guess[1]
    1
applp
ppppe
0110
011.



'''

def wordle_guess(answer,guess):
    guessmap=""
    d={}
    len1,len2=len(answer),len(guess)
    for i in range(len1):
        if(answer[i] in d):
            d[answer[i]].append(i)
        else:
            d[answer[i]]=[i]
    #iterate through guess
    for i in range(len2):
        if(guess[i] in d):
            #charcter is present in answer
            if(i in d[guess[i]]):
                guessmap+="1"
            else:
                guessmap+="0"
        else:
            guessmap+="."
    return guessmap

#expecteed: .0.11
print(wordle_guess("apple","table"))
#check non-equal strings, no match, expected all .'s
print(wordle_guess("apple","ttttttttttttttttttt"))
#check "cloth" for "apple"
print(wordle_guess("apple","cloth"))




