//--------------------prototipos----------------------------//
void HiInterrupcion(void);
void LoInterrupcion(void);
void leer_sensores_vector(void);
int Comprobacion_lectura(void);
void limpiar_sensor(void);
void botones(void);
void lucir(void);
int comprobacion_lectura(void);
void funcion_modo(void);
void cambiar_sensor_ant_por_sensor(void);
int calcular_error_absoluto_porcentaje(void);
void INIT_T3(void);
void Delay_3s(void);
void Delay_1s(void);
void Delay_500ms(void);
void Delay_100ms(void);
float calculo_arctan(void);
void envio_angulo(void);
float filtro_Complementario_1(float newAngle, float newRate);
float filtro_Complementario_2(float newAngle, float newRate);
float filtro_kalman(float newAngle, float newRate);
void refrescar_acelerometro(void);

// --------------------DEFINDES DE PID-----------------------//
int porcentaje            =   40;
int ejecucion       =   9;
int BIAS_intento_centrado   =   40;
int KP_intento_centrado     =   4;//   16;//11(2x.3.3)   //  18//18//16(7,4)
int KD_intento_centrado     =  90;//180;//237 (2x.3.3);//243//240//160(7,4)
int BIAS_porc               =   50;//70;//80(2.3.3);//85//90//70(7,4)
int KP_porc                 =   9;//   16;//11(2x.3.3)   //  18//18//16(7,4)
int KD_porc                 =   100;//180;//237 (2x.3.3);//243//240//160(7,4)
int BIAS_lateral            =   50;//70;//80(2.3.3);//85//90//70(7,4)
int KP_lateral              =   9;//   16;//11(2x.3.3)   //  18//18//16(7,4)
int KD_lateral               =   100;//180;//237 (2x.3.3);//243//240//160(7,4)
int BIAS_recto             =   70;//70;//80(2.3.3);//85//90//70(7,4)
int KP_recto               =   9;//   16;//11(2x.3.3)   //  18//18//16(7,4)
int KD_recto               =   100;//180;//237 (2x.3.3);//243//240//160(7,4)
int tfuera                  =   0;
int msdefrenada             =   18;
int  aux_errorLeido         = 0;
float tanto_por_diento      = 0.4;
int modo                    =0;
int aux_salida              =0;
int t_centrando             =50;
unsigned double centrado=   0;
int i=0;
int tiempo_retardo=2;
int rampa=0;
// --------------------DEFINDES DE bifurcacion-----------------------//
int sensor[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int numero_lineas=0;
int sensor_ant[12] = {0,0,0,0,0,1,1,0,0,0,0,0};
int numero_error,lado;
int giro=0,detectado_lado=0,salido=0,var_A0=0,var_A7=0,acumulada_desvio=0;
float media_ant=0,media=0;
int aux_comprobar_lado=0;
int conta=0;
// --------------------DEFINDES DE CONTROL-----------------------//
int                     parados_motores=0;
int                     cont=0;
signed	int		errorAnt;
signed	int		int_MD=0;
signed	int		int_MI=0;
signed	int		dire=0;
signed	int		direAnt=0;
int             	pd=0;
int             	pi=0;
signed int		rcontrol=0;
signed int              errorLeido=0;

// --------------------DEFINDES DE ACELEROMETRO-----------------------//
signed int ax,ay,az,gx,gy,gz,T;
signed int ax_ant,ay_ant,az_ant,gx_ant,gy_ant,gz_ant,T_ant;
float angulo=0,x1=0,y1=0,x2=0,x_angle2C=0;
float tau=0.075,a=0.0,x_angleC=0.0;
float Q_angle  =  0.02,Q_gyro   =  0.0006,R_angle  =  0.02;
float x_bias = 0, P_00 = 0, P_01 = 0, P_10 = 0, P_11 = 0,y,S,K_0, K_1,x_angle;
int valor_angulo;
float k=10;
int contador_ace=0;
//---------------------DEFINES ENVIO----------------------------------//
       static unsigned char Retorno[] ="\r\n";
