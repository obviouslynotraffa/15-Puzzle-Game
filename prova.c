#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define rows 4
#define columns 4

void find_zero(int table[rows][columns], int *row_zero, int *column_zero)
{//PRE: table is not empty

   for ( int i = 0; i < rows; i++)
   {
      for ( int j = 0; j < columns; j++)
      {
         if(table[i][j]==0)
         {
            *row_zero=i;
            *column_zero=j;
         }
      }
      
   }
//POST: return the position of the blank space
}

int count_inversions(int array[])
{
   //PRE: table is not empty


   int inv_count = 0;

    for (int i = 0; i < rows * columns - 1; i++)
    {
        for (int j = i + 1; j < rows * columns; j++)
        {
            if (array[j] && array[i] && array[i] > array[j])inv_count++;
        }
    }

    return inv_count;

   //POST: return the number of inversions
}

int isSolvable(int table[rows][columns], int *row_zero, int *column_zero)
{

   /*The 15 puzzle is solvable only if:
   - the blank space is on a even row and the number of inversions is odd;
   - the blank space is on a odd row and the number of inversions is even;
   In any other cases, the puzzle is not solvable;


    "inversion"  mean when we have a pair or tiles (a,b) and a appears before b but a>b 


   */

   int inversions_n = count_inversions((int*)table);

   find_zero(table, row_zero, column_zero);

   if(*row_zero%2==0 && inversions_n%2!=0)return 1;
   if(*row_zero%2!=0 && inversions_n%2==0)return 1;


   return 0;
}

void create_table(int table[rows][columns])
{
   //PRE: 
   int j;
   int temp;
   int a[rows*columns];
   int min=0, max=15;
   

   srand(time(NULL));
   
   for (int i = 0; i < rows*columns; i++)
   {

      temp=rand()%16;

      if(i==0)
      {
         a[i]=temp;
      }else
         {
         int check=0;
         j=0;
         
         while(check==0 && j<i)
         {
            if(a[j]==temp)check=1;
            j++;
         }

         if(check==0)a[i]=temp;
         else i--;
         }
      
   }
   int k=0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j <columns; j++)
      {
        table[i][j]=a[k];
        k++;
      }
      
   }

   //POST: create a table with random distinct numbers between 0-15
}

void print_table(int table[rows][columns])
{
   //PRE: table is not empty

   printf("---------------------\n");
   printf("   15 Puzzle Game    \n");
   printf("---------------------\n");

    for (int i = 0; i < rows; i=i+1) {
      for (int j = 0; j < columns; j+=1) { 
         printf("%-5d ", table[i][j]);
      } 
      printf("\n"); 
   }
   printf("\n");  

   //POST: print the table
}

int move_tiles(int table[rows][columns], int *tile, int row_zero, int column_zero)
{
   //PRE: table is not empty and row/column_zero has value
   int check=0;

   if(*tile==table[row_zero][column_zero+1])
   {
      int swap=table[row_zero][column_zero];
      table[row_zero][column_zero]=table[row_zero][column_zero+1];
      table[row_zero][column_zero+1]=swap;
      
      return check+1;
   }

   if(*tile==table[row_zero][column_zero-1])
   {
      int swap=table[row_zero][column_zero];
      table[row_zero][column_zero]=table[row_zero][column_zero-1];
      table[row_zero][column_zero-1]=swap;
      
      return check+1;
   }

   if(*tile==table[row_zero+1][column_zero])
   {
      int swap=table[row_zero][column_zero];
      table[row_zero][column_zero]=table[row_zero+1][column_zero];
      table[row_zero+1][column_zero]=swap;
      
      return check+1;
   }

   if(*tile==table[row_zero-1][column_zero])
   {
      int swap=table[row_zero][column_zero];
      table[row_zero][column_zero]=table[row_zero-1][column_zero];
      table[row_zero-1][column_zero]=swap;
      
      return check+1;
   }


   return check;

   //POST: check if the tile to move is near the blank space and swap them
}

int check_victory(int* table)
{
   //PRE: table is not empty

   for( int i=0; i< rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if(i==rows-1 && j==columns-2 && *(table+rows*columns-1)==0) return 1;
         
         if(*(table+i*columns+j)>*(table+i*columns+j+1))return 0;
         
         
      }
      
   }

   //POST:  check if the table is ordered and if the blank space is a the end of the table
   //       if so print win, if not keep going 

}

int main() {

   int table[rows][columns];
   int tile;
   int row_zero, column_zero;
   int *pointer=table[0];


   /*
   Check if the table just created is solvable,
   if not create another one
   */

  do
  {
     create_table(table);
  } while (isSolvable(table, &row_zero, &column_zero)==0); 
  
  
  do  //repeat until victory or give up
  {
   print_table(table);
   find_zero(table, &row_zero, &column_zero);

   printf("Digit the tile to move: ");
   scanf("%d",&tile);
   printf("\n");

   printf("%s",(move_tiles(table, &tile, row_zero,column_zero)==1)?"Tile moved correctly\n":"You can not move this tile\n");
  }while(check_victory(pointer)==0);

  print_table(table);

  printf("CONGRATULATIONS\nYou Won!");
      
}
