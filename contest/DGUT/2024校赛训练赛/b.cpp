#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans = "";
    for(char c:s){
        if(c == 'D' || c == 'G' || c == 'U' || c == 'T') ans+=c;
    }
    if(ans=="DGUT"){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}