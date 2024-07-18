#include<iostream>

using namespace std;
//牛客周赛 Round 28--小红的炸砖块
/*
初始有一个n∗m的砖块矩阵。小红会炸k次，每次会向一个位置投炸弹，如果这个位置有一个砖块，则砖块消失，上方的砖块向下落。
小红希望你画出最终砖块的图案。
题目中，n表示行数，m表示列数，k表示炸砖块次数，'*'表示有砖块，'.'表示空
*/
const int N = 1001;
char ans[N][N];//记录砖块状态
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    //init
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = '*';
        }
        
    }
    //处理炸砖块
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;//数组的索引是从0开始
        //整体思路是将炸的那一点变为空，然后上浮到最上面一层
        for (int j = x; j >=0; j--)
        {//模拟过程，j从x开始上浮至最上层
            ans[j][y]='.';//表示砖块爆炸'.'
            //向上移动
            if (j>0&&ans[j-1][y]=='*')
            {//当前不是第一行，并且上面有砖块
                ans[j][y]=ans[j-1][y];//当前块更新为上一行的状态，即砖块
                //ans[j-1][y]='.';//将炸了的这点的状态上移，其实可以不需要，因为循环外已经确保每次上浮的位置为爆炸后的状态，即'.'
                
            }
        }
        
    }
    //print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
}