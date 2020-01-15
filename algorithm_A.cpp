#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions
 * 1. ~ 4. are listed in next block)
 *
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 *
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/


void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    srand(time(NULL));
    int row, col;

    int color = player.get_color();

    while(1){
        //to find a random cell
        row = rand() % 5;
        col = rand() % 6;
        //corner = rand() % 4;
        //**********************************************//
        //**********************************************//
        //**********************************************//
        //find our cell at threshold
        for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                if(board.get_cell_color(i,j)==color && board.get_capacity(i,j)!=2){
                    if( (board.get_capacity(i,j)-board.get_orbs_num(i,j))==1 ){
                        row=i;
                        col=j;
                    }
                }
            }
        }

        //**********************************************//
        //**********************************************//
        //**********************************************//
        //find the empty corner

        if(board.get_cell_color(0,0)=='w' ){
            row=0;
            col=0;
        }
        else if(board.get_cell_color(0,5)=='w' ){
            row=0;
            col=5;
        }
        else if(board.get_cell_color(4,0)=='w' ){
            row=4;
            col=0;
        }
        else if(board.get_cell_color(4,5)=='w'){
            row=4;
            col=5;
        }
        else{}

        //**********************************************/
        //**********************************************/
        //**********************************************/
        //find our corner whose adjacency cell is at threshold
        if( board.get_cell_color(0,0)==color &&((board.get_capacity(0,1)-board.get_orbs_num(0,1))<=1 || (board.get_capacity(1,0)-board.get_orbs_num(1,0))<=1) ){
            row=0;
            col=0;
        }
        else if( board.get_cell_color(0,5)==color &&((board.get_capacity(0,4)-board.get_orbs_num(0,4))<=1 || (board.get_capacity(1,5)-board.get_orbs_num(1,5))<=1) ){
            row=0;
            col=5;
        }
        else if( board.get_cell_color(4,0)==color &&((board.get_capacity(4,1)-board.get_orbs_num(4,1))<=1 || (board.get_capacity(3,0)-board.get_orbs_num(3,0))<=1) ){
            row=4;
            col=0;
        }
        else if( board.get_cell_color(4,5)==color &&((board.get_capacity(4,4)-board.get_orbs_num(4,4))<=1 || (board.get_capacity(3,5)-board.get_orbs_num(3,5))<=1) ){
            row=4;
            col=5;
        }
        else{}
        //**********************************************/
        //**********************************************/
        //**********************************************/
        if(board.get_cell_color(row, col) == color || board.get_cell_color(row, col) == 'w') break;
    }

    index[0] = row;
    index[1] = col;
}
