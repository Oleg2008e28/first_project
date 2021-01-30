#ifndef Dis12864BV20_H_
#define Dis12864BV20_H_


//#define BUILT_SPI
//#define PROGRAM_SPI
//#define PARALLEL_4_BITS
//#define PARALLEL_8_BITS

//#define F_CPU 8000000UL					//����� ������ ������� �����, � ���� ��������������� ����� ��� ����� ������� ������ main_config.h.
#include "main_config.h"					//���� � ������������ F_CPU ��� ����� �������.
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

typedef enum {COMMAND, DATA} ComDat;		//��������� ������������ ��� ������: ���� �������(COMMAND), ���� ������ (DATA).
	
/***************************************************************************************************************************************************************************************/
/*														��������� ��� ������ �� SPI, �������������� ���������.									 									   */
/***************************************************************************************************************************************************************************************/

//#define DISPLAY_CONTROL_MOD PROGRAM_SPI		//�������� ������� DISPLAY_CONTROL_MOD ���������� ����� ���������� ��������.

#define DDR_Date_line DDRC					//���������� ������ ����� � �������� ���������� ��� ����� ������.
#define PORT_Date_line PORTC	
#define Date_line	PC4

#define DDR_Clock_line DDRC					//���������� ������ ����� � �������� ���������� ��� ����� �������� ���������.
#define PORT_Clock_line PORTC
#define Clock_line	PC3

#define DDR_Device_selection_line DDRC		//���������� ������ ����� � �������� ���������� ��� ����� ������ ����������.
#define PORT_Device_selection_line PORTC
#define Device_selection_line	PC5


/***************************************************************************************************************************************************************************************/

/***************************************************************************************************************************************************************************************/
/*														��������� ��� ������ �� SPI, �������������� ���������.									 									   */
/***************************************************************************************************************************************************************************************/
//#define DISPLAY_CONTROL_MOD BUILT_SPI		//�������� ������� DISPLAY_CONTROL_MOD ���������� ����� ���������� ��������.

#define SPI_SCK			PB5
#define SPI_MISO		PB4
#define SPI_MOSI		PB3
#define SPI_CS			PB2
#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
/***************************************************************************************************************************************************************************************/
#define Reset_PORT PORTB					//���������� ������ ����� � �������� ���������� ��� ����� ������.
#define Reset_DDR DDRB
#define Reset_pin PB1

#define PROGRAM_SPI		0					//��������� ������ ������ �� ��������� SPI, �������������� ��������� (�� ��������).
#define BUILT_SPI		1					//��������� ������ ������ �� ��������� SPI, �������������� ��������� (�� ��������).
#define PARALLEL_4_BITS	2					//��������� ������ ������ �� 4-� ������� ������������� ����������. (�� ��������).
#define PARALLEL_8_BITS	3					//��������� ������ ������ �� 8-� ������� ������������� ����������. (�� ��������).


/***************************************************************************************************************************************************************************************/

/***************************************************************************************************************************************************************************************/
/*														��������� ��� ������ �� 8-�� ������� ������������� ����������.									 									   */
/***************************************************************************************************************************************************************************************/
#define DISPLAY_CONTROL_MOD PARALLEL_8_BITS
#if (DISPLAY_CONTROL_MOD==PARALLEL_8_BITS)

#define E_PIN PD6
#define E_PIN_PORT PORTD
#define E_PIN_DDR  DDRD

#define RW_PIN PD7
#define	RW_PIN_PORT PORTD
#define RW_PIN_DDR DDRD

#define RS_PIN PB0
#define RS_PIN_PORT PORTB
#define RS_PIN_DDR DDRB

#define RESET_PIN PD1
#define RESET_PIN_PORT PORTD
#define RESET_PIN_DDR  DDRD

#define DB0_PIN PD5
#define	DB0_PIN_PORT PORTD
#define DB0_PIN_DDR DDRD

#define DB1_PIN PC0
#define	DB1_PIN_PORT PORTC
#define DB1_PIN_DDR DDRC

#define DB2_PIN PC1
#define	DB2_PIN_PORT PORTC
#define DB2_PIN_DDR DDRC

#define DB3_PIN PC2
#define	DB3_PIN_PORT PORTC
#define DB3_PIN_DDR DDRC

#define DB4_PIN PC3
#define	DB4_PIN_PORT PORTC
#define DB4_PIN_DDR DDRC

#define DB5_PIN PC4
#define	DB5_PIN_PORT PORTC
#define DB5_PIN_DDR DDRC

#define DB6_PIN PC5
#define	DB6_PIN_PORT PORTC
#define DB6_PIN_DDR DDRC

#define DB7_PIN PD0
#define	DB7_PIN_PORT PORTD
#define DB7_PIN_DDR DDRD
#endif //PARALLEL_8_BITS
/***************************************************************************************************************************************************************************************/


void initDisplay();
/*��������� �������� ������ ����� ������. ��������� ������������ ��� ������� ��� ������ ������� ��� �������������.*/
void initDisplayPinProgramSpi();
void initDisplayBuiltSpiMod();
void initDisplayParallel4bitMod();
void initDisplayParallel8bitMod();
/*������� ������� ����������� ��� ������ ������ � �������� � ��� �� ��� ��������� ������. ���������� �������  � �������� ���������.*/
void resetDisplay();
/*������� ������������� ��� ������� ������� ��� ������ � ����������� ������.*/
void clearDisplayGraphicMode(void);
/*������ ������� ������������� ������ �� ������������ ����� ����������� ������� ���� ������ � ����������� ������*/
void setDisplayGraphicRamAddress(uint8_t Vertical_address, uint8_t Horizontal_address);
/*������� transferDisplayByte(uint8_t a, uint8_t rs) �������� ���� ���� ������ ��� ������ �� ������� �� ���������� SPI.
� �������� ������� ���������, uint8_t a, ���������� ���� ��� ��������. 
� ������� ������� ���������, rs, ���������� ���������, ������������ ���������� ����������� ����� (COMMAND-�������, DATA-������).*/
void transferDisplayByte(uint8_t a, ComDat rs);
/*������ ������� ������������� �� ������� ���� �� ������� ����� � ��������� ������� �� ������� ������. 
��� ���� �� ����������� ��������� ������� ��������������� �������. � �������� ������� ��������� ������������ 
��������� �� ������ ��������, ������� ������ ���������� �������� '\0'-����� ������. ������ �������� ��������� 
����� ������ � ������� ��������� ��������� ������ (0-�������, 1-������ ������, 2-�������������, 3-������). 
������ �������� ������ �������� �������� (0-��� ��������, 1-�������� ��������).*/
void printDisplayString(unsigned char *s, uint8_t number_string, uint8_t invers);
/*������ ������� ��������� ������� �� ���������� ������ � ����������� � �������, ��� �� �������� � ��������� ������� � ����������� ������ ���������� 8-�� ��� 4-� ������*/
void setDisplayExtendedFunction(uint8_t bit_interface_control, uint8_t  extended_instruction_set_control_bit, uint8_t Graphic_Display_bit);


void setDisplayDdramAddress(uint8_t  DDRAM_address);
void setDispleyCgramAddress(uint8_t CGRAM_Address );
void setDisplayScrollAddress(uint8_t address_of_vertical_scroll);
void reverseDisplay(uint8_t R1, uint8_t R0);
void selectDisplayScroollOrRamAddress(uint8_t SR);

void enableDisplayStandby();
void controlDisplay(uint8_t Display_ON_OFF_control_bit, uint8_t Cursor_ON_OFF_control_bit, uint8_t Character_Blink_ON_OFF_control_bit);




#endif /* Dis12864BV20_H_ */

