
from typing import List


class Solution:
    def printGraph(self, V, edges):
        mat = [[] for _ in range(V)]
        for el in edges:
            mat[el[0]].append(el[1])
            mat[el[1]].append(el[0])
        
        return mat
        
        


#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()



class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        V,E=IntArray().Input()
        
        
        edges=IntMatrix().Input(E, 2)
        
        obj = Solution()
        res = obj.printGraph(V, edges)
        
        for row in res:
            print(*sorted(row))
# } Driver Code Ends