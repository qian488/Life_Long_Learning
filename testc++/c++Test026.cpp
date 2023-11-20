#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string clearZero(string s)
{
    string result;
    if (s.find_first_not_of('0')!= string::npos)
    {
        //找到前后第一个非零元素并截取出来
        result= s.substr(s.find_first_not_of('0'), s.find_last_not_of('0') - s.find_first_not_of('0') + 1);
        
    }
    else//避免只有零导致找不到非零元素以致运行错误
    {
        result = '0';
    }

    return (result != "" ? result : "0");
}

// 反转字符串,并清前导零
string reverseString(string s)
 {
    reverse(s.begin(), s.end());
    cout << "before clearzero:" << s << endl;
    s=clearZero(s);
    cout << "after clerzero:" << s << endl;
    return s;
}

// 反转实数
string reverseRealNumber(string n) 
{
    if (n.find('.') != string::npos)
     {
        // 小数
        string aPart = n.substr(0, n.find('.'));
        string bPart = n.substr(n.find('.') + 1);
        string reversedaPart = reverseString(aPart);
        string reversedbPart = reverseString(bPart);
        return reversedaPart + "." + reversedbPart;
    } 
    else if (n.find('/') != string::npos) 
    {
        // 分数
        string fz = n.substr(0, n.find('/'));
        string fm = n.substr(n.find('/') + 1);
        string reversedfz = reverseString(fz);
        string reversedfm = reverseString(fm);
        return reversedfz + "/" + reversedfm;
    } 
    else if (n.find('%') != string::npos) 
    {
        // 百分数
        string numberPart = n.substr(0, n.find('%'));
        string reversedNumberPart = reverseString(numberPart);
        return reversedNumberPart + "%";
    } 
    else
     {
        // 整数
        return reverseString(n);
    }
}

int main() 
{
    string number;
    cin >> number;
    string ans = reverseRealNumber(number);
    cout << ans;
    return 0;
}