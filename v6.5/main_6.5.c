/*
* @Author: Administrator
* @Date:   2019-03-15 08:14:24
* @Last Modified by:   22486
* @Last Modified time: 2019-05-04 21:29:08
*/

//////////////////////////导入头文件//////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
/////////////////////////////////////////////////////////////////
//////////////////////////全局变量//////////////////////////////
typedef struct link LINK;//重命名结构体
HANDLE handle;//句柄
double money;//记录总资产
char sort_search_three;//选择标记
int mm;//选择标记
int storage_num=0;
///////////////////////////////////////////////////////////////
///
/////////////////////////数据结构//////////////////////////////
struct POX//生成光标位置结构
{
	int x;
	int y;
};//定义一个结构体变量,储存光标坐标
struct TIME//生成时间结构
{
	int month;
	int day;
	int hour;
	int minute;
};
struct link//生成链表数据结构
{
	struct TIME time;
	char name[20];
	char type[30];
	char maker[20];
	float price;
	int num;
	float sum;
	char infor[20];
	LINK *next;
};

///////////////////////////////////////////////////////////////
///
/////////////////////////函数声明部分//////////////////////////
///
//////////////////////////MXQ
void menu (int num);//打印开始界面
void start_menu (void);//开始界面生成
void menu_of_statistic (int num);//统计模块ui
void menu_of_stastic_second (int i);//销售记录二级菜单
void print_info (LINK *p);//以列表形式打印配件，型号，制造商信息
void print_buy_info (int num,LINK *p);//打印进货信息
void print_statistic (void);//打印财务统计
float print_total_sales (void);//统计总销售额
void print_total_profit (void);//总盈利额
void print_statistic_of_table (int i);//打印进货表
void print_statistic_of_sell (void);//打印报销售表
void print_ststus_reporting (void);//库存报表
void print_statistic_of_old_data (void);//打印历史销售记录
int choose_donation (char info[]);//赠品选择
void change_num(int num,LINK* p,int);//改变链表里某一节点的库存数量，并把记录输出到stock.txt中存档
int check_num (int num,LINK* p,int sell_num);//检查想要销售的数量是否足够销售，够返回1，否则返回0
void change_files(LINK* p);//修改storage.txt里面的数据值
void change_num_of_sell(int add,LINK *p,int num,float price,char info[]);
char get_hit (void);//获取键盘敲击返回值
void get_money (void);
void write_money (void);
float get_file_sum_date (const char *pstr,const char *pstrMod);//返回sum值
void buy (void);//进货主函数
void sell (void);//销售主函数
float calc (int num,LINK* p,int sum);//计算链表里某一结点的总价数量及：单价*数量
FILE* open (const char *pstr,const char *pstrMod);//打开文件
void FullScreen(void);//全屏函数
LINK* make_link (FILE* fp,int i);//链表制作
int choose_time (struct TIME *ptim,struct POX *p,char *key);//时间选择器从x月x日x时x分-----到x月x日x时x分
void setcursorposition(int x,int y);//设置光标位置
void SearchStart();//搜索函数主程序
void choose(int i);//选择函数
void search(LINK*,char,char search[]);//查找信息函数
void home(int);//搜索选择查询类型界面界面《一级界面》
void main_home();//check()函数主界面
void main_sort_home(int);//
void sort_home(int);//《二级界面》
void XiaoHuangRen();//小黄人
void StartMenu(int n);//开始菜单
void StartDelete();//开始删除
void ChooseDeleteInfor(int);//选择删除类型
LINK* Delete(LINK*,int);//删除节点
void InputDeleteInfor(LINK*,int);//修改信息
int DeleteMenu1(LINK*);//删除菜单
void menu_of_change_record (int num);
void print_change_record (void);//打印修改记录
void print_addchange_record (void);//打印添加记录
char delete_write(LINK *p);//删除文件并重写文件
void add_change_storage(LINK *p,int i);//库存修改
void ChooseChangeInfor(int n);//选择修改信息
void set_white_txt (void);//设置白色文本
void set_normal_txt (void);//恢复文本
void add_storage (void);//添加库存
void num_of_storage (void);//获取库存数量
void del_storage (void);//库存删除函数
int strcmpr(char* p0,char* p);//
int calcsize (char * p);
void money_storage (void);
///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////函数实现部分///////////////////////////////////
int main()
{
	//system("chcp 65001");//设置utf-8编码
	//setcursorposition(0,0);//光标回到原点
	FullScreen();
	get_money();
	num_of_storage ();
    handle=GetStdHandle(STD_OUTPUT_HANDLE);//句柄的产生
	start_menu();//载入开始界面
    return 0;
}

void set_white_txt (void)
{
	SetConsoleTextAttribute(handle,BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
}

void set_normal_txt (void)
{
	SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
}

void setcursorposition(int x,int y)
{
	COORD coord;//鼠标位置结构体
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition (handle,coord);//设置光标位置
}

void menu (int num)
{
	switch(num)
	{
		case -1:printf("*************************************************            *****************\n");
			   printf("*****Computer accessories management system******              press: 'W'or'S  \n");
			   printf("*****          1.buy                       ******                   UP:'W'     \n");//进货//销售
			   printf("*****          2.sale                      ******                   DOWN:'S'   \n");//销售
			   printf("*****          3.check information         ******             *****************\n");//信息查询
			   printf("*****          4.delete information        ******\n");//删除信息
			   printf("*****          5.change information        ******\n");//更改一条信息
			   printf("*****          6.financial statsaistics    ******\n");//财务统计
			   printf("*****          7.exit                      ******\n");//退出
			   printf("*************************************************\n");
			   XiaoHuangRen();
			   break;
		case 2:printf("*****          1.buy                       ******\n");break;
		case 3:printf("*****          2.sale                      ******\n");break;
		case 4:printf("*****          3.check information         ******\n");break;
		case 5:printf("*****          4.delete information        ******\n");break;
		case 6:printf("*****          5.change information        ******\n");break;
		case 7:printf("*****          6.financial statistics      ******\n");break;
		case 8:printf("*****          7.exit                      ******\n");break;
	}
}

void menu_of_statistic (int num)
{
	switch(num)
	{
		case -1:printf("************************************************\n");
			   printf("*******        financial  statisyic       *******            *****************\n");
			   printf("*******        1.total sales              *******             press: 'W'or'S  \n");//销售总额
			   printf("*******        2.benefit                  *******                  UP:'W'     \n");//盈/亏额
			   printf("*******        3.status reporting         *******                  DOWN:'S'   \n");//当前库存报表
               printf("*******        4.statisyic of data        *******            *****************\n");//返回上一层
			   printf("*******        5.back                     *******\n");
			   printf("*************************************************\n");
			   XiaoHuangRen();
			   break;
		case 2:printf("*******        1.total sales              *******\n");break;
		case 3:printf("*******        2.benefit                  *******\n");break;
		case 4:printf("*******        3.status reporting         *******\n");break;
        case 5:printf("*******        4.statisyic of data        *******\n");break;
		case 6:printf("*******        5.back                     *******\n");break;
	}
}

LINK* make_link (FILE* fp,int i)//输入数字，打印所需链表长度,并返回头指针
{
	LINK *p=NULL;//中间变量指针
	LINK *header=NULL;//头节点指针
	LINK *tail=NULL;//尾节点指针
	p=(LINK*)malloc(sizeof(LINK));
	if (p==NULL)//判断空间是否开辟成功
	{
		printf("Wrong\n");
		exit(0);
	}
	p->next=NULL;//初始化头节点链表内部指针
	header=p;
	tail=p;
	while(!feof(fp))//循环开辟链表空间
	{
		p=(LINK *)malloc(sizeof(LINK));//开辟空间
		if (p==NULL)//判断空间是否开辟成功
		{
			printf("Wrong\n");
			exit(0);
		}
		if(!ftell(fp))//如果文件指针在头部跳一行
		{
		    fscanf(fp,"%*[^\n]\n");
		}
		if (feof(fp))
		{
			free(header);//删除头节点，完成链表
			free(p);
			return NULL;
		}
		switch(i)
		{
			case 1:
					fscanf(fp,"%d%d%d%d",&p->time.month,&p->time.day,&p->time.hour,&p->time.minute);//读取月日,时间
					fscanf(fp,"%s %s %s",p->name,p->type,p->maker);//读取配件，型号，制造商
					fscanf(fp,"%f %d %f",&p->price,&p->num,&p->sum);//读取进价，数量，总价
					fscanf(fp,"%s\n",p->infor);//读取客户信息
					;break;//进货记录stock.txt//批发sale by bluk.txt//单卖single sale.txt//赠品donation.txt
            case 2:
                    fscanf(fp,"%s %s %s",p->name,p->type,p->maker);//读取配件，型号，制造商
                    fscanf(fp,"%f %d\n",&p->price,&p->num);//读取进价，数量，总价
                    ;break;//库存storage.txt
		}
		tail->next=p;//链接上原有链表
		tail=p;//尾部指针变化
		p->next=NULL;//初始节点内部指针
	}
	p=header->next;//
	free(header);//删除头节点，完成链表
	return p;
}

float print_total_sales (void)
{
	float sales=0;//记录总的销售额
    sales=get_file_sum_date("single sale.txt","r");
    sales+=get_file_sum_date("sale by bulk.txt","r");
    printf("Total sales so far this year have been at:%.2fyuan\n", sales);
    return sales;
}

void print_total_profit (void)
{
	float cost=0;
    cost=get_file_sum_date("stock.txt","r");//记录总的成本
    printf("Total profit so far this year have been at:%.2fyuan\n",print_total_sales()-cost );//销售额减去成本为利润
}

void print_ststus_reporting (void)
{
	FILE* fp=NULL;
	LINK* p=NULL;
	char string[300];
    fp=open("storage.txt","r");
    system("cls");
	p=make_link(fp,2);
	print_info(p);
	fclose(fp);
}

void print_statistic (void)
{
    struct POX pox;
	char key_stastic='s';
	menu_of_statistic(-1);//打印菜单
	pox.x=0;
	pox.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key_stastic=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key_stastic=='\r')
		{
			switch(pox.y-1)
			{
				case 1:print_total_sales();system("pause");break;
				case 2:print_total_profit();system("pause");break;
				case 3:print_ststus_reporting();system("pause");break;
                case 4:system("cls");print_statistic_of_old_data();break;
				case 5:return;
			}
			system("cls");
			menu_of_statistic(-1);
			pox.y--;
			key_stastic='s';
		}
		switch(key_stastic)
		{
			case 'W':
			case 'w':
					if (pox.y!=2)
					{
						setcursorposition(0,pox.y);
						menu_of_statistic(pox.y);
						pox.y--;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu_of_statistic(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key_stastic='0';
					break;
			case 'S':
			case 's':
					if (pox.y!=6)
					{
						setcursorposition(0,pox.y);
						menu_of_statistic(pox.y);
						pox.y++;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu_of_statistic(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key_stastic='0';
					break;
		}
	}
}

void start_menu (void)
{
    struct POX pox;
	char key='s';//初始移动方向
	menu(-1);//打印菜单
	pox.x=0;
	pox.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key=='\r')//判断回车
		{
			switch(pox.y-1)
			{
				case 1: system("cls");buy();system("pause");break;//buy函数放这里
				case 2: system("cls");sell();system("pause");break;//sale函数放这里
				case 3: system("cls");SearchStart();break;//check函数放这里
				case 4: system("cls");StartDelete();break;//delete函数放这里
				case 5: system("cls");print_change_record();break;//add change函数放这里
				case 6: system("cls");print_statistic();break;//财务统计放这里
				case 7: exit(0);
			}
			system("cls");
			menu(-1);
			pox.y--;
			key='s';
		}
		switch(key)
		{
			case 'W':
			case 'w':
					if (pox.y!=2)
					{
						setcursorposition(0,pox.y);
						menu(pox.y);
						pox.y--;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,10);
					key='0';
					break;
			case 'S':
			case 's':
					if (pox.y!=8)
					{
						setcursorposition(0,pox.y);
						menu(pox.y);
						pox.y++;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,10);
					key='0';
					break;
		}
	}
}

int  choose_donation (char info[])//传入客户信息
{
	struct POX pox={0,5};
	LINK* p=NULL;//链表移动指针
	LINK* header=NULL;//链表头指针
	FILE* fp=NULL;
	LINK donation[3];//存储三个赠品信息
	int i=0;
	int poxtion=0;
	int pox_num[3];
	char a[300];//保存第一行数据
	int random=0;//存入随机数
	int key='s';//存入按键信息
	time_t t;
    struct tm * lt;//定义时间结构体指针
	srand((unsigned)time(NULL));//建立随机数种子
    fp=open("storage.txt","r");
	fscanf(fp,"%[^\n]",a);//读取一行到a中
	p=header=make_link(fp,2);//链表制作成功
	fclose(fp);//关闭文件
    int flag=0;
	while(i!=3)
	{
		poxtion=random=rand()%storage_num;//产生随机数
		while(random)
		{
			--random;
			if (p!=NULL)
			{
				p=p->next;/* code */
			}
			if (p==NULL)
			{
				break;
			}
		}
		if ((p->price<100)&&p->num>0)
		{
		    strcpy(donation[i].name,p->name);
		    strcpy(donation[i].type,p->type);
		    strcpy(donation[i].maker,p->maker);
		    pox_num[i]=poxtion;
			++i;
		}
		p=header;
		flag++;
		if (flag==10000)
		{
			printf("对不起库存不足，无法赠送\n");
			return 0;
		}
	}
	for(int i=0;i<3;++i)
    {
        printf("%s %s %s\n",donation[i].name,donation[i].type,donation[i].maker);//打印送出的礼物
    }
	setcursorposition(0,5);
	while(1)
	{
		switch(key)
		{
			case 'w':
			case 'W':
					if (pox.y!=5)
					{
						setcursorposition(0,pox.y);
						printf("%s %s %s \n",donation[pox.y-5].name,donation[pox.y-5].type,donation[pox.y-5].maker);
						set_white_txt();
						--pox.y;
						setcursorposition(0,pox.y);
						printf("%s %s %s \n",donation[pox.y-5].name,donation[pox.y-5].type,donation[pox.y-5].maker);
						set_normal_txt();
						setcursorposition(0,8);
					}
					break;
			case 's':
			case 'S':
					if (pox.y!=7)
					{
						setcursorposition(0,pox.y);
						printf("%s %s %s \n",donation[pox.y-5].name,donation[pox.y-5].type,donation[pox.y-5].maker);
						set_white_txt();
						++pox.y;
						setcursorposition(0,pox.y);
						printf("%s %s %s \n",donation[pox.y-5].name,donation[pox.y-5].type,donation[pox.y-5].maker);
						set_normal_txt();
						setcursorposition(0,8);
					}
					break;
			case'\r':
					i=pox.y-5;
					p=header;
					while(pox_num[i])
					{
						--pox_num[i];
						p=p->next;
					}
					--p->num;
				    time (&t);//获取Unix时间戳。
				    lt = localtime (&t);//转为时间结构。
				    strcpy(p->infor,info);
				    fp=open("single sale.txt","a+");
				    fprintf (fp,"%d %d %d %d  %s   %s   %s   0   1  0     %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,p->infor);//输出结果
				    fclose(fp);
					p=header;
					fp=open("storage.txt","w");
					fprintf(fp,"%s\n",a);//打印第一行
					while(p!=NULL)
					{
						fprintf(fp,"%s          %s         %s        %f       %d\n",p->name,p->type,p->maker,p->price,p->num);//改动文件里的礼物信息
						p=p->next;
					}
					fclose(fp);
					return 1;
		}
		key=get_hit();
	}
	return 0;
}

void print_statistic_of_old_data(void)//打印历史销售记录 (void)
{
    struct POX pox;
    char key_stastic='s';
    menu_of_stastic_second(-1);//打印菜单
    pox.x=0;
    pox.y=0;
    while(1)
    {
        if(_kbhit())//判断是否有按键
        {
            key_stastic=_getch();//将按键赋值给key
            fflush(stdin);//刷新缓冲区
        }
        if(key_stastic=='\r')
        {
            switch(pox.y)
            {
                case 1:system("cls");print_statistic_of_table(1);system("pause");break;
                case 2:system("cls");print_statistic_of_table(2);system("pause");break;
                case 3:return;
            }
            system("cls");
            menu_of_stastic_second(-1);
            pox.y--;
            key_stastic='s';
        }
        switch(key_stastic)
        {
            case 'W':
            case 'w':
                    if (pox.y!=1)
                    {
                        setcursorposition(0,pox.y);
                        menu_of_stastic_second(pox.y);
                        pox.y--;
                        set_white_txt();
                        setcursorposition(0,pox.y);
                        menu_of_stastic_second(pox.y);
                    }
                    set_normal_txt();
                    setcursorposition(0,5);
                    key_stastic='0';
                    break;
            case 'S':
            case 's':
                    if (pox.y!=3)
                    {
                        setcursorposition(0,pox.y);
                        menu_of_stastic_second(pox.y);
                        pox.y++;
                        set_white_txt();
                        setcursorposition(0,pox.y);
                        menu_of_stastic_second(pox.y);
                    }
                    set_normal_txt();
                    setcursorposition(0,5);
                    key_stastic='0';
                    break;
        }
    }
}

void menu_of_stastic_second (int i)
{
    switch(i)
    {
        case -1:printf("*************************************\n");
                printf("********        1.stock      ********\n");
                printf("********        2.sell       ********\n");
                printf("********        3.back       ********\n");
                printf("*************************************\n");
                XiaoHuangRen();
                break;
        case 1:printf("********        1.stock      ********\n");break;
        case 2:printf("********        2.sell       ********\n");break;
        case 3:printf("********        3.back       ********\n");break;
    }
}

void print_statistic_of_table (int i)
{
    struct POX pox;
    struct TIME begin_time={0,0,0,0};
    struct TIME end_time={0,0,0,0};
    float total_times[3]={0,0,0};
    LINK* p=NULL;
    FILE * fp=NULL;
    char key='s';
    printf("请选择所要打印的时间范围\n");
    printf("起始时间，按住w/s进行选择:\n");
    pox.x=0;
    pox.y=2;
    while(1)
    {
        if (choose_time (&begin_time,&pox,&key))
        {
            break;
        }
    }
    printf("结束时间，按住w/s进行选择:\n");
    pox.x=0;
    pox.y=4;
    while(1)
    {
        if (choose_time (&end_time,&pox,&key))
        {
            break;
        }
    }
    pox.y=7;
    pox.x=0;
    if (i==1)
    {
        fp=open("stock.txt","r");
    }
    else if (i==2)
    {
        printf("\n******************零售记录*******************\n");
        pox.y++;
        setcursorposition(0,pox.y);
        fp=open("single sale.txt","r");
    }
    setcursorposition(pox.x,pox.y);
    while(i)
    {
        p=make_link(fp,1);
        fclose(fp);
        total_times[0]=(begin_time.month)*31*24+(begin_time.day)*24+(begin_time.hour)+(begin_time.minute)/60.0;
        total_times[1]=(end_time.month)*31*24+(end_time.day)*24+(end_time.hour)+(end_time.minute)/60.0;
        while(p!=NULL)
        {
            total_times[2]=(p->time.month)*31*24+(p->time.day)*24+(p->time.hour)+(p->time.minute)/60.0;
            if (total_times[0]<=total_times[2]&&total_times[2]<=total_times[1])
            {
                printf("%2d月%2d日%2d时%2d分",p->time.month,p->time.day,p->time.hour,p->time.minute);
            	printf("    配件名称：%s", p->name);
            	setcursorposition(39,pox.y);
            	printf("型号：%s", p->type);
            	setcursorposition(59,pox.y);
            	printf("制造商：%s", p->maker);
            	setcursorposition(79,pox.y);
            	printf("进价：%.2f", p->price);
            	setcursorposition(95,pox.y);
            	printf("数量：%d", p->num);
            	setcursorposition(110,pox.y);
            	printf("总价值：%.2f", p->sum);
            	setcursorposition(125,pox.y);
            	printf("客户信息：%s \n", p->infor);
            	setcursorposition(135,pox.y);
            	pox.y++;
            	setcursorposition(0,pox.y);
            }
            p=p->next;
        }
        --i;//标记-1
        if (i==1)
        {
            printf("\n******************批发记录*******************\n");
            pox.y+=2;
            setcursorposition(0,pox.y);
            fp=open("sale by bulk.txt","r");
        }
    }
}

FILE* open (const char *pstr,const char *pstrMod)
{
    FILE* fp=NULL;
    if ((fp=fopen(pstr,pstrMod))==NULL)//打开文件并判断打开是否成功
    {
        printf("wrong\n");
        exit(0);
    }
    return fp;
}

float get_file_sum_date (const char *pstr,const char *pstrMod)
{
    LINK* header=NULL;//链表头指针
    LINK* p0=NULL;//可以在链表上动的指针
    FILE* fp=NULL;//文件指针
    float data=0;//记录总的销售额
    fp=open(pstr,pstrMod);//打开文件
    header=make_link(fp,1);//生成链表
    p0=header;
    while (p0!=NULL)
    {
        data+=p0->sum;//统计总的进货总数
        p0=p0->next;//指向下一个节点
    }
    fclose(fp);//关闭文件
    return data;
}

int choose_time (struct TIME *ptim,struct POX *p,char *key)
{
    if (_kbhit())
        {
            *key=_getch();
            fflush(stdin);
        }
    if(*key=='\r')
    {
        setcursorposition(p->x,p->y+1);
        fflush(stdin);
        *key='s';
        return 1;
    }
    switch(*key)
        {
            case 'a':
            case 'A':
                if (p->x>0)
                {
                    p->x-=5;
                }
                break;
            case 'd':
            case 'D':
                if(p->x<15)
                {
                    p->x+=5;
                }
                break;
            case 'w':
            case 'W':
                if (p->x==0)
                {
                    if (ptim->month<12)//判断合法月份
                    {
                        ++ptim->month;
                    }
                }
                else if (p->x==5)
                {
                    if (ptim->day<31)//合法天数
                    {
                        ++ptim->day;
                    }
                }
                else if (p->x==10)
                {
                    if (ptim->hour<12)//合法小时
                    {
                        ++ptim->hour;
                    }
                }
                else if (p->x==15)
                {
                    if (ptim->minute<60)//合法分钟
                    {
                        ++ptim->minute;
                    }
                }
                break;
            case 's':
            case 'S':
                if (p->x==0)
                {
                    if (ptim->month>0)//判断合法月份
                    {
                        --ptim->month;
                    }
                }
                else if (p->x==5)
                {
                    if (ptim->day>0)//合法天数
                    {
                        --ptim->day;
                    }
                }
                else if (p->x==10)
                {
                    if (ptim->hour>0)//合法小时
                    {
                        --ptim->hour;
                    }
                }
                else if (p->x==15)
                {
                    if (ptim->minute>0)//合法分钟
                    {
                        --ptim->minute;
                    }
                }
                break;
        }
    if (*key=='w'||*key=='W'||*key=='s'||*key=='S'||*key=='a'||*key=='A'||*key=='d'||*key=='D')
    {
        printf("\r%d月 %d日 %d时 %d分      \n",ptim->month,ptim->day,ptim->hour,ptim->minute);
        setcursorposition(p->x,p->y);
    }
    *key='0';
    return 0;
}

void buy (void)
{
    struct POX pox;
    FILE * fp=NULL;
    LINK *header=NULL;
    LINK *p=NULL;
    int key='s';
    pox.x=0;
    pox.y=0;
    fp=open("storage.txt","r");
    p=header=make_link(fp,2);//创建链表
    fclose(fp);
    print_info(p);
    setcursorposition(0,0);
    while(1)
    {
        switch(key)
        {
            case 'W':
            case 'w':
                    if (pox.y!=0)
                    {
                        print_buy_info(pox.y,p);
                        --pox.y;
                        setcursorposition(0,pox.y);
                        set_white_txt();
                        print_buy_info(pox.y,p);
                        set_normal_txt();
                        //SetConsoleTextAttribute(handle,7);
                        setcursorposition(0,pox.y);
                    }
                    break;
            case 'S':
            case 's':
                    if (pox.y!=storage_num-1)
                    {
                        print_buy_info(pox.y,p);
                        ++pox.y;
                        setcursorposition(0,pox.y);
                        set_white_txt();
                        print_buy_info(pox.y,p);
                        set_normal_txt();
                        //SetConsoleTextAttribute(handle,7);
                        setcursorposition(0,pox.y);
                    }
                    break;
            case '\r':
                    setcursorposition(83,pox.y);
                    int num=0;//初始化购买数量
                    key='w';
                    while(1)
                    {
                        switch(key)
                        {
                            case 'W':
                            case 'w':
                                    ++num;
                                    printf("  +%d   ",num);
                                    setcursorposition(83,pox.y);
                                    break;
                            case 'S':
                            case 's':
                                    if (num!=0)
                                     {
                                        --num;
                                        printf("  +%d   ",num);
                                        setcursorposition(83,pox.y);
                                     }
                                    break;
                            case '\r':
		                            if (num==0)
		                            {
		                            	return;
		                            }
                                    if (money-calc(pox.y,p,num)>0)
                                    {
                                        setcursorposition(83,pox.y);
                                        printf("                                         ");
                                        setcursorposition(83,pox.y);
                                        money-=calc(pox.y,p,num);
                                        write_money();
                                        setcursorposition(83,pox.y);
                                        printf("购买成功，剩余总资产%.2lf",money);
                                    }
                                    else
                                    {
                                    	printf("钱不够了");
                                    	_getch();
                                    	return;
                                    }
                                    change_num(num,p,pox.y);
                                    change_files(p);
                                    setcursorposition(83,pox.y);
                                    printf("                                                                  ");
                                    setcursorposition(83,pox.y);
                                    return;
                        }
                        key='0';
                        key=get_hit();
                    }
                    break;
        }
        key=get_hit();
    }
}

void print_info (LINK *p)
{
    struct POX pox={0,0};
    while(p!=NULL)
    {
        printf("配件名称：%s", p->name);
        setcursorposition(19,pox.y);
        printf("型号：%s", p->type);
        setcursorposition(39,pox.y);
        printf("制造商：%s", p->maker);
        setcursorposition(59,pox.y);
        printf("进价：%.2f", p->price);
        setcursorposition(75,pox.y);
        printf("数量：%d", p->num);
        setcursorposition(85,pox.y);
        pox.y++;
        setcursorposition(0,pox.y);
        p=p->next;
    }
}

void print_buy_info (int num,LINK *p)
{
    struct POX pox={0,0};
    int c=num;
    while(num)
        {
            --num;
            p=p->next;
        }
    printf("配件名称：%-70s", p->name);
    setcursorposition(19,c);
    printf("型号：%s", p->type);
    setcursorposition(39,c);
    printf("制造商：%s", p->maker);
    setcursorposition(59,c);
    printf("进价：%.2f", p->price);
    setcursorposition(75,c);
    printf("库存：%d", p->num);
    setcursorposition(85,c);
}

char get_hit (void)
{
    char key;
    if (_kbhit())
    {
        key=_getch();
        fflush(stdin);
        return key;
    }
    return 0;
}

float calc (int num,LINK* p,int sum)
{
    while(num)
    {
        --num;
        p=p->next;
    }
    return p->price*sum;
}

void change_num(int add,LINK *p,int num)
{
    FILE *fp=NULL;
    time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    while(num)
    {
        --num;
        p=p->next;
    }
    p->num+=add;
    printf("请输入客户信息: ");
    scanf("%s",p->infor);
    fp=open("stock.txt","a+");
    fprintf (fp,"%d %d %d %d  %s   %s   %s   %f   %d   %f    %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,p->price,add,p->price*add,p->infor);//输出结果
    fclose(fp);
}

void change_files(LINK *p)
{
    FILE* fp=NULL;
    char a[300];
    fp=open("storage.txt","r");
    fscanf(fp,"%[^\n]",a);
    fclose(fp);
    fp=open("storage.txt","w");
    fprintf(fp, "%s\n",a);
    while(p!=NULL)
    {
        fprintf(fp, "%s     %s     %s     %f     %d\n",p->name,p->type,p->maker,p->price,p->num);
        p=p->next;
    }
    fclose(fp);
}

void sell (void)
{
	struct POX pox;
    FILE * fp=NULL;
    LINK *header=NULL;
    LINK *p=NULL;
    int key='s';
    pox.x=0;
    pox.y=0;
    fp=open("storage.txt","r");
    p=header=make_link(fp,2);//创建链表
    fclose(fp);
    print_info(p);//打印库存完整信息
    setcursorposition(0,0);
    while(1)
    {
        switch(key)
        {
            case 'W':
            case 'w':
                    if (pox.y!=0)
                    {
                        print_buy_info(pox.y,p);
                        --pox.y;
                        setcursorposition(0,pox.y);
                        set_white_txt();
                        print_buy_info(pox.y,p);
                        set_normal_txt();
                        //SetConsoleTextAttribute(handle,7);
                        setcursorposition(0,pox.y);
                    }
                    break;
            case 'S':
            case 's':
                    if (pox.y!=storage_num-1)
                    {
                        print_buy_info(pox.y,p);
                        ++pox.y;
                        setcursorposition(0,pox.y);
                        set_white_txt();
                        print_buy_info(pox.y,p);
                        set_normal_txt();
                        //SetConsoleTextAttribute(handle,7);
                        setcursorposition(0,pox.y);
                    }
                    break;
            case '\r':
            		system("cls");//清屏
                    key='s';
                    int num=1;//初始化购买数量
                    while(1)//二级子选择，目的是选择销售的数量
                    {
                        switch(key)
                        {
                            case 'W':
                            case 'w':
                            		if (num!=0)
                            		{
                            			++num;
                                    	printf("\r销售%d 商品,按住w/s进行修改    ",num);
                            		}
                                    break;
                            case 'S':
                            case 's':
                                    --num;
                                    printf("\r销售%d 商品,按住w/s进行修改    ",num);
                                    break;
                            case '\r':
		                            if (num==0)
		                            {
		                            	return;
		                            }
                                    if (check_num(pox.y,p,-num))//判断库存是否有做够多的和商品可以卖
                                    {
                                    	printf("\n");
                                    	float price=0;
                                    	int flag=0;
                                    	LINK* mid=p;
                                		int number=pox.y;
                                		while(number)//移动到对应位置
                                		{
                                			--number;
                                			mid=mid->next;
                                		}
                                		price=mid->price;
                                    	while(1)
                                    	{
                                    		printf("\r请选择售价：%.2f, 按住w/s进行选择",price);
                                    		switch(get_hit())
                                    		{
                                    			case'\r':flag=1;
                                    					break;
                                    			case'w':
                                    			case'W':++price;
                                    					break;
                                    			case's':
                                    			case'S':--price;
                                    					break;
                                    		}
                                    		if (flag)
                                    		{
                                    			break;
                                    		}
                                    	}
                                    	printf("\n请输入客户信息: ");
										scanf("%s",mid->infor);
                                    	if (-num>=10||price*(-num)>1000)
                                    	{
                                    		setcursorposition(0,4);
                                    		printf("恭喜你可以获取赠品，赠品三选一\n");
                                    		choose_donation(mid->infor);//随机打印出三个赠品，选择一个库存减一
                                    	}
                                        money-=(price*num);
                                        write_money();
                                        fp=open("storage.txt","r");
    									p=make_link(fp,2);//创建链表
    									fclose(fp);
                                        printf("销售成功,剩余总资产%.2lf\n",money);
                                        change_num_of_sell(num,p,pox.y,price,mid->infor);
                                    	change_files(p);//添加进货记录
                                    }
                                    return;
                        }
                        key='0';
                        key=get_hit();
                    }
                    break;
        }
        key=get_hit();
    }
}

int check_num (int num,LINK* p,int sell_num)
{
	while(num)
	{
		--num;
		p=p->next;
	}
	if ( p->num>=sell_num )
	{
		return 1;
	}
	return 0;
}

void change_num_of_sell(int add,LINK *p,int num,float price,char info[])//num表示在链表中的节点位置
{
	FILE *fp=NULL;
    time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    while(num)//定位当前行
    {
        --num;
        p=p->next;
    }
    p->num+=add;
    strcpy(p->infor,info);
    if (-add>10)//属于批发,(数量大于十)
    {
    	fp=open("sale by bulk.txt","a+");
    	fprintf (fp,"%d %d %d %d  %s   %s   %s   %f   %d   %f   %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,price,-add,price*(-add),p->infor);//输出结果
    }
    else
    {
    fp=open("single sale.txt","a+");
    fprintf (fp,"%d %d %d %d  %s   %s   %s   %f   %d   %f   %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,price,-add,price*(-add),p->infor);//输出结果
    }
	fclose(fp);
}

void get_money (void)
{
	FILE* fp=NULL;
	fp=open("money.txt","r");
	fscanf(fp,"%lf",&money);
	fclose(fp);
}

void write_money (void)
{
	FILE* fp=NULL;
	fp=open("money.txt","w");
	fprintf(fp, "%.2lf",money );
	fclose(fp);
}

void FullScreen()//设置全屏函数，直接调用即可
{
	HWND hwnd=GetForegroundWindow();
	int x=GetSystemMetrics(SM_CXSCREEN)+300,y=GetSystemMetrics(SM_CYSCREEN)+300;
	char setting[30];
	sprintf(setting,"mode con:cols=%d lines=%d",x,y);//设置控制台行数列数
	system(setting);
	SetWindowPos(hwnd, HWND_TOPMOST,0,0,x+300,y+300,0);//置顶
	MoveWindow(hwnd,-10,-40,x+300,y+300,1);//移动
}

void SearchStart()
{
     main_home();
}

void main_home()
{
    char key='s';
	struct POX position;//定义一个结构体变量
	home(-1);//打印菜单
	position.x=0;
	position.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key=='\r')
		{
			switch(position.y-1)
			{
				case 1:system("cls");main_sort_home(1);system("pause");break;     //销售信息查询
				case 2:system("cls");main_sort_home(2);system("pause");break;     //进货信息查询
				case 3:return;
			}
			system("cls");
			home(-1);
			position.y--;
			key='s';
		}
		switch(key)
		{
			case 'W':
			case 'w':
					if (position.y!=2)
					{

						setcursorposition(0,position.y);
						home(position.y);
						position.y--;
						set_white_txt();
						setcursorposition(0,position.y);
						home(position.y);
					}
					set_normal_txt();
					setcursorposition(0,6);
					key='0';
					break;
			case 'S':
			case 's':
					if (position.y!=4)
					{

						setcursorposition(0,position.y);
						home(position.y);
						position.y++;
						set_white_txt();
						setcursorposition(0,position.y);
						home(position.y);
					}
					set_normal_txt();
					setcursorposition(0,6);
					key='0';
					break;
		}
	}
}

void home(int i)
{
    switch(i)
    {
      case -1:printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
              printf("☆☆ choose the selling one or the buying one  ☆☆              ☆☆ press w or s ☆☆\n");
              printf("☆☆                 1.selling                 ☆☆              ☆☆    w:up      ☆☆\n");
              printf("☆☆                 2.buying                  ☆☆              ☆☆    s:up      ☆☆\n");
              printf("☆☆                 3.quit                    ☆☆\n");
              printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
              XiaoHuangRen();
              break;
      case 2: printf("☆☆                 1.selling                 ☆☆\n");break;
      case 3: printf("☆☆                 2.buying                  ☆☆\n");break;
      case 4: printf("☆☆                 3.quit                    ☆☆\n");break;
      case 5: printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");break;
      case 6: printf("☆☆ choose the selling one or the buying one  ☆☆              ☆☆ press w or s ☆☆\n");
    }
}

void main_sort_home(int n)
{
    char key='s';
	struct POX sort_position;//定义一个结构体变量
	sort_home(-1);//打印菜单
	sort_position.x=0;
	sort_position.y=1;
	while(1)
    {   if(_kbhit())//判断是否有按键
		{
			key=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key=='\r')
		{
			switch(sort_position.y-1)
			{
				case 1:system("cls");sort_search_three='a';choose(n);system("pause");break;   //查询配件
				case 2:system("cls");sort_search_three='b';choose(n);system("pause");break;                   //查询制造商
				case 3:system("cls");sort_search_three='c';choose(n);system("pause");break;                    //查询客户信息
				case 4:return;
			}
			system("cls");
			sort_home(-1);
			sort_position.y--;
			key='s';
		}
		switch(key)
		{
			case 'W':
			case 'w':
					if (sort_position.y!=2)
					{

						setcursorposition(0,sort_position.y);
						sort_home(sort_position.y);
						sort_position.y--;
						set_white_txt();
						setcursorposition(0,sort_position.y);
						sort_home(sort_position.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key='0';
					break;
			case 'S':
			case 's':
					if (sort_position.y!=5)
					{

						setcursorposition(0,sort_position.y);
						sort_home(sort_position.y);
						sort_position.y++;
						set_white_txt();
						setcursorposition(0,sort_position.y);
						sort_home(sort_position.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key='0';
					break;
		}
    }

}

void sort_home(int i)
{
    switch(i)
    {
        case -1:printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
                printf("☆☆               -选择查询种类-               ☆☆\n");
                printf("☆☆                   -配件-                   ☆☆               ☆☆ press w or s ☆☆\n");
                printf("☆☆                  -制造商-                  ☆☆               ☆☆       w:up   ☆☆\n");
                printf("☆☆                   -客户-                   ☆☆               ☆☆      s:down  ☆☆\n");
                printf("☆☆                   -返回-                   ☆☆\n");
                printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
                XiaoHuangRen();
                break;
       case 2:  printf("☆☆                   -配件-                   ☆☆\n");break;
       case 3:  printf("☆☆                  -制造商-                  ☆☆\n");break;
       case 4:  printf("☆☆                   -客户-                   ☆☆\n");break;
       case 5:  printf("☆☆                   -返回-                   ☆☆\n");break;
       case 6:  printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");break;
       case 7:  printf("☆☆               -选择查询种类-               ☆☆\n");
    }
}

void choose(int i)
{
    FILE*fp=NULL;
    printf("☆ Please input the name you want to search ☆\n");
    fflush(stdin);//刷新缓冲区
    char name[20];
    scanf("%s",name);//输入查询名字
    LINK *p1,*p2;
    if(i==1)                  //查找销售
    {
        fp=open("sale by bulk.txt","r");      //先查批发
        p1=make_link (fp,1);                                 //用p1存放销售批发的头指针
        printf("☆批发信息：\n");                           //更改“批发信息”的颜色
        search(p1,sort_search_three,name);                //检索
        fclose(fp);
        fp=open("single sale.txt","r");     //零售
        p2=make_link (fp,1);                                  //用p2存放销售零售的头指针
        printf("☆零售信息：\n");
        search(p2,sort_search_three,name);                  //检索
        fclose(fp);
    }
    else
    {
        fp=open("stock.txt","r");            //进货
        p1=make_link (fp,1);
        printf("☆进货信息：\n");
        search(p1,sort_search_three,name);
    }
}

void search(LINK* p,char c,char name[])
{
    int cout=0;
    int boolflag=0;//是否查询到物品
    LINK* header=p;
    if (header==NULL)
    {
    	printf("wrong there is nothing in it\n");
    	return;
    }
    while(boolflag!=1)
    {
    	p=header;
    	switch (c)
	    {
		    case 'a':
		        while(p!=NULL)
		        {
		            while((p!=NULL)&&(strcmp(name,p->name)!=0))          //不同就继续找
		            {
		                p=p->next;
		            }
		            if(p!=NULL)
		            {
		            	boolflag=1;
		                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
		                printf("\n");//打印信息
		                //cout++;      //计算此文件是否有此类信息，没有则通知没有
		                p=p->next;
		            }
		        }
		        if (boolflag==0)
		        {
		        	p=header;
					int num=strcmpr(name,p->name);
					int i=0;
					char str[300];
					strcpy(str,p->name);
					while(p!=NULL)
					{
						i=strcmpr(name,p->name);
						if (i>num)
						{
							strcpy(str,p->name);
							num=i;
						}
						p=p->next;
					}
					printf("你确定你要找的是%s而不是%s吗？(回车键否认，其他键确认)\n",name,str);
					int k=_getch();
					if (k=='\r')
					{
						strcpy(name,str);
					}
					else
					{
						printf("\n☆ There is no information about it ☆\n");//没有信息，提示
						return;
					}
		        }
		        break;
		    case 'b':
		        while(p!=NULL)
		        {
		            while((p!=NULL)&&(strcmp(name,p->maker)!=0))
		            {
		                p=p->next;
		            }
		            if(p!=NULL)
		            {
		            	boolflag=1;
		                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
		                printf("\n");
		               // cout++;     //计算此文件是否有此类信息
		                p=p->next;
		            }

		        }
		        if (boolflag==0)
			    {
			    	p=header;
					int num=strcmpr(name,p->maker);
					int i=0;
					char str[300];
					strcpy(str,p->maker);
					while(p!=NULL)
					{
						i=strcmpr(name,p->maker);
						if (i>num)
						{
							strcpy(str,p->maker);
							num=i;
						}
						p=p->next;
					}
					printf("你确定你要找的是%s而不是%s吗？(回车键否认，其他键确认)\n",name,str);
					int k=_getch();
					if (k=='\r')
					{
						strcpy(name,str);
					}
					else
					{
						printf("\n☆ There is no information about it ☆\n");//没有信息，提示
						return;
					}
			    }
		        break;
		    case 'c':
		        while(p!=NULL)
		        {
		            while((p!=NULL)&&(strcmp(name,p->infor)!=0))
		            {
		                p=p->next;
		            }
		            if(p!=NULL)
		            {
		            	boolflag=1;
		                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
		                printf("\n");
		                //cout++;
		                p=p->next;
		            }
		        }
		        if (boolflag==0)
		        {
		        	p=header;
					int num=strcmpr(name,p->infor);
					int i=0;
					char str[300];
					strcpy(str,p->infor);
					while(p!=NULL)
					{
						i=strcmpr(name,p->infor);
						if (i>num)
						{
							strcpy(str,p->infor);
							num=i;
						}
						p=p->next;
					}
					printf("你确定你要找的是%s而不是%s吗？(回车键否认，其他键确认)\n",name,str);
					int k=_getch();
					if (k=='\r')
					{
						strcpy(name,str);
					}
					else
					{
						printf("\n☆ There is no information about it ☆\n");//没有信息，提示
						return;
					}
		        }
	    }
    }
}

int DeleteMenu1(LINK*p)//整个内容的选择菜单
{
    printf("时间           配件名称          型号        制造商        单价         数量        总价        客户信息\n");
    printf("-点击此处返回-\n");
    int cout=0;
    if(p==NULL)
    {
        printf("-end-");
        return 1;
    }
    while(p!=NULL)
    {
        printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
        p=p->next;
        cout++;
    }
    printf("-end-");
    return cout+1;
}

void StartDelete()
{
    char key='s';
	struct POX pod;//定义一个结构体变量
	StartMenu(-1);//打印菜单
	pod.x=0;
    pod.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key=='\r')//判断回车
		{
			switch(pod.y-1)
			{
				case 1: system("cls");ChooseDeleteInfor(1);system("pause");break;     //1代表销售，2代表零售，3代表进货
				case 2:	system("cls");ChooseDeleteInfor(2);system("pause");break;
				case 3: system("cls");ChooseDeleteInfor(3);system("pause");break;
				case 4: system("cls");del_storage();system("pause");break;
				case 5: return;
			}
			system("cls");
			StartMenu(-1);
			pod.y--;
			key='s';
		}
		switch(key)
		{
			case 'W':
			case 'w':
					if (pod.y!=2)
					{
                        set_normal_txt();
						setcursorposition(0,pod.y);
						StartMenu(pod.y);
						pod.y--;
						set_white_txt();
						setcursorposition(0,pod.y);
						StartMenu(pod.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key='0';
					break;
			case 'S':
			case 's':
					if (pod.y!=6)
					{
					    set_normal_txt();
						setcursorposition(0,pod.y);
						StartMenu(pod.y);
						pod.y++;
						set_white_txt();
						setcursorposition(0,pod.y);
						StartMenu(pod.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key='0';
					break;
		}
	}
}

void StartMenu(int n)
{
    switch(n)
        {case -1:printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
                printf("☆☆              please  choose               ☆☆              ☆☆ press w or s ☆☆\n");
                printf("☆☆                 1.批发                    ☆☆              ☆☆    w:up      ☆☆\n");
                printf("☆☆                 2.零售                    ☆☆              ☆☆    s:up      ☆☆\n");
                printf("☆☆                 3.进货                    ☆☆\n");
                printf("☆☆                 4.库存（小心）             ☆☆\n");
                printf("☆☆                 5.quit                    ☆☆\n");
                printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
                XiaoHuangRen();
                break;
        case 2: printf("☆☆                 1.批发                    ☆☆\n");break;
        case 3: printf("☆☆                 2.零售                    ☆☆\n");break;
        case 4: printf("☆☆                 3.进货                    ☆☆\n");break;
       	case 5:	printf("☆☆                 4.库存（小心）             ☆☆\n");break;
        case 6: printf("☆☆                 5.quit                    ☆☆\n");break;
        }
}

void ChooseDeleteInfor(int n)
{
    char key='s';
	struct POX pod;//定义一个结构体变量
	int i=0;
	FILE*fp=NULL;
	switch(n)
	{
	    case 1:fp=open("sale by bulk.txt","r");
               break;
        case 2:fp=open("single sale.txt","r");
               break;
        case 3:fp=open("stock.txt","r");
               break;
	}
    LINK* p1,*p;
    p1=make_link(fp,1);
    fclose(fp);
    int cout=0;//计算行数
    cout=DeleteMenu1(p1);
    p=p1;
	pod.x=0;
    pod.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key=='\r')//判断回车
		{
		    system("cls");
		    if(pod.y!=1)
               {
                   if(pod.y!=cout+1)
                    p1=Delete(p1,pod.y-1);//删除,pod.y-1为哪一项
                    else
                    cout=DeleteMenu1(p1); //不进行任何操作
               }
			else
                {
                    InputDeleteInfor(p1,n);
                    return;//将修改后的信息写入
                }
            system("pause");
			system("cls");
			cout=DeleteMenu1(p1);
			pod.y--;
			key='s';
		}
		switch(key)
		{
			case 'W':
			case 'w':

                        if(pod.y!=1)
                        {
                            set_normal_txt();
                            setcursorposition(0,pod.y);
                            i=1;
                            p=p1;//p1为文件头指针
                            while(i<pod.y-1)
                            {
                                p=p->next;//找到当前行
                                i++;
                            }
                            if(pod.y!=cout+1)
                                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else
                                printf("-end-");
                            pod.y--;
                            set_white_txt();
                            setcursorposition(0,pod.y);
                            i=2;
                            p=p1;
                            while(i<pod.y)
                            {
                                p=p->next;
                                i++;
                            }
                            if(pod.y!=1)
                                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else
                                printf("-点击此处返回-\n");
                        }

					set_normal_txt();
					setcursorposition(0,pod.y);
					key='0';
					break;
			case 'S':
			case 's':
                        if(pod.y!=cout+1)
                        {
                            set_normal_txt();
                            setcursorposition(0,pod.y);
                            i=1;
                            p=p1;//p1为文件头指针
                            while(i<pod.y-1)
                                {
                                    p=p->next;//找到当前行
                                    i++;
                                }
                            if((pod.y>1)&&(pod.y!=cout+1))
                                    printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else if(pod.y==1)
                                    printf("-点击此处返回-\n");
                            pod.y++;
                            set_white_txt();
                            setcursorposition(0,pod.y);
                            i=2;
                            p=p1;
                            while(i<pod.y)
                            {
                                p=p->next;
                                i++;
                            }
                            if(pod.y!=cout+1)
                                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else
                                printf("-end-");
                        }
                    set_normal_txt();
					setcursorposition(0,pod.y);
					key='0';
					break;
        }
	}
}

LINK* Delete(LINK*p,int n)
{
    int i=1;
    LINK*p0=NULL,*p2=p;
    if(i<n)
    {
        while(i<n)
        {
            p0=p;
            p=p->next;
            i++;
        }
        p0->next=p->next;
        free(p);
        p=p0->next;
        LINK*p3=p2;
        return p2;
    }
    else
    {
        if(p->next!=NULL)
        {
            p0=p;
            p=p->next;
            free(p0);
            return p;
        }
        else
            return NULL;
    }
}

void InputDeleteInfor(LINK*p,int n)
{
    FILE *fp=NULL;
    switch(n)
	{
	    case 1:fp=open("sale by bulk.txt","w");
               break;
        case 2:fp=open("single sale.txt","w");
               break;
        case 3:fp=open("stock.txt","w");
               break;
	}
	char FirstLine1[]="时间           配件名称          型号        制造商        单价         数量        总价        客户信息";
	fprintf(fp,"%s\n",FirstLine1);
        while(p!=NULL)
        {
            fprintf(fp,"%d %d %d %d          ",p->time.month,p->time.day,p->time.hour,p->time.minute);//写取月日,时间
		    fprintf(fp,"%s          %s          %s          ",p->name,p->type,p->maker);//写取配件，型号，制造商
		    fprintf(fp,"%.1f          %d          %.1f  ",p->price,p->num,p->sum);//写取单价，数量，总价
		    fprintf(fp,"%s\n",p->infor);
		    p=p->next;
        }
    fclose(fp);
}

void menu_of_change_record (int num)
{
	switch(num)
	{
		case -1:printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
                printf("☆☆         please  choose                    ☆☆              ☆☆ press w or s ☆☆\n");
                printf("☆☆               1.stock                     ☆☆              ☆☆    w:up      ☆☆\n");
                printf("☆☆               2.single sell               ☆☆              ☆☆    s:up      ☆☆\n");
                printf("☆☆               3.sell by bulk              ☆☆\n");
                printf("☆☆               4.add storage               ☆☆\n");
                printf("☆☆               5.change money              ☆☆\n");
                printf("☆☆               6.quit                      ☆☆\n");
                printf("☆☆☆☆☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆☆☆☆☆\n");
                XiaoHuangRen();
                break;
        case 2: printf("☆☆               1.stock                   ☆☆\n");break;
        case 3: printf("☆☆               2.single sell             ☆☆\n");break;
        case 4: printf("☆☆               3.sell by bulk            ☆☆\n");break;
        case 5: printf("☆☆               4.add storage             ☆☆\n");break;
        case 6: printf("☆☆               5.change money            ☆☆\n");break;
        case 7: printf("☆☆               6.quit                    ☆☆\n");break;
	}
}

void menu_of_addchange_record (int i)
{
    switch(i)
    {
        case -1:printf("☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆\n");
                printf("☆☆     choose change type    ☆☆\n");
                printf("☆☆           1.stock         ☆☆\n");
                printf("☆☆           2.sell          ☆☆\n");
                printf("☆☆           3.back          ☆☆\n");
                printf("☆☆☆☆☆☆☆☆-*-☆☆☆☆☆☆☆☆\n");
                XiaoHuangRen();
                break;
        case 2: printf("☆☆           1.stock         ☆☆\n");break;
        case 3: printf("☆☆           2.sell          ☆☆\n");break;
        case 4: printf("☆☆           3.back          ☆☆\n");break;
    }
}

void print_change_record (void)
{
	char key_stastic='s';
	struct POX pox;//定义一个结构体变量
	menu_of_change_record(-1);//打印菜单
	pox.x=0;
	pox.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key_stastic=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key_stastic=='\r')
		{
			switch(pox.y-1)
			{
				case 1:system("cls");mm=3; ChooseChangeInfor(mm);break;
				case 2:system("cls");mm=2; ChooseChangeInfor(mm);break;
				case 3:system("cls");mm=1; ChooseChangeInfor(mm);break;
				case 4:system("cls");add_storage();break;
				case 5:system("cls");money_storage();break;
				case 6:return;
			}
			system("cls");
			menu_of_change_record(-1);
			pox.y--;
			key_stastic='s';
		}
		switch(key_stastic)
		{
			case 'W':
			case 'w':
					if (pox.y!=2)
					{
						setcursorposition(0,pox.y);
						menu_of_change_record(pox.y);
						pox.y--;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu_of_change_record(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key_stastic='0';
					break;
			case 'S':
			case 's':
					if (pox.y!=7)
					{
						setcursorposition(0,pox.y);
						menu_of_change_record(pox.y);
						pox.y++;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu_of_change_record(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,7);
					key_stastic='0';
					break;
		}
	}
}

void print_addchange_record (void)
{
	char key_stastic='s';
	struct POX pox;//定义一个结构体变量
	menu_of_addchange_record(-1);//打印菜单
	pox.x=0;
	pox.y=1;
	printf("请选择修改成的类型");
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key_stastic=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key_stastic=='\r')
		{
			switch(pox.y-1)
			{
				case 1:system("cls");mm=3;buy();return;//买的函数
				case 2:system("cls");sell();return;//卖
				case 3:return;
			}
			system("cls");
			menu_of_addchange_record(-1);
			pox.y--;
			key_stastic='s';
		}
		switch(key_stastic)
		{
			case 'W':
			case 'w':
					if (pox.y!=2)
					{
						setcursorposition(0,pox.y);
						menu_of_addchange_record(pox.y);
						pox.y--;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu_of_addchange_record(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,6);
					key_stastic='0';
					break;
			case 'S':
			case 's':
					if (pox.y!=4)
					{
						setcursorposition(0,pox.y);
						menu_of_addchange_record(pox.y);
						pox.y++;
						set_white_txt();
						setcursorposition(0,pox.y);
						menu_of_addchange_record(pox.y);
					}
					set_normal_txt();
					setcursorposition(0,6);
					key_stastic='0';
					break;
		}
	}
}

char delete_write(LINK *p)
{
    FILE *fp=NULL;
    FILE *fp1=NULL;
    char a[300];
    char flag='y';
    fp=open("storage.txt","r");//库存
    fscanf(fp,"%[^\n]",a);
    fp1=open("single sale.txt","r");//赠品
    LINK *head=make_link(fp,2);//建立链表改变库存
    LINK *head1=make_link(fp1,1);//建立链表改变赠品
    LINK *l=p;
    LINK *q=NULL;
    q=head;
    fclose(fp1);
    while(q!=NULL)
    {
        if(strcmp(q->name,p->name)==0&&strcmp(q->type,p->type)==0&&strcmp(p->maker,q->maker)==0)//删库存
        {
            if(mm==3)
			{
				if((q->num-p->num)<0)
               	{
                	system("cls");
                	printf("数量不足\n");
                	flag='n';
                	return flag;
               	}
            	else
            		q->num=q->num-p->num;
           	}
           	if(mm==2||mm==1)
            	q->num=q->num+p->num;
                q=q->next;
                break;
        }
        else
	    {
	        q=q->next;
	    }
	}
    if(mm==3)
        money=money+p->sum;
    if(mm==2||mm==1)
        money=money-p->sum;
    write_money();
    q=head;
	fclose(fp);
	add_change_storage(q,1);
	LINK *q01=NULL;
	LINK *q1=NULL;
	LINK *s1=NULL;
	s1=(LINK *)malloc(sizeof(LINK));//开辟空间
	if (s1==NULL)//判断空间是否开辟成功
	{
	    printf("Wrong\n");
	    exit(0);
	}
    s1->next=head1;
    q1=head1;
    q01=s1;
	if(mm==2||mm==1)//将赠品退账
	{
	    while(q1!=NULL)
	    {
	        if(strcmp(q1->infor,p->infor)==0&&q1->price==0&&p->time.day==q1->time.day&&p->time.month==q1->time.month&&q1->time.hour==p->time.hour&&p->time.minute==q1->time.minute)
	        {
	            //printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                LINK *l1=(LINK *)malloc(sizeof(LINK));
                strcpy(l1->name,q1->name);
                strcpy(l1->type,q1->type);
                strcpy(l1->maker,q1->maker);
               if(q1==head1)
               {
                   head1=head1->next;
                   q1=q1->next;
               }
               else
               {
                    q1= q1->next;
                    free(q01->next);
                    q01->next=q1;
               }
                    FILE* fp2=open("storage.txt","r");
                    LINK *head2=make_link(fp2,2);
                    fclose(fp2);
                    LINK *p2=head2;
	            while(p2!=NULL)
	            {
	                if(strcmp(p2->name,l1->name)==0&&strcmp(p2->type,l1->type)==0&&strcmp(p2->maker,l1->maker)==0)
	                {
	                    p2->num=p2->num+1;
	                    p2=p2->next;
	                }
	                else
	                {
	                    p2=p2->next;
	                }
	            }
				p2=head2;
				add_change_storage(p2,1);
	        }
	        else
	        {
               q01=q1;
               q1=q1->next;
	        }
	    }
	}
    q1=head1;
    add_change_storage(q1,2);
    fclose(fp1);
    flag='y';
    return flag;
}

void add_change_storage(LINK *p,int i)
{
    FILE *fp=NULL;
    char a[300];
    if(i==1)
        fp=open("storage.txt","r");//库存
    if(i==2)
        fp=open("single sale.txt","r");
    fscanf(fp,"%[^\n]",a);
    fclose(fp);
    if(i==1)
    {
        fp=open("storage.txt","w");
        fprintf(fp, "%s\n",a);
        while(p!=NULL)
		{
		    fprintf(fp, "%s     %s     %s     %f     %d\n",p->name,p->type,p->maker,p->price,p->num);
		    p=p->next;
		}
    	fclose(fp);
	}
    if(i==2)
    {
        fp=open("single sale.txt","w");
        fprintf(fp, "%s\n",a);
	    while(p!=NULL)
	    {
	        fprintf(fp, "%d    %d    %d    %d    %s     %s     %s     %f     %d   %f     %s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
	        p=p->next;
	    }
    	fclose(fp);
	}
}

void ChooseChangeInfor(int n)
{
    char key='s';
	struct POX pod;//定义一个结构体变量
	int i=0;
	char flag='y';
	FILE*fp=NULL;
	switch(n)
	{
	    case 1:fp=open("sale by bulk.txt","r");
               break;
        case 2:fp=open("single sale.txt","r");
               break;
        case 3:fp=open("stock.txt","r");
               break;
	}
    LINK* p1,*p;
    p1=make_link(fp,1);
    fclose(fp);
    int cout=0;//计算行数
    cout=DeleteMenu1(p1);
    p=p1;
	pod.x=0;
    pod.y=1;
	while(1)
	{
		if(_kbhit())//判断是否有按键
		{
			key=_getch();//将按键赋值给key
			fflush(stdin);//刷新缓冲区
		}
		if(key=='\r'&&pod.y==1)
		{
            return;
		}
		if(key=='\r'&&pod.y!=1)//判断回车
		{
                int i=2;
                LINK *p0=p1;
                while(i<pod.y)
                {
                  p0=p0->next;
                  i++;
                }
                flag=delete_write(p0);
                if(flag=='y')
                {
                    p1=Delete(p1,pod.y-1);
                    InputDeleteInfor(p1,n);
                    setcursorposition(83,pod.y);
                    printf("                                         ");
                    setcursorposition(83,pod.y);
                    printf("退账成功，剩余总资产%.2lf",money);
                    system("pause");
                    system("cls");
                    print_addchange_record();
                }
                //printf("%c",flag);
                system("pause");
                if(flag=='n')
                {
                     printf("退账失败");
                     system("pause");
                }
                system("cls");
			    key='s';
                flag='y';
                break;
            }
		switch(key)
		{
			case 'W':
			case 'w':

                        if(pod.y!=1)
                        {
                           set_normal_txt();
                            setcursorposition(0,pod.y);
                            i=1;
                            p=p1;//p1为文件头指针
                            while(i<pod.y-1)
                            {
                                p=p->next;//找到当前行
                                i++;
                            }
                            printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            pod.y--;
                            set_white_txt();
                            setcursorposition(0,pod.y);
                            i=2;
                            p=p1;
                            while(i<pod.y)
                            {
                                p=p->next;
                                i++;
                            }
                            if(pod.y!=1)
                                printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else
                                printf("-点击此处返回-");
                        }

					set_normal_txt();
					setcursorposition(0,5);
					key='0';
					break;
			case 'S':
			case 's':
                        if(pod.y!=cout)
                        {
                            set_normal_txt();
                            setcursorposition(0,pod.y);
                            i=1;
                            p=p1;//p1为文件头指针
                            while(i<pod.y-1)
                                {
                                    p=p->next;//找到当前行
                                    i++;
                                }
                            if(pod.y!=1)
                                    printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                                else
                                    printf("-点击此处返回-");
                            pod.y++;
                            set_white_txt();
                            setcursorposition(0,pod.y);
                            i=2;
                            p=p1;
                            while(i<pod.y)
                            {
                                p=p->next;
                                i++;
                            }
                            printf("时间:%d %d %d %d 配件:%10s 型号:%10s 制造商:%10s 单价:%5f 数量:%5d 总价:%5f 客户信息:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                        }
                    set_normal_txt();
					setcursorposition(0,5);
					key='0';
					break;
        }
	}
}


void XiaoHuangRen()
{
    int x=15,y=12;
    for(x=15;x<180;x=x+35)
    {
        setcursorposition(x,y);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf(" ■   ■   ■");
        setcursorposition(x-3,y+1);
        printf("■  ■   ■   ■   ■");
        setcursorposition(x-2,y+2);
        printf("■  ■  ■  ■  ■");
        setcursorposition(x-6,y+3);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■■■■■■■■■■■■■");
        setcursorposition(x-7,y+4);
        printf("■■■■■■■■■■■■■■");
        setcursorposition(x-9,y+5);
        for(int i=0;i<2;i++)
        {
            printf("■■");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■■■■■");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        }
        printf("■■");         //眼镜上边
        setcursorposition(x-9,y+6);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■");
        for(int i=0;i<2;i++)
        {
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■");
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■■■■■");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■");
        }
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■");                          //眼镜第二行


        ///////////////////
        for(int j=0;j<2;j++)
        {
            setcursorposition(x-8,y+7+j);
            printf(" ");
           SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
           for(int i=0;i<2;i++)
           {
            printf("■");
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■■      ");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■");
           }
        } //眼睛
        ////////////////


        setcursorposition(x-9,y+9);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■");
        for(int i=0;i<2;i++)
        {
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■");
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■■■■■");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■");
        }
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■");
        setcursorposition(x-9,y+10);
        for(int i=0;i<2;i++)
        {
            printf("■■");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("■■■■■");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        }
        printf("■■");
        //眼睛全部打完！

        //开始打嘴巴
        setcursorposition(x-9,y+11);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■■■■■■■■■■■■■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("  ■  ■");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        setcursorposition(x-9,y+12);
        printf("■■■■■  ■■■■  ■■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("    ■ ");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        setcursorposition(x-9,y+13);
        printf("■■■■■■  ■■  ■■■■■■");
        printf("    ■ ");
        setcursorposition(x-9,y+14);
        printf("■■■■■■■    ■■■■■■■");
        printf("    ■ ");
        //脸打完蜡


        //背带裤！
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        setcursorposition(x-9,y+15);
        printf("■■■■■■■■■■■■■■■■");//背带裤第一行

        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("  ■ ");
        setcursorposition(x-11,y+16);
        printf("■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■■■■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■■■■");
         //背带裤第二行

        setcursorposition(x-13,y+17);
        printf("■  ■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■");
        SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
        printf("■■■■■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■■");
        //背带裤第三行

        setcursorposition(x-15,y+18);
        printf("■    ■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
        printf("■■■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("■");
        //背带裤第四行

        setcursorposition(x-13,y+19);
        printf("■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
        printf("■■■■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■■■");
        //背带裤第五行

        setcursorposition(x-11,y+20);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("■");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■■■■■■■■■■■■■");
        //背带裤第六行

        setcursorposition(x-7,y+21);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■■■■■■■■■■■");
        //背带裤第七行

        setcursorposition(x-5,y+22);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■■■■■■■■■■");
        //背带裤第八行

        setcursorposition(x-2,y+23);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("■■■      ■■■");
        //腿1

        setcursorposition(x-2,y+24);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("■■■      ■■■");
        setcursorposition(x-2,y+25);
        printf("■■■      ■■■");
        //腿2,3

        setcursorposition(x-2,y+26);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("■■■■    ■■■■");
        //脚
    }
    set_normal_txt();
}

void add_storage (void)
{
	FILE* fp=NULL;
	fp=open("storage.txt","a+");
	fflush(stdin);
	char str[100]={'\0'};
	float price;
	int flag=0;
	printf("请输入配件名称\n");
	scanf("%[^\n]",str);
	for (int i = 0; *(str+i)!='\0'; ++i)
	{
		if (*(str+i)==' ')
		{
			*(str+i)='_';
		}
	}
	if (*str!='\0')
	{
		fprintf(fp,"%s  ",str);
	}
	else
		return;
	printf("请输入型号\n");
	fflush(stdin);
	scanf("%[^\n]",str);
	for (int i = 0; *(str+i)!='\0'; ++i)
	{
		if (*(str+i)==' ')
		{
			*(str+i)='_';
		}
	}
	if (*str!='\0')
	{
		fprintf(fp,"%s  ",str);
	}
	else
		return;
	printf("请输入制造商\n");
	fflush(stdin);
	scanf("%[^\n]",str);
	for (int i = 0; *(str+i)!='\0'; ++i)
	{
		if (*(str+i)==' ')
		{
			*(str+i)='_';
		}
	}
	if (*str!='\0')
	{
		fprintf(fp,"%s  ",str);
	}
	else
		return;
	while(1)
	{
		printf("\r请选择售价：%.2f, 按住w/s(Q加速增,E加速减,N与M调整小数,O与P小数加速)",price);
		switch(get_hit())
		{
			case'\r':flag=1;
					break;
			case'w':
			case'W':++price;
					break;
			case's':
			case'S':--price;
					break;
			case'q':
			case'Q':price+=100;
					break;
			case'e':
			case'E':price-=100;
					break;
			case'n':
			case'N':price+=0.01;
					break;
			case'm':
			case'M':price-=0.01;
					break;
			case'o':
			case'O':price+=0.1;
					break;
			case'p':
			case'P':price-=0.1;
					break;
		}
		if (flag)
		{
			break;
		}
	}
	fprintf(fp,"%.2f  ",price);
	fprintf(fp, "%d ",0);
	fclose(fp);
	num_of_storage();
}

void num_of_storage (void)
{
	LINK* p=NULL;
	FILE* fp=NULL;
	fp=open("storage.txt","r");
	p=make_link(fp,2);
	int num=0;
	while(p!=NULL)
	{
		++num;
		p=p->next;
	}
	storage_num=num;
}

void del_storage (void)
{
	struct POX pox={0,0};
	FILE* fp=NULL;
	LINK* p=NULL;
	LINK* p0=NULL;
	LINK* header=NULL;
	int k;
	int key='s';
	fp=open("storage.txt","r");
	header=p=make_link(fp,2);
	fclose(fp);
	setcursorposition(0,0);
	print_info(header);
	setcursorposition(0,0);
	while(1)
	{
		switch(key)
		{
			case'w':
			case'W':
					if (pox.y!=0)
                    {
                        print_buy_info(pox.y,p);
                        --pox.y;
                        setcursorposition(0,pox.y);
                        set_white_txt();
                        print_buy_info(pox.y,p);
                        set_normal_txt();
                        //SetConsoleTextAttribute(handle,7);
                        setcursorposition(0,pox.y);
                    }
					break;
			case's':
			case'S':
					if (pox.y!=storage_num-1)
                    {
                        print_buy_info(pox.y,p);
                        ++pox.y;
                        setcursorposition(0,pox.y);
                        set_white_txt();
                        print_buy_info(pox.y,p);
                        set_normal_txt();
                        //SetConsoleTextAttribute(handle,7);
                        setcursorposition(0,pox.y);
                    }
					break;
			case'\r':
					k=pox.y;
					while(k)
					{
						--k;
						p0=p;
						p=p->next;
					}
					if (p->num==0)
					{
						p=p->next;
						free(p0->next);
						p0->next=p;
						change_files(header);
						num_of_storage();
						return;
					}
					else
					{
						system("cls");
						printf("对不起目前你还无法删除库存\n");
						return;
					}
		}
		key=get_hit();
	}
}


int calcsize (char * p)
{
	int size=0;
	while((*p)!='\0')
	{
		size+=(int)*p;
		p++;
	}
	return size;
}

int strcmpr(char* p0,char* p)
{
    int i=0;
	while(*p0!='\0'&&*p!='\0')
	{
		if (*p0==*p)
		{
			++i;
		}
		p0++;
		p++;
	}
	return i;
}


void money_storage (void)
{
	get_money();
	double i=money;
	char key='w';
	while(1)
	{
		printf("\r请按w/s(Q/E加速，减速||N/M修改小数)修改钱%.2lf    ",i);
		switch(key)
		{
			case 'W':
			case 'w':++i;
					break;
			case 'S':
			case 's':--i;
					break;
			case 'Q':
			case 'q':i+=100;
					break;
			case 'E':
			case 'e':i-=100;
					break;
			case 'N':
			case 'n':i+=0.01;
					break;
			case 'M':
			case 'm':i-=0.01;
					break;
			case '\r':
					money=i;
					write_money();
					return;
		}
		key=get_hit();
	}
}
