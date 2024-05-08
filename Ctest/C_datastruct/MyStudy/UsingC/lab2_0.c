#include<stdio.h>

/*
实验题目：二叉树的建立、遍历及其应用
设树结点的元素类型为ElemType(可以为char或int)，采用二叉链（或三叉链，即双亲孩子）存储，实现以下二叉树的各种基本操作的程序：
①	编写一个创建二叉树的函数，建立不少于8个结点的二叉树T（建议通过文件读取，用递归方式创建）； 
②	给定元素x，在二叉树中查找该元素x，若找到则返回该结点的指针；
③	用凹入表示法打印该二叉树（可以是图8-2的形式或者8.4.3中的逆时针旋转90°，一个先序，一个中序RDL）；
④	用非递归方式先序遍历方式输出树T的结点；（用到栈） 
⑤	用中序或后序遍历方式输出树T的结点； 
⑥	用层次遍历方式输出树T的结点；（用到队列）
⑦	输出树T的深度；
⑧	输出树T的叶子结点或非叶子结点；
⑨	主函数设计菜单，通过菜单选择相应的函数调用实现以上各项操作。（在实验报告中请画出测试的二叉树。）
*/

void CreateTree();
pointer* GetPtrbyval(int val);
void PrintTree();
void PrePrintTree();
void MidPrintTree();
void EndPrintTree();
void BFSPrintTree();
int Getdepth();
int *Getyezi();

int main(){

    return 0;
}