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
//struct member staff[100]={//�����ó�ʼ������  ���ڽṹ�崦����������ظ����� 
//	{1001,"����","��",3000,500,300,400,2000},//�ڶ���ʱ������ֵ��ʼ�� 
////	{0},
//};
void menu();//�����溯�� 
void insert();


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
				break;
			case '3':
				printf("����3\n"); 
				break;
			case '4':
				printf("����4\n"); 
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
	int i;
//	for(i=0;i<100;i++){
//		if(staff[i].number!=0){
//			
//		}
	
		
	}
