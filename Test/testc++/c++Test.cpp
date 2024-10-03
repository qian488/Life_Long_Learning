
#include<iostream>
using namespace std;
int main()
{
    cout << "纸上谈来终觉浅，绝知此事要躬行！" << endl;
    return 0;
}
/*
//删除单向循环链表的某个结点的前驱结点
#include <iostream>

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node** s) {
    if (*s == NULL || (*s)->next == *s) {
        // 空链表或只有一个节点的情况
        return;
    }

    Node* curr = *s;//当前结点
    Node* prev = curr;//真正待删除的结点

    // 遍历链表找到要删除节点的前一个节点
    while (1)
    {
        if (prev->next->next == *s)
        {
            break;
        }
        curr = curr->next;
        prev = curr;
    }

    // 前一个节点指向被删除节点的下一个节点
    prev->next = curr->next->next;
    
    // 释放要删除的节点内存
    //delete prev;
    //prev = NULL;
}

int main() {
    Node* node1 = new Node{1, NULL};
    Node* node2 = new Node{2, node1};
    Node* node3 = new Node{3, node2};
    Node* node4 = new Node{4, node3};
    node1->next = node4;  // 形成循环链表

    Node* nodeToDelete = node2;  // 要删除节点的后驱结点

    deleteNode(&nodeToDelete);

    // 打印剩余节点
    Node* curr = node1;
    do
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != node1);
    std::cout << std::endl;

    // 释放剩余节点内存
    curr = node1;
    Node* temp;
    do {
        temp = curr->next;
        delete curr;
        curr = temp;
    } while (curr != node1);

    return 0;
}
*/