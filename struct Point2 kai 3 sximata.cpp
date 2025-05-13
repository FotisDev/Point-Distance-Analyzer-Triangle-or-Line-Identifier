#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //���������� �� �� ������ ���� �������� .cpp
#include <math.h>

typedef struct 
{
	char letter;
	float x, y;
}Point;

float apostasi(Point point1, Point point2)
{
	return sqrt( pow((point2.x-point1.x), 2) + pow(point2.y-point1.y, 2) );
}

int main()
{
	int i;
	float AB, AC, BC;
	Point p[3];
	
	system("CHCP 1253 > NUL");
	
	for(i=0; i<3; i++)
	{
		printf("%d� ������\n-------------\n", i+1);
		printf("\t���� �� ������ ��� %d�� �������:", i+1);
		scanf("%c", &p[i].letter);
		printf("\t���� �� x ��� %d�� �������:", i+1);
		scanf("%f", &p[i].x);
		printf("\t���� �� y ��� %d�� �������:", i+1);
		scanf("%f", &p[i].y);
		printf("\n");
		getchar();
	}
	
	system("CLS");
	
	AB = apostasi(p[0], p[1]);
	AC = apostasi(p[0], p[2]);
	BC = apostasi(p[1], p[2]);
	
	if(AB==0 && AC==0 && BC==0)//��������� �������
		printf("\n�������� �� ������: %c(%.1f, %.1f)\n\n", toupper(p[0].letter), p[0].x, p[0].y);
	
	//��������� �������� �� �� ������ ��� ����� �����������
	else if((AB!=0 && AC!=0 && BC!=0) && ((p[0].y-p[1].y)/(p[0].x-p[1].x) != (p[0].y-p[2].y)/(p[0].x-p[2].x)))
	{//�� �� ������ ��� ����� �����������
		printf("\n�������� ������� �� ������� �� ������: "); 
		for(i=0; i<3; i++)
			printf("\n%c(%.1f, %.1f)", toupper(p[i].letter), p[i].x, p[i].y);
		printf("\n\n��� ����� �������:\n");
		printf("(%c%c): %.2f ������� ������\n", toupper(p[0].letter), toupper(p[1].letter), AB);
		printf("(%c%c): %.2f ������� ������\n", toupper(p[0].letter), toupper(p[2].letter), AC);
		printf("(%c%c): %.2f ������� ������\n", toupper(p[1].letter), toupper(p[2].letter), BC);
	}
	else//��������� ������� ����� ��� �� �� ������ ����� �����������
	{
		printf("\n�������� ���������� ����� �� ���� �� ������: ");
		if((p[0].y-p[1].y)/(p[0].x-p[1].x) != (p[0].y-p[2].y)/(p[0].x-p[2].x)) //�� �� ������ ��� ����� �����������
		{
			if(AB==0)
			{
				printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
				printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
				printf("\n������ (%c%c): %.2f �������.\n\n", toupper(p[1].letter), toupper(p[2].letter), (AC + BC)/2);
			}
			else if(AC==0)
			{
				printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
				printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
				printf("\n������ (%c%c): %.2f �������.\n\n", toupper(p[0].letter), toupper(p[2].letter), (AB + BC)/2);
			}
			else if(BC==0)
			{
				printf("\n%c(%.1f, %.1f)", toupper(p[0].letter), p[0].x, p[0].y);
				printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
				printf("\n������ (%c%c): %.2f �������.\n\n", toupper(p[0].letter), toupper(p[2].letter), (AB + AC)/2);
			}
		}
		else//�� �� ������ ����� �����������
		{
			if(AB>=AC && AB>=BC)
			{
				printf("\n%c(%.1f, %.1f)", toupper(p[0].letter), p[0].x, p[0].y);
				printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
				printf("\n������ (%c%c): %.2f �������.\n\n", toupper(p[0].letter), toupper(p[1].letter), AB);
			}
			else if(BC>=AB && BC>=AC)
			{
				printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
				printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
				printf("\n������ (%c%c): %.2f �������.\n\n", toupper(p[1].letter), toupper(p[2].letter), BC);
			}
			else
			{
				printf("\n%c(%.1f, %.1f)", toupper(p[0].letter), p[0].x, p[0].y);
				printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
				printf("\n������ (%c%c): %.2f �������.\n\n", toupper(p[0].letter), toupper(p[2].letter), AC);
			}
		}	
	}
	
	system("PAUSE");
	return 0;
}
