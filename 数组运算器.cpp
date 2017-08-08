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
	printf("数组为降序。\n");
	if(k==0)
	printf("数组为升序。\n");
	if(j!=0&&k!=0)
	printf("数组无序！\n");
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
		printf("\n0、退出\n1、产生数组随机数\n2、显示数组\n3、删除指定下标的元素\n4、删除指定值的元素\n5、普通查找\n6、求数组中最大值和最小值\n7、求数组的平均值\n8、在数组里查找并插入元素\n9、设置数组大小\n10、选择排序\n11、交换排序\n12、冒泡排序\n13、逆序数组\n14、判断数组是否有序\n15、二分查找\n");
		scanf("%d",&b);
		switch(b){
			case 0:return 0;
			case 1:{
				int max=0,min=1,rnd;
				printf("请输入数组长度,最大1000		");
				scanf("%d",&c);
				c=c%1001;
				while(max<min){
				printf("请设置最大值");
				scanf("%d",&max);
				printf("请设置最小值");
				scanf("%d",&min);
				if(max<min)
				printf("最大值不能小于最小值！");
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
				printf("删除第几个元素?");
				scanf("%d",&d);
				c--;
				for(i=d-1;i<=c;i++)
				a[i]=a[i+1]; 
				break;
			}
			case 4:{
				int e;
				printf("删除值为多少的元素？");
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
				printf("查找值为多少的元素？");
				scanf("%d",&f);
				for(i=0;i<=c-1;i++)
				{
					if(a[i]==f)
					printf("值为%d的元素的下标为%d.",f,i);
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
					printf("最大值为%d,最小值为%d",h,g);
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
					printf("数组的平均值为%.1f",avr);
					break;
				}
				case 8:{
					int adr,val;
					printf("请输入要插入的位置和数值");
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
					printf("请设置数组大小,最大1000		");
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
					printf("请输入要查找的数值\n");
					scanf("%d",&key);
					i=binarysearch(a,c,key);
					printf("查得下标为%d",i);
					break;
				}
		}
	}
}
