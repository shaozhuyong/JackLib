#include "stdafx.h"
/*
 * 朴素模式匹配算法
*/
int match(char* s,char* t)
{
	int j=0;
	int i=0;	
	while(t[i]!='\0'&&s[j]!='\0')
	{
		if(s[j]==t[i])
		{
			i++;j++;
		}
		else { 
			j=j-i;
			i=0;
		}
	}
	if(t[i]=='\0')
	{ return j-i;}
	else
	{ return -1;}
}

/*
 * KMP求解next数组的方法
 */
int* getNext(char * t)
{
	//模式字符串长度
	int len =strlen(t);
	int *next=new int[len];

	/*将数组元素预置为0*/
	int i=0;
	while(t[i]!='\0')
	{
	   next[i]=0;
	   i++;
	}
	/*将数组元素预置为0*/

	int j=0;int k=-1;
	next[0]=-1;
	
	while(t[j+1]!='\0')
	{
		if(k==-1||t[j]==t[k])
		{
			k++;j++;
			next[j]=k;
		}		
		else
		{
			j++;
			k= next[k+1];
		}
	}	
	return next;
}
/*
 * KMP模式匹配算法
*/
int kmpMatch(char* s,char* t)
{
	int j=0;
	int i=0;
	int *next=getNext(t);
	while(t[i]!='\0'&&s[j]!='\0')
	{
		if(s[j]==t[i])
		{
			i++;j++;
		}
		else { 
			j=j-next[i];//j-i+i-next[i]
			i=0;
		}
	}

	if(t[i]=='\0')
	{ return j-i;}
	else
	{ return -1;}

}

/**
 * main函数入口
 */
/*
int main(int argc, char* argv[]) {
	
	char ss[15]="abcdefgABCDABD";
	char t[13]="fgAB";
	int index=kmpMatch(ss,t);
	printf("%d",index);
    system("pause");
    return 0;
}*/