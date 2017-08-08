#include<stdio.h>
#include<string.h>
int search(char* s1,char* s2)
{
	if(strlen(s1)<strlen(s2))
	return 0;
	int i,j,frqc=0;
	int next[11];
	j=0;i=-1;next[0]=-1;
	while(j<=strlen(s2)-1)
		if(i==-1||s2[j]==s2[i])
		{
			j++;i++;
			if(s2[j]!=s2[i])next[j]=i;
			else next[j]=next[i];
		}
		else i=next[i];
	i=j=0;
	while(i<strlen(s1))
	{
		if(j==-1||s1[i]==s2[j]){i++,j++;}
		else j=next[j];
		if(j==strlen(s2)){frqc++;j=0;}
	}
	return frqc;
}
int search_f(FILE*fp,char*key)
{
	int i,frqc=0;
	char s1[300];
	while(!feof(fp))
	{
		i=0;
		s1[0]=fgetc(fp);
		while(s1[i]!='\n'&&!feof(fp)) 
		{i++;s1[i]=fgetc(fp);}
		s1[i]='\0';
		frqc+=search(s1,key);
	}
	return frqc;
}

