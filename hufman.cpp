#include "huf.h"
#include "minh.h"
int main(){
	int chouse,time,j;
	char charreat[100],code[200],val[9]={'a','b','c','d','e','f','g','h','i'};
	int num,i,k,wei[9]={1,8,3,2,5,6,10,8,15};
	HufumanTree *Tree,sum[N*2],node[N];
	HufumanTree *h1,*h2;


	Tree=CreatemptyHufumanTree();
	num=9;
	printf("��������Ϊ:\n");
	InitNode(node,num+1);
	/*��ʼ��node�ڵ�*/
	for(i=1,j=0;i<num+1;i++,j++){
		node[i].node->valu=val[j];
		node[i].node->weight=wei[j];
	}
	/*��ʼ��ÿ��sum�ڵ�*/
	for(i=0;i<N*2;i++){
		sum[i]=*CreatemptyHufumanTree();
	}
	/*���HufumanTree���ڵ�*/
	Tree=CreatHufumanTree(node,num+1,sum);
	printf("%d\n",Tree->node->weight);
	while(chouse!=3){
		printf("********************************************************************************\n");
		printf("��������Ҫѡ��ķ���\n\n");
		printf("1.����\t\t2.����\t\t3.�˳�\n");
		printf("********************************************************************************\n");
		scanf("%d",&chouse);
		getchar();
		while(chouse>3||chouse<1){
			printf("�����������,����������\n");
			scanf("%d",&chouse);
			getchar();
		}
		switch(chouse){
			case 1:
				printf("��������Ҫ������ַ���\n");
				scanf("%s",charreat);
				printf("������Ϊ:\n");
				k=strlen(charreat);
				HufumanTreecode(Tree,charreat,k,sum);
				printf("\n\n");
				printf("�����������");
				getchar();
				scanf("%c",&time);
				break;
			case 2:
				printf("������Ҫ����Ķ�������\n");
				scanf("%s",&code);
				k=strlen(code);
				printf("������Ϊ:\t");
				HufumanTreeDecode(Tree,code,k);
				printf("\n\n�����������");
				getchar();
				scanf("%c",&time);
				break;
			}
		}
	return 0;
}
