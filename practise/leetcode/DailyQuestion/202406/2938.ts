function minimumSteps(s: string): number {
    let ans=0;
    let cnt=0;
    for(let c of s){
        if(c=='1'){
            cnt++;
        }else{
            ans+=cnt;
        }
    }
    return ans;
};