#[1,2,3]
#[2,2,3]
#223 232 322

#[[1,2,3],[2,1,3]..] 

#123 213 321 ....

class Solution:
    def __init__(self):
        return
    
    def recursion(self,current,input,final):
        if(len(input)==0):
            if(current not in final):
                final.append(current[:])
            return
        for index in range(len(input)):
            val=input[index]
            current.append(val)
            input.pop(index)
            self.recursion(current,input,final)
            current.pop()
            input.insert(index,val)
        
    def combination(self,input):
        final=[]
        if(len(input)==0):
            return []
        self.recursion([],input,final)
        return final

#input = [1,2,3]
#input = [2,3,2]
input = [1,1,2,2]
sol=Solution()
result=sol.combination(input)
print("input:",input,"result:",result)
