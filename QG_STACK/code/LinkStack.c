#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../head/LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	LinkStackPtr p1,p2;
	s->count = 0;
	s->top = NULL;
	printf("Please give me the length of the link stack which is smaller than 10000 and bigger than 0:\n");
	int length;
	getInt(&length);
	s->count = length;
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	s->top->data = length--; 
	p2 = s->top;
	while(length != 0)
	{
		if((p1 = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL)
			return ERROR;
		p1->data = length--;
		p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
	return SUCCESS;
}


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->top == NULL && s->count ==0)
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->count == 0)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(s->count==0 && s->top==NULL)
		return ERROR; 
	LinkStackPtr p1,p2;
	p1 = s->top;
	p2 = s->top;
	while(p1 != NULL)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
	if(s == NULL)
		return ERROR;
	free(s);
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	int trueLength=0;
	LinkStackPtr p1=s->top;
	while(p1 != NULL)
	{
		p1 = p1->next;
		trueLength++;
	}
	if((*length=trueLength) == s->count)
		return SUCCESS;
	else
		return ERROR;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p1=(LinkStackPtr)malloc(sizeof(StackNode));
	if(p1 == NULL)
		return ERROR;
	p1->data = data;
	p1->next = s->top;
	s->top = p1;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(s->count == 0)
		return ERROR;
	*data = s->top->data;
	s->top = s->top->next;
	s->count--;
	return SUCCESS;
}

