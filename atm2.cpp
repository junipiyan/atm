#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

struct Account
{
	char username[100];
	char password[100];
	
	struct Account * next;	
};
typedef struct Account Account;

Account * head=NULL;//指向头结点的指针
Account * tail=NULL;//指向尾结点的指针 
Account * curAccount=NULL;//当前登录账户的指针 

int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)
		&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
		curP=curP->next;
	}
	return 0;
}

void updatePassword()
{
	printf("请输入旧密码：\n");
	char oldPassword[100];
	scanf("%s",oldPassword);
	if(strcmp(oldPassword,curAccount->password)==0)
	{
		printf("请输入新密码：\n");
		scanf("%s",curAccount->password);
		printf("修改密码成功！\n");
	}
	else
	{
		printf("密码错误，不能修改！\n");
	}
}

void homePage()
{
	printf("Press...\n");
	printf("按...\n");
	updatePassword();
}

void signIn()
{
	for(int i=0;i<3;i++)
	{
		Account a;
		printf("请输入账号：\n");
		scanf("%s",a.username);
		
		printf("请输入密码：\n");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			printf("登录成功！\n");	
			homePage();
			break;
		}
		else
		{
			printf("登录失败!\n");
		}
	}
}

int loadData()
{
	FILE*fp=fopen("C:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
				//创建结点
				Account *newNode=(Account *)malloc(sizeof(Account));
				
				//结点初始化
				newNode->next=NULL;
				fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
				
				//添加到链表
				if(head==NULL)
				{
					head=newNode;
					tail=newNode;
				} 
				else
				{
					tail->next=newNode;
					tail=newNode;
				}
		}	
		return 1;
	}
}

void printLinkedList()
{
	Account* curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}	
}

int main()
{
	int status=loadData(); 
	if(status==1)
	{
		printf("加载成功！\n");
		printLinkedList();
	}
	else
	{
		printf("加载失败!\n");
	}
	signIn();
	
	
	
	return 0;
}

