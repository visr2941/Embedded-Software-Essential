#include "binary_logger.h"

binary_logger_t * create_log_item(uint8_t log_id, uint16_t log_length)
{
	binary_logger_t * item = (binary_logger_t *) malloc(sizeof(binary_logger_t));
	item->log_length = log_length;
	item->log_id = log_id;
	item->log_payload = (uint8_t *) malloc(sizeof(log_length));
	item->timestamp = (uint8_t *) malloc(8*sizeof(uint8_t));
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
	LOG_RAW_STRING("LOG_TIMESTAMP: ");
	LOG_RAW_STRING(item->timestamp);
	LOG_RAW_STRING("\n\r");
}

void destroy_log_item(binary_logger_t * item)
{
	free(item->log_payload);
	item->log_payload = NULL;
	free(item);
	item = NULL;
}

