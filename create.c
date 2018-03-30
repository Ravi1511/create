
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc,char *argv[])
{   
	char *test,n;
    int i,s,fd,x,y;
    x=1024*1024;

    if(argc!=2)
    {
    	printf("Invalid arguments..Insert two arguments \n");
    }
    else
    {
    printf("Enter File size in MB : ");
    scanf("%d",&y);
    s=x*y;
    char *a=malloc(sizeof(char)*s);
    printf("%d\n",s);
    fd = open(argv[1],O_CREAT |O_EXCL |O_RDWR,0777); 
    if(fd==-1)
     {
     	printf("Error\n");
     	exit(-1);
     }
 
    else
    {
     for(i=0;i<s;i++)
     {
      write(fd, &a[i], 1);
     }
     exit(0);
    }

    close(fd);
    
}
	return 0;
}
