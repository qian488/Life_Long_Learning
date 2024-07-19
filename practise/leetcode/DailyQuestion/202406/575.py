class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(set(candyType)), len(candyType) // 2)

class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        ctmp = {}
        for e in candyType:
            if e in ctmp:
                ctmp[e] += 1
            else:
                ctmp[e] = 1
        ans = len(candyType) // 2
        return min(ans, len(ctmp))