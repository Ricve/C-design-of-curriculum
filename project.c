#include<stdio.h>
#include<windows.h>
struct member{
	int number;//工资
	char name[20];//姓名 
	char gender[2];//性别
	double salary;//基本工资
	double allowance;//补贴 
	double bous;//奖金 
	double fee;//水电费
	double rent;//房租 
	double payment;//实发工资
	int rank;//工资排名
	 
	
}staff[100];
void menu();


int main(){
	int run=1;
	char choice;
	while(run){
		menu();//调用界面函数,返回用户选项 
		choice=_getch();
		switch(choice){
			case '0':
				run=0;
				break;
			case '1':
//				system("cls");
				printf("函数1\n"); 
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
				printf("非法输入！\n");
				break;
		}
		sleep(1);
		system("cls");
//		system("pause");
	}
	return 0;
}
void menu(){
	printf("这是一个临时界面，请选择1~6,选择0退出程序\n");
}
