#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(nullptr));
    map<int,int> cnt;
    for(int i=0;i<100;i++){
        int value = rand() % 6;
        cnt[value]++;
    }
    int sum=0;
    for(auto [x,y]:cnt){
        sum+=y;
        cout<<x<<" "<<y<<endl;
    }
    cout<<sum<<endl;
    return 0;
}