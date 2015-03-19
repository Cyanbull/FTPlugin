#pragma once

/************************************************* 
Copyright: FUTU
Author: Lin
Date: 2015-03-18
Description: ����API�ͻص��ӿڶ���
**************************************************/  

enum Trade_SvrResult
{
	Trade_SvrResult_Succeed = 0, //����������������ɹ�
	Trade_SvrResult_Failed = -1, //����������������ʧ�ܣ�ʧ�ܵ�ԭ����ܺܶ࣬�������糬ʱ����ʱͳһ����ʧ�ܣ�
};

enum Trade_OrderSide
{
	Trade_OrderSide_Buy = 1, //����
	Trade_OrderSide_Sell = 2, //����
};

enum Trade_OrderType_HK
{
	Trade_OrderType_HK_EnhancedLimit = 1, //��ͨ���ף���ǿ�޼ۣ�
	Trade_OrderType_HK_Auction = 2, //���۽���
	Trade_OrderType_HK_AuctionLimit = 3, //�����޼�
};

enum Trade_OrderStatus_HK
{
	Trade_OrderStatus_HK_Processing = 0, //������������...
	Trade_OrderStatus_HK_WaitDeal = 1, //�ȴ��ɽ�
	Trade_OrderStatus_HK_PartDealt = 2, //���ֳɽ�
	Trade_OrderStatus_HK_AllDealt = 3, //ȫ���ɽ�
	Trade_OrderStatus_HK_Disabled = 4, //��ʧЧ
	Trade_OrderStatus_HK_Failed = 5, //�µ�ʧ�ܣ������Ѳ�����������ʧ�ܣ�
	Trade_OrderStatus_HK_Cancelled = 6, //�ѳ���
	Trade_OrderStatus_HK_Deleted = 7, //��ɾ��
	Trade_OrderStatus_HK_WaitOpen = 8, //�ȴ�����
	Trade_OrderStatus_HK_LocalSent = 21, //�����ѷ���
	Trade_OrderStatus_HK_LocalFailed = 22, //�����ѷ��ͣ������������µ�ʧ�ܣ�û��������
	Trade_OrderStatus_HK_LocalTimeOut = 23, //�����ѷ��ͣ��ȴ����������س�ʱ
};

enum Trade_SetOrderStatus_HK
{
	Trade_SetOrderStatus_HK_Cancel = 1, //����
	Trade_SetOrderStatus_HK_Disable = 2, //ʧЧ
	Trade_SetOrderStatus_HK_Enable = 3, //��Ч
	Trade_SetOrderStatus_HK_Delete = 4, //ɾ��
};

struct Trade_OrderItem_HK
{
	UINT64 nLocalID; //�ͻ��˲����Ķ���ID���Ƕ���������ID�����ڹ���
	UINT64 nOrderID; //�����ţ������������Ķ���������ID

	Trade_OrderSide enSide;
	Trade_OrderType_HK enType;
	Trade_OrderStatus_HK enStatus;
	WCHAR szCode[16];
	WCHAR szName[128];
	UINT64 nPrice;
	UINT64 nQty;
	UINT64 nDealtQty; //�ɽ�����
	
	UINT64 nSubmitedTime; //�������յ��Ķ����ύʱ��
	UINT64 nUpdatedTime; //���������µ�ʱ��

	UINT16 nErrCode; //������
};

interface ITrade_HK
{
	/**
	* �µ�

	* @param pCookie ���ձ��ε��ö�Ӧ��Cookieֵ�����ڷ���������ʱ����Ӧ��ϵ�ж�.
	* @param enSide �������������.
	* @param enType ��������.
	* @param lpszCode ��Ʊ����.
	* @param nPrice �����۸�.
	* @param nQty ��������.

	* @return true���ͳɹ���false����ʧ��.
	*/
	virtual bool PlaceOrder(UINT* pCookie, Trade_OrderSide enSide, Trade_OrderType_HK enType, LPCWSTR lpszCode, UINT64 nPrice, UINT64 nQty) = 0;

	/**
	* ���ö���״̬

	* @param pCookie ���ձ��ε��ö�Ӧ��Cookieֵ�����ڷ���������ʱ����Ӧ��ϵ�ж�.
	* @param enStatus ����Ϊ����״̬.
	* @param nOrderID ����������ID.

	* @return true���ͳɹ���false����ʧ��.
	*/
	virtual bool SetOrderStatus(UINT* pCookie, Trade_SetOrderStatus_HK enStatus, UINT64 nOrderID) = 0;

	/**
	* �ĵ�

	* @param pCookie ���ձ��ε��ö�Ӧ��Cookieֵ�����ڷ���������ʱ����Ӧ��ϵ�ж�.
	* @param nOrderID ����������ID.
	* @param nPrice �µĶ����۸�.
	* @param nQty �µĶ�������.

	* @return true���ͳɹ���false����ʧ��.
	*/
	virtual bool ChangeOrder(UINT* pCookie, UINT64 nOrderID, UINT64 nPrice, UINT64 nQty) = 0;
};

interface ITradeCallBack_HK
{
	/**
	* �µ����󷵻�

	* @param nCookie ����ʱ��Cookie.
	* @param enRet ������������.
	* @param nLocalID �ͻ��˲����Ķ���ID.
	* @param nErrCode ������.
	*/
	virtual void OnPlaceOrder(UINT nCookie, Trade_SvrResult enRet, UINT64 nLocalID, UINT16 nErrCode) = 0;

	/**
	* ������������

	* @param orderItem �����ṹ��.
	*/
	virtual void OnOrderUpdated(const Trade_OrderItem_HK& orderItem) = 0;

	/**
	* ���ö���״̬���󷵻�

	* @param nCookie ����ʱ��Cookie.
	* @param enRet ������������.
	* @param nOrderID ������.
	* @param nErrCode ������.
	*/
	virtual void OnSetOrderStatus(UINT nCookie, Trade_SvrResult enRet, UINT64 nOrderID, UINT16 nErrCode) = 0;

	/**
	* �ĵ����󷵻�

	* @param nCookie ����ʱ��Cookie.
	* @param enRet ������������.
	* @param nOrderID ������.
	* @param nErrCode ������.
	*/
	virtual void OnChangeOrder(UINT nCookie, Trade_SvrResult enRet, UINT64 nOrderID, UINT16 nErrCode) = 0;
};
