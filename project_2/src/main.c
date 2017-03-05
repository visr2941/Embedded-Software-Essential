#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cirbuf.h"

main()
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));
	buffer_init(buf, 3);
	printf("head %p tail %p buffer %p length %d count %d *head %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head));
	
	buffer_add(buf, 25);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_add(buf, 52);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_add(buf, 57);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));

	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));

	buffer_add(buf, 62);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));

	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	

	buffer_add(buf, 92);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_add(buf, 32);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	//buffer_add(buf, 82);
	//printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	//buffer_add(buf, 162);
	//printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));

	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	buffer_remove(buf);
	printf("head %p tail %p buffer %p length %d count %d *head %d *tail %d\n", buf->head, buf->tail, buf->buffer, buf->length, buf->count, *(buf->head), *(buf->tail));
	
}
