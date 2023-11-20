#include<iostream>


using namespace std;

const int N = 10010;
string s[N][N];


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        while (getchar()!='\n')
        {
            int j = 0;
            cin >> s[i][j];
            j++;
        }
        
        
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    
    return 0;
}