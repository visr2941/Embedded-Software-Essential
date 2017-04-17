#ifndef SOURCES_NRF_H_
#define SOURCES_NRF_H_

#include "main.h"
#include <stdint.h>


	#define NRF24L01P_SPI_CMD_RD_REG            0x00
	#define NRF24L01P_SPI_CMD_WR_REG            0x20
	#define NRF24L01P_SPI_CMD_RD_RX_PAYLOAD     0x61
	#define NRF24L01P_SPI_CMD_WR_TX_PAYLOAD     0xa0
	#define NRF24L01P_SPI_CMD_FLUSH_TX          0xe1
	#define NRF24L01P_SPI_CMD_FLUSH_RX          0xe2
	#define NRF24L01P_SPI_CMD_REUSE_TX_PL       0xe3
	#define NRF24L01P_SPI_CMD_R_RX_PL_WID       0x60
	#define NRF24L01P_SPI_CMD_W_ACK_PAYLOAD     0xa8
	#define NRF24L01P_SPI_CMD_W_TX_PYLD_NO_ACK  0xb0
	#define NRF24L01P_SPI_CMD_NOP               0xff


	#define NRF24L01P_REG_CONFIG                0x00
	#define NRF24L01P_REG_EN_AA                 0x01
	#define NRF24L01P_REG_EN_RXADDR             0x02
	#define NRF24L01P_REG_SETUP_AW              0x03
	#define NRF24L01P_REG_SETUP_RETR            0x04
	#define NRF24L01P_REG_RF_CH                 0x05
	#define NRF24L01P_REG_RF_SETUP              0x06
	#define NRF24L01P_REG_STATUS                0x07
	#define NRF24L01P_REG_OBSERVE_TX            0x08
	#define NRF24L01P_REG_RPD                   0x09
	#define NRF24L01P_REG_RX_ADDR_P0            0x0a
	#define NRF24L01P_REG_RX_ADDR_P1            0x0b
	#define NRF24L01P_REG_RX_ADDR_P2            0x0c
	#define NRF24L01P_REG_RX_ADDR_P3            0x0d
	#define NRF24L01P_REG_RX_ADDR_P4            0x0e
	#define NRF24L01P_REG_RX_ADDR_P5            0x0f
	#define NRF24L01P_REG_TX_ADDR               0x10
	#define NRF24L01P_REG_RX_PW_P0              0x11
	#define NRF24L01P_REG_RX_PW_P1              0x12
	#define NRF24L01P_REG_RX_PW_P2              0x13
	#define NRF24L01P_REG_RX_PW_P3              0x14
	#define NRF24L01P_REG_RX_PW_P4              0x15
	#define NRF24L01P_REG_RX_PW_P5              0x16
	#define NRF24L01P_REG_FIFO_STATUS           0x17
	#define NRF24L01P_REG_DYNPD                 0x1c
	#define NRF24L01P_REG_FEATURE               0x1d

	#define NRF24L01P_REG_ADDRESS_MASK          0x1f
	#define NRF24L01P_CONFIG_PRIM_RX        	(1<<0)
	#define NRF24L01P_CONFIG_PWR_UP         	(1<<1) // Equivalent to #define NORDIC_POWER_UP

	// Function Prototypes
	uint8_t nrf_read_register(uint8_t reg);
	void nrf_write_register(uint8_t register, uint8_t value);
	uint8_t nrf_read_status();
	void nrf_write_config(uint8_t config);
	uint8_t nrf_read_config();
	uint8_t nrf_read_rf_setup();
	void nrf_write_rf_setup(uint8_t config);
	uint8_t nrf_read_rf_ch();
	void nrf_write_rf_ch(uint8_t channel);
	uint8_t * nrf_read_TX_ADDR();
	void nrf_write_TX_ADDR(uint8_t * tx_addr);
	uint8_t nrf_read_fifo_status();
	void nrf_flush_tx_fifo();
	void nrf_flush_rx_fifo();



#endif /* SOURCES_NRF_H_ */
