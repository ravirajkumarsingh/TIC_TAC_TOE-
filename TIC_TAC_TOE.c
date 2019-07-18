#include<stdio.h>
#include<stdlib.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main()
{

    char done;
    printf("This is a game of Tic tac toe.\n");
    printf("You will be playing against the computer.\n");

    done = ' ';
    init_matrix();
    do{

        disp_matrix();
        get_player_move();
        done = check();
        if(done != ' ') break;
        get_computer_move();
        done = check();
    }while(done == ' ');
    if(done == 'X') printf("\nYou WON!!!!\n");
    else printf("\nI WON!!!!\n");
    disp_matrix();

    return 0;
}

void init_matrix()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            matrix[i][j] = ' ';
}

void get_player_move()
{
    int x,y;
    printf("Enter the X and Y coordinates for your moves.\n");
    scanf("%d%*c%d", &x, &y);
    x--;y--;
    if(matrix[x][y] != ' ') {
        printf("Invalid Move. Try Again\n");
        get_player_move();
    }
    else
        matrix[x][y] = 'X';
}

void get_computer_move()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            if(matrix[i][j] == ' ') break;
        if(matrix[i][j] == ' ')break;
    }
    if(i*j == 9) {
        printf("MATCH TIED.\n");
        exit(0);
    }
    else
        matrix[i][j] = 'O';
}

void disp_matrix()
{
    int t;
    for(t=0;t<3;t++){
        printf(" %c | %c | %c ",matrix[t][0],matrix[t][1],matrix[t][2]);
        if(t!=2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

char check(void)
{
    int i;
    for(i=0;i<3;i++)   //checking the rows;
        if(matrix[i][0] == matrix[i][1] &&
           matrix[i][1]== matrix[i][2])
           return matrix[i][0];

    for(i=0;i<3;i++)    //checking for the columns
        if(matrix[0][i] == matrix[1][i] &&
           matrix[1][i] == matrix[2][i])
           return matrix[0][i];

    /*test for the diagonals*/
    if(matrix[0][0] == matrix[1][1] &&
       matrix[1][1] == matrix[2][2])
        return matrix[0][0];
    if(matrix[0][2] == matrix[1][1] &&
       matrix[1][1] == matrix[0][2])
        return matrix[0][2];

    return ' ';
}
