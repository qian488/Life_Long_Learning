#include<iostream>
#include<vector>
using namespace std;
//Codeforces Round 928 (Div. 4)_B. Vlad and Shapes

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = true;
        char c[n+1][n+1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> c[i][j];
            }
            
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (c[i][j] == '1')
                {
                    int x = n;
                    for (int k = j + 1; k <= n; k++)
                    {
                        if (c[i][k] != '1')
                        {
                            x = k;
                            if (x-j==1)
                            {
                                flag = false;
                            }
                            
                            break;
                        }
                    }
                    
                    for (int k = i + 1; k < x; k++)
                    {
                        for (int y = j + 1; y < x; y++)
                        {
                            if (c[k][y] != '1')
                            {
                                flag = false;
                                break;
                            }
                        }
                        
                        if (!flag)
                        {
                            break;
                        }  
                       
                        
                    }
                    
                    break;
                }
            }
            
            if (!flag)
            {
                break;
            }
        }
        
        if (flag)
        {
            cout << "SQUARE" << endl;
        }
        else
        {
            cout << "TRIANGLE" << endl;
        }
    }
    
    return 0;
}