memmove_dma(uint8_t * src_addr, uint8_t * dst_addr, size_t length, uint8_t word_size)
{
    // clocking DMA & DMAMUX
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
    // end

    // configuring DMA_DCR0 for memory to memory
    DMA_DCR0 |= DMA_DCR_SINC_MASK |     // increase source pointer
                DMA_DCR_DINC_MASK |     // increase destination pointer
                DMA_DCR_DSIZE_MASK |    // masking the destination size
                DMA_DCR_SSIZE_MASK;     // masking the source size
    // end

    // setting the DSIZE and SSIZE based on word_size
    if(word_size==1)
        DMA_DCR0 &= ~(0x10<<20 | 0x10<<17);
    else if(word_size==2)
    {
        src_addr = (uint16_t *) src_addr;       // casting src address to 2 byte
        dst_addr = (uint16_t *) dst_addr;       // casting dst address to 2 byte
        DMA_DCR0 &= (0x01<<20 | 0x01<<17);
    }
    else if(word_size==4)
    {
        src_addr = (uint32_t *) src_addr;       // casting src address to 4 byte
        dst_addr = (uint32_t *) dst_addr;       // casting dst address to 4 byte
        DMA_DCR0 &= (0x11<<20 | 0x11<<17)
    } // end

    // configuring addresses 
    DMA_SAR0 |= src_addr;
    DMA_DAR0 |= dst_addr;
    // end

    DMA_DCR0 |= DMA_DCR_START_MASK;     // starting the dma
}


memzero_dma(uint8_t * src_addr, uint8_t word_size)
{
    uint8_t x = 0; // defining a variable having zero value

    // clocking DMA & DMAMUX
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
    // end

    // configuring DMA_DCR0 for memory to memory
    DMA_DCR0 |= DMA_DCR_DINC_MASK |     // increase destination pointer
                DMA_DCR_DSIZE_MASK |    // masking the destination size
                DMA_DCR_SSIZE_MASK;     // masking the source size
    DMA_DCR0 &= ~DMA_DCR_SINC_MASK;     // stopping source increment
    // end


    // setting the DSIZE and SSIZE based on word_size
    if(word_size==1)
        DMA_DCR0 &= ~(0x10<<20 | 0x10<<17);
    else if(word_size==2)
    {
        x = (uint16_t) x;
        x=0;
        src_addr = (uint16_t *) src_addr;       // casting src address to 2 byte
        DMA_DCR0 &= (0x01<<20 | 0x01<<17);
    }
    else if(word_size==4)
    {
        x = (uint32_t) x;
        x = 0;
        src_addr = (uint32_t *) src_addr;       // casting src address to 4 byte
        DMA_DCR0 &= (0x11<<20 | 0x11<<17)
    } // end

    // configuring addresses 
    DMA_SAR0 |= &x;
    DMA_DAR0 |= dst_addr;
    // end

    DMA_DCR0 |= DMA_DCR_START_MASK;     // starting the dma
}
