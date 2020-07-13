
#include "trade.h"
#include <iostream>

using namespace std;

void ToBuy(int& ID, int& count)
{
	cout << "请输入购买商品的编号" << endl;
	cin >> ID;
	getchar();
	cout << "请输入购买商品的数量:" << endl;
	cin >> count;
	getchar();
}

void ToSell(int& ID, int& count)
{
	cout << "请输入卖出商品的编号" << endl;
	cin >> ID;
	getchar();
	cout << "请输入卖出商品的数量:" << endl;
	cin >> count;
	getchar();
}

void operate()
{
	printf("按任意键继续");
	getchar();
	system("cls"); //清空屏幕
}

void drawIndex()
{
	system("cls");
	printf("\t -------------------------------------------------------- \n");
	printf("\t               ***** 商品目录 *****                       \n");
	printf("\t -------------------------------------------------------- \n");
}

void drawLine()
{
	printf("\t -------------------------------------------------------- \n");
}

void DrawMainMenu()
{
	printf("\t╔------------------------------------------------------╗\n");
	printf("\t║                  抗击疫情，口罩先行                  ║\n");
	printf("\t╠------------------------------------------------------╣\n");
	printf("\t║                 1 -   购进商品                       ║\n");
	printf("\t║                 2 -   卖出商品                       ║\n");
	printf("\t║                 3 -   上线新品                       ║\n");
	printf("\t║                 4 -   查看商品信息                   ║\n");
	printf("\t║                 5 -   查看采购记录                   ║\n");
	printf("\t║                 6 -   查看销售记录                   ║\n");
	printf("\t║                 7 -   统计                           ║\n");
	printf("\t║                 8 -   退出                           ║\n");
	printf("\t╚------------------------------------------------------╝\n");
}

void drawBuyRecord()
{
	system("cls");
	printf("\t -------------------------------------------------------- \n");
	printf("\t               ***** 采购记录 *****                         \n");
	printf("\t -------------------------------------------------------- \n");
}

void drawSellRecord()
{
	system("cls");
	printf("\t -------------------------------------------------------- \n");
	printf("\t               ***** 销售记录 *****                         \n");
	printf("\t -------------------------------------------------------- \n");
}
int main(int argc, char* argv[])
{
	trade myTrade;

	if (!myTrade.init())//初始化数据导入
	{
		return -1;
	}

	bool quitFlag = false;
	while (!quitFlag)
	{
		DrawMainMenu();
		printf("请输入您的选项:");
		int selection;
		cin >> selection;
		getchar();
		int ID;
		int count;
		int stock;
		COMMODITYTYPE commoditytype;
		int temp = 0;//标记位
		int temp1 = 0;//标记位
		switch (selection)
		{
		case 1:
			drawIndex();
			myTrade.GetIndex(MASK);
			myTrade.GetIndex(DRUG);
			drawLine();
			ToBuy(ID, count);
			if (myTrade.Buy(ID, count))
			{
				system("cls");
				printf("\t购买成功\n");
			}
			else
			{
				system("cls");
				printf("\t没有该商品\n");
			}
			operate();
			break;

		case 2:
			drawIndex();
			myTrade.GetIndex(MASK);
			myTrade.GetIndex(DRUG);
			drawLine();
			ToSell(ID, count);
			if (myTrade.Sell(ID, count))
			{
				system("cls");
				printf("\t出售成功\n");
			}
			operate();
			break;

		case 3:
			char name[30];
			float value;
			float cost;
			printf("\t -------------------------------------------------------- \n");
			printf("\t               *****  1-口罩  *****                       \n");
			printf("\t               *****  2-药品  *****                       \n");
			printf("\t -------------------------------------------------------- \n");
			cin >> temp1;
			getchar();
			switch (temp1)
			{
			case 1:
				commoditytype = MASK;
				break;
			case 2:
				commoditytype = DRUG;
				break;
			default:
				printf("\t无效的选项\n");
				break;
			}
			system("cls");
			cout << "请输入新品的名称" << endl;
			cin >> name;
			getchar();
			cout << "请输入购入价格" << endl;
			cin >> cost;
			getchar();
			cout << "请输入出售价格" << endl;
			cin >> value;
			getchar();
			myTrade.AddNew(name, cost, value,commoditytype);
			system("cls");
			printf("\t上线成功\n");
			operate();
			break;

		case 4:
			drawIndex();
			printf("\t -------------------------------------------------------- \n");
			printf("\t               *****  1-口罩  *****                       \n");
			printf("\t               *****  2-药品  *****                       \n");
			printf("\t               *****  3-全部  *****                       \n");
			printf("\t -------------------------------------------------------- \n");
			cin >> temp;
			getchar();
			switch (temp)
			{
			case 1:
				myTrade.GetIndex(MASK);
				break;
			case 2:
				myTrade.GetIndex(DRUG);
				break;
			case 3:
				myTrade.GetIndex(MASK);
				myTrade.GetIndex(DRUG);
				break;
			default:
				printf("\t无效的选项\n");
				break;
			}

			drawLine();
			cout << "请输入商品编号:";
			int index;
			cin >> index;
			getchar();
			system("cls");
			if (!myTrade.GetInformathion(index))
			{
				cout << "\t无效的商品编号\n";
				operate();
			}
			else{
				operate();
			}
			break;

		case 5:
			drawBuyRecord();
			myTrade.getBuyRecord();
			operate();
			break;

		case 6:
			drawSellRecord();
			myTrade.getSellRecord();
			operate();
			break;
		case 7:
			system("cls");
			cout << "\t进行了" << trandeNum << "次交易\n";
			cout << "\t新上线过" << addNum << "个商品\n";
			if (myTrade.total >= 0)
			{
				cout << "\t赚了" << myTrade.total << "元钱\n";
			}
			else
			{
				cout << "\t亏了" << -myTrade.total << "元钱\n";
			}
			operate();
			break;
		case 8:
			quitFlag = true;
			break;

		default:
			system("cls");
			printf("\t无效的选项\n");
			operate();
		}
	}
	return 0;
}
