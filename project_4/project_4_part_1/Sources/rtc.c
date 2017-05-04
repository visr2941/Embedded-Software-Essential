#include "rtc.h"

void init_rtc()
{
	MCG_C1 = MCG_C1_IRCLKEN_MASK; //Enable internal reference clock
	MCG_C2 &= ~(MCG_C2_IRCS_MASK);  //Internal Reference Clock -->Slow

	SIM_SCGC5  |= SIM_SCGC5_PORTC_MASK;       // port C

	PORTC_PCR(1) |= PORT_PCR_MUX(1);             // 1 (GPIO/RTC_CLKIN)
	SIM_SOPT1 &= SIM_SOPT1_OSC32KSEL(2);
	SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(2);	// selecting 32 KHz OSC

	SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(4);
	PORTC_PCR(3) |= PORT_PCR_MUX(5);             //5 (CLKOUT)

	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;	// enabling RTC

	RTC_CR = RTC_CR_SWR_MASK;
	RTC_CR &= ~RTC_CR_SWR_MASK;

	if(RTC_SR & RTC_SR_TIF_MASK)
		RTC_TSR = 0x0;

	RTC_IER |= RTC_IER_TSIE_MASK;
	NVIC_EnableIRQ(RTC_Seconds_IRQn);

	RTC_SR |= RTC_SR_TCE_MASK;

}

void RTC_Seconds_IRQHandler()
{
	RTC_TPR = 0x0;
}
