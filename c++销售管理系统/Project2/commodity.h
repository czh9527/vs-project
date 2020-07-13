#include <string.h>
#include <iostream>
extern int addNum;//上线的数量，配合delete析构函数实现
using namespace std;
enum COMMODITYTYPE	//枚举变量定义商品类型
{
	MASK,
	DRUG
};
class Commodity
{
private:
	int static kinds; //商品种类
	int ID; //商品编号
	int stock; //商品库存量
	float buyValue; //商品进货单价
	float sellValue; //商品售出单价
	char name[30]; //商品名称
	char *otherInfo;
	COMMODITYTYPE commoditytype;
protected:
	void setOtherInfo(char*info);//只有子类可以使用


public:
	//构造函数
	Commodity()
	{
	
	};
	Commodity(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype,char* otherInfo);
	void setValue(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype);
	//析构函数
	~Commodity();
	char* getOtherInfo();
	int getID(); //获取商品编号
	int getStock(); //获取商品库存量
	float getBuyValue(); //获取进货单价
	float getsellValue(); //获取售出单价
	char* getName(); //获取商品名称
	COMMODITYTYPE getType();//获取商品类型

	bool UpdateStock(int n); //更新商品库存量
};
class Drug :public Commodity
{
public:
	Drug(){

	};
	~Drug(){
		addNum++;
	};
	void setArea(char* a)//设置产地
	{
		this->setOtherInfo(a);
	}
};
class Mask :public Commodity
{
public:
	Mask()
	{
		
	};
	void setMaterial(char*m)//设置材料
	{
		this->setOtherInfo(m);
	}
	~Mask(){
		addNum++;
	};
};