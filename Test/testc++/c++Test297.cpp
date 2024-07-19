#include <iostream>
using namespace std;
//蓝桥杯——日期统计
int main()
{
    int a, i,day, j;
    int arry[100] = { 5,6,8,6,9,1,6,1,2,4,9,1,9,8,2,3,6,4,7,7,5,9,5,0,3,8,7,5,8,1,5,8,6,1,8,3,0,3,7,9,2,
               7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,1,4,
               0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3 };
    int count=0;
    for (int month = 1; month <= 12; month++)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            day = 31;
        }
        else if (month == 2)
        {
            day = 28;
        }
        else
        {
            day = 30;
        }

        for (j = 1; j <= day; j++)
        {
            int k = 0;
            int bian[8] = { 2,0,2,3,month / 10,month % 10,j/ 10,j % 10 };
            for (i = 0; i < 100; i++)
            {
                if (arry[i] == bian[k])
                {
                    k++;
                }
                if (k == 8)
                {
                    count++; break;
                
                }
            }

        }

    }
    cout << count;
}