#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	FILE *fp1,*fp2;
	char a[1000],c[1000];
	char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,j,key,length,k,numb,num,n,z;
	printf("\nEnter the source to decrypt:");
    fp1=fopen("source.txt","r");
    fgets(a,200,fp1);
    puts(a);
    fclose(fp1);
    printf("\nSource is:");
    printf("\n%s",a);
    length=strlen(a);
	printf("\nlength of the source:%d\n",length);
	printf("Your cipher series is:%s\n",b);
	strupr(a);
	for(key=0;key<strlen(b);key++)  /
	{
		num=0;
		numb=0;
		printf("\nKEY %d: ",key);
		num=num-key;   
		k=0;
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
					if(numb>26)
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
		fprintf(fp2,"KEY:%d\t",key);
		fputs(c,fp2);
		fputs("\n",fp2);
		fclose(fp2);	
	}
	printf("\n________________________________________________________\n");
	printf("\t\t\tAB WAR");
	printf("\n________________________________________________________\n");
}
