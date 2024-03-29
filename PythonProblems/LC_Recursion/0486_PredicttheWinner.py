'''
486. Predict the Winner
Medium
Topics
Companies
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 107
'''

class Solution:
    def recursive(self, nums, sumA, sumB):
        print("numA:",sumA,"numB:",sumB,"nums:",nums)
        result,gotB=False,0
        numA,numB=0,0
        if(len(nums)==0 or len(nums)==0):
            if(sumA>=sumB):
                return True
            return False
        #Choice for player1 first
        for index in range(min(4,len(nums))):
            if(index==0):
                print("index:",index,"nums:",nums,"sumA:",sumA,"sumB:",sumB)
                numA=nums[0]
                nums.pop(0)
                if(nums):
                    gotB=1
                    numB=nums[0]
                    nums.pop(0)
                    sumA+=numA
                    sumB+=numB
                    result=self.recursive(nums,sumA,sumB)
                else:
                    result = True if(sumA>=sumB) else False
                    gotB=0
                if(result):
                    return result
                if(gotB):
                    nums.insert(0,numB)
                nums.insert(0,numA)
                sumA-=numA
                sumB-=numB
            elif(index==1):
                print("index:",index,"nums:",nums,"sumA:",sumA,"sumB:",sumB)
                numA=nums[0]
                nums.pop(0)
                if(nums):
                    gotB=1
                    numB=nums[-1]
                    nums.pop()
                    sumA+=numA
                    sumB+=numB
                    result=self.recursive(nums,sumA,sumB)
                else:
                    result = True if(sumA>=sumB) else False
                    gotB=0
                if(result):
                    return result
                if(gotB):
                    nums.append(numB)
                nums.insert(0,numA)
                sumA-=numA
                sumB-=numB
            elif(index==2):
                print("index:",index,"nums:",nums,"sumA:",sumA,"sumB:",sumB)
                numA=nums[-1]
                nums.pop()
                if(nums):
                    gotB=1
                    numB=nums[-1]
                    nums.pop()
                    sumA+=numA
                    sumB+=numB
                    result=self.recursive(nums,sumA,sumB)
                else:
                    result = True if(sumA>=sumB) else False
                    gotB=0
                if(result):
                    return result
                if(gotB):
                    nums.append(numB)
                nums.append(numA)
                sumA-=numA
                sumB-=numB
            elif(index==3):
                print("index:",index,"nums:",nums,"sumA:",sumA,"sumB:",sumB)
                numA=nums[-1]
                nums.pop()
                if(nums):
                    gotB=1
                    numB=nums[0]
                    nums.pop(0)
                    sumA+=numA
                    sumB+=numB
                    result=self.recursive(nums,sumA,sumB)
                else:
                    result = True if(sumA>=sumB) else False
                    gotB=0
                if(result):
                    return result
                if(gotB):
                    nums.insert(0,numB)
                nums.insert(0,numA)
                sumA-=numA
                sumB-=numB
        return result

                
        result=self.recursive(nu)
        #Choice for player 2 next
    def predictTheWinner(self, nums: List[int]) -> bool:
        #Call recursion sume, and check all sums of A and B
        result=False
        result=self.recursive(nums,0,0)
        return result