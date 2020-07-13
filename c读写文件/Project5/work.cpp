
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <vector>
int PT08_S1[10000] = { 0 };
int NMHC[10000] = { 0 };
int NOx[10000] = { 0 };
char all_str[10000] = { 0 };
int dataNum = 0;
#define FILE_PATH "DataSet1：AirQualityUCI.txt"
void writeFile(char* info, FILE *pFile)
{
		fputs(info, pFile);
}
void makeFile()
{
	FILE* pFile = fopen("get.txt", "w");
	char szTest[1000] = { 0 };

	char target[100] = "";
	int len = 0;
	int j = 0;
	int k = 0;
	bool isNum=false;
	int NMHC_i = 0;
	int NOx_i = 0; 
	int PT08_S1_i = 0;
	FILE *fp = fopen(FILE_PATH, "r");
	if (NULL == fp)
	{
		printf("failed to open DataSet1：AirQualityUCI.txt\n");
		return;
	}
	while (!feof(fp) )
	{
		k = 0;
		memset(szTest, 0, sizeof(szTest));//清空szTest
		fgets(szTest, sizeof(szTest)-1, fp); // 包含了换行符
		for (int i = 0; i < strlen(szTest); i++)
		{
			
			target[j] = szTest[i];
			j++;
			if (szTest[i] == '\t' )//单词分隔符
			{
				k++;
				if (atoi(target) != 0)
				{
					target[j - 1] = '\0';//把/t换成/0结束字符串
					if (k == 4)
					{
						dataNum++;
						PT08_S1[PT08_S1_i] = atoi(target);
						printf("来l%s", target);			
						strcat(target, "\\");
						writeFile(target, pFile);
					/*	printf("%d+", PT08_S1[PT08_S1_i]);*/
						PT08_S1_i++;
					}
					if (k == 5)
					{

						NMHC[NMHC_i] = atoi(target);
						char s[10] = "";
						sprintf(s, "%d", NMHC[NMHC_i]);
						strcat(s, "\\");
						writeFile(s, pFile);
						/*printf("%d+", NMHC[NOx_i]);*/
						NMHC_i++;
					}
					if (k == 8)
					{
						NOx[NOx_i] = atoi(target);
						char s[10] = "";
						sprintf(s, "%d", NOx[NOx_i]);
						strcat(s, "\n");
						writeFile(s, pFile);
						/*printf("%d+\n", NOx[NOx_i]);*/
						NOx_i++;


					}
				}
				
				j = 0;
				memset(target, 0, sizeof(target));
			}
				
		}

	
	}
	
	fclose(fp);
	fclose(pFile);
	printf("\t完成!\n");

	
}
void printResult()
{
	long long all = 0;
	long long fall = 0;
	int jPT08_S1 = 0;
	int jNMHC = 0;
	int jNOx = 0;
	int fPT08_S1 = 0;
	int fNMHC = 0;
	int fNOx = 0;
	for (int i = 0; i < dataNum; i++)
	{
		all += PT08_S1[i];
	}
	jPT08_S1 = all / dataNum;
	for (int i = 0; i < dataNum; i++)
	{
		fall += pow((PT08_S1[i] - jPT08_S1), 2);
	}
	fPT08_S1 = fall / dataNum;
	all = 0;
	fall = 0;
	for (int i = 0; i < dataNum; i++)
	{
		all += NMHC[i];
	}
	jNMHC = all / dataNum;
	for (int i = 0; i < dataNum; i++)
	{
		fall += pow((NMHC[i] - jNMHC), 2);
	}
	fNMHC = fall / dataNum;
	all = 0;
	fall = 0;
	for (int i = 0; i < dataNum; i++)
	{
		all += NOx[i];
	}
	jNOx = all / dataNum;
	for (int i = 0; i < dataNum; i++)
	{
		fall += pow((NOx[i] - jNOx), 2);
	}
	fNOx = fall / dataNum;

	printf("\t均值:\tPT08.S1(CO):%d\tNMHC(GT):%d \t NOx(GT):%d\n", jPT08_S1, jNMHC, jNOx);
	printf("\t方差:\tPT08.S1(CO):%d\tNMHC(GT):%d \t NOx(GT):%d\n", fPT08_S1, fNMHC, fNOx);

}
int main()
{
	makeFile();
	printResult();

	system("pause");
	return 0;
}
