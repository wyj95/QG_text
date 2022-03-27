/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define MAX_QUEUE 50
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//��ʽ���нṹ
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;         //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    int length;            //���г���
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;		

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void GetType()
 *  @description : ��ȡ���� 
 *  @param       : None
 *  @notice      : None
 */
void GetType();

/**
 *  @name        : void GetData(void **data)
 *  @description : ����type���Ͳ�ͬ��ȡ��ͬ���� 
 *  @param       : data ����ȡ����ָ����δ���䣬�ڶ�ӦGetInt�Ⱥ����з��� 
 *  @notice      : ����ȷ��type 
 */
void GetData(void **data); 

/**
 *  @name        : void getInt(void ** data)
 *  @description : ��ȡint���� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data���ж��Ƿ�������int 
 */
void GetInt(void **data);

/**
 *  @name        : void getFloat(void ** data)
 *  @description : ��ȡfloat���� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data���ж��Ƿ�������float
 */
void GetFloat(void **data);

/**
 *  @name        : void getChar(void ** data)
 *  @description : ��ȡChar���� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data
 */
void GetChar(void **data);

/**
 *  @name        : void getCharS(void ** data)
 *  @description : ��ȡ�ַ������� 
 *  @param       : data ���ݴ��洢��ַ 
 *  @notice      : �����ַ��data
 */
void GetCharS(void **data);

/**
 *  @name        : void show()
 *  @description : ��ʼ������ʾ��������û�ѡ���Ӧ���� 
 *  @param       : None
 *  @notice      : None
 */
void Show();

/**
 *  @name          : void InitLQueue(LQueue *Q)
 *  @description   : ��ʼ������
 *  @param         :  Q ����ָ��Q
 *  @notice        : None
 */
void InitLQueue(LQueue *Q);

/**
 *  @name          : void DestoryLQueue(LQueue *Q)
 *  @description   : ���ٶ���
 *  @param         : Q ����ָ��Q
 *  @notice        : None
 */
void DestoryLQueue(LQueue *Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : �鿴��ͷԪ��
 *  @param       : Q e ����ָ��Q,��������ָ��e
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void **e);

/**
 *  @name          : Status LengthLQueue(LQueue *Q, int *length)
 *  @description   : ȷ�����г���
 *  @param         : Q ����ָ��Q,lenth ���г��� 
 *  @return        : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice        : None
 */
Status LengthLQueue(LQueue *Q, int *length);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      :�ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data);

/**
 *  @name        : Status DeLQueue(LQueue *Q, void **e)
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void **e);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : ��ն���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : ������������
 *  @param       : Q ����ָ��Q����������ָ��foo
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *  @description : ��������
 *  @param       : q ָ��q
 *  @notice      : None
 */
void LPrint(void *q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


