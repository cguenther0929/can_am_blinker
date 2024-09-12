/*
 * uart.c
 *
 *  Created on: May 12, 2023
 *      Author: clint
 */
#include "uart.h"

// struct UARTMembers ut;
// fuse         fus;               // Struct for all things fuse related
// timing       tim;               // Struct for all things timing related

extern uart_type        ut;
extern timing_type      tim;

void print_float (float number, uint8_t action) {
    char temp_buffer[8];        //Define the array that will hold the ASCII values
    char c = '\0';

    /* USE SPRINT F TO BUILD THE ARRAY OF ASCII CHARACTERS */
    sprintf(temp_buffer, "%.4f", number);   //f tells the function we want to print a float value

    HAL_UART_Transmit(&huart1, (uint8_t *) temp_buffer, sizeof(temp_buffer), HAL_MAX_DELAY);

    /* CHECK TO SEE IF THE USER WISHES TO CREATE A NEW LINE */
    if(action == LF) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
        c = '\n';  HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
    else if(action == CR) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
}

void print_8b_binary_rep (uint8_t number, uint8_t action) {
    uint16_t i;
    uint8_t tx_char;
    char c = '\0';

    for(i = 8; i > 0; i--) {
        tx_char = (uint16_t)(number >> (i - 1));
        tx_char = (uint16_t)(tx_char & 0x01);
        tx_char = (uint16_t)(tx_char + 0x30);         //Turn this into an ASCII value
        c = (char)tx_char;

        HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }

    /* CHECK TO SEE IF THE USER WISHES TO CREATE A NEW LINE */
    if(action == LF) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
        c = '\n';  HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
    else if(action == CR) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
}

void print_16b_binary_rep (uint16_t number, uint8_t action) {
    uint16_t i;
    uint16_t tx_char;
    char c = '\0';

    for(i = 16; i > 0; i--) {
        tx_char = (uint16_t)(number >> (i - 1));
        tx_char = (uint16_t)(tx_char & 0x01);
        tx_char = (uint16_t)(tx_char + 0x30);         //Turn this into an ASCII value
        c = (char)tx_char;

        HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }

    /* CHECK TO SEE IF THE USER WISHES TO CREATE A NEW LINE */
    if(action == LF) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
        c = '\n';  HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
    else if(action == CR) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
}

void print_string(const char * s, uint8_t action) {
    char c = '\0';

    while(*s != '\0') {
        HAL_UART_Transmit(&huart1, (uint8_t *) s, (uint16_t) 0x01, HAL_MAX_DELAY);
        s++;
    }

    /* CHECK TO SEE IF THE USER WISHES TO CREATE A NEW LINE */
    if(action == LF) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
        c = '\n';  HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
    else if(action == CR) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }

}

void print_unsigned_decimal (uint16_t number, uint8_t action) {
    char temphex[5];        //Define the array that will hold the ASCII values
    char c = '\r';
    uint8_t i;                
    uint8_t decimal_count;    //This is how many digits are written

    /* USE SPRINT F TO BUILD THE ARRAY OF ASCII CHARACTERS */
    decimal_count = (uint8_t)(sprintf(temphex, "%u", number)); //u tells the function we want an unsigned decimal number

    for(i = 0; i < decimal_count; i++) {    //Print out the array of ASCII characters.
        // TXREG1 = (temphex[i]);
        HAL_UART_Transmit(&huart1,(uint8_t *) &temphex[i], (uint16_t) 0x01, HAL_MAX_DELAY);
    }

    /* CHECK TO SEE IF THE USER WISHES TO CREATE A NEW LINE */
    if(action == LF) {
        HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
        c = '\n';  HAL_UART_Transmit(&huart1, (uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
    else if(action == CR) {
        c = '\r';  HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
}

void ClearCursorUp( void ) {
    char c = 0x1B;
    HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    print_string("[1J",0);        //Send the rest of the sequence to clear the screen

}

void ClearScreen( void ) {
    char c = 0x1B;
    HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    print_string("[2J",0);        //Send the rest of the sequence to clear the screen
}

void ClearLine( void ) {
    char c = 0x1B;
    HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    print_string("[2K",0);        //Send the rest of the sequence to clear the screen

}

void CursorTopLeft( void ) {
    char c = 0x1B;
    HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    print_string("[H",0);     //Send the rest of the sequence to clear the screen
}

void ResetTerminal( void ) {
    char c = 0x1B;
    HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    print_string("c",0);      //Send the rest of the sequence to clear the screen
}

void InsertLineFeed( uint8_t line_feeds ) {
    uint8_t i = 0;         //Use this as a counter
    char c = '\r';
    
    for(i = 0; i < line_feeds; i++){
        HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
        c = '\n'; //TODO: do we need this line?
        HAL_UART_Transmit(&huart1,(uint8_t *) &c, (uint16_t) 0x01, HAL_MAX_DELAY);
    }
}

void InsertLineSeparator( void ) {
    print_string("---------------------------------------", LF);
}

void ResetRxBuffer(uart_type * ut) {

    ut->consumer_index = ut->producer_index = 0;                              //Reset the pointers
    ut->byte_counter = 0;                                            //Reset the data counter
    memset(ut->rxbuf,'\0',MAX_ELEMENTS);                           //Null out the buffer
} /* End of ResetRxBuffer */

void HandleByte(uart_type * ut) {     

    
    
    switch(ut->msg_state) {
        case(STATESTART):                                   //Have yet to receive a valid SOF
            ut->len_verify = 0;                            //Good place to reset the length verify counter
            if(ut->rxbuf[ut->consumer_index] == RXSOF) {
                ut->msg_state = SOFRXED;                   //Advance state if we receive SOF
                IncrementConsumer(ut);
            }
            else if(ut->rxbuf[ut -> consumer_index] == 'z') {     //User wishes to run calibration routine
                ut->inmenu = true;                      //Set this flag so that we don't mess up the rxbuffer
                ResetRxBuffer(ut);                            //Reset this because messaging handling didn't occur while calibrating
                MainMenu(ut);                         //Run the calibration routine
                ut->inmenu = false;                     //Clear this now that the sensors have been calibrated
            }
            else {
                IncrementConsumer(ut);                        //Not a valid byte, keep looking
            }
        break;

        // case(SOFRXED):                                   //Now we should be looking at the ID value
        //     ut->msg_id = ut->rxbuf[ut->consumer_index];
        //     IncrementConsumer(); 
        //     /* Check that a valid ID byte was received */         
        //     if(ut->msg_id > 0x00 && ut->msg_id <= 0x06) {
        //         ut->msg_state = IDRXED;                        //We have received a valid message ID
        //     }
        //     else{
        //         ut->msg_state = STATESTART;                    //Garbage, so start looking for SOF
        //     }
        // break;

        // case(IDRXED):                                    //Now we should be looking at the length value
        //     ut->msg_len = ut->rxbuf[ut->consumer_index];
        //     IncrementConsumer();
        //     if(ut->msg_len <= 0x05) {                  //Put some restriction on this so we know data is valid
        //         ut->msg_state = LENRXED;                        //We have received a valid message ID
        //     }
        //     else {
        //         ut->msg_state = STATESTART;                //Garbage, so start looking for SOF.
        //     }
        // break;

        // case(LENRXED):                                       //Now we can collect the data
        //     if((ut->rxbuf[ut->consumer_index] != FRAMEEND) && ut->len_verify == 0) {          //Still collecting data
        //         ut->data_index = ut->consumer_index;            //Define where data starts in queue
        //     }
            
        //     else if((ut->rxbuf[ut->consumer_index] == FRAMEEND) && (ut->len_verify == ut->msg_len)){   //We have reached the EOF framing byte
        //         ut->data_end = ut->consumer_index-1;              //Define where data ends in queue
        //         ut->msg_state = STATESTART;                //Begin looking for SOF
        //         ut->validmsg = true;                       //Valid message confirmed
        //     }
        //     else if((ut->rxbuf[ut->consumer_index] != FRAMEEND) && (ut->len_verify >= ut->msg_len)) {
        //         ut->msg_state = STATESTART;
        //     }

        //     ut->len_verify++;                           //Used to validate the length byte received
        //     IncrementConsumer();                        //Move pointer
        // break;
    }
} /* End of HandleByte */

void IncrementConsumer(uart_type * ut) {
    ut->consumer_index >= MAX_RX_BUF_INDEX ? (ut->consumer_index = 0):(ut->consumer_index++);                        // Either roll over or increment the "consumer" pointer
    (ut->byte_counter <= 1) ? (ut->byte_counter = 0):(ut->byte_counter--);                                           //Decrement data counter
} /* End of IncrementConsumer */




uint8_t getNumber_u8 (uart_type * ut ) {
    int number      = 0;
    uint8_t timeout     = 0;

    ResetRxBuffer(ut);
    
    ut->rxchar = '\0';
    while(ut->rxchar == '\0'){}                   // Wait for keyboard input 
    
    while (timeout < 20) {
        if(ut->rxchar == ENTER_KEY) break;

        HAL_Delay(100);          // Delay in ms 
        timeout++;
    }

    sscanf(ut->rxbuf,"%d",&number);

    print_string("Number Received: ",0);
    print_unsigned_decimal((uint8_t)number, LF);

    ResetRxBuffer(ut);
    return(number);
}

float getNumber_float(uart_type * ut) {
    float number        = 0;
    uint8_t timeout     = 0;
    
    ResetRxBuffer(ut);
    
    ut->rxchar = '\0';
    while(ut->rxchar == '\0'){}                   // Wait for keyboard input 
    
    while (timeout < 80) {
        
        if(ut->rxchar == ENTER_KEY) break;

        HAL_Delay(100);          // Delay in ms
        timeout++;
    }

    sscanf(ut->rxbuf,"%f.3",&number);
    
    ResetRxBuffer(ut);

    return(number);

}




void MainMenu(uart_type * ut) {
    /*
     * This routine will be using the same buffer as what's 
     * used for the main application.  ResetRxBuffer() is called
     * in main.c just prior to entering this routine. 
     * 
     * 
     */

	uint8_t     usr_number_u8           = 0;        // Number user has entered will be stored here
    float       temp_float              = 0.0;
    
    ut->rxchar = '\0';                  
    ResetTerminal();                            // Clear all the contents on the terminal

    
    HAL_Delay(1);
    CursorTopLeft();
    HAL_Delay(1);

    while(usr_number_u8 != 99) {
        InsertLineFeed(1);
        InsertLineSeparator();
        print_string("1 --- Not implemented1...",LF);
        print_string("2 --- Not implemented2...",LF);
        print_string("3 --- Print SW version.",LF);
        
        InsertLineFeed(1);
        
        print_string("8 --- Get SW version information.",LF);
        
        print_string("99 -- Exit menu.",LF);  
        
        InsertLineFeed(2);
        
        print_string("Enter Selection:  ",0);
        usr_number_u8 = getNumber_u8(ut);

       
        switch(usr_number_u8) {
            /* Note implemented 1 */
            case 1:
                InsertLineFeed(1);
                InsertLineSeparator();
                print_string("Need to implement something here...",0);
                temp_float = getNumber_float(ut);
                InsertLineFeed(1);
                print_string("Now I'm leaving...",0);
                print_float(temp_float,LF);

            	// dac_data_value = get_dac_data_value (temp_float);
                // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)dac_data_value);
            break;
            
            /* Note implemented 2 */
            case 2:
                InsertLineFeed(1);
                InsertLineSeparator();
                print_string("Need to implement something here...",0);

            	// dac_data_value = get_dac_data_value (temp_float);
                
                // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)dac_data_value);
            	
            break;

            /* Print SW version */
            case 3:
                InsertLineFeed(1);
                InsertLineSeparator();
                
                print_string("SW Version:",0);
                print_string(SW_VER_STR,LF);

            break;

            /* Leave menu */
            case 99:
                ResetTerminal();              //Leaving menu, so clear the screen so not to confuse user
                HAL_Delay(1);
                CursorTopLeft();        //Make sure the cursor is in the Top Left position
                HAL_Delay(1);
                usr_number_u8 = 99;
            break;

            default:
                usr_number_u8 = 0;
        }   //END Switch(usr_number_u8)
    }  //END while(usr_number_u8 != 99)

    print_string("Leaving console.",LF);

}

