#ifndef LOGGER_H
#define LOGGER_H

#include "cirbuf.h"

CircBuf * tx_buf;
CircBuf * rx_buf;

buffer_init(tx_buf, 100);
buffer_init(rx_buf, 100);

#endif

