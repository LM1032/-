#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>//���ڶ�����ͣ
#include<time.h> //�������������
#define LEN 30//����ṹ�����鳤��
int len_Put;//ͳ��������� 
struct information
{
	int numb;
	char name[10];
	float mark1;
	float mark2;
	float mark3;
	float marksum;
};
struct information student[LEN+1];
void boom()//����һ���ʵ� 
{
	printf("\n\n\n\n\n			����������ˣ��ȴ�ɱһ����������쿴���ܲ��ָܻ�:)\n");
	printf("			������������ȡһ�������\n");
	getch();
	srand((unsigned int )(time(NULL)));
	printf("			���� %d �ż����\n", rand() % 1+3);
}
/*void pro()//���ڵ��ԣ����õ� 
{
	system("cls");
}*/ 
int pro()//����һ�������� 
{
	char ch=16;
	int i,j,k=0;
	system("cls");
	for(i=0;i<=30;i+=3)
		{printf("\n\n\n\n\n\n\n\n\n\n\n                       " );
		for(j=i;j>0;j--)
			printf("%c", ch);
		printf(" %d %% \n", k);
		k+=10;	
		Sleep(100);
		system("cls");}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n                                ��������ɣ�2��������\n");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n                                ��������ɣ�1��������\n");
	Sleep(1000);
	system("cls");
	return 0;
}
//�����ǳɼ�¼��
void input_Mark()//�ɼ�¼��
{
	int i,count=1;
	char flag; //�ж��Ƿ��˳�
	system("cls");	
	for(i=0;i<LEN;i++)
	{
		printf("������ѧ��ѧ�ţ�\n");
		scanf("%d",&student[i].numb);
	    printf("��������ѧ��������\n");
	    scanf(" %s",student[i].name);	        
	    printf("���һ���ˣ��������Ƴɼ����Կո����\n");
	    scanf("%f %f %f",&student[i].mark1,&student[i].mark2,&student[i].mark3);
	    count++;
	    len_Put=count-1;//����ͳ����������飬���ں�������
	    printf("���һλѧ��¼�룬�������ǵ� %d λ����Ҫ�˳������� E ,������һ������ Z,����N����\n",count);
	    scanf(" %c",&flag);
	    if(flag=='E'||count==LEN)
	    	break;
	    else if(flag=='Z')
		    i-=1;
		else if(flag=='L')
		{
			printf("                                  ��Ȼ������ʾ�䣡������ʵ��ɣ�\n");
			boom();
		} 

	}
	printf("�����������"); 
	getchar();
}
//�ɼ�ͳ�����˵�
void statistics_Mark()
{
	int i;
	float sum1=0,sum2=0,sum3=0,sum4=0;//δ��ʼ�����´𰸴���
	printf("����ͳ���ܳɼ������Եȣ�\n");
	for(i=0;i<len_Put;i++)
		{student[i].marksum=student[i].mark1+student[i].mark2+student[i].mark3;
		sum1+=student[i].mark1;
		sum2+=student[i].mark2;
		sum3+=student[i].mark3;
		sum4+=student[i].marksum;}
	pro();//������������Ƚ��ио�
	printf("\n\n\n\n\n\n\n\n				��һ��ƽ����Ϊ��%7.2f\n", sum1/len_Put);
	printf("				�ڶ���ƽ����Ϊ��%7.2f\n", sum2/len_Put);
	printf("				������ƽ����Ϊ��%7.2f\n", sum3/len_Put);
	printf("				�ܳɼ�ƽ����Ϊ��%7.2f\n", sum4/len_Put);
	printf("				�����������\n");
	getch();
}
//��������������ʵ���Խ���һ�����鼯�ϣ��ٴ���һ���������Ϳ���ֻҪ�������������������ĸģ����Ի�ܳ� 96-246
void qppxsum()//���ݷ������ܳɼ� 
{
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].marksum<student[j+1].marksum)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				���ܳɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void qppxmark1()//���ݷ����� �ɼ�һ
{
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].mark1<student[j+1].mark1)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				����һ�Ƴɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch();  
}
void qppxmark2()//���ݷ�����ɼ��� 
{ 
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].mark2<student[j+1].mark2)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				���ڶ��Ƴɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void qppxmark3()//���ݷ�����ɼ��� 
{ 
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].mark3<student[j+1].mark3)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				�������Ƴɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch();  
}
void xzpxsum()//ѡ�������ܳɼ� 

{
	int i,j,k;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-2;i++)
	{
		k=i;
		for(j=i+1;j<len_Put;j++)
			if(student[k].marksum>student[j].marksum) k=j;
				temp=student[i];student[i]=student[k];student[k]=temp;
	}
	pro();
	printf("				���ܳɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 

}
void xzpxmark1()//ѡ������ɼ�һ 
{
	int i,j,k;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-2;i++)
	{
		k=i;
		for(j=i+1;j<len_Put;j++)
			if(student[k].mark1>student[j].mark1) k=j;
				temp=student[i];student[i]=student[k];student[k]=temp;
	}
	pro();
	printf("				����һ�Ƴɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void xzpxmark2()//ѡ������ɼ��� 
{
	int i,j,k;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-2;i++)
	{
		k=i;
		for(j=i+1;j<len_Put;j++)
			if(student[k].mark2>student[j].mark2) k=j;
				temp=student[i];student[i]=student[k];student[k]=temp;
	}
	pro();
	printf("				���ڶ��Ƴɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 

}
void xzpxmark3()//ѡ������ɼ��� 
{
	int i,j,k;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-2;i++)
	{
		k=i;
		for(j=i+1;j<len_Put;j++)
			if(student[k].mark3>student[j].mark3) k=j;
				temp=student[i];student[i]=student[k];student[k]=temp;
	}
	pro();
	printf("				�������Ƴɼ��������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 

}
void arr_numb()//ѧ������ (���ݷ�) 
{
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].numb>student[j+1].numb)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				��ѧ���������\n");
	i=1;
	printf("ѧ��	����	��һ��		�ڶ���		������		�ܳɼ�		����\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void arr_Markb()//�ɼ��������˵�
{
	void arr_Mark();
	int ch;
	while(1)
	{
		system("cls");
		printf("\n\n\n\n\n\n				ѧ���ɼ�����(ѡ��)\n");
		printf(" 				---------------\n");
		printf("				1--�ܳɼ�����\n");
		printf(" 				2--��һ�Ƴɼ�����\n");
		printf("				3--�ڶ��Ƴɼ�����\n");
		printf("				4--�����Ƴɼ�����\n");
		printf("				5--��ѧ������\n");
		printf("				6--�л�����ʽ\n");
		printf("				0--�˳�����\n");
		printf("  	   	  		---------------\n");
		printf("				������Ӧ����ѡ���Ӧ���ܣ�");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:printf("�˳�����\n");return;
			case 1:xzpxsum();break;
			case 2:xzpxmark1();break;
			case 3:xzpxmark2();break;
			case 4:xzpxmark3();break;
			case 5:arr_numb();break;
			case 6:printf("���л�Ϊ��������\n");Sleep(1000);arr_Mark();
			default:printf("�����������������\n");	
		}
	printf("�������������\n");
	getchar();
	}
}
void arr_Mark()//�ɼ��������˵�
{
	int ch;
	while(1)
	{
		system("cls");
		printf("\n\n\n\n\n\n				ѧ���ɼ�����(���ݷ�)\n");
		printf("				---------------\n");
		printf("				1--�ܳɼ�����\n");
		printf(" 				2--��һ�Ƴɼ�����\n");
		printf("				3--�ڶ��Ƴɼ�����\n");
		printf("				4--�����Ƴɼ�����\n");
		printf("				5--��ѧ������\n");
		printf("				6--�л�����ʽ\n");
		printf("				0--�˳�����\n");
		printf("  	   	  		---------------\n");
		printf("				������Ӧ����ѡ���Ӧ���ܣ�");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:printf("�˳�����\n");return;
			case 1:qppxsum();break;
			case 2:qppxmark1();break;
			case 3:qppxmark2();break;
			case 4:qppxmark3();break;
			case 5:arr_numb();break;
			case 6:printf("				���л�Ϊѡ������\n");Sleep(1000);arr_Markb();
			default:printf("�����������������\n");
		}
	printf("				�������������\n");
	getchar();
	}
}

//�������ǳɼ�����
void f_Max()//�����ɼ�
{
	int i;
	float max1,max2,max3,maxsum;
	maxsum=student[0].marksum;
	for(i=0;i<len_Put;i++)
		if(maxsum<student[i].marksum)
			maxsum=student[i].marksum;
	max1=student[0].mark1;
	for(i=0;i<len_Put;i++)
		if(max1<student[i].mark1)
			max1=student[i].mark1;
	max2=student[0].mark2;
	for(i=0;i<len_Put;i++)
		if(max2<student[i].mark2)
			max2=student[i].mark2;
	max3=student[0].mark3;
	for(i=0;i<len_Put;i++)
		if(max3<student[i].mark3)
			max3=student[i].mark3;
	printf("				�ܳɼ���߷�Ϊ��%f\n",maxsum);
	printf("				��һ����߷�Ϊ��%f\n",max1);
	printf("				�ڶ�����߷�Ϊ��%f\n",max2);
	printf("				��������߷�Ϊ��%f\n",max3);


}
void f_Min()//��С��
{
	int i;
	float minsum,min1,min2,min3;
	minsum=student[0].marksum;
	for(i=0;i<len_Put;i++)
		if(minsum>student[i].marksum)
			minsum=student[i].marksum;
	min1=student[0].mark1;
	for(i=0;i<len_Put;i++)
		if(min1>student[i].mark1)
			min1=student[i].mark1;
	min2=student[0].mark2;
	for(i=0;i<len_Put;i++)
		if(min2>student[i].mark2)
			min2=student[i].mark2;
	min3=student[0].mark3;
	for(i=0;i<len_Put;i++)
		if(min3>student[i].mark3)
			min1=student[i].mark3;
	printf("				�ܳɼ���ͷ�Ϊ��%f\n",minsum);
	printf("				��һ����ͷ�Ϊ��%f\n",min1);
	printf("				�ڶ�����ͷ�Ϊ��%f\n",min2);
	printf("				��������ͷ�Ϊ��%f\n",min3);
}
void f_Arr()//���������пյĻ���������Ŀ¼���ҵ�������:)
{	
	int i,count=1;
	float cj;
	printf("				����������ܳɼ�\n");
	scanf("%f",&cj);

	for(i=0;i<len_Put-1;i++)
		if(cj<student[i].marksum)
			count++;
	printf("				�������Ϊ:%d\n",count );

}
void inquire_Mark()//�ɼ���ѯ
{
	int ch;
	while(1)
	{
		system("cls");
		printf("\n\n\n\n\n\n				ѧ���ɼ���ѯ\n\n");
		printf("				 ------------------\n\n");
		printf("				1---��ѯ��߷�\n");
		printf("				2---��ѯ��ͷ�\n");
		printf("				3---��ѯ�ɼ���������\n");
		printf("				0---�˳���ѯ\n\n");
		printf("				------------------\n");
		printf("            ������Ӧ������ѡ���Ӧ���ܣ�\n");
		scanf("%d",&ch);
		switch(ch)//������ͬ��
		{
			case 0:printf("				�˳���ѯ\n");return;
			case 1:f_Max();break;
			case 2:f_Min();break;
			case 3:f_Arr();break;
			default:printf("				�������\n");
		}
		printf("				���������\n");
		getch();
	}
}
//��������д���ļ�
void file_put()//������д�� 
{
	FILE *fp;
	int i;
	char filename[40];
	printf("				�����ļ�·����");
	scanf("%s", filename);
	if((fp=fopen(filename,"wb"))==NULL)
	{printf("			���󣬼��·���Ƿ���ȷ��\n");
	 return;}
	else
	{
		for(i=0;i<len_Put;i++)
			fwrite(&student[i], sizeof(struct information), 1, fp); // ������д��
		fclose(fp);
		pro();}
}
void file_get()//��ȡ���� ����֪��Ϊʲô���Դ�ӡ��������֮�����ã����ڶ���ӡ����������:) 
{
	FILE *fp;
	int i; 
	char filename[40];
	printf("				����Ҫ¼��������");
	scanf("%d",&len_Put);//����ֺ������ˡ�������Ҳ����������� 
	printf("				�����ļ�·����");
	scanf(" %s", filename);
	fp=fopen(filename,"rb");
	if(fp==NULL)
		{printf("				���󣬼��·���Ƿ���ȷ��\n");exit(0);} 
	else
	{
		fseek(fp,0,0); 
		for(i=0;i<len_Put;i++)
			fread(&student[i], sizeof(struct information), 1, fp); // ������д��
		fclose(fp);}
	for(i=0;i<len_Put;i++)
		printf("%d %s %.2f %.2f %.2f %.2f\n",student[i].numb,student[i].name,student[i].mark1,student[i].mark2,student[i].mark3,student[i].marksum);
	Sleep(500);
}
void file_wput()//TXTд�� 
{
	FILE *fp;
	int i;
	char filename[40];
	printf("				�����ļ�·����");
	scanf("%s", filename);
	if((fp=fopen(filename,"w"))==NULL)
	{printf("				���󣬼��·���Ƿ���ȷ��\n");return;}
	else
	{	
		for(i=0;i<len_Put;i++)
			fprintf(fp,"%d,%s,%.2f,%.2f,%.2f,%.2f\n",student[i].numb,student[i].name,student[i].mark1,student[i].mark2,student[i].mark3,student[i].marksum);
		fclose(fp);
		pro();}
}
void file_wget()//��ȡTXT������ 
{
	int i=0;
	FILE *fp;
	char filename[40];
	printf("				����Ҫ¼��������");
	scanf("%d",&len_Put);
	printf("				�����ļ�·����");
	scanf("%s",filename); 
	fp=fopen(filename,"r"); 
	if(fp==NULL)
		{printf("				���󣬼��·���Ƿ���ȷ��\n");exit(0);}
	fseek(fp,0,0); 
	for(i=0;i<len_Put;i++) 
		fscanf(fp,"%d,%s,%f,%f,%f,%f\n",&student[i].numb,student[i].name,&student[i].mark1,&student[i].mark2,&student[i].mark3,&student[i].marksum);
	fclose(fp);
	for(i=0;i<len_Put;i++)
		{printf("				�Ѷ�ȡ%d������\n",i+1);
		printf("%d %s %.2f %.2f %.2f %.2f\n",student[i].numb,student[i].name,student[i].mark1,student[i].mark2,student[i].mark3,student[i].marksum);
		Sleep(500);} 
	}
void print_Markb()//д���ļ�
{
	void print_Mark();
	int ch;
    while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\n\n				   TXT�ļ�ϵͳ\n");
		printf("				----------------\n"); 
    	printf("				1--¼���ļ�\n");
    	printf("				2--���ļ��ж�ȡ\n");
		printf("				3--�л����뷽ʽ\n");
		printf("				0--�˳��ļ�\n"); 
		printf("				----------------\n"); 
		printf("                           ������Ӧ������ѡ���Ӧ���ܣ�");
    	scanf("%d",&ch); 
		switch (ch)
		{
			case 0:return;	
			case 1:file_wput();break;
			case 2:file_wget();break;
			case 3:pro();printf("				���л�Ϊ�������ı�\n");Sleep(400);print_Mark();;
			default:printf("�������������������ֲ���������\n");//��֪��ΪʲôҪ������ 
		}
	}
	printf("				�������������\n");
    getch();
}
void print_Mark()//д���ļ�
{
	int ch;
    while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\n\n				   �������ļ�ϵͳ\n");
		printf("				----------------\n"); 
    	printf("				1--¼���ļ�\n");
    	printf("				2--���ļ��ж�ȡ\n");
		printf("				3--�л����뷽ʽ\n");
		printf("				0--�˳��ļ�\n"); 
		printf("				----------------\n"); 
		printf("                           ������Ӧ������ѡ���Ӧ���ܣ�");
    	scanf("%d",&ch); 
    	switch(ch)
    	{
    		case 0:return;
    		case 1:file_put();break;
    		case 2:file_get();break;
			case 3:pro();printf("				���л�ΪTXT�ı�\n");Sleep(400);print_Markb();
			default:printf("�������������������ֲ���������\n");
		}	
    printf("				�������������\n");
    getch();
	}		
}
////////////////////////////////////////////////////////////////////////////////
//������������
int main()
{
	int ch;
	system("color 3f");//�趨����ɫ��������ɫ
	system("mode con cols=90 lines=30");//�趨������С
    while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\n\n			  	  ѧ���ɼ�����ϵͳ\n");
    	printf("			   \n");
    	printf("                                ----------------------\n");
    	printf("                                  1---ѧ���ɼ�����\n");
    	printf("                                  2---ѧ���ɼ�ͳ��\n");
    	printf("                                  3---ѧ���ɼ�����\n");
    	printf("                                  4---ѧ���ɼ���ѯ\n");
    	printf("                                  5---ѧ���ɼ��ļ�\n");
    	printf("                                  0---�˳�ϵͳ\n");
    	printf("                                -----------------------\n\n");
    	printf("                                ������Ӧ������ѡ���Ӧ���ܣ�");
    	scanf("%d",&ch); 
    	switch(ch)
    	{
    		case 0:printf("�˳�ϵͳ\n");exit(0);
    		case 1:input_Mark();break;//¼�뺯��
    		case 2:statistics_Mark();break;//ͳ�ƺ���
    		case 3:arr_Mark();break;//������
    		case 4:inquire_Mark();break;//��ѯ����
    		case 5:print_Mark();break;//��ӡ����
    		default:printf("�������������������ֲ���������\n");
    	}
    	printf("�������������\n");//��֪��ԭ�������ӡ���Σ�ǰ���ͬһ���Ҳ����:)
    	getch();	
    }
	return 0;
}
