/*
Homework 1
COP 3514
*/
#include <stdio.h>
/*Purpose: The user will input 2 different fractions. 
Each fraction will be input in the form of "a/b" where a and b are both 
positive integers. For each fraction the program stores the numerator and denominator as integers. The operations preformed are: 
addition, subtraction, multiplication, and division. This is followed by 
a conditional statement to find out whether the first fraction is a improper 
fraction or not. If it is an improper fraction, The program then prints that it is and prints 
it as a mixed number, making sure if the fraction is 0/b after doing the mixed 
number, not print the fractional part. The user is asked for one 
last integer for a GPA grade. With this integer you will use a switch statement 
to print out what the letter grade would be.*/ 
int main(void){
	/*The following are variable declerations that will be initialized 
	and used throughout the program. The designation top and bottom indicates the
	the numerator and denominator, respectively, with fewer letters*/
	int topa, topb, topResult, bottoma, bottomb, bottomResult, grade, i=0;
	float decimalValue = 1;
	/*The next four lines output a question and the take input from
	the user and store the values in the variable locations declared above*/	
	printf("Enter Fraction 1: ");	
	scanf("%d/%d",&topa,&bottoma);
	
	printf("Enter Fraction 2: ");
	scanf("%d/%d",&topb,&bottomb);
	/*the following two assignments first assign the integer value to the float decimalValue by 
	promotion then completes the calculation of the decimal value of fraction 1*/
	decimalValue = topa/decimalValue;
	decimalValue = decimalValue/bottoma;
	/*the next two lines print the fractions entered by the user*/
	printf("Fraction Number 1: %d/%d\n", topa,bottoma);
	printf("Fraction Number 2: %d/%d\n",topb,bottomb);
	/*the following adds the numerator and denomenator after addition 
	prints the result as a fraction*/
	topResult = topa*bottomb + topb*bottoma;
	bottomResult = bottoma * bottomb;
	printf("Addition of Fractions: %d/%d\n",topResult,bottomResult);
	/*the following calculates the value of the numerator and denomenator 
	after subtraction prints the results as a fraction*/
	topResult = topa*bottomb - topb*bottoma;
	bottomResult = bottoma * bottomb;
	printf("Subtraction of Fractions: %d/%d\n",topResult,bottomResult);
	/* the following calculates the value of the two input fractions 
	multiplied and prints that fraction*/
	topResult = topa * topb;
	bottomResult = bottoma * bottomb;
	printf("Multiplication of Fractions: %d/%d\n", topResult,bottomResult);
	/*the following divides the two given fractions and prints the results*/
	topResult = topa*bottomb;
	bottomResult = bottoma*topb;
	printf("Division of Fractions: %d/%d\n",topResult,bottomResult);
	/* the first if evaluates the first fraction and determines if the 
	fraction is proper then prints the appropriate statement*/
	if(topa < bottomb){
		printf("Fraction 1 is a proper fraction\n");
	}
	else	
		printf("Fraction 1 is an improper fraction\n");
	/*this if statement also evaluates the first fraction. If the numerator is greater 
	than the denominator, integer division is preformed and the value is stored in variable "i"
	and the remander value is assigned to the variable topa*/
	if(topa > bottoma){
		i = topa/bottoma; 
		topa = topa%bottoma;
	}
		
	/*this if statement prints the new mixed number in either the case the numerator
	is zero or it is an integer*/
	if(i>0){
		if(topa != 0)
			printf("Fraction 1 as a Mixed Number: %d %d/%d\n",i,topa,bottoma);
		else
			printf("Fraction 1 as a Mixed Number: %d\n", i); 
	}
	/*the following prints the decimal value of the first fraction, 
	calculated above*/
	printf("Decimal Approximation of Fraction 1: %0.2f\n", decimalValue);
	/*the following prompts the user to enter their gpa using a numeric value, assigns that value to the variable grade,
	then assigns the numeric value a letter grade using the switch statement and finally prints that grade.*/ 
	printf("Enter in a GPA for the class (0-4 integer): ");
	scanf("%d", &grade);
	switch (grade) {
		case 4: printf("You got an A!");
				break;
		case 3: printf("You got a B!");
				break;
		case 2: printf("You got a C");
				break;
		case 1: printf("You got a D");
				break;
		case 0: printf("You got an F");
				break;
		default: printf("That isn't a grade");
				 break;
	}			 
	
	
}	
