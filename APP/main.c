/*
 * main.c
 *
 *  Created on: Dec 17, 2021
 *      Author: Mahmoud Khaled
 */

/*
 * Description:
 *   This is a simple calculator program that perform  mathematical operations.
 *
 * Features:
 *   1. Signed Numbers: It can deal with signed numbers as inputs or outputs.
 *   2. Floating Point Results: Although this calculator don't have '.'
 *      button, it can perform floating point operations and show a decimal
 *      result.
 *   3. Division By Zero: It can detect "Division By Zero" and thus, shows
 *      an error message.
 *   4. Entering a Number after Result: On entering a number after result is
 *      displayed, the calculator will automatically reset and display this
 *      number as the beginning of an operand of an new operation.
 *   5. Entering an Operator after Result: On entering an operator after
 *      result is displayed, the calculator will automatically reset showing
 *      the result as an operand of the new operation and the operator that
 *      was entered.
 *   6. Operator Replacement: On entering two consecutive operators the
 *      second will replace the first unless it was meant as sign operator.
 *   7. Multiple Operations: Multiple operations can be performed at a time
 *      according to their insertion order.
 *   8. Display Shifting: On entering while screen is full display will be
 *      shifted to show the new entries and will be shifted back on displaying
 *      the result.
 *   9. Configurable Properties: The maximum operations per entry and the
 *      maximum digits per entry can be performed per entry can be adjusted
 *      within the code #-directives.
 *   10.Operations Precedence: The order of the opertions performed is 
 *      affected by their precedence.
 */


/* Needed Libraries Inclusion */

#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/errorState.h"


#include "../HAL/Keypad/Keypad_int.h"
#include "../HAL/LCD/LCD_int.h"

#include "util/delay.h"


/* Magic Numbers Definitions */

#define 	CALC_ADD		10
#define 	CALC_SUB		20
#define 	CALC_DIV		30
#define 	CALC_MUL		40

#define		True			1
#define		False			0

#define		MAX_OPERATIONS	5		/* Maximum Number of Operations Performed Per Entry */
#define		MAX_DIGITS		20		/* Maximum Number of Digits Displayed               */
#define		LCD_WIDTH		16


u8	Calc_u8DispDigitsItr;			/* Counter For Entered Digits */

u8  Calc_u8PressedKey;

u8  Calc_u8Operation [  MAX_OPERATIONS  ];		/* Array For Entered Operations */
f32 Calc_f32Operand  [MAX_OPERATIONS + 1];		/* Array For Entered Operands   */

f64 Calc_f64Result;

u8  Calc_u8OperationIndex;
u8  Calc_u8OperandIndex  ;


u8  Calc_u8SignFlag				= False;	/* Flag For Operand Sign                                 */
u8  Calc_u8LastOperandFlag		= False;	/* Flag For Detecting Operand Entry                      */
u8  Calc_u8ResultExistFlag		= False;	/* Flag For Detecting If Result is Calculated            */
u8  Calc_u8ResultRequestFlag	= False;	/* Flag For Detecting If Result is Requested for Display */
u8  Calc_u8DivisionByZeroFlag	= False;	/* Flag For Detecting Division By Zero                   */
u8  Calc_MaxOperationFlag		= False;	/* Flag For Detecting Reaching Maximum Operation Number  */
u8  Calc_LastEnteredOperand		= False;	/* Flag For Detecting If The Last Entry is an Operand    */


void Calc_voidClear (void);
void Calc_voidShiftDisp (void);


int main(void)
{

	Keypad_enuInit();
	LCD_enuInit();

	while(1)
	{
		Keypad_enuGetPressed(&Calc_u8PressedKey);

		/* Checking if Maximum Operations Number or Maximum Screen Digits is reached */
		if(Calc_MaxOperationFlag || (Calc_u8DispDigitsItr >= MAX_DIGITS))
		{
			Calc_u8PressedKey = '=';
			Calc_MaxOperationFlag = False;
		}
		else{/* Do Nothing */}


		/* Checking for Entry after Displaying the Result */
		if (Calc_u8PressedKey != 0xFF)
		{
			if (Calc_u8ResultExistFlag)
			{
				if ((Calc_u8PressedKey == 'x') || (Calc_u8PressedKey == '/') ||
						(Calc_u8PressedKey == '+') || (Calc_u8PressedKey == '-'))
				{
					Calc_voidClear();
					Calc_f32Operand[Calc_u8OperandIndex] = Calc_f64Result;

					LCD_enuSendString("ANS");
					Calc_u8DispDigitsItr = 3;

					Calc_u8LastOperandFlag = True;
				}
				else if ((Calc_u8PressedKey >= '0') && (Calc_u8PressedKey <= '9'))
				{
					Calc_voidClear();
				}
				else { /* Do Nothing */ }
			}
			else { /* Do Nothing */ }


			/* Checking the Entered Key */
			switch (Calc_u8PressedKey)
			{
				case 'C':
					Calc_voidClear();
					break;

				case '0'...'9':			/* Operand Digits Entry */
					Calc_f32Operand[Calc_u8OperandIndex] *= 10;
					if (Calc_u8SignFlag == True)
					{
						Calc_f32Operand[Calc_u8OperandIndex] += -1 * (Calc_u8PressedKey - '0');
					}
					else
					{
						Calc_f32Operand[Calc_u8OperandIndex] +=  1 * (Calc_u8PressedKey - '0');
					}
					Calc_u8LastOperandFlag = True;

					Calc_voidShiftDisp();
					LCD_enuSendData(Calc_u8PressedKey);
					break;

				case '+':
					if (Calc_u8LastOperandFlag)
					{
						/* Checking if Maximum Operations Number is reached */
						if (Calc_u8OperationIndex == MAX_OPERATIONS)
						{
							Calc_MaxOperationFlag = True;
						}
						else
						{
							/* Resetting Sign Flag for New Operand */
							Calc_u8SignFlag = False;
							/* Inserting Operation in Operations Array */
							Calc_u8Operation[Calc_u8OperationIndex++] = CALC_ADD;
							Calc_u8OperandIndex++;

							Calc_u8LastOperandFlag = False;

							/* Displaying The Operator */
							Calc_voidShiftDisp();
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					else
					{
						Calc_u8DispDigitsItr--;

						Calc_u8Operation[Calc_u8OperationIndex - 1] = CALC_ADD;
						LCD_enuSendCommand(0x10);
						if (Calc_u8SignFlag)
						{
							LCD_enuSendCommand(0x10);
							LCD_enuSendData(Calc_u8PressedKey);
							LCD_enuSendCommand(0x14);
						}
						else
						{
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					break;

				case '-':
					if (Calc_u8LastOperandFlag)
					{
						/* Checking if Maximum Operations Number is reached */
						if (Calc_u8OperationIndex == MAX_OPERATIONS)
						{
							Calc_MaxOperationFlag = True;
						}
						else
						{
							/* Resetting Sign Flag for New Operand */
							Calc_u8SignFlag = False;
							/* Inserting Operation in Operations Array */
							Calc_u8Operation[Calc_u8OperationIndex++] = CALC_SUB;
							Calc_u8OperandIndex++;

							Calc_u8LastOperandFlag = False;

							/* Displaying The Operator */
							Calc_voidShiftDisp();
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					else if (Calc_u8SignFlag)
					{
						/* Replacing Operator on Successive Operators Entry */

						Calc_u8DispDigitsItr--;

						Calc_u8Operation[Calc_u8OperationIndex - 1] = CALC_SUB;
						LCD_enuSendCommand(0x10);
						LCD_enuSendCommand(0x10);
						LCD_enuSendData(Calc_u8PressedKey);
						LCD_enuSendCommand(0x14);
					}
					else if (!Calc_u8SignFlag)
					{
						/* Setting Sign Flag for Negative Operands */

						Calc_u8SignFlag        = True;
						Calc_u8LastOperandFlag = False;

						Calc_voidShiftDisp();
						LCD_enuSendData(Calc_u8PressedKey);
					}
					break;

				case 'x':
					if (Calc_u8LastOperandFlag)
					{
						/* Checking if Maximum Operations Number is reached */
						if (Calc_u8OperationIndex == MAX_OPERATIONS)
						{
							Calc_MaxOperationFlag = True;
						}
						else
						{
							/* Resetting Sign Flag for New Operand */
							Calc_u8SignFlag = False;
							/* Inserting Operation in Operations Array */
							Calc_u8Operation[Calc_u8OperationIndex++] = CALC_MUL;
							Calc_u8OperandIndex++;

							Calc_u8LastOperandFlag = False;

							/* Displaying The Operator */
							Calc_voidShiftDisp();
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					else	/* Replacing Operator on Successive Operators Entry */
					{
						Calc_u8DispDigitsItr--;

						Calc_u8Operation[Calc_u8OperationIndex - 1] = CALC_MUL;
						LCD_enuSendCommand(0x10);
						if (Calc_u8SignFlag)
						{
							LCD_enuSendCommand(0x10);
							LCD_enuSendData(Calc_u8PressedKey);
							LCD_enuSendCommand(0x14);
						}
						else
						{
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					break;

				case '/':
					if (Calc_u8LastOperandFlag)
					{
						/* Checking if Maximum Operations Number is reached */
						if (Calc_u8OperationIndex == MAX_OPERATIONS)
						{
							Calc_MaxOperationFlag = True;
						}
						else
						{
							/* Resetting Sign Flag for New Operand */
							Calc_u8SignFlag = False;
							/* Inserting Operation in Operations Array */
							Calc_u8Operation[Calc_u8OperationIndex++] = CALC_DIV;
							Calc_u8OperandIndex++;

							Calc_u8LastOperandFlag = False;

							/* Displaying The Operator */
							Calc_voidShiftDisp();
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					else	/* Replacing Operator on Successive Operators Entry */
					{
						Calc_u8DispDigitsItr--;

						Calc_u8Operation[Calc_u8OperationIndex - 1] = CALC_DIV;
						LCD_enuSendCommand(0x10);
						if (Calc_u8SignFlag)
						{
							LCD_enuSendCommand(0x10);
							LCD_enuSendData(Calc_u8PressedKey);
							LCD_enuSendCommand(0x14);
						}
						else
						{
							LCD_enuSendData(Calc_u8PressedKey);
						}
					}
					break;

				case '=':
					/* Performing Operations on entering '=' Sign */

					Calc_f64Result = Calc_f32Operand[0];
					u8 L_u8Iter = 0;
					for(L_u8Iter = 0; L_u8Iter < Calc_u8OperationIndex; L_u8Iter++)
					{
						switch (Calc_u8Operation[L_u8Iter])
						{
							case CALC_ADD:
								Calc_f64Result += Calc_f32Operand[L_u8Iter + 1];
								break;

							case CALC_SUB:
								Calc_f64Result -= Calc_f32Operand[L_u8Iter + 1];
								break;

							case CALC_MUL:
								Calc_f64Result *= Calc_f32Operand[L_u8Iter + 1];
								break;

							case CALC_DIV:
								if (Calc_f32Operand[L_u8Iter + 1] == 0)
								{
									Calc_u8DivisionByZeroFlag = True;
								}
								else
								{
									Calc_f64Result /= (f32)Calc_f32Operand[L_u8Iter + 1];
								}
								break;

							default:
								break;
						}
					}

					Calc_u8ResultExistFlag   = True;
					Calc_u8ResultRequestFlag = True;
					break;

					default:
						break;
			}


			/* Displayed Digits Number Increment */
			Calc_u8DispDigitsItr++;


			/* Displaying The Result */
			if (Calc_u8ResultRequestFlag)
			{
				LCD_enuSendCommand(0xC0);
				if (Calc_u8DivisionByZeroFlag)
				{
					LCD_enuSendString("Err_Div By 0");
					_delay_ms(1000);
					Calc_voidClear();
				}
				else if (!Calc_u8LastOperandFlag)
				{
					LCD_enuSendString("Err_Missing Oprd");
					_delay_ms(1000);
					Calc_voidClear();
				}
				else
				{
					if (Calc_u8DispDigitsItr >= LCD_WIDTH)
					{
						/* Shifting Back The Display to Normal */
						for( ; Calc_u8DispDigitsItr > (LCD_WIDTH + 1); Calc_u8DispDigitsItr--)
						{
							LCD_enuSendCommand(0x1C);
						}
					}
					else { /* Do Nothing */ }
					LCD_enuSendNum(Calc_f64Result);
					Calc_u8ResultRequestFlag = False;
				}
			}
		}
	}

	return 0;
}


void Calc_voidClear (void)
{
	u8 L_u8Itr = 0;

	LCD_enuSendCommand(0x01);
	LCD_enuSendCommand(0x80);

	for(L_u8Itr = 0; L_u8Itr < MAX_OPERATIONS; L_u8Itr++)
	{
		Calc_u8Operation[L_u8Itr] = 0;
	}
	for(L_u8Itr = 0; L_u8Itr <= MAX_OPERATIONS; L_u8Itr++)
	{
		Calc_f32Operand[L_u8Itr] = 0;
	}

	Calc_u8OperationIndex = 0;
	Calc_u8OperandIndex   = 0;

	Calc_u8SignFlag				= False;
	Calc_u8LastOperandFlag		= False;
	Calc_u8ResultExistFlag		= False;
	Calc_u8ResultRequestFlag	= False;
	Calc_u8DivisionByZeroFlag	= False;
	Calc_MaxOperationFlag		= False;
	Calc_LastEnteredOperand		= False;

	Calc_u8DispDigitsItr = 0;
}


void Calc_voidShiftDisp (void)
{
	if (Calc_u8DispDigitsItr >= LCD_WIDTH)
	{
		LCD_enuSendCommand(0x18);
	}
	else{ /* Do Nothing */ }
}

