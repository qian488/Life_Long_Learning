#include<iostream>

using namespace std;
//派蒙数列
//矩阵快速幂典题
long long N = 1e9 + 7;
const int len = 3;
//定义结构体表示矩阵
struct Matrix{
    long long t[len][len] = {};
    /*
    重载这个运算符，可以像访问数组一样访问结构体的成员变量。
    该函数接受一个整数索引作为参数，并返回指向该索引对应行的指针。
    */
    long long* operator[](int index)
    {
        return t[index];
    }
};
//重载*法运算为矩阵乘法
Matrix operator*(Matrix &a,Matrix &b)
{
    Matrix c;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= N;
            }
            
        }
        
    }
    return c;
}
//初始化获得单位矩阵
Matrix init_maxrix()
{
    Matrix m;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i==j)
            {
                m[i][j] = 1;
            }
            
        }
        
    }
    return m;
}
//矩阵快速幂
Matrix mqpow(Matrix m,long long n)
{
    Matrix ans = init_maxrix();
    while (n)
    {
        if (n%2)//(n&1)
        {
            ans = ans * m;
        }
        m = m * m;
        n /= 2;//(n>>=1)
    }
    return ans;
}

int main()
{
    long long n;
    cin >> n;
    Matrix m;
    m[0][1] = m[1][2] = m[2][0] = m[2][1] = m[2][2] = 1;
    Matrix ans = mqpow(m, n - 1);
    cout << (ans[0][0] + ans[0][1] + ans[0][2]) % N;
    return 0;
}