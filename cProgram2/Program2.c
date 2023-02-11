#include<stdio.h>
#include<stdlib.h>


int combos(int score)
{

    int points, touchdown, FG, safety, touchdown_2, touchdown_1;
    int combos = 0; 


    for(touchdown_2 = 0; touchdown_2 <= score/8; touchdown_2++)
    {
        for(touchdown_1 = 0; touchdown_1 <= score/7; touchdown_1++)
        {
            for(touchdown = 0; touchdown <= score/6; touchdown++)
            {
                for(FG = 0; FG <= score/3; FG++)
                {
                    for(safety = 0; safety <= score/2; safety++)
                    {
                        points = score - (touchdown_2 * 8 + touchdown_1 * 7 + touchdown * 6 + FG * 3 + safety * 2);
                        if (points == 0 )
                        {
                            combos = combos + 1; 
                            
                            printf("\n%d TD + 2pts, %d TD + 1pt, %d TD, %d FG, %d Safety\n", touchdown_2,touchdown_1,touchdown,FG, safety);
                        }
                        
                    }
                }
            }
        }
    }

    printf("\nNumber of Combos: %d", combos);
    return combos;
}






int main()

{


    int myNum;
    printf("Enter 0 or 1 to STOP. \n Enter the NFL score: ");
    
    scanf("%d", &myNum);

    if(myNum == 0 | myNum == 1)
    {
        printf("\nSTOPPING!");
        exit(0);
    }
    else
    {
        combos(myNum);
    }
    
    






}