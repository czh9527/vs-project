
#include "Commodity.h"
int addNum = 0;
//��ʼ��ID
int Commodity::kinds = 0;
Commodity::Commodity(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype, char* otherInfo) //���캯��
{
	kinds++;
	this->ID = kinds;
	this->stock = stock;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	strcpy(this->name, name);
	this->commoditytype = commoditytype;
	this->otherInfo=otherInfo;
}
void Commodity::setValue(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype) //���캯��
{
	kinds++;
	this->ID = kinds;
	this->stock = stock;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	strcpy(this->name, name);
	this->commoditytype = commoditytype;
}
Commodity::~Commodity()
{
	
}
bool Commodity::UpdateStock(int n) //������Ʒ���
{
	if (stock + n < 0)
	{
		return false;
	}
	else
	{
		stock += n;
		return true;
	}

}
int Commodity::getStock() //��ȡ��Ʒ���
{
	return stock;
}

int Commodity::getID() //��ȡ��Ʒ���
{
	return ID;
}

float Commodity::getBuyValue() //��ȡ�����
{
	return buyValue;
}

float Commodity::getsellValue() //��ȡ�۳���
{
	return sellValue;
}

char* Commodity::getName() //��ȡ��Ʒ����
{
	return name;
}
char* Commodity::getOtherInfo()
{
	return otherInfo;
}
COMMODITYTYPE Commodity::getType()
{
	return commoditytype;
}
void Commodity::setOtherInfo(char*info)//ֻ���������ʹ��
{
	otherInfo = info;
}