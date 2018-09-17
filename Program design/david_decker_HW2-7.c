#include <stdio.h>
/*the following directive defines the constants 
for the max number of rows and collumn in the magic square
using the variable length array was creating run time issues 
and compile errors, so this solution was implemented*/
#define maxRow 11
#define maxCol 11
/*declare global variables*/
int n = 0;
int m = 0;
int MS[maxRow][maxCol];
/*initial declarations of functions-prototypes. They are defined and 
explained following the declarations*/
void MS_zero(void);	
void MS_print(void);
int magic_sum(void);
void MS_create(void);

int main(void)
{
/*prompt the user to enter the size of the magic square then stores the value entered into the variable p 
which will be used by the MS_create function to create the multidimensional array. 
The program exits if the value entered is even or not between 1 and 11. The functions declared above are then called. 
*/

	int total = 0;
	printf("Enter size of magic square: ");
	scanf("%d",&n);
	m=n;
	if((n-1)%2!=0 || n>11)
	{	
		printf("Invalid Input: %d\n",n);
		return (0);
	}
	MS_create();
	MS_print();
	total = magic_sum();
	printf("Sum of Magic Numbers: %d\n", total);
}
/*FUNCTION ONE */
/*the following defines the function for creating the "magic square" 
in a two dimensional array and initializes the variables used to assign the
initial postition in the magic square. The initialization statement MS[n][n]={0}; 
kept sending error messages when compiling, so the following for loop is used to initilize the array 
to zero by going thru each element individually,[0][0],[0][1],[0][2] etc. thru [n-1][n-1]	
although the array was created to be 11x11, the program only uses the elements in the 
range provided by the user.
The for loop following the nested for loops	uses conditionals 
that will populate the 2-d array by starting with 1
in the middle of column of the first row and the adding each additional number
in the element that is one above and one to the right, unless that element has a value
greater than zero, in which case the program then selects the element directly below. The nested 
conditionals also keep the square in the dimensions provided by the user; i.e. 3x3, 5x5 etc. 	*/
void MS_create(void)	
{	
	int i,j,row,col,newRow,newCol, value;
	for(i = 0; i < n; i++)
    {
		for(j = 0; j < n; j++)
			MS[i][j] = 0;
    }
	row = 0;
	col = n/2;
	for(value=1; value<=n*n; value++)
	{
		MS[row][col] = value;
		if((row-1)>=0)
			newRow = row-1;
		else
			newRow = n-1;
		if((col+1)<=(n-1))
			newCol = col+1;
		else
			newCol = 0;
		if(MS[newRow][newCol]==0)
		{
			row = newRow;
			col = newCol;
		}
	    else
			row = row+1;
	}
}	
/*FUNCTION TWO*/
/*the following is the second function of the project and follows the same
form as the nested for loops that initializes the array earlier. The outer loop iterates 
n times while the inner loop iterates n times for each iteration of the outer loop
the field width	is set to 5. The new line command starts a new row at the end of each row.
this prints one row then moves on too the next*/
void MS_print(void)
{
	int i,j;
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{	
			printf("%5d", MS[i][j]);
		}
		printf("\n");	
	}
}
	
/*FUNCTION THREE*/
/*the sum of all the elements in the magic square is calculated in the following function. 
The while loop starts with the value of element [0][0] then increments j until j = n-1
and then increments i by one, until the last element has been added to magicSum.
Finally the sum is printed and the program exits.
	*/
int magic_sum(void)
{
int i=0, j=0;
int magicSum=0;
while(i<n)
{
	j=0;
	while(j<n)
	{	
		magicSum += MS[i][j];
		j++;
	}
	i++;
}
	return(magicSum);

}
	