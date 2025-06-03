class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        n=len(status)
        q=deque()
        for start in initialBoxes:
            q.append(start)
        s=set()
        total = 0
        while q:
            curr = q.popleft()
            if status[curr]==0:
                s.add(curr)
                continue
            for open in keys[curr]:
                status[open]=1
                if open in s:
                    q.append(open)
                    s.discard(open)
            total+=candies[curr]
            for nbr in containedBoxes[curr]:
                q.append(nbr)
        return total
