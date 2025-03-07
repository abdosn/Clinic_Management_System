/**
 * @file PatientRecords.h
 * @author Abdelrahman Sobhy (abdonassar@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PATIENT_RECORDS_H_
#define PATIENT_RECORDS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/** @defgroup GENDER
 * @{
*/
#define MALE    0
#define FEMALE  1
/**
 * @}
*/

/**
 * @brief Patient Data structure definition
 */
typedef struct PatientData
{
    char Name[50];
    uint8_t Age;
    uint8_t Gender;
    uint16_t Id;
}PatientData_t;


/**
 * @brief Patient Records structure definition
 */
typedef struct PatientRecords
{
    PatientData_t*       Patient;
    struct PatientRecords *   pNext;
}PatientRecords_t;


/**
 * @brief Error structure definition
 */
typedef enum Error
{
    Succeded    ,
    IdExist     ,
    IdNotFound

}Error_t ;


/** @defgroup PatientRecords_Exported_Functions
 * @{
*/



Error_t AddPatient(uint16_t Copy_u16Id , char* Copy_ptrName ,uint8_t Copy_u8Age ,uint8_t Copy_u8Gender );
Error_t RemovePatient(uint16_t Copy_u16Id);
void ViewPatient(uint16_t Copy_u16Id);
Error_t EditPatient(uint16_t Copy_u16OldId, PatientData_t Copy_NewPatientData);
void ReserveSlot(uint16_t id);
void CancelReservation(uint16_t id);
void ViewReservations();

/**
 * @}
*/


#ifdef __cplusplus
}
#endif

#endif /* PATIENT_RECORDS_H_ */