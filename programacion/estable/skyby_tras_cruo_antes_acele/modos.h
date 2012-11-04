void lucir()
{    borrar_led
    if(modo==0);
    if(modo==1)
        LED_ROJO=1;
    if(modo==2)
        LED_VERDE=1;
    if(modo==3)
        LED_AZUL=1;
    if(modo==4)
        LED_NARANJA=1;
}

void funcion_modo()
{
    if(modo==0)
    {
    BIAS_intento_centrado   =    35;
    KP_intento_centrado     =     4;
    KD_intento_centrado     =    120;
                                    //no tocar
    BIAS_porc               =    85;//no tocar
    KP_porc                 =    21;//no tocar
    KD_porc                 =   200;//no tocar
    porcentaje              =   0.2;//no tocar
//no tocar
    BIAS_lateral            =    45;//no tocar
    KP_lateral              =    21;//no tocar
    KD_lateral              =   200;//no tocar

    BIAS_recto             =    70;//no tocar
    KP_recto               =     9;//no tocar
    KD_recto               =   100;//no tocar

    msdefrenada             =    25;//no tocar
    tiempo_retardo          =    2;//no tocar
    }

    if(modo==1)
    {
        BIAS_intento_centrado   =    35;
    KP_intento_centrado     =     4;
    KD_intento_centrado     =    120;

    BIAS_porc               =    90;
    KP_porc                 =    23;
    KD_porc                 =   210;
    porcentaje              =   0.3;

    BIAS_lateral            =    57;
    KP_lateral              =    27;
    KD_lateral              =   210;

    BIAS_recto             =    70;
    KP_recto               =     9;
    KD_recto               =   100;

    msdefrenada             =    25;
    tiempo_retardo          =    2;
    }
    if(modo==2)
    {
    BIAS_intento_centrado   =    35;
    KP_intento_centrado     =     4;
    KD_intento_centrado     =    120;

    BIAS_porc               =   120;
    KP_porc                 =    24;
    KD_porc                 =   210;
    porcentaje              =   0.4;

    BIAS_lateral            =    63;
    KP_lateral              =    24;
    KD_lateral              =   210;

    BIAS_recto             =    80;
    KP_recto               =    17;
    KD_recto               =   170;

    msdefrenada             =    25;
    tiempo_retardo          =    2;
    }
    if(modo==3)
    {
BIAS_intento_centrado   =    35;
    KP_intento_centrado     =     4;
    KD_intento_centrado     =    120;

    BIAS_porc               =   130;
    KP_porc                 =    23;
    KD_porc                 =   230;
    porcentaje              =   0.2;

    BIAS_recto            =    60;
    KP_recto              =    19;
    KD_recto              =   230;

    BIAS_recto             =    70;
    KP_recto               =     9;
    KD_recto               =   100;

    msdefrenada             =    20;
    tiempo_retardo          =    2;
                }
    if(modo==4)
    {
BIAS_intento_centrado   =    35;
    KP_intento_centrado     =     4;
    KD_intento_centrado     =    120;

    BIAS_porc               =   120;
    KP_porc                 =    23;
    KD_porc                 =   230;
    porcentaje              =   0.2;

    BIAS_recto            =    60;
    KP_recto              =    19;
    KD_recto              =   230;

    BIAS_recto             =    70;
    KP_recto               =     9;
    KD_recto               =   100;

    msdefrenada             =    20;
    tiempo_retardo          =    2;
                }

                LED_AZUL=1;
                LED_VERDE=1;
                LED_ROJO=1;
                LED_NARANJA=1;
                Delay10KTCYx(250);
                borrar_led
                lucir();


 }
void botones()
{
    while(BOTON_NARANJA==libre)
    {

             if (BOTON_NEGRO==pulsado)
             {
                 modo++;
                 if (modo==5)
                     modo=0;
                 lucir();
                 while(BOTON_NEGRO==pulsado);
                 temporizacion_boton

             }
            if (BOTON_BLANCO==pulsado)
             {
                while(BOTON_BLANCO==pulsado);
                temporizacion_boton
                funcion_modo();
             }
    }
    correr
}
