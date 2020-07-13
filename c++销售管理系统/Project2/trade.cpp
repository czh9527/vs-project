
#include "trade.h"
using namespace std;
int trandeNum = 0;
trade::trade() {}
trade::~trade()
{
	total = 0;
}
bool trade::Buy(int ID, int count) //������Ʒ�Ĳ��������ݼ��
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getID() == ID)
		{
			iter->UpdateStock(count);
			time_t t = time(0);
			char temp[50];
			strftime(temp, sizeof(temp), "%Y�� %m�� %d�� %X %A", localtime(&t));
			buyRecordList.push_back(record(iter->getName(), count, temp));
			total -= count*iter->getBuyValue();
			trandeNum++;
			return true;
		}
	}
	return false;
}

bool trade::Sell(int ID, int count) //�۳���Ʒ�Ĳ��������ݼ��
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getID() == ID && !(iter->getStock() + count < 0))
		{ 
			if (!iter->UpdateStock(-count))//���û����ɹ�
			{
				printf("\tû����ô���棡����\n\t��ֻ�ܹ���%d��\n", iter->getStock());
				return false;
			}
			time_t t = time(0);
			char temp[50];
			strftime(temp, sizeof(temp), "%Y�� %m�� %d�� %X %A", localtime(&t));
			sellRecordList.push_back(record(iter->getName(), count, temp));
			trandeNum++;
			total += count*(iter->getsellValue()-iter->getBuyValue());
			return true;
		}
	}
	system("cls");
	printf("û�и���Ʒ��\n");
	return false;
}

void trade::AddNew(char *name, float buyValue, float sellValue, COMMODITYTYPE commoditytype) //����һ��ȫ�µ���Ʒ
{
	if (commoditytype == MASK)
	{
		Mask *addMode = new Mask();
		cout << "��������ֲ��ϣ�";
		cin >> otherInfo;
		addMode->setMaterial(otherInfo);
		addMode->setValue(name, buyValue, sellValue, 0, commoditytype);

		dataList.push_back(*addMode);
		delete addMode;//�ͷſռ䣬������������
	}
	else
	{
		Drug *addMode = new Drug();
		cout << "������ҩƷ���أ�";
		cin >> otherInfo;
		addMode->setArea(otherInfo);
		addMode->setValue(name, buyValue, sellValue, 0, commoditytype);
		dataList.push_back(*addMode);
		delete addMode;//�ͷſռ䣬������������
		
	}

}

void trade::GetIndex(COMMODITYTYPE commoditytype) //��ȡ�������ƷĿ¼
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getType() == commoditytype)
		{
			printf("\t  ��Ʒ���: %i  ��Ʒ����: %s\n", iter->getID(), iter->getName());
		}
	}
}

bool trade::GetInformathion(int index) //��ȡ�������Ʒ��Ϣ
{
	for (auto iter = dataList.begin(); iter != dataList.end(); iter++)
	{
		if (iter->getID() == index)
		{
			printf("��Ʒ���:%d\n��Ʒ����:%s\n����۸�%f\n���ۼ۸�%f\nʣ�ࣺ%d\n", index,
				iter->getName(),
				iter->getBuyValue(),
				iter->getsellValue(),
				iter->getStock());
			if (iter->getType() == MASK)
			{
				printf("���ֲ���:%s\n", iter->getOtherInfo());
			}
			else
			{
				printf("ҩƷ����:%s\n", iter->getOtherInfo());
			}

			return true;
		}
	}
	return false;
}
bool trade::init() //�ӻ�ȡ��Ʒ��Ϣ
{
	Commodity *mask1 = new Commodity("3m����", 10.5, 20.5, 100, MASK, "�޷Ĳ�");
	Commodity *drug1 = new Commodity("����", 200, 210, 50, DRUG, "����");

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

void trade::getSellRecord() //�����Ʒ�����ۼ�¼
{
	for (auto iter = sellRecordList.begin(); iter != sellRecordList.end(); iter++)
	{
		printf("\t������Ʒ����:%s\n", iter->name);
		printf("\t��������:%s\n", iter->sTime);
		printf("\t������Ŀ:%d\n", iter->count);
		printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
	}
}

void trade::getBuyRecord()//�����Ʒ�Ĺ����¼
{
	for (auto iter = buyRecordList.begin(); iter != buyRecordList.end(); iter++)
	{

		printf("\t������Ʒ����:%s\n", iter->name);
		printf("\t��������:%s\n", iter->sTime);
		printf("\t������Ŀ:%d\n", iter->count);
		printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
	}
}