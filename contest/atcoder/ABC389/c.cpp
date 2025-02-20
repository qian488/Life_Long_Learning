#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve()
{
    int q;
    cin >> q;
    deque<pair<ll,ll>> dq;
    ll offset = 0; 
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l;
            cin >> l;
            if(dq.empty())
            {
                dq.push_back({0,l});
            }
            else
            {
                dq.push_back({dq.back().first + dq.back().second,l});
            }
        }
        else if(op == 3)
        {
            int k;
            cin >> k;
            cout << dq[k-1].first - offset << endl;
        }
        else{
            ll m = dq.front().second;
            dq.pop_front();
            offset += m;
        }
        /*
        for(auto e : dq) cout << "[" << e.first << "," << e.second << "]" << " ";
        cout<<endl;
        */
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}