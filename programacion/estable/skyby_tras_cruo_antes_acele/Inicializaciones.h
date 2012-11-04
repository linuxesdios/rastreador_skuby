
// ********************************************************************************************** //
//				INICIALIZAR_PIC											//
// ********************************************************************************************** //
void Inicializar_PIC (void)
{
	//------------------//
//  Oscilador PIC	//
	UCFGbits.FSEN = 1;
	OSCCON	= 0b11101100;       // OSCCON.7 = idlen - no lo usamos
                                    // OSCCON.6-4 = Seleccion de Frecuencia de reloj interno: 111 = 8MHz
                                    // OSCCON.3-2 = solo lectura
                                    // OSCCON.1-0 = Seleccion de reloj de sistema - 11 = oscilador interno

	OSCTUNE = 0b11000000;	
//------------------//
//  Registros I/O	//
	PORTA = 0;
	PORTB = 0;
	PORTC = 0;	
	ADCON1 = 0x0F;		// Datos digitales

        UCONbits.USBEN = 0; // Deshabilitar USB para poder usar rc4 y rc5
        UCFGbits.UTRDIS=1;  // Deshabilitar USB para poder usar rc4 y rc5
	TRISA = 0b11111111;	// Todo entrada: 7 Sensores delanteros + 1 pulsador
	
	TRISB = 0b10000111;                     // RB7:	SENSOR
						// RB6: LED
						// RB5: LED
						// RB4: LED				
						// RB3: LED
						// RB2: encoder 				- '1'
						// RB1: scl				- '1'
						// RB0: sda				- '1'

	TRISC = 0b00110001;                     // RC7:	Recepcion Bluetooth
                                                // RC6:	Transmision Bluetooth		- '1'
						// RC5: boton					- '1'
						// RC4: boton 					- '0'
						// RC3: no existe					- '0'
						// RC2: PWM motor 1				- '0'
						// RC1: PWM motor 2				- '0'
						// RC0: pulsador					- '0'
         	TRISD = 0b1110000;	// RD7:NC
                                        // RD6:NC
                                        // RD5:NC
                                        // RD4:NC
                                        // RD3:MOTOR
                                        // RD2:MOTOR
                                        // RD1:MOTOR
                                        // RD0:MOTOR
                                        //
	       TRISE = 0b11111111;	//RE3:sensor
                                        //RE2:pulsador
                                        //RE1:pulsador
}                                       //RE0:sensor


// ********************************************************************************************** //
//			Inicializar_interrupciones											//
// ********************************************************************************************** //
void Init_Inter (void)
{
        INTCONbits.T0IF = 0;  //bandera de int temp 0
	INTCONbits.T0IE = 1;   //habilito int temp 0
       
        PIR1bits.TMR1IF = 0;  //bandera de int temp 1
	PIE1bits.TMR1IE = 0;   //habilito int temp 1

        INTCON3bits.INT2IF = 0;  //bandera de int externa 2
	INTCON3bits.INT2IE = 0;      //habilito int externa 2

        PIR2bits.TMR3IF = 0;  //bandera de int temp 1
	PIE2bits.TMR3IE = 1;   //habilito int temp 1

	INTCONbits.RBIF = 0;    //bandera de int portB
	INTCONbits.RBIE = 0;   //interrupciones  de portB

	INTCONbits.PEIE = 1;   //interrupciones perifericas
	INTCONbits.GIE = 1;    //interrupciones globales

        //prioridad de interrupciones
        RCONbits.IPEN = 1 ;     // permitir niveles de prioridad
        INTCONbits.GIEL = 1;   // habilitar las interrupciones de baja
        INTCONbits.GIEH = 1;   // habilitar las interrupciones de baja
        INTCON2bits.T0IP = 1;
        IPR2bits.TMR3IP = 0; //interrupcion  temporizador 3 enviada a low
        IPR1bits.TMR1IP = 0; //interrupcion  temporizador 1 enviada a low
        //INTCON3bits.INT1IP=0;


}

// ********************************************************************************************** //
//				Inicializar_PWM											//
// ********************************************************************************************** //
void Inicializar_PWM (void)
{
	T2CON=0x07;		//B00000111;
				// bit7		= 0		no implementado
				// TOUTPS3-0	= 0000	Postescala de TMR2	
				// TMR2ON	= 1		TMR2 encendido (0-> apagado)
				// T2CKPS2-0	= 01	Preescala de TMR2 (00->1; 01->4; 1x->16)
// CCP1CON
	CCP1CONbits.DC1B1 = 0;
	CCP1CONbits.DC1B0 = 0;
	CCP1CONbits.CCP1M3 = 1;
	CCP1CONbits.CCP1M2 = 1;
	CCP1CONbits.CCP1M1 = 0;
	CCP1CONbits.CCP1M0 = 0;
// CCP2CON
	CCP2CONbits.DC2B1 = 0;
	CCP2CONbits.DC2B0 = 0;
	CCP2CONbits.CCP2M3 = 1;
	CCP2CONbits.CCP2M2 = 1;
	CCP2CONbits.CCP2M1 = 0;
	CCP2CONbits.CCP2M0 = 0;
	
	PR2=249;			// PR2=249  ->  Frecuencia de PWM = 2 KHz
}

void INIT_T3(void)
{
	T3CONbits.TMR3CS = 0;	// Fuente de temporizador = frecuencia de oscilacion
	T3CONbits.T3CKPS1 = 1;	// Valor de preescala = ==> 1:8-->cada 8 ciclos cuenta 1
	T3CONbits.T3CKPS0 = 1;
}

// ********************************************************************************************** //
//				Inicializar Timer0 -> PID								//
// ********************************************************************************************** //
void Init_T0(void)
{
	// Realizaremos un bucle que cuente 1ms.
	// Temporizacion = [ (256 - TMR0)*PS + 2] *(4/fosc);
	//          1e-3 = [ (256 - TMR0)*128 + 2] *(4/48e+6);
	//          12000 = [ (256 - TMR0)*128 + 2];
	//          11998 =	 (256 - TMR0)*128;
	//	93,734375 = 256 - TMR0;
	//			TMR0 	= 256 - 62,4843 = 162,265625 	--> 162
	//											 		--> 163
	// Podemos comprobarlo:
	// Temporizacion1 = [ (256 - 162)*128 + 2] *(4/48e+6) = 0,001002833 msg
	// Temporizacion2 = [ (256 - 163)*128 + 2] *(4/48e+6) = 0,00099216 msg	--> ESTE	163 = 0xA3



	// Configuracion del modulo Timer0
	// Seleccionamos preescala:
	T0CONbits.T0CS = 0;	// Fuente de temporizador = frecuencia interna de oscilacion
	T0CONbits.PSA = 0;	// Preescala asignada a timer0
	T0CONbits.T08BIT = 1;

	T0CONbits.T0PS0 = 0;	// Valor de preescala = 1 1 0 ==> 1:128
	T0CONbits.T0PS1 = 1;
	T0CONbits.T0PS2 = 1;

	INTCONbits.T0IF = 1;	// --> Borramos el flag de fin de temporizacion
	INTCONbits.T0IE = 0;
	TMR0H = 0;
	TMR0L =177;//217
}


void Set_T0_1ms(void)
{
	INTCONbits.T0IF = 0;	// --> Borramos el flag de fin de temporizacion
	TMR0H = 0;
	TMR0L = 217;//163
	T0CONbits.TMR0ON = 1;
}

void Set_T0_1ms_20MHZ(void)
{
	// Realizaremos un bucle que cuente 1ms.
	// Temporizacion = [ (256 - TMR0)*PS + 2] *(4/fosc);
	//          1e-3 = [ (256 - TMR0)*128 + 2] *(4/48e+6);
	//          5000 = [ (256 - TMR0)*128 + 2];
	//          4998 =	 (256 - TMR0)*128;
	//		39.04687 = 256 - TMR0;
	//			TMR0 	= 256 - 39.04687 = 217 	--> 0xD9
	//											 
	// Podemos comprobarlo:
	// Temporizacion1 = [ (256 - 217)*128 + 2] *(4/20e+6) = 0,001002833 msg

	INTCONbits.T0IF = 0;	// --> Borramos el flag de fin de temporizacion
	TMR0H = 0;
	TMR0L = 217;
	T0CONbits.TMR0ON = 1;
}
void Set_T0_2_5ms_20MHZ(void)
{
	// Realizaremos un bucle que cuente 1ms.
	// Temporizacion = [ (256 - TMR0)*PS + 2] *(4/fosc);
	//          2e-3 = [ (256 - TMR0)*128 + 2] *(4/20e+6);
	//          10000 = [ (256 - TMR0)*128 + 2];
	//          9998 =	 (256 - TMR0)*128;
	//		78,109375 = 256 - TMR0;
	//			TMR0 	= 256 - 78,109375 = 178 	--> 0xD9
	//
	// Podemos comprobarlo:
	// Temporizacion1 = ( (256 - 178)*128 + 2) *(4/20e+6) = 0,001002833 msg

	INTCONbits.T0IF = 0;	// --> Borramos el flag de fin de temporizacion
	TMR0H = 0;
	TMR0L = 20;//177
	T0CONbits.TMR0ON = 1;
}
// ********************************************************************************************** //
//				Inicializar Timer0 -> PID								//
// ********************************************************************************************** //
void Init_T1 (void)
{
	T1CONbits.NOT_T1SYNC = 0;
	T1CONbits.T1RUN = 1;
        T1CONbits.T1OSCEN = 0;

        T1CONbits.TMR1CS = 0;	
        T1CONbits.T1CKPS0 = 1;//
        T1CONbits.T1CKPS1 = 1;// / multi de 16
	T1CONbits.RD16 = 1; //usando 16 o 8  bit en este caso 16 bit

}

