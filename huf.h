#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
#define startsize 100

//����������ڵ�
typedef struct{
	char valu;
	int weight;
}Node;

//������������������
typedef struct tree{
	Node *node;
	struct tree *parent;
	struct tree *left;//������
	struct tree *right;//������
}HufumanTree;



Node * Createmptynode();
Node * CreateNodeWithWeight();
HufumanTree * CreatemptyHufumanTree();
void InitNode(HufumanTree m[],int n);
HufumanTree * CreatHufumanTree(HufumanTree a[],int length,HufumanTree sum[]);
void HufumanTreecode(HufumanTree *hufumanTree,char charreat[],int n1,HufumanTree sum[]);
void HufumanTreeDecode(HufumanTree *HfTree,char *code,int n2);

