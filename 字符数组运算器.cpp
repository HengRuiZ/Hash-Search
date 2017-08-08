#include<stdio.h>
#include<stdlib.h>
#define N 10
#define M 1000
int CAL(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
} 
void output(char a[][M])
{
	int i;
	for(i=0;i<N;i++)
	printf("%d:%s\n",i+1,a[i]);
}
void AC(char a[],char b[])
{
	int i,j,k;
	j=CAL(a);
	k=CAL(b);
	for(i=j;i<j+k;i++)
	a[i]=b[i-j];
	a[j+k]='\0';
}
int comp(char a[],char b[])
{
	int i;
	for(i=0;i<M;i++)
	{
	if(a[i]>b[i])
	return 1;
	if(a[i]<b[i])
	return -1;
	}
	return 0;
}
void strcpy(char a[],char b[])
{
	int i,j;
	j=CAL(b);
	for(i=0;i<=j;i++)
	a[i]=b[i];
}
void Insert(char s[],int pos,char t[])
{
	int i,j,k;
	j=CAL(s);
	k=CAL(t);
	s[j+k]='\0';
	for(i=j+k-1;i>=pos;i--)
	s[i]=s[i-k];
	for(i=pos;i<pos+k;i++)
	s[i]=t[i-pos];
}
void SS(char s[],int pos,int n)
{
	int i;
	char b[]={0};
	for(i=pos;i<pos+n;i++)
	b[i-pos]=s[i];
	b[n]='\0';
	printf("%s\n",b);
}
int StrSearch(char a[],char b[])//返回值是a的第几位；返回0则没有结果
{
	int j,k;
	if(sizeof(a)<sizeof(b))return 0;
	for(j=0;j<=sizeof(a)-sizeof(b);j++)
	if(a[j]==b[0])
	for(k=1;k<sizeof(b);k++)
	{
		if(a[j+k]!=b[k])break;
		if(k==sizeof(b)-1)
		return j+1;
	}
}
void search(char a[][1000],char b[],int n)
{
	int i,j,k=0;
	for(i=0;i<n;i++)
	{
		j=StrSearch(a[i],b);
		if(j!=0)
		{printf("第%d行第%d位到第%d位为要查找的字符串\n",i+1,j,j+sizeof(b)-1);k=1;}
	}
	if(k==0)printf("没有搜索结果！\n");
}
main()
{
	int i,j,k,m,n;
	char a[N][M]={0};
	char b[M]={0},c[M]={0};
	while(1)
	{
		printf("0.退出\n1.输入字符串\n2.显示字符串\n3.求串长\n4.串连接\n5.串比较\n6.串复制\n7.转成大些\n8.转成小写\n9.串插入\n10.求子串\n11.串查找\n12.串置换\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:return 0;
			case 1:{
				printf("要保留在第几行？\n");
				scanf("%d",&i);
				printf("请输入字符串\n");
				getchar();
				gets(a[i-1]);
				break;
			}
			case 2:{
				output(a);
				break;
			}
			case 3:{
				printf("要求第几行的串长？\n");
				scanf("%d",&j);
				i=CAL(a[j-1]);
				printf("串长为%d\n",i);
				break;
			}
			case 4:{
				printf("请输入要连接的字符串行数和被连接的字符串行数，中间用空格隔开\n");
				scanf("%d %d",&j,&k);
				AC(a[k-1],a[j-1]);
				break;
			}
			case 5:{
				printf("请输入要比较的字符串行数,中间用空格隔开\n");
				scanf("%d %d",&j,&k); 
				i=comp(a[j-1],a[k-1]);
				switch(i)
				{
					case 1:printf("第%d行>第%d行\n",j,k);break;
					case 0:printf("第%d行=第%d行\n",j,k);break;
					case -1:printf("第%d行>第%d行\n",k,j);break;
				}
				break;
			}
			case 6:{
				printf("请输入复制的行数和要复制到的位置，中间用空格隔开\n");
				scanf("%d %d",&j,&k);
				strcpy(a[k-1],a[j-1]);
				break;
			}
			case 7:{
				printf("哪一行需要转为大写？\n");
				scanf("%d",&j);
				for(i=0;i<CAL(a[j-1]);i++)
				if(a[j-1][i]>=97&&a[j-1][i]<=122)
				a[j-1][i]=a[j-1][i]-32;
				}
				break;
			case 8:{
				printf("哪一行需要转为小写？\n");
				scanf("%d",&j);
				for(i=0;i<CAL(a[j-1]);i++)
				if(a[j-1][i]>=65&&a[j-1][i]<=90)
				a[j-1][i]=a[j-1][i]+32;
				break; 
			}
			case 9:{
				printf("请输入要插入的字符串行数和被插入的字符串行数,中间用空格隔开\n");
				scanf("%d %d",&j,&k);
				printf("要插入到几号下标之前？\n");
				scanf("%d",&m);
				Insert(a[k-1],m,a[j-1]);
				break;
			}
			case 10:{
				printf("请输入要截取的字符串行数和开始截取的下标和截取位数，之间用空格隔开\n");
				scanf("%d %d %d",&j,&m,&n);
				SS(a[j-1],m,n);
				break;
			}
			case 11:{
				printf("请输入要查找的字符串\n");
				getchar();
				gets(b);
				search(a,b,10);
				break;
			}
			case 12:{
				printf("请输入要置换的字符串\n");
				getchar();
				gets(c);
				printf("请输入被置换的字符串\n");
				gets(b);
				for(i=0;i<N;i++)
				{
					if(CAL(a[i])<CAL(b))continue;
					for(j=0;j<=CAL(a[i])-CAL(b);j++)
					if(a[i][j]==b[0])
					for(k=1;k<CAL(b);k++)
					{
						if(a[i][j+k]!=b[k])break;
						if(k==CAL(b)-1)
						{
							for(k=0;k<CAL(a[i]);k++)
							a[i][j+k]=a[i][j+CAL(b)+k];
							m=CAL(a[i]);
							n=CAL(c);	
							for(k=0;k<=CAL(c);k++)
							a[i][m+n-k]=a[i][m-k];
							for(k=0;k<CAL(c);k++)
							a[i][j+k]=c[k];
						}
					}
				}
				break;
			}
			default:break;
		}
	}
}
