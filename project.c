#include<stdio.h>
#include<windows.h>//sleep?
#include<stdlib.h>//system?
struct member{//
	int number;//工号 
	char name[20];//姓名 
	char gender[2];//性别
	double salary;//基本工资
	double allowance;//补贴 
	double bous;//奖金 
	double fee;//水电费
	double rent;//房租 
	double payment;//实发工资
	int rank;//工资排名
	 
	
}staff[100];//定义一个全局的结构体数组
int N=0;//N为当前已录入员工数量 
//struct member staff[100]={//测试用初始化数据  若在结构体处定义后不能再重复定义 
//	{1001,"张三","男",3000,500,300,400,2000},//在定义时批量赋值初始化 
////	{0},
//};
void menu();//主界面函数 
void insert();


int main(){
	int run=1;
	char choice;
	while(run){
		menu();//调用界面函数,返回用户选项 
		choice=_getch();//读入用户输入，无需敲回车 若输英文 需英文输入法 
		switch(choice){
			case '0'://读入为char，故用'' 
				printf("即将退出程序\n");
				run=0;
				break;
			case '1':
//				system("cls");
				printf("函数1\n"); /*测试用 展示当前员工列表*/ 
				printf("%d %s %s %f %f %f %f %f %f %d\n",staff[0].number,staff[0].name,staff[0].gender,staff[0].salary,staff[0].allowance,staff[0].bous,staff[0].fee,staff[0].rent,staff[0].payment,staff[0].rank);
				system("pause");
				break;
			case '2':
				printf("函数2\n"); 
				break;
			case '3':
				printf("函数3\n"); 
				break;
			case '4':
				printf("函数4\n"); 
				break;
			case '5':
				printf("函数5\n"); 
				break;
			case '6':
				printf("函数6\n"); 
				break;
			default:
				printf("非法输入！请重新输入\n");
				break;
		}
		sleep(1);//延时 
		system("cls");//清屏 
//		system("pause");
	}
	return 0;
}
void menu(){
	printf("这是一个临时界面，请选择1~6,选择0退出程序\n");
}
void insert(){//插入一条员工的信息 
	int i;
//	for(i=0;i<100;i++){
//		if(staff[i].number!=0){
//			
//		}
	
		
	}
