#include "iostream"
#include "SearchKey.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "hash.h"
using namespace std;
FILE*fp1,*fp2;
main(){
	int i,frqc1[HASH_LENGTH],frqc2[HASH_LENGTH];
	KeyInfo a[HASH_LENGTH];
	float X,D;
	char s[100];
	char key[32][9]={"int","char","float","void","auto","short","long","double","stuct","union","enum","typedef","const","unsigned","signed","extern","register","static","volatile","if","else","switch","case","for","do","while","goto","continue","break","default","sizeof","return"};
	for(i=0;i<HASH_LENGTH;i++)
	{
		a[i].key[0]='\0';
		a[i].frqc1=0;
		a[i].frqc2=0;
	}
	FormHash(a,key);
	cout<<"请输入第一个文件名"<<endl;
	cin>>s;
	if((fp1=fopen(s,"r"))==NULL){
		cout<<"无法打开文件\"数组运算器.cpp\""<<endl;
		system("pause");
		exit(0);
	}
	cout<<"请输入第二个文件名"<<endl;
	cin>>s;
	if((fp2=fopen(s,"r"))==NULL){
		cout<<"无法打开文件\"字符数组运算器.cpp\""<<endl;
		system("pause");
		exit(0);
	}
	for(i=0;i<HASH_LENGTH;i++)
	frqc1[i]=frqc2[i]=0;
	SearchKey_F(a,fp1,frqc1);
	for(i=0;i<HASH_LENGTH;i++)
	a[i].frqc1=frqc1[i];
	SearchKey_F(a,fp2,frqc2);
	for(i=0;i<HASH_LENGTH;i++)
	a[i].frqc2=frqc2[i];
	fclose(fp1);
	fclose(fp2);
	for(i=0;i<HASH_LENGTH;i++)
	//printf("%d	%s	%d	%d\n",i,a[i].key,a[i].frqc1,a[i].frqc2);
	X=Cos(frqc1,frqc2);
	D=L(frqc1,frqc2);
	printf("X=%f	D=%f\n",X,D);
	if(X>0.5&&D<0.5)
	printf("两源程序相似度较高。\n");
	else
	printf("两源程序相似度不高。\n"); 
	system("pause");
}
int h(char x[9])
{
	int a,i;
	for(i=0;x[i]!='\0';i++);
	a=x[0]*100+x[i-1];
	return a%41;
}
void FormHash(KeyInfo*a,char key[KEY_NUM][9])
{
	int i,j,k;
	for(i=0;i<KEY_NUM;i++)
	{
		if(!a[j=k=h(key[i])].key[0])
		{strcpy(a[j].key,key[i]);
		//printf("%d	%s到%d\n",i,key[i],j);
		}
		else
		{
			while(a[j=(++j)%HASH_LENGTH].key[0])
			if(j==k){
				cout<<"插槽不足！"<<endl;
				exit(0);
			}
			strcpy(a[j].key,key[i]);
			//printf("%d	%s到%d\n",i,key[i],j);
		}
		
	}
}
int Hash(char key[9],KeyInfo *a,int &i)
{
	int j;
	if(strcmp(a[i=h(key)].key,key)==0)
	return 1;
	else
	for(j=1;j<HASH_LENGTH;j++)
	{
		i=(++i)%HASH_LENGTH;
		if(strcmp(a[i].key,key)==0)
		return 1;
	}
	return 0;
}
void SearchKey_F(KeyInfo *a,FILE*fp,int*frqc)
{
	char key[9];
	int i;
	while(!feof(fp))
	{
		while(1){
			if(feof(fp))return;
			key[0]=fgetc(fp);
			if(key[0]>96&&key[0]<123)break;
		}
		if(feof(fp))return;
		for(i=1;i<9;i++)
		{
			key[i]=fgetc(fp);
			if(key[i]<97||key[i]>122)
			break;
		}
		if(i<9)
		{
			key[i]='\0';
			if(Hash(key,a,i))
			frqc[i]++;
		}
	}
}
float Cos(int *x1,int *x2)
{
	int i;
	float Y=0,X1=0,X2=0;
	for(i=0;i<HASH_LENGTH;i++)
	{
		X1+=pow(x1[i],2);
		X2+=pow(x2[i],2);
		Y+=x1[i]*x2[i];
	}
	return Y/sqrt(X1*X2);
}
float L(int *x1,int *x2)
{
	int i;
	float Z=0,X1=0,X2=0;
	for(i=0;i<HASH_LENGTH;i++)
	{
		Z+=pow(x1[i]-x2[i],2);
		X1+=pow(x1[i],2);
		X2+=pow(x2[i],2);
	}
	return Z/sqrt(X1*X2);
}
