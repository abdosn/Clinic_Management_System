/**
 * @file main.c
 * @author Abdelrahman Sobhy (abdonassar@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <stdio.h>

int mode = 0;

void main(void)
{
    scanf("1-Admin mode\n2-User mode\nEnter mode number : %d" , &mode);

    if(mode == 1)
    {
        
    }
    else if(mode == 2)
    {

    }
    else
    {
        printf("Wrong Entry..Try again\n");
    }


}