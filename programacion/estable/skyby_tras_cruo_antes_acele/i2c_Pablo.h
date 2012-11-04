#include    <p18f4550.h>
#include <i2c.h>

void Init_I2C(void)
{
  SSPSTAT = 0x00;	// SMP	0
					// CKE	0
					// D/A	0
					// P	0
					// S	0
					// R/W	0
					// UA	0
					// BF	0
					
  SSPCON1 = 0x28;	// WCOL		0
					// SSPOV	0
					// SSPEN	1
					// CKP		0
					// SSPM3:0	1000				
  
   SSPCON2 = 0x00;	// GCEN		0
					// ACKSTAT	0
					// ACKDT	0
					// ACKEN	0
					// RCEN		0
					// PEN		0
					// RSEN		0
					// SEN		0
 
}

unsigned int ByteWrite(unsigned char address, unsigned char data)
{
	unsigned int ErrorCode;
	unsigned char write = 0xD0;		// Byte de Control del ACC
	
	IdleI2C();						//Ensure Module is Idle
	
	StartI2C();						//Generate Start COndition
	while(SSPCON2bits.SEN);			// wait until start condition is over
	WriteI2C(write);				//Write Control byte
	IdleI2C();
	while(SSPCON2bits.ACKSTAT);		// test for ACK condition, if received
	
	WriteI2C(address);				//Write High Address
	IdleI2C();
	while(SSPCON2bits.ACKSTAT);		// test for ACK condition, if received
	
	WriteI2C(data);					//Write Data
	IdleI2C();
	while(SSPCON2bits.ACKSTAT);		// test for ACK condition, if received
	
	StopI2C();						//Initiate Stop Condition
	while(SSPCON2bits.PEN); 		// wait until stop condition is over
	
	return(ErrorCode);
        Delay100TCYx(5);
}

unsigned char ByteRead(unsigned char address)
{
	unsigned char control = 0xD0;	// Byte de Control de Escritura del ACC
	unsigned char data = 0x00;		// Dato a enviar
	
	IdleI2C();                      //Wait for bus Idle
	StartI2C();                     //Generate Start Condition

	WriteI2C(control);				//Write Control Byte
	IdleI2C();
	while(SSPCON2bits.ACKSTAT);		// test for ACK condition, if received

	WriteI2C(address);				//Write Adrss Byte
	IdleI2C();                      //wait for bus Idle
	while(SSPCON2bits.ACKSTAT);		// test for ACK condition, if received

	RestartI2C();					//Generate restart condition
	WriteI2C(control+1);			//Write control byte for read
	IdleI2C();						//wait for bus Idle
	while(SSPCON2bits.ACKSTAT);		// test for ACK condition, if received

	SSPCON2bits.RCEN = 1;			// enable master for 1 byte reception
	while(SSPCON2bits.RCEN);		// check that receive sequence is over
	
	// Como no se que debe recibir el ACC cuando leemos datos, envio un ACK y comento el NoACK
	//AckI2C();						// send ACK condition
	NotAckI2C();					// send ACK condition
	
	StopI2C();						// send STOP condition
	while(SSPCON2bits.PEN);			// wait until stop condition is over
	
	data = SSPBUF;
	return data;					// return with data
        Delay100TCYx(5);
} 

