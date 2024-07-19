#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
//莞工集训24.01.27--F

int main()
{
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s;
    return 0;
}