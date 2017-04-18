#include "nrf.h"

void delay(int size)
{
	int i,j;
	for (j=0;j<size;j++)
	{
		for(i=0;i<1475;i++)
			{

			}
	}

}

void nrf_write_register(uint8_t reg, uint8_t value)
{
	GPIOD_PCOR = 1<<0;
	SPI_write_byte(NRF24L01P_SPI_CMD_WR_REG|reg);
	uint8_t stat = SPI_read_byte();
	SPI_write_byte(value);
	GPIOD_PSOR = 1<<0;

}

uint8_t nrf_read_register(uint8_t reg) //function to configure address for reading into register
{
	GPIOD_PCOR = 1<<0;
	SPI_write_byte(NRF24L01P_SPI_CMD_RD_REG|reg);
	//delay(100);
	uint8_t data=SPI_read_byte();
	SPI_write_byte(NRF24L01P_SPI_CMD_NOP);
	//delay(50);
	data=SPI_read_byte();
	GPIOD_PSOR = 1<<0;
	return data;
}

uint8_t nrf_read_config()           //Reading from config register
{
           //Clearing the CSN pin to send data
	return nrf_read_register(NRF24L01P_REG_CONFIG);           //Setting the CSN pin

}

void nrf_write_config(uint8_t config)
{

	nrf_write_register(NRF24L01P_REG_EN_RXADDR,config);
}


uint8_t nrf_read_status()
{
	return nrf_read_register(NRF24L01P_REG_STATUS);
}

uint8_t nrf_read_rf_setup()
{
	return nrf_read_register(NRF24L01P_REG_RF_SETUP);

}

void nrf_write_rf_setup(uint8_t config)
{
	nrf_write_register(NRF24L01P_REG_RF_SETUP,config);
	//spi_send_byte(0x84);
}

uint8_t nrf_read_rf_ch()
{
	return nrf_read_register(NRF24L01P_REG_RF_CH);

}

void nrf_write_rf_ch(uint8_t channel)
{
	nrf_write_register(NRF24L01P_REG_RF_CH,channel);
}

uint8_t * nrf_read_TX_ADDR()
{
	uint8_t tx = nrf_read_register(NRF24L01P_REG_TX_ADDR);
	return (uint8_t *) &tx;
}

void nrf_write_TX_ADDR(uint8_t * tx_addr)
{
	nrf_write_register(NRF24L01P_REG_TX_ADDR, *tx_addr);
}


uint8_t nrf_read_fifo_status(void)
{
	return nrf_read_register(NRF24L01P_REG_FIFO_STATUS);
}

void nrf_flush_tx_fifo(void)
{
	GPIOD_PCOR = 1<<0;             //Clearing the CSN pin to send data
	SPI_write_byte(NRF24L01P_SPI_CMD_FLUSH_TX);          //sending command to flush tx fifo
	GPIOD_PSOR =  1<<0;            //Setting the CSN pin
}

void nrf_flush_rx_fifo()
{
	GPIOD_PCOR = 1<<0;             //Clearing the CSN pin to send data
	SPI_write_byte(NRF24L01P_SPI_CMD_FLUSH_RX);           //sending command to flush tx fifo
	GPIOD_PSOR =  1<<0;            //Setting the CSN pin
}

