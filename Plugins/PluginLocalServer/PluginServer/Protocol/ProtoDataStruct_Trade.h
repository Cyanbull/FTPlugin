#pragma once
#include <vector>
#include "ProtoDataStruct.h"

//////////////////////////////////////////////////////////////////////////
//���͸۹ɶ���ʵʱ��Ϣ, PROTO_ID_TDHK_PUSH_ORDER_UPDATE
struct	OrderUpdatePushHKReqBody
{
};

struct OrderUpdatePushHKAckBody
{
	int nEnvType;
	INT64 nLocalID;
	INT64 nOrderID;
	int   nOrderDir;
	int	  nOrderTypeHK;
	int   nOrderStatusHK;	
	int   nPrice;
	INT64 nQTY;
	INT64 nDealQTY;
	int   nSubmitTime;
	int   nUpdateTime;
	std::string strStockName;
	std::string strStockCode;
};

struct	OrderUpdatePushHK_Req
{
	ProtoHead					head;
	OrderUpdatePushHKReqBody	body;
};

struct	OrderUpdatePushHK_Ack
{
	ProtoHead					head;
	OrderUpdatePushHKAckBody	body;
};



//////////////////////////////////////////////////////////////////////////
//���͸۹ɶ���������Ϣ, PROTO_ID_TDHK_PUSH_ORDER_ERROR
struct	OrderErrorPushHKReqBody
{
};

struct OrderErrorPushHKAckBody
{	
	int nEnvType;
	INT64 nOrderID;
	int   nOrderErrNotifyHK;
	int	  nOrderErrCode;
	std::string  strOrderErrDesc;
};

struct	OrderErrorPushHK_Req
{
	ProtoHead				head;
	OrderErrorPushHKReqBody	body;
};

struct	OrderErrorPushHK_Ack
{
	ProtoHead				head;
	OrderErrorPushHKAckBody	body;
};


//////////////////////////////////////////////////////////////////////////
//�¶��� PROTO_ID_TDHK_PLACE_ORDER 
struct	PlaceOrderReqBody
{
	int nEnvType;
	int nCookie;
	int nOrderDir;
	int nOrderType;
	int nPrice;
	INT64 nQty;
	std::string strCode;
};

struct PlaceOrderAckBody
{	
	int nEnvType;
	int nCookie;
	INT64 nLocalID;
	int nSvrResult;	
};

struct	PlaceOrder_Req
{
	ProtoHead			head;
	PlaceOrderReqBody	body;
};

struct	PlaceOrder_Ack
{
	ProtoHead				head;
	PlaceOrderAckBody		body;
};


//////////////////////////////////////////////////////////////////////////
//���ö���״̬ PROTO_ID_TDHK_SET_ORDER_STATUS
struct	SetOrderStatusReqBody
{
	int		nEnvType;
	int		nCookie;
	int		nSetOrderStatus;
	INT64	nSvrOrderID;
	INT64	nLocalOrderID;

};

struct SetOrderStatusAckBody
{	
	int		nEnvType;
	int		nCookie;
	INT64	nSvrOrderID;
	INT64	nLocalOrderID;
	int		nSvrResult;	
};

struct	SetOrderStatus_Req
{
	ProtoHead				head;
	SetOrderStatusReqBody	body;
};

struct	SetOrderStatus_Ack
{
	ProtoHead				head;
	SetOrderStatusAckBody	body;
};


//////////////////////////////////////////////////////////////////////////
//��������
struct UnlockTradeReqBody
{
	int			nCookie;
	std::string strPasswd;
};

struct UnlockTradeAckBody
{
	int	nCookie;
	int nSvrResult;	
};

struct UnlockTrade_Req
{
	ProtoHead				head;
	UnlockTradeReqBody		body;
};

struct UnlockTrade_Ack
{
	ProtoHead				head;
	UnlockTradeAckBody		body;
};


//////////////////////////////////////////////////////////////////////////
//�۹ɸĵ� PROTO_ID_TDHK_CHANGE_ORDER
struct	ChangeOrderReqBody
{
	int		nEnvType;
	int		nCookie;
	INT64	nSvrOrderID;
	INT64	nLocalOrderID;
	int		nPrice;
	INT64	nQty;
};

struct ChangeOrderAckBody
{	
	int		nEnvType;
	int		nCookie;
	INT64	nSvrOrderID;
	INT64	nLocalOrderID;
	int		nSvrResult;	
};

struct	ChangeOrder_Req
{
	ProtoHead			head;
	ChangeOrderReqBody	body;
};

struct	ChangeOrder_Ack
{
	ProtoHead				head;
	ChangeOrderAckBody	body;
};

//////////////////////////////////////////////////////////////////////////
//��ȡ�û��ʻ���Ϣ
struct	QueryAccInfoReqBody
{
	int		nEnvType;
	int		nCookie;	
};

struct QueryAccInfoAckBody
{	
	int		nEnvType;
	int		nCookie;
	
	//������Trade_AccInfoͬ��
	INT64 nPower; //������
	INT64 nZcjz; //�ʲ���ֵ
	INT64 nZqsz; //֤ȯ��ֵ
	INT64 nXjjy; //�ֽ����
	INT64 nKqxj; //��ȡ�ֽ�
	INT64 nDjzj; //�����ʽ�
	INT64 nZsje; //׷�ս��

	INT64 nZgjde; //��߽����
	INT64 nYyjde; //�����Ŵ���
	INT64 nGpbzj; //��Ʊ��֤��
};

struct	QueryAccInfo_Req
{
	ProtoHead			head;
	QueryAccInfoReqBody	body;
};

struct	QueryAccInfo_Ack
{
	ProtoHead			head;
	QueryAccInfoAckBody	body;
};