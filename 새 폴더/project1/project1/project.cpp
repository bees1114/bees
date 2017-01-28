#include <stdlib.h>
#include <stdio.h>

typedef struct Triplet
{
    int row;
    int col;
    int val;

}Tri;

void fast_tran(Tri * T);

int main() {
    int col, row, val;
    //FILE * p = fopen("input.txt", "w");
    FILE * fa =fopen("A.txt", "r");
    FILE * fb =fopen("B.txt", "r");
    
    fscanf(fa, "%d %d %d", &row, &col, &val);
     Tri * tri_A = (Tri *)malloc(sizeof(Tri) * (val+1));
    tri_A[0].row = row;
    tri_A[0].col = col;
    tri_A[0].val = val;
    
    fscanf(fb, "%d %d %d", &row, &col, &val);
    Tri * tri_B = (Tri *)malloc(sizeof(Tri) * (val+1));
    tri_B[0].row = row;
    tri_B[0].col = col;
    tri_B[0].val = val;
    
    fast_tran(tri_A);
    
    
    
    return 0;
}


void fast_tran(Tri * T)
{
	
    printf("aaaa %d", T[1].col);
    Tri * tr_T = (Tri *)malloc(sizeof(Tri) * (T[0].val+1));
    int * term = (int *)malloc(sizeof(int) * (T[0].col));
    int * starting_pos = (int *)malloc(sizeof(int)* (T[0].col));
    tr_T[0].col =T[0].row;
    int col = tr_T[0].row =T[0].col;
    int val = tr_T[0].val =T[0].val;
    int i,j;
    printf("%d", T[1].col);
    
    if(val>0)
    {
        for(i=0;i<col;i++)
            term[i]=0;
        for(i=1;i<=val;i++)
        {
            printf("%d",T[i].col);
            //term[(*T)[i].col]++;
        }
        
        starting_pos[0] = 1;
        
        for(i=0;i<col;i++)
            starting_pos[i] = starting_pos[i-1] + term[i-1];
        
        for(i=0; i<=val;i++)
        {
            j= starting_pos[T[i].col]++;
            tr_T[j].row = T[i].col;
            tr_T[j].col = T[i].row;
            tr_T[j].val = T[i].val;
        }
    }
    
    FILE * transT = fopen("/transT.txt","W");
    for(i=0; i<=val; i++)
    {
        fprintf(transT, "%d %d %d \n",tr_T[i].row,tr_T[i].col,tr_T[i].val);
    }
    
    
}