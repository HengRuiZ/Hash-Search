#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void printarray(int array[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	printf("%d	",array[i]);
}
void selectsort(int array[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		j=i;
		k=i+1;
		for(k;k<n;k++)
		{
			if(array[j]<array[k])
			j=k;
		}
		if(j!=i){
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
		}
	}
}
void exchangesort(int a[],int n)
{
	int i,k,temp;
	for(i=0;i<n-1;i++)
	for(k=i+1;k<n;k++)
	{
		if(a[i]<a[k])
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
}
void bubblesort(int a[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		j=0;
		for(k=0;k<n-i-1;k++)
		{
			if(a[k]<a[k+1])
			{
				temp=a[k+1];
				a[k+1]=a[k];
				a[k]=temp;
				j=1;
			}
		}
		if(j=0)
		return;
	}
}
void bubblereverse(int a[],int n)
{
	int temp,i;
	n--;
	for(i=0;i<n;i++,n--)
	{
		temp=a[i];
		a[i]=a[n];
		a[n]=temp;
	}
}
void judgesort(int a[],int n)
{
	int i,j,k;
	j=0,k=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i]<=a[i+1])
		j=1;
		if(a[i]>=a[i+1])
		k=1;
	}
	if(j==0)
	printf("����Ϊ����\n");
	if(k==0)
	printf("����Ϊ����\n");
	if(j!=0&&k!=0)
	printf("��������\n");
}
int binarysearch(int a[],int n,int key)
{
	int low,mid,high;
	low=0;high=n-1;
	if(a[low]<a[high])
	{ 
		while(low<high)
		{
			mid=(low+high)/2;
			if(key>a[mid])
			low=mid+1;
			else if(key==a[mid])
			return(mid);
			else
			high=mid-1;
		}
	}
	else
	{
		while(low<high)
		{
			mid=(low+high)/2;
			if(key<a[mid])
			low=mid+1;
			else if(key==a[mid])
			return(mid);
			else
			high=mid-1;
		}
	}
}
main()
{
	int i,b,c;
	int a[1000]={0};
	system("color 80");
	while(1){
		printf("\n0���˳�\n1���������������\n2����ʾ����\n3��ɾ��ָ���±��Ԫ��\n4��ɾ��ָ��ֵ��Ԫ��\n5����ͨ����\n6�������������ֵ����Сֵ\n7���������ƽ��ֵ\n8������������Ҳ�����Ԫ��\n9�����������С\n10��ѡ������\n11����������\n12��ð������\n13����������\n14���ж������Ƿ�����\n15�����ֲ���\n");
		scanf("%d",&b);
		switch(b){
			case 0:return 0;
			case 1:{
				int max=0,min=1,rnd;
				printf("���������鳤��,���1000		");
				scanf("%d",&c);
				c=c%1001;
				while(max<min){
				printf("���������ֵ");
				scanf("%d",&max);
				printf("��������Сֵ");
				scanf("%d",&min);
				if(max<min)
				printf("���ֵ����С����Сֵ��");
				}
				srand((unsigned)time(NULL));
				for(i=0;i<=c-1;)
				{
					rnd=rand();
					if(rnd>=min&&rnd<=max)
					{a[i]=rnd;i++;
					}
				};
				break;
			}
			case 2:{
				printarray(a,c);
				break;
			}
			case 3:{
				int d;
				printf("ɾ���ڼ���Ԫ��?");
				scanf("%d",&d);
				c--;
				for(i=d-1;i<=c;i++)
				a[i]=a[i+1]; 
				break;
			}
			case 4:{
				int e;
				printf("ɾ��ֵΪ���ٵ�Ԫ�أ�");
				scanf("%d",&e);
				for(i=0;i<=c-1;i++)
				{
					if(a[i]==e)
					{c--;
					for(i;i<=c-1;i++)
					a[i]=a[i+1];
					}
				}
				break;
			}
			case 5:{
				int f;
				printf("����ֵΪ���ٵ�Ԫ�أ�");
				scanf("%d",&f);
				for(i=0;i<=c-1;i++)
				{
					if(a[i]==f)
					printf("ֵΪ%d��Ԫ�ص��±�Ϊ%d.",f,i);
				}
				break;
				}
				case 6:{
					int g=100,h=0;
					for(i=0;i<=c-1;i++)
					{
						if(a[i]<=g) g=a[i];
						if(a[i]>=h) h=a[i];
					}
					printf("���ֵΪ%d,��СֵΪ%d",h,g);
					break;
				}
				case 7:{
					int tot=0;
					float avr;
					for(i=0;i<=c-1;i++)
					{
						tot+=a[i];
					}
					avr=(float)tot/c;
					printf("�����ƽ��ֵΪ%.1f",avr);
					break;
				}
				case 8:{
					int adr,val;
					printf("������Ҫ�����λ�ú���ֵ");
					scanf("%d",&adr);
					scanf("%d",&val);
					c++;
					for(i=c-1;i>=adr;i--)
					a[i]=a[i-1];
					a[adr-1]=val;
					break;
				}
				case 9:{
					int size;
					printf("�����������С,���1000		");
					scanf("%d",&size);
					size=size%1000;
					if(size>=c){
					for(i=c;i<=size;i++)
					a[i]=rand()%100;
					c=size;}
					else{
						for(i=c;i>=size;i--)
					a[i]=rand()%100;
					c=size;
					}
					break;
				}
				case 10:{
					selectsort(a,c);
					break;
				}
				case 11:{
					exchangesort(a,c);
					break;
				}
				case 12:{
					bubblesort(a,c);
					break;
				}
				case 13:{
					bubblereverse(a,c);
					break;
				}
				case 14:{
					judgesort(a,c);
					break;
				}
				case 15:{
					int key;
					printf("������Ҫ���ҵ���ֵ\n");
					scanf("%d",&key);
					i=binarysearch(a,c,key);
					printf("����±�Ϊ%d",i);
					break;
				}
		}
	}
}
