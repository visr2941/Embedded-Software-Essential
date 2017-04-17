#ifndef BINARY_LOGGER_H_
#define BINARY_LOGGER_H_

#include "main.h"

#define LOG_ITEM(item)		log_item(item)

typedef struct
{
	uint8_t log_id;
	uint16_t log_length;
	uint8_t * log_payload;
	uint8_t * timestamp;
} binary_logger_t;

typedef enum log_ids {LOGGER_INITIALZED, GPIO_INITIALZED, SYSTEM_INITIALIZED, SYSTEM_HALTED, \
	INFO, WARNING, ERROR, DATA_RECEIVED, DATA_ANALYSIS_STARTED, DATA_ALPHA_COUNT, DATA_NUMERIC_COUNT, \
	DATA_PUNCTUATION_COUNT, DATA_MISC_COUNT, DATA_ANALYSIS_COMPLETED, HEARTBEAT} log_id_e;

binary_logger_t * create_log_item(uint8_t log_id, uint16_t log_length);
void log_item(binary_logger_t * item);
void destroy_log_item(binary_logger_t * item);

#endif /* SOURCES_BINARY_LOGGER_H_ */

