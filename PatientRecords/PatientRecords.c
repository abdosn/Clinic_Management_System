/**
 * @file PatientRecords.c
 * @author Abdelrahman Sobhy (abdonassar@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "PatientRecords.h"


static PatientRecords_t MyRecords;
static uint16_t NoOfPatients;


/**
 * @brief Add new patient record
 * @param Copy_u16Id ID for the patient -- shall be unique
 * @param Copy_ptrName Name of the patient
 * @param Copy_u8Age Age of the patient
 * @param Copy_u8Gender Gender of patient should be a value from @ref GENDER
 * @return IdExist if Id is repeated or succedded otherwise //TODO Add multiple error returns for various errors 
 */
Error_t AddPatient(uint16_t Copy_u16Id , char* Copy_ptrName ,uint8_t Copy_u8Age ,uint8_t Copy_u8Gender )
{
    PatientRecords_t * Loc_ptrRecords = &MyRecords;
    
    // Loc_ptrNewRecord->Patient.
    
    while (Loc_ptrRecords->pNext != NULL)
    {
        if (Loc_ptrRecords->Patient->Id == Copy_u16Id)
        {
            return IdExist;
        }
        else
        {
            /* Do Nothing */
        }
        
        Loc_ptrRecords = Loc_ptrRecords->pNext;
    }
    if (Loc_ptrRecords->Patient->Id == Copy_u16Id)
    {
        return IdExist;
    }
    else
    {
        /* Do nothing */
    }
    PatientData_t * Loc_ptrNewRecord = (PatientData_t *)malloc(sizeof(PatientData_t));
    
    Loc_ptrNewRecord->Id = Copy_u16Id;
    strcpy(Loc_ptrNewRecord->Name , Copy_ptrName);
    Loc_ptrNewRecord->Age = Copy_u8Age;
    Loc_ptrNewRecord->Gender = Copy_u8Gender;
    
    while (Loc_ptrRecords != NULL)
    {
        Loc_ptrRecords = Loc_ptrRecords->pNext;
    }


    
    Loc_ptrRecords->Patient = Loc_ptrNewRecord;

    return Succeded;
    
}
/**
 * @brief Remove patient record
 * 
 * @param Copy_u16Id Id of the patient to be removed
 * @return Error_t IdNotFound or succeded
 */
Error_t RemovePatient(uint16_t Copy_u16Id)
{
    PatientRecords_t * Loc_ptrRecords = &MyRecords;
    PatientRecords_t * Loc_ptrPrev = &MyRecords;
    while(Loc_ptrRecords != NULL || Loc_ptrRecords->Patient->Id != Copy_u16Id)
    {
        Loc_ptrPrev = Loc_ptrRecords;
        Loc_ptrRecords = Loc_ptrRecords->pNext;
    }

    if (Loc_ptrRecords == NULL)
    {
        return IdNotFound;
    }
    else
    {
        free(Loc_ptrRecords->Patient);
        Loc_ptrPrev->pNext = Loc_ptrRecords->pNext;
        Loc_ptrRecords->Patient = NULL;
        return Succeded;
    }
    
}
/**
 * @brief Edit Patient data
 * 
 * @param Copy_u16OldId Id of the patient to be edited
 * @param Copy_NewPatientData New Patient Data
 * @return Error_t IdNotFound or Succeded
 */
Error_t EditPatient(uint16_t Copy_u16OldId, PatientData_t Copy_NewPatientData)
{
    PatientRecords_t * Loc_ptrRecords = &MyRecords;
    while(Loc_ptrRecords != NULL || Loc_ptrRecords->Patient->Id != Copy_u16OldId)
    {
        Loc_ptrRecords = Loc_ptrRecords->pNext;
    }

    if(Loc_ptrRecords == NULL)
    {
        return IdNotFound;
    }
    else
    {
        Loc_ptrRecords->Patient->Id = Copy_NewPatientData.Id;
        Loc_ptrRecords->Patient->Age = Copy_NewPatientData.Age;
        strcpy(Loc_ptrRecords->Patient->Name , Copy_NewPatientData.Name);
        Loc_ptrRecords->Patient->Gender = Copy_NewPatientData.Gender;
        return Succeded;
    }
}

/**
 * @brief View patient record and print it on screen
 * @param Copy_u16Id ID of patient
 */
void ViewPatient(uint16_t Copy_u16Id)
{
    PatientRecords_t * Loc_ptrRecords = &MyRecords;

    while( Loc_ptrRecords != NULL || Loc_ptrRecords->Patient->Id != Copy_u16Id )
    {
        Loc_ptrRecords = Loc_ptrRecords->pNext;
    }

    if(Loc_ptrRecords == NULL)
    {
        printf("Id Not Exist\n");
        return;
    }
    else
    {
        printf("Patient Id : %d\nPatient Name : %s\nPatinet Age : %d\nPatient gender : %d\n",Loc_ptrRecords->Patient->Id , Loc_ptrRecords->Patient->Name , Loc_ptrRecords->Patient->Age , Loc_ptrRecords->Patient->Gender);
    }


}