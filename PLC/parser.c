/*
 * parser.c
 *
 *  Created on: Nov 6, 2019
 *      Author: Matt Williams
 */
//includes  TODO determine which includes are necessary for final release
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>



#if defined(_WIN32) || defined(_WIN64)
        char* relativePath = "..\\input.txt";
#else
        char* relativePath = "../input.txt";
#endif



//constants
const int MAX_STRING_LENGTH = 25;
const int NUM_STRINGS = 21;

//function declarations
void handleExpression();
void lexicalAnalyzer(char expression[]);

//char e(char* begin, char* end);
//char a(char* begin, char* end);
//char b(char* begin, char* end);
//char c(char* begin, char* end);

//globals
enum operator {OR, XOR, AND, SHIFT_LEFT, SHIFT_RIGHT, NOT, LEFT_PARENTHESIS, RIGHT_PARENTHESIS} op;
char hexNum;


/*
 * reads in expressions and handles them line-by-line
 */
void handleExpression(){
//	printf("entered handleExpression function\n");
	FILE *readFile;
	readFile = fopen("/home/mwilliams/C++/Project4/327_proj3_fileIO/PLC/input.txt", "r");

	if(!readFile){  // file not opened
		printf("%s", strerror(errno));
		exit(1);
	}

//	printf("File opened\n");

	char* emptyChar = "";

	char line[MAX_STRING_LENGTH];
	int arrIndex = 0;


	int i = 0;
	while(fgets(line, MAX_STRING_LENGTH, readFile) != NULL){
//		printf("Expression:      %s", line);
		lexicalAnalyzer(line);
		i++;
	}
//	printf("While iterations: %d\n", i);

}

/*
 * lexical analyzer TODO update this description when you understand what this function's purpose is
 */
void lexicalAnalyzer(char expression[]){
//	printf("Made to lexicalAnalyzer\n");
	for(int i = 0; i < MAX_STRING_LENGTH; i++){
		if (expression[i] == '\n')
			expression[i] = '\0';
	}
	printf("Expression:      %s\n", expression);
}




int main(int argc, char* argv[]){
//	printf("entered main\n");
	handleExpression();
}



