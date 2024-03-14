'''
983. Minimum Cost For Tickets
Medium
Topics
Companies
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
 

Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
'''

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        totalCost=0
        numDays=len(days)
        #all cost are high initially
        day=days[0]
        costDay=[0]*(days[-1]+1)
        totalCost=[0]*(days[-1]+1)
        #initialize the first element
        day=days[0]
        costDay[day]=min(costs)     #cost of ticket chosen on that day
        totalCost[day]=costDay[day]   #total cost of tickets so far
        lastDay=day
        #now start from first to all
        for i in range(1,numDays):
            day=days[i]
            #get the three minimum values, option1, previoys+cost0, 
            #option2,cost7 days before+cost1,option3:cost30days before+cost30
            #do not forget to adjust the price difference if ticket was purchased on that day
            #option1: revoke last day and buy individual tickets
            val1 = totalCost[lastDay]-costDay[lastDay]+costs[0]*2
            #option2: revoke the last day or 7th last day
            #7-day minimum, adjust the balance
            val2,val3=10**10,10**10
            if(day<=7):
                day7=1
            else:
                day7=day-6
            while(costDay[day7]==0 and day7<day):
                day7+=1
            if(day7!=day):
                newval=totalCost[day7]-costDay[day7]+costs[1]
                val2=val2 if newval>val2 else newval
            if(day<=30):
                day30=1
            else:
                day30=day-29
            while(costDay[day30]==0 and day30<day):
                day30+=1
            if(day30!=day):
                newval=totalCost[day30]-costDay[day30]+costs[2]
                val3=val3 if newval>val3 else newval
            #pick the minimum
            print("lastDay:",lastDay,"day:",day,",day7:",day7,",day30:",day30,"val1:",val1,",val2:",val2,",val3:",val3)
            minval=min(val1,val2,val3)
            #readjust the values accordingly-do we need to do this?
            if(minval==val1):
                costDay[day]=costs[0]
            elif(minval==val2):
                costDay[day]=costs[1]
            else:
                costDay[day]=costs[2]
            totalCost[day]=minval
            lastDay=day
        print("cost by day:",costDay)
        print("total cost:",totalCost)
        return(totalCost[-1])