/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N = 1e6 + 10;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

void insertAfter(Node* x, int y) 
{
    Node* newNode = new Node();
    newNode->value = y;
    newNode->prev = x;
    newNode->next = x->next;
    x->next->prev = newNode;
    x->next = newNode;
}

void removeNode(Node* x) 
{
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;
}

void solve()
{
    int N;
    cin >> N;
    Node* head = new Node(); // Dummy head node
    Node* tail = new Node(); // Dummy tail node
    head->next = tail;
    tail->prev = head;

    // Construct initial sequence
    for (int i = 0; i < N; ++i) 
    {
        int value;
        cin >> value;
        insertAfter(tail->prev, value);
    }

    int Q;
    cin >> Q;
    while (Q--) 
    {
        int type;
        cin >> type;
        if (type == 1) 
        {
            int x, y;
            cin >> x >> y;
            Node* current = head->next;
            while (current != tail) 
            {
                if (current->value == x) 
                {
                    insertAfter(current, y);
                    break;
                }
                current = current->next;
            }
        } 
        else if (type == 2) 
        {
            int x;
            cin >> x;
            Node* current = head->next;
            while (current != tail) 
            {
                if (current->value == x) 
                {
                    Node* toRemove = current;
                    current = current->next;
                    removeNode(toRemove);
                    break;
                }
                current = current->next;
            }
        }
    }

    // Print the sequence
    Node* current = head->next;
    while (current != tail) 
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

    // Free memory
    while (head->next != tail) 
    {
        Node* toRemove = head->next;
        head->next = toRemove->next;
        delete toRemove;
    }
    delete head;
    delete tail;
}

int main() 
{
    ios
    solve();
    //AtCoder Beginner Contest 344_E.Insert or Erase
    //放弃数组模拟了，还是直接用结构体加指针
    //TLE...
    //链表本身太慢了，可以使用 map 来辅助维护节点值到节点指针的映射，以实现快速查找。
    return 0;
}
*/
//AC代码
#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<random>
#include<functional>
#include<time.h>
#include<cstring>
#include<bitset>
#include<array>
using namespace std;
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'

struct node {
    int val;
    node *pre=NULL,*next=NULL;
};

signed main() {
    
    // ios::sync_with_stdio(0); cout.tie(0);

    int n;cin>>n;

    map<int,node*> ma;
    node *head;
    head=new node;
    cin>>head->val;
    node *curr=head;
    ma[head->val]=head;
    for(int i=1;i<n;i++) {
        node *p=curr;
        curr=new node;
        cin>>curr->val;
        p->next=curr;
        curr->pre=p;
        ma[curr->val]=curr;
    }

    int q;cin>>q;
    while(q--) {
        int type;cin>>type;
        if(type==1) {
            int x,y;cin>>x>>y;
            node *curr=ma[x];
            node *ne=new node;
            ne->val=y;
            ma[y]=ne;
            if(curr->next) {
                curr->next->pre=ne;
                ne->next=curr->next;
            }
            curr->next=ne;
            ne->pre=curr;
        } else {
            int x;cin>>x;
            node *curr=ma[x];
            if(curr->pre) {
                curr->pre->next=curr->next;
            } else {
                head=curr->next;
            }
            if(curr->next) {
                curr->next->pre=curr->pre;
            }
        }
    }

    for(node *curr=head;curr;curr=curr->next) {
        cout<<curr->val<<" ";
    }

    return 0;
}