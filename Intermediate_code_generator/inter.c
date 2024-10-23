#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char op[2],op1[5],op2[5],result[5];
void main(){
	FILE * fp1, * fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	while(!feof(fp1)){
		fscanf(fp1,"%s%s%s%s",op,op1,op2,result);
		if(strcmp(op,"+") == 0){
			fprintf(fp2,"\n\tMOV R0 , %s",op1);
			fprintf(fp2,"\n\tADD R0 , %s",op2);
			fprintf(fp2,"\n\tMOV %s , R0",result);
		}
		if(strcmp(op,"*") == 0){
			fprintf(fp2,"\n\tMOV R0 , %s",op1);
			fprintf(fp2,"\n\tMUL R0 , %s",op2);
			fprintf(fp2,"\n\tMOV %s , R0",result);
		}
		if(strcmp(op,"-") == 0){
			fprintf(fp2,"\n\tMOV R0 , %s",op1);
			fprintf(fp2,"\n\tSUB  R0 , %s",op2);
			fprintf(fp2,"\n\tMOV %s , R0",result);
		}
		if(strcmp(op,"/") == 0){
			fprintf(fp2,"\n\tMOV R0 , %s",op1);
			fprintf(fp2,"\n\tDIV R0 , %s",op2);
			fprintf(fp2,"\n\tMOV %s , R0",result);
		}
		if(strcmp(op,"=") == 0){
			fprintf(fp2,"\n\tMOV R0 , %s",op1);
			fprintf(fp2,"\n\tMOV %s , R0",result);
		}	
	}
	fclose(fp1);
	fclose(fp2);
}
