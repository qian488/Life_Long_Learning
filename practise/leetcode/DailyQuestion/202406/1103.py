class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans=[0]*num_people
        i=1
        while candies>0:
            ans[(i-1)%num_people]+=min(i,candies)
            candies-=i
            i+=1
        return ans

class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans=[0]*num_people
        m=int((sqrt(8*candies+1)-1)/2)
        k,extra=divmod(m,num_people)
        ans=[k*(k-1)//2*num_people+k*(i+1)+(k*num_people+i+1 if i<extra else 0)for i in range(num_people)]
        ans[extra]+=candies-m*(m+1)//2
        return ans