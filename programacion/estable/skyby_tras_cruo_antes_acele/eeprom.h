void write_eeprom(unsigned int eeprom_addr, unsigned char eeprom_data)
{
	EECON1bits.EEPGD = 0; 				/* Ensure EEPGD is clear for EEDATA access */
	EECON1bits.CFGS=0;					/* Select Data EEPROM */
	EECON1bits.WREN = 1; 				/* Ensure WREN is set to enable EEDATA writes */
        EEADR = eeprom_addr;
	EEDATA = eeprom_data; 				/* Set EEDATA to the value to write */
	EECON2 = 0x55; 						/* Write 0x55 to EECON2 */
	EECON2 = 0xaa; 						/* Write 0xAA to EECON2 */
	EECON1bits.WR = 1; 					/* Initiate write cycle by setting the WR bit */
	while (!PIR2bits.EEIF);				/* Wait for the EEIF flag to be set */
	PIR2bits.EEIF = 0; 					/* Clear the EEIF flag */
	EECON1bits.WREN = 0; 				/* Ensure WREN is set to enable EEDATA writes */
}

unsigned char read_eeprom(unsigned int eeprom_addr)
{
    EEADR = eeprom_addr;
	EECON1bits.EEPGD = 0; 			/* Ensure EEPGD is clear for EEDATA access */
	EECON1bits.RD = 1; 				/* Trigger a read by setting the RD bit */
	return EEDATA;					/* Read the result from EEDATA register */
}
