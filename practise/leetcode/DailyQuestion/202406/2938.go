func minimumSteps(s string) int64 {
    cnt:=0
    var ans int64
    for _,c:=range s{
        if c == '1'{
            cnt++
        }else{
            ans+=int64(cnt)
        }
    }
    return ans
}