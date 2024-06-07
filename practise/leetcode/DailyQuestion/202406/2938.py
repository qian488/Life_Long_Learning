class Solution:
    def minimumSteps(self, s: str) -> int:
        ans=0
        cnt=0
        for c in s:
            if c=='1':
                cnt+=1
            else :
                ans+=cnt
        return ans