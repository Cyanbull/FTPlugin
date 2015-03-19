#pragma once
 
/************************************************* 
Copyright: FUTU
Author: ysq
Date: 2015-03-18
Description: ����API�ͻص��ӿڶ���
**************************************************/  

static const GUID IID_IFTQuoteData = 
{ 0xb75073e3, 0xaa3a, 0x4717, { 0xac, 0xa2, 0x11, 0x94, 0xa1, 0x3, 0x78, 0xc7 } };

static const GUID IID_IFTQuoteOperation = 
{ 0x9c65990c, 0x903, 0x4185, { 0x97, 0x12, 0x3e, 0xa7, 0xab, 0x34, 0xd, 0xc5 } };


/**
*��Ʊ���г����� 
*/ 
enum StockMktType 
{	
	StockMkt_HK = 1,  //�۹� 
	StockMkt_US = 2,  //����
	StockMkt_SH = 3,  //����
	StockMkt_SZ = 4,  //���
}; 


/**
* ��Ʊ����������Ϣ��
* �۸񾫶���3λС���� �籨��8.888�洢ֵ 88888
*/
typedef struct tagQuotePriceBase
{ 
	DWORD dwOpen;		//���̼�
	DWORD dwLastClose;  //���ռ�
	DWORD dwCur;		//��ǰ��
	DWORD dwHigh;		//��߼�
	DWORD dwLow;		//��ͼ�
	INT64 ddwVolume;	//�ɽ���
	INT64 ddwTrunover;	//�ɽ���
}Quote_PriceBase, *LPQuote_PriceBase;


/**
* ��Ʊʮ������
* IFTQuoteData::FillOrderQueue �Ľӿڲ���  
*/
typedef struct tagQuoteOrderQueue
{
	DWORD	dwBuyPrice, dwSellPrice;  //��� ����
	INT64	ddwBuyVol, ddwSellVol;    //���� ����
	int		nBuyOrders, nSellOrders;  //��λ 
}Quote_OrderQueue, *LPQuote_OrderQueue;  


/**
* ��������ӿ� 
*/
interface IFTQuoteOperation 
{
	//���鶨��
	virtual void Subscribe_PriceBase(GUID guidPlugin, LPCWSTR wstrStockCode,  StockMktType eType, bool bSubb) = 0;  
	virtual void Subscribe_OrderQueue(GUID guidPlugin, LPCWSTR wstrStockCode, StockMktType eType, bool bSubb) = 0; 
};

/**
* �������ݵĽӿ�
*/
interface IFTQuoteData
{ 
	/**
	* ��ǰ�Ƿ���ʵʱ����
	*/
	virtual bool   IsRealTimeQuotes() = 0; 

	/**
	* stock ��hashֵ, �ص��ӿڷ��� 
	*/ 
	virtual INT64  GetStockHashVal(LPCWSTR pstrStockCode, StockMktType eMkt) = 0; 

	/**
	* ���������� 
	*/ 
	virtual bool   FillPriceBase(INT64 ddwStockHash,  Quote_PriceBase* pInfo) = 0; 

	/**
	* ���ʮ������
	*/ 
	virtual bool   FillOrderQueue(INT64 ddwStockHash, Quote_OrderQueue* parQuote, int nCount) = 0; 
}; 

/**
* �������ݻص�
*/
interface IQuoteInfoCallback
{ 
	/**
	* ����������Ϣ�仯 
	*/ 
	virtual void  OnChanged_PriceBase(INT64  ddwStockHash) = 0; 

	/**
	* ʮ�����ݱ仯
	*/ 
	virtual void  OnChanged_OrderQueue(INT64 ddwStockHash) = 0; 
};

