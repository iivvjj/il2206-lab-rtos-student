#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "bsp.h"


TaskHandle_t    xTask1_handle; /* Handle for task 1. */
TaskHandle_t    xTask2_handle; /* Handle for task 2. */
SemaphoreHandle_t xMutex;

/* Shared global variable */
int32_t x = 1;

void vTaskA(void *args) { /* Periodic Task */
    TickType_t xLastWakeTime = 0;
    const TickType_t xPeriod = (int)args;   /* Get period (in ticks) from argument. */
    

    for (;;) {
        
        xSemaphoreTake(xMutex, ( TickType_t ) portMAX_DELAY);
        if (x > 0){
            printf("Sending:  %d\n", x);
        }
        else {
            printf("Receiving:  %d\n", x);
            x = (x * -1) + 1;
            printf("Sending:  %d\n", x);
        }
        
        xSemaphoreGive(xMutex);

        vTaskDelayUntil(&xLastWakeTime, xPeriod);   /* Wait for the next release. */
    }
}
/*-----------------------------------------------------------*/

void vTaskB(void *args) { /* Periodic Task */
    TickType_t xLastWakeTime = 0;
    const TickType_t xPeriod = (int)args;   /* Get period (in ticks) from argument. */
    
    for (;;) {
        xSemaphoreTake(xMutex, ( TickType_t ) portMAX_DELAY);
        x *= -1;
        xSemaphoreGive(xMutex);

        vTaskDelayUntil(&xLastWakeTime, xPeriod);   /* Wait for the next release. */        
    }
}

/*-----------------------------------------------------------*/
int main()
{
    BSP_Init();             /* Initialize all components on the lab-kit. */
    
    /* Create Semaphore */
    xMutex=xSemaphoreCreateMutex();

    /* Create the tasks. */
    xTaskCreate(vTaskA, "Task A", 512, (void*) 1000, 2, &xTask1_handle);
    xTaskCreate(vTaskB, "Task B", 512, (void*) 1000, 1, &xTask2_handle);
    


    vTaskStartScheduler();  /* Start the scheduler. */
    
    return 0; /* Should not reach here... */
}
/*-----------------------------------------------------------*/