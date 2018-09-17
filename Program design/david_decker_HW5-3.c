#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80  // sets the constant MAX at 80
//struct type definition 
typedef struct {
	char name[MAX];
	int age;
	}person;
//function declaration.Function defined after main
void stringCopy(char *a1, const char *a2);
void print(int limit, person people[]);
void nameSort(int limit, person people[], person tempC[]);
void ageSort(int limit, person people[], person tempC[]);
int main (int argc, char *argv[])
{
	int i, j;
	int limit = (argc-1)/2;//calculates number of people created by the user
	person people[limit];//array of type person to hold the value entered on the command line
	person tempC[limit];//declare an array of type person to use as a temp in sorting
	tempC[0].age = 0;// initilize a temp sruct to use in sorting
	stringCopy(tempC[0].name,argv[0]);//initilize the string in the temp struct
	if(argc<=2)//if statement to verify the length of arguments entered at the command line
	{
		printf("Invalid Arguments.\n");
		printf("Usage: ./hw5 name1 age1 name2 age2 ...\n");
		return(0);
	}	
	if((argc%2 == 0))//conditional to check the number of arguments entered
	{
		printf("Invalid Arguments.\n");
		printf("Usage: ./hw5 name1 age1 name2 age2 ...\n");
		return (0);
	}
		
	for(i=2; i<argc; i=i+2)//loop that checks for zero value on all age arguments entered
	{	
		if(atoi(argv[i]) == 0)
		{
			printf("You have entered %d person(s) into the program.\n", limit);
			printf("Invalid age <= 0. Try again. \n");
			return (0);
		}
	}
	printf("You have entered %d person(s) into the program.\n", limit);
	// following asigns the arguments to variables in the array of structs
	for(i=0, j=1; j<argc; i++, j=j+2)//goes thru argv[] by individul elements and 
	{								//stores the values given into each element in the 	
		stringCopy(people[i].name,argv[j]);//array of structs named people
		people[i].age = atoi(argv[j+1]);
	}
	
	printf("Unsorted Names: \n");
	print(limit, people);//first call of print function declared above	
	nameSort(limit, people, tempC);//calls the namesort function
	printf("Sorted by First Name: \n");
	print(limit, people);
	printf("Sorted by Age:\n");
	ageSort(limit, people, tempC);//calls the ageSort function
	print(limit, people);
} 

void print(int limit, person people[])// print function
{
	int i;
	for(i =0; i < limit; i++)//prints the name and age of the people 
	{						//entered in the correct format	
		printf("Name: %s | Age: %d\n", people[i].name, people[i].age);
	}
}
void nameSort(int limit, person people[], person tempC[])
{
	int i,j;
	person *p1,*p2; //person type pointers
	p1 = &people[0];//assigns the pointer p1 to the first element of people[]
	p2 = &tempC[0];//p2 now points to tempC[]	
		//the following uses a modified bubble-style sort. 
		//citation:
		//Knuth, Donald. "Bubble Sort." Wikipedia. Wikimedia Foundation, 
		//28 June 2016. Web. 03 July 2016.
	for(i=0; i<limit; i++)	
	{
		for(j=0;j<limit-1;j++)
		{
			if(strcmp(p1[j].name, p1[j+1].name) > 0)
			{
				int temp = p1[j+1].age;
				stringCopy(p2[0].name,p1[j+1].name); 
				p1[j+1].age=p1[j].age;
				stringCopy(p1[j+1].name, p1[j].name);
				p1[j].age = temp;
				stringCopy(p1[j].name,p2[0].name);
			
			}
		}
	}
}
void ageSort(int limit, person people[], person tempC[])
{
	int i,j,temp;
	person *p1,*p2; //person type pointers
	p1 = &people[0];//assigns the pointer p1 to the first element of people[]
	p2 = &tempC[0];//p2 now points to tempC
	for(i=0; i<limit; i++)//next use of the sort method above, slightly modified
	{					  //modified for an int value instead of a string
		for(j=0;j<limit-1;j++)
		{
			if(p1[j].age > p1[j+1].age)
			{
				temp = p1[j+1].age;
				stringCopy(p2[0].name,p1[j+1].name); 
				p1[j+1].age=p1[j].age;
				stringCopy(p1[j+1].name, p1[j].name);
				p1[j].age = temp;
				stringCopy(p1[j].name,p2[0].name);
				
			}
		}
	}
}
//the following definition is taken(slightly modified) from the string idioms 
// listed on pg. 298 of our text book "C progamming. A Modern Approach"
//by K.N. King 
void stringCopy(char *a1, const char *a2) //the second argument is copied into the first
{
	char *p = a1;
	while(*a2 != '\0')
	{
		*p = *a2;
		p++;
		a2++;
	}	
	*p = '\0';
}