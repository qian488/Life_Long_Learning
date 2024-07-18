#include<iostream>
#include<string>
#include<set>
using namespace std;
//帅学长的毕业照
//有出现身体其他部位的就找到他相对位置的人头,人头数就是最终人数
struct point{
    int x, y;
    bool operator < (const point &p)const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

set<point> person;

int main()
{
    int n, m;
    point p;
    while(cin>>n>>m)
    {
        cin.ignore();
        person.clear();

        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin,s);
            for (int j = 0; j < m; j++)
            {
                switch (s[j])
                {
                case 'o':
                    p.x = j, p.y = i;
                    break;
                case '/':
                    p.x = j + 1, p.y = i - 1;
                    break;
                case '|':
                    p.x = j, p.y = i - 1;
                    break;
                case '\\':
                    p.x = j - 1, p.y = i - 1;
                    break;
                case '(':
                    p.x = j + 1, p.y = i - 2;
                    break;
                case ')':
                    p.x = j - 1, p.y = i - 2;
                    break;
                default:
                    break;
                }

                if (s[j]!=' ')
                {
                    person.insert(p);
                }
                
            }
            
            
        }

        cout << person.size() << endl;
    }
    return 0;
}