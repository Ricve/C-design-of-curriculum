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
struct member staff[100]={//测试用初始化数据  若在结构体处定义后不能再重复定义 
	{1001,"张三","男",3000,500,300,400,2000},//在定义时批量赋值初始化 
	{1002,"张四","女",3000,500,300,600,2000},
	{1003,"张五","女",3000,500,300,800,3000},
	{1004,"张六","男",3000,500,300,900,4000},
//	{0},
};
void menu();//主界面函数 
void insert();
void mod();
void sum();
void delete();
void putout(char str[][60],char s[],int l);//弹窗函数 

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
				insert();
				break;
			case '4':
				printf("函数4\n"); 
				mod();
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
	int i,repeat=1;//repeat判断是否继续插入信息 
	while(repeat){
		system("cls");//清屏 
		printf("请按照下列顺序插入信息，每条信息间空格:\n");
		printf("工号 | 姓名 | 性别 | 基本工资 | 补贴 | 奖金 | 水电费 | 房租\n");
		scanf("%d %s %s %f %f %f %f %f",&staff[N+1].number,&staff[N+1].name,&staff[N+1].gender,&staff[N+1].salary,&staff[N+1].allowance,&staff[N+1].bous,&staff[N+1].fee,&staff[N+1].rent);
		//此处调用计算函数 计算出新插入的员工的 实发工资与工资排名
		N++;
		printf("是否继续插入？\n 是请输入1\n");
		scanf("%d",&i);
		//此处可以插入不显示函数 
		if(i==1){
			repeat=1;
		}else{
			repeat=0;
		}
	}
	
		
}
void mod()
{
	int n;
	int i;
	printf("请输入要修改员工的工号");
	scanf("%d",&n);
	for(i=0;i<=N;i++){
	 	if(staff[i].number==n)
	  	break;
	 }
	 int m;
	 char title[20]={"请输入数字1~8:"};
	 char dis[8][60]={
	 	{"1：修改员工工号；"},
	 	{"2：修改员工姓名；"},
		{"3：修改员工性别；"},
		{"4：修改员工基本工资；"},
		{"5；修改员工补贴；"},
		{"6：修改员工奖金；"},
		{"7：修改员工水电费；"},
		{"8；修改员工房租；"} 
	 };
//	 printf("请输入数字1~8:\n"
//	"1：修改员工工号；\n" 
//	"2：修改员工姓名；\n"
//	"3：修改员工性别；\n"
//	"4：修改员工基本工资；\n"
//	"5；修改员工补贴；\n"
//	"6：修改员工奖金；\n"
//	"7：修改员工水电费；\n"
//	"8；修改员工房租；\n");
	putout(dis,title,8);
	scanf("%d",&m);
	
	switch(m)
	
	 {
	 	case 1:
		 	printf("请输入修改后的工号：");
			scanf("%d",&staff[i].number);break;
	  case 2:
		  printf("请输入要修改后的姓名:");
		  scanf("%s",&staff[i].name);break;
	  case 3:
	  	printf("请输入修改后的性别:");
	  	scanf("%s",&staff[i].gender);break;
	  case 4:
	  	printf("请输入修改后的基本工资：");
	  	scanf("%lf",&staff[i].salary);break;
	  case 5:
	  	printf("请输入修改后的补贴：");
	  	scanf("%lf",&staff[i].allowance);break;
	  case 6:
	  	printf("请输入修改后奖金：");
	  	scanf("%lf",&staff[i].bous);break;
	  case 7:
	  	printf("请输入修改后的水电费：");
	  	scanf("%lf",&staff[i].fee);break;
	  case 8:
	  	printf("请输入修改后的房租：");
	  	scanf("%lf",&staff[i].rent);break;
	  default:
	  	printf("输入错误");
	 }
	 if(m>=4&&m<=8){
	 staff[i].payment=staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	 }
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
	int n;
	int i;
	int k;
	printf("请输入要删除员工的工号:");
	scanf("%d",&n);
	for(i=0;i<=N;i++){
		if(staff[i].number==n)
	  		k=i;break;
	 }
	 for(i=k;i<N;i++){
	 	staff[i]=staff[i+1];
	 }
	 N--;
	 printf("删除完成");
}
void putout(char str[][60],char s[],int l){
	//            选择内容    标题     选项数量 
	char t;
	int i,j,m;
	int max=0,n=0;	
	for(i=0;i<l;i++){
		m=strlen(str[i]);
		if(max<m)max=m;
	}
	m=strlen(s);
	if(max<m)max=m;//取最大长度 
	    
    int length,len_h;
    len_h=max/2;
    length=len_h*2+18;//计算弹窗长度
	
	int s1,s2;
	s1=(length-strlen(s))/2;
	s2=length-strlen(s)-s1;
	int k1[l],k2[l];
	for(i=0;i<l;i++){
		k1[i]=(length-strlen(str[i]))/2;
		k2[i]=length-strlen(str[i])-k1[i];
	}//计算居中格式 
	
	printf("\n"); printf("\n");printf("\n");printf("\n");printf("\n");
		
	printf("                 ┌");
	for(i=0;i<length/2;i++)printf("—");
	printf("┐\n");//表格上端
	
	printf("                 │");
	for(i=0;i<s1;i++)printf(" ");
	printf("%s",s);
	for(i=0;i<s2;i++)printf(" ");
	printf("│\n");//标题 	

	for(j=0;j<l;j++){
	printf("                 │");
	for(i=0;i<k1[j];i++)printf(" ");
	printf("%s",str[j]);
	for(i=0;i<k2[j];i++)printf(" ");
	printf("│\n");		
	}//内容	
	
	printf("                 └");
	for(i=0;i<length/2;i++)printf("—");
	printf("┘\n");//表格下段 	
	
	
	printf("                  请选择：");//选择界面 
	fflush(stdin);//清除缓存区
}


