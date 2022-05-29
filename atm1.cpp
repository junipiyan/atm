#include<stdio.h>
#include<stdlib.h>

struct Account
{
	char name[100];
	char username[100];
	char password[100];	
	
	struct Account * next; 
};
typedef struct Account Account;

Account a[500]; 

Account *head=NULL;
Account *tail=NULL;

void addNode(Account *node)
{
	node->next=NULL;
	if(head==NULL)
	{
		head=node;
		tail=node;
	}
	else
	{
		tail->next=node;
		tail=node;
	}
}

void loadData()
{
	FILE* fp=fopen("C:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//申请一块内存空间，将其地址赋值给指针newNodeP 
			Account *newNodeP=(Account *)malloc(sizeof(Account));
			fscanf(fp,"%s %s %s\n",newNodeP->name,newNodeP->username,newNodeP->password);
			addNode(newNodeP);
		}
		fclose(fp);
		printf("初始化成功！\n");
	}
}

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\t%s\n",curP->name,curP->username,curP->password);
		curP=curP->next;
	}
}

void saveData()
{
	FILE* fp=fopen("C:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s %s\n",curP->name,curP->username,curP->password);
			curP=curP->next;
		}
		fclose(fp);
	}
}

void signUp()
{
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("请输入名字：\n");
	scanf("%s",newNodeP->name);
	
	printf("请输入账号：\n");
	scanf("%s",newNodeP->username);
	
	printf("请输入密码：\n");
	scanf("%s",newNodeP->password);
	
	addNode(newNodeP);
	
	printf("创建成功！\n");
}

int main()
{
	loadData();
	
	signUp();
	
	
	
	printLinkedList();
	
	saveData();
	return 0;
}

