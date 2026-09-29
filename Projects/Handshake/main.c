#include <stdio.h>
#include "FreeRTOS.h"
#include "bsp.h"
#include "task.h"


TaskHandle_t    xTask1_handle; /* Handle for task 1. */
TaskHandle_t    xTask2_handle; /* Handle for task 2. */


/* Shared global variable */
uint32_t x = 0;


void vTask1(void *args) { /* Periodic Task */
    TickType_t xLastWakeTime = 0;
    const TickType_t xPeriod = (int)args;   /* Get period (in ticks) from argument. */
    
    BSP_SetLED(LED_RED, false); /* Turn on the red LED. */

    for (;;) {
        BSP_ToggleLED(LED_RED);
        vTaskDelayUntil(&xLastWakeTime, xPeriod);   /* Wait for the next release. */
    }
}
/*-----------------------------------------------------------*/

void vTask2(void *args) { /* Periodic Task */
    
    const TickType_t xPeriod = (int)args;   /* Get period (in ticks) from argument. */
    BSP_SetLED(LED_GREEN, true); /* Turn on the green LED. */
    vTaskDelay(2000); 
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;) {
        BSP_ToggleLED(LED_GREEN);
        vTaskDelayUntil(&xLastWakeTime, xPeriod);   /* Wait for the next release. */        
    }
}

/*-----------------------------------------------------------*/
int main()
{
    BSP_Init();             /* Initialize all components on the lab-kit. */
    
    /* Create the tasks. */
    xTaskCreate(vTask1, "Task 1", 512, (void*) 4000, 1, &xTask1_handle);
    xTaskCreate(vTask2, "Task 2", 512, (void*) 4000, 2, &xTask2_handle);    

    vTaskStartScheduler();  /* Start the scheduler. */
    
    return 0; /* Should not reach here... */
}
/*-----------------------------------------------------------*/
