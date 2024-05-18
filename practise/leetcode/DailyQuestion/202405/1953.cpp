class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
    long long sum=0,maxn=0;
    for(auto e:milestones){ 
        sum+=e;
        if(e>maxn) maxn=e;
    }
    return maxn>sum-maxn+1?(sum-maxn)*2+1:sum;
    }
};