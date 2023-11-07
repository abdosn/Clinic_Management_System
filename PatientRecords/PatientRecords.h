#ifndef PATIENT_RECORDS_H_
#define PATIENT_RECORDS_H_

#include <string.h>
#include <stdint.h>

#define MALE    0
#define FEMALE  1


typedef struct PatientData
{
    char Name[50];
    uint8_t Age;
    uint8_t Gender;
    uint16_t Id;
}PatientData_t;


typedef struct PatientRecords
{
    PatientData_t*       Patient;
    PatientRecords_t*   pNext;
}PatientRecords_t;

typedef enum Error
{
    Succeded    ,
    IdExist     

}Error_t ;

Error_t AddPatient(uint16_t Copy_u16Id , char* Copy_ptrName ,uint8_t Copy_u8Age ,uint8_t Copy_u8Gender );

void ViewPatient(uint16_t Copy_u16Id);

#endif