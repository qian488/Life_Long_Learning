#include <iostream>
#include <string>

using namespace std;

int main()
 {
    int n;
    cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        string op, num1, num2;
        cin >> op;
        num1 = "", num2 = "";

        if(op[0]=='a'||op[0]=='b'||op[0]=='c')
        {
            p = op[0];
            cin >> num1 >> num2;
        }
        else
        {
            num1 = op;
            cin >> num2;
        }
        int result;
        if (p == 'a')
        {
            op = '+';
            result = stoi(num1) + stoi(num2); 
        } else if (p == 'b') 
        {
            op = '-';
            result = stoi(num1) - stoi(num2); 
        } else if (p == 'c') 
        {
            op = '*';
            result = stoi(num1) * stoi(num2); 
        }

        string equation = num1 + op + num2 + "=" + to_string(result);

        cout << equation << endl; 
        cout << equation.length() << endl; 
    }

    return 0;
}