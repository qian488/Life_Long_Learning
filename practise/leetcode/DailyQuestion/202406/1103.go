func distributeCandies(candies int, num_people int) []int {
    ans :=make([]int,num_people)
    for i:=1;candies>0;i++{
        ans[(i-1)%num_people]+=min(i,candies)
        candies-=i
    }
    return ans
}

func distributeCandies(candies int, num_people int) []int {
    ans :=make([]int,num_people)
    m:=int((math.Sqrt((float64)(8*candies+1))-1)/2)
    k,extra:=m/num_people,m%num_people
    for i := range ans{
        k:=k
        if i<extra{
            k++
        }
        ans[i]=k*(k-1)/2*num_people+k*(i+1)
    }
    ans[extra]+=candies-m*(m+1)/2
    return ans
}