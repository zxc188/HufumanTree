#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
#define startsize 100

void exchange(HufumanTree a[],int i,int j);
int Left(int i);
int Right(int i);
void min_heapify(HufumanTree a[],int i,int length);
void BUILD_MIN_HEAP(HufumanTree a[],int length);
