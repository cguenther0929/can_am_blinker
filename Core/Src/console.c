/**
  ******************************************************************************
  * @file           : console.c
  * @brief          : Implementation of command line interface 
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Clinton Guenther
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "console.h"            //Include file to support console

extern uart_type           ut; 
extern timing_type         tim;

// uint8_t getNumber_u8 (uart_type * ut ) {
//     int number      = 0;
//     uint8_t timeout     = 0;

//     ResetRxBuffer(ut);
    
//     ut->rxchar = '\0';
//     while(ut->rxchar == '\0'){}                   // Wait for keyboard input 
    
//     while (timeout < 20) {
//         if(ut->rxchar == ENTER_KEY) break;

//         HAL_Delay(100);          // Delay in ms 
//         timeout++;
//     }

//     sscanf(ut->rxbuf,"%d",&number);

//     print_string("Number Received: ",0);
//     print_unsigned_decimal((uint8_t)number, LF);

//     ResetRxBuffer(ut);
//     return(number);
// }

// float getNumber_float(uart_type * ut) {
//     float number        = 0;
//     uint8_t timeout     = 0;
    
//     ResetRxBuffer(ut);
    
//     ut->rxchar = '\0';
//     while(ut->rxchar == '\0'){}                   // Wait for keyboard input 
    
//     while (timeout < 80) {
        
//         if(ut->rxchar == ENTER_KEY) break;

//         HAL_Delay(100);          // Delay in ms
//         timeout++;
//     }

//     sscanf(ut->rxbuf,"%f.3",&number);
    
//     ResetRxBuffer(ut);

//     return(number);

// }

// void MainMenu(uart_type * ut) {
//     /*
//      * This routine will be using the same buffer as what's 
//      * used for the main application.  ResetRxBuffer() is called
//      * in main.c just prior to entering this routine. 
//      * 
//      * 
//      */

// 	uint8_t     usr_number_u8           = 0;        // Number user has entered will be stored here
//     // uint16_t    dac_data_value          = 0;
//     // uint16_t    temp_fuse_status_u16    = 0;
//     // uint8_t     temp_u8                 = 0;
//     // bool        temp_bool               = 0;
//     float       temp_float              = 0.0;
    
//     ut->rxchar = '\0';                  
//     ResetTerminal();                            // Clear all the contents on the terminal

    
//     HAL_Delay(1);
//     CursorTopLeft();
//     HAL_Delay(1);

//     while(usr_number_u8 != 99) {
//         InsertLineFeed(1);
//         InsertLineSeparator();
//         print_string("1 --- Not implemented1...",LF);
//         print_string("2 --- Not implemented2...",LF);
//         print_string("3 --- Print SW version.",LF);
        
//         InsertLineFeed(1);
        
//         print_string("8 --- Get SW version information.",LF);
        
//         print_string("99 -- Exit menu.",LF);  
        
//         InsertLineFeed(2);
        
//         print_string("Enter Selection:  ",0);
//         usr_number_u8 = getNumber_u8(ut);

       
//         switch(usr_number_u8) {
//             /* Note implemented 1 */
//             case 1:
//                 InsertLineFeed(1);
//                 InsertLineSeparator();
//                 print_string("Need to implement something here...",0);
//                 temp_float = getNumber_float(ut);
//                 InsertLineFeed(1);
//                 print_string("Now I'm leaving...",0);
//                 print_float(temp_float,LF);

//             	// dac_data_value = get_dac_data_value (temp_float);
//                 // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)dac_data_value);
//             break;
            
//             /* Note implemented 2 */
//             case 2:
//                 InsertLineFeed(1);
//                 InsertLineSeparator();
//                 print_string("Need to implement something here...",0);

//             	// dac_data_value = get_dac_data_value (temp_float);
                
//                 // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)dac_data_value);
            	
//             break;

//             /* Print SW version */
//             case 3:
//                 InsertLineFeed(1);
//                 InsertLineSeparator();
                
//                 print_string("SW Version:",0);
//                 print_string(SW_VER_STR,LF);

//             break;

//             /* Leave menu */
//             case 99:
//                 ResetTerminal();              //Leaving menu, so clear the screen so not to confuse user
//                 HAL_Delay(1);
//                 CursorTopLeft();        //Make sure the cursor is in the Top Left position
//                 HAL_Delay(1);
//                 usr_number_u8 = 99;
//             break;

//             default:
//                 usr_number_u8 = 0;
//         }   //END Switch(usr_number_u8)
//     }  //END while(usr_number_u8 != 99)

//     print_string("Leaving console.",LF);

// }
