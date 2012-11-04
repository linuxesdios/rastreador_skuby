void envio_vector(void);
void  limpiar_sensor(void) //pongo los en vector  a ceros
{
  int i;
  for ( i=0; i < 12; i++)
    sensor[i]=0;
}
void  limpiar_sensor_ant(void)//pongo los en vector  a ceros
{
  int i;
  for ( i=0; i < 12; i++)
    sensor_ant[i]=0;
}
void  cambiar_sensor_ant_por_sensor(void)
{
  int i;
  for ( i=0; i < 12; i++)
    sensor_ant[i]=sensor[i];
}

void leer_sensores_vector(void)
{
  limpiar_sensor();
  if(S0 == N) sensor[1]=1;
  if(S1 == N) sensor[2]=1;
  if(S2 == N) sensor[3]=1;
  if(S3 == N) sensor[4]=1;
  if(S4 == N) sensor[5]=1;
  if(S5 == N) sensor[6]=1;
  if(S6 == N) sensor[7]=1;
  if(S7 == N) sensor[8]=1;
  if(S8 == N) sensor[9]=1;
  if(S9 == N) sensor[10]=1;
  
}

int comprobacion_lectura(void)
  //ejemplo de como dectecto:
  //
  // 0001100 --> un solo salto
  //00110100 -->  decto  dos saltos
  //
  //es decir resto  la posion 7 con la 6  y asi sucesivamente hasta 0
  // viendo  cuando  la resta en es -1
  // y asi veo el numero de saltos
  //
  //vector -> 0  0  0  1  1  0  0
  //resta ->    0  0  1  0  -1 0   --> un solo salto
  //
  //vector -> 0  -1  0  1  1  0  0
  //resta ->    -1  0  1  0  -1 0   -->  dos saltos
  //
  //ademas de eso hago la media   de donde hay negro
  //cosa q despues vemaldra paa dectar  en a lado esta la marda de desviacion
{

  int acu=0, numero_acu=0;
  int i;
  leer_sensores_vector();
  numero_lineas=0;
  for (i=0; i < 11; i++)
  {
    if ((sensor[i]-sensor[i+1])==1)
      numero_lineas++;
    if (sensor[i]==1)
    {
      numero_acu++;
      acu=acu+i;
    }
  }
  media=acu/numero_acu;
  return(numero_lineas);
}


int comprobar_lado(void)
{   
   
  int acu=0, numero_acu=0;
  int i;
  for ( i=0; i < 11; i++)
  {
    if ((sensor[i]-sensor[i+1])!=(sensor_ant[i]-sensor_ant[i+1]))
    {
      numero_acu ++;
      acu=acu+i;
    }
  }
  media_ant=acu/numero_acu;

  if (media>media_ant)
    return 1;
  else
    return 2;
}





