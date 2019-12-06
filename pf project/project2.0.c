#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
//#include "phy.h"
struct customer
{
	char name[25];
	int id;	//system assigned
	int costofcourse;	//cost of selected course  
	int instructselect;
	int costofinstructor;	//cost of instructor if applied for
	char selectedcourse[25];	//number of selected course
	int daye, monthe, yeare;	//date of admission/entry
	float bmi;	//days before payment
	int counter;	//counter for id assignment
}

c;
void add()
{
	float h, w;
	printf("enter name\n");
	fflush(stdin);
	gets(c.name);
	printf("enter height(cm) and weight(kg)");
	scanf("%f%f", &h, &w);
	h = h / 100;
	c.bmi = w / (h *h);
	if (c.bmi <= 18.5)
	{
		printf("\nRecommended Weightlifting.");
	}
	else if (c.bmi <= 24.9)
	{
		printf("\nRecommended Weightlifting.");
	}
	else if (c.bmi <= 29.9)
	{
		printf("\nRecommended Cardio.");
	}
	else if (c.bmi > 29.9)
	{
		printf("\nRecommended Full course(pakage).");
	}

	printf("\n\nSelect course\n1.Weightlifting Rs1800\n2.swimming Rs2000\n3.Cardio Rs1200\n4.sauna Rs1000\n5.Full course(pakage) Rs 3000\n");
	int courseselect;
	fflush(stdin);
	scanf("%d", &courseselect);
	if (courseselect == 1)
	{
		c.costofcourse = 1800;
		strcpy(c.selectedcourse, "Weightlifting");
	}

	if (courseselect == 2)
	{
		c.costofcourse = 2000;
		strcpy(c.selectedcourse, "swimming");
	}

	if (courseselect == 3)
	{
		c.costofcourse = 1200;
		strcpy(c.selectedcourse, "Cardio");
	}

	if (courseselect == 4)
	{
		c.costofcourse = 1000;
		strcpy(c.selectedcourse, "Suana");
	}

	if (courseselect == 5)
	{
		c.costofcourse += 3000;
		strcpy(c.selectedcourse, "fullcourse");
	}

	printf("\nRequire Instructor? (Y/N)\n");
	char instructorchoice;
	fflush(stdin);
	scanf("%c", &instructorchoice);
	fflush(stdin);
	c.instructselect = 0;
	if (instructorchoice == 'y' || instructorchoice == 'Y')
	{
		c.instructselect = 1;
		if (courseselect == 1)
		{
			printf("\nInstructor of weightlifting available in only following time slots\n");
			printf("\nchoose Time slot\n1. 8am-12am\n2. 3pm-5pm\n3. 8pm-10pm");
			int instructortime;
			scanf("%d", &instructortime);
			if (instructortime == 1)
			{
				c.costofcourse = c.costofcourse + 1000;
				c.costofinstructor = 1000;
			}

			if (instructortime == 2)
			{
				c.costofcourse = c.costofcourse + 900;
				c.costofinstructor = 900;
			}

			if (instructortime == 3)
			{
				c.costofcourse = c.costofcourse + 1200;
				c.costofinstructor = 1200;
			}
		}

		if (courseselect == 2)
		{
			printf("\nInstructor of swimming available in only following time slots\n");
			printf("\nchoose Time slot\n1. 8am-12am\n2. 3pm-5pm\n");
			int instructortime;
			scanf("%d", &instructortime);
			if (instructortime == 1)
			{
				c.costofcourse = c.costofcourse + 1200;
				c.costofinstructor = 1200;
			}

			if (instructortime == 2)
			{
				c.costofcourse = c.costofcourse + 800;
				c.costofinstructor = 800;
			}
		}

		if (courseselect == 3 || courseselect == 4)
		{
			printf("\nNo instructor.\n");
			c.instructselect = 0;
		}

		if (courseselect == 5)
		{
			c.costofcourse = c.costofcourse + 2000;
			c.costofinstructor = 2000;
		}
	}
}

void displayall()
{
	int custnum = 1;
	printf("\n%d)NAME: %s\n ID number: %d\n total cost of course: %d\n last paymet: %d-%d-%d ", custnum, c.name, c.id, c.costofcourse, c.daye, c.monthe, c.yeare);
	//	printf("BMI:%f",c.bmi);
	if (c.bmi <= 18.5)
	{
		printf("\nYour BMI is %f: Underweight.", c.bmi);
	}
	else if (c.bmi <= 24.9)
	{
		printf("\nYour BMI is %f: Normal.", c.bmi);
	}
	else if (c.bmi <= 29.9)
	{
		printf("\nYour BMI is %f: Overweight.", c.bmi);
	}
	else if (c.bmi > 29.9)
	{
		printf("\nYour BMI is %f: Obese.", c.bmi);
	} 

	if (c.instructselect == 1)
	{
		printf("\n Instructor fee(Included in total cost) : %d", c.costofinstructor);
	}

	if (c.instructselect == 0)
	{
		printf("\n NO instructor");
	}

	printf("\n selected course : %s\n\n", c.selectedcourse);
}

int main()
{
	system("COLOR F0");
	char password[15] = "pass";	//password code
	char userinput[10];
	start:
		printf("Input Password:");
	fflush(stdin);
	gets(userinput);
	if ((strcmp(userinput, password)) == 0)
	{
		system("cls");
	}
	else if ((strcmp(userinput, password)) != 0)
	{
		system("cls");
		printf("\ninvalid password\n");
		goto start;
	}

	int day, month, year;	//date entry code start
	datestart:
		printf("Input date format in numbers(dd/mm/yyyy)\n");
	day:
		printf("input day\n");
	scanf("%d", &day);
	if (day > 31 || day == 0)
	{
		printf("Invalid day entry\n");
		goto day;
	}

	month:
		printf("input month\n");
	scanf("%d", &month);
	if (month > 12 || month == 0)
	{
		printf("Invalid month entry\n");
		goto month;
	}

	year:
		printf("input year\n");
	scanf("%d", &year);
	if (year < 2000 || year == 0)
	{
		printf("Invalid year entry\n");
		goto year;
	}

	printf("Your Input date %d-%d-%d\nCorrect(Y/N)  ", day, month, year);
	fflush(stdin);
	char correctchoice;
	scanf("%c", &correctchoice);
	if (correctchoice == 'n' || correctchoice == 'N')
	{
		system("cls");
		goto datestart;
	}
	else
	{
		system("cls");
		printf("\n   Date saved successfully\n");
	}	//date entry code end

	FILE *fp, *ft;
	int a, i, tempid;
	int n = 0;
	char ch = 'y';
	long size = sizeof(c);
	while (ch == 'y')
	{
		//	c.id=100;	
		fp = fopen("gymmanager.dat", "rb+");
		if (fp == NULL)
		{
			fp = fopen("gymmanager.dat", "wb+");
			if (fp == NULL)
			{
				printf("File cannot be opened");
				exit(0);
			}
		}

		//	fseek(fp,0,SEEK_END);
		//	fseek(fp,-size,SEEK_CUR);
		//	while (fread(&c,sizeof(c),1,fp)==1)
		//	{
		//		n=c.id-100;
		//	}
		printf("\n\t\t\tselect a process\n");
		printf("\t\t\t1)Input new customer\n\t\t\t2)Display Info\n\t\t\t3)Delete info\n\t\t\t4)Modify existing info\n\t\t\t5)pay fees\n\t\t\t0)Exit\n");
		scanf("%d", &a);
			
		switch (a)
		{
			case 1:
				{
					while (fread(&c, sizeof(c), 1, fp) == 1)	//loop reading kar ke counter ko value assign karega
					{
						fread(&c, sizeof(c), 1, fp);
					}

					fseek(fp, 0, SEEK_END);
					while (ch == 'y')
					{
						system("cls");

						add(c);
						c.daye = day;
						c.monthe = month;
						c.yeare = year;
						c.id = c.counter + 100;
						c.counter++;
						fwrite(&c, sizeof(c), 1, fp);
						printf("do you want to enter another?(y/n)\n");
						fflush(stdin);
						ch = getch();
						if (ch == 'Y')
						{
							ch = 'y';
						}
					}

					break;
				}

			case 2:
				{
					system ("cls");
					//displaying data from file
					printf(" 1)detail info of all customer\n 2)display info of specific customer \n 3)display all\n your choice?");
					scanf("%d", &a);
					int custnum = 1;
					switch (a)
					{
						system("cls");
						case 1:
							{
								rewind(fp);
								while (fread(&c, sizeof(c), 1, fp) == 1)
								{
									displayall();
									custnum++;
								}

								break;
							}

						case 2:
							{
								printf("enter customer ID:");
								scanf("%d", &tempid);
								rewind(fp);	//placing cursor at the start of file
								while (fread(&c, sizeof(c), 1, fp) == 1)
								{
									if (tempid == c.id)
									{
										//							printf(" ID:%d\t name:%s\t total cost:%d last paid date: %d-%d-%d\n\n",c.id,c.name,c.costofcourse,c.daye,c.monthe,c.yeare);
										displayall();

									}
								}

								break;
							}

						case 3:
							{
								rewind(fp);	//placing cursor at the start of file
								while (fread(&c, sizeof(c), 1, fp) == 1)
								{
									printf(" ID:%d\t name:%s\t total cost:%d last paid date: %d-%d-%d\n\n", c.id, c.name, c.costofcourse, c.daye, c.monthe, c.yeare);
								}

								break;
							}
					}

					break;
				}

			case 3:
				{
					system ("cls");
					//deleting data from file
					while (ch == 'y')
					{
						printf("Enter the ID you want to delete");
						scanf("%d", &tempid);
						ft = fopen("temp.dat", "wb");
						rewind(fp);	//placing cursor at the start of file
						while (fread(&c, sizeof(c), 1, fp) == 1)
						{
							if (tempid != c.id)
								fwrite(&c, sizeof(c), 1, ft);	//copying all data except the one user wants to delete into a new file
						}

						fclose(fp);
						fclose(ft);
						remove("gymmanager.dat");	//deleting the old file and renaming the new one 
						rename("temp.dat", "gymmanager.dat");
						fp = fopen("gymmanager.dat", "rb+");
						printf("do you want to enter another?(y/n)\n");
						fflush(stdin);
						ch = getch();
						if (ch == 'Y')
						{
							ch = 'y';
						}
					}

					break;
				}

			case 4:
				{
					system ("cls");
					//updating the record in file
					printf("enter the ID to update");
					scanf("%d", &tempid);
					rewind(fp);	//placing cursor at the start of file
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						if (tempid == c.id)
						{
							//					printf("enter new name,Quantity and price");
							//					fflush(stdin);
							//					gets(c.name);
							add(c);

							fseek(fp, -size, SEEK_CUR);	//used the variable (size) because compiler was displaying an error
							fwrite(&c, sizeof(c), 1, fp);
							break;
						}
					}

					break;
				}

			case 5:
				{
					int tempmonth,tempyear;
					system ("cls");
					//check dues
					rewind(fp);	//placing cursor at the start of file
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						tempyear=c.yeare - year;
						if (tempyear <= 0)
						{
							tempmonth=(c.monthe) - month;
							if(tempyear<=-1)
							{
								tempmonth-12;
							}
							if (tempmonth < 0)
							{
								
								if ((c.daye) - day <= 0)
								{
									printf(" ID:%d\t name:%s\t total cost:%d\n\n", c.id, c.name, c.costofcourse);
								}
							}
						}
					}

					printf("Pay fees?(y/n)");
					ch = getch();
					if (ch == 'y' || ch == 'Y')
					{
						printf("Enter the ID you want to delete");
						scanf("%d", &tempid);
						rewind(fp);	//placing cursor at the start of file
						while (fread(&c, sizeof(c), 1, fp) == 1)
						{
							if (tempid == c.id)
							{
								//							printf("enter new record no,Name,Quantity and price");
								//							scanf("%d%s%d%f",&e.id,&e.name,&e.quant,&e.cost);
								c.monthe++;
								if (c.monthe > 12)
								{
									c.monthe = 1;
									c.yeare++;
								}

								fseek(fp, -size, SEEK_CUR);	//used the variable (size) because compiler was displaying an error
								fwrite(&c, sizeof(c), 1, fp);
								break;
							}
						}
					}

					break;
				}

			case 0:
				{
					fclose(fp);
					exit(0);
					break;
				} 
			default :
				{
					printf("Invalid Choice\n");	
				}	
		}

		fclose(fp);
		printf("do you want to restart?(y/n)\n");
		fflush(stdin);
		ch = getch();

		if (ch == 'Y')
		{
			ch = 'y';
		}

		system("cls");

	}
}
