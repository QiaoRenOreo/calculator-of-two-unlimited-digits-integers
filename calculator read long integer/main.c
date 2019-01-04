#include <stdio.h>
#include <stdlib.h>
/*
void GetLongInt(char *array)
{
    int size1=4;
    char *var1;
    var1=(char*)malloc(size1*sizeof(char));//*sizeof(char));//sizeof(char)=1 integer
    int i=0,j=0;
    char c;
    c=getchar();
    while(c!='\n')//('0'<=(c=getchar())&&(c=getchar())<='9') ||((c=getchar())=='\\') )
    {

         if (c=='\\')
        {
            while (getchar()!='\n')
                ;
        }
        else
        {
             if (i==size1)
            {
                char *temp;
                temp=(char*)malloc(size1+4);
                for (j=0;j<size1;j++)
                {
                    temp[j]=var1[j];
                }
                free(var1);
                var1=temp;
                size1=size1+4;
            }
        }
            var1[i] =c;
            i=i+1;
            c=getchar();
    }
    printf("print long integer\n");
    for (i=0;i<size1;i++)
    {
        printf ("here: %d:%c\n",i,var1[i]);
    }
}


int main ()
{
    char *var1;
    printf("Enter the 1st integer number: \n");
    GetLongInt(var1);
    return 0;
}
*/

/*
int getLine(char *);
int main()
{
    char b[20]="";
    int rv=0;
    printf("enter your name");
    rv=getLine(b);
    if (rv>0)
    {
        printf("Hello %s\n",b);
    }
    printf("b[3]=%c\n",b[3]);
    b[3]=b[3]-'0';
    printf("b[3]integer=%d\n",b[3]);
    return 0;
}

int getLine(char *buffer)
{
    char c;
    int n=0;
    c=getchar();
    while(c!='\n')
    {
        buffer[n]=c;
        n++;
        c=getchar();
    }
    return n;
}
*/



/*
#include <stdio.h>

int main ()
{
   char c;

   printf("Enter character: ");
   c = getchar();

   printf("Character entered: ");
   putchar(c);
   printf("\n\n");
   return(0);
}
*/
/*
void main()
{
int i = 0;
char name[20];
printf("Enter the Name : ");
while((name[i] = getchar())!='\n')
{
    printf("%d%c,",i,name[i]);
    i++ ;
}
getch();
}
*/
int main(int argc, char ** argv) {
  int * arr;
  foo(arr);
  printf("car[3]=%d\n",arr[3]);
  free (arr);
  return 1;
}

void foo(int * &arr ) {
  arr = (int*) malloc( sizeof(int)*25 );
  arr[3] = 69;
}
