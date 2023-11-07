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
#include <stdint.h>
#include <string.h>

#include "PatientRecords/PatientRecords.h"
int mode = 0;
char SavedPassword[30] = "1234";
void main(void)
{
    scanf("1-Admin mode\n2-User mode\nEnter mode number : %d" , &mode);

    if(mode == 1) // Admin Mode
    {
        int trails = 3 ;
        char EnteredPassword[30];
        while(trails != 0)
        {
            scanf("Enter Password : %s",&EnteredPassword);
            if(strcmp(SavedPassword , EnteredPassword) == 0)
            {
                printf("Access Granted\n");
                break;                
            }
            else
            {
                trails --;
                printf("Wrong password\nYou have %d trails left",trails);
                if(trails == 0)
                {
                    return;
                }
            }
        }
        int AdminMode;
        scanf("Options Avaliable\n1-Add new patient record\n2-Edit patient record\n3-Reserve a slot with the doctor\n4-Cancel reservation\nEnter option number : %d",&AdminMode);
        switch (AdminMode)
        {
        case 1:
            uint16_t EnteredID;
            char*EnteredName;
            uint8_t EnteredAge;
            uint8_t EnteredGender;
            scanf("## Add new patient record ##\nEnter the following data\nPatient ID : %d\nName of patient : %s\nAge : %d\nGender(Male 0 , Female 1) : %d" , &EnteredID , &EnteredName , &EnteredAge , &EnteredGender);
            AddPatient(EnteredID , EnteredName , EnteredAge , EnteredGender);   
            break;
        case 2:

            break;
        case 3:

            break;

        case 4:

            break;
        default:
            break;
        }

    }
    else if(mode == 2)
    {
        int UserMode;
        scanf("Options Avaliable\n1-View patient record\n2-View today's reservations\nEnter option number : %d",&UserMode);
        switch (UserMode)
        {
        case 1:
            uint16_t EnteredId;
            scanf("## View patient record ##\nEnter Patient Id : %d" , &EnteredId);
            ViewPatient(EnteredId);
            break;
        
        case 2:

            break;
        default:
            break;
        }

    }
    else
    {
        printf("Wrong Entry..Try again\n");
    }


}