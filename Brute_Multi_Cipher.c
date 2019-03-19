#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	FILE *fp1,*fp2;
	char a[1000],c[1000];
	char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,j,key,length,k,num,n,key_low,key_high;
	printf("\nThe source to decrypt:");
    fp1=fopen("source.txt","r");
    fgets(a,1000,fp1);
    puts(a);
    fclose(fp1);
    printf("\nSource is:");
	printf("\n%s",a);
    length=strlen(a);
	printf("\nLength of the source:%d\n",length);
	printf("Your cipher series is:%s\n",b);
	printf("Enter the range of key:");
	scanf("%d%d",&key_low,&key_high);
	strupr(a);
	printf("\nThe cipher is:\n");
	for(key=key_low;key<=key_high;key++)
	{
		k=0,num=0;
		printf("\nKey %d:",key);
		i=0;
		while(a[i]!='\0')
		{
			for(j=0;b[j]!='\0';j++)
			{
				if(a[i]!=b[j])  
					c[k]=a[i];  
				if(a[i]==b[j])    
				{	
					num=(j*key)%strlen(b);				
					c[k]=b[num];
					break;
				}				
			}
		printf("%c",c[k]);  
		k++;
		i++;
		}
		fp2=fopen("out.txt","a");
		fprintf(fp2,"KEY:%d\t",key);
		fputs(c,fp2);
		fputs("\n",fp2);
		fclose(fp2);
	}
	printf("\n________________________________________________________\n");
	printf("\t\t\tAB WAR");
	printf("\n________________________________________________________\n");
}
