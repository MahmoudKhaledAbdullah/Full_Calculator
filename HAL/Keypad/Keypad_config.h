/*
 * Keypad_config.h
 *
 *  Created on: Dec 13, 2021
 *      Author: Mahmoud Khaled
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define COL_NUM				4
#define ROW_NUM				4

#define R1_GROUP			DIO_u8GROUP_B
#define R1_PIN              DIO_u8PIN4

#define R2_GROUP            DIO_u8GROUP_B
#define R2_PIN              DIO_u8PIN5

#define R3_GROUP            DIO_u8GROUP_B
#define R3_PIN              DIO_u8PIN6

#define R4_GROUP            DIO_u8GROUP_B
#define R4_PIN              DIO_u8PIN7


#define C1_GROUP            DIO_u8GROUP_D
#define C1_PIN              DIO_u8PIN2

#define C2_GROUP            DIO_u8GROUP_D
#define C2_PIN              DIO_u8PIN3

#define C3_GROUP            DIO_u8GROUP_D
#define C3_PIN              DIO_u8PIN4

#define C4_GROUP            DIO_u8GROUP_D
#define C4_PIN              DIO_u8PIN5


#define KEYS_VALUES			{{'7','8','9','/'},\
							 {'4','5','6','x'},\
							 {'1','2','3','-'},\
							 {'C','0','=','+'}}



#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
