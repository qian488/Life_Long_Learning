#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> ans;

    while(n--){
        string s;
        cin >> s;
        vector<int> v(26, 0); 
        for (char c : s) {
            v[c - 'A']++;
        }
        string kk = "";
        for (int e : v) {
            kk += to_string(e) + "."; 
        }
        ans.insert(kk);
    }

    cout << ans.size() << endl;

    return 0;
}

/*
 #include <bits/stdc++.h>
 #define ll long long
 using namespace std;
 set<string>s;
 int main()
 {
    int n;cin>>n;
    string str;
    while (n--) {
        cin>>str;
        sort(str.begin(),str.end());
        s.insert(str);
    }
    cout<<s.size();
    return 0;
 }
*/