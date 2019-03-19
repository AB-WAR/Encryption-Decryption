#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	FILE *fp1,*fp2;
	char a[1000],c[1000];
	char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,j,key,mode,length,k=0,numb=0,num=0,n;
	printf("\nEnter the source to encrypt or decrypt:");
    fp1=fopen("source.txt","r");
    fgets(a,1000,fp1);
    puts(a);
    fclose(fp1);
    printf("\n%s",a);
    length=strlen(a);
	printf("length of the source:%d\n",length);
	printf("Your cipher series is:%s\n",b);
	printf("Enter the key:");
	scanf("%d",&key);
	strupr(a);
	printf("\nEnter the mode:\n 1 to Encrypt.\n 2 to Decrypt.\nMode:");
    scanf("%d",&mode);
	if(mode==1)
		num=num+key;
	else
		num=num-key;
	printf("\nThe cipher is:\n");
	i=0;
	while(a[i]!='\0')
	{
		for(j=0;b[j]!='\0';j++)
		{
			if(a[i]!=b[j])   
				c[k]=a[i];  
			if(a[i]==b[j])    
			{
				numb=num+j;
				if(numb>=26)
					numb=numb-26;
				else if(numb<0)
					numb=numb+26;
				else
					numb=numb;
				c[k]=b[numb];
				break;
			}				
		}
	printf("%c",c[k]);  
	k++;
	i++;
	numb=num;
	}
	fp2=fopen("out.txt","a");
	fprintf(fp2,"\nKEY:%d\t",key);
	fputs(c,fp2);
	fclose(fp2);
	printf("\n________________________________________________________\n");
	printf("\t\t\tAB WAR");
	printf("\n________________________________________________________\n");
}
