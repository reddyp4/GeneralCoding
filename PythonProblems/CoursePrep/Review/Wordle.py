# Libraries Included:
# Numpy, Scipy, Scikit, Pandas

'''
// Build the Wordle game!

// We use 1 to denote Green (The letter appears at the correct position). We use 0 to denote Yellow (The letter exists in the answer but at a different position). We use . to denote Grey (The letter does not appear in the answer). 

// Implement a method that given a guess, an answer return the result of the guess.
// Say the correct answer is apple.
// Guess table  return . 0 . 1 1
// cloth --  . 0 . . .

apple
table
.0.11

soon
most
.10.

most
soon
01

aapplp
pppppe

0.11..
00110.


eapplp
pppppe


'''

class wordle():
    def __init__(self,answer):
        answer=answer.lower()
        self.answer=answer
        self.d={}
        for c in answer:
            if c in self.d:
                self.d[c]=self.d[c]+1
            else:
                self.d[c]=1
        
    def guess(self,guess):
        if(len(guess)==0):
            return "Invalid guess!"
        result=["."]*len(guess)
        print("guess:",guess)
        guess=guess.lower()
        for index in range(len(guess)):
            #Setting all the 1's
            if(guess[index]==self.answer[index]):
                result[index]="1"
                self.d[guess[index]]=self.d[guess[index]]-1
        print("result:",result)
        for index in range(len(guess)):
            if(guess[index] in self.d and self.d[guess[index]]>0):
                result[index]="0"
                self.d[guess[index]]=self.d[guess[index]]-1
        return result
                    

#wordle1=wordle("apple")
#print(wordle1.guess("table"))

#wordle1=wordle("eapplp")
#print(wordle1.guess("pppppe"))

#wordle1=wordle("apple")
#print(wordle1.guess("APPLE"))

wordle1=wordle("appl.e")
print(wordle1.guess("APPL.E"))

wordle1=wordle("aaapp")
print(wordle1.guess("ppppe"))
