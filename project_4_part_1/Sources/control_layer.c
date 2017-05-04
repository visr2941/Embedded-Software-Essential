#include "main.h"


void gpio_init_led()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	//clocking the Port B
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	//clocking the Port B
	PORTB_PCR18 = PORT_PCR_MUX(1);		//setting port B for GPIO
	PORTB_PCR19 = PORT_PCR_MUX(1);		//setting port B for GPIO
	PORTD_PCR1 = PORT_PCR_MUX(1);		//setting port D for GPIO
}

void led_on(uint8_t led)
{
	gpio_init_led();

	if(led==RED || led==GREEN)
	{
		GPIOB_PDDR |= (1<<led);
		GPIOB_PDOR &= ~(1<<led);	//putting 1 on pin 18 of portB
	}
	else if (led==BLUE)
	{
		GPIOD_PDDR |= (1<<led);
		GPIOD_PDOR &= ~(1<<led);	//putting 1 on pin 18 of portB
	}
}

void led_off(uint8_t led)
{
	if(led==RED || led==GREEN)
		GPIOB_PDOR |= (1<<led);		//putting 1 on pin 18 of portB
	else if (led==BLUE)
		GPIOD_PDOR |= (1<<led);		//putting 1 on pin 18 of portB
}


void pwm_config()
{
	MCG_C1 = MCG_C1_IREFS_MASK|MCG_C1_IRCLKEN_MASK;
	MCG_C2 = MCG_C2_IRCS_MASK;

	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;	//clocking the TPM0 module
	SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;	//clocking the TPM0 module
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	//clocking the Port B
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	//clocking the Port B

	PORTB_PCR18 = PORT_PCR_MUX(3);		//setting port B for PWM
	PORTB_PCR19 = PORT_PCR_MUX(3);		//setting port B for PWM
	PORTD_PCR1 = PORT_PCR_MUX(4);		//setting port D for PWM

    //Set Direction of PORT
    GPIOB_PDDR=(1<<18);
    GPIOB_PDDR |=(1<<19);
    GPIOD_PDDR=(1<<1);

    GPIOB_PDOR |= (1<<18 | 1<<19);
    GPIOD_PDOR = (1<<1);

	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(3);	//selecting internal MCG clock

	TPM0_SC = TPM_SC_CMOD(1);	//setting TPM0 to increase count on LPTPM clock
	TPM2_SC = TPM_SC_CMOD(1);	//setting TPM2 to increase count on LPTPM clock

	TPM2_MOD = 16383;
	TPM0_MOD = 16383;

	TPM2_CnSC(0) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
	TPM2_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
	TPM0_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;

	TPM2_CnV(0) = TPM2_CnV(1) = TPM0_CnV(1) = 16384;
}

void inc_brightness(uint8_t led)
{
	if(led==RED)
		TPM2_CnV(0) = TPM2_CnV(0) - 2048;
	else if(led==GREEN)
		TPM2_CnV(1) = TPM2_CnV(1) - 2048;
	else if (led==BLUE)
		TPM0_CnV(1) = TPM0_CnV(1) - 2048;
}

void dec_brightness(uint8_t led)
{
	if(led==RED)
		TPM2_CnV(0) = TPM2_CnV(0) + 2048;
	else if(led==GREEN)
		TPM2_CnV(1) = TPM2_CnV(1) + 2048;
	else if (led==BLUE)
		TPM0_CnV(1) = TPM0_CnV(1) + 2048;
}

void get_rtc_time(uint8_t * str)
{
	uint32_t x = RTC_TSR;
	uint8_t hr = x/3600;
	uint8_t min = x/60;
	uint8_t sec = x%60;
	sprintf(str,"%02d:%02d:%02d", hr,min,sec);
}











