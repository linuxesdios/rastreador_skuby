
void envio_vector(void)
{leer_sensores_vector();
       BAUDCONbits.BRG16=1;
       OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH,1250);// 9600,8,n,1

       printf("%d%d%d%d%d%d%d%d%d%d%d%d - ",sensor[0],sensor[1],sensor[2],sensor[3],sensor[4],sensor[5],sensor[6],sensor[7],sensor[8],sensor[9],sensor[10],sensor[11],sensor[12]);
//       printf("%d%d%d%d%d%d%d%d%d%d%d%d",sensor_ant[0],sensor_ant[1],sensor_ant[2],sensor_ant[3],sensor_ant[4],sensor_ant[5],sensor_ant[6],sensor_ant[7],sensor_ant[8],sensor_ant[9],sensor_ant[10],sensor_ant[11],sensor_ant[12]);       printf(" lineas=%d",numero_lineas);
//       printf(" ejecuta %d",ejecucion);
//       printf(" giro %d",giro );
//       printf(" salido %d",salido );
 //      printf(" DIRE %d",dire );
       putsUSART((char *)Retorno);
       CloseUSART();
}

