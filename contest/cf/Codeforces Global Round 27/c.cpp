#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

void solve() {
    int n;
    cin >> n;

    if(n&1){
        cout<<n<<endl;
        for(int i=4;i<n-1;i++) cout<<i<<" ";
        cout<<"2 1 3 "<<n-1<<" "<<n<<endl;
    }else if(n == 6){
        cout<<"7\n1 2 4 6 5 3\n";
    }else{
        int k = 2147483648LL>>__builtin_clz(n);
        cout<< (k<<1) - 1 <<endl;
        for(int i=4;i<k-2;i++) cout<<i<<" ";
        for(int i=k;i<n;i++) cout<<i<<" ";
        cout<<"2 1 3 "<<k-2<<" "<<k - 1<<" "<<n<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
