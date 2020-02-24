//INSTRUCTIONS
//Your parser will read from input.txt
//input.txt consists of a series inputs that you need to read.
//each input is proceeded by a flag.
//Each flag will be either I, C, or F.
//I means int, C means char, F means float.

//So for example

//I 7963467 
//means int 7963467

//C H
//means char H

//F 0.7896
//means float 0.7896

//Your parser must read in each input, and then print it to the correct file.
//ints go in ints.txt
//chars go in chars.txt
//floats go in floats.txt

//CODE BEGINS HERE

//include fprintf and fscanf
#include<stdio.h>
//begin your main function
int main() {
//open ints.txt, chars.txt, and floats.txt for writing
FILE* intsout = fopen("ints.txt", "w");
FILE* charsout = fopen("chars.txt", "w");
FILE* floatsout = fopen("floats.txt", "w");
//open input.txt for reading
FILE* fp = fopen("input.txt", "r");
//don't forget that the file access mode is different for each!

//create a char variable to hold the flags you read	
char flag;
char garbage;
//create an int, char, and float variable to hold the int, char, and float values you read
char datai;
char datac;
char dataf;
//while fscanf does not return an EOF error
while((flag = fgetc(fp))!=EOF) {
	if(flag=='C'){
		garbage = fgetc(fp);
		datac = fgetc(fp);
		fprintf(charsout, "%c", datac);
		fprintf(charsout, "%c", ' ');
		garbage = fgetc(fp); 
	}
	else if(flag=='I'){
		garbage = fgetc(fp);
		while((datai = fgetc(fp))!=EOF) {
			if((datai==' ')||(datai=='\n')||(datai=='\0')){
				break;
			}
			fprintf(intsout, "%c", datai);
		}
		fprintf(intsout, "%c", ' ');
	}
	else if(flag=='F'){
		garbage = fgetc(fp);
		while((dataf = fgetc(fp))!=EOF) {
			if((dataf==' ')||(dataf=='\n')||(dataf=='\0')){
				break;
			}
			fprintf(floatsout, "%c", dataf);
		}
		fprintf(floatsout, "%c", ' ');
	}
}
fclose(fp);
return 0;
}
//read in a flag from input.txt

//if it stands for an int
//read an int from input.txt
//write the int to ints.txt

//if it stands for a char
//read a char from input.txt
//write the char to chars.txt

//if it stands for a float
//read a float from input.txt
//write the float to floats.txt

//once fscanf returns and EOF error return a successful exit status

	 
