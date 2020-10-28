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
void mod();
void sum();
void delete();

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
				delete(); 
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
void mod(){
	int n;
 	printf("请输入要修改员工的工号");
 	scanf("%d",&n);
	int m;
	 printf("请输入数字1~7:\n"
	
	 "1：修改员工姓名；\n"
	 "2：修改员工性别；\n"
	 "3：修改员工基本工资；\n"
	 "4；修改员工补贴；\n"
	 "5：修改员工奖金；\n"
	 "6：修改员工水电费；\n"	
	 "7；修改员工房租；\n");
	 scanf("%d",&m);
	 switch(m)
	 {	
	 	case 1:
			printf("请输入要修改后的姓名:");
	  		scanf("%[^\n]",&staff[n].name);break;
	  	case 2:
			printf("请输入修改后的性别:");
	  		scanf("%[^\n]",&staff[n].gender);break;
	  case 3:
			printf("请输入修改后的基本工资：");
	  		scanf("%ld",&staff[n].salary);break;
	  case 4:
	  		printf("请输入修改后的补贴：");
	  		scanf("%ld",&staff[n].allowance);break;
	  case 5:
	  		printf("请输入修改后奖金：");
	  		scanf("%ld",&staff[n].bous);break;
	  case 6:
	  		printf("请输入修改后的水电费：");
	  		scanf("%ld",&staff[n].fee);break;
	  case 7:
	  		printf("请输入修改后的房租：");
	  		scanf("%ld",&staff[n].rent);break;
	  default:printf("输入错误");
	 }

 if(m>=3&&m<=7){
 staff[n].payment=staff[n].salary+staff[n].allowance+staff[n].bous-staff[n].fee-staff[n].rent;}

 printf("修改成功");

}
void sum(){
	int i;
	for(i=0;i<=N;i++){
		staff[i].payment=staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	}
	printf("计算完成");
}
void delete(){	
	int n,i;
 	printf("请输入要删除员工的工号:");
	 scanf("%d",&n);
	 for(i=n;i<N;i++){
	 	staff[i]=staff[i+1];
	 }
	 N--;
	 printf("删除完成");
}


