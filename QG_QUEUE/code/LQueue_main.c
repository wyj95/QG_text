#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"..\head\LQueue.h"

char type;
char datatype[MAX_QUEUE];
/*
 * ������ʹ��datatype����ģ����д洢���Ͷ�����������
 * ����������ʹ��ʽ�����ŵ㲻����
 * ����Ҫ�ǿ���ѡ��Ļ����������ͷ��ڶ��н����Ч��Ӧ�û����
 * �������û����datatype�򿪷�ʽ�Ļ�...��
 */ 

int main()
{
	Show();
	return 0;
}

/**
 *  @name        : void GetType()
 *  @description : ��ȡ���� 
 *  @param       : None
 *  @notice      : None
 */
void GetType()
{
	while(1)
	{
		type = '\0';
		printf("Please give me what kind of the data you want to keep:\n");
		printf("'i' means int, 'f' means float, 'c' means char while 's' means char string!\n");
		scanf("%c", &type);
		while(getchar() != '\n');
		if(type=='i' || type=='f' || type=='c' || type=='s')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}

/**
 *  @name        : void GetData(void **data)
 *  @description : ����type���Ͳ�ͬ��ȡ��ͬ���� 
 *  @param       : data ����ȡ����ָ����δ���䣬�ڶ�ӦGetInt�Ⱥ����з��� 
 *  @notice      : ����ȷ��type 
 */
void GetData(void **data)
{
	if(type == 'i')
	{
		GetInt(data);
	}
	else if(type == 'f')
	{
		GetFloat(data);
	}
	else if(type == 'c')
	{
		GetChar(data);
	}
	else if(type == 's')
	{
		GetCharS(data);
	}
}

/**
 *  @name        : void getInt(void ** data)
 *  @description : ��ȡint���� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data���ж��Ƿ�������int 
 */
void GetInt(void **data)
{
	printf("Please give me a int number:\n");
	int *p = (int*)malloc(sizeof(int));
	/* ��Ϊʵ�ʵ�ַ */ 
	char s[10];  /* �洢��ת��Ŀ���ַ��� */ 
	int i;       /* ����ѭ�� */ 
	int flag;    /* �����ж������쳣�ַ�����  flag==1 ����   flag==0 �������ַ�����*/ 
	while(1)
	{
		for(i=0; i<10 && (s[i]=getchar()) != '\n'; i++);
		if(i == 10)
		{
			*s = 'X';/* ֱ�������ж� */ 
			while(getchar() != '\n');
		}
		else
			s[i] = '\0';
		flag = 1;
		if(*s == '-')
		{
			/* ����ʵ������Ӧ��С��10000������ϵͳint���ݴ�С��һ��һ�� */ 
			if(strlen(s) < 6)
			{
				for(i=1; i<6 && s[i]!='\0'; i++)
					if(s[i]<'0' || s[i]>'9')
					{
						flag = 0;
						break;
					}/* �����쳣�ַ� */ 
				if(flag == 1)
				{
					*p = 0;
					for(i=1; i<6 && s[i]!='\0'; i++)
						*p = (*p)*10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if(strlen(s) < 5)
		{
			int i;
			for(i=0; i<5 && s[i]!='\0'; i++)
				if(s[i]<'0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				*p = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}	
}

/**
 *  @name        : void getFloat(void ** data)
 *  @description : ��ȡfloat���� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data���ж��Ƿ�������float
 */
void GetFloat(void **data)
{
	printf("Please give me a float number:\n");
	int length[2]; /* ����ͳ����������length[0]��С�����ֳ���length[1] */ 
	int flag;      /* �����ж��ַ����Ƿ�����������ֵֹ����⣨�ǣ�flag==0�� */ 
	int status;    /* �����жϴ�ʱ��������������С����ǰ����С����� */ 
	char s[20];    /* ��ת����float��Ŀ���ַ��� */ 
	float count;   /* ����Э������С������ */ 
	float *p;      /* �洢float������ */ 
	p = (float*)malloc(sizeof(float));
	while(1)
	{
		int i;
		for(i=0; i<20 && (s[i]=getchar()) != '\n'; i++);
		if(i == 20)
		{
			while(getchar() != '\n');
			system("cls");
			printf("Please don't give me something else,\n");
			printf("And the part bigger than 1 of the number you give shouldn't be longer than 4,");
			printf("as well as the part smaller than 1!\n");
			continue;
		}
		else
			s[i] = '\0';
		/* ���ϣ���ֹ����Խ�� */ 
		flag = 1;
		status = 0;
		length[0] = 0;
		length[1] = 0;
		i=0;
		if(*s == '-')
		{
			i++;
			while(s[i]!='\0')
			{
				if(s[i]>='0' && s[i]<='9')
					length[status] ++;
				else if(s[i]=='.' && status==0)
				{
					status = 1;
				}
				else
				{
					flag = 0;
					break;
				}
				i++;
			}
			if(length[0]>4 || length[1]>4)
				flag = 0;
			if(flag == 1)
			{
				count = 0.1;
				*p = 0.0;
				for(i=0; s[i]!='.' && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				if(s[i] == '.')
					i++;
				for(; s[i]!='\0'; count /= 10)
					*p += count * (s[i++]-'0');
				*p *= -1;
				*data = (void*)p;
				return;
			}
		}
		else
		{
			while(s[i]!='\0')
			{
				if(s[i]>='0' && s[i]<='9')
					length[status] ++;
				else if(s[i]=='.' && status==0)
				{
					status = 1;
				}
				else
				{
					flag = 0;
					break;
				}
				i++;
			}
			if(length[0]>4 || length[1]>4)
				flag = 0;
			if(flag == 1)
			{
				count = 0.1;
				*p = 0.0;
				for(i=0; s[i]!='.' && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				if(s[i] == '.')
					i++;
				for(; s[i]!='\0'; count /= 10)
					*p += count * (s[i++]-'0');
				*data = (void*)p;
				return;
			}
		}
		system("cls");
		printf("Please don't give me something else,\n");
		printf("And the part bigger than 1 of the number you give shouldn't be longer than 4,");
		printf("as well as the part smaller than 1!\n");
	}
}

/**
 *  @name        : void getCharS(void ** data)
 *  @description : ��ȡ�ַ������� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data
 */
void GetCharS(void **data)
{
	printf("Please give me a char string whose length is shorter than 50:\n"); 
	char *p=(char*)malloc(sizeof(char)*50);
	int i;
	for(i=0; i<50 && (p[i]=getchar()) != '\n'; i++);
	if(i==50)
	{
		p[49] = '\0';
		while(getchar() != '\n');
	}
	else
		p[i] = '\0';
	/* ��ֹ����Խ�� */ 
	*data = (void*)p;
}

/**
 *  @name        : void getChar(void ** data)
 *  @description : ��ȡChar���� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data
 */
void GetChar(void **data)
{
	printf("Please give me one char.\nIf you give me more,I will get the first:\n");
	char *p = (char*)malloc(sizeof(char));
	/* һ���̶��Ϸ�ֹ������������� */
	*p = getchar();
	if(*p == '\n')
		*p = '0';/* ��ֹ����ֵֹĻ��У��۸в��� */ 
	while(getchar() != '\n');
	*data = (void*)(p);
}

/**
 *  @name        : void show()
 *  @description : ��ʼ������ʾ��������û�ѡ���Ӧ���� 
 *  @param       : None
 *  @notice      : None
 */
void Show()
{
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));    /* ���� */ 
	void *data;                                   /* �����ռ����� */ 
	void *addData;                                /* ������ӽ��ʱ�����ַ��ز��� */ 
	int flag;                                     /* �ж��û����� */ 
	int length;                                   /* ���鳤�� */ 
	InitLQueue(Q);/* ��ʼ������ */ 
	while(1)
	{
		while(1)
		{
			flag = 0;
			printf("You can do these function:\n");
			printf("1.Check whether the queue is empty or not;\n");
			printf("2.Get the data of the queue head;\n");
			printf("3.Add a node into the queue;\n");
			printf("4.Get a node out of the queue;\n");
			printf("5.Read all the node of the queue;\n");
			printf("6.Get the length of the queue;\n");
			printf("7.Delete the queue;\n");
			printf("8.Quit.\n");
			printf("Now please give me the number to finish the function:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag<1 || flag>8)
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
		switch(flag)
		{
			case(1):
				if(IsEmptyLQueue(Q) == TRUE)
					printf("The queue is empty now!You should add something!\n");
				else
					printf("The queue is not empty now.\n");
				break;
			case(2):
				if(GetHeadLQueue(Q, &data) == TRUE)
				{
					type = datatype[0];
					/* ��ȡ��ͷ�������� */ 
					LPrint(data);
				}
				else
					printf("The queue is empty now!You should add something!\n");
				break;
			case(3):
				if(Q->length > MAX_QUEUE-1)
				{
					printf("Sorry,but the stack is full!\n");
					break;
				}
				/* ��ֹdatatype����Խ�� */ 
				GetType();
				GetData(&addData);
				/* �Ȼ�ȡ�������� ����GetData���õĶ�ӦgetInt�Ⱥ���������ַ */ 
				if(EnLQueue(Q, addData) == TRUE)
					printf("We have add it into the queue!\n");
				else
				{
					printf("The room is full!!!\n");
					exit(-1);
				}
				break;
			case(4):
				if(DeLQueue(Q, &data) == TRUE)
				{
					printf("We have get the node out of the queue.\n");
					printf("And it is :");
					/* ���� DeLQueue�����л�ȡɾ������type */
					LPrint(data);
					free(data);
					/* �����ͽ���ɾ�� */ 
				}
				else
					printf("The queue is empty now!\n");
				break;
			case(5):
				printf("They are:\n");
				TraverseLQueue(Q, LPrint);
				break;
			case(6):
				if(LengthLQueue(Q, &length) == TRUE)
					printf("The length of the queue is %d.\n", length);
				else
				{
					printf("There is some wrong in the queue!!!\n");
					exit(-1);
				}
				break;
			case(7):
				ClearLQueue(Q);
				break;
			case(8):
				DestoryLQueue(Q);
				return;
		}
		printf("Please give me anything to continue:\n");
		while(getchar() != '\n');
		system("cls");
	}
}
