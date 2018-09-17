/*
David Decker
U03219590
Homework 3
COP 3514
*/
#include <stdio.h>
#include <math.h>// include the math header for square root function
/*function one - quadratic formula*/
int quadraticFormula(int a, int b, int c, float *root1, float *root2)
{
float disc;
disc = (b*b-4*a*c); //declare and define the value of the discriminant
if (disc > 0)//three possible values of the discriminant which determines the roots
	{
		*root1 = ((-b) + sqrt(disc))/(float)(2*a);
		*root2 = ((-b) - sqrt(disc))/(float)(2*a);
		return (2);
	}
else if (disc == 0)	// second possible value of the disciminant
	{
		*root1 = (-b)/(float)(2*a);
		return (1);
	}
else if (disc < 0)//final value of the disciminant, no real roots
		return (0);
return (0);
}
/*function 2- Vertex*/
void quadraticVertex(int a, int b, int c, float *xvalue, float *yvalue)
{
	*xvalue = (-b)/(float)(2*a);//the formula gives us the x location of the axis of symmetry 
	*yvalue = (4*a*c-b*b)/(float)(4*a); //formula for the y value of the vertex
}
/*function 3 - directrix*/
void quadraticInfo(int a, int  b, int c, char *dir, float *dirValue)
{ 
	*dirValue = ((4*a*c-b*b)/(float)(4*a)) - 1/(float)(4*a);//formula from the standard quadratic form for the directrix
	if (a > 0)//if conditional that determines if the parabola opens up or down and assigns a char value accordingly
	{
		*dir = 'U';
	}
	else
		*dir = 'D';
}

int main(void)
{
	/*the following declares variables to be used throughout the main function*/
	float root1, root2, value,xvalue, yvalue, dirValue; 
	int a,b,c;
	char dir;
	printf("Enter coefficents a, b, and c: ");
	scanf("%d%d%d", &a, &b, &c);
	while(a == 0)//error handling if the user enters a zero for the coefficient of x^2
	{
	printf("The vlaue of a can not be zero, please enter new values.\n");
	printf("Enter coefficents a, b, and c: ");
	scanf("%d%d%d",&a, &b, &c);
	}
	value = quadraticFormula(a,b,c,&root1,&root2);//call the quadratic equation function
	printf("f(x) = %dx^2 + %dx + %d\n", a, b, c);
	if(value == 2)//series of conditionals evaluating the return value of the above function
	{
	printf("Roots: %.2f and %.2f\n", root1, root2);
	}
	else if(value == 1)
	{
	printf("Root: %.2f\n", root1);
	}
	else if (value == 0)
	{
	printf("No real roots\n");
	}
	quadraticVertex(a,b,c,&xvalue,&yvalue);//call the quadraticVertex function and store the values of the vertex in xvalue and yvalue
	printf("Vertex: (%.2f, %.2f)\n", xvalue, yvalue);
	quadraticInfo(a,b,c,&dir,&dirValue);//calling the dierctrix function and storing the value in dirValue
	printf("Directrix: y = %.2f\n", dirValue);
	if (dir == 'U')//conditional statement evaulating the char value stored int dir 
		printf("The graph is facing up\n");
	else
		printf("The graph is facing down\n");
	return (0);
	}

