#include "huf.h"
#include "minh.h"
//��С��
void exchange(HufumanTree a[],int i,int j){//���������������н���λ��
		HufumanTree t;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
int Left(int i){//�ҵ���iΪ����Ķѵ�����
		return 2*i;
	}
	
int Right(int i){//�ҵ���iΪ����Ķѵ��Һ���
		return 2*i+1;
	}
void min_heapify(HufumanTree a[],int i,int length){//��֤��iΪ����������ֶѵ�����
		int minest;
		int l=Left(i);
		int r=Right(i);
		if(l<=length-1&&a[l].node->weight<a[i].node->weight){
			minest=l;
		}else{
			minest=i;
		}
		if(r<=length-1&&a[r].node->weight<a[minest].node->weight){
			minest=r;
		}
		if(minest!=i){
		exchange(a,i,minest);
			min_heapify(a,minest,length);
		}
	}
void BUILD_MIN_HEAP(HufumanTree a[],int length){//��С����
		int i;
		int mid=length/2;
		for(i=mid;i>0;i--){
			min_heapify(a,i,length);
		}
		for(i=1;i<length;i++){
		printf("%d\t",a[i].node->weight);
		}
		printf("\n");
	}