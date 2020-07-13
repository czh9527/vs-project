
#include <list>
#include "Commodity.h" //����Commodity.h
#include <time.h> //����ʱ�����ͷ�ļ�
extern int trandeNum;
using namespace std; 
struct record //��Ʒ���׼�¼�ṹ��
{
	char name[30]; //��Ʒ����
	int count; //��������
	char sTime[70]; //����ʱ��

	record(char* name, int count, char *time)//���캯��
	{
		strcpy(this->name, name);
		this->count = count;
		strcpy(sTime, time);
	}
};
class trade//������
{


	//��Ա����
private:
	list<Commodity> dataList; //ʹ�� Commodity�� ʵ��һ����Ʒ��������
	list<record> buyRecordList; //ʹ�� record�ṹ�� ʵ��һ����Ʒ������¼����
	list<record> sellRecordList; //ʹ�� record�ṹ�� ʵ��һ����Ʒ�ۻ���¼����
	char otherInfo[20];//������Ϣ

	//��Ա����
public:
	trade();
	~trade();
	bool GetInformathion(int index); //��ȡ�������Ʒ��Ϣ
	void GetIndex(COMMODITYTYPE commoditytype); //��ȡ�������ƷĿ¼
	bool init(); //�ӱ����ļ���ȡ��Ʒ��Ϣ
	bool Buy(int ID, int count); //������Ʒ�Ĳ��������ݼ��
	bool Sell(int n, int ID); //�۳���Ʒ�Ĳ��������ݼ��
	void AddNew(char *name, float buyValue, float sellValue, COMMODITYTYPE commoditytype); //����µ���Ʒ

	/*�����Ʒ�Ĺ�������ۼ�¼*/
	void getSellRecord();
	void getBuyRecord();

	float total;
;
};
