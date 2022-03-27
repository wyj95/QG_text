#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "..\head\LQueue.h" 

extern char type;
extern char datatype[MAX_QUEUE];
				
/**
 *  @name          : void InitLQueue(LQueue *Q)
 *  @description   : ��ʼ������
 *  @param         :  Q ����ָ��Q
 *  @notice        : None
 */
void InitLQueue(LQueue *Q){
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name          : void DestoryLQueue(LQueue *Q)
 *  @description   : ���ٶ���
 *  @param         : Q ����ָ��Q
 *  @notice        : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : �鿴��ͷԪ��
 *  @param       : Q e ����ָ��Q,��������ָ��e
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void **e){
	if(Q->length == 0)
		return FALSE;
	*e = Q->front->data;
	return TRUE;
}

/**
 *  @name          : Status LengthLQueue(LQueue *Q, int *length)
 *  @description   : ȷ�����г���
 *  @param         : Q ����ָ��Q,lenth ���г��� 
 *  @return        : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice        : None
 */
Status LengthLQueue(LQueue *Q,int *length){
	Node *p1;
	int truelength=0; /* �����Ķ��г��� */ 
	p1 = Q->front;
	while(p1 != NULL)
	{
		p1 = p1->next;
		truelength++;
	}
	if( (*length=truelength) == Q->length )
		return TRUE;
	else
		return FALSE;
		
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      :�ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *p1=(Node*)malloc(sizeof(Node));
	if(p1 == NULL)
		return FALSE;
	p1->data = data;
	p1->next = NULL;
	if(Q->length == 0)
	{
		Q->rear = p1;
		Q->front = p1;
	}
	/*����Ϊ�գ���ͷ�Ͷ�β��Ϊ�½�㣬����ֱ�ӽ��½������ȥ���ö�βΪ�½�� */ 
	else
	{
		Q->rear->next = p1;
		Q->rear = p1;
	}
	datatype[Q->length] = type;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q, void **e)
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void **e){
	if(Q->front == NULL)
		return FALSE;
	*e = Q->front->data;
	Node *p1;
	p1 = Q->front->next;
	free(Q->front);
	/* �����������eָ�����free�� */ 
	Q->front = p1;
	Q->length--;
	type = datatype[0];
	/* ��¼�ñ�ɾ���Ľ������ */ 
	int i;
	for(i=0; i<Q->length; i++)
		datatype[i] = datatype[i+1];
	/* ������������ǰ�� */ 
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : ��ն���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node *p1=Q->front;
	while(p1 != NULL)
	{
		p1 = p1->next;
		free(Q->front->data);
		free(Q->front);
		Q->front = p1;
	}
	/* �������У�����free����������ָ�� */ 
	Q->rear = NULL;
	Q->length = 0;
	/* ǰ��������ϲ����б��NULL�� */ 
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : ������������
 *  @param       : Q ����ָ��Q����������ָ��foo
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q->length == 0)
		return FALSE;
	Node *p1;
	p1 = Q->front;
	int i=0;
	while(p1 != NULL)
	{
		type = datatype[i++];
		printf("%d.", i);
		(*foo)(p1->data);
		p1 = p1->next;
	}
	/* ������type����Ϊ��ǰ����������ͣ�����ú������� */ 
}

/**
 *  @name        : void LPrint(void *q)
 *  @description : ��������
 *  @param       : q ָ��q
 *  @notice      : None
 */
void LPrint(void *q){
	if(type == 'i')
	{
		printf("%d\n", *( (int *)q ));
	}
	else if(type == 'c')
	{
		printf("%c\n", *( (char*)q ));
	}
	else if(type == 'f')
	{
		printf("%.2f\n", *( (float*)q ));
	}
	else if(type == 's')
	{
		printf("%s\n",  (char*)q );
	}
	/* ���ݲ�ͬ���ͽ���ɾ�������ⲿ���øú���ǰ�ѽ�type��Ϊq��Ӧ���� */ 
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
