#ifndef H_DRUG_HH
#define H_DRUG_HH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ҩƷ��Ϣ�ṹ��
typedef struct drug {
	int  number;//��Ϊ���
	char  name[50];//ҩƷ����
	int  amount;//ҩƷ����
	float  money1;//ҩƷ�ۼ�
	char  size[50];//���
	char  manufacturer[50];//��������
	struct drug* link;
}drug;

//���ܺ���
void  menu(); //�˵������� 
int  menu_select(void); //�˵�ѡ���� 
void  addRecord(drug* head); //������Ϣ����
void  display(drug* head); //��ʾ����ҩƷ��Ϣ���� 
void  saveRecords(drug* head); //�ļ��洢�������� 
drug*  loadRecords(); //�ļ���ȡ��������
void  quit(drug* head); //���������� 
void  findRecord(int n, drug* head4); //����ָ����¼���� 
void  queryInfo(drug* head3); //��ѯָ��ҩƷ��Ϣ�ĺ��� 
void  modifyRecord(drug* head2); //�޸�ָ��ҩƷ��Ϣ���� 
drug*  insertRecord(drug* head5);//������Ϣ����
drug*  removeRecord(drug* head6); //ɾ����¼���� 
void  Data_statistics(drug* h);//����ͳ��
void  sortInfo(drug* h2);  //ҩƷ��Ϣ������ 

//��������
static void eatline(void);//�������������
int length(drug* head);//�Ƴ�����
void serialNumber(drug* h3);//��ź���


#endif 
#pragma once
