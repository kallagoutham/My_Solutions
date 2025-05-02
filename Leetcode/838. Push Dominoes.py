class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n=len(dominoes)
        prefix_right = [0]*n
        prefix_left = [0]*n
        prefix_right[0] = -1 if dominoes[0] == 'L' else (1 if dominoes[0] == 'R' else 0)
        prefix_left[n-1]= -1 if dominoes[n-1] == 'L' else (1 if dominoes[n-1] == 'R' else 0)
        for i in range(1,n):
            if dominoes[i] == 'L':
                prefix_right[i]=-1
            elif dominoes[i] == 'R':
                prefix_right[i]=1
            else:
                if prefix_right[i-1] > 0:
                    prefix_right[i] = prefix_right[i-1]+1
        for i in range(n-2,-1,-1):
            if dominoes[i] == 'R':
                prefix_left[i]=1
            elif dominoes[i] == 'L':
                prefix_left[i]=-1
            else:
                if prefix_left[i+1] < 0:
                    prefix_left[i] = prefix_left[i+1]-1
        # print(prefix_right)
        # print(prefix_left)
        res=""
        for i in range(n):
            if prefix_right[i]==0 and prefix_left[i] == 0:
                res+='.'
            elif prefix_right[i]==-1 and prefix_left[i] == -1:
                res+='L'
            elif prefix_right[i]==1 and prefix_left[i] == 1:
                res+='R'
            elif prefix_right[i]==0:
                res+='L'
            elif prefix_left[i]==0:
                res+='R'
            else:
                if abs(prefix_right[i]) < abs(prefix_left[i]):
                    res+='R'
                elif abs(prefix_right[i]) > abs(prefix_left[i]):
                    res+='L'
                else:
                    res+='.'

        return res
            

        
