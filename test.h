#ifndef H_DRUG_HH
#define H_DRUG_HH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//药品信息结构体
typedef struct drug {
	int  number;//人为编号
	char  name[50];//药品名称
	int  amount;//药品数量
	float  money1;//药品售价
	char  size[50];//规格
	char  manufacturer[50];//生产厂家
	struct drug* link;
}drug;

//功能函数
void  menu(); //菜单处理函数 
int  menu_select(void); //菜单选择函数 
void  addRecord(drug* head); //增加信息函数
void  display(drug* head); //显示所有药品信息函数 
void  saveRecords(drug* head); //文件存储操作函数 
drug*  loadRecords(); //文件读取操作函数
void  quit(drug* head); //结束程序函数 
void  findRecord(int n, drug* head4); //查找指定记录函数 
void  queryInfo(drug* head3); //查询指定药品信息的函数 
void  modifyRecord(drug* head2); //修改指定药品信息函数 
drug*  insertRecord(drug* head5);//插入信息函数
drug*  removeRecord(drug* head6); //删除记录函数 
void  Data_statistics(drug* h);//数据统计
void  sortInfo(drug* h2);  //药品信息排序函数 

//辅助函数
static void eatline(void);//解决缓冲区问题
int length(drug* head);//计长函数
void serialNumber(drug* h3);//编号函数


#endif 
#pragma once
