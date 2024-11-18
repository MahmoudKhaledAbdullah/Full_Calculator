/*
 * LCD_int.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Mahmoud Khaled
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuSendString(const char * Copy_pcString);

ES_t LCD_enuSendNum(f32 Copy_f32Num);

#endif /* LCD_INT_H_ */
