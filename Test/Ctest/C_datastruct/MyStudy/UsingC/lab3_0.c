#include<stdio.h>

/*
实验题目：图的建立、遍历及其应用
设图中顶点的元素类型为VertType( 或者DataType，可以为char或int)，实现以下图的各种基本操作：
①	建立一个不少于10个顶点的带权无向图G（可以通过文件读取方式输入）；
②	用邻接矩阵作为储结构存储图G并输出该邻接矩阵；
③	用邻接链表作为储结构存储图G并输出该邻接链表；
④	按深度优先遍历(DFS)算法输出图G中顶点的遍历序列；
⑤	按广度优先遍历(BFS)算法输出图G中顶点的遍历序列；
⑥	编写函数求邻接矩阵（或者邻接表）存储结构的图G中各顶点的入度和出度（如果是无向图，则入度和出度一样，为顶点的度）；
⑦	使用Prim算法(或者Kruskal算法)从某个指定的顶点出发输出图G的最小生成树；（要求把最小生成树的各条边输出成A-B-wight,或者(A,B,weight)的形式）；
⑧	主函数通过菜单选择函数调用实现以上各项操作，请在实验报告中请画出设计的图。
*/

void CreateGrid();
void PrintGrid();
void PrintGrid();
void DFS();
void BFS();
void Prim();
void Kruskal();
void Getdeegre();

int main(){

    return 0;
}