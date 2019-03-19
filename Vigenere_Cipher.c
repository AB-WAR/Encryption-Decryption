#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	FILE *fp1,*fp2;
	char a[1000],c[1000],p[30];
	char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,j,mode,key,length,k=0,numb=0,num=0,n,ch,t;
	int keynum[30];
	printf("\nThe source to decrypt:");
    fp1=fopen("source.txt","r");
    fgets(a,1000,fp1);
    puts(a);
    fclose(fp1);
   	printf("\nEnter cipher phrase:");
	gets(p);
	n=strlen(p);
    length=strlen(a);
    printf("\nEnter the mode(1/2):\n1 to Encrypt.\n2 to Decrypt.");
    printf("\nDefault Decrypt.\n\nMode:");
    scanf("%d",&mode);
	printf("\nLength of the source:%d\n",length);
	printf("\nYour cipher series is:%s\n",b);
	strupr(a);
	printf("\nThe cipher is:\n");
	puts(p);
	if(mode==1)
		printf("\nEncrypted text is:\n");
	else 
		printf("\nDecrypted text is:\n");
	for(i=0;p[i]!='\0';i++)
	{
		keynum[i]=p[i]-97;
	}
	i=0;
	while(a[i]!='\0')
	{
		t=i;
		for(j=0;b[j]!='\0';j++)
		{
			if(a[i]!=b[j]) 
				c[k]=a[i];
			if(a[i]==b[j])    
			{
				ch=t%n;
				switch(ch)
				{
					case 0:key=keynum[0];
					break;
					case 1:key=keynum[1];
					break;
					case 2:key=keynum[2];
					break;
					case 3:key=keynum[3];
					break;
					case 4:key=keynum[4];
					break;
					case 5:key=keynum[5];
					break;
					case 6:key=keynum[6];
					break;
					case 7:key=keynum[7];
					break;
					case 8:key=keynum[8];
					break;
					case 9:key=keynum[9];
					break;
					case 10:key=keynum[10];
					break;
					case 11:key=keynum[11];
					break;
					case 12:key=keynum[12];
					break;
					case 13:key=keynum[13];
					break;
					case 14:key=keynum[14];
					break;
					case 15:key=keynum[15];
					break;
					case 16:key=keynum[16];
					break;
					case 17:key=keynum[17];
					break;
					case 18:key=keynum[18];
					break;
					case 19:key=keynum[19];
					break;
					case 20:key=keynum[20];
					break;
					case 21:key=keynum[21];
					break;
					case 22:key=keynum[22];
					break;
					case 23:key=keynum[23];
					break;
					case 24:key=keynum[24];
					break;
					case 25:key=keynum[25];
					break;
				}
				if(mode==1)
					num=+key;
				else
					num=-key;
				numb=num+j;
				if(numb>=strlen(b)&&numb<=2*strlen(b))
					numb=numb-strlen(b);
				else if(numb<0)
					numb=numb+strlen(b);
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
	fputs(c,fp2);
	fclose(fp2);
	printf("\n________________________________________________________\n");
	printf("\t\t\tAB WAR");
	printf("\n________________________________________________________\n");
}
