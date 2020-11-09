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
int N=4;//N为当前已录入员工数量 
struct member staff[100]={//测试用初始化数据  若在结构体处定义后不能再重复定义 
	{1001,"张三","男",3000,500,300,400,2000},//在定义时批量赋值初始化 
	{1002,"张四","女",3000,500,300,600,2000},
	{1003,"张五","女",3000,500,300,800,3000},
	{1004,"张六","男",3000,500,300,900,4},
//	{0},
};
void menu();//主界面函数 
void insert();//插入函数 
void mod();//修改函数 
void sum();//计算函数 
void delete();//删除函数 
void putout(char str[][60],char s[],int l);//弹窗函数 
void display();//显示函数 
void BubbleSort(int n);//排序函数,n为选择排序依据
/*1=工号，2=工资，3=补贴，4=奖金，5=水电费，6=房租，7=实发工资*/ 
void rank_h();//排名函数，计算每个员工rank 
void print_pass(int t,int n,int m);
void print_all(); 


int main(){
	int run=1;//通过run判断是否循环 
	char choice;
	while(run){ 
		menu();//调用界面函数,使用户选择选项 
		choice=_getch();//读入用户输入，无需敲回车 若输英文 需英文输入法 
		switch(choice){
			case '0'://读入为char，故需用'' 
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
				print_all();
				break;
			case '6':
				printf("函数6\n"); 
				sum(); 
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
	printf("这是一个临时界面\n");
	char title[20]={"请输入数字0~6:"};
	char dis[7][60]={
	 	{"1：测试"},
	 	{"2：删除员工信息"},
		{"3：插入员工信息"},
		{"4：修改员工信息"},
		{"5；展示员工信息"},
		{"6：计算员工工资"},
		{"0：退出程序"},
	 };
	putout(dis,title,7);
}
void insert(){//插入一条员工的信息 
	char repeat='1';//repeat判断是否继续插入信息 
	while(repeat=='1'){
		system("cls");//清屏 
		printf("请按照下列顺序插入信息，每条信息间空格:\n");
		printf("工号 | 姓名 | 性别 | 基本工资 | 补贴 | 奖金 | 水电费 | 房租\n");
		scanf("%d %s %s %lf %lf %lf %lf %lf",&staff[N].number,&staff[N].name,&staff[N].gender,&staff[N].salary,&staff[N].allowance,&staff[N].bous,&staff[N].fee,&staff[N].rent);
		N++;
		sum();//调用计算函数 计算出插入后员工的 实发工资
//		rank_h();//调用排序函数 
		printf("是否继续插入？\n 是请输入1，否输入其他\n");
		repeat=_getche();
	}		
}
void mod()
{
	int n;
	int i;
	system("cls");
	printf("请输入要修改员工的工号");
	scanf("%d",&n);
	for(i=0;i<=N;i++){
	 	if(staff[i].number==n)
	  	break;
	 }
	 int m;
	 char title[30]={"请输入数字1~8选择修改选项:"};
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
	 	staff[i].payment = staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	 }
	 printf("修改成功");
	 //此处调用显示函数 
}
void sum(){
	int i;
	for(i=0;i<=N;i++){
		staff[i].payment=staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	}
	rank_h();//调用排名函数 
	printf("计算完成");
}
void delete(){
	int n;
	int i;
	int k;
	system("cls");
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
	 printf("删除完成\n");
	 display();//此处调用显示函数 
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
	
	
//	printf("                  请选择：");//选择界面 
	fflush(stdin);//清除缓存区
}
void display(){
	int i;
	system("cls"); 
	for(i=0;i<N;i++){
		printf("%d %s %s %f %f %f %f %f %f %d\n",staff[i].number,staff[i].name,staff[i].gender,staff[i].salary,staff[i].allowance,staff[i].bous,staff[i].fee,staff[i].rent,staff[i].payment,staff[i].rank);
	}
	system("pause");
}
void BubbleSort(int n){
	int i,j;
	struct member sbb;
	switch(n){
		case 1://工号 
            for(i=0;i<N;i++){int t=0;for(j=1;j<N-i;j++){if(staff[j].number>staff[j-1].number){sbb=staff[j];staff[j]=staff[j-1];staff[j-1]=sbb;t=1;}}if(t=1)return;}
		    break;      
		case 2://工资 
            for(i=0;i<N;i++){int t=0;for(j=1;j<N-i;j++){if(staff[j].salary>staff[j-1].salary){sbb=staff[j];staff[j]=staff[j-1];staff[j-1]=sbb;t=1;}}if(t=1)return;}
		    break;      
		case 3://补贴 
            for(i=0;i<N;i++){int t=0;for(j=1;j<N-i;j++){if(staff[j].allowance>staff[j-1].allowance){sbb=staff[j];staff[j]=staff[j-1];staff[j-1]=sbb;t=1;}}if(t=1)return;}
			break;	  		
		case 4://奖金 
            for(i=0;i<N;i++){int t=0;for(j=1;j<N-i;j++){if(staff[j].bous>staff[j-1].bous){sbb=staff[j];staff[j]=staff[j-1];staff[j-1]=sbb;t=1;}}if(t=1)return;}
		    break;
		case 5://水电费 
		    for(i=0;i<N;i++){int t=0;for(j=1;j<N-i;j++){if(staff[j].fee>staff[j-1].fee){sbb=staff[j];staff[j]=staff[j-1];staff[j-1]=sbb;t=1;}}if(t=1)return;}
		    break;
		case 6://房租
            for(i=0;i<N;i++){int t=0;for(j=1;j<N-i;j++){if(staff[j].rent>staff[j-1].rent){sbb=staff[j];staff[j]=staff[j-1];staff[j-1]=sbb;t=1;}}if(t=1)return;}
		    break;
		case 7://实发工资
            for(i=0;i<N-1;i++){
				for(j=0;j<N-1-i;j++){
				    if(staff[j].payment<staff[j+1].payment){
					    sbb=staff[j];
						staff[j]=staff[j+1];
						staff[j+1]=sbb;
						}
					}
				}
		    break;  			  	  	  				  		          
	}	
}
void rank_h(){
	int i;
	BubbleSort(7);
	for (i=0;i<N;i++){
		staff[i].rank=i+1;
	}
}
void print_pass(int t,int n,int m){
	int i,s;s=n-m;if(t==0){for(i=0;i<s;i++)printf(" ");}
	else{for(i=0;i<s;i++)printf("--");}}
//输出调整 
void print_all(){
//	void BubbleSort(n);
	int i,j,m;
    double m_nam,m_sal,m_all,m_bou,m_fee,m_ren,m_pay;
    int max_nam=strlen("姓名"),
	    max_sal=strlen("基本工资")-3,
		max_all=strlen("补贴")-3,
		max_bou=strlen("奖金")-3,
		max_fee=strlen("水电费")-3,
		max_ren=strlen("房租")-3,
		max_pay=strlen("实发工资")-3;
    int s_nam[N],s_sal[N],s_all[N],s_bou[N],s_fee[N],s_ren[N],s_pay[N];
    for(i=0;i<N;i++){
    	m_nam=strlen(staff[i].name);s_nam[i]=m_nam;j=0;
    	if(max_nam<m_nam)max_nam=m_nam;
    	//计算姓名格式 
	    m_sal=staff[i].salary;j=0;
    	while(m_sal>=10){m_sal=m_sal/10;j++;};
    	s_sal[i]=j;if(max_sal<j)max_sal=j;
    	//计算工资格式 
    	m_all=staff[i].allowance;j=0;
    	while(m_all>=10){m_all=m_all/10;j++;};
    	s_all[i]=j;if(max_all<j)max_all=j;
    	//计算补贴格式
		m_bou=staff[i].bous;j=0;
		while(m_bou>=10){m_bou=m_bou/10;j++;};
		s_bou[i]=j;if(max_bou<j)max_bou=j;
		//计算奖金格式
		m_fee=staff[i].fee;j=0;
		while(m_fee>=10){m_fee=m_fee/10;j++;};
		s_fee[i]=j;if(max_fee<j)max_fee=j;
		//计算水电费格式
		m_ren=staff[i].rent;j=0;
		while(m_ren>=10){m_ren=m_ren/10;j++;};
		s_ren[i]=j;if(max_ren<j)max_ren=j;
		//计算房租格式
		m_pay=staff[i].payment;j=0;
		while(m_pay>=10){m_pay=m_pay/10;j++;};
		s_pay[i]=j;if(max_pay<j)max_pay=j;
		//计算实发工资格式 
	}
//	strlen(s)
    print_pass(1,4,2);print_pass(1,max_nam,0);print_pass(1,4,0);print_pass(1,max_sal,0);print_pass(1,max_all,0);print_pass(1,max_bou,0);print_pass(1,max_fee,0);print_pass(1,max_ren,0);print_pass(1,max_pay,0);print_pass(1,8,0);printf("\n"); 
    printf("|工号");
    printf("|姓名");print_pass(0,max_nam,4);
    printf("|性别");
	printf("|基本工资");print_pass(0,max_sal,4);
	printf("|补贴");print_pass(0,max_all+4,4);
	printf("|奖金");print_pass(0,max_bou+4,4);
	printf("|水电费");print_pass(0,max_fee+4,6);
	printf("|房租");print_pass(0,max_ren+4,4);
	printf("|实发工资");print_pass(0,max_pay+4,8);
	printf("|工资排名");
	printf("|\n");
	for(i=0;i<N;i++){
		printf("|%d",staff[i].number);
		printf("|%s",staff[i].name);print_pass(0,max_nam,s_nam[i]);
		printf("| %s ",staff[i].gender);
		printf("|%.2f",staff[i].salary);print_pass(0,max_sal,s_sal[i]);
		printf("|%.2f",staff[i].allowance);print_pass(0,max_all,s_all[i]);
		printf("|%.2f",staff[i].bous);print_pass(0,max_bou,s_bou[i]);
		printf("|%.2f",staff[i].fee);print_pass(0,max_fee,s_fee[i]);
		printf("|%.2f",staff[i].rent);print_pass(0,max_ren,s_ren[i]);
		printf("|%.2f",staff[i].payment);print_pass(0,max_pay,s_pay[i]);
		printf("|    %d   |\n",staff[i].rank);
	} 
	print_pass(1,4,2);print_pass(1,max_nam,0);print_pass(1,4,0);print_pass(1,max_sal,0);print_pass(1,max_all,0);print_pass(1,max_bou,0);print_pass(1,max_fee,0);print_pass(1,max_ren,0);print_pass(1,max_pay,0);print_pass(1,8,0);printf("\n"); 
	system("pause");
}
