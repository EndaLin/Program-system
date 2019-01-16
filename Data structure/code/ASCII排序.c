#include <stdio.h>
#include<string.h>
void main( )
{
    int i,j,k,a=0;
	char s[1][4],(*p)[4]=s,*min,temp;
	

   while(scanf("%s",s)!=EOF){

	  for(i=0;i<1;i++){
	      min=*(p+i);
		for(k=0;k<3;k++){
			min=*(p+i)+k;
		  for(j=k;j<3;j++){
			if(strcmp(min,*(p+i)+j)>0){
			       min=*(p+i)+j;
			}
	  }
		temp=*min;
		*min=*(*(p+i)+k);
		*(*(p+i)+k)=temp;
		
	  }
	}


	for(i=0;i<1;i++){
		for(j=0;j<3;j++){
			printf("%c",*(*(p+i)+j));
			if(j!=2)printf(" ");
		}
		printf("\n");
	}
   }
}           