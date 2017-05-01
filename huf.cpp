#include "huf.h"
#include "minh.h"
//创建一个不带权值的节点
Node * Createmptynode(){
	Node *node;
	node=(Node *)malloc(sizeof(Node));
	if(!node)
		exit(-1);
	node->valu='\0';
	node->weight=0;
	return node;
}

//创建一个带有权值的节点
Node * CreateNodeWithWeight(){
	Node *node;
	node=(Node *)malloc(sizeof(Node));
	if(!node)
		exit(-1);
	else{
		printf("请输入字符：\n");
		getchar();
		scanf("%c",&node->valu);
		printf("请输字符入权值\n");
		scanf("%d",&node->weight);
		printf("\n");
	}
	return node;
}

//创建一个空的霍夫曼树节点
HufumanTree * CreatemptyHufumanTree(){
	HufumanTree *Tree;
	Tree=(HufumanTree*)malloc(sizeof(HufumanTree));
	if(!Tree)
		exit(-1);
	Tree->node=Createmptynode();
	if(!(Tree->left=(HufumanTree*)malloc(sizeof(HufumanTree))))
		exit(-1);
	if(!(Tree->right=(HufumanTree*)malloc(sizeof(HufumanTree))))
		exit(-1);
	Tree->parent=NULL;
	Tree->right=NULL;
	Tree->left=NULL;
	return Tree;
}

//初始化数据节点
void InitNode(HufumanTree m[],int n){
	int i;
	for(i=0;i<n;i++){
		m[i]=*CreatemptyHufumanTree();
	}
}
//创建一个霍夫曼树
HufumanTree * CreatHufumanTree(HufumanTree a[],int length,HufumanTree sum[]){
	int i,l,r,minint,s;
	HufumanTree *hf,*one,*two,*add;
	s=0;
	l=2;
	r=3;
	hf=CreatemptyHufumanTree();
	while(length!=2){
		BUILD_MIN_HEAP(a,length);
		if(r>length-1&&l<=length-1){
			minint=l;
		}
		else{
				if(l<=length-1&&r<=length-1&&a[l].node->weight<=a[r].node->weight){
					minint=l;
					}
				if(l<=length-1&&r<=length-1&&a[l].node->weight>a[r].node->weight){
					minint=r;
					}
			}
		if(minint!=2){
				exchange(a,l,r);
			}
		if(a[1].left&&a[2].left){
			sum[s].left=a[1].left->parent;
			sum[s].right=a[2].left->parent;
			a[1].left->parent->parent=&sum[s];
			a[2].left->parent->parent=&sum[s];
			sum[s].node->weight=a[1].node->weight+a[2].node->weight;
			a[1]=sum[s];
			s=s+1;
		}else if(a[1].left&&!a[2].left){
			sum[s]=a[2];
			sum[s+1].left=a[1].left->parent;
			sum[s+1].right=&sum[s];
			sum[s].parent=&sum[s+1];
			a[1].left->parent->parent=&sum[s+1];
			sum[s+1].node->weight=a[1].node->weight+a[2].node->weight;
			a[1]=sum[s+1];
			s=s+2;
		}else if(!a[1].left&&a[2].left){
			sum[s]=a[1];
			sum[s+1].left=&sum[s];
			sum[s+1].right=a[2].left->parent;
			sum[s].parent=&sum[s+1];
			a[2].left->parent->parent=&sum[s+1];
			sum[s+1].node->weight=a[1].node->weight+a[2].node->weight;
			a[1]=sum[s+1];
			s=s+2;
		}else{
		sum[s]=a[1];
		sum[s+1]=a[2];
		sum[s+2].node->weight=sum[s].node->weight+sum[s+1].node->weight;
		sum[s+2].left=&sum[s];
		sum[s+2].right=&sum[s+1];
		sum[s].parent=&sum[s+2];
		sum[s+1].parent=&sum[s+2];
		a[1]=sum[s+2];
		s=s+3;
		}
		exchange(a,2,length-1);
		--length;
	}
	hf=&sum[s-1];

	return hf;
}
//霍夫曼编码
void HufumanTreecode(HufumanTree *hufumanTree,char charreat[],int n1,HufumanTree sum[]){
	int start,i,j,h;
	char code[N*2];
	HufumanTree *f1,*f2,*f3;
	for(j=0;j<n1;j++){
		for(i=0;i<1000;i++){
			if(sum[i].node->valu==charreat[j]){
				f2=&sum[i];
				f1=sum[i].parent;
				break;
			}
		}
		start=N*2-1;
		while(f1){
			if(f2==f1->left){
			code[start]='0';
			f3=f2;
			f2=f3->parent;
			f1=f2->parent;
			--start;
			}
			else{
			code[start]='1';
			f3=f2;
			f2=f3->parent;
			f1=f2->parent;
			--start;
			}
		}
		printf("%c\t",charreat[j]);
		for(h=start+1;h<N*2;h++){
			printf("%c",code[h]);
		}
		printf("\n");
	}
}
//霍夫曼译码
void HufumanTreeDecode(HufumanTree *HfTree,char *code,int n2){
	HufumanTree *hf1,*hf2;
	int i;
	hf1=CreatemptyHufumanTree();
	hf2=CreatemptyHufumanTree();
	hf2=HfTree;
		for(i=0;i<n2;i++){
					if(code[i]=='0'){
						hf1=hf2;
						hf2=hf2->left;
						}
					if(code[i]=='1'){
						hf1=hf2;
						hf2=hf2->right;
						}
					if(!hf2){
						--i;
						printf("%c",hf1->node->valu);
						hf2=HfTree;
					}
		}
		printf("%c\n",hf2->node->valu);
	}


