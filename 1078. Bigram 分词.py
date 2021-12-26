# 暴力搜一遍就行了
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        res = []
        l = text.split(" ")
        for i,t in enumerate(l):
            if t == first:
                if len(l) > i+2:
                    if l[i+1]==second:
                        res = res+l[i+2:i+3]
        return res
