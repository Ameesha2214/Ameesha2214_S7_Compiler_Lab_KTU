#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char input[100];
int n=0;

void E();
void E_prime();
void match(char token);
void match(char token){
	if(input[n] == token){
		n++;
	}
	else{
		printf("\nSyntax error\n");
		exit(1);
	}
}
void E_prime(){
	if(input[n] == '+'){
		match('+');
		match('i');
		E_prime();
	}
	if(input[n] == '*'){
		match('*');
		match('i');
		E_prime();
	}
}
void E(){
	match('i');
	E_prime();
}
void main(){
	printf("Enter the grammar\n");
	printf("E->iE'\nE'->+iE'/*iE'\n");
	printf("Enter the expression\n");
	scanf("%s",input);
	E();
	if(input[n] == '\0'){
		printf("Successfully Parsed\n");
	}
	else{
		printf("Failure\n");
	}
}
			
