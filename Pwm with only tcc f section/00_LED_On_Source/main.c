//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////

#include "sam.h"
#include "definitions.h"
#include "app.h"

//////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////
void ClocksInit(void);	// Configure Clock, Wait States and synch, bus clocks for 48MHz operation

int main(void)
{
	// CMSIS compliant function not used
	//SystemInit();

	// Application hardware and software initialization 
	AppInit();
	/*// for pa9
	TCC0->CTRLA.bit.ENABLE = 0;
	TCC0->CTRLA.bit.PRESCSYNC = 0x1;
	TCC0->CTRLA.bit.PRESCALER = 0x2;
	TCC0->WAVE.bit.WAVEGEN = 0x2;
	
	TCC0->PER.bit.PER = 65536 - 1;
	TCC0->CC[1].bit.CC = 16384 - 1;
	TCC0->CTRLA.bit.ENABLE = 1;
	*/
	// for pb10
	TCC0->CTRLA.bit.ENABLE = 0;
	TCC0->CTRLA.bit.PRESCSYNC = 0x1;
	TCC0->CTRLA.bit.PRESCALER = 0x1;
	TCC0->WAVE.bit.WAVEGEN = 0x2;
	TCC0->WAVE.bit.POL0 = 0;
	TCC0->CTRLBSET.bit.LUPD = 0;
	//TCC0->WAVE.bit.CICCEN0 = 1;
	//TCC0->WAVE.bit.CIPEREN = 1;
	TCC0->PER.bit.PER = 65536 - 1;
	TCC0->PERB.bit.PERB = 32768 - 1;
	while(!(TCC0->STATUS.bit.PERBV)){}
	TCC0->CC[0].bit.CC = 16384 - 1;
	TCC0->CCB[0].bit.CCB = 16384 - 1;
	while(!(TCC0->STATUS.bit.CCBV0)){}
	TCC0->CTRLA.bit.ENABLE = 1; 
	
	/*//for pa10
	TCC0->CTRLA.bit.ENABLE = 0;
	TCC0->CTRLA.bit.PRESCSYNC = 0x1;
	TCC0->CTRLA.bit.PRESCALER = 0x1;
	TCC0->WAVE.bit.WAVEGEN = 0x2;
	TCC0->WAVE.bit.POL2 = 0;
	TCC0->CTRLBSET.bit.LUPD = 0;
	//TCC0->WAVE.bit.CICCEN0 = 1;
	//TCC0->WAVE.bit.CIPEREN = 1;
	TCC0->PER.bit.PER = 65536 - 1;
	TCC0->PERB.bit.PERB = 65536 - 1;
	while(!(TCC0->STATUS.bit.PERBV)){}
	TCC0->CC[2].bit.CC = 32768 - 1;
	TCC0->CCB[2].bit.CCB = 32768 - 1;
	while(!(TCC0->STATUS.bit.CCBV2)){}
	TCC0->CTRLA.bit.ENABLE = 1; 
	*/
	// Super loop
	while(1)
	{
		// Run your application
		
	}
} // main()




