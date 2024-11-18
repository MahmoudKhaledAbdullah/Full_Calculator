/*
 * DIO_config.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Mahmoud Khaled
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
 /*			DIO_u8OUTPUT // DIO_u8INPUT */
#define DIO_PA0_DIR		DIO_u8OUTPUT
#define DIO_PA1_DIR		DIO_u8OUTPUT
#define DIO_PA2_DIR		DIO_u8INPUT
#define DIO_PA3_DIR
#define DIO_PA4_DIR
#define DIO_PA5_DIR
#define DIO_PA6_DIR
#define DIO_PA7_DIR

#define DIO_PB0_DIR
#define DIO_PB1_DIR
#define DIO_PB2_DIR
#define DIO_PB3_DIR
#define DIO_PB4_DIR
#define DIO_PB5_DIR
#define DIO_PB6_DIR
#define DIO_PB7_DIR


#define DIO_PC0_DIR
#define DIO_PC1_DIR
#define DIO_PC2_DIR
#define DIO_PC3_DIR
#define DIO_PC4_DIR
#define DIO_PC5_DIR
#define DIO_PC6_DIR
#define DIO_PC7_DIR


#define DIO_PD0_DIR
#define DIO_PD1_DIR
#define DIO_PD2_DIR
#define DIO_PD3_DIR
#define DIO_PD4_DIR
#define DIO_PD5_DIR
#define DIO_PD6_DIR
#define DIO_PD7_DIR


 /*			DIO_u8HIGH // DIO_u8LOW if pin is output */
 /*			DIO_u8PULL_UP // DIO_u8LOW if pin is input */
#define DIO_PA0_VAL		DIO_u8HIGH
#define DIO_PA1_VAL		DIO_u8LOW
#define DIO_PA2_VAL		DIO_u8PULL_UP
#define DIO_PA3_VAL
#define DIO_PA4_VAL
#define DIO_PA5_VAL
#define DIO_PA6_VAL
#define DIO_PA7_VAL

#define DIO_PB0_VAL
#define DIO_PB1_VAL
#define DIO_PB2_VAL
#define DIO_PB3_VAL
#define DIO_PB4_VAL
#define DIO_PB5_VAL
#define DIO_PB6_VAL
#define DIO_PB7_VAL

#define DIO_PC0_VAL
#define DIO_PC1_VAL
#define DIO_PC2_VAL
#define DIO_PC3_VAL
#define DIO_PC4_VAL
#define DIO_PC5_VAL
#define DIO_PC6_VAL
#define DIO_PC7_VAL

#define DIO_PD0_VAL
#define DIO_PD1_VAL
#define DIO_PD2_VAL
#define DIO_PD3_VAL
#define DIO_PD4_VAL
#define DIO_PD5_VAL
#define DIO_PD6_VAL
#define DIO_PD7_VAL


#endif /* DIO_CONFIG_H_ */
