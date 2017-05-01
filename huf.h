#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
#define startsize 100

//霍夫曼编码节点
typedef struct{
	char valu;
	int weight;
}Node;

//霍夫曼树的数据类型
typedef struct tree{
	Node *node;
	struct tree *parent;
	struct tree *left;//左子树
	struct tree *right;//右子树
}HufumanTree;



Node * Createmptynode();
Node * CreateNodeWithWeight();
HufumanTree * CreatemptyHufumanTree();
void InitNode(HufumanTree m[],int n);
HufumanTree * CreatHufumanTree(HufumanTree a[],int length,HufumanTree sum[]);
void HufumanTreecode(HufumanTree *hufumanTree,char charreat[],int n1,HufumanTree sum[]);
void HufumanTreeDecode(HufumanTree *HfTree,char *code,int n2);

