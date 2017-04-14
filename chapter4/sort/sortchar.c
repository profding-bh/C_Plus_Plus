#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char word[100];

int cmp( const void *a , const void *b )
{
//注意，网上很多版本是 “ return *(char *)a - *(int *)b;  ” 
//因为编辑者的不用心，盲目copy，以讹传讹，传的一直是错的 *(int *)b
//应该是return *(char *)a - *(char *)b;
return *(char *)a - *(char *)b;
}

int main()
{
 printf("Please input a string:");
 scanf("%s",word);
 
 
qsort(word,strlen(word),sizeof(word[0]),cmp);
//附，可能 getchar();  会派上用场 

printf("%s",word);
printf("\n");
return(0);
}
