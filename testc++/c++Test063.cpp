#include<iostream>
#include<map>
using namespace std;
//原来你也玩原神
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int> maps;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        maps[a] = b;
    }

    for(auto& pair : maps)
    {

    }

    for (int i = 0; i < m; i++)
    {
        
    }
    
    /*
    for(map<int,int>::iterator it = maps.begin(); it != maps.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    */
    
    return 0;
}