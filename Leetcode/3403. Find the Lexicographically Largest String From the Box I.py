class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        l = len(word) - numFriends + 1
        res = ""
        for i in range(0, len(word)):
            res = max(res, word[i:i+l])
        return res
