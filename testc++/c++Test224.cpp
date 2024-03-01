#include<iostream>

using namespace std;
//牛客周赛 Round 34_小红的陡峭值
const int N=1e5+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    int x=0,y=0,py=0;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        if(a[i]!=0) 
        {
            if (x==0)
            {
                x=a[i];
            }
            else if(y==0)
            {
                y=a[i];
                py = i;
            }
        }
        //cout << x << " " << y << endl;
    }
    for(int i=0;i<n;i++) 
    {
        if(a[i]==0) a[i]=x;
    }
    if(y==0) 
    {
        y=x+1;
        a[0]=y;
    }
    //cout<<py<<endl;
    if(py==0||py==n-1) for(int i=0;i<n;i++) cout<<a[i]<<" ";
    else cout<<-1<<endl;
    return 0;
}