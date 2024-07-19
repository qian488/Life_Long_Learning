class Solution {
typedef long long ll;

public:
    ll n,maxn,minn,base,c1,c2;
    ll f(ll x){
        ll s=base+(x-maxn)*n;
        ll d=x-minn;
        ll res=0;
        if(d<=s-d){
            res=s/2*c2+s%2*c1;
        }else{
            res=(s-d)*c2+(d*2-s)*c1;
        }
        return res;
    }
    ll binary_search0(){
        ll l=maxn/2,r=maxn;
        while(l<r){
            ll mid=(l+r)/2;
            if(f(mid*2)<f((mid+1)*2)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    ll binary_search1(){
        ll l=maxn/2,r=maxn;
        while(l<r){
            ll mid=(l+r)/2;
            if(f(mid*2+1)<f((mid+1)*2+1)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        const int MOD=1e9+7;
        n=nums.size();
        c1=cost1,c2=cost2;
        maxn=*max_element(nums.begin(),nums.end());
        minn=*min_element(nums.begin(),nums.end());
        base=maxn*n-(ll)accumulate(nums.begin(),nums.end(),0LL);
        if(cost1*2<=cost2) return base*cost1%MOD;

        ll ans=1e18;
        if(maxn%2==1){
            ans=f(maxn);
            maxn++;
            base+=n;
        }
        ll k0=binary_search0();
        ll k1=binary_search1();
        ans=min(ans,f(k0*2));
        ans=min(ans,f(k1*2+1));
        return ans%MOD;
    }
};