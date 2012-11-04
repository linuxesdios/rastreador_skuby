void Delay_3s()
{
	// Temporizacion = (65536 - Precarga)*PS*(4/fosc);
	// 		   0.05	 = (65536 - Precarga)*PS*(4/20e+6);
	//		 400000  = (65536 - Precarga)*8;
	//		  25000	 = (65536 - Precarga);
	//		Precarga = (65536 - 25000) = 40536
	//		Lo pasamos a hexadecimal y resulta mas sencillo asignar TMR1H y TMR1L;
	//		Precarga = 40536 d = 0x85ee;
	// TMR1H = 0x85;
	// TMR1L = 0xee;



	int contador = 54;//60
        borrar_led
	while(contador>0)
	{
            LED_ROJO=1;
            if (contador==18)
            LED_VERDE=1;
            if (contador==36)
            LED_AZUL=1;
            TMR1H = 0x85;//31250//7A
            TMR1L = 0xee;//12
            PIR1bits.TMR1IF = 0;

            T1CONbits.TMR1ON = 1;
                    while(!PIR1bits.TMR1IF);	// Este bucle espera a que termine la cuenta--> 50 msg
                    contador--;
            T1CONbits.TMR1ON = 0;
	}
}
void Delay_1s()
{


	int contador = 10;//10
	while(contador>0)
	{
		TMR1H = 0x85;//31250//7A
		TMR1L = 0xee;//12
		PIR1bits.TMR1IF = 0;

		T1CONbits.TMR1ON = 1;
			while(!PIR1bits.TMR1IF);	// Este bucle espera a que termine la cuenta--> 50 msg
			contador--;
		T1CONbits.TMR1ON = 0;
	}
}
void Delay_500ms()
{


	int contador = 5;//5
	while(contador>0)
	{
		TMR1H = 0x85;//31250//7A
		TMR1L = 0xee;//12
		PIR1bits.TMR1IF = 0;

		T1CONbits.TMR1ON = 1;
			while(!PIR1bits.TMR1IF);	// Este bucle espera a que termine la cuenta--> 50 msg
			contador--;
		T1CONbits.TMR1ON = 0;
	}
}

void Delay_100ms()
{

		TMR1H = 0x85;//31250//7A
		TMR1L = 0xee;//12
		PIR1bits.TMR1IF = 0;

		T1CONbits.TMR1ON = 1;
			while(!PIR1bits.TMR1IF);	// Este bucle espera a que termine la cuenta--> 50 msg
		T1CONbits.TMR1ON = 0;

}
