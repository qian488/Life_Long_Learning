class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        a, b = set(), set()
        for u, v in paths:
            a.add(u)
            b.add(v)

        ans = b - a
        return ans.pop()