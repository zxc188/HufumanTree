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
	printf("建树过程为:\n");
	InitNode(node,num+1);
	/*初始化node节点*/
	for(i=1,j=0;i<num+1;i++,j++){
		node[i].node->valu=val[j];
		node[i].node->weight=wei[j];
	}
	/*初始化每个sum节点*/
	for(i=0;i<N*2;i++){
		sum[i]=*CreatemptyHufumanTree();
	}
	/*获得HufumanTree根节点*/
	Tree=CreatHufumanTree(node,num+1,sum);
	printf("%d\n",Tree->node->weight);
	while(chouse!=3){
		printf("********************************************************************************\n");
		printf("请输入你要选择的服务\n\n");
		printf("1.编码\t\t2.译码\t\t3.退出\n");
		printf("********************************************************************************\n");
		scanf("%d",&chouse);
		getchar();
		while(chouse>3||chouse<1){
			printf("你的输入有误,请重新输入\n");
			scanf("%d",&chouse);
			getchar();
		}
		switch(chouse){
			case 1:
				printf("请输入你要编码的字符串\n");
				scanf("%s",charreat);
				printf("编码结果为:\n");
				k=strlen(charreat);
				HufumanTreecode(Tree,charreat,k,sum);
				printf("\n\n");
				printf("按任意键继续");
				getchar();
				scanf("%c",&time);
				break;
			case 2:
				printf("请输入要解码的二进制码\n");
				scanf("%s",&code);
				k=strlen(code);
				printf("译码结果为:\t");
				HufumanTreeDecode(Tree,code,k);
				printf("\n\n按任意键继续");
				getchar();
				scanf("%c",&time);
				break;
			}
		}
	return 0;
}
