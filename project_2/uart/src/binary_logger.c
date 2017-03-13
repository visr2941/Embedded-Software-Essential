#include <stdint.h>
#include "logger.h"
#include <malloc.h>


typedef struct
{
	uint8_t log_id;
	uint16_t log_length;
	uint8_t * log_payload;
} binary_logger_t;

typedef enum log_ids {LOGGER_INITIALZED, GPIO_INITIALZED, SYSTEM_INITIALIZED, SYSTEM_HALTED, \
	INFO, WARNING, ERROR, DATA_RECEIVED, DATA_ANALYSIS_STARTED, DATA_ALPHA_COUNT, DATA_NUMERIC_COUNT, \
	DATA_PUNCTUATION_COUNT, DATA_MISC_COUNT, DATA_ANALYSIS_COMPLETED} log_id_e;

binary_logger_t * create_log_item(uint8_t log_id, uint16_t log_length)
{
	binary_logger_t * item = (binary_logger_t *) malloc(sizeof(binary_logger_t));
	item->log_length = log_length;
	item->log_id = log_id;
	item->log_payload = (uint8_t *) malloc(sizeof(log_length));
	return item;
}

void log_item(binary_logger_t * item)
{
	LOG_RAW_STRING("LOG_ID: ");
	LOG_RAW_INT(item->log_id);
	LOG_RAW_STRING("\n\r");
	LOG_RAW_STRING("LOG_LENGTH: ");
	LOG_RAW_INT(item->log_length);
	LOG_RAW_STRING("\n\r");
	LOG_RAW_STRING("LOG_PAYLOAD: ");
	LOG_RAW_STRING(item->log_payload);
	LOG_RAW_STRING("\n\r");
}

void destroy_log_item(binary_logger_t * item)
{
	free(item->log_payload);
	item->log_payload = NULL;
	free(item);
	item = NULL;
}

