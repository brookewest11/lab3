/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: brookewest
 */



#include <stdio.h>
#include <stdlib.h>

 char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August",
			"September", "October", "November", "December"};  //creates array of months so we can access month by using numbers



void min(float sales[])
{
	float min; 
	min = sales[0];
	int month = 0; 


	for(int i = 0; i < 11; i ++)
	{
		if (min < sales[i+1])
		{
			min = min;
			month = month; 
		}
		else
		{
			min = sales[i+1];
			month = i + 1;
		}

	}


	printf("\nMinimal Sales: $%.2f (%s)" ,min, months[month]);
	
}


void max(float sales[])
{
	float max; 
	max = sales[0];
	int month = 0; 


	for(int i = 0; i < 11; i ++)
	{
		if (max > sales[i+1])
		{
			max = max;
			month = month; 
		}
		else
		{
			max = sales[i+1];
			month = i + 1;
		}

	}


	printf("\nMaximum Sales: $%.2f (%s)" ,max, months[month]);
}

void avg(float sales[])
{
	float avg; 
	avg = 0.0;


	for(int i = 0; i < 12; i ++)
	{
	
		avg = avg + sales[i];
	}

	avg = avg/12;

	printf("\nAverage Sales: $%.2f" ,avg);
}

void salesReport(float sales[])
{
	float report[12];
	char *reportMonths[12]; 
	float temp; 
	char *tempMonth;
	

	for(int i = 0; i < 12; i++)
	{
		report[i] = sales[i];

	} 

	for(int i = 0; i < 12; i++)
	{
		reportMonths[i] = months[i];

	} 

	for(int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if(report[i] > report[j])
			{
				temp = report[i];
				report[i] = report[j];
				report[j] = temp;

				tempMonth = reportMonths[i];
				reportMonths[i] = reportMonths[j];
				reportMonths[j] = tempMonth;

				

			}
		}
		

	}

	printf("\nSales Report (High to Low): \n");

	for(int i = 0; i < 12; i++)
		{
			printf("%-9s $%.2f\n", reportMonths[i], report[i]);

		}

}

void sixMonthAvg(float sales[], char *month[] ,int startMonth)
{
	float avg; 
	avg = 0.0;



	for(int i = startMonth; i < startMonth + 6; i ++)
	{
	
		avg = avg + sales[i];
	}

	avg = avg/6;

	printf("%-9s - %-9s $%.2f\n" , months[startMonth], months[startMonth + 5], avg);
}

int main()
{




	FILE *file;

	file = fopen("input.txt", "r");
	    if (file == NULL)
	    { printf("File does not exist!");
	    	return 1; }






	float sales[12];

	
	for(int i = 0; i < 12; i++)
	{
		fscanf(file, "%f",&sales[i]);
		

	}



	fclose(file);


	printf("Monthly sales report for 2022:\n");
	printf("\nMonth:    Sales:\n");
	

	for(int i = 0; i < 12; i++)
		{
			printf("%-9s $%.2f\n", months[i], sales[i]);

		}

	
	printf("\n");

	printf("\nSales Summary: \n");
	min(sales);
	max(sales);
	avg(sales);

	printf("\n\nSix-Month Moving Average Report: \n");
	sixMonthAvg(sales, months, 0);
	sixMonthAvg(sales,months,1);
	sixMonthAvg(sales,months,2);
	sixMonthAvg(sales,months,3);
	sixMonthAvg(sales,months,4);
	sixMonthAvg(sales,months,5);
	sixMonthAvg(sales,months,6);

	printf("\n");
	salesReport(sales);
	

	return 0;
}
