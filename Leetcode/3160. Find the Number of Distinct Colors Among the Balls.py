from typing import List

class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        res = []
        value_count = {}  
        visited = {}  
        for idx, val in queries:
            if idx in visited:
                prev_val = visited[idx]
                value_count[prev_val] -= 1
                if value_count[prev_val] == 0:
                    del value_count[prev_val] 
            visited[idx] = val  
            if val in value_count:
                value_count[val] += 1
            else:
                value_count[val] = 1
            res.append(len(value_count))
        return res
