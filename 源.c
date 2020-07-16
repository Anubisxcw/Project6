
#include<stdio.h>
#include<stdlib.h>
#include"test.h"


int main() {

  
        printf("\n");
        printf("\t******************************\n");
        printf("\t*          ����һ��          *\n");
        printf("\t*        ҩ�����ϵͳ        *\n");
        printf("\t*    ���Զ�ҩ��ҩƷ���й���  *\n");
        printf("\t*      ��ӭʹ�ù������      *\n");
        printf("\t******************************\n");
        printf("\n");
         menu();

}
void  menu() {
    int a1 = 0;
    int  Tag = 0;
    int  numDrugs = 0;
    drug* head;
    head = (drug*)malloc(sizeof(drug));
    if (head != NULL)
    {
        head->link = NULL;
    }
    for (; ; ) {
        switch ( menu_select()) {
        case 1:
             addRecord(head);

            break;
        case 2:
             modifyRecord(head);
            break;
        case 3:
             display(head);
            break;
        case 4:
             queryInfo(head);
            break;
        case 5:
            head =  removeRecord(head);
            break;
        case 6:
            head =  insertRecord(head);
            break;
        case 7:
             Data_statistics(head);
            break;
        case 8:
            head =  loadRecords();
            break;
        case 9:
             sortInfo(head);
            break;
        case 10:
             saveRecords(head);
            break;
        case 11:
             quit(head);
        }
    }
}
int  menu_select() {
    char  str[3];
    int  se = 0;
    printf("\n");
    printf("\t1. ����ҩƷ��Ϣ\n");
    printf("\t2. �޸�ҩƷ��Ϣ\n");
    printf("\t3. ��ʾҩƷ��Ϣ\n");
    printf("\t4. ��ѯҩƷ��Ϣ\n");
    printf("\t5. ɾ��ҩƷ��Ϣ\n");
    printf("\t6. ����ҩƷ��Ϣ\n");
    printf("\t7. ͳ��ҩƷ��Ϣ\n");
    printf("\t8. �Ӽ�¼�ļ���ȡҩƷ��Ϣ\n");
    printf("\t9. ��ҩƷ��Ϣ��������\n");
    printf("\t10. ����ҩƷ��Ϣ����¼�ļ�\n");
    printf("\t11. ��������\n");
    printf("\n\t ������ֶ�Ӧ����ѡ����ѡ1-11: ");

    for (; ; )
    {
        gets ( str, 3);

         se = atoi( str);//���ַ���ת�������� 
        /*if ( se == 0 && (strcmp( str, "0") == 0))  se = 12;*/
        if ( se < 0 ||  se>11) printf("\n\t���������ѡ1-10��");
        else break;

    }
    return  se;
}
//ʵ������ҩƷ��Ϣ���ܣ���������
void  addRecord(drug* head) {

    char str[3];
    drug* p, * q;
    p = head;
    while (1)
    {
        printf("����Ҫ���һ����Ϣ��ȷ����(Y/N)");
        gets (str, 3);
        if (str[0] == 'n' || str[0] == 'N')
            break;

        q = (drug*)malloc(sizeof(drug));
        printf("������ҩƷ���:");
        scanf ("%d", &q-> number);
        eatline();
        printf("������ҩƷ����:");
        scanf ("%s", q-> name);
        eatline();
        printf("������ҩƷ����:");
        scanf ("%f", &q-> amount);
        eatline();
        printf("������ҩƷ�ۼ�:");
        scanf ("%f", &q-> money1);
        eatline();
        printf("������ҩƷ���:");
        scanf ("%s", q-> size);
        eatline();
        printf("��������������:");
        scanf ("%s", q-> manufacturer);
        eatline();
        p->link = q;
        q->link = NULL;
        p = q;
    }
    printf("\n����һ����%d����Ϣ...\n", length(head));
}
//ʵ�ִ��������¼���ļ�����
void  saveRecords(drug* head) {
    FILE* fp;
    int Tag;
    char fname[30];
    drug* p = NULL;
    p = head->link;

    if (length(head) == 0)
    {
        printf("û�м�¼�ɴ棡");
        return;
    }

    printf("������Ҫ������ļ���(ֱ�ӻس�ѡ���ļ�drug_info.txt)��");
    gets (fname);
    if (strlen(fname) == 0)//�Զ������ļ���
        strcpy(fname, "D://drug_info.txt");
    if ((fp = fopen(fname, "w+")) == NULL)
    {
        printf("���ܴ����ļ���");
        return;
    }
    printf("\n���ļ�...\n");
    while (p) {//�������ȡ���ݵ��ļ�
        fprintf(fp, "%d\t%s\t%f\t%f\t%s\t%s\n", p-> number, p-> name, p-> amount, p-> money1, p-> size, p-> manufacturer);
        p = p->link;

    }
    fclose(fp);
    printf("%d����¼�Ѵ����ļ������������.\n", length(head));
}
//ʵ�ִ��ļ���ȡ��Ϣ�������ܣ��������½����������ͷ�ڵ�
drug*  loadRecords() {

    FILE* fp;
    char fname[30];
    drug* p1, * q1, * head1;
    drug w;
    head1 = (drug*)malloc(sizeof(drug));
    p1 = head1;


    printf("������Ҫ��ȡ���ļ���(ֱ�ӻس�ѡ���ļ�drug_info.txt)��");
    gets (fname, 30);
    if (strlen(fname) == 0)
        strcpy(fname, "D://drug_info.txt");

    if ((fp = fopen(fname, "rb")) == NULL)
    {
        printf("�򲻿��ļ���������ѡ��\n");
        return NULL;
    }

    printf("\n��ȡ�ļ�...\n");


    int  number1;//��Ϊ���
    char  name1[50];//ҩƷ����
    float  money2;//ҩƷ����
    float  money3;//ҩƷ�ۼ�
    char  size1[50];//���
    char  manufacturer1[50];//��������
    int amount1;
    while (fscanf(fp, "%d\t%s\t%d\t%f\t%s\t%s", & number1,  name1, & amount1, & money3,  size1,  manufacturer1) != EOF) {


        q1 = (drug*)malloc(sizeof(drug));
        q1-> number =  number1;
        strcpy(q1-> name,  name1);
        q1-> amount =  amount1;
        q1-> money1 =  money3;
        strcpy(q1-> size,  size1);
        strcpy(q1-> manufacturer,  manufacturer1);
        p1->link = q1;
        q1->link = NULL;
        p1 = q1;
    }
    printf("��ȡ��%d����¼\n", length(head1));
    fclose(fp);
    return head1;
}
//ʵ���޸�ָ����ŵ�ҩƷ��Ϣ����
void  modifyRecord(drug* head2) {
    FILE* fp;
    char fname[30];
    char str[3];
    int n; int i = 0;
    drug* p2;

    printf("����Ҫ�޸�һ����Ϣ��ȷ����(Y/N)");
    gets (str);
    if (str[0] == 'n' || str[0] == 'N')
        return;
    else
        printf("������Ҫ�޸�ҩƷ�ı��:");

    scanf ("%d", &n, 5);
    eatline();
    for (p2 = head2; i < n && p2->link != NULL; i++) {
        p2 = p2->link;
    }
    printf("�޸�ҩƷ���Ϊ:");
    scanf ("%d", &p2-> number, 5);
    eatline();
    printf("�޸�ҩƷ����Ϊ:");
    scanf ("%s", p2-> name, 50);
    eatline();
    printf("�޸�ҩƷ����Ϊ:");
    scanf ("%f", &p2-> amount, 5);
    eatline();
    printf("�޸�ҩƷ�ۼ�Ϊ:");
    scanf ("%f", &p2-> money1, 5);
    eatline();
    printf("�޸�ҩƷ���Ϊ:");
    scanf ("%s", p2-> size, 50);
    eatline();
    printf("�޸���������Ϊ:");
    scanf ("%s", p2-> manufacturer, 50);
    eatline();

    int t = 0;
    printf("�Ƿ���Ҫ����?\n");
    printf("����1Ϊ�ǣ�0Ϊ��\n");
    printf("������:");
    scanf("%d", &t);
    eatline();
    if (t == 1) {
         saveRecords(head2);
    }
}
drug*  removeRecord(drug* head6) {
    drug* p6, * q6;
    int n = 0;
    int i = 0;
    printf("������Ҫɾ����ҩƷ��Ϣ�ı��:");
    scanf("%d", &i);
    for (p6 = head6; n < i - 1 && p6->link != NULL; ++n)
        p6 = p6->link;
    if (i > 0 && p6->link != NULL) {
        q6 = p6->link;
        p6->link = q6->link;
        free(q6);
    }
    serialNumber(head6);
    printf("\n����ɾ���ɹ�...\n");
    eatline();
    return head6;
}

//ʵ����ʾ����ҩƷ��Ϣ����
void  display(drug* head) {

    int  i;

    if (length(head) == 0)
    {
        printf("û�пɹ���ʾ�ļ�¼");
        return;
    }
    printf("\t-------------------------------------------------------------------------------------------------------- \n");
    printf("\t���\tҩƷ����\tҩƷ����/Ԫ\tҩƷ�ۼ�/Ԫ\tҩƷ���\t��������\n");

    drug* p;
    p = head->link;
    printf("\t-------------------------------------------------------------------------------------------------------- \n");
    while (p != NULL)
    {
        printf("\t%d\t%s\t%f\t%f\t%s\t%s\n", p-> number, p-> name, p-> amount, p-> money1, p-> size, p-> manufacturer);
        printf("\t-------------------------------------------------------------------------------------------------------- \n");
        p = p->link;
    }
    for ( i = 0;  i < length(head);  i++) {


        if ( i % 19 == 0 &&  i != 0)//��ӡһ����Ŀ��Ϣ������һ�´�ӡ̫����Ϣ
        {
            printf("���������ַ������...\n");
            getchar();
            printf("\n\n");
            printf("\t���\tҩƷ����\tҩƷ����/Ԫ\tҩƷ�ۼ�/Ԫ\tҩƷ���\t��������\n");
        }

    }
}

//ʵ�ּ��������ȹ��ܣ������س���ֵ
int length(drug* head) {
    int len;
    drug* p;
    for (len = 0, p = head->link; p != NULL; len++)//��ͷ�ڵ㿪ʼһֱѭ����β�ڵ�
        p = p->link;
    return len;
}

//ʵ�ָ�ҩƷ��Ϣ���±�Ź���
void serialNumber(drug* h3) {
    drug* i;
    i = h3->link;
    int j = length(h3);

    for (int n = 1; n <= j; n++) {
        i-> number = n;
        i = i->link;
    }

}

//���scanf����������
static void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
