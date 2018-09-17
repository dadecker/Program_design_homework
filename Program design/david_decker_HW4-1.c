/*
David Decker
U03219590
Homework 4
COP 3514
*/
#include <stdio.h>
#define ROW 3 //constants used throughout the program
#define COL 2
//declare the specified functions
void arrayToZero(int Z[ROW][COL]);//additional function initilizes the arrays to zero 
void clockwiseRotateTriangle(int TA[ROW][COL], int R[ROW][COL]);
int reflectTriangle(char axis, int TA[ROW][COL], int RE[ROW][COL]);
void translateTriangle(int transx, int transy, int TA[ROW][COL], int TRA[ROW][COL]);
void printTriangle(int printA[ROW][COL]);
int main(void)
{

	int TA[ROW][COL], alter[ROW][COL];//TA holds the original values throughout the program, alter  is alterd
	char axis;
	int reflectReturn, transx, transy;//values to use in the various functions' arguments
	arrayToZero(alter);
	arrayToZero(TA);// calling the function that initilizes the array to zero
	printf("Enter point #1 as x and y: ");//assigning the user input to the array
	scanf("%d%d", &TA[0][0], &TA[0][1]);         
	printf("Enter point #2 as x and y: ");
	scanf("%d%d", &TA[1][0], &TA[1][1]);
	printf("Enter point #3 as x and y: ");
	scanf("%d%d", &TA[2][0], &TA[2][1]);
	printf("Starting Triangle: ");
	printTriangle(TA);//call print function, prints the user  input
	clockwiseRotateTriangle(TA,alter);//call the function to rotate the triangle
	printf("Rotated Triangle: ");
	printTriangle(alter);//calls print function
	fflush(NULL);//clears buffer page 549 of book
	printf("Enter axis to reflect (x or y): ");
	scanf(" %c", &axis);
	fflush(NULL);//
	reflectReturn = reflectTriangle(axis, TA, alter);//calls the function to rotate the triangle over the given axis
	if(reflectReturn == 0)//conditional to evaluate the return value of reflectTriangle
	{						//and print the corresponding message
		printf("Reflected Triangle: ");
		printTriangle(alter);
	}
	else
	{	
		printf("Reflected Triangle: Invalid Axis. Next time enter x or y.\n");
	}
	printf("Enter translation values (x and y): ");
	scanf("%d%d", &transx, &transy);
	translateTriangle(transx, transy, TA, alter);//call the translate function
	printf("Translated Triangle: ");
	printTriangle(alter);//final print of TA array
return(0);
}
void arrayToZero(int Z[ROW][COL] )// one additional function to initilize the array to zero
{
int *p;
for(p = &Z[0][0]; p <= &Z[2][1];p++)
	*p=0;
}
void clockwiseRotateTriangle(int TA[ROW][COL], int R[ROW][COL])
{
int i, *p, *q;//assign pointers to store the value of elements in the 
//original array
for(i=0;i<ROW;i++)
{
p = &TA[i][1];//the following 4 lines uses the formula (x,y)=(y,-x)
q = &TA[i][0];//and implements the change using pointers
R[i][0] = *p; //and a for loop
R[i][1] = *q * (-1); 
}
}
int reflectTriangle(char axis, int TA[ROW][COL], int RE[ROW][COL])
{
int i, *p, *q;//assign pointers to store the value of elements in the 
//original array
if(axis == 'x')//four if else statements for each possible valid input value 
{
	for(i=0;i<ROW;i++)
	    {
		p = &TA[i][0];//the following 4 lines uses the formula (x,y)=(x,-y)
		q = &TA[i][1];//and implements the change using pointers
		RE[i][0] = *p; //and a for loop
		RE[i][1] = *q * (-1);
		}
return (0);
}else if(axis == 'X')
{
	for(i=0;i<ROW;i++)
	    {
		p = &TA[i][0];
		q = &TA[i][1];
		RE[i][0] = *p; 
		RE[i][1] = *q * (-1);
		}	
return (0);
}else if(axis == 'Y')
{
	for(i=0;i<ROW;i++)
	    {
		p = &TA[i][0];//the following 4 lines uses the formula (x,y)=(-x,y)
		q = &TA[i][1];//and implements the change using pointers
		RE[i][0] = *p * (-1); //and a for loop
		RE[i][1] = *q;
		}	
return (0);
}else if(axis == 'y')
{
	for(i=0;i<ROW;i++)
	    {
		p = &TA[i][0];
		q = &TA[i][1];
		RE[i][0] = *p * (-1); 
		RE[i][1] = *q;
		}	
return (0);
}
else
{
	return(-1);
}	
	
}
void translateTriangle(int transx, int transy, int TA[ROW][COL], int TRA[ROW][COL])
{
int i, *p, *q;
for(i=0; i<ROW; i++)
{
	p = &TA[i][0];
	q = &TA[i][1];
	TRA[i][0] = *p + transx;
	TRA[i][1] = *q + transy;
}
}
void printTriangle(int printA[ROW][COL])
{
int (*p)[COL];
for(p=&printA[0]; p<&printA[ROW];p++)//the for loop uses pointer arithmetic 
{                                    //to move thru the array and print the elements
	printf("(%d", (*p)[0]);
	printf(", %d)",(*p)[1]);
}
printf("\n");
}


