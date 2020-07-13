
#include "Commodity.h"
int addNum = 0;
//初始化ID
int Commodity::kinds = 0;
Commodity::Commodity(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype, char* otherInfo) //构造函数
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
void Commodity::setValue(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype) //构造函数
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
bool Commodity::UpdateStock(int n) //更新商品库存
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
int Commodity::getStock() //获取商品库存
{
	return stock;
}

int Commodity::getID() //获取货品编号
{
	return ID;
}

float Commodity::getBuyValue() //获取购入价
{
	return buyValue;
}

float Commodity::getsellValue() //获取售出价
{
	return sellValue;
}

char* Commodity::getName() //获取商品名称
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
void Commodity::setOtherInfo(char*info)//只有子类可以使用
{
	otherInfo = info;
}