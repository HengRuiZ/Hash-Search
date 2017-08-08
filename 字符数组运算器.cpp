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
int StrSearch(char a[],char b[])//����ֵ��a�ĵڼ�λ������0��û�н��
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
		{printf("��%d�е�%dλ����%dλΪҪ���ҵ��ַ���\n",i+1,j,j+sizeof(b)-1);k=1;}
	}
	if(k==0)printf("û�����������\n");
}
main()
{
	int i,j,k,m,n;
	char a[N][M]={0};
	char b[M]={0},c[M]={0};
	while(1)
	{
		printf("0.�˳�\n1.�����ַ���\n2.��ʾ�ַ���\n3.�󴮳�\n4.������\n5.���Ƚ�\n6.������\n7.ת�ɴ�Щ\n8.ת��Сд\n9.������\n10.���Ӵ�\n11.������\n12.���û�\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:return 0;
			case 1:{
				printf("Ҫ�����ڵڼ��У�\n");
				scanf("%d",&i);
				printf("�������ַ���\n");
				getchar();
				gets(a[i-1]);
				break;
			}
			case 2:{
				output(a);
				break;
			}
			case 3:{
				printf("Ҫ��ڼ��еĴ�����\n");
				scanf("%d",&j);
				i=CAL(a[j-1]);
				printf("����Ϊ%d\n",i);
				break;
			}
			case 4:{
				printf("������Ҫ���ӵ��ַ��������ͱ����ӵ��ַ����������м��ÿո����\n");
				scanf("%d %d",&j,&k);
				AC(a[k-1],a[j-1]);
				break;
			}
			case 5:{
				printf("������Ҫ�Ƚϵ��ַ�������,�м��ÿո����\n");
				scanf("%d %d",&j,&k); 
				i=comp(a[j-1],a[k-1]);
				switch(i)
				{
					case 1:printf("��%d��>��%d��\n",j,k);break;
					case 0:printf("��%d��=��%d��\n",j,k);break;
					case -1:printf("��%d��>��%d��\n",k,j);break;
				}
				break;
			}
			case 6:{
				printf("�����븴�Ƶ�������Ҫ���Ƶ���λ�ã��м��ÿո����\n");
				scanf("%d %d",&j,&k);
				strcpy(a[k-1],a[j-1]);
				break;
			}
			case 7:{
				printf("��һ����ҪתΪ��д��\n");
				scanf("%d",&j);
				for(i=0;i<CAL(a[j-1]);i++)
				if(a[j-1][i]>=97&&a[j-1][i]<=122)
				a[j-1][i]=a[j-1][i]-32;
				}
				break;
			case 8:{
				printf("��һ����ҪתΪСд��\n");
				scanf("%d",&j);
				for(i=0;i<CAL(a[j-1]);i++)
				if(a[j-1][i]>=65&&a[j-1][i]<=90)
				a[j-1][i]=a[j-1][i]+32;
				break; 
			}
			case 9:{
				printf("������Ҫ������ַ��������ͱ�������ַ�������,�м��ÿո����\n");
				scanf("%d %d",&j,&k);
				printf("Ҫ���뵽�����±�֮ǰ��\n");
				scanf("%d",&m);
				Insert(a[k-1],m,a[j-1]);
				break;
			}
			case 10:{
				printf("������Ҫ��ȡ���ַ��������Ϳ�ʼ��ȡ���±�ͽ�ȡλ����֮���ÿո����\n");
				scanf("%d %d %d",&j,&m,&n);
				SS(a[j-1],m,n);
				break;
			}
			case 11:{
				printf("������Ҫ���ҵ��ַ���\n");
				getchar();
				gets(b);
				search(a,b,10);
				break;
			}
			case 12:{
				printf("������Ҫ�û����ַ���\n");
				getchar();
				gets(c);
				printf("�����뱻�û����ַ���\n");
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
