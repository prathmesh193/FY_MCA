#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
	int rollNo;
	char name[50];
	float percentage;
};

int binarySearch(struct Student students[],int n,int targetRollNo)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid= low + (high-low)/2;
		
		if(students[mid].rollNo==targetRollNo)
		{
			return mid;
		}
		else if(students[mid].rollNo<targetRollNo)
		{
			low=mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return -1;
}

void displayStudent(struct Student student)
{
	printf("Roll no: %d\n",student.rollNo);
	printf("Name: %s\n",student.name);
	printf("Percentage: %.2f\n",student.percentage);
}

int main()
{
	int i,n;
	printf("Enter the no of students :");
	scanf("%d",&n);
	
	struct Student* students = (struct Students*)malloc(n* sizeof(struct Student));
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter the details for student %d:\n",i+1);
		printf("Rol no:");
		scanf("%d",&students[i].rollNo);
		printf("Name:");
		scanf("%s",students[i].name);
		printf("Percentage :");
		scanf("%f",&students[i].percentage);
	}
	
	int targetRollNo;
	printf("\nEnter the Roll no to Search: ");
	scanf("%d",&targetRollNo);
	
	int index = binarySearch(students, n, targetRollNo);
	
	if(index !=-1)
	{
		printf("\nStudent found:\n");
		displayStudent(students[index]);
	}
	else
	{
		printf("\nStudent not found...\n");
	}
	free(students);
	
	return 0;
}
