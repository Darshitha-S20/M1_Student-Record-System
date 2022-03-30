#include<stdio.h>
#include <stdlib.h>

static int n=0;
struct STUDENT
{
	int age,roll_no,maths,science,english,total;
	char name[10];
	float avg;
};
int main()
{
	void add();
	void displayAll();
	void record();
	void del();
	void marksheet();
	void modify();
	int i,count=0,a,n=0,r,m,ms;
	printf("\n\t\t\t\t********************************************************\n");
	printf("\n\t\t\t\t\t\t   STUDENT RECORD SYSTEM\n");
	printf("\n\t\t\t\t********************************************************\n");

		while(1)
		{
		printf("\n----------------------");
		printf("\nChoose any option from below");
		printf("\n----------------------");
		printf("\n1.Add a record");
		printf("\n2.Delete a record");
		printf("\n3.Modify a record");
		printf("\n4.Generate marksheet");
		printf("\n5.Search a record");
		printf("\n6.Display all records");
		printf("\n7.Exit");
		printf("\n----------------------\n");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
			{
				
				add();	
				break;
			}
			case 2:
			{	
				
				del();
				break;
			}
			case 3:
			{
				
				modify();
				break;
			}
			case 4:
			{
				marksheet();
				break;	
			}
			case 5:
			{
				record();
				break;
			}
			case 6:
			{
				displayAll();
				break;
			}
			case 7:
			{
				exit(0);
			}
				
		}
	}	
}
void add()
{
		int i;
		struct STUDENT s;
		int size;
		FILE *fp;
		size=sizeof(s);
		fp=fopen("record.dat","ab");
 		printf("\nEnter Roll no for record\n");
		scanf("%d",&s.roll_no);
		printf("Enter Name\n");
		scanf("%s",s.name);
		printf("Enter Age\n");
		scanf("%d",&s.age);
		printf("Enter Maths Marks\n");
		scanf("%d",&s.maths);
		printf("Enter Science Marks\n");
		scanf("%d",&s.science);
		printf("Enter English Marks\n");
		scanf("%d",&s.english);
		s.total=s.maths+s.science+s.english;
		s.avg=s.total/3;
		fwrite(&s,size,1,fp);
		fclose(fp);	
		printf("\n New Record Successfully Added.");
}


void displayAll()
{
FILE *fp;
struct STUDENT s;

fp=fopen("record.dat","rb");

printf("\n******************************************************\n\n");
printf("\t\t All Student Details\n\n");
printf("********************************************************\n\n");


while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
		printf("\nRollno:%d\t",s.roll_no);
		printf("Name:%s\t",s.name);
		printf("Age:%d\t",s.age);
		printf("Total:%d\n",s.total);
}
printf("*********************************************************\n\n");

fclose(fp);
}
void record()
{
FILE *fp;
struct STUDENT s;
int id,found=0;
fp=fopen("record.dat","rb");
printf("\nEnter the student roll no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
printf("\n******************************************************\n\n");
printf("\t\t Student Record of %d\n\n",s.roll_no);
printf("********************************************************\n\n");

		printf("Rollno:%d\t",s.roll_no);
		printf("Name:%s\t",s.name);
		printf("Age:%d\t",s.age);
		printf("Total:%d\n",s.total);

printf("*********************************************************\n\n");
}
}
if(found==0)
{
printf("\nNo Record Found");
}
fclose(fp);
}
void del()
{
FILE *fp,*fp1;
struct STUDENT s,s1;
int id,found=0;

fp=fopen("record.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter Student Roll No to be Deleted:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("No Record Found\n\n");
}
else
{
fp=fopen("record.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}
}
fclose(fp);
fclose(fp1);
}
void marksheet()
{
FILE *fp;
struct STUDENT s;
int id,found=0;
fp=fopen("record.dat","rb");
printf("\nEnter the student roll no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
printf("\n******************************************************\n\n");
printf("\t\t Student Marksheet of %d\n\n",s.roll_no);
printf("********************************************************\n\n");

		printf("Rollno:%d\t",s.roll_no);
		printf("Name:%s\t",s.name);
		printf("Maths:%d\t",s.maths);
		printf("Science:%d\t",s.science);
		printf("English:%d\t",s.english);
		printf("Total marks scored:%d\t",s.total);
		printf("Average:%2f\n",s.avg);

printf("**********************************************************\n\n");
}
}
if(found==0)
{
printf("\n No Record Found");
}
fclose(fp);
}
void modify()
{
FILE *fp,*fp1;
struct STUDENT s;
int id,found=0;

fp=fopen("record.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter Student Roll No to be modified:");
scanf("%d",&id);

while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
		printf("Enter Roll No for record\n");
		scanf("%d",&s.roll_no);	
		//fflush(stdin);
		printf("Enter Name\n");
		scanf("%s",s.name);
		printf("Enter Age\n");
		scanf("%d",&s.age);
		printf("Enter Maths Marks\n");
		scanf("%d",&s.maths);
		printf("Enter Science Marks\n");
		scanf("%d",&s.science);
		printf("Enter English Marks\n");
		scanf("%d",&s.english);
		s.total=s.maths+s.science+s.english;
		s.avg=s.total/3;
fwrite(&s,sizeof(s),1,fp1);
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf(" No Record Found\n\n");
}
else
{
fp=fopen("record.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}

}
fclose(fp);
fclose(fp1);
}

