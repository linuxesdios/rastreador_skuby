

// ********************************************************************************************** //
//										MOTOR DERECHO											//
// ********************************************************************************************** //
void MotorDerecho(int Sentido)
{
	//MotorDerecho
	//LATCbits.LATC2 = 1;
	switch(Sentido)
	{
		case Adelante:
			MOTORDERECHO1 = 1;	//IN1_A
			MOTORDERECHO2 = 0;	//IN1_B
			break;

		case Atras:
			MOTORDERECHO1 = 0;	//IN1_A
			MOTORDERECHO2 = 1;	//IN1_B
			break;

		case Stop:
			MOTORDERECHO1 = 1;	//IN1_A
			MOTORDERECHO1 = 1;	//IN1_B
			break;
      }
}



// ********************************************************************************************** //
//										MOTOR IZQUIERDO											//
// ********************************************************************************************** //
void MotorIzquierdo(int Sentido)
{
	//MotorIzquierdo
	//LATCbits.LATC1 = 1;

	switch(Sentido)
	{
		case Adelante:
			MOTORIZQUIERDO1 = 0;	//IN1_A
			MOTORIZQUIERDO2 = 1;	//IN1_B
			break;

		case Atras:
			MOTORIZQUIERDO1 = 1;	//IN1_A
			MOTORIZQUIERDO2 = 0;	//IN1_B
			break;

		case Stop:
			MOTORIZQUIERDO1 = 1;	//IN1_A
			MOTORIZQUIERDO2 = 1;	//IN1_B
			break;
	}
}


//-------------------------------------------------------
//---------          FUNCIONES DE PID        ------------
//-------------------------------------------------------
int PrimD(void)
{
   if(S0 == N) return 1;//negro es 0
   if(S1 == N) return 2;
   if(S2 == N) return 3;
   if(S3 == N) return 4;
   if(S4 == N) return 5;
   if(S5 == N) return 6;
   if(S6 == N) return 7;
   if(S7 == N) return 8;
   if(S8 == N) return 9;
   if(S9 == N) return 10;
   return 0;
}


int PrimI(void)
{
   if(S9 == N) return 10;
   if(S8 == N) return 9;
   if(S7 == N) return 8;
   if(S6 == N) return 7;
   if(S5 == N) return 6;
   if(S4 == N) return 5;
   if(S3 == N) return 4;
   if(S2 == N) return 3;
   if(S1 == N) return 2;
   if(S0 == N) return 1;
   return 0;
}
int PrimD_inv(void)
{
   if(S4 == N) return 5;//negro es 0
   if(S3 == N) return 4;
   if(S2 == N) return 3;
   if(S1 == N) return 2;
   if(S0 == N) return 1;
   if(S5 == N) return 6;
   if(S6 == N) return 7;
   if(S7 == N) return 8;
   if(S8 == N) return 9;
   if(S9 == N) return 10;
   return 0;
}


int PrimI_inv(void)
{
   if(S5 == N) return 6;
   if(S6 == N) return 7;
   if(S7 == N) return 8;
   if(S8 == N) return 9;
   if(S9 == N) return 10;
   if(S4 == N) return 5;
   if(S3 == N) return 4;
   if(S2 == N) return 3;
   if(S1 == N) return 2;
   if(S0 == N) return 1;
   return 0;
}
signed int control_recto(signed int lectura)
{
   signed int errorLeido =0;
   signed int resultado=0;
   errorLeido = lectura - REFERENCIA;
   resultado = errorLeido*KP_recto;                         //Parte proporcional
   resultado = resultado + (errorLeido - errorAnt)*KD_recto;    //Anadido parte derivativa
   errorAnt=errorLeido;

   return resultado;                            //Devuelve la actuacion
}
signed int control_porc(signed int lectura)
{
   signed int errorLeido =0;
   signed int resultado=0;
   errorLeido = lectura - REFERENCIA;
   resultado = errorLeido*KP_porc;                         //Parte proporcional
   resultado = resultado + (errorLeido - errorAnt)*KD_porc;    //Anadido parte derivativa
   errorAnt=errorLeido;

   return resultado;                            //Devuelve la actuacion
}

signed int control_lateral(signed int lectura)
{
   signed int errorLeido =0;
   signed int resultado=0;
   errorLeido = lectura - REFERENCIA;
   resultado = errorLeido*KP_lateral;                         //Parte proporcional
   resultado = resultado + (errorLeido - errorAnt)*KD_lateral;    //Anadido parte derivativa
   errorAnt=errorLeido;

   return resultado;                            //Devuelve la actuacion
}
signed int control_intento_centrado(signed int lectura)
{
   signed int errorLeido =0;
   signed int resultado=0;
   errorLeido = lectura - REFERENCIA;
   resultado = errorLeido*KP_intento_centrado;                         //Parte proporcional
   resultado = resultado + (errorLeido - errorAnt)*KD_intento_centrado;    //Anadido parte derivativa
   errorAnt=errorLeido;

   return resultado;                            //Devuelve la actuacion
}
void ponMotores(signed int mi,signed int md)
{   rampa++;
    if (rampa<mi)
        mi=rampa;
    if (rampa<md)
        md=rampa;
    if (rampa>255)
        rampa=255;
    if(parados_motores==1)
    {
       motizq = 0;
       motder = 0;
       return;
    }

	// Actuamos sobre motor izquierdo
	if (mi>0)
	{
		if(mi>255)
			mi = 255;
		MotorIzquierdo(Adelante);
		motizq = mi;
	}
	else
	{
		if(mi<-255)
			mi = -255;
		MotorIzquierdo(Atras);
		motizq = -mi;
	}

	// Actuamos sobre motor derecho
	if (md>0)
	{
		if(md>255)
			md=255;
		MotorDerecho(Adelante);
		motder = md;
	}
	else
	{
		if(md<-255)
			md=-255;
		MotorDerecho(Atras);
		motder = -md;
	}    
}

