
#include<stdio.h>
#include<stdlib.h>
#include"test.h"


int main() {

  
        printf("\n");
        printf("\t******************************\n");
        printf("\t*          这是一个          *\n");
        printf("\t*        药店管理系统        *\n");
        printf("\t*    可以对药店药品进行管理  *\n");
        printf("\t*      欢迎使用管理程序      *\n");
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
    printf("\t1. 增加药品信息\n");
    printf("\t2. 修改药品信息\n");
    printf("\t3. 显示药品信息\n");
    printf("\t4. 查询药品信息\n");
    printf("\t5. 删除药品信息\n");
    printf("\t6. 插入药品信息\n");
    printf("\t7. 统计药品信息\n");
    printf("\t8. 从记录文件读取药品信息\n");
    printf("\t9. 对药品信息进行排序\n");
    printf("\t10. 保存药品信息至记录文件\n");
    printf("\t11. 结束运行\n");
    printf("\n\t 左边数字对应功能选择，请选1-11: ");

    for (; ; )
    {
        gets ( str, 3);

         se = atoi( str);//将字符串转化成整数 
        /*if ( se == 0 && (strcmp( str, "0") == 0))  se = 12;*/
        if ( se < 0 ||  se>11) printf("\n\t输入错误，重选1-10：");
        else break;

    }
    return  se;
}
//实现增加药品信息功能，建立链表
void  addRecord(drug* head) {

    char str[3];
    drug* p, * q;
    p = head;
    while (1)
    {
        printf("您将要添加一组信息，确定吗？(Y/N)");
        gets (str, 3);
        if (str[0] == 'n' || str[0] == 'N')
            break;

        q = (drug*)malloc(sizeof(drug));
        printf("请输入药品编号:");
        scanf ("%d", &q-> number);
        eatline();
        printf("请输入药品名称:");
        scanf ("%s", q-> name);
        eatline();
        printf("请输入药品进价:");
        scanf ("%f", &q-> amount);
        eatline();
        printf("请输入药品售价:");
        scanf ("%f", &q-> money1);
        eatline();
        printf("请输入药品规格:");
        scanf ("%s", q-> size);
        eatline();
        printf("请输入生产厂家:");
        scanf ("%s", q-> manufacturer);
        eatline();
        p->link = q;
        q->link = NULL;
        p = q;
    }
    printf("\n现在一共有%d条信息...\n", length(head));
}
//实现从链表保存记录到文件功能
void  saveRecords(drug* head) {
    FILE* fp;
    int Tag;
    char fname[30];
    drug* p = NULL;
    p = head->link;

    if (length(head) == 0)
    {
        printf("没有记录可存！");
        return;
    }

    printf("请输入要存入的文件名(直接回车选择文件drug_info.txt)：");
    gets (fname);
    if (strlen(fname) == 0)//自动生成文件名
        strcpy(fname, "D://drug_info.txt");
    if ((fp = fopen(fname, "w+")) == NULL)
    {
        printf("不能存入文件！");
        return;
    }
    printf("\n存文件...\n");
    while (p) {//从链表读取数据到文件
        fprintf(fp, "%d\t%s\t%f\t%f\t%s\t%s\n", p-> number, p-> name, p-> amount, p-> money1, p-> size, p-> manufacturer);
        p = p->link;

    }
    fclose(fp);
    printf("%d条记录已存入文件，请继续操作.\n", length(head));
}
//实现从文件读取信息到链表功能，并返回新建立的链表的头节点
drug*  loadRecords() {

    FILE* fp;
    char fname[30];
    drug* p1, * q1, * head1;
    drug w;
    head1 = (drug*)malloc(sizeof(drug));
    p1 = head1;


    printf("请输入要读取的文件名(直接回车选择文件drug_info.txt)：");
    gets (fname, 30);
    if (strlen(fname) == 0)
        strcpy(fname, "D://drug_info.txt");

    if ((fp = fopen(fname, "rb")) == NULL)
    {
        printf("打不开文件！请重新选择\n");
        return NULL;
    }

    printf("\n读取文件...\n");


    int  number1;//人为编号
    char  name1[50];//药品名称
    float  money2;//药品进价
    float  money3;//药品售价
    char  size1[50];//规格
    char  manufacturer1[50];//生产厂家
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
    printf("读取出%d条记录\n", length(head1));
    fclose(fp);
    return head1;
}
//实现修改指定编号的药品信息功能
void  modifyRecord(drug* head2) {
    FILE* fp;
    char fname[30];
    char str[3];
    int n; int i = 0;
    drug* p2;

    printf("您将要修改一组信息，确定吗？(Y/N)");
    gets (str);
    if (str[0] == 'n' || str[0] == 'N')
        return;
    else
        printf("请输入要修改药品的编号:");

    scanf ("%d", &n, 5);
    eatline();
    for (p2 = head2; i < n && p2->link != NULL; i++) {
        p2 = p2->link;
    }
    printf("修改药品编号为:");
    scanf ("%d", &p2-> number, 5);
    eatline();
    printf("修改药品名称为:");
    scanf ("%s", p2-> name, 50);
    eatline();
    printf("修改药品进价为:");
    scanf ("%f", &p2-> amount, 5);
    eatline();
    printf("修改药品售价为:");
    scanf ("%f", &p2-> money1, 5);
    eatline();
    printf("修改药品规格为:");
    scanf ("%s", p2-> size, 50);
    eatline();
    printf("修改生产厂家为:");
    scanf ("%s", p2-> manufacturer, 50);
    eatline();

    int t = 0;
    printf("是否需要保存?\n");
    printf("输入1为是，0为否\n");
    printf("请输入:");
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
    printf("请输入要删除的药品信息的编号:");
    scanf("%d", &i);
    for (p6 = head6; n < i - 1 && p6->link != NULL; ++n)
        p6 = p6->link;
    if (i > 0 && p6->link != NULL) {
        q6 = p6->link;
        p6->link = q6->link;
        free(q6);
    }
    serialNumber(head6);
    printf("\n数据删除成功...\n");
    eatline();
    return head6;
}

//实现显示所有药品信息功能
void  display(drug* head) {

    int  i;

    if (length(head) == 0)
    {
        printf("没有可供显示的记录");
        return;
    }
    printf("\t-------------------------------------------------------------------------------------------------------- \n");
    printf("\t编号\t药品名称\t药品进价/元\t药品售价/元\t药品规格\t生产厂家\n");

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


        if ( i % 19 == 0 &&  i != 0)//打印一定数目信息，避免一下打印太多信息
        {
            printf("输入任意字符后继续...\n");
            getchar();
            printf("\n\n");
            printf("\t编号\t药品名称\t药品进价/元\t药品售价/元\t药品规格\t生产厂家\n");
        }

    }
}

//实现计算链表长度功能，并返回长度值
int length(drug* head) {
    int len;
    drug* p;
    for (len = 0, p = head->link; p != NULL; len++)//从头节点开始一直循环到尾节点
        p = p->link;
    return len;
}

//实现给药品信息重新编号功能
void serialNumber(drug* h3) {
    drug* i;
    i = h3->link;
    int j = length(h3);

    for (int n = 1; n <= j; n++) {
        i-> number = n;
        i = i->link;
    }

}

//解决scanf缓冲区问题
static void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
