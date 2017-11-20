#include <stdio.h>
#include <stdint.h>
#include "results.h"
#include <stdlib.h>
#include <string.h>

char mat[8][8];

int64_t byte8_md5(){
	return 0x3b1ee5f6b3d99ff7;
}

uint64_t sub_403034(uint64_t a1)
{
	return 1103515245 * a1 + 12345;
}

void xor_dest(char *dest, unsigned int size, int64_t hash){

  	int64_t result;
  	int64_t v4;
  	signed int i;

  	v4 = hash;
  	for ( i = 0; ; ++i )
  	{
    		result = (unsigned int)i;
    		if ( i >= (signed int)size )
      			break;
    		v4 = sub_403034(v4);
    		dest[i] ^= v4;
  	}
}


void sub_4030AF(char* a1)
{
	int v2;
 	uint64_t i;

  	//printf("Shot!!**\n");
  	*(uint64_t *)(a1 + 16) += 1427 * *(uint8_t *)(a1 + 0x1D)
                        + 7681 * *(uint8_t *)(a1 + 28)
                        + *(uint8_t *)(a1 + 28) * *(uint8_t *)(a1 + 29)
                        + 5281;
  	v2 = 0;
  	for ( i = *(uint64_t *)(a1 + 8); i; i >>= 1 )
  	{
    		if ( i & 1 )
      		++v2;
  	}
  	if ( *(uint32_t *)(a1 + 24) <= v2 )
    	++*(uint64_t *)(a1 + 16);
}


/*

 v19 = 0;
  printf(format, &v4);
  *(_QWORD *)(a1 + 16) += 1427 * *(_BYTE *)(a1 + 0x1D)
                        + 7681 * *(_BYTE *)(a1 + 28)
                        + *(_BYTE *)(a1 + 28) * *(_BYTE *)(a1 + 29)
                        + 0x14A1;
  v2 = 0;
  for ( i = *(_QWORD *)(a1 + 8); i; i >>= 1 )
  {
    if ( i & 1 )
      ++v2;
  }
  if ( *(_DWORD *)(a1 + 24) <= v2 )
    ++*(_QWORD *)(a1 + 16);
  return *MK_FP(__FS__, 40LL) ^ v20;
}
*/


int sub_4038D6(char* a1, uint64_t a2)
{
	int result = 0;
  	int64_t v3;
  	uint64_t whatthefuck = a2;
  	int v5 = 0;
  	int v6;
  	uint64_t i;
  
  	//printf("Rank %s, %lx\n", a1 + 30, a2);

  	v6 = 0;
  	for ( i = *(uint64_t *)(a1 + 8); i; i >>= 1 )
  	{
    		if ( i & 1 )
      		++v6;
  	}
  	if ( v6 + 1 <= *(uint32_t *)(a1 + 24) )
  	{
    		//printf("0x%lx & 0x%lx === 0x%lx &0x%lx \n",*(uint64_t *)a1, *(uint64_t *)(a1 + 8), whatthefuck, *(uint64_t *)a1 );
   
    		if ( (*(uint64_t *)a1 & *(uint64_t *)(a1 + 8)) <= (whatthefuck & *(uint64_t *)a1) ) // shot or not 
    		{ 
      			if ( *(uint64_t *)(a1 + 8) ) // 1
      			{
        			printf("You missed\n");
      			}
      			else // 0     
      			{
        			printf("int: [%s]\n", a1 + 62);
      			}
    		}
    		else         // shot
    		{
      			sub_4030AF(a1);
    		}
  	}
  	else
  	{
    		printf("out of ammo\n");v5 = 2;
  	}


  	if ( *(uint64_t *)(a1 + 16) == 0x216B6E75736C6C61LL )
  	{
    		printf("Thanks for playing\n");v5 = 3;
  	}
  	else if ( !v5 && (*(uint64_t *)a1 & *(uint64_t *)(a1 + 8)) == *(uint64_t *)a1 )
  	{
    		printf("You sunk all ships\n");
    		//sub_403530();
    		v5 = 1;
  	}

  	result = v5;
	return result;
}


/*
*(uint64_t *)a1 //(*(uint64_t *)a1 & *(uint64_t *)(a1 + 8))

(uint64_t *)(a1 + 8) // *(uint64_t *)(a1 + 8) |= 1 << (8 * (uint8_t)v2 + v3);

*(uint64_t *)(a1 + 16) // hash

*(uint32_t *)(a1 + 24) // bullets
*(char *)(a1 + 28) // chr
*(char *)(a1 + 29) // num
*(char *)(a1 + 30) // string
*/



void enter_cord(char* a1)
{

	int v2;
    	int v3;
   

    	char y[] = {'1', '2', '3', '4', '5', '6', '7', '8', '\0'};
    	char x[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '\0'};

    	uint64_t gamevar =  *(uint64_t *)(a1) - *(uint64_t *)(a1+8);

    	int count = 0;
    	while (!(gamevar&1)){
		count ++;
		gamevar >>= 1;
		
    	}
    
    	v2 = count / 8;
    	v3 = count % 8 ;
    
        mat[v2][v3] = 'o';


    	//printf("%d %d\n", v2, v3);   
 
    //printf("before -> %lx\n", *(uint64_t *)(a1 + 8));

    *(uint64_t *)(a1 + 8) |= (uint64_t) 1 << (8 * (uint8_t)v2 + v3);
    
    //printf("after -> %lx\n", *(uint64_t *)(a1 + 8));

    


    *(char *)(a1 + 28) = x[v2];
    *(char *)(a1 + 29) = y[v3];

    //printf("setting %c%c\n", *(char *)(a1 + 28), *(char *)(a1 + 29));
}

void clearmat(){
int i, j;

for (i=0; i<=7; i++){
	for (j=0; j<=7; j++){
	mat[i][j] = ' ';
	}
}

}

void printmat(){
int i, j;

for (i=0; i<=7; i++){
        for (j=0; j<=7; j++){
        printf("%c", mat[i][j]);
        }
	printf("\n");
}

}



unsigned int print_game(char* a1)
{
  int v2; 
  signed int i; 
  uint64_t v4;

  v4 = 0;
  v2 = 0;
  for ( i = 0; i <= 63; ++i )
  {
	//printf("inside loop %d\n", i);
        //clear();    
        //return_board(a1);
  
        v2 = sub_4038D6(a1, v4);
    	
        if ( (signed int)v2 > 0 )
      		break;
    	
        v4 = *(uint64_t *)(a1 + 8);

    	enter_cord(a1); //sub_40377D(a1)
  }
  return v2;
}



void main(){
	unsigned int i;
	char *dest = malloc(576);
  	int64_t hash = byte8_md5();
  	for ( i = 0; i <= 0x63; ++i )
  	{
		printf("[+] main loop => %d\n", i);
    		memcpy(dest, &ida[576*i], 576); 
		xor_dest(dest, 576, hash);
                // printf("[+] Hash after decoding 0x%lx\n", *(int64_t*)(dest + 16));
                clearmat();
    		if ((unsigned int) print_game(dest) != 1 ){
			break;
		}
                printmat();	
		hash = *(int64_t*)(dest + 16);
		// printf("[+] Hash after game  0x%lx", hash);

  	}
	free(dest);
}

