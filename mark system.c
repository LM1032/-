#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>//用于短暂暂停
#include<time.h> //用于随机数函数
#define LEN 30//定义结构体数组长度
int len_Put;//统计输入个数 
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
void boom()//这是一个彩蛋 
{
	printf("\n\n\n\n\n			彭！程序出错了，等待杀一个吉祥物祭天看看能不能恢复:)\n");
	printf("			按任意键随机抽取一名吉祥物！\n");
	getch();
	srand((unsigned int )(time(NULL)));
	printf("			抽中 %d 号吉祥物！\n", rand() % 1+3);
}
/*void pro()//用于调试，懒得等 
{
	system("cls");
}*/ 
int pro()//这是一个进度条 
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
	printf("\n\n\n\n\n\n\n\n\n\n\n                                进程已完成，2秒后继续。\n");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n                                进程已完成，1秒后继续。\n");
	Sleep(1000);
	system("cls");
	return 0;
}
//这里是成绩录入
void input_Mark()//成绩录入
{
	int i,count=1;
	char flag; //判断是否退出
	system("cls");	
	for(i=0;i<LEN;i++)
	{
		printf("请输入学生学号：\n");
		scanf("%d",&student[i].numb);
	    printf("现在输入学生姓名：\n");
	    scanf(" %s",student[i].name);	        
	    printf("最后一步了，输入三科成绩，以空格隔开\n");
	    scanf("%f %f %f",&student[i].mark1,&student[i].mark2,&student[i].mark3);
	    count++;
	    len_Put=count-1;//用于统计输入多少组，便于后续排序
	    printf("完成一位学生录入，接下来是第 %d 位，若要退出请输入 E ,重输上一组请输 Z,输入N继续\n",count);
	    scanf(" %c",&flag);
	    if(flag=='E'||count==LEN)
	    	break;
	    else if(flag=='Z')
		    i-=1;
		else if(flag=='L')
		{
			printf("                                  居然不按提示输！给你个彩蛋吧！\n");
			boom();
		} 

	}
	printf("按任意键继续"); 
	getchar();
}
//成绩统计主菜单
void statistics_Mark()
{
	int i;
	float sum1=0,sum2=0,sum3=0,sum4=0;//未初始化导致答案错误
	printf("正在统计总成绩，请稍等！\n");
	for(i=0;i<len_Put;i++)
		{student[i].marksum=student[i].mark1+student[i].mark2+student[i].mark3;
		sum1+=student[i].mark1;
		sum2+=student[i].mark2;
		sum3+=student[i].mark3;
		sum4+=student[i].marksum;}
	pro();//这样看起来会比较有感觉
	printf("\n\n\n\n\n\n\n\n				第一科平均分为：%7.2f\n", sum1/len_Put);
	printf("				第二科平均分为：%7.2f\n", sum2/len_Put);
	printf("				第三科平均分为：%7.2f\n", sum3/len_Put);
	printf("				总成绩平均分为：%7.2f\n", sum4/len_Put);
	printf("				按任意键继续\n");
	getch();
}
//接下来是排序，其实可以建立一个数组集合，再传入一个参数，就可以只要两个函数，但是我懒的改，所以会很长 96-246
void qppxsum()//起泡法排序总成绩 
{
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].marksum<student[j+1].marksum)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				按总成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void qppxmark1()//起泡法排序 成绩一
{
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].mark1<student[j+1].mark1)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				按第一科成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch();  
}
void qppxmark2()//起泡法排序成绩二 
{ 
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].mark2<student[j+1].mark2)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				按第二科成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void qppxmark3()//起泡法排序成绩三 
{ 
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].mark3<student[j+1].mark3)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				按第三科成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student; p<student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch();  
}
void xzpxsum()//选择法排序总成绩 

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
	printf("				按总成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 

}
void xzpxmark1()//选择法排序成绩一 
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
	printf("				按第一科成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void xzpxmark2()//选择法排序成绩二 
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
	printf("				按第二科成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 

}
void xzpxmark3()//选择法排序成绩三 
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
	printf("				按第三科成绩排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 

}
void arr_numb()//学号排序 (起泡法) 
{
	int i,j;
	struct information *p=student;
	struct information temp;
	for(i=0;i<=len_Put-1;i++)
		for(j=0;j<len_Put-i;j++)
			if(student[j].numb>student[j+1].numb)
				{temp=student[j];student[j]=student[j+1];student[j+1]=temp;}
	pro();
	printf("				按学号排序完成\n");
	i=1;
	printf("学号	姓名	第一科		第二科		第三科		总成绩		名次\n");
	for(p=student+1; p<=student+len_Put;p++)
		{printf("%3d	%s	%6.2f		%6.2f		%6.2f		%6.2f		%2d\n", p->numb,p->name,p->mark1, p->mark2,p->mark3, p->marksum,i);i++;}
	printf("\n");
	getch(); 
}
void arr_Markb()//成绩排序主菜单
{
	void arr_Mark();
	int ch;
	while(1)
	{
		system("cls");
		printf("\n\n\n\n\n\n				学生成绩排序(选择法)\n");
		printf(" 				---------------\n");
		printf("				1--总成绩排序\n");
		printf(" 				2--第一科成绩排序\n");
		printf("				3--第二科成绩排序\n");
		printf("				4--第三科成绩排序\n");
		printf("				5--按学号排序\n");
		printf("				6--切换排序方式\n");
		printf("				0--退出程序\n");
		printf("  	   	  		---------------\n");
		printf("				输入相应数字选择对应功能：");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:printf("退出排序！\n");return;
			case 1:xzpxsum();break;
			case 2:xzpxmark1();break;
			case 3:xzpxmark2();break;
			case 4:xzpxmark3();break;
			case 5:arr_numb();break;
			case 6:printf("已切换为起泡排序\n");Sleep(1000);arr_Mark();
			default:printf("输入错误，请重新输入\n");	
		}
	printf("输入任意键继续\n");
	getchar();
	}
}
void arr_Mark()//成绩排序主菜单
{
	int ch;
	while(1)
	{
		system("cls");
		printf("\n\n\n\n\n\n				学生成绩排序(起泡法)\n");
		printf("				---------------\n");
		printf("				1--总成绩排序\n");
		printf(" 				2--第一科成绩排序\n");
		printf("				3--第二科成绩排序\n");
		printf("				4--第三科成绩排序\n");
		printf("				5--按学号排序\n");
		printf("				6--切换排序方式\n");
		printf("				0--退出程序\n");
		printf("  	   	  		---------------\n");
		printf("				输入相应数字选择对应功能：");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:printf("退出排序！\n");return;
			case 1:qppxsum();break;
			case 2:qppxmark1();break;
			case 3:qppxmark2();break;
			case 4:qppxmark3();break;
			case 5:arr_numb();break;
			case 6:printf("				已切换为选择排序\n");Sleep(1000);arr_Markb();
			default:printf("输入错误，请重新输入\n");
		}
	printf("				输入任意键继续\n");
	getchar();
	}
}

//接下来是成绩查找
void f_Max()//找最大成绩
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
	printf("				总成绩最高分为：%f\n",maxsum);
	printf("				第一科最高分为：%f\n",max1);
	printf("				第二科最高分为：%f\n",max2);
	printf("				第三科最高分为：%f\n",max3);


}
void f_Min()//最小的
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
	printf("				总成绩最低分为：%f\n",minsum);
	printf("				第一科最低分为：%f\n",min1);
	printf("				第二科最低分为：%f\n",min2);
	printf("				第三科最低分为：%f\n",min3);
}
void f_Arr()//找排名，有空的话建立三级目录，找单科排名:)
{	
	int i,count=1;
	float cj;
	printf("				请输入你的总成绩\n");
	scanf("%f",&cj);

	for(i=0;i<len_Put-1;i++)
		if(cj<student[i].marksum)
			count++;
	printf("				你的排名为:%d\n",count );

}
void inquire_Mark()//成绩查询
{
	int ch;
	while(1)
	{
		system("cls");
		printf("\n\n\n\n\n\n				学生成绩查询\n\n");
		printf("				 ------------------\n\n");
		printf("				1---查询最高分\n");
		printf("				2---查询最低分\n");
		printf("				3---查询成绩所在排名\n");
		printf("				0---退出查询\n\n");
		printf("				------------------\n");
		printf("            输入相应的数字选择对应功能：\n");
		scanf("%d",&ch);
		switch(ch)//与排序同理
		{
			case 0:printf("				退出查询\n");return;
			case 1:f_Max();break;
			case 2:f_Min();break;
			case 3:f_Arr();break;
			default:printf("				输错啦！\n");
		}
		printf("				任意键继续\n");
		getch();
	}
}
//接下来是写入文件
void file_put()//二进制写入 
{
	FILE *fp;
	int i;
	char filename[40];
	printf("				输入文件路径：");
	scanf("%s", filename);
	if((fp=fopen(filename,"wb"))==NULL)
	{printf("			错误，检查路径是否正确！\n");
	 return;}
	else
	{
		for(i=0;i<len_Put;i++)
			fwrite(&student[i], sizeof(struct information), 1, fp); // 二进制写入
		fclose(fp);
		pro();}
}
void file_get()//读取文字 ，不知道为什么可以打印出来但是之后不能用，现在都打印不出来了呢:) 
{
	FILE *fp;
	int i; 
	char filename[40];
	printf("				输入要录入人数：");
	scanf("%d",&len_Put);//这里分号扩错了。。。他也不报错，真的是 
	printf("				输入文件路径：");
	scanf(" %s", filename);
	fp=fopen(filename,"rb");
	if(fp==NULL)
		{printf("				错误，检查路径是否正确！\n");exit(0);} 
	else
	{
		fseek(fp,0,0); 
		for(i=0;i<len_Put;i++)
			fread(&student[i], sizeof(struct information), 1, fp); // 二进制写入
		fclose(fp);}
	for(i=0;i<len_Put;i++)
		printf("%d %s %.2f %.2f %.2f %.2f\n",student[i].numb,student[i].name,student[i].mark1,student[i].mark2,student[i].mark3,student[i].marksum);
	Sleep(500);
}
void file_wput()//TXT写出 
{
	FILE *fp;
	int i;
	char filename[40];
	printf("				输入文件路径：");
	scanf("%s", filename);
	if((fp=fopen(filename,"w"))==NULL)
	{printf("				错误，检查路径是否正确！\n");return;}
	else
	{	
		for(i=0;i<len_Put;i++)
			fprintf(fp,"%d,%s,%.2f,%.2f,%.2f,%.2f\n",student[i].numb,student[i].name,student[i].mark1,student[i].mark2,student[i].mark3,student[i].marksum);
		fclose(fp);
		pro();}
}
void file_wget()//读取TXT到数组 
{
	int i=0;
	FILE *fp;
	char filename[40];
	printf("				输入要录入人数：");
	scanf("%d",&len_Put);
	printf("				输入文件路径：");
	scanf("%s",filename); 
	fp=fopen(filename,"r"); 
	if(fp==NULL)
		{printf("				错误，检查路径是否正确！\n");exit(0);}
	fseek(fp,0,0); 
	for(i=0;i<len_Put;i++) 
		fscanf(fp,"%d,%s,%f,%f,%f,%f\n",&student[i].numb,student[i].name,&student[i].mark1,&student[i].mark2,&student[i].mark3,&student[i].marksum);
	fclose(fp);
	for(i=0;i<len_Put;i++)
		{printf("				已读取%d组数据\n",i+1);
		printf("%d %s %.2f %.2f %.2f %.2f\n",student[i].numb,student[i].name,student[i].mark1,student[i].mark2,student[i].mark3,student[i].marksum);
		Sleep(500);} 
	}
void print_Markb()//写入文件
{
	void print_Mark();
	int ch;
    while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\n\n				   TXT文件系统\n");
		printf("				----------------\n"); 
    	printf("				1--录入文件\n");
    	printf("				2--从文件中读取\n");
		printf("				3--切换输入方式\n");
		printf("				0--退出文件\n"); 
		printf("				----------------\n"); 
		printf("                           输入相应的数字选择对应功能：");
    	scanf("%d",&ch); 
		switch (ch)
		{
			case 0:return;	
			case 1:file_wput();break;
			case 2:file_wget();break;
			case 3:pro();printf("				已切换为二进制文本\n");Sleep(400);print_Mark();;
			default:printf("输入有误，请检查输入数字并重新输入\n");//不知道为什么要输两次 
		}
	}
	printf("				按任意键继续。\n");
    getch();
}
void print_Mark()//写入文件
{
	int ch;
    while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\n\n				   二进制文件系统\n");
		printf("				----------------\n"); 
    	printf("				1--录入文件\n");
    	printf("				2--从文件中读取\n");
		printf("				3--切换输入方式\n");
		printf("				0--退出文件\n"); 
		printf("				----------------\n"); 
		printf("                           输入相应的数字选择对应功能：");
    	scanf("%d",&ch); 
    	switch(ch)
    	{
    		case 0:return;
    		case 1:file_put();break;
    		case 2:file_get();break;
			case 3:pro();printf("				已切换为TXT文本\n");Sleep(400);print_Markb();
			default:printf("输入有误，请检查输入数字并重新输入\n");
		}	
    printf("				按任意键继续。\n");
    getch();
	}		
}
////////////////////////////////////////////////////////////////////////////////
//这里是主函数
int main()
{
	int ch;
	system("color 3f");//设定背景色与字体颜色
	system("mode con cols=90 lines=30");//设定弹窗大小
    while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\n\n			  	  学生成绩管理系统\n");
    	printf("			   \n");
    	printf("                                ----------------------\n");
    	printf("                                  1---学生成绩输入\n");
    	printf("                                  2---学生成绩统计\n");
    	printf("                                  3---学生成绩排序\n");
    	printf("                                  4---学生成绩查询\n");
    	printf("                                  5---学生成绩文件\n");
    	printf("                                  0---退出系统\n");
    	printf("                                -----------------------\n\n");
    	printf("                                输入相应的数字选择对应功能：");
    	scanf("%d",&ch); 
    	switch(ch)
    	{
    		case 0:printf("退出系统\n");exit(0);
    		case 1:input_Mark();break;//录入函数
    		case 2:statistics_Mark();break;//统计函数
    		case 3:arr_Mark();break;//排序函数
    		case 4:inquire_Mark();break;//查询函数
    		case 5:print_Mark();break;//打印函数
    		default:printf("输入有误，请检查输入数字并重新输入\n");
    	}
    	printf("按任意键继续。\n");//不知名原因他会打印两次，前面的同一语句也这样:)
    	getch();	
    }
	return 0;
}
