
#include <list>
#include "Commodity.h" //加入Commodity.h
#include <time.h> //加入时间操作头文件
extern int trandeNum;
using namespace std; 
struct record //商品交易记录结构体
{
	char name[30]; //商品名称
	int count; //交易数量
	char sTime[70]; //交易时间

	record(char* name, int count, char *time)//构造函数
	{
		strcpy(this->name, name);
		this->count = count;
		strcpy(sTime, time);
	}
};
class trade//交易类
{


	//成员变量
private:
	list<Commodity> dataList; //使用 Commodity类 实现一个商品数据链表
	list<record> buyRecordList; //使用 record结构体 实现一个商品进货记录链表
	list<record> sellRecordList; //使用 record结构体 实现一个商品售货记录链表
	char otherInfo[20];//其他信息

	//成员函数
public:
	trade();
	~trade();
	bool GetInformathion(int index); //获取并输出商品信息
	void GetIndex(COMMODITYTYPE commoditytype); //获取并输出商品目录
	bool init(); //从本地文件获取商品信息
	bool Buy(int ID, int count); //购买商品的操作与数据检查
	bool Sell(int n, int ID); //售出商品的操作与数据检查
	void AddNew(char *name, float buyValue, float sellValue, COMMODITYTYPE commoditytype); //添加新的商品

	/*获得商品的购入和销售记录*/
	void getSellRecord();
	void getBuyRecord();

	float total;
;
};
