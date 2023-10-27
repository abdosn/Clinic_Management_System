#include "PatientRecords.h"


static PatientRecords_t MyRecords;
static uint16_t NoOfPatients;
void AddPatient(uint16_t Copy_u16Id , char* Copy_ptrName ,uint8_t Copy_u8Age ,uint8_t Copy_u8Gender )
{
    PatientRecords_t * Loc_ptrRecords = &MyRecords;
    
    PatientRecords_t * Loc_ptrNewRecord = (PatientRecords_t *)malloc(sizeof(PatientRecords_t));
    // Loc_ptrNewRecord->Patient.
    
    while (Loc_ptrRecords->pNext != NULL)
    {
        Loc_ptrRecords = Loc_ptrRecords->pNext;
    }

    
    
}

void RemovePatient(uint16_t Copy_u16Id)
{

}

void EditPatient(uint16_t Copy_u16Id)
{

}