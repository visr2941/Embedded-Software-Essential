#include "dma.h"


uint8_t memmove_dma(uint8_t * src_addr, uint8_t * dst_addr, size_t length)
{
	uint8_t word_size=4;

    // clocking DMA & DMAMUX
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
    // end

    // configuring DMA_DCR0 for memory to memory
    DMA_DCR0 |= DMA_DCR_SINC_MASK |     // increase source pointer
                DMA_DCR_DINC_MASK ;     // increase destination pointer
    // end

    /* word_size for fastest transfer */
	while(length%word_size)
	{
		word_size = word_size/2;
	}
	// end

    // setting the DSIZE and SSIZE based on word_size
    if(word_size==4)
    {
    	DMA_DCR0 |= DMA_DCR_SSIZE(0);		// setting source for 4 byte transfer
    	DMA_DCR0 |= DMA_DCR_DSIZE(0);		// setting destination for 4 byte transfer
    }
    else if(word_size==2)
    {
    	DMA_DCR0 |= DMA_DCR_SSIZE(2);		// setting source for 2 byte transfer
    	DMA_DCR0 |= DMA_DCR_DSIZE(2);		// setting destination for 2 byte transfer
    }
    else if(word_size==1)
    {
    	DMA_DCR0 |= DMA_DCR_SSIZE(1);		// setting source for 1 byte transfer
    	DMA_DCR0 |= DMA_DCR_DSIZE(1);		// setting destination for 1 byte transfer
    } // end


    DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);	// setting the length of counter for number of bytes

    // configuring addresses 
	//if((src_addr < dst_addr) && (src_addr+length-1 >= dst_addr))
    //	DMA_SAR0 |= (uint32_t) src_addr+length-1;
    //	DMA_DAR0 |= (uint32_t) dst_addr+length-1;
	//else
		DMA_SAR0 |= (uint32_t) src_addr;
    	DMA_DAR0 |= (uint32_t) dst_addr;
    // end

    //DMA_DCR_START(0);
    DMA_DCR0 |= DMA_DCR_START_MASK;     // starting the dma

    return 0;
}


uint8_t memzero_dma(uint8_t * addr, size_t length)
{
    uint8_t x=0, word_size=4;

    // clocking DMA & DMAMUX
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
    // end

    // configuring DMA_DCR0 for memory to memory
    DMA_DCR0 |= DMA_DCR_DINC_MASK ;     // increase destination pointer
    // end

    /* word_size for fastest transfer */
	while(length%word_size)
	{
		word_size = word_size/2;
	}
	// end

    // setting the DSIZE and SSIZE based on word_size
    if(word_size==4)
    {
    	DMA_DCR0 |= DMA_DCR_SSIZE(0);		// setting source for 4 byte transfer
    	DMA_DCR0 |= DMA_DCR_DSIZE(0);		// setting destination for 4 byte transfer
    }
    else if(word_size==2)
    {
    	DMA_DCR0 |= DMA_DCR_SSIZE(2);		// setting source for 2 byte transfer
    	DMA_DCR0 |= DMA_DCR_DSIZE(2);		// setting destination for 2 byte transfer
    }
    else if(word_size==1)
    {
    	DMA_DCR0 |= DMA_DCR_SSIZE(1);		// setting source for 1 byte transfer
    	DMA_DCR0 |= DMA_DCR_DSIZE(1);		// setting destination for 1 byte transfer
    } // end

    DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);	// setting the length of counter for number of bytes

    // configuring addresses
    DMA_SAR0 |= (uint32_t) &x;		// setting source address as address of x
    DMA_DAR0 |= (uint32_t) addr;	// setting destination address
    // end

    DMA_DCR0 |= DMA_DCR_START_MASK;     // starting the dma

    return 0;
}
