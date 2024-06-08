func maxOperations(nums []int) int {
    n := len(nums)
    res1 := solve(nums[2:], nums[0]+nums[1])
    res2 := solve(nums[:n-2], nums[n-2]+nums[n-1])
    res3 := solve(nums[1:n-1], nums[0]+nums[n-1])
    return max(res1, res2, res3) + 1
}

func solve(a []int, target int) int{
    n := len(a)
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, n)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    var dfs func(int, int) int
    dfs = func(i, j int) (res int){
        if i >= j{
            return
        }
        p := &dp[i][j]
        if *p != -1{
            return *p
        }
        if a[i]+a[i+1] == target{
            res = max(res,dfs(i+2, j)+1)
        }
        if a[j-1]+a[j] == target{
            res = max(res,dfs(i,j-2)+1)
        }
        if a[i]+a[j] == target{
            res = max(res,dfs(i+1,j-1)+1)
        }
        *p = res
        return 
    }
    return dfs(0,n-1)
}