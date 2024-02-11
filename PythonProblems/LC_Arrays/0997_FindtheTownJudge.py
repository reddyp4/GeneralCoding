'''
997. Find the Town Judge
Solved
Easy
Topics
Companies
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.

'''

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if(len(trust)==0):
            if(n==1):
                return 1
            return -1
        lenTrust = len(trust)
        #[a,b] means a is not town judge, 'b' can be
        #collect all the 'b''s, the count of "b"==n, now go back and check if b in trust[0]
        d={}
        for index in range(len(trust)):
            if(trust[index][1] in d):
                d[trust[index][1]]+=1
            else:
                d[trust[index][1]]=1
        print("d:",d)
        judges=[k for k,v in d.items() if v==(n-1)]
        judge=-1
        #Now search if judge knows anyone
        for k in range(len(judges)):
            judge=judges[k]
            for index in range(len(trust)):
                if(trust[index][0]==judges[k]):
                    judge=-1
                    break
        print("judges:",judges)
        return judge


'''
Work through array to find the person with all connections.
Now go back and check if this person knows anyone.
Space: O(n), Time:O(n)

'''
