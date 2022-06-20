//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "app.h"
#include "clock.h"

void AppInit(void)
{
	ClocksInit();
	
	// Assign LED0 as OUTPUT
	REG_PORT_DIR0 = LED0_PIN_MASK;
	REG_PORT_DIR0 |= PORT_PA20;
	// Set LED0 OFF
	REG_PORT_OUTCLR0 = LED0_PIN_MASK;
	REG_PORT_OUTCLR0 |= PORT_PA20;
	
	//PORT->Group[0].PINCFG[5].bit.PMUXEN = 1; // for tcc0 wo[1] at e
	//PORT->Group[0].PMUX[2].bit.PMUXO = 0x4;
	
	//PORT->Group[0].PINCFG[6].bit.PMUXEN = 1; // for tcc1 wo[0] at e
	//PORT->Group[0].PMUX[3].bit.PMUXE = 0x4;
	
	PORT->Group[0].PINCFG[9].bit.PMUXEN = 1; // for tcc0 wo[1] at e
	PORT->Group[0].PMUX[4].bit.PMUXO = 0x4;
	
	//PORT->Group[0].PINCFG[9].bit.PMUXEN = 1; // for tcc1 wo[3] at f
	//PORT->Group[0].PMUX[4].bit.PMUXO = 0x5;
	
	PORT->Group[1].PINCFG[10].bit.PMUXEN = 1; // for tcc0 wo[4] at f 
	PORT->Group[1].PMUX[5].bit.PMUXE = 0x5;
	
	PORT->Group[0].PINCFG[10].bit.PMUXEN = 1; // for tcc0 wo[4] at f 
	PORT->Group[0].PMUX[5].bit.PMUXE = 0x5;
	
} // AppInit()

void AppRun(void)
{
	while(1)
	{
		// Set the drive strength to strong
		PORT->Group[LED0_PORT].PINCFG[LED0_PIN_NUMBER].bit.DRVSTR = 1;
		// Turn the LED on PA17 ON
		REG_PORT_OUTSET0 = LED0_PIN_MASK;
	}

} // Apprun()

