#include "PatientRecords.h"


static PatientRecords_t MyRecords;
static uint16_t NoOfPatients;
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
    PatientRecords_t * Loc_ptrNewRecord = (PatientRecords_t *)malloc(sizeof(PatientRecords_t));
    
    Loc_ptrNewRecord->Patient->Id = Copy_u16Id;
    strcpy(Loc_ptrNewRecord->Patient->Name , Copy_ptrName);
    Loc_ptrNewRecord->Patient->Age = Copy_u8Age;
    Loc_ptrNewRecord->Patient->Gender = Copy_u8Gender;
    
    
    Loc_ptrRecords->Patient = Loc_ptrNewRecord;

    
    
}

void RemovePatient(uint16_t Copy_u16Id)
{

}

void EditPatient(uint16_t Copy_u16Id)
{

}
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