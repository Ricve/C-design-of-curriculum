#include<stdio.h>
#include<windows.h>//sleep?
#include<stdlib.h>//system?
#include<string.h> 
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
int N=7;//NΪ��ǰ��¼��Ա������ 
struct member staff[100]={//�����ó�ʼ������  ���ڽṹ�崦����������ظ����� 
	{1001,"����","��",3000,500,300,400,2000},//�ڶ���ʱ������ֵ��ʼ�� 
	{1003,"����","Ů",4000,500,300,600,2000},
	{1008,"����","Ů",9000,500,300,800,3000},
	{1002,"����","��",5000,500,300,400,1000},
	{1005,"����","��",4000,500,300,400,1000},
	{1006,"�Ű�","��",4000,500,300,400,1000},
	{1004,"�ž�","��",4000,500,300,600,2000},
};
char menu();//���溯�� 
void insert();//���뺯�� 
void mod();//�޸ĺ��� 
void sum();//���㺯�� 
void delete();//ɾ������ 
void putout(char str[][60],char s[],int l);//�������� 
void BubbleSort(int n);//������,nΪѡ����������
/*1=���ţ�2=���ʣ�3=������4=����5=ˮ��ѣ�6=���⣬7=ʵ������*/ 
void rank_h();//��������������ÿ��Ա��rank 
void print_pass(int t,int n,int m);
void print_all(); //��ʾ���� 
void search();//�������� 

int main(){
	int run=1;//ͨ��run�ж��Ƿ�ѭ�� 
	while(run){ 
		switch(menu()){//���ý��溯��,�������û�ѡ��ѡ�� 
			case '0'://����Ϊchar��������'' 
				printf("\n    �����˳�����\n");
				run=0;
				break;
			case '1':
				print_all();
				break;
			case '2':
				insert();
				break;
			case '3':
				delete(); 
				break;
			case '4':
				mod();
				break;
			case '5':
				search();
				break; 
			default:
				printf("�Ƿ����룡����������\n");
				break;
		}
		sleep(1);//��ʱ 
		system("cls");//���� 
	}
	return 0;
}
char menu(){
	char p;
	Lab:
	while( !_kbhit() ) {
		  printf(" �q�����������������������������������������������������������������������������������������������������������������������������r\n");
		  printf("��                       Ա����Ϣ����ϵͳ                        ��\n");
		  printf("���T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T ��\n");
		  printf("��                    [������Ӧ���ֽ��в���]                     ��\n");
		  printf("��                                                               ��\n");
		  printf("��     [1].��ʾԱ����Ϣ                [2].����Ա����Ϣ          ��\n");
		  printf("��                                                               ��\n");
		  printf("��                                                               ��\n");
		  printf("��     [3].ɾ��Ա����Ϣ                [4].�޸�Ա����Ϣ          ��\n");
		  printf("��                                                               ��\n");
		  printf("��                                                               ��\n");
		  printf("��     [5].��ѯԱ����Ϣ                [0].�˳�����              ��\n");
		  printf("��                          (�s>��<)�s                             ��\n");
		  printf(" �t�����������������������������������������������������������������������������������������������������������������������������s\n");
		  Sleep(100);
		  system("cls");
		  printf(" �q�����������������������������������������������������������������������������������������������������������������������������r\n");
		  printf("��                       Ա����Ϣ����ϵͳ                        ��\n");
		  printf("���T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T ��\n");
		  printf("��                    [������Ӧ���ֽ��в���]                     ��\n");
		  printf("��                                                               ��\n");
		  printf("��     [1].��ʾԱ����Ϣ                [2].����Ա����Ϣ          ��\n");
		  printf("��                                                               ��\n");
		  printf("��                                                               ��\n");
		  printf("��     [3].ɾ��Ա����Ϣ                [4].�޸�Ա����Ϣ          ��\n");
		  printf("��                                                               ��\n");
		  printf("��                                                               ��\n");
		  printf("��     [5].��ѯԱ����Ϣ                [0].�˳�����              ��\n");
		  printf("��                          (�r'��')�r                             ��\n");
		  printf(" �t�����������������������������������������������������������������������������������������������������������������������������s\n");
	      Sleep(100);
		  system("cls");
	}
	p=_getch();////�����û����룬�����ûس� ����Ӣ�� ��Ӣ�����뷨  
	if(p>='0'&&p<='5'){
		return p;
	}
	else goto Lab;
}
void insert(){//����һ��Ա������Ϣ 
	char repeat='1';//repeat�ж��Ƿ����������Ϣ 
	while(repeat=='1'){
		system("cls");//���� 
		printf("\n            �밴������˳�������Ϣ��ÿ����Ϣ��ո�:\n");
		printf("���� | ���� | �Ա� | �������� | ���� | ���� | ˮ��� | ����\n");
		scanf("%d %s %s %lf %lf %lf %lf %lf",&staff[N].number,&staff[N].name,&staff[N].gender,&staff[N].salary,&staff[N].allowance,&staff[N].bous,&staff[N].fee,&staff[N].rent);
		N++;
		print_all();//�Զ�������ʾ���� ��ʾ������Ľ�� 
		printf("�Ƿ�������룿\n ��������1������������\n");
		repeat=_getche();
	}		
}
void mod()
{
	int n;//�洢��Ҫ�޸�Ա���Ĺ��� 
	int i;
	int find = 0;//find��������Ƿ��ҵ�Ҫ�޸ĵĹ���
	int round = 1;
	while (round) {
		system("cls");
		printf("������Ҫ�޸�Ա���Ĺ���:");
		scanf("%d", &n);
		for (i = 0; i < N; i++)
		{
			if (staff[i].number == n) {
				find = 1;
				break;
			}
		}
		if (find == 0) {
			printf("\n    δ�ҵ���Ա��,�����޸�������1,����������������0\n");
			scanf("%d", &round);
		}
		else {
			int m;
			char title[30] = { "����������1~8ѡ���޸�ѡ��:" };
			char dis[8][60] = {
			   {"1���޸�Ա�����ţ�"},
			   {"2���޸�Ա��������"},
			   {"3���޸�Ա���Ա�"},
			   {"4���޸�Ա���������ʣ�"},
			   {"5���޸�Ա��������"},
			   {"6���޸�Ա������"},
			   {"7���޸�Ա��ˮ��ѣ�"},
			   {"8���޸�Ա�����⣻"}
			};
			putout(dis, title, 8);
			scanf("%d", &m);
			switch (m)
			{
			case 1:
				printf("�������޸ĺ�Ĺ��ţ�");
				scanf("%d", &staff[i].number); break;
			case 2:
				printf("������Ҫ�޸ĺ������:");
				scanf("%s", &staff[i].name); break;
			case 3:
				printf("�������޸ĺ���Ա�:");
				scanf("%s", &staff[i].gender); break;
			case 4:
				printf("�������޸ĺ�Ļ������ʣ�");
				scanf("%lf", &staff[i].salary); break;
			case 5:
				printf("�������޸ĺ�Ĳ�����");
				scanf("%lf", &staff[i].allowance); break;
			case 6:
				printf("�������޸ĺ󽱽�");
				scanf("%lf", &staff[i].bous); break;
			case 7:
				printf("�������޸ĺ��ˮ��ѣ�");
				scanf("%lf", &staff[i].fee); break;
			case 8:
				printf("�������޸ĺ�ķ��⣺");
				scanf("%lf", &staff[i].rent); break;
			default:
				printf("�������");
			}
			if (m >= 4 && m <= 8) {
				staff[i].payment = staff[i].salary + staff[i].allowance + staff[i].bous - staff[i].fee - staff[i].rent;
			}
			printf("\n    �޸ĳɹ�,�����޸�������1,����������������0\n");
			scanf("%d", &round);

		}
	}
}
void sum(){
	int i;
	for(i=0;i<=N;i++){
		staff[i].payment=staff[i].salary+staff[i].allowance+staff[i].bous-staff[i].fee-staff[i].rent;
	}
	rank_h();//������������ 
}
void delete(){
	 int n;//�洢��Ҫɾ���Ĺ��� 
	 int i;
	 int find=0;//find��������Ƿ��ҵ�Ҫɾ���Ĺ���
	 int round=1;
	 while(round){
	 	system("cls");
		 printf("������Ҫɾ��Ա���Ĺ���:");
		 scanf("%d",&n);
		 for(i=0;i<N;i++)
		  {
		  	if(staff[i].number==n){
			  find=1;
			  break;
		      }
		  }
		 if(find==0){
		   printf("\n    δ�ҵ���Ա��,����ɾ��������1,����������������0\n");
		   scanf("%d",&round); 
		}
		 else{
		   for(;i<=N;i++)
			  staff[i]=staff[i+1];
		   	N--;
	 		printf("     ɾ����ɣ�\n����ɾ��������1������������������0\n");
	 		scanf("%d",&round);
	 		}
     }
     print_all();
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
	
	
//	printf("                  ��ѡ��");//ѡ����� 
	fflush(stdin);//���������
}
void BubbleSort(int n){
	int i,j;
    struct member sbb;
	switch(n){
		case 1://���� 
            for(i=0;i<N-1;i++){
			    for(j=1;j<N-i-1;j++){
				    if(staff[j].number>staff[j-1].number){
					    sbb=staff[j];
						staff[j]=staff[j-1];
						staff[j-1]=sbb;
					}
				}
			}
		    break;      
		case 2://���� 
            for(i=0;i<N-1;i++){
			    for(j=1;j<N-i-1;j++){
			        if(staff[j].salary>staff[j-1].salary){
				        sbb=staff[j];
					    staff[j]=staff[j-1];
					    staff[j-1]=sbb;
			    	}
		    	}
		    }
		    break;      
		case 3://���� 
            for(i=0;i<N-1;i++){
			    for(j=1;j<N-i-1;j++){
				    if(staff[j].allowance>staff[j-1].allowance){
					    sbb=staff[j];
						staff[j]=staff[j-1];
						staff[j-1]=sbb;
					}
				}
			}
			break;	  		
		case 4://���� 
            for(i=0;i<N-1;i++){
			    for(j=1;j<N-i-1;j++){
				    if(staff[j].bous>staff[j-1].bous){
					    sbb=staff[j];
						staff[j]=staff[j-1];
						staff[j-1]=sbb;
					}
				}
			}
		    break;
		case 5://ˮ��� 
		    for(i=0;i<N;i++){
			    for(j=1;j<N-i;j++){
				    if(staff[j].fee>staff[j-1].fee){
					    sbb=staff[j];
						staff[j]=staff[j-1];
						staff[j-1]=sbb;
					}
				}
			}
		    break;
		case 6://����
            for(i=0;i<N-1;i++){
			    for(j=1;j<N-i-1;j++){
				    if(staff[j].rent>staff[j-1].rent){
					    sbb=staff[j];
						staff[j]=staff[j-1];
						staff[j-1]=sbb;
					}
				}
			}
		    break;
		case 7://ʵ������
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
		if(staff[i].payment==staff[i-1].payment)
			staff[i].rank=staff[i-1].rank;
	}
}
void print_pass(int t,int n,int m){
	int i,s;s=n-m;if(t==0){for(i=0;i<s;i++)printf(" ");}
	else{for(i=0;i<s;i++)printf("--");}}
//������� 
void print_all(){
	system("cls");
	sum();
	int i,j,m;
    double m_nam,m_sal,m_all,m_bou,m_fee,m_ren,m_pay;
    int max_nam=strlen("����"),
	    max_sal=strlen("��������")-3,
		max_all=strlen("����")-3,
		max_bou=strlen("����")-3,
		max_fee=strlen("ˮ���")-3,
		max_ren=strlen("����")-3,
		max_pay=strlen("ʵ������")-3;
    int s_nam[N],s_sal[N],s_all[N],s_bou[N],s_fee[N],s_ren[N],s_pay[N];
    for(i=0;i<N;i++){
    	m_nam=strlen(staff[i].name);s_nam[i]=m_nam;j=0;
    	if(max_nam<m_nam)max_nam=m_nam;
    	//����������ʽ 
	    m_sal=staff[i].salary;j=0;
    	while(m_sal>=10){m_sal=m_sal/10;j++;};
    	s_sal[i]=j;if(max_sal<j)max_sal=j;
    	//���㹤�ʸ�ʽ 
    	m_all=staff[i].allowance;j=0;
    	while(m_all>=10){m_all=m_all/10;j++;};
    	s_all[i]=j;if(max_all<j)max_all=j;
    	//���㲹����ʽ
		m_bou=staff[i].bous;j=0;
		while(m_bou>=10){m_bou=m_bou/10;j++;};
		s_bou[i]=j;if(max_bou<j)max_bou=j;
		//���㽱���ʽ
		m_fee=staff[i].fee;j=0;
		while(m_fee>=10){m_fee=m_fee/10;j++;};
		s_fee[i]=j;if(max_fee<j)max_fee=j;
		//����ˮ��Ѹ�ʽ
		m_ren=staff[i].rent;j=0;
		while(m_ren>=10){m_ren=m_ren/10;j++;};
		s_ren[i]=j;if(max_ren<j)max_ren=j;
		//���㷿���ʽ
		m_pay=staff[i].payment;j=0;
		while(m_pay>=10){m_pay=m_pay/10;j++;};
		s_pay[i]=j;if(max_pay<j)max_pay=j;
		//����ʵ�����ʸ�ʽ 
	}
//	strlen(s)
    print_pass(1,4,2);print_pass(1,max_nam,0);print_pass(1,4,0);print_pass(1,max_sal,0);print_pass(1,max_all,0);print_pass(1,max_bou,0);print_pass(1,max_fee,0);print_pass(1,max_ren,0);print_pass(1,max_pay,0);print_pass(1,8,0);printf("\n"); 
    printf("|����");
    printf("|����");print_pass(0,max_nam,4);
    printf("|�Ա�");
	printf("|��������");print_pass(0,max_sal,4);
	printf("|����");print_pass(0,max_all+4,4);
	printf("|����");print_pass(0,max_bou+4,4);
	printf("|ˮ���");print_pass(0,max_fee+4,6);
	printf("|����");print_pass(0,max_ren+4,4);
	printf("|ʵ������");print_pass(0,max_pay+4,8);
	printf("|��������");
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
void search(){
	int choice,i,found=0,run=1,times;
	int s_id,s_rank;
	char s_name[20];//���� 
	char s_gender[2];//�Ա�
	sum();
	char title[30]={"����������1~4ѡ���ѯ��:"};
	char dis[4][60]={
	 	{"1������Ա�����Ų�ѯ��"},
	 	{"2������Ա��������ѯ��"},
		{"3������Ա���Ա��ѯ��"},
		{"4�����չ���������ѯ��"},
	 };
	putout(dis,title,4);
	scanf("%d",&choice);
	switch(choice){
		case 1:
			while(run){
				system("cls");
				printf("��������Ҫ��ѯ��Ա������:\n");
				scanf("%d",&s_id);
				for(i=0,times=0,found=0;i<N;i++){
					if(staff[i].number==s_id){
						found=1;
						break;
					}
				}
				if(found==1){
					printf("���� | ���� | �Ա� | �������� | ���� | ���� | ˮ��� | ���� | ʵ������ | ��������\n");
				 	printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f %.2f %d\n",staff[i].number,staff[i].name,staff[i].gender,staff[i].salary,staff[i].allowance,staff[i].bous,staff[i].fee,staff[i].rent,staff[i].payment,staff[i].rank);
				}else{
					printf("\n\n     δ�ҵ���Ա��,������������룡\n\n");
				}
				printf("�Ƿ���������Ų�ѯ����������1����������0\n");
				scanf("%d",&run);
			}
			break;
		case 2:
			while(run){
				system("cls");
				printf("��������Ҫ��ѯ��Ա������:\n");
				scanf("%s",s_name);
				for(i=0,times=0,found=0;i<N;i++){
					if(strcmp(s_name,staff[i].name)==0){
						found=1;
						break;
					}
				}
				if(found==1){
					printf("���� | ���� | �Ա� | �������� | ���� | ���� | ˮ��� | ���� | ʵ������ | ��������\n");
					printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f %.2f %d\n",staff[i].number,staff[i].name,staff[i].gender,staff[i].salary,staff[i].allowance,staff[i].bous,staff[i].fee,staff[i].rent,staff[i].payment,staff[i].rank);
				}else{
					printf("\n\n     δ�ҵ���Ա��,������������룡\n\n");
				}
				printf("�Ƿ������������ѯ����������1����������0\n");
				scanf("%d",&run);
			}
			break;
		case 3:
			while(run){
				system("cls");
				printf("��������Ҫ��ѯ��Ա���Ա�:\n");
				scanf("%s",s_gender);
				for(i=0,times=0,found=0;i<N;i++){
					if(strcmp(s_gender,staff[i].gender)==0){
						found=1;
						times++;
						if(times==1){
							printf("���� | ���� | �Ա� | �������� | ���� | ���� | ˮ��� | ���� | ʵ������ | ��������\n");
						}
						printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f %.2f %d\n",staff[i].number,staff[i].name,staff[i].gender,staff[i].salary,staff[i].allowance,staff[i].bous,staff[i].fee,staff[i].rent,staff[i].payment,staff[i].rank);
					}
				}
				if(found==0){
					printf("\n\n     δ�ҵ���Ա��,������������룡\n\n");
				}
				printf("�Ƿ�������Ա��ѯ����������1����������0\n");
				scanf("%d",&run);
			}
			break;
		case 4:
			while(run){
				system("cls");
				printf("��������Ҫ��ѯ��Ա������:\n");
				scanf("%d",&s_rank);
				for(i=0,times=0,found=0;i<N;i++){
					if(staff[i].rank==s_rank){
						found=1;
						times++;
						if(times==1){
							printf("���� | ���� | �Ա� | �������� | ���� | ���� | ˮ��� | ���� | ʵ������ | ��������\n");
						}
						printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f %.2f %d\n",staff[i].number,staff[i].name,staff[i].gender,staff[i].salary,staff[i].allowance,staff[i].bous,staff[i].fee,staff[i].rent,staff[i].payment,staff[i].rank);
					}
				}
				if(found==0){
					printf("\n\n     δ�ҵ���Ա��,������������룡\n\n");
				}
				printf("�Ƿ������������ѯ����������1����������0\n");
				scanf("%d",&run);
			}
			break;
		default:
			printf("��������");
			break;
	}
}
