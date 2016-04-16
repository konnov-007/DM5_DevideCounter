#include <stdio.h>
#include <stdlib.h>

int devideTask(){
	//MY NUMBERS ARE 5, 14, 22
	int count=0;
	int num1, num2, num3;
	int choose, max, min;
	FILE *result;
	result = fopen ("DevideCounter.txt", "w");
	
	puts("Input first, second and third number that will be devided:\n");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	puts("\nInput range (for example '100 999' means range [100, 999]:\n ");
	scanf("%d %d", &min, &max);

	puts("\nChoose condition:\n");
	printf("1)Numbers [%d;%d] devide by %d or %d or %d\n",min, max, num1, num2, num3);
	printf("2)Numbers [%d;%d] devide by only one of these numbers\n", min, max);
	printf("3)Numbers [%d;%d] devide by %d and %d and %d\n",min, max, num1, num2, num3);
	
	do{
	puts("\nInput 1, 2 or 3:\n");
	scanf("%d", &choose);


if(choose==1)
{
	printf("\n\nFor [%d; %d]:\n\n", min, max);
	fprintf(result, " For numbers [%d;%d] devide by %d or %d or %d:\n\n",min, max, num1, num2, num3);
	for(int i=min; i<=max; i++)
{
	if(i%num1==0||i%num2==0||i%num3==0)  
{
	 count++; printf("%d can devide by one/all numbers, count=%d\n", i, count); 
	 fprintf(result, "%d can devide by one/all numbers, count=%d\n", i, count); 
} 
    //else { printf("%d can't be devided of one/all of these numbers\n", i); }
}
}



if(choose==2)
{
 printf("\n\nFor [%d; %d]:\n", min, max);
 fprintf(result, " For numbers [%d;%d] devide by only one of these numbers:\n\n", min, max);
	for(int i=min; i<=max; i++)
{
if((i%num1==0)&&(i%num2>0)&&(i%num3>0))  
{ 
	count++; printf("%d can devide by %d, count=%d\n", i, num1, count);
	fprintf(result, "%d can devide by %d, count=%d\n", i, num1, count); 
} 
else if((i%num2==0)&&(i%num1>0)&&(i%num3>0))  
{
	count++; printf("%d can devide by %d, count=%d\n", i, num2, count); 
	fprintf(result, "%d can devide by %d, count=%d\n", i, num1, count);
}  
else if((i%num3==0)&&(i%num2>0)&&(i%num1>0))   
{ 
	count++; printf("%d can devide by %d, count=%d\n", i, num3, count); 
	fprintf(result, "%d can devide by %d, count=%d\n", i, num1, count);
}   
    //else { printf("%d can't be devided of only one number\n", i); }
}	
}


if(choose==3){
	printf("\n\nFor [%d; %d]:\n", min, max);
	fprintf(result, " For numbers [%d;%d] devide by %d and %d and %d:\n\n",min, max, num1, num2, num3);
	for(int i=min; i<=max; i++)
{
	if((i%num1==0)&&(i%num2==0)&&(i%num3==0))  
{ 
count++; printf("%d can devide by all numbers, count=%d\n", i, count);
fprintf(result, "%d can devide by all numbers, count=%d\n", i, count);
} 
    //else { printf("%d can't be devided of one/all of these numbers\n", i); }
}
}
}while(choose!=1&&choose!=2&&choose!=3);
printf("\n In results, %d number(s) can be devided\n\n", count);
fprintf(result, "\n In results, %d number(s) can be devided\n\n", count);



fclose(result);
}


main(){
	 devideTask();
system("PAUSE");
return 0;
}

