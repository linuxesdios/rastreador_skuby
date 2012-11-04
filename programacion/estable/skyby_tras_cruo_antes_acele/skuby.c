#include        <p18f4550.h>
#include	"PragmaConfig.h"
#include        <stdio.h>
#include	"VarGlobales.h"
#include 	"defines.h"
#include 	"vectores.h"
#include 	<delays.h>
#include 	<timers.h>
#include 	<pwm.h>
#include 	"PID.h"
#include 	"Inicializaciones.h"
#include         "usart.h"
#include        <stdlib.h>
#include        <math.h>
#include 	"modos.h"
#include 	"eeprom.h"
#include 	"envio.h"
#include 	"temporizaciones.h"
#include 	"aplicaciones.h"

// Rutina de Interrupcion de ALTA prioridad
#pragma interrupt HiInterrupcion

void HiInterrupcion(void)
{
    if(INTCONbits.T0IF == 1)	// Comprobamos si ha saltado el TMR0
    {
        Set_T0_2_5ms_20MHZ();
        switch(ejecucion)
            {
                case lectura_centrada:	// No hay bifurcacion
                      calcular_error_absoluto_porcentaje();
                      eject_porc                  //ejecuto el PDLIMPIAR_LED
                      borrar_led
                      LED_ROJO=1;
                      break;
                 case lectura_transicion:	// No hay bifurcacion
                      break;
                 case lectura_derecha:	
                      borrar_led
                      LED_VERDE=1;
                      calc_dire_der
                      eject_lateral                 //ejecuto el PD
                      break;
                 case lectura_izquierda:	// No hay bifurcacion
                      calc_dire_izq
                      borrar_led
                      LED_AZUL=1;
                      eject_lateral
		      break;
                 case lectura_recto:	// No hay bifurcacion
                      borrar_led
                      LED_VERDE=1;
                      LED_AZUL=1;
                        calc_dire_inv
                        eject_recto
                      break;
                 case atras_condicional:	// No hay bifurcacion
                        tfuera=0;
                        if ((tfuera<msdefrenada)&&((direAnt==2)||(direAnt==18)))
                        {
                            ponMotores(-200,-200);
                            tfuera++;
                            LED_ROJO=LED_VERDE=LED_NARANJA=LED_AZUL=1;

                        }
                        else
                            eject_porc
                      break;


             }
        }
}
//This return will be a "retfie fast", since this is in a #pragma interrupt section



// Rutina de Interrupcion de BAJA prioridad
#pragma interrupt LoInterrupcion
void LoInterrupcion(void)
{
        if(PIR1bits.TMR1IF == 1)
	{
          PIR1bits.TMR1IF = 0;
//          conta_1++;
        }       
}
// Creamos una nueva seccion de codigo a partir de la direccion 0x18.-
// Son las interrupciones de BAJA prioridad
#pragma code InterrupcionLow = 0X0018
void VectorInterrupcionLow(void)
{
	 _asm goto LoInterrupcion _endasm
}
// Creamos una nueva seccion de codigo a partir de la direccion 0x08.-
// Son las interrupciones de ALTA prioridad
#pragma code Interrupcion = 0X0008
void VectorInterrupcion(void)
{
	 _asm goto HiInterrupcion _endasm
}	//This return will be a "retfie", since this is in a #pragma interruptlow section

#pragma code // Cerramos seccion.-

void main(void)
{
Inicializar_PIC();
Init_Inter();
Inicializar_PWM();
Init_T0();
Init_T1();
INIT_T3();
while(1)
{
LED_VERDE=1;
}
botones();
Delay_3s();
while(1)
 {
    INTCONbits.T0IE = 0;
    numero_lineas=comprobacion_lectura();
    INTCONbits.T0IE = 1;

   if (giro==sin_giro)
        {
        if (numero_lineas==0)//posicion estoy fuera  de la linea
            {
                calc_dire;
                ejecucion=atras_condicional;
                giro=sin_giro;

            }
         if (numero_lineas==1)
            {
              calc_dire;
              cambiar_sensor_ant_por_sensor();
              ejecucion=lectura_centrada;
              giro=sin_giro;

            }
         if (numero_lineas==2)
            {
             detectado_lado=0;
             while (comprobacion_lectura()==2)
                {
                 if (detectado_lado==0)
                  {
                    aux_comprobar_lado=0;
                    aux_comprobar_lado=comprobar_lado();
                    detectado_lado=1;
                    if (aux_comprobar_lado==1)
                          giro=derecho;
                    else if(aux_comprobar_lado==2)
                          giro=izquierdo;
                  }
               if (detectado_lado==1)
                  {
                    direAnt=dire;
                    if (giro==izquierdo) ejecucion=lectura_derecha;
                    if(giro==derecho) ejecucion=lectura_izquierda;
                  }
                }
            }
            if (numero_lineas==3)
            {
                while (comprobacion_lectura()!=1)
                {
                   giro=recto;
                   ejecucion=lectura_recto;
                }
            }
        }//sin_giro
   else if (giro!=sin_giro)
        {
            salido=0,var_A7=0,var_A0=0;
//            ini_t1_cuenta_atras //inicializo el contador para salir por tiempo
            while (salido==0 )
            {
                leer_sensores_vector();
                if(S9==N)
                    var_A7=1;
                if(S0==N)
                    var_A0=1;

                if(giro==derecho)
                {
                    ejecucion=lectura_derecha;

                    if((S9 == B) &&(var_A7==1))
                    salido=1;
                }
                if(giro==izquierdo)
                {
                    ejecucion=lectura_izquierda;

                    if((S0 == B) && (var_A0==1))
                    salido=1;
                }
                if (giro==recto)
                {
                    ejecucion=lectura_recto;
                   
                    if((S9 ==B) && (S0 ==B) && (var_A7==1) && (var_A0==1))
                    salido=1;
                }
//                if (conta_1==cuenta_atras)
//                {
//                   salido=1;//salgo por tiempo
//                }

            }//salido
//            parar_tm1_cuenta_atras
//            inicializar_tm1_deriva
//            while(conta_1<deriva);
            giro=sin_giro;
        }//distinto sin giro
    }//while 1

}//main

