#include <fcntl.h>//flags
#include <stdlib.h>//exit
#include <stdio.h>//printf,scanf
#include <time.h>//time computation

//Main program starts here
int main(int argc,char *argv[])
{
//----variable declaraion---------
  char buf;
  int fd1,fd2,a,s,i;
  //a=1024*1024;
  //a=1;
  short x;
  clock_t start, finish;
  double Time_taken;
//----------------------------------

 if(argc!=3) //checking for correct number of parameters
  {
    printf("Incorrect parameters");  
    exit(-1);
  }
 else
  {
    fd1 = open(argv[1], O_RDONLY,0777); //opening the file to be copied from
    if(fd1==-1)
      {
        printf("Source File: File could not be opened or does not exist");
        exit(-1);
      }
    else
      {
        
  
  printf("press x to copy x Bytes files file\n" );
  scanf("%d",&x);
   s=x;
   printf("Number of Bytes to be copied: %d Bytes \n",s );

   fd2=open(argv[2],O_CREAT |O_EXCL |O_RDWR,0777); 
        //opening the file to copy to,if do not exist then create and copy
        if(fd2==-1)
          {
            printf("Destination file:Error in opening file at location specified by argv[2]");
            exit(-1);
          }

//--------------------------------------------------------------------
  //Computing time to copy files
  start = clock();
  for ( i = 0; i < s-1; ++i)
  {
    read(fd1, &buf, 1);  //reading from the argv[1] and copying it to buffer c
    write(fd2, &buf, 1);  //reading from buffer c and copying it to fd
  }
  finish = clock();
  Time_taken= ((double) (finish - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed during operation : %f\n",Time_taken); //printing time taken to copy files
  }
//-----------------------------------------------------------------------

//Closing files and removing file specified by argv[1]
  close(fd1);
  close(fd2);
  remove(argv[1]);
//------------------------------------------------------------------------
  
}
  return 0;

}
