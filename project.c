#include<stdio.h>
#include<windows.h>//sleep?
#include<stdlib.h>//system?
struct member{//
	int number;//���� 
	char name[20];//���� 
	char gender[2];//�Ա�
	double salary;//��������
	double allowance;//���� 
	double bous;//���� 
	double fee;//ˮ���
	double rent;//���� 
	double payment;//ʵ������
	int rank;//��������
	 
	
}staff[100];//����һ��ȫ�ֵĽṹ������
int N=0;//NΪ��ǰ��¼��Ա������ 
struct member staff[100]={//�����ó�ʼ������  ���ڽṹ�崦����������ظ����� 
	{1001,"����","��",3000,500,300,400,2000},//�ڶ���ʱ������ֵ��ʼ�� 
	{1002,"����","Ů",3000,500,300,600,2000},
	{1003,"����","Ů",3000,500,300,800,3000},
	{1004,"����","��",3000,500,300,900,4000},
//	{0},
};
void menu();//�����溯�� 
void insert();
void mod();
void sum();
void delete();
void putout(char str[][60],char s[],int l);//�������� 

int main(){
	int run=1;
	char choice;
	while(run){
		menu();//���ý��溯��,�����û�ѡ�� 
		choice=_getch();//�����û����룬�����ûس� ����Ӣ�� ��Ӣ�����뷨 
		switch(choice){
			case '0'://����Ϊchar������'' 
				printf("�����˳�����\n");
				run=0;
				break;
			case '1':
//				system("cls");
				printf("����1\n"); /*������ չʾ��ǰԱ���б�*/ 
				printf("%d %s %s %f %f %f %f %f %f %d\n",staff[0].number,staff[0].name,staff[0].gender,staff[0].salary,staff[0].allowance,staff[0].bous,staff[0].fee,staff[0].rent,staff[0].payment,staff[0].rank);
				system("pause");
				break;
			case '2':
				printf("����2\n"); 
				delete(); 
				break;
			case '3':
				printf("����3\n"); 
				insert();
				break;
			case '4':
				printf("����4\n"); 
				mod();
				break;
			case '5':
				printf("����5\n"); 
				break;
			case '6':
				printf("����6\n"); 
				break;
			default:
				printf("�Ƿ����룡����������\n");
				break;
		}
		sleep(1);//��ʱ 
		system("cls");//���� 
//		system("pause");
	}
	return 0;
}
void menu(){
	printf("����һ����ʱ���棬��ѡ��1~6,ѡ��0�˳�����\n");
}
void insert(){//����һ��Ա������Ϣ 
	int i,repeat=1;//repeat�ж��Ƿ����������Ϣ 
	while(repeat){
		system("cls");//���� 
		printf("�밴������˳�������Ϣ��ÿ����Ϣ��ո�:\n");
		printf("���� | ���� | �Ա� | �������� | ���� | ���� | ˮ��� | ����\n");
		scanf("%d %s %s %f %f %f %f %f",&staff[N+1].number,&staff[N+1].name,&staff[N+1].gender,&staff[N+1].salary,&staff[N+1].allowance,&staff[N+1].bous,&staff[N+1].fee,&staff[N+1].rent);
		//�˴����ü��㺯�� ������²����Ա���� ʵ�������빤������
		N++;
		printf("�Ƿ�������룿\n ��������1\n");
		scanf("%d",&i);
		//�˴����Բ��벻��ʾ���� 
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
	printf("������Ҫ�޸�Ա���Ĺ���");
	scanf("%d",&n);
	for(i=0;i<=N;i++){
	 	if(staff[i].number==n)
	  	break;
	 }
	 int m;
	 char title[20]={"����������1~8:"};
	 char dis[8][60]={
	 	{"1���޸�Ա�����ţ�"},
	 	{"2���޸�Ա��������"},
		{"3���޸�Ա���Ա�"},
		{"4���޸�Ա���������ʣ�"},
		{"5���޸�Ա��������"},
		{"6���޸�Ա������"},
		{"7���޸�Ա��ˮ��ѣ�"},
		{"8���޸�Ա�����⣻"} 
	 };
//	 printf("����������1~8:\n"
//	"1���޸�Ա�����ţ�\n" 
//	"2���޸�Ա��������\n"
//	"3���޸�Ա���Ա�\n"
//	"4���޸�Ա���������ʣ�\n"
//	"5���޸�Ա��������\n"
//	"6���޸�Ա������\n"
//	"7���޸�Ա��ˮ��ѣ�\n"
//	"8���޸�Ա�����⣻\n");
	putout(dis,title,8);
	scanf("%d",&m);
	
	switch(m)
	
	 {
	 	case 1:
		 	printf("�������޸ĺ�Ĺ��ţ�");
			scanf("%d",&staff[i].number);break;
	  case 2:
		  printf("������Ҫ�޸ĺ������:");
		  scanf("%s",&staff[i].name);break;
	  case 3:
	  	printf("�������޸ĺ���Ա�:");
	  	scanf("%s",&staff[i].gender);break;
	  case 4:
	  	printf("�������޸ĺ�Ļ������ʣ�");
	  	scanf("%lf",&staff[i].salary);break;
	  case 5:
	  	printf("�������޸ĺ�Ĳ�����");
	  	scanf("%lf",&staff[i].allowance);break;
	  case 6:
	  	printf("�������޸ĺ󽱽�");
	  	scanf("%lf",&staff[i].bous);break;
	  case 7:
	  	printf("�������޸ĺ��ˮ��ѣ�");
	  	scanf("%lf",&staff[i].fee);break;
	  case 8:
	  	printf("�������޸ĺ�ķ��⣺");
	  	scanf("%lf",&staff[i].rent);break;
	  default:
	  	printf("�������");
	 }
	 if(m>=4&&m<=8){
	 staff[i].payment=staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	 }
	 printf("�޸ĳɹ�");
}
void sum(){
	int i;
	for(i=0;i<=N;i++){
		staff[i].payment=staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	}
	printf("�������");
}
void delete(){
	int n;
	int i;
	int k;
	printf("������Ҫɾ��Ա���Ĺ���:");
	scanf("%d",&n);
	for(i=0;i<=N;i++){
		if(staff[i].number==n)
	  		k=i;break;
	 }
	 for(i=k;i<N;i++){
	 	staff[i]=staff[i+1];
	 }
	 N--;
	 printf("ɾ�����");
}
void putout(char str[][60],char s[],int l){
	//            ѡ������    ����     ѡ������ 
	char t;
	int i,j,m;
	int max=0,n=0;	
	for(i=0;i<l;i++){
		m=strlen(str[i]);
		if(max<m)max=m;
	}
	m=strlen(s);
	if(max<m)max=m;//ȡ��󳤶� 
	    
    int length,len_h;
    len_h=max/2;
    length=len_h*2+18;//���㵯������
	
	int s1,s2;
	s1=(length-strlen(s))/2;
	s2=length-strlen(s)-s1;
	int k1[l],k2[l];
	for(i=0;i<l;i++){
		k1[i]=(length-strlen(str[i]))/2;
		k2[i]=length-strlen(str[i])-k1[i];
	}//������и�ʽ 
	
	printf("\n"); printf("\n");printf("\n");printf("\n");printf("\n");
		
	printf("                 ��");
	for(i=0;i<length/2;i++)printf("��");
	printf("��\n");//����϶�
	
	printf("                 ��");
	for(i=0;i<s1;i++)printf(" ");
	printf("%s",s);
	for(i=0;i<s2;i++)printf(" ");
	printf("��\n");//���� 	

	for(j=0;j<l;j++){
	printf("                 ��");
	for(i=0;i<k1[j];i++)printf(" ");
	printf("%s",str[j]);
	for(i=0;i<k2[j];i++)printf(" ");
	printf("��\n");		
	}//����	
	
	printf("                 ��");
	for(i=0;i<length/2;i++)printf("��");
	printf("��\n");//����¶� 	
	
	
	printf("                  ��ѡ��");//ѡ����� 
	fflush(stdin);//���������
}


