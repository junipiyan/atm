#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"cstdio"
#include"windows.h"
#include"conio.h"


//��������
void main1();
void InitTraData();
void SignUp(); 
void SignIn();   
void Menu(); 
void SaveMoney(); 
void SaveMoney1();
void WithdrawMoney();  
void WithdrawMoney1(); 
void TransferMoney();   
void TransferMoney1();  
void Inquire();   
void InquireBalance(); 
void InqInformation();  
void InqRecord(); 
void ChangeInformation();  
void ChangeUserName();   
void ChangePhone();   
void ChangePassword(); 
void getPassword(char a[], int b);  
void SysTime();       
void SaveUserData();    
void SaveTransactionData();     
void IniUser_Data();     
void SetPassword();           
void SetPhoneNum();          
void SaveTransaction();      
void WithdrawTransaction();    
void TransferTransaction();      
void HandTransaction();        
void PrintTransaction();   
float HandMoney; 
int QK = 0, CK = 0, ZZ = 0;


struct Account
{
	char name[100];
	char AccountNum[50];
	char PhoneNum[12];
	char password[10];
	float balance;

	struct Account* next;
};

struct Trade
{
	char TAccountNum[50];
	char Time[100];
	char Operation[100];
	float Money;

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account ZX;

Trade* THead = NULL;
Trade* TTail = NULL;
Trade* TCurAccount;
Trade TA;


int FindACC(Account IV1)//��¼ʱ���ҵ�ǰ�˻�
{
	Account* curP = head;
	Trade* TcurP = THead;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindPassword(Account IV1)//��¼ʱ���ҵ�ǰ�˻�����
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0 && strcmp(curP->password, IV1.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC2(Account IV)//�����Ƿ������˻�
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC3(Account TT)//����ת���˻�
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->AccountNum, TT.AccountNum) == 0)
		{
			int a, b = 0;
			printf("\n����\n");
			printf("\nYou can't transfer money to yourself! ! !\n");
			while (b < 3)
			{
				printf("\n\n1.��������Է��˻�����/Re-enter the account number of the other party");
				printf("\n\n2.�������˵�/Back to main menu/Return to the homepage");
				printf("\n\n0.�˳�ϵͳ/Exit system/Exit the system\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					TransferMoney();
					b = 3;
					break;
				case 2:
					system("cls");
					Menu();
					b = 3;
					break;
				case 0:
					b = 3;
					SaveUserData();
					exit(0);
				default:
					b++;
					break;
				}
			}
		}
		else if (strcmp(curP->AccountNum, TT.AccountNum) == 0)
		{
			curAccountO = curP;//��ǰת�˶����˻�
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


int main()
{
	SysTime();
	IniUser_Data();
	InitTraData();
	main1();
	SaveUserData();
	SaveTransactionData();
	return 0;
}

void main1()
{
	printf("\n�����Ӧѡ�����֣����س���ȷ�ϡ�/Enter the option number and press Enter to confirm the option.\n\t\n");
	int a, b = 0;
	while (b != 1)
	{
		printf("\n\t1.�û����¼/Sign in\n");
		printf("\t2.�û���ע��/Sign up\n");
		printf("\t0.�˳�/Exit\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			SignIn();
			break;
		case 2:
			SignUp();
			break;
		case 0:
			exit(0);
		default:
			b = 1;
			system("cls");
			printf("\n������������������!");
			printf("Error,please follow the prompts to enter again!\n");
			break;
		}
	}
}

void SignIn()//��¼
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ/Exit system
	{
		Account IV1;//�˻��м����1
		printf("\n\t�������˺�/please enter account��\n");
		scanf("%s", IV1.AccountNum);
		system("cls");
		if (FindACC(IV1))
		{
			while (n < 3)//3����������뽫�˳�ϵͳ/Exit system
			{
				printf("\n\t����������/Please enter password/Please enter password��\n");
				char storePassword[10] = { '\0' };    //�洢�û����������
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");
				if (FindPassword(IV1))
				{
					m = 3;
					n = 3;
					Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\t���˺��ѱ�����/The account has been frozen\n");
						strcpy(curAccount->password, "abc");;
						break;
					}
					else
					{
						printf("\n\t�������/Wrong password\n");
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\tû�в��ҵ����û�!����������/The user was not found! Please re-enter��\n");
			if (m == 3)
			{
				printf("\n\t�������˳�ϵͳ/Exit system\n");
				SaveUserData();
				exit(0);
			}
		}
	}
}

void Menu()//���˵�
{
	int a, b = 1;
	while (b)
	{
		b = 0;
		printf("\n1.���/Deposit\n");
		printf("\n2.ȡ��/Withdrawal\n");
		printf("\n3.ת��/Transfer\n");
		printf("\n4.��ѯ/Query\n");
		printf("\n5.�޸�����/Modify data\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			SaveMoney();
			break;
		case 2:
			system("cls");
			WithdrawMoney();
			break;
		case 3:
			system("cls");
			TransferMoney();
			break;
		case 4:
			system("cls");
			Inquire();
			break;
		case 5:
			system("cls");
			ChangeInformation();
			break;
		case 0:
			system("cls");
			SaveUserData();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n�������/Input error!\n");
			b = 1;
			break;
		}
	}
}

void SaveTransaction()//����¼
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "���/Deposit");
		TP->Money = TA.Money;

		SaveTransactionData();
	}
}

void WithdrawTransaction()//ȡ���¼
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "ȡ��/Withdraw");
		TP->Money = TA.Money;
		SaveTransactionData();
	}
}

void TransferTransaction()//ת�˼�¼
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "ת��/Transfer");
		TP->Money = TA.Money;
		SaveTransactionData();
	}
	Trade* TPi = (Trade*)malloc(sizeof(Trade));
	TPi->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TPi;
		TTail = TPi;
	}
	else
	{
		TTail->Tnext = TPi;
		TTail = TPi;
		strcpy(TPi->TAccountNum, curAccountO->AccountNum);
		strcpy(TPi->Time, TA.Time);
		strcpy(TPi->Operation, "�յ�ת��/Transfer");
		TPi->Money = -TA.Money;
		SaveTransactionData();
	}
}

void HandTransaction()//�����Ѽ�¼
{
	Trade* HP = (Trade*)malloc(sizeof(Trade));
	HP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = HP;
		TTail = HP;
	}
	else
	{
		TTail->Tnext = HP;
		TTail = HP;
		strcpy(HP->TAccountNum, curAccount->AccountNum);
		strcpy(HP->Time, TA.Time);
		strcpy(HP->Operation, "������/Handling fee");
		HP->Money = -HandMoney;
		SaveTransactionData();
	}
}

void PrintTransaction()//��ӡ��ˮ
{
	int a = 0;
	Trade* HcurP = THead;
	while (HcurP != NULL)//���׼�¼
	{
		if (strcmp(curAccount->AccountNum, HcurP->TAccountNum) == 0)
		{
			a++;
			TCurAccount = HcurP;
			printf("\n<���/Num:%d>\tʱ��/Time��%s\t��������/Type��%s\t���/Quantity��%.2f\n", a, TCurAccount->Time, TCurAccount->Operation, TCurAccount->Money);
		}
		HcurP = HcurP->Tnext;
	}
	if (a == 0)
	{
		printf("\n\t��=��=��=��=��=¼\n\n");
		printf("\n\tNo transaction record now.\n\n");
	}
}

void SaveMoney()//���
{
	int a;
	QK = 0;
	printf("\t��ܰ��ʾ�����ʴ��ó���10,000��\n");
	printf("\tHint��A single save cannot exceed 10,000.\n");
	printf("\n\n\t��������Ҫ����Ľ��/Enter amount��\n");
	printf("\n\t");
	scanf("%d", &a);
	if (a > 20000)
	{
		system("cls");
		printf("\n\t���ʴ��ó���10,000��\n\tA single save cannot exceed 10,000.\n");
		SaveMoney1();
	}
	else
	{
		SysTime();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		SaveUserData();
		SaveTransaction();
		printf("\n\t�������ѳɹ�����%.2f!!!!\n", TA.Money);
		printf("\n\tYou have successfully deposited %.2f this time!!!!\n", TA.Money);
		CK = 1;
		SaveMoney1();
	}
}

void SaveMoney1()//���ѡ��
{
	int k = 0, b;
	while (k < 3)
	{
		if (CK)
			printf("\n1.�������/Continue to deposit\n");
		else
			printf("\n1.����������/Re-enter amount\n");
		printf("\n2.�������˵�/Back to main menu\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			SaveMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void WithdrawMoney()//ȡ��
{
	int a;
	CK = 0;
	printf("\t��ܰ��ʾ������ȡ��ó���10,000��\n");
	printf("\tHint��A single withdraw cannot exceed 10,000.\n");
	printf("\n\n��������Ҫȡ���Ľ��/Enter amount��");
	scanf("%d", &a);
	if (a > 20000)
	{
		system("cls");
		printf("\n\t����ȡ��ó���10,000��\n");
		printf("\n\tA single withdrawal cannot exceed 10,000.\n");
		WithdrawMoney1();
	}
	else
	{
		SysTime();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n\t����!!!!\n\tInsufficient balance!!!\n");
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			SaveUserData();
			WithdrawTransaction();
			printf("\n\tȡ��ɹ�!!!!\n\tWithdrawal succeeded!!!\n");
			QK = 1;
		}
		WithdrawMoney1();
	}
}

void WithdrawMoney1()//ȡ��ѡ��
{
	int k = 0, b;
	while (k < 3)
	{
		if (QK)
			printf("\n\n1.�ٴ�ȡ��/Withdraw again");
		else
			printf("\n\n1.����������/Re-enter amount");
		printf("\n\n2.�������˵�/Back to main menu");
		printf("\n\n0.�˳�ϵͳ/Exit system");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			WithdrawMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void TransferMoney()//ת��
{
	int a;
	ZZ = 0;
	printf("\t��ܰ��ʾ��1.����ȡ��ó���10,000��\n");
	printf("\t        2.ת�˽���ȡ2%%�������ѡ�\n\t\n");
	printf("\tHint��1.A single withdraw cannot exceed 10,000.\n");
	printf("\t      2.Transfers will be subject to a 2% handling fee.\n\t\n");
	printf("\n\n��������Ҫת�������˻�/Account��__");
	Account TT;
	scanf("%s", &TT.AccountNum);
	if (FindACC3(TT))
	{
		system("cls");
		printf("\n��������Ҫת���Ľ��/Money��");
		scanf("%d", &a);
		if (a > 10000)
		{
			printf("\n\t����ת�˲��ó���10,000��\n\tTransfers will be subject to a 2% handling fee.\n");
			TransferMoney1();
		}
		else
		{
			SysTime();
			TA.Money = a * -1.00;
			HandMoney = 0.02 * a;
			if (curAccount->balance + TA.Money - HandMoney < 0)
			{
				system("cls");
				printf("\n\t����!!!!\n\tInsufficient balance!!!\n");
			}
			else
			{
				system("cls");
				curAccount->balance = curAccount->balance + TA.Money - HandMoney;
				curAccountO->balance = curAccountO->balance - TA.Money;
				TransferTransaction();
				HandTransaction();
				SaveUserData();
				printf("\n\tת�˳ɹ�!!!!\n\tSucceeded!!!\n");
				ZZ = 1;
			}
			TransferMoney1();
		}
	}
	else
	{
		system("cls");
		printf("\n\t�Է��˻������ڣ�������\n\tThe account of the other party does not exist! ! ! !");
		TransferMoney1();
	}

}

void TransferMoney1()//ת��ѡ��
{
	int k = 0, b;
	while (k < 3)
	{
		if (ZZ)
			printf("\n\n1.�ٴ�ת��/Transfer again");
		else
			printf("\n\n1.����ת��/Retransfer");
		printf("\n\n2.�������˵�/Back to main menu");
		printf("\n\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			TransferMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void Inquire()//��ѯҳ
{

	int a, b = 0;
	while (b < 3)
	{
		printf("\n1.��ѯ���/Check balances\n");
		printf("\n2.��ѯ���׼�¼/Query transaction records\n");
		printf("\n3.��ѯ������Ϣ/Inquire about personal information\n");
		printf("\n4.�������˵�/Back to main menu\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			InquireBalance();
			b = 3;
			break;
		case 2:
			system("cls");
			InqInformation();
			b = 3;
			break;
		case 3:
			system("cls");
			InqRecord();
			b = 3;
			break;
		case 4:
			system("cls");
			Menu();
			b = 3;
			break;
		case 0:
			system("cls");
			b = 3;
			SaveUserData();
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InquireBalance()//��ѯ�˻�
{
	SysTime();
	printf("\n\t�������Ϊ/Your balance is��\n%.2f\n", curAccount->balance);
	int a, b = 0;
	while (b < 3)
	{
		printf("\n1.������һҳ/Go back to the last page\n");
		printf("\n2.�������˵�/Back to main menu\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			b = 3;
			break;
		case 2:
			system("cls");
			Menu();
			b = 3;
			break;
		case 0:
			b = 3;
			SaveUserData();
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InqInformation()//��ѯ������Ϣ
{
	printf("\n\t����/Name��\n%s\n", curAccount->name);
	printf("\n\t�˺�/Account number��\n%s\n", curAccount->AccountNum);
	printf("\n\tԤ���ֻ���/phone number��\n%s\n", curAccount->PhoneNum);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1.������һҳ/Go back to the last page\n");
		printf("\n\t2.�������˵�/Back to main menu\n");
		printf("\n\t0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void InqRecord()//��ѯ���׼�¼
{
	PrintTransaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n1.������һҳ/Go back to the last page\n");
		printf("\n2.�������˵�/Back to main menu\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void ChangeInformation()//�޸���Ϣ�˵�
{
	system("cls");
	int a, b = 1;
	while (b)
	{
		printf("\n1.�޸��û�/Modify user\n");
		printf("\n2.�޸ĵ绰/Modify the phone\n");
		printf("\n3.�޸�����/Change password\n");
		printf("\n4.������һҳ/Go back to the last page\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ChangeUserName();
			b = 0;
			break;
		case 2:
			ChangePhone();
			b = 0;
			break;
		case 3:
			ChangePassword();
			b = 0;
			break;
		case 4:
			Menu();
			b = 0;
			break;
		case 0:
			SaveUserData();
			exit(0);
		default:
			system("cls");
			printf("�������\t�밴����ʾ��������/Input error! \tPlease re-enter as prompted��\n");
			break;
		}
	}
}

void ChangeUserName()//�޸��û�
{
	int a, b = 0, c = 0;
	while (b < 3)
	{
		system("cls");
		printf("\n\t���������û�����:");
		scanf("%s", curAccount->name);
		system("cls");
		printf("\n\t�û������޸ĳɹ���\n");
		SaveUserData();
		b = 3;
		while (c < 3)
		{
			printf("\n1.������һҳ/Go back to the last page\n");
			printf("\n2.�������˵�/Back to main menu\n");
			printf("\n0.�˳�ϵͳ/Exit system\n");
			
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();
				b = 3;
				break;
			case 2:
				system("cls");
				Menu();
				b = 3;
				break;
			case 0:
				b = 3;
				SaveUserData();
				exit(0);
			default:
				b++;
				break;
			}
		}
	}
}

void ChangePhone()//�޸ĵ绰
{
	system("cls");
	int a, b = 0, c = 0;
	while (b < 3)
	{
		printf("\n\t����������ϵ�绰����/Please enter a new contact phone number:");
		scanf("%s", curAccount->PhoneNum);
		system("cls");
		printf("\n\t��ϵ�绰�޸ĳɹ���/Successfully modified!\n");
		SaveUserData();
		b = 3;
		while (c < 3)
		{
			printf("\n1.������һҳ/Go back to the last page\n");
			printf("\n2.�������˵�/Back to main menu\n");
			printf("\n0.�˳�ϵͳ/Exit system\n");
			
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();
				c = 3;
				break;
			case 2:
				system("cls");
				Menu();
				c = 3;
				break;
			case 0:
				c = 3;
				SaveUserData();
				exit(0);
			default:
				c++;
				break;
			}
		}
	}
}

void ChangePassword()//�޸�����
{
	system("cls");
	int a, b = 0, c = 0;
	char Password[100];
	while (b < 3)
	{
		printf("\n\n\t������ԭʼ����/Please enter password��");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n������������/Please enter new password:");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n�û������޸ĳɹ���/Successfully modified!\n");
			SaveUserData();
			b = 3;
			while (c < 3)
			{
				printf("\n1.������һҳ/Go back to the last page\n");
				printf("\n2.�������˵�/Back to main menu\n");
				printf("\n0.�˳�ϵͳ/Exit system\n");		
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					ChangeInformation();
					c = 3;
					break;
				case 2:
					system("cls");
					Menu();
					c = 3;
					break;
				case 0:
					c = 3;
					SaveUserData();
					exit(0);
				default:
					c++;
					break;
				}
			}
		}
		else
		{
			b++;
			system("cls");
			printf("\n\t�����������!/wrong password!\n");
		}
	}
}

void getPassword(char* storePw, int maxPwLen)//��������
{
	char c = '\0';
	char* pc = storePw;
	int pwlen = 0;

	while (1)
	{
		c = getch();
		if (c == '\r')
			break;
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

void SysTime()//ϵͳʱ��
{
	time_t t = time(0);
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strcpy(TA.Time, tmp);
}

void SaveUserData()
{
	FILE* fp = fopen("D:/�û���Ϣ.txt", "w");//�����û�����
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%f\n", curP->AccountNum, curP->name, curP->PhoneNum, curP->password, curP->balance);
			curP = curP->next;
		}
		fclose(fp);
	}
}

void SaveTransactionData()
{
	FILE* Tfp = fopen("D:/������Ϣ.txt", "at+");//���潻������
	if (Tfp != NULL)
	{
		Trade* TcurP = THead;
		while (TcurP != NULL)
		{
			if (TcurP->Tnext == NULL)
			{
				fprintf(Tfp, "%s\t%s\t%s\t%f\n", TcurP->TAccountNum, TcurP->Time, TcurP->Operation, TcurP->Money);
			}
			TcurP = TcurP->Tnext;
		}
		fclose(Tfp);
	}
}

void IniUser_Data()//��ʼ���û�
{
	FILE* fp = fopen("D:/�û���Ϣ.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\t%f\n", newNodeP->AccountNum, newNodeP->name, newNodeP->PhoneNum, newNodeP->password, &newNodeP->balance);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

void InitTraData()//��ʼ��������Ϣ
{
	FILE* Tfp = fopen("D:/������Ϣ.txt", "r");
	if (Tfp != NULL)
	{
		while (!feof(Tfp))
		{
			Trade* TnewNodeP = (Trade*)malloc(sizeof(Trade));
			fscanf(Tfp, "%s\t%s\t%s\t%f\n", TnewNodeP->TAccountNum, TnewNodeP->Time, TnewNodeP->Operation, &TnewNodeP->Money);
			TnewNodeP->Tnext = NULL;

			if (THead == NULL)
			{
				THead = TnewNodeP;
				TTail = TnewNodeP;
			}
			else
			{
				TTail->Tnext = TnewNodeP;
				TTail = TnewNodeP;
			}
		}
		fclose(Tfp);
	}
}

void SignUp()//ע�ắ��
{
	int a, k = 0;
	system("cls");
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//�Ѷ���
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//������ǵ�һ�������Ľ�㣬��ͷ βָ��ָ��������
	}
	else
		tail->next = Pset; //������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
	printf("\n�������������/Please enter your name��\n");
	scanf("%s", ZX.name);
	strcpy(Pset->name, ZX.name);
	int ACCountNum = 10000;
	itoa(ACCountNum, ZX.AccountNum, 10);
	while (FindACC2(ZX))
	{
		ACCountNum++;
		itoa(ACCountNum, ZX.AccountNum, 10);
		break;
	}
	strcpy(Pset->AccountNum, ZX.AccountNum);
	SetPhoneNum();
	SetPassword();
	Pset->balance = 0;
	SaveUserData();
	while (k < 3)
	{
		system("cls");
		printf("\nע��ɹ�/Success!\n");
		printf("\n%s\n", Pset->AccountNum);
		printf("\n1.���ص�¼/Back to login\n");
		printf("\n0.�˳�ϵͳ/Exit system\n");
		scanf("%d", &a);
		if (a == 1)
		{
			system("cls");
			SignIn();
			break;
		}
		else if (a == 0)
		{
			exit(0);
		}
		else
		{
			k++;
			printf("\n�����������!/Incorrect password! \n");
		}
	}
}

void SetPassword()//��������
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("\n����������˻�����/Please set your account password��\n");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(ZX.password, storePassword);
		if (strlen(ZX.password) == 6)
		{
			strcpy(Pset->password, ZX.password);
			break;
		}
		else
		{
			printf("\n����Ϊ��λ�����������������/The password is six digits, your password is set incorrectly��\n����������/Please reset it��\n");
		}
	}
}

void SetPhoneNum()//�����ֻ���
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("��������ĵ绰����/Please enter your phone number��\n");
		scanf("%s", ZX.PhoneNum);
		if (strlen(ZX.PhoneNum) == 11)
		{
			strcpy(Pset->PhoneNum, ZX.PhoneNum);
			break;
		}
		else
		{
			system("cls");
			printf("\n���Ԥ��������������/Your reserved number is set incorrectly!\n����������/Please reset it��\n");
		}
	}
}