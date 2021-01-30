#ifndef Dis12864BV20_H_
#define Dis12864BV20_H_


//#define BUILT_SPI
//#define PROGRAM_SPI
//#define PARALLEL_4_BITS
//#define PARALLEL_8_BITS

//#define F_CPU 8000000UL					//Можно задать частоту здесь, а мжно воспользоваться общим для всего проекта файлом main_config.h.
#include "main_config.h"					//Файл с определением F_CPU для всего проекта.
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

typedef enum {COMMAND, DATA} ComDat;		//Множество определяющее тип данных: либо каманды(COMMAND), либо данные (DATA).
	
/***************************************************************************************************************************************************************************************/
/*														Настройки для работы по SPI, реализованному програмно.									 									   */
/***************************************************************************************************************************************************************************************/

//#define DISPLAY_CONTROL_MOD PROGRAM_SPI		//Значение макроса DISPLAY_CONTROL_MOD определяет режим управления дисплеем.

#define DDR_Date_line DDRC					//Назначение вывода порта и регистра управления для линии данных.
#define PORT_Date_line PORTC	
#define Date_line	PC4

#define DDR_Clock_line DDRC					//Назначение вывода порта и регистра управления для линии тактовых импульсов.
#define PORT_Clock_line PORTC
#define Clock_line	PC3

#define DDR_Device_selection_line DDRC		//Назначение вывода порта и регистра управления для линии выбора устройства.
#define PORT_Device_selection_line PORTC
#define Device_selection_line	PC5


/***************************************************************************************************************************************************************************************/

/***************************************************************************************************************************************************************************************/
/*														Настройки для работы по SPI, реализованному аппаратно.									 									   */
/***************************************************************************************************************************************************************************************/
//#define DISPLAY_CONTROL_MOD BUILT_SPI		//Значение макроса DISPLAY_CONTROL_MOD определяет режим управления дисплеем.

#define SPI_SCK			PB5
#define SPI_MISO		PB4
#define SPI_MOSI		PB3
#define SPI_CS			PB2
#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
/***************************************************************************************************************************************************************************************/
#define Reset_PORT PORTB					//Назначение вывода порта и регистра управления для линии сброса.
#define Reset_DDR DDRB
#define Reset_pin PB1

#define PROGRAM_SPI		0					//Константа режима работы по протоколу SPI, реализованному програмно (не изменять).
#define BUILT_SPI		1					//Константа режима работы по протоколу SPI, реализованному аппаратно (не изменять).
#define PARALLEL_4_BITS	2					//Константа режима работы по 4-х битному параллельному интерфейсу. (не изменять).
#define PARALLEL_8_BITS	3					//Константа режима работы по 8-и битному параллельному интерфейсу. (не изменять).


/***************************************************************************************************************************************************************************************/

/***************************************************************************************************************************************************************************************/
/*														Настройки для работы по 8-ми битному параллельному интерфейсу.									 									   */
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
/*Установка настроек портов ввода вывода. Требуется использовать эту функцию при старте проекта для инициализации.*/
void initDisplayPinProgramSpi();
void initDisplayBuiltSpiMod();
void initDisplayParallel4bitMod();
void initDisplayParallel8bitMod();
/*Данааая функция испольуетяс при начале работы с дисплеем а так же при повторном старте. Возвращает дисплей  в исходное состояние.*/
void resetDisplay();
/*функция предназначена для очистки дисплея при работе в графическом режиме.*/
void clearDisplayGraphicMode(void);
/*Данная функция устанавливает курсор на определенный адрес видеопамяти дисплея прри работе в графическом режиме*/
void setDisplayGraphicRamAddress(uint8_t Vertical_address, uint8_t Horizontal_address);
/*Функция transferDisplayByte(uint8_t a, uint8_t rs) передает один байт команд или данных на дисплей по интерфейсу SPI.
В качестве первого параметра, uint8_t a, передается байт для передачи. 
В качетве второго параметра, rs, передается константа, определяющая назначение переданного байта (COMMAND-команда, DATA-данные).*/
void transferDisplayByte(uint8_t a, ComDat rs);
/*Данная функция распечатывает на дисплее одну из четырех строк с начальной позиции до крайней правой. 
При этом не заполненные символами позиции распечатываются пустыми. В качестве первого параметра используется 
указатель на массив символов, который Должен закончится символом '\0'-конец строки. Второй параметр указывает 
номер строки в которую требуется выполнить печать (0-верхняя, 1-вторая сверху, 2-предпоследняя, 3-нижняя). 
Третий параметр задает инверсию пикселей (0-нет инверсии, 1-инверсия пикселей).*/
void printDisplayString(unsigned char *s, uint8_t number_string, uint8_t invers);
/*Данная функция переводит дисплей из строкового режима в графический и обратно, Так же включает и отключает дисплей в графическом режиме определяет 8-ми или 4-х битный*/
void setDisplayExtendedFunction(uint8_t bit_interface_control, uint8_t  extended_instruction_set_control_bit, uint8_t Graphic_Display_bit);


void setDisplayDdramAddress(uint8_t  DDRAM_address);
void setDispleyCgramAddress(uint8_t CGRAM_Address );
void setDisplayScrollAddress(uint8_t address_of_vertical_scroll);
void reverseDisplay(uint8_t R1, uint8_t R0);
void selectDisplayScroollOrRamAddress(uint8_t SR);

void enableDisplayStandby();
void controlDisplay(uint8_t Display_ON_OFF_control_bit, uint8_t Cursor_ON_OFF_control_bit, uint8_t Character_Blink_ON_OFF_control_bit);




#endif /* Dis12864BV20_H_ */

