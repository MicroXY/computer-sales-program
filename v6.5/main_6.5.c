/*
* @Author: Administrator
* @Date:   2019-03-15 08:14:24
* @Last Modified by:   22486
* @Last Modified time: 2019-05-04 21:29:08
*/

//////////////////////////����ͷ�ļ�//////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
/////////////////////////////////////////////////////////////////
//////////////////////////ȫ�ֱ���//////////////////////////////
typedef struct link LINK;//�������ṹ��
HANDLE handle;//���
double money;//��¼���ʲ�
char sort_search_three;//ѡ����
int mm;//ѡ����
int storage_num=0;
///////////////////////////////////////////////////////////////
///
/////////////////////////���ݽṹ//////////////////////////////
struct POX//���ɹ��λ�ýṹ
{
	int x;
	int y;
};//����һ���ṹ�����,����������
struct TIME//����ʱ��ṹ
{
	int month;
	int day;
	int hour;
	int minute;
};
struct link//�����������ݽṹ
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
/////////////////////////������������//////////////////////////
///
//////////////////////////MXQ
void menu (int num);//��ӡ��ʼ����
void start_menu (void);//��ʼ��������
void menu_of_statistic (int num);//ͳ��ģ��ui
void menu_of_stastic_second (int i);//���ۼ�¼�����˵�
void print_info (LINK *p);//���б���ʽ��ӡ������ͺţ���������Ϣ
void print_buy_info (int num,LINK *p);//��ӡ������Ϣ
void print_statistic (void);//��ӡ����ͳ��
float print_total_sales (void);//ͳ�������۶�
void print_total_profit (void);//��ӯ����
void print_statistic_of_table (int i);//��ӡ������
void print_statistic_of_sell (void);//��ӡ�����۱�
void print_ststus_reporting (void);//��汨��
void print_statistic_of_old_data (void);//��ӡ��ʷ���ۼ�¼
int choose_donation (char info[]);//��Ʒѡ��
void change_num(int num,LINK* p,int);//�ı�������ĳһ�ڵ�Ŀ�����������Ѽ�¼�����stock.txt�д浵
int check_num (int num,LINK* p,int sell_num);//�����Ҫ���۵������Ƿ��㹻���ۣ�������1�����򷵻�0
void change_files(LINK* p);//�޸�storage.txt���������ֵ
void change_num_of_sell(int add,LINK *p,int num,float price,char info[]);
char get_hit (void);//��ȡ�����û�����ֵ
void get_money (void);
void write_money (void);
float get_file_sum_date (const char *pstr,const char *pstrMod);//����sumֵ
void buy (void);//����������
void sell (void);//����������
float calc (int num,LINK* p,int sum);//����������ĳһ�����ܼ�������������*����
FILE* open (const char *pstr,const char *pstrMod);//���ļ�
void FullScreen(void);//ȫ������
LINK* make_link (FILE* fp,int i);//��������
int choose_time (struct TIME *ptim,struct POX *p,char *key);//ʱ��ѡ������x��x��xʱx��-----��x��x��xʱx��
void setcursorposition(int x,int y);//���ù��λ��
void SearchStart();//��������������
void choose(int i);//ѡ����
void search(LINK*,char,char search[]);//������Ϣ����
void home(int);//����ѡ���ѯ���ͽ�����桶һ�����桷
void main_home();//check()����������
void main_sort_home(int);//
void sort_home(int);//���������桷
void XiaoHuangRen();//С����
void StartMenu(int n);//��ʼ�˵�
void StartDelete();//��ʼɾ��
void ChooseDeleteInfor(int);//ѡ��ɾ������
LINK* Delete(LINK*,int);//ɾ���ڵ�
void InputDeleteInfor(LINK*,int);//�޸���Ϣ
int DeleteMenu1(LINK*);//ɾ���˵�
void menu_of_change_record (int num);
void print_change_record (void);//��ӡ�޸ļ�¼
void print_addchange_record (void);//��ӡ��Ӽ�¼
char delete_write(LINK *p);//ɾ���ļ�����д�ļ�
void add_change_storage(LINK *p,int i);//����޸�
void ChooseChangeInfor(int n);//ѡ���޸���Ϣ
void set_white_txt (void);//���ð�ɫ�ı�
void set_normal_txt (void);//�ָ��ı�
void add_storage (void);//��ӿ��
void num_of_storage (void);//��ȡ�������
void del_storage (void);//���ɾ������
int strcmpr(char* p0,char* p);//
int calcsize (char * p);
void money_storage (void);
///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////����ʵ�ֲ���///////////////////////////////////
int main()
{
	//system("chcp 65001");//����utf-8����
	//setcursorposition(0,0);//���ص�ԭ��
	FullScreen();
	get_money();
	num_of_storage ();
    handle=GetStdHandle(STD_OUTPUT_HANDLE);//����Ĳ���
	start_menu();//���뿪ʼ����
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
	COORD coord;//���λ�ýṹ��
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition (handle,coord);//���ù��λ��
}

void menu (int num)
{
	switch(num)
	{
		case -1:printf("*************************************************            *****************\n");
			   printf("*****Computer accessories management system******              press: 'W'or'S  \n");
			   printf("*****          1.buy                       ******                   UP:'W'     \n");//����//����
			   printf("*****          2.sale                      ******                   DOWN:'S'   \n");//����
			   printf("*****          3.check information         ******             *****************\n");//��Ϣ��ѯ
			   printf("*****          4.delete information        ******\n");//ɾ����Ϣ
			   printf("*****          5.change information        ******\n");//����һ����Ϣ
			   printf("*****          6.financial statsaistics    ******\n");//����ͳ��
			   printf("*****          7.exit                      ******\n");//�˳�
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
			   printf("*******        1.total sales              *******             press: 'W'or'S  \n");//�����ܶ�
			   printf("*******        2.benefit                  *******                  UP:'W'     \n");//ӯ/����
			   printf("*******        3.status reporting         *******                  DOWN:'S'   \n");//��ǰ��汨��
               printf("*******        4.statisyic of data        *******            *****************\n");//������һ��
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

LINK* make_link (FILE* fp,int i)//�������֣���ӡ����������,������ͷָ��
{
	LINK *p=NULL;//�м����ָ��
	LINK *header=NULL;//ͷ�ڵ�ָ��
	LINK *tail=NULL;//β�ڵ�ָ��
	p=(LINK*)malloc(sizeof(LINK));
	if (p==NULL)//�жϿռ��Ƿ񿪱ٳɹ�
	{
		printf("Wrong\n");
		exit(0);
	}
	p->next=NULL;//��ʼ��ͷ�ڵ������ڲ�ָ��
	header=p;
	tail=p;
	while(!feof(fp))//ѭ����������ռ�
	{
		p=(LINK *)malloc(sizeof(LINK));//���ٿռ�
		if (p==NULL)//�жϿռ��Ƿ񿪱ٳɹ�
		{
			printf("Wrong\n");
			exit(0);
		}
		if(!ftell(fp))//����ļ�ָ����ͷ����һ��
		{
		    fscanf(fp,"%*[^\n]\n");
		}
		if (feof(fp))
		{
			free(header);//ɾ��ͷ�ڵ㣬�������
			free(p);
			return NULL;
		}
		switch(i)
		{
			case 1:
					fscanf(fp,"%d%d%d%d",&p->time.month,&p->time.day,&p->time.hour,&p->time.minute);//��ȡ����,ʱ��
					fscanf(fp,"%s %s %s",p->name,p->type,p->maker);//��ȡ������ͺţ�������
					fscanf(fp,"%f %d %f",&p->price,&p->num,&p->sum);//��ȡ���ۣ��������ܼ�
					fscanf(fp,"%s\n",p->infor);//��ȡ�ͻ���Ϣ
					;break;//������¼stock.txt//����sale by bluk.txt//����single sale.txt//��Ʒdonation.txt
            case 2:
                    fscanf(fp,"%s %s %s",p->name,p->type,p->maker);//��ȡ������ͺţ�������
                    fscanf(fp,"%f %d\n",&p->price,&p->num);//��ȡ���ۣ��������ܼ�
                    ;break;//���storage.txt
		}
		tail->next=p;//������ԭ������
		tail=p;//β��ָ��仯
		p->next=NULL;//��ʼ�ڵ��ڲ�ָ��
	}
	p=header->next;//
	free(header);//ɾ��ͷ�ڵ㣬�������
	return p;
}

float print_total_sales (void)
{
	float sales=0;//��¼�ܵ����۶�
    sales=get_file_sum_date("single sale.txt","r");
    sales+=get_file_sum_date("sale by bulk.txt","r");
    printf("Total sales so far this year have been at:%.2fyuan\n", sales);
    return sales;
}

void print_total_profit (void)
{
	float cost=0;
    cost=get_file_sum_date("stock.txt","r");//��¼�ܵĳɱ�
    printf("Total profit so far this year have been at:%.2fyuan\n",print_total_sales()-cost );//���۶��ȥ�ɱ�Ϊ����
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
	menu_of_statistic(-1);//��ӡ�˵�
	pox.x=0;
	pox.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key_stastic=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
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
	char key='s';//��ʼ�ƶ�����
	menu(-1);//��ӡ�˵�
	pox.x=0;
	pox.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key=='\r')//�жϻس�
		{
			switch(pox.y-1)
			{
				case 1: system("cls");buy();system("pause");break;//buy����������
				case 2: system("cls");sell();system("pause");break;//sale����������
				case 3: system("cls");SearchStart();break;//check����������
				case 4: system("cls");StartDelete();break;//delete����������
				case 5: system("cls");print_change_record();break;//add change����������
				case 6: system("cls");print_statistic();break;//����ͳ�Ʒ�����
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

int  choose_donation (char info[])//����ͻ���Ϣ
{
	struct POX pox={0,5};
	LINK* p=NULL;//�����ƶ�ָ��
	LINK* header=NULL;//����ͷָ��
	FILE* fp=NULL;
	LINK donation[3];//�洢������Ʒ��Ϣ
	int i=0;
	int poxtion=0;
	int pox_num[3];
	char a[300];//�����һ������
	int random=0;//���������
	int key='s';//���밴����Ϣ
	time_t t;
    struct tm * lt;//����ʱ��ṹ��ָ��
	srand((unsigned)time(NULL));//�������������
    fp=open("storage.txt","r");
	fscanf(fp,"%[^\n]",a);//��ȡһ�е�a��
	p=header=make_link(fp,2);//���������ɹ�
	fclose(fp);//�ر��ļ�
    int flag=0;
	while(i!=3)
	{
		poxtion=random=rand()%storage_num;//���������
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
			printf("�Բ����治�㣬�޷�����\n");
			return 0;
		}
	}
	for(int i=0;i<3;++i)
    {
        printf("%s %s %s\n",donation[i].name,donation[i].type,donation[i].maker);//��ӡ�ͳ�������
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
				    time (&t);//��ȡUnixʱ�����
				    lt = localtime (&t);//תΪʱ��ṹ��
				    strcpy(p->infor,info);
				    fp=open("single sale.txt","a+");
				    fprintf (fp,"%d %d %d %d  %s   %s   %s   0   1  0     %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,p->infor);//������
				    fclose(fp);
					p=header;
					fp=open("storage.txt","w");
					fprintf(fp,"%s\n",a);//��ӡ��һ��
					while(p!=NULL)
					{
						fprintf(fp,"%s          %s         %s        %f       %d\n",p->name,p->type,p->maker,p->price,p->num);//�Ķ��ļ����������Ϣ
						p=p->next;
					}
					fclose(fp);
					return 1;
		}
		key=get_hit();
	}
	return 0;
}

void print_statistic_of_old_data(void)//��ӡ��ʷ���ۼ�¼ (void)
{
    struct POX pox;
    char key_stastic='s';
    menu_of_stastic_second(-1);//��ӡ�˵�
    pox.x=0;
    pox.y=0;
    while(1)
    {
        if(_kbhit())//�ж��Ƿ��а���
        {
            key_stastic=_getch();//��������ֵ��key
            fflush(stdin);//ˢ�»�����
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
    printf("��ѡ����Ҫ��ӡ��ʱ�䷶Χ\n");
    printf("��ʼʱ�䣬��סw/s����ѡ��:\n");
    pox.x=0;
    pox.y=2;
    while(1)
    {
        if (choose_time (&begin_time,&pox,&key))
        {
            break;
        }
    }
    printf("����ʱ�䣬��סw/s����ѡ��:\n");
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
        printf("\n******************���ۼ�¼*******************\n");
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
                printf("%2d��%2d��%2dʱ%2d��",p->time.month,p->time.day,p->time.hour,p->time.minute);
            	printf("    ������ƣ�%s", p->name);
            	setcursorposition(39,pox.y);
            	printf("�ͺţ�%s", p->type);
            	setcursorposition(59,pox.y);
            	printf("�����̣�%s", p->maker);
            	setcursorposition(79,pox.y);
            	printf("���ۣ�%.2f", p->price);
            	setcursorposition(95,pox.y);
            	printf("������%d", p->num);
            	setcursorposition(110,pox.y);
            	printf("�ܼ�ֵ��%.2f", p->sum);
            	setcursorposition(125,pox.y);
            	printf("�ͻ���Ϣ��%s \n", p->infor);
            	setcursorposition(135,pox.y);
            	pox.y++;
            	setcursorposition(0,pox.y);
            }
            p=p->next;
        }
        --i;//���-1
        if (i==1)
        {
            printf("\n******************������¼*******************\n");
            pox.y+=2;
            setcursorposition(0,pox.y);
            fp=open("sale by bulk.txt","r");
        }
    }
}

FILE* open (const char *pstr,const char *pstrMod)
{
    FILE* fp=NULL;
    if ((fp=fopen(pstr,pstrMod))==NULL)//���ļ����жϴ��Ƿ�ɹ�
    {
        printf("wrong\n");
        exit(0);
    }
    return fp;
}

float get_file_sum_date (const char *pstr,const char *pstrMod)
{
    LINK* header=NULL;//����ͷָ��
    LINK* p0=NULL;//�����������϶���ָ��
    FILE* fp=NULL;//�ļ�ָ��
    float data=0;//��¼�ܵ����۶�
    fp=open(pstr,pstrMod);//���ļ�
    header=make_link(fp,1);//��������
    p0=header;
    while (p0!=NULL)
    {
        data+=p0->sum;//ͳ���ܵĽ�������
        p0=p0->next;//ָ����һ���ڵ�
    }
    fclose(fp);//�ر��ļ�
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
                    if (ptim->month<12)//�жϺϷ��·�
                    {
                        ++ptim->month;
                    }
                }
                else if (p->x==5)
                {
                    if (ptim->day<31)//�Ϸ�����
                    {
                        ++ptim->day;
                    }
                }
                else if (p->x==10)
                {
                    if (ptim->hour<12)//�Ϸ�Сʱ
                    {
                        ++ptim->hour;
                    }
                }
                else if (p->x==15)
                {
                    if (ptim->minute<60)//�Ϸ�����
                    {
                        ++ptim->minute;
                    }
                }
                break;
            case 's':
            case 'S':
                if (p->x==0)
                {
                    if (ptim->month>0)//�жϺϷ��·�
                    {
                        --ptim->month;
                    }
                }
                else if (p->x==5)
                {
                    if (ptim->day>0)//�Ϸ�����
                    {
                        --ptim->day;
                    }
                }
                else if (p->x==10)
                {
                    if (ptim->hour>0)//�Ϸ�Сʱ
                    {
                        --ptim->hour;
                    }
                }
                else if (p->x==15)
                {
                    if (ptim->minute>0)//�Ϸ�����
                    {
                        --ptim->minute;
                    }
                }
                break;
        }
    if (*key=='w'||*key=='W'||*key=='s'||*key=='S'||*key=='a'||*key=='A'||*key=='d'||*key=='D')
    {
        printf("\r%d�� %d�� %dʱ %d��      \n",ptim->month,ptim->day,ptim->hour,ptim->minute);
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
    p=header=make_link(fp,2);//��������
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
                    int num=0;//��ʼ����������
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
                                        printf("����ɹ���ʣ�����ʲ�%.2lf",money);
                                    }
                                    else
                                    {
                                    	printf("Ǯ������");
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
        printf("������ƣ�%s", p->name);
        setcursorposition(19,pox.y);
        printf("�ͺţ�%s", p->type);
        setcursorposition(39,pox.y);
        printf("�����̣�%s", p->maker);
        setcursorposition(59,pox.y);
        printf("���ۣ�%.2f", p->price);
        setcursorposition(75,pox.y);
        printf("������%d", p->num);
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
    printf("������ƣ�%-70s", p->name);
    setcursorposition(19,c);
    printf("�ͺţ�%s", p->type);
    setcursorposition(39,c);
    printf("�����̣�%s", p->maker);
    setcursorposition(59,c);
    printf("���ۣ�%.2f", p->price);
    setcursorposition(75,c);
    printf("��棺%d", p->num);
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
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    while(num)
    {
        --num;
        p=p->next;
    }
    p->num+=add;
    printf("������ͻ���Ϣ: ");
    scanf("%s",p->infor);
    fp=open("stock.txt","a+");
    fprintf (fp,"%d %d %d %d  %s   %s   %s   %f   %d   %f    %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,p->price,add,p->price*add,p->infor);//������
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
    p=header=make_link(fp,2);//��������
    fclose(fp);
    print_info(p);//��ӡ���������Ϣ
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
            		system("cls");//����
                    key='s';
                    int num=1;//��ʼ����������
                    while(1)//������ѡ��Ŀ����ѡ�����۵�����
                    {
                        switch(key)
                        {
                            case 'W':
                            case 'w':
                            		if (num!=0)
                            		{
                            			++num;
                                    	printf("\r����%d ��Ʒ,��סw/s�����޸�    ",num);
                            		}
                                    break;
                            case 'S':
                            case 's':
                                    --num;
                                    printf("\r����%d ��Ʒ,��סw/s�����޸�    ",num);
                                    break;
                            case '\r':
		                            if (num==0)
		                            {
		                            	return;
		                            }
                                    if (check_num(pox.y,p,-num))//�жϿ���Ƿ���������ĺ���Ʒ������
                                    {
                                    	printf("\n");
                                    	float price=0;
                                    	int flag=0;
                                    	LINK* mid=p;
                                		int number=pox.y;
                                		while(number)//�ƶ�����Ӧλ��
                                		{
                                			--number;
                                			mid=mid->next;
                                		}
                                		price=mid->price;
                                    	while(1)
                                    	{
                                    		printf("\r��ѡ���ۼۣ�%.2f, ��סw/s����ѡ��",price);
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
                                    	printf("\n������ͻ���Ϣ: ");
										scanf("%s",mid->infor);
                                    	if (-num>=10||price*(-num)>1000)
                                    	{
                                    		setcursorposition(0,4);
                                    		printf("��ϲ����Ի�ȡ��Ʒ����Ʒ��ѡһ\n");
                                    		choose_donation(mid->infor);//�����ӡ��������Ʒ��ѡ��һ������һ
                                    	}
                                        money-=(price*num);
                                        write_money();
                                        fp=open("storage.txt","r");
    									p=make_link(fp,2);//��������
    									fclose(fp);
                                        printf("���۳ɹ�,ʣ�����ʲ�%.2lf\n",money);
                                        change_num_of_sell(num,p,pox.y,price,mid->infor);
                                    	change_files(p);//��ӽ�����¼
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

void change_num_of_sell(int add,LINK *p,int num,float price,char info[])//num��ʾ�������еĽڵ�λ��
{
	FILE *fp=NULL;
    time_t t;
    struct tm * lt;
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    while(num)//��λ��ǰ��
    {
        --num;
        p=p->next;
    }
    p->num+=add;
    strcpy(p->infor,info);
    if (-add>10)//��������,(��������ʮ)
    {
    	fp=open("sale by bulk.txt","a+");
    	fprintf (fp,"%d %d %d %d  %s   %s   %s   %f   %d   %f   %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,price,-add,price*(-add),p->infor);//������
    }
    else
    {
    fp=open("single sale.txt","a+");
    fprintf (fp,"%d %d %d %d  %s   %s   %s   %f   %d   %f   %s\n",lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min,p->name,p->type,p->maker,price,-add,price*(-add),p->infor);//������
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

void FullScreen()//����ȫ��������ֱ�ӵ��ü���
{
	HWND hwnd=GetForegroundWindow();
	int x=GetSystemMetrics(SM_CXSCREEN)+300,y=GetSystemMetrics(SM_CYSCREEN)+300;
	char setting[30];
	sprintf(setting,"mode con:cols=%d lines=%d",x,y);//���ÿ���̨��������
	system(setting);
	SetWindowPos(hwnd, HWND_TOPMOST,0,0,x+300,y+300,0);//�ö�
	MoveWindow(hwnd,-10,-40,x+300,y+300,1);//�ƶ�
}

void SearchStart()
{
     main_home();
}

void main_home()
{
    char key='s';
	struct POX position;//����һ���ṹ�����
	home(-1);//��ӡ�˵�
	position.x=0;
	position.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key=='\r')
		{
			switch(position.y-1)
			{
				case 1:system("cls");main_sort_home(1);system("pause");break;     //������Ϣ��ѯ
				case 2:system("cls");main_sort_home(2);system("pause");break;     //������Ϣ��ѯ
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
      case -1:printf("�������������-*-�������������\n");
              printf("��� choose the selling one or the buying one  ���              ��� press w or s ���\n");
              printf("���                 1.selling                 ���              ���    w:up      ���\n");
              printf("���                 2.buying                  ���              ���    s:up      ���\n");
              printf("���                 3.quit                    ���\n");
              printf("�������������-*-�������������\n");
              XiaoHuangRen();
              break;
      case 2: printf("���                 1.selling                 ���\n");break;
      case 3: printf("���                 2.buying                  ���\n");break;
      case 4: printf("���                 3.quit                    ���\n");break;
      case 5: printf("�������������-*-�������������\n");break;
      case 6: printf("��� choose the selling one or the buying one  ���              ��� press w or s ���\n");
    }
}

void main_sort_home(int n)
{
    char key='s';
	struct POX sort_position;//����һ���ṹ�����
	sort_home(-1);//��ӡ�˵�
	sort_position.x=0;
	sort_position.y=1;
	while(1)
    {   if(_kbhit())//�ж��Ƿ��а���
		{
			key=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key=='\r')
		{
			switch(sort_position.y-1)
			{
				case 1:system("cls");sort_search_three='a';choose(n);system("pause");break;   //��ѯ���
				case 2:system("cls");sort_search_three='b';choose(n);system("pause");break;                   //��ѯ������
				case 3:system("cls");sort_search_three='c';choose(n);system("pause");break;                    //��ѯ�ͻ���Ϣ
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
        case -1:printf("�������������-*-�������������\n");
                printf("���               -ѡ���ѯ����-               ���\n");
                printf("���                   -���-                   ���               ��� press w or s ���\n");
                printf("���                  -������-                  ���               ���       w:up   ���\n");
                printf("���                   -�ͻ�-                   ���               ���      s:down  ���\n");
                printf("���                   -����-                   ���\n");
                printf("�������������-*-�������������\n");
                XiaoHuangRen();
                break;
       case 2:  printf("���                   -���-                   ���\n");break;
       case 3:  printf("���                  -������-                  ���\n");break;
       case 4:  printf("���                   -�ͻ�-                   ���\n");break;
       case 5:  printf("���                   -����-                   ���\n");break;
       case 6:  printf("�������������-*-�������������\n");break;
       case 7:  printf("���               -ѡ���ѯ����-               ���\n");
    }
}

void choose(int i)
{
    FILE*fp=NULL;
    printf("�� Please input the name you want to search ��\n");
    fflush(stdin);//ˢ�»�����
    char name[20];
    scanf("%s",name);//�����ѯ����
    LINK *p1,*p2;
    if(i==1)                  //��������
    {
        fp=open("sale by bulk.txt","r");      //�Ȳ�����
        p1=make_link (fp,1);                                 //��p1�������������ͷָ��
        printf("��������Ϣ��\n");                           //���ġ�������Ϣ������ɫ
        search(p1,sort_search_three,name);                //����
        fclose(fp);
        fp=open("single sale.txt","r");     //����
        p2=make_link (fp,1);                                  //��p2����������۵�ͷָ��
        printf("��������Ϣ��\n");
        search(p2,sort_search_three,name);                  //����
        fclose(fp);
    }
    else
    {
        fp=open("stock.txt","r");            //����
        p1=make_link (fp,1);
        printf("�������Ϣ��\n");
        search(p1,sort_search_three,name);
    }
}

void search(LINK* p,char c,char name[])
{
    int cout=0;
    int boolflag=0;//�Ƿ��ѯ����Ʒ
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
		            while((p!=NULL)&&(strcmp(name,p->name)!=0))          //��ͬ�ͼ�����
		            {
		                p=p->next;
		            }
		            if(p!=NULL)
		            {
		            	boolflag=1;
		                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
		                printf("\n");//��ӡ��Ϣ
		                //cout++;      //������ļ��Ƿ��д�����Ϣ��û����֪ͨû��
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
					printf("��ȷ����Ҫ�ҵ���%s������%s��(�س������ϣ�������ȷ��)\n",name,str);
					int k=_getch();
					if (k=='\r')
					{
						strcpy(name,str);
					}
					else
					{
						printf("\n�� There is no information about it ��\n");//û����Ϣ����ʾ
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
		                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
		                printf("\n");
		               // cout++;     //������ļ��Ƿ��д�����Ϣ
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
					printf("��ȷ����Ҫ�ҵ���%s������%s��(�س������ϣ�������ȷ��)\n",name,str);
					int k=_getch();
					if (k=='\r')
					{
						strcpy(name,str);
					}
					else
					{
						printf("\n�� There is no information about it ��\n");//û����Ϣ����ʾ
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
		                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
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
					printf("��ȷ����Ҫ�ҵ���%s������%s��(�س������ϣ�������ȷ��)\n",name,str);
					int k=_getch();
					if (k=='\r')
					{
						strcpy(name,str);
					}
					else
					{
						printf("\n�� There is no information about it ��\n");//û����Ϣ����ʾ
						return;
					}
		        }
	    }
    }
}

int DeleteMenu1(LINK*p)//�������ݵ�ѡ��˵�
{
    printf("ʱ��           �������          �ͺ�        ������        ����         ����        �ܼ�        �ͻ���Ϣ\n");
    printf("-����˴�����-\n");
    int cout=0;
    if(p==NULL)
    {
        printf("-end-");
        return 1;
    }
    while(p!=NULL)
    {
        printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
        p=p->next;
        cout++;
    }
    printf("-end-");
    return cout+1;
}

void StartDelete()
{
    char key='s';
	struct POX pod;//����һ���ṹ�����
	StartMenu(-1);//��ӡ�˵�
	pod.x=0;
    pod.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key=='\r')//�жϻس�
		{
			switch(pod.y-1)
			{
				case 1: system("cls");ChooseDeleteInfor(1);system("pause");break;     //1�������ۣ�2�������ۣ�3�������
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
        {case -1:printf("�������������-*-�������������\n");
                printf("���              please  choose               ���              ��� press w or s ���\n");
                printf("���                 1.����                    ���              ���    w:up      ���\n");
                printf("���                 2.����                    ���              ���    s:up      ���\n");
                printf("���                 3.����                    ���\n");
                printf("���                 4.��棨С�ģ�             ���\n");
                printf("���                 5.quit                    ���\n");
                printf("�������������-*-�������������\n");
                XiaoHuangRen();
                break;
        case 2: printf("���                 1.����                    ���\n");break;
        case 3: printf("���                 2.����                    ���\n");break;
        case 4: printf("���                 3.����                    ���\n");break;
       	case 5:	printf("���                 4.��棨С�ģ�             ���\n");break;
        case 6: printf("���                 5.quit                    ���\n");break;
        }
}

void ChooseDeleteInfor(int n)
{
    char key='s';
	struct POX pod;//����һ���ṹ�����
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
    int cout=0;//��������
    cout=DeleteMenu1(p1);
    p=p1;
	pod.x=0;
    pod.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key=='\r')//�жϻس�
		{
		    system("cls");
		    if(pod.y!=1)
               {
                   if(pod.y!=cout+1)
                    p1=Delete(p1,pod.y-1);//ɾ��,pod.y-1Ϊ��һ��
                    else
                    cout=DeleteMenu1(p1); //�������κβ���
               }
			else
                {
                    InputDeleteInfor(p1,n);
                    return;//���޸ĺ����Ϣд��
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
                            p=p1;//p1Ϊ�ļ�ͷָ��
                            while(i<pod.y-1)
                            {
                                p=p->next;//�ҵ���ǰ��
                                i++;
                            }
                            if(pod.y!=cout+1)
                                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
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
                                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else
                                printf("-����˴�����-\n");
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
                            p=p1;//p1Ϊ�ļ�ͷָ��
                            while(i<pod.y-1)
                                {
                                    p=p->next;//�ҵ���ǰ��
                                    i++;
                                }
                            if((pod.y>1)&&(pod.y!=cout+1))
                                    printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else if(pod.y==1)
                                    printf("-����˴�����-\n");
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
                                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
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
	char FirstLine1[]="ʱ��           �������          �ͺ�        ������        ����         ����        �ܼ�        �ͻ���Ϣ";
	fprintf(fp,"%s\n",FirstLine1);
        while(p!=NULL)
        {
            fprintf(fp,"%d %d %d %d          ",p->time.month,p->time.day,p->time.hour,p->time.minute);//дȡ����,ʱ��
		    fprintf(fp,"%s          %s          %s          ",p->name,p->type,p->maker);//дȡ������ͺţ�������
		    fprintf(fp,"%.1f          %d          %.1f  ",p->price,p->num,p->sum);//дȡ���ۣ��������ܼ�
		    fprintf(fp,"%s\n",p->infor);
		    p=p->next;
        }
    fclose(fp);
}

void menu_of_change_record (int num)
{
	switch(num)
	{
		case -1:printf("�������������-*-�������������\n");
                printf("���         please  choose                    ���              ��� press w or s ���\n");
                printf("���               1.stock                     ���              ���    w:up      ���\n");
                printf("���               2.single sell               ���              ���    s:up      ���\n");
                printf("���               3.sell by bulk              ���\n");
                printf("���               4.add storage               ���\n");
                printf("���               5.change money              ���\n");
                printf("���               6.quit                      ���\n");
                printf("�������������-*-�������������\n");
                XiaoHuangRen();
                break;
        case 2: printf("���               1.stock                   ���\n");break;
        case 3: printf("���               2.single sell             ���\n");break;
        case 4: printf("���               3.sell by bulk            ���\n");break;
        case 5: printf("���               4.add storage             ���\n");break;
        case 6: printf("���               5.change money            ���\n");break;
        case 7: printf("���               6.quit                    ���\n");break;
	}
}

void menu_of_addchange_record (int i)
{
    switch(i)
    {
        case -1:printf("���������-*-���������\n");
                printf("���     choose change type    ���\n");
                printf("���           1.stock         ���\n");
                printf("���           2.sell          ���\n");
                printf("���           3.back          ���\n");
                printf("���������-*-���������\n");
                XiaoHuangRen();
                break;
        case 2: printf("���           1.stock         ���\n");break;
        case 3: printf("���           2.sell          ���\n");break;
        case 4: printf("���           3.back          ���\n");break;
    }
}

void print_change_record (void)
{
	char key_stastic='s';
	struct POX pox;//����һ���ṹ�����
	menu_of_change_record(-1);//��ӡ�˵�
	pox.x=0;
	pox.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key_stastic=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
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
	struct POX pox;//����һ���ṹ�����
	menu_of_addchange_record(-1);//��ӡ�˵�
	pox.x=0;
	pox.y=1;
	printf("��ѡ���޸ĳɵ�����");
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key_stastic=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key_stastic=='\r')
		{
			switch(pox.y-1)
			{
				case 1:system("cls");mm=3;buy();return;//��ĺ���
				case 2:system("cls");sell();return;//��
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
    fp=open("storage.txt","r");//���
    fscanf(fp,"%[^\n]",a);
    fp1=open("single sale.txt","r");//��Ʒ
    LINK *head=make_link(fp,2);//��������ı���
    LINK *head1=make_link(fp1,1);//��������ı���Ʒ
    LINK *l=p;
    LINK *q=NULL;
    q=head;
    fclose(fp1);
    while(q!=NULL)
    {
        if(strcmp(q->name,p->name)==0&&strcmp(q->type,p->type)==0&&strcmp(p->maker,q->maker)==0)//ɾ���
        {
            if(mm==3)
			{
				if((q->num-p->num)<0)
               	{
                	system("cls");
                	printf("��������\n");
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
	s1=(LINK *)malloc(sizeof(LINK));//���ٿռ�
	if (s1==NULL)//�жϿռ��Ƿ񿪱ٳɹ�
	{
	    printf("Wrong\n");
	    exit(0);
	}
    s1->next=head1;
    q1=head1;
    q01=s1;
	if(mm==2||mm==1)//����Ʒ����
	{
	    while(q1!=NULL)
	    {
	        if(strcmp(q1->infor,p->infor)==0&&q1->price==0&&p->time.day==q1->time.day&&p->time.month==q1->time.month&&q1->time.hour==p->time.hour&&p->time.minute==q1->time.minute)
	        {
	            //printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
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
        fp=open("storage.txt","r");//���
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
	struct POX pod;//����һ���ṹ�����
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
    int cout=0;//��������
    cout=DeleteMenu1(p1);
    p=p1;
	pod.x=0;
    pod.y=1;
	while(1)
	{
		if(_kbhit())//�ж��Ƿ��а���
		{
			key=_getch();//��������ֵ��key
			fflush(stdin);//ˢ�»�����
		}
		if(key=='\r'&&pod.y==1)
		{
            return;
		}
		if(key=='\r'&&pod.y!=1)//�жϻس�
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
                    printf("���˳ɹ���ʣ�����ʲ�%.2lf",money);
                    system("pause");
                    system("cls");
                    print_addchange_record();
                }
                //printf("%c",flag);
                system("pause");
                if(flag=='n')
                {
                     printf("����ʧ��");
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
                            p=p1;//p1Ϊ�ļ�ͷָ��
                            while(i<pod.y-1)
                            {
                                p=p->next;//�ҵ���ǰ��
                                i++;
                            }
                            printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
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
                                printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                            else
                                printf("-����˴�����-");
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
                            p=p1;//p1Ϊ�ļ�ͷָ��
                            while(i<pod.y-1)
                                {
                                    p=p->next;//�ҵ���ǰ��
                                    i++;
                                }
                            if(pod.y!=1)
                                    printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
                                else
                                    printf("-����˴�����-");
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
                            printf("ʱ��:%d %d %d %d ���:%10s �ͺ�:%10s ������:%10s ����:%5f ����:%5d �ܼ�:%5f �ͻ���Ϣ:%10s\n",p->time.month,p->time.day,p->time.hour,p->time.minute,p->name,p->type,p->maker,p->price,p->num,p->sum,p->infor);
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
        printf(" ��   ��   ��");
        setcursorposition(x-3,y+1);
        printf("��  ��   ��   ��   ��");
        setcursorposition(x-2,y+2);
        printf("��  ��  ��  ��  ��");
        setcursorposition(x-6,y+3);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��������������������������");
        setcursorposition(x-7,y+4);
        printf("����������������������������");
        setcursorposition(x-9,y+5);
        for(int i=0;i<2;i++)
        {
            printf("����");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("����������");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        }
        printf("����");         //�۾��ϱ�
        setcursorposition(x-9,y+6);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��");
        for(int i=0;i<2;i++)
        {
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("��");
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("����������");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("��");
        }
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��");                          //�۾��ڶ���


        ///////////////////
        for(int j=0;j<2;j++)
        {
            setcursorposition(x-8,y+7+j);
            printf(" ");
           SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
           for(int i=0;i<2;i++)
           {
            printf("��");
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("����      ");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("��");
           }
        } //�۾�
        ////////////////


        setcursorposition(x-9,y+9);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��");
        for(int i=0;i<2;i++)
        {
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("��");
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("����������");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("��");
        }
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��");
        setcursorposition(x-9,y+10);
        for(int i=0;i<2;i++)
        {
            printf("����");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("����������");
            SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        }
        printf("����");
        //�۾�ȫ�����꣡

        //��ʼ�����
        setcursorposition(x-9,y+11);
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��������������������������������");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("  ��  ��");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        setcursorposition(x-9,y+12);
        printf("����������  ��������  ����������");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("    �� ");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        setcursorposition(x-9,y+13);
        printf("������������  ����  ������������");
        printf("    �� ");
        setcursorposition(x-9,y+14);
        printf("��������������    ��������������");
        printf("    �� ");
        //��������


        //�����㣡
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        setcursorposition(x-9,y+15);
        printf("��������������������������������");//�������һ��

        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("  �� ");
        setcursorposition(x-11,y+16);
        printf("��������");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("��������������������");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��������");
         //������ڶ���

        setcursorposition(x-13,y+17);
        printf("��  ����");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("����");
        SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
        printf("����������������");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("����");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("����");
        //�����������

        setcursorposition(x-15,y+18);
        printf("��    ��");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("��������");
        SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
        printf("������������");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("��������");
        SetConsoleTextAttribute(handle,FOREGROUND_RED|FOREGROUND_GREEN);
        printf("��");
        //�����������

        setcursorposition(x-13,y+19);
        printf("��");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("��");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("������������");
        SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
        printf("��������");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("������������");
        //�����������

        setcursorposition(x-11,y+20);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("��");
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("��������������������������������");
        //�����������

        setcursorposition(x-7,y+21);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("����������������������������");
        //�����������

        setcursorposition(x-5,y+22);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("������������������������");
        //������ڰ���

        setcursorposition(x-2,y+23);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("������      ������");
        //��1

        setcursorposition(x-2,y+24);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        printf("������      ������");
        setcursorposition(x-2,y+25);
        printf("������      ������");
        //��2,3

        setcursorposition(x-2,y+26);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        printf("��������    ��������");
        //��
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
	printf("�������������\n");
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
	printf("�������ͺ�\n");
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
	printf("������������\n");
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
		printf("\r��ѡ���ۼۣ�%.2f, ��סw/s(Q������,E���ټ�,N��M����С��,O��PС������)",price);
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
						printf("�Բ���Ŀǰ�㻹�޷�ɾ�����\n");
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
		printf("\r�밴w/s(Q/E���٣�����||N/M�޸�С��)�޸�Ǯ%.2lf    ",i);
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
