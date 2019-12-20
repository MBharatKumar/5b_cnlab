#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
 int sender(int b[10],int k)
 {
 	int checksum,sum=0,i;
        	printf("\n****SENDER****\n");
     
for(i=0;i<k;i++)
      		sum+=b[i];
      		printf("SUM IS: %d",sum);
                     
    	checksum=~sum;
    	printf("\nSENDER's CHECKSUM IS:%d",checksum);
    	return checksum;
}
 
int receiver(int c[10],int k,int scheck)
{
int checksum,sum=0,i;
     	printf("\n\n****RECEIVER****\n");
     	for(i=0;i<k;i++)
      		sum+=c[i];
      	printf(" RECEIVER SUM IS:%d",sum);
      	sum=sum+scheck;
      	checksum=~sum;
      	printf("\nRECEIVER's CHECKSUM IS:%d",checksum);
      		return checksum;
  }
    void main()
   {
     	int a[10],i,m,n,scheck,rcheck;
     	printf("\nENTER SIZE OF THE STRING:");
     	scanf("%d",&m);
     	printf("\nENTER THE ELEMENTS OF THE ARRAY:");
     	for(i=0;i<m;i++)
    	scanf("%d",&a[i]);
    	scheck=sender(a,m);
	printf("\n enter 1 for error free data and enter 2 for error in data \n");
	scanf("%d",&n);
	if(n == 1)
    	rcheck=receiver(a,m,scheck);
	else if(n == 2)
	rcheck=receiver(a,m,scheck+1);
	else printf("\nenter a valid option\n\n");exit(0);
    	if(rcheck==0)
      		printf("\n\nNO ERROR IN TRANSMISSION\n\n");
    	else
      		printf("\n\nERROR DETECTED\n\n");
} 	
