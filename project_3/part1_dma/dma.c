memmove_dma(uint8_t * src_addr, uint8_t * dst_addr, size_t length, uint8_t word_size)
{
	if(word_size==2)
	{	
		src_addr = (uint16_t *) src_addr;
		dst_addr = (uint16_t *) dst_addr;
	}
	else if(word_size==4)
	{	
		src_addr = (uint32_t *) src_addr;
		dst_addr = (uint32_t *) dst_addr;
	}
	else if(word_size==1)
	{
	}
	else
		printf("Invalid word size");
	
		
	
}

