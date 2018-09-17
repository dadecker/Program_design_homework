/*
David Decker
U03219590
Homework 7
COP 3514
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//macro used for the maximum length of a word
#define MAX_WORD_LEN 50
//typedef of a struct used to hold the 
//words and a count of the words
typedef struct {
	char word[MAX_WORD_LEN];
	int uses;
	}word_struct;
//function declarations
int char_count(const char *s, int *chars);
int word_count(const char *s, int *words);
int line_count(const char *s, int *lines);
int bag_of_words(const char *s, int words);

int main(int argc, char *argv[])
{
	//calls each function, each function defined below main
	int chars, words, lines;
	char_count(argv[1], &chars);
	word_count(argv[1], &words);
	line_count(argv[1], &lines);
	bag_of_words(argv[1], words);
	printf("Number of Characters: %d\n", chars);//prints each of the variables
	printf("Number of Words: %d\n", words);
	printf("Number of Lines: %d\n", lines);
	return 0;
}	
int char_count(const char *s, int *chars)//arguments are pointers in the following three functions
{										//used to acess values outside of the function	
	int ch;
  	*chars = 0;
	//creates a pointer of type FILE
	FILE *fp;
	//the following opens the file given as an argument on
	//the command line
	fp = fopen(s, "r");
	//the following checks to see if fp points to a file
	//adapted from KN King's "C Programming, a modern approach"
	//page 
	if (fp == NULL)
	{
		printf("Error, %s can not be opened", s);
		return 0;
	}
	//The following is also taken from KN King pg. 567
	//it is a while loop that reads characters from  a file one by one 
	//until the end of the file is reached
	//it then tests for white space or end of line to increment
	//the value of lines, words and chars when appropriate in each of the flollowing functions
	//white space is not included in the character count 
	while((ch = getc(fp)) != EOF)
	{
			(*chars)++;//only counts characters
	}	
	//close file after completion
	fclose(fp);
	return 0;
}
//word_count and line_count are nearly identical to char_count
int word_count(const char *s, int *words)
{
	int ch;
	*words = 0;
	FILE *fp;

	fp = fopen(s, "r");

	if (fp == NULL)
	{
		printf("Error, %s can not be opened", s);
		return 0;
	}

	while((ch = getc(fp)) != EOF)
	{
		if (ch == ' '|| ch== '\n')//only major difference between functions. this one counts 
			(*words)++;			//words based in white space and end of line characters	
	}	
	fclose(fp);
	return 0;
}
int line_count(const char *s, int *lines)
{
	int ch;
	*lines = 0;
	FILE *fp;

	fp = fopen(s, "r");

	if (fp == NULL)
	{
		printf("Error, %s can not be opened", s);
		return 0;
	}

	while((ch = getc(fp)) != EOF)
	{
		if (ch== '\n')
			(*lines)++;
	}	
	fclose(fp);
	return 0;
}
//final function is to create the bag of words
int bag_of_words(const char *s, int num_of_words)//argument num_of_words takes the value of words given 
{												//by the function word_count
	//various variables used throughout function
	int	count = 0;
	int i = 0;
	int j = 0;
	int tracker = 0;
	int final_counter = 0;
	int new_word_counter = 0;
	//a array of characters used only to initilize the structs
	char initil[]="zrg";
	//creating and array of structs to hold the int and string
	//then initilizing the values
	word_struct final[num_of_words + 1];//final array of structs
	word_struct array_of_structs[num_of_words +1];//temp array of structs
	array_of_structs[0].uses = 0;
	strcpy(array_of_structs[0].word, initil);
	strcpy(final[0].word, initil);
	final[0].uses = 0;
	//creates pointers of type FILE, one for reading and one for writing
	FILE *fp,*fpwrites;
    //the following is used to hold each word 
	//until it is copied into the struct
	//45 letters is the longest word in a standard dictionary
	//so 50 is chosen as max length
	char word_temp[MAX_WORD_LEN];
	//opens the file
	fp = fopen(s, "r");
		if (fp == NULL)//tests for a NULL pointer
	{
		printf("Error, %s can not be opened", s);
		return -1;
	}
	fpwrites = fopen("bagofwords.txt", "w");//opens the bagofwords file to be written
	if (fpwrites == NULL)
	{
		printf("Error, %s can not be opened", s);
		return -1;
	}
	//the basis for the conversion specification is modified from the following blog, url given
	//URL http://www.thecodingforums.com/threads/newbie-fscanf-conversions-multipliers.440669/
	//conversion specification used to skip punctuation
	//while loop copies each string from the text file into an array of structs with a string component
	while((fscanf(fp, "%50[a-zA-Z]%*[^a-zA-Z]", word_temp)) != EOF)//copies the text string by string
	{	
			strcpy(array_of_structs[i].word, word_temp);
			array_of_structs[i].uses = 1;
			i++;
			count++;//count is used to count words copied
	}
	//each word stored is comapared against the strings currently stored in final[]
	//if strcmp == 0 the count of the word count in the struct is incremented 
	//if the word does not match any previous words, it is copied into a new struct in the array
	strcpy(final[0].word, array_of_structs[0].word);//initial element copied as a start
	final[0].uses = 1;
	for(i=1; i<count; i++)
	{
		tracker = 0;//resets variable each iteration
		for(j=0; j<final_counter+1; j++)
		{	
			if((strcmp(array_of_structs[i].word, final[j].word)) == 0)//if the value of the strinf in array matches one of the 
			{														//words stored in final, only the value of uses is incremented
				final[j].uses++;									//and the variable tracker is incremented
				tracker++;
			}	
		}
	    if(tracker == 0)//checks for increment in previous step
		{				//the string is only copied into a new struct if the word is new
			strcpy(final[final_counter+1].word, array_of_structs[i].word);
			final[final_counter+1].uses =1;
			final_counter++;//counts new words added, used to keep track of how many structs in final[]
			
		}
	
	}	
		
	for (i=0; i<final_counter+1; i++)//output to file, element by element
	{	
		fprintf(fpwrites, "%s: ",final[i].word); //copies members of final[] into bagofwords
		fprintf(fpwrites, "%d\n", final[i].uses);	
	}	
	fclose(fpwrites);                      
	return 0;
}		
