"""
323. Number of Connected Components in an Undirected Graph
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
"""

"""
Solution:
    edges=[]
    connected=[]
    discovered=[]
def countHelper
    ele=discovered.pop()
    callBFS(ele) #should get all of the elements
    call count()

3 Steps
1-adj list
2-call BFS
3-outerloop to process all nodes

Building adjacency list
buildAdj(edges):
    for (src,dec in edges):
        adjList[src].append(dec)
        adjList[dec].append(src)


Outerloop
visited[1:vertex]=-1
for vertex in enumerate vertices:
    if(visited[vetex]==-1):
        callBFS(vertex)
        


"""
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        