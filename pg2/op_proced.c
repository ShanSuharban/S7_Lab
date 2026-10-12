#include <stdio.h>
#include <string.h>

void main(){
	char stack[20] ,ip[20] ,opt[10][10][2] ,ter[10];
	int i ,j ,k ,n ,top =0 ,row ,col;
	for (i =0 ;i<10 ;i++){
		stack[i] =0;
		ip[i] =0;
		for (j =0 ;j<10 ;j++){
			opt[i][j][1] =0;
		}
	}
	printf("enter the no of terminals:");
	scanf("%d" ,&n);
	printf("enter terminals:");
        scanf("%s" ,ter);
	printf("enter the table values:\n");
        for (i =0 ;i<n ;i++){
		for (j =0 ;j<n ;j++){
			printf("enter values for %c%c" ,ter[i] ,ter[j]);
			scanf("%s" ,opt[i][j]);
		}
	}
	printf("\n operator presedence table :\n");

	for (i =0 ;i<n ;i++){
		printf("\t%c" ,ter[i]);
	}

	printf("\n");
	printf("\n");
	for (i =0 ;i<n ;i++){
                printf("\n%c|" ,ter[i]);
		for(j =0 ;j<n ;j++){
			printf("\t%s" ,&opt[i][j][0]);
		}
        }
	stack[top] ='$';
	printf("\n\nenter the input:");
	scanf("%s" ,ip);



	printf("\nstack\t\t\tinput string\t\t\taction");
	printf("\n%s\t\t\t%s\t\t\t",stack ,ip);
	i =0;
	while(i < strlen(ip)){
		for (k =0 ;k<n ;k++){
			if(stack[top] == ter[k]){
				row =k;}
			if(ip[i] == ter[k]){
				col =k;}
		}
		if( stack[top] == '$' && ip[i] =='$'){
			printf("str is accepted");
			break;
		}
		else if((opt[row][col][0]=='<')||( opt[row][col][0] == '=')){
			stack[++top] = opt[row][col][0];
			stack[++top] = ip[i];
			ip[i]=' ';
			printf("shift %c",ip[i]);
			i++;
		}
		else{
			if (opt[row][col][0]=='>'){
				while (stack[top] != '<'){
					--top;}
				top =top -1;
				printf("reduce");
			}
			else{
				printf("\n string not accepted");
				break;
			}
		}
		printf("\n");
		for (k =0 ;k<=top ;k++){
			printf("%c",stack[k]);
		}
		printf("\t\t\t");
		for(k =0 ;k<strlen(ip);k++){
			printf("%c" ,ip[k]);
		}
		printf("\t\t\t");
	}
}

