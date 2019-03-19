#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	FILE *fp1,*fp2;
	char a[1000],c[1000],d[40];
	char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int length,i,j,k,mode;
	printf("\nThe source to encrypt or to decrypt:");
    fp1=fopen("source.txt","r");
    fgets(a,1000,fp1);
    puts(a);
    fclose(fp1);
    printf("\nSource is:");
    printf("\n%s",a);
    length=strlen(a);
	printf("\nlength of the source:%d\n",length);
	printf("\nEnter the substitution alphanumer key with no repetition.");
	gets(d);
	printf("\nEnter the mode:\n1.Encrypt.\n2.Decrypt.");
	scanf("%d",&mode);
	if(mode==1)
	{
		i=0;
		while(a[i]!='\0')
		{
			strupr(a);
			for(j=0;b[j]!='\0';j++)
			{
				if(a[i]!=b[j])   
					c[k]=a[i];  
				if(a[i]==b[j])
				{
					c[k]=d[j];
					break;
				}
			}
		printf("%c",c[k]);  
		k++;
		i++;
		}
	}
	else
	{
		i=0;
		while(a[i]!='\0')
		{
			strupr(a);
			for(j=0;d[j]!='\0';j++)
			{
				if(a[i]!=d[j])   
					c[k]=a[i];  
				if(a[i]==d[j])
				{
					c[k]=b[j];
					break;
				}
			}
		printf("%c",c[k]);  
		k++;
		i++;
		}
	}	
	fp2=fopen("out.txt","a");
	fputs(c,fp2);
	fclose(fp2);
	printf("\n________________________________________________________\n");
	printf("\t\t\tAB WAR");
	printf("\n________________________________________________________\n");
}
