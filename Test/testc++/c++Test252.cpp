#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

struct Node
{
    Node *left;
    Node *right;
    int val;

    Node() : left(nullptr), right(nullptr), val(0) {}
    Node(int val) : left(nullptr), right(nullptr), val(val) {}
};

unordered_map<int, Node *> m;
Node *head = new Node();
Node *tail = new Node();

void add(int x,int y)
{
    Node *ynode = m[y];
    Node *t = new Node(x);
    Node *second = ynode->right;
    ynode->right = t;
    t->left = ynode;
    t->right = second;
    second->left = t;
    m[x] = t;
}

void addHead(int x)
{
    Node *t = new Node(x);
    Node *second = head->right;
    head->right = t;
    t->left = head;
    t->right = second;
    second->left = t;
    m[x] = t;
}

void remove(int x)
{
    Node *xnode = m[x];
    Node *left = xnode->left;
    Node *right = xnode->right;
    left->right = right;
    right->left = left;
    m.erase(x);
    delete xnode;
}

vector<int> toList()
{
    vector<int> res;
    Node *it = head->right;
    while (it!=tail)
    {
        res.push_back(it->val);
        it = it->right;
    }
    return res;
}

void Solve()
{

    head->right = tail;
    tail->left = head;

    int n;
    cin >> n;
    while (n--)
    {
        int type;
        cin >> type;
        if (type==1)
        {//在x后插入y
            int x, y;
            cin >> x >> y;
            if(y==0)
            {
                addHead(x);
            }
            else
            {
                add(x, y);
            }
        }
        else if(type==2)
        {//删除节点
            int x;
            cin >> x;
            remove(x);
        }
    }

    vector<int> ans = toList();
    cout << ans.size() << endl;
    for (auto e:ans)
    {
        cout << e << " ";
    }
    
    //clear
    for (auto it = m.begin(); it != m.end(); ++it) {
        delete it->second;
    }
    delete head;
    delete tail;
    
}

int main()
{
    ios
    Solve();
    //牛客周赛 Round 31_D小红数组操作
    //其实和atcoder那题一样，可以使用 map 来辅助维护节点值到节点指针的映射，以实现快速查找。
    return 0;
}
/*AC代码
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;

    Node() : left(nullptr), right(nullptr), val(0) {}
    Node(int val) : left(nullptr), right(nullptr), val(val) {}
};

class Structure {
private:
    unordered_map<int, Node*> hash;
    Node* head;
    Node* tail;

public:
    Structure() {
        head = new Node();
        tail = new Node();
        head->right = tail;
        tail->left = head;
    }

    void add(int x, int y) {
        Node* yn = hash[y];
        Node* cur = new Node(x);
        Node* second = yn->right;
        yn->right = cur;
        cur->left = yn;
        cur->right = second;
        second->left = cur;
        hash[x] = cur;
    }

    void addHead(int x) {
        Node* cur = new Node(x);
        Node* second = head->right;
        head->right = cur;
        cur->left = head;
        cur->right = second;
        second->left = cur;
        hash[x] = cur;
    }

    void remove(int x) {
        Node* xn = hash[x];
        Node* left = xn->left;
        Node* right = xn->right;
        left->right = right;
        right->left = left;
        hash.erase(x);
        delete xn;
    }

    vector<int> toList() {
        vector<int> res;
        Node* iter = head->right;
        while (iter != tail) {
            res.push_back(iter->val);
            iter = iter->right;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Structure structure;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            if (y == 0) {
                structure.addHead(x);
            } else {
                structure.add(x, y);
            }
        } else {
            int x;
            cin >> x;
            structure.remove(x);
        }
    }
    vector<int> res = structure.toList();

    cout << res.size() << "\n";
    stringstream ss;
    for (int num : res) {
        ss << num << " ";
    }
    string result = ss.str();
    result.pop_back(); // Remove the trailing space
    cout << result << "\n";

    return 0;
}
*/