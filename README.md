# Full_Calculator
An ATMega32 Based Project where it is used for implementing a  calculator similar to the commercial ones while having multiple other features. 
Description:
This is a simple calculator program that perform  mathematical operations.
 Features:
 1. Signed Numbers: It can deal with signed numbers as inputs or outputs.
 2. Floating Point Results: Although this calculator don't have '.' button, it can perform floating point operations and show a decimal result.
 3. Division By Zero: It can detect "Division By Zero" and thus, shows an error message.
 4. Entering a Number after Result: On entering a number after result is displayed, the calculator will automatically reset and display this number as the beginning of an operand of an new operation.
 5. Entering an Operator after Result: On entering an operator after result is displayed, the calculator will automatically reset showing the result as an operand of the new operation and the operator that was entered.
 6. Operator Replacement: On entering two consecutive operators the second will replace the first unless it was meant as sign operator.
 7. Multiple Operations: Multiple operations can be performed at a time according to their insertion order.
 8. Display Shifting: On entering while screen is full display will be shifted to show the new entries and will be shifted back on displaying the result.
 9. Configurable Properties: The maximum operations per entry and the maximum digits per entry can be performed per entry can be adjusted within the code #-directives.
 10.Operations Precedence: The order of the opertions performed is  affected by their precedence.
