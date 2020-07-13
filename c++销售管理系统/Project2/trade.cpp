
#include "trade.h"
using namespace std;
int trandeNum = 0;
trade::trade() {}
trade::~trade()
{
	total = 0;
}
bool trade::Buy(int ID, int count) //购买商品的操作与数据检查
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getID() == ID)
		{
			iter->UpdateStock(count);
			time_t t = time(0);
			char temp[50];
			strftime(temp, sizeof(temp), "%Y年 %m月 %d日 %X %A", localtime(&t));
			buyRecordList.push_back(record(iter->getName(), count, temp));
			total -= count*iter->getBuyValue();
			trandeNum++;
			return true;
		}
	}
	return false;
}

bool trade::Sell(int ID, int count) //售出商品的操作与数据检查
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getID() == ID && !(iter->getStock() + count < 0))
		{ 
			if (!iter->UpdateStock(-count))//超额，没有买成功
			{
				printf("\t没有这么多库存！！！\n\t你只能购买%d个\n", iter->getStock());
				return false;
			}
			time_t t = time(0);
			char temp[50];
			strftime(temp, sizeof(temp), "%Y年 %m月 %d日 %X %A", localtime(&t));
			sellRecordList.push_back(record(iter->getName(), count, temp));
			trandeNum++;
			total += count*(iter->getsellValue()-iter->getBuyValue());
			return true;
		}
	}
	system("cls");
	printf("没有该商品！\n");
	return false;
}

void trade::AddNew(char *name, float buyValue, float sellValue, COMMODITYTYPE commoditytype) //加入一种全新的商品
{
	if (commoditytype == MASK)
	{
		Mask *addMode = new Mask();
		cout << "请输入口罩材料：";
		cin >> otherInfo;
		addMode->setMaterial(otherInfo);
		addMode->setValue(name, buyValue, sellValue, 0, commoditytype);

		dataList.push_back(*addMode);
		delete addMode;//释放空间，调用析构函数
	}
	else
	{
		Drug *addMode = new Drug();
		cout << "请输入药品产地：";
		cin >> otherInfo;
		addMode->setArea(otherInfo);
		addMode->setValue(name, buyValue, sellValue, 0, commoditytype);
		dataList.push_back(*addMode);
		delete addMode;//释放空间，调用析构函数
		
	}

}

void trade::GetIndex(COMMODITYTYPE commoditytype) //获取并输出商品目录
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getType() == commoditytype)
		{
			printf("\t  商品编号: %i  商品名称: %s\n", iter->getID(), iter->getName());
		}
	}
}

bool trade::GetInformathion(int index) //获取并输出商品信息
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getID() == index)
		{
			printf("商品编号:%d\n商品名称:%s\n购入价格：%f\n出售价格：%f\n剩余：%d\n", index,
				iter->getName(),
				iter->getBuyValue(),
				iter->getsellValue(),
				iter->getStock());
			if (iter->getType() == MASK)
			{
				printf("口罩材料:%s\n", iter->getOtherInfo());
			}
			else
			{
				printf("药品产地:%s\n", iter->getOtherInfo());
			}

			return true;
		}
	}
	return false;
}
bool trade::init() //从获取商品信息
{
	Commodity *mask1 = new Commodity("3m口罩", 10.5, 20.5, 100, MASK, "无纺布");
	Commodity *drug1 = new Commodity("疫苗", 200, 210, 50, DRUG, "北京");

	dataList.clear();
	dataList.push_back(*mask1);
	dataList.push_back(*drug1);
	if (dataList.size() == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void trade::getSellRecord() //获得商品的销售记录
{
	for (auto iter = sellRecordList.begin(); iter != sellRecordList.end(); iter++)
	{
		printf("\t出售商品名称:%s\n", iter->name);
		printf("\t交易日期:%s\n", iter->sTime);
		printf("\t出售数目:%d\n", iter->count);
		printf("\t ════════════════════════════ \n");
	}
}

void trade::getBuyRecord()//获得商品的购入记录
{
	for (auto iter = buyRecordList.begin(); iter != buyRecordList.end(); iter++)
	{

		printf("\t购入商品名称:%s\n", iter->name);
		printf("\t交易日期:%s\n", iter->sTime);
		printf("\t购入数目:%d\n", iter->count);
		printf("\t ════════════════════════════ \n");
	}
}