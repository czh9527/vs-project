#include <string.h>
#include <iostream>
extern int addNum;//���ߵ����������delete��������ʵ��
using namespace std;
enum COMMODITYTYPE	//ö�ٱ���������Ʒ����
{
	MASK,
	DRUG
};
class Commodity
{
private:
	int static kinds; //��Ʒ����
	int ID; //��Ʒ���
	int stock; //��Ʒ�����
	float buyValue; //��Ʒ��������
	float sellValue; //��Ʒ�۳�����
	char name[30]; //��Ʒ����
	char *otherInfo;
	COMMODITYTYPE commoditytype;
protected:
	void setOtherInfo(char*info);//ֻ���������ʹ��


public:
	//���캯��
	Commodity()
	{
	
	};
	Commodity(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype,char* otherInfo);
	void setValue(char name[], float buyValue, float sellValue, int stock, COMMODITYTYPE commoditytype);
	//��������
	~Commodity();
	char* getOtherInfo();
	int getID(); //��ȡ��Ʒ���
	int getStock(); //��ȡ��Ʒ�����
	float getBuyValue(); //��ȡ��������
	float getsellValue(); //��ȡ�۳�����
	char* getName(); //��ȡ��Ʒ����
	COMMODITYTYPE getType();//��ȡ��Ʒ����

	bool UpdateStock(int n); //������Ʒ�����
};
class Drug :public Commodity
{
public:
	Drug(){

	};
	~Drug(){
		addNum++;
	};
	void setArea(char* a)//���ò���
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
	void setMaterial(char*m)//���ò���
	{
		this->setOtherInfo(m);
	}
	~Mask(){
		addNum++;
	};
};