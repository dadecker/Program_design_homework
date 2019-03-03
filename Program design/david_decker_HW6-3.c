/*

Homework 6
COP 3514
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20 //max length of a word
#define MAX_WORDS 50 //max length of the array of pointer, max number of entrys
//function declarations, defined after main
int read_line(char str[], int n);
void wordSort(char *a[], int count);
void print(char *a[], int count);

int main(void)
{
	char word_str[MAX_LENGTH+1];//array of chars, max length set to 20
	char *words[MAX_WORDS+1];//creates and array of type char pointers
	//int used throughout the program
	int total = 0;
	int i = 0;
	int count = 0;
	int true = 1;
	while(true)//while conditional never evaluates to false-infinite loop
	{	
		printf("Enter word: ");
		total = read_line(word_str, MAX_LENGTH+2);//assign the number of chars to total
		if(total < 1)//evauate the number of characters. if only return is hit break is used to exit loop
		{	
			break;//exits loop
		}
		words[i]=malloc(total*sizeof(char));//allocates the correct amount of memory based on characters entered
		strcpy(words[i],word_str);//stores word_str in words[]
		i++;
		count++;//keeps track of entries 
		if(i >= MAX_WORDS-1)
		{
			printf("Maximum Words Reached \n");
			break;
		}
	}
	wordSort(words, count);//calls the sorting function
	printf("In Sorted order: ");
	print(words, count);//calls the print function defined below
	
	for(i=0; i<count; i++)//for loop to free malloc'ed space
	free(words[i]); 	
	
	return 0; //end of program	
}
//taken from K.N King "C programming. A modern approach"
//page 287
int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
//the following uses a modified bubble-style sort. 
//citation:
//Knuth, Donald. "Bubble Sort." Wikipedia. Wikimedia Foundation, 
//28 June 2016. Web. 03 July 2016.
//uses a bubble-sort algorithm to sort the words entered
void wordSort(char *a[], int count)
{
	int i,j;
	char temp[MAX_LENGTH];
	strcpy(temp,a[0]);
	for(i=0; i<count; i++)	
	{
		for(j=i; j<count; j++)
		{
			if(strcmp(a[i], a[j]) > 0)
			{
						
				strcpy(temp,a[j]); 
				strcpy(a[j],a[i]);
				strcpy(a[i],temp);
					
			}
		}
	}
}
//printing function
void print(char *a[], int count)// print function
{
	int i;
	for(i =0; i < count; i++)
	{							
		printf("%s  ", a[i]);
	}
}
