#include "stdafx.h"
/*
 * ����ģʽƥ���㷨
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
 * KMP���next����ķ���
 */
int* getNext(char * t)
{
	//ģʽ�ַ�������
	int len =strlen(t);
	int *next=new int[len];

	/*������Ԫ��Ԥ��Ϊ0*/
	int i=0;
	while(t[i]!='\0')
	{
	   next[i]=0;
	   i++;
	}
	/*������Ԫ��Ԥ��Ϊ0*/

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
 * KMPģʽƥ���㷨
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
 * main�������
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