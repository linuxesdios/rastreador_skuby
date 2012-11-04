void refrescar_acelerometro(void)
{
    ax=ByteRead(MPU6050_RA_ACCEL_XOUT_H);
    ax=ax<<8;
    ax=ax+ByteRead(MPU6050_RA_ACCEL_XOUT_L);

    ay=ByteRead(MPU6050_RA_ACCEL_YOUT_H);
    ay=ay<<8;
    ay=ay+ByteRead(MPU6050_RA_ACCEL_YOUT_L);

//    az=ByteRead(MPU6050_RA_ACCEL_ZOUT_H);
//    az=az<<8;
//    az=az+ByteRead(MPU6050_RA_ACCEL_ZOUT_L);

    gx=ByteRead(MPU6050_RA_GYRO_XOUT_H);
    gx=gx<<8;
    gx=gx+ByteRead(MPU6050_RA_GYRO_XOUT_L);
//
//    gy=ByteRead(MPU6050_RA_GYRO_YOUT_H);
//    gy=gy<<8;
//    gy=gy+ByteRead(MPU6050_RA_GYRO_YOUT_L);
//
//    gz=ByteRead(MPU6050_RA_GYRO_ZOUT_H);
//    gz=gz<<8;
//    gz=gz+ByteRead(MPU6050_RA_GYRO_ZOUT_L);
//
//    T=ByteRead(MPU6050_RA_TEMP_OUT_H);
//    T=T<<8;
//    T=T+ByteRead(MPU6050_RA_TEMP_OUT_L);


}

// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

float calculo_arctan(void)
{
    return(atan2((float)ay,(float)ax));
}

float filtro_Complementario_1(float newAngle, float newRate) {
float dtC = 0.1;
a=tau/(tau+dtC);
x_angleC= a* (x_angleC + newRate * dtC) + (1-a) * (newAngle);
return x_angleC;
}

float filtro_Complementario_2(float newAngle, float newRate) {

float dtc2=0.1;
x1 = (newAngle -x_angle2C)*k*k;
y1 = dtc2*x1 + y1;
x2 = y1 + (newAngle - x_angle2C)*2*k + newRate;
x_angle2C = dtc2*x2 + x_angle2C;

return x_angle2C;

}





// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

float filtro_kalman(float newAngle, float newRate)
{
float dt = 0.1;
x_angle += dt * (newRate - x_bias);
P_00 +=  - dt * (P_10 + P_01) + Q_angle * dt;
P_01 +=  - dt * P_11;
P_10 +=  - dt * P_11;
P_11 +=  + Q_gyro * dt;

y = newAngle - x_angle;
S = P_00 + R_angle;
K_0 = P_00 / S;
K_1 = P_10 / S;

x_angle +=  K_0 * y;
x_bias  +=  K_1 * y;
P_00 -= K_0 * P_00;
P_01 -= K_0 * P_01;
P_10 -= K_1 * P_00;
P_11 -= K_1 * P_01;

return x_angle;
}


void comprobar_acelerometro(void)
{
    refrescar_acelerometro();
      if((ax-ax_ant)>800)
           LED_ROJO=1;
       else
           LED_ROJO=0;
       if((ay-ay_ant)>800)
           LED_VERDE=1;
       else
           LED_VERDE=0;
       if((az-az_ant)>800)
           LED_AZUL=1;
       else
           LED_AZUL=0;

           ax_ant=ax;
           ay_ant=ay;
           az_ant=az;
           gx_ant=gx;
           gy_ant=gy;
           gz_ant=gz;
}
 void autosintonizado(void)
{   int i=0;
    long acuG_x,acuG_y,acuG_z,acuA_x,acuA_y,acuA_z=0;
    for(i=0;i>20;i++)
    {
        refrescar_acelerometro();
        acuG_x=ax+acuG_x;
        acuG_y=ax+acuG_y;
        acuG_z=ax+acuG_z;
        acuA_x=ax+acuA_x;
        acuA_y=ax+acuA_y;
        acuA_z=ax+acuA_z;

    }
        acuG_x=acuG_x/20;
        acuG_y=acuG_y/20;
        acuG_z=acuG_z/20;
        acuA_x=acuA_x/20;
        acuA_y=acuA_y/20;
        acuA_z=acuA_z/20;
        BAUDCONbits.BRG16=1;
        OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH,520);// 9600,8,n,1
        printf("acuG_x = %d acuG_y = %d acuG_z = %d acuA_x = %d acuA_y = %d acuA_z = %d ",(int)acuG_x,(int)acuG_y,(int)acuG_z,(int)acuA_x,(int)acuA_y,(int)acuA_z);
        putsUSART((char *)Retorno);
        CloseUSART();
}


 void calcular_k(void)
 {
     float i;
     int j,valor;
     borrar_led
     BAUDCONbits.BRG16=1;
     OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH,520);// 9600,8,n,1

     for (i=200;i>0.001;i=i-1)
     {  valor=0;
        k=i;
         for(j=0;j>19;j++)
         {
            refrescar_acelerometro();
            valor=valor+filtro_Complementario_2(calculo_arctan(), (float)gx);
            Delay_100ms();
         }
         printf("\t%d",(int)(filtro_Complementario_2(calculo_arctan(), (float)gx)) );
         valor=valor/20;
         envio_angulo();
         printf("\t%d\t%d",(int)(i),(int)(1000*valor) );
         putsUSART((char *)Retorno);
       

     }
          putsUSART((char *)Retorno);
         CloseUSART();
 }

 