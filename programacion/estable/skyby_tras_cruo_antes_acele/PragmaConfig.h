/*
---------------------------------------------------------------------------------
PLL Prescaler Selection bits:

opciones diponibles

PLLDIV = 1	No prescale (4 MHz oscillator input drives PLL directly)
PLLDIV = 2 	Divide by 2 (8 MHz oscillator input)
PLLDIV = 3	Divide by 3 (12 MHz oscillator input)
PLLDIV = 4	Divide by 4 (16 MHz oscillator input)
PLLDIV = 5	Divide by 5 (20 MHz oscillator input)
PLLDIV = 6	Divide by 6 (24 MHz oscillator input)
PLLDIV = 10	Divide by 10 (40 MHz oscillator input)
PLLDIV = 12	Divide by 12 (48 MHz oscillator input)
---------------------------------------------------------------------------------
/*
 */

#pragma config PLLDIV   = 5

/*---------------------------------------------------------------------------------
CPU System Clock Postscaler:

opciones diponibles

CPUDIV = OSC1_PLL2	 [OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
CPUDIV = OSC2_PLL3	 [OSC1/OSC2 Src: /2][96 MHz PLL Src: /3]
CPUDIV = OSC3_PLL4	 [OSC1/OSC2 Src: /3][96 MHz PLL Src: /4]
CPUDIV = OSC4_PLL6	 [OSC1/OSC2 Src: /4][96 MHz PLL Src: /6]
---------------------------------------------------------------------------------
*/

        #pragma config CPUDIV   = OSC1_PLL2

/*---------------------------------------------------------------------------------
USB Clock Selection bit (used in Full Speed USB mode only; UCFG:FSEN = 1):

opciones diponibles

USBDIV = 1	 	USB clock source comes directly from the primary oscillator block with no postscale
USBDIV = 2	 	USB clock source comes from the 96 MHz PLL divided by 2
---------------------------------------------------------------------------------
*/

// NO SE USA EN ESTE EJEMPLO

/*---------------------------------------------------------------------------------
Oscillator Selection bits:

opciones diponibles

FOSC = XT_XT	 	XT oscillator, XT used by USB
FOSC = XTPLL_XT	 	XT oscillator, PLL enabled, XT used by USB
FOSC = ECIO_EC	 	External clock, port function on RA6, EC used by USB
FOSC = EC_EC	 	External clock, CLKOUT on RA6, EC used by USB
FOSC = ECPLLIO_EC	External clock, PLL enabled, port function on RA6, EC used by USB
FOSC = ECPLL_EC		External clock, PLL enabled, CLKOUT on RA6, EC used by USB
FOSC = INTOSCIO_EC	Internal oscillator, port function on RA6, EC used by USB
FOSC = INTOSC_EC	Internal oscillator, CLKOUT on RA6, EC used by USB
FOSC = INTOSC_XT	Internal oscillator, XT used by USB
FOSC = INTOSC_HS	Internal oscillator, HS used by USB
FOSC = HS		HS oscillator, HS used by USB
FOSC = HSPLL_HS		HS oscillator, PLL enabled, HS used by USB
---------------------------------------------------------------------------------
*/
#pragma config FOSC = HSPLL_HS


/*---------------------------------------------------------------------------------
Fail-Safe Clock Monitor Enable bit:

opciones diponibles

FCMEN = OFF		Fail-Safe Clock Monitor disabled
FCMEN = ON			Fail-Safe Clock Monitor enabled
---------------------------------------------------------------------------------
*/
#pragma config FCMEN = OFF // elegimos Fail-Safe Clock Monitor disabled


/*---------------------------------------------------------------------------------
Internal/External Oscillator Switchover bit:

opciones diponibles

IESO = OFF			Oscillator Switchover mode disabled
IESO = ON			Oscillator Switchover mode enabled
---------------------------------------------------------------------------------
*/
#pragma config IESO = OFF // elegimos Oscillator Switchover mode disabled


/*---------------------------------------------------------------------------------
CPU System Clock Postscaler:

opciones diponibles

CPUDIV = OSC1_PLL2	[OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
CPUDIV = OSC2_PLL3	[OSC1/OSC2 Src: /2][96 MHz PLL Src: /3]
CPUDIV = OSC3_PLL4	[OSC1/OSC2 Src: /3][96 MHz PLL Src: /4]
CPUDIV = OSC4_PLL6	[OSC1/OSC2 Src: /4][96 MHz PLL Src: /6]
---------------------------------------------------------------------------------
*/
//#pragma config CPUDIV = OSC1_PLL2 // elegimos [OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]

/*---------------------------------------------------------------------------------
Power-up Timer Enable bit:

opciones diponibles

 PWRT = ON
 PWRT enabled
 PWRT = OFF
 PWRT disabled
---------------------------------------------------------------------------------
*/
#pragma config PWRT = ON // // Power-up Timer Enable bit enable

/*---------------------------------------------------------------------------------
Brown-out Reset Enable bits:

opciones disponibles

BOR = OFF	 	Brown-out Reset disabled in hardware and software
BOR = SOFT	 	Brown-out Reset enabled and controlled by software (SBOREN is enabled)
BOR = ON_ACTIVE Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
BOR = ON		Brown-out Reset enabled in hardware only (SBOREN is disabled)
---------------------------------------------------------------------------------
*/
#pragma config BOR = OFF

/*---------------------------------------------------------------------------------
Brown-out Voltage bits:

opciones disponibles

BORV = 0    Maximum setting
BORV = 1
BORV = 2
BORV = 3	Minimum setting
---------------------------------------------------------------------------------
*/
#pragma config BORV = 0

/*---------------------------------------------------------------------------------
Watchdog Timer Enable bit:

opciones disponibles

WDT = OFF	 HW Disabled - SW Controlled
WDT = ON	 HW Enabled - SW Disabled
---------------------------------------------------------------------------------
*/
#pragma config WDT = OFF

/*---------------------------------------------------------------------------------
Watchdog Timer Postscale Select bits:

opciones disponibles

WDTPS = 1	 	1:1
WDTPS = 2	 	1:2
WDTPS = 4	 	1:4
WDTPS = 8	 	1:8
WDTPS = 16	 	1:16
WDTPS = 32	 	1:32
WDTPS = 64	 	1:64
WDTPS = 128	 	1:128
WDTPS = 256	 	1:256
WDTPS = 512	 	1:512
WDTPS = 1024 	1:1024
WDTPS = 2048 	1:2048
WDTPS = 4096	1:4096
WDTPS = 8192 	1:8192
WDTPS = 16384 	1:16384
WDTPS = 32768 	1:32768
---------------------------------------------------------------------------------
*/
#pragma config WDTPS = 32768

/*---------------------------------------------------------------------------------
MCLR Pin Enable bit:

opciones disponibles

MCLRE = OFF	 RE3 input pin enabled; MCLR disabled
MCLRE = ON		 MCLR pin enabled; RE3 input pin disabled
---------------------------------------------------------------------------------
*/
#pragma config MCLRE = OFF

/*---------------------------------------------------------------------------------
Low-Power Timer 1 Oscillator Enable bit:

opciones disponibles

LPT1OSC = OFF	 Timer1 configured for higher power operation
LPT1OSC = ON	 Timer1 configured for low-power operation

---------------------------------------------------------------------------------
*/
#pragma config LPT1OSC = OFF

/*---------------------------------------------------------------------------------

opciones disponibles

PORTB A/D Enable bit:
PBADEN = OFF		PORTB<4:0> pins are configured as digital I/O on Reset
PBADEN = ON	 		PORTB<4:0> pins are configured as analog input channels on Reset
---------------------------------------------------------------------------------
*/
#pragma config PBADEN = OFF

/*---------------------------------------------------------------------------------
CCP2 MUX bit:

opciones disponibles

 CCP2MX = OFF	 CCP2 input/output is multiplexed with RB3
 CCP2MX = ON	 CCP2 input/output is multiplexed with RC1
---------------------------------------------------------------------------------
*/
#pragma config CCP2MX = ON

/*---------------------------------------------------------------------------------
Stack Full/Underflow Reset Enable bit:

opciones disponibles

 STVREN = OFF			 Stack full/underflow will not cause Reset
 STVREN = ON			 Stack full/underflow will cause Reset
---------------------------------------------------------------------------------
*/
#pragma config STVREN = OFF

/*---------------------------------------------------------------------------------
Single-Supply ICSP Enable bit:

opciones disponibles

 LVP = OFF		 Single-Supply ICSP disabled
LVP = ON		 Single-Supply ICSP enabled
---------------------------------------------------------------------------------
*/
#pragma config LVP = OFF

/*---------------------------------------------------------------------------------
Extended Instruction Set Enable bit:

opciones disponibles

XINST = OFF	 	Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
XINST = ON		Instruction set extension and Indexed Addressing mode enabled
---------------------------------------------------------------------------------
*/
#pragma config XINST = OFF

/*---------------------------------------------------------------------------------
Background Debugger Enable bit:

opciones disponibles

 DEBUG = ON	 	Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
 DEBUG = OFF	Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
---------------------------------------------------------------------------------
*/
#pragma config DEBUG = OFF


/*---------------------------------------------------------------------------------
Code Protection bit Block 0:

opciones disponibles

CP0 = ON		Block 0 (000800-001FFFh) code-protected
CP0 = OFF	 	Block 0 (000800-001FFFh) not code-protected
---------------------------------------------------------------------------------
*/
#pragma config CP0 = OFF


/*---------------------------------------------------------------------------------
Code Protection bit Block 1:

opciones disponibles

CP1 = ON	 Block 1 (002000-003FFFh) code-protected
CP1 = OFF	 Block 1 (002000-003FFFh) not code-protected
---------------------------------------------------------------------------------
*/
#pragma config CP1 = OFF


/*---------------------------------------------------------------------------------
Code Protection bit Block 2:

opciones disponibles

CP2 = ON	Block 2 (004000-005FFFh) code-protected
CP2 = OFF	Block 2 (004000-005FFFh) not code-protected
---------------------------------------------------------------------------------
*/
#pragma config CP2 = OFF


/*---------------------------------------------------------------------------------
Code Protection bit Block 3:

opciones disponibles

CP3 = ON	Block 3 (006000-007FFFh) code-protected
CP3 = OFF	Block 3 (006000-007FFFh) not code-protected
---------------------------------------------------------------------------------
*/
#pragma config CP3 = OFF

/*---------------------------------------------------------------------------------
Boot Block Code Protection bit:

opciones disponibles

 CPB = ON	 Boot block (000000-0007FFh) code-protected
 CPB = OFF	 Boot block (000000-0007FFh) not code-protected
---------------------------------------------------------------------------------
*/
#pragma config CPB = OFF

/*---------------------------------------------------------------------------------
Data EEPROM Code Protection bit:

opciones disponibles

CPD = ON	 Data EEPROM code-protected
CPD = OFF	 Data EEPROM not code-protected
---------------------------------------------------------------------------------
*/
#pragma config CPD = OFF

/*---------------------------------------------------------------------------------
Write Protection bit Block 0:

opciones disponibles

WRT0 = ON		 Block 0 (000800-001FFFh) write-protected
WRT0 = OFF		 Block 0 (000800-001FFFh) not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRT0 = OFF

/*---------------------------------------------------------------------------------
Write Protection bit Block 1:

opciones disponibles

 WRT1 = ON	 Block 1 (002000-003FFFh) write-protected
 WRT1 = OFF	 Block 1 (002000-003FFFh) not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRT1 = OFF

/*---------------------------------------------------------------------------------
Write Protection bit Block 2:

opciones disponibles

 WRT2 = ON	 Block 2 (004000-005FFFh) write-protected
 WRT2 = OFF	 Block 2 (004000-005FFFh) not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRT2 = OFF

/*---------------------------------------------------------------------------------
Write Protection bit Block 3:

opciones disponibles

 WRT3 = ON	 Block 3 (006000-007FFFh) write-protected
 WRT3 = OFF	 Block 3 (006000-007FFFh) not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRT3 = OFF

/*---------------------------------------------------------------------------------
Boot Block Write Protection bit:

opciones disponibles

WRTB = ON	 Boot block (000000-0007FFh) write-protected
WRTB = OFF	 Boot block (000000-0007FFh) not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRTB = OFF

/*---------------------------------------------------------------------------------
 Configuration Register Write Protection bit:

opciones disponibles

WRTC = ON	 Configuration registers (300000-3000FFh) write-protected
WRTC = OFF	 Configuration registers (300000-3000FFh) not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRTC = OFF

/*---------------------------------------------------------------------------------
Data EEPROM Write Protection bit:

opciones disponibles

 WRTD = ON	 Data EEPROM write-protected
 WRTD = OFF	 Data EEPROM not write-protected
---------------------------------------------------------------------------------
*/
#pragma config WRTD = OFF


/*---------------------------------------------------------------------------------
Table Read Protection bit Block 0:

opciones disponibles

 EBTR0 = ON	 		Block 0 (000800-001FFFh) protected from table reads executed in other blocks
 EBTR0 = OFF	 	Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
---------------------------------------------------------------------------------
*/
#pragma config EBTR0 = OFF


/*---------------------------------------------------------------------------------
Table Read Protection bit Block 1:

opciones disponibles

EBTR1 = ON		Block 1 (002000-003FFFh) protected from table reads executed in other blocks
EBTR1 = OFF	 	Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
---------------------------------------------------------------------------------
*/
#pragma config EBTR1 = OFF

/*---------------------------------------------------------------------------------
Table Read Protection bit Block 2:

opciones disponibles

EBTR2 = ON		 Block 2 (004000-005FFFh) protected from table reads executed in other blocks
EBTR2 = OFF		 Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
---------------------------------------------------------------------------------
*/

#pragma config EBTR2 = OFF

/*---------------------------------------------------------------------------------
Table Read Protection bit Block 3:

opciones disponibles
EBTR3 = ON	 Block 3 (006000-007FFFh) protected from table reads executed in other blocks
EBTR3 = OFF	 Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
---------------------------------------------------------------------------------
*/
#pragma config EBTR3 = OFF

/*---------------------------------------------------------------------------------
Boot Block Table Read Protection:

opciones disponibles

EBTRB = ON		 Boot block (000000-0007FFh) protected from table reads executed in other blocks
EBTRB = OFF		 Boot block (000000-0007FFh) not protected from table reads executed in other blocks
---------------------------------------------------------------------------------
*/
#pragma config EBTRB = OFF
