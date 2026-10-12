#include <stdio.h>
#include <string.h>
#include <ctype.h>

int k_count =0 ,i_count =0;

void keyword(char str[10]){
	if (strcmp("for" ,str)== 0|| strcmp("printf" ,str)==0||
	strcmp("while" ,str)== 0|| strcmp("do" ,str)==0||
	strcmp("int" ,str)== 0|| strcmp("float" ,str)==0||
	strcmp("char" ,str)== 0|| strcmp("switch" ,str)==0||
	strcmp("void" ,str)==0 || strcmp("case" ,str)== 0|| strcmp("include" ,str)==0)
	{
		printf("\n%s is a keyword \n" ,str);
		k_count++;
	}
	else
	{
		printf("\n%s is an identifier \n" ,str);
		i_count ++;
	}
}

void main(){
	FILE *f1 ,*f2 ,*f3;
	char c ,str[10] ,str1[10];
	int num[100] ,lineno =0 ,tokenvalue =0 ,i=0 ,j=0 ,k=0 ,count =0 ,s_count =0;
	f1 =fopen("input.txt","r");
	f2 =fopen("identifier","w");
	f3 =fopen("specialchar","w");

	while((c =getc(f1))!= EOF){
		if(isdigit(c)){
			tokenvalue =c-'0';
			c=getc(f1);
			while (isdigit(c)){
				tokenvalue*=10+c-'0';
				c =getc(f1);
			}
			num[i++]=tokenvalue;
			ungetc(c ,f1);
			count =i;
		}
		else if(isalpha(c)){
			putc(c ,f2);
			c =getc(f1);
			while(isdigit(c)|| isalpha(c)|| c=='_' || c=='$'){
				putc(c ,f2);
				c =getc(f1);
			}
			putc(' ',f2);
			ungetc(c ,f1);
		}
		else if(c==' ' || c=='\t')
			printf(" ");
		else if(c =='\n')
			lineno++;
		else
			putc(c ,f3);
	}
	fclose(f2);
	fclose(f3);
	fclose(f1);

	printf("\n the no's in the prgm are:");
	for (i =0 ;i<count ; i++)
		printf("%d \t" ,num[i]);
	for (j=0 ;j<1 ;j++){
		printf("\n");
		f2 =fopen("identifier" ,"r");
		k=0;
		printf("\n the keyword and identifiers are:");
		while((c =getc(f2))!=EOF){
			if (c!=' ')
				str[k++] =c;
			else{
				str[k] ='\0';
				keyword(str);
				k =0;
				}
		}

		fclose(f2);
		f3 =fopen("specialchar" ,"r");
		printf("\n the special characters are :");
		while((c=getc(f3))!=EOF){
			printf("%c" ,c);
			s_count++;
		}
	}


	printf("\n");
	fclose(f3);
	printf("\n total number of lines are :%d \n" ,lineno);
	printf("\n count of numbers are :%d \n" ,count);
	printf("\n total number of keywords are :%d \n"  ,k_count);
	printf("\n total number of identifiers are :%d \n" ,i_count);
	printf("\n total number of special characterzs are :%d \n" ,s_count);

}

