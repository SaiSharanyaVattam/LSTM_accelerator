#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"

#define AXI_BASEADDR 0x43C00000   // Replace with the base address of your AXI Lite port
#define DATA_OFFSETARR  0x10
#define DATA_OFFSETOUT_PUT 0x18// Replace with the offset of the data register
#define CONTROL_OFFSET 0x00       // Replace with the offset of the control register


int main()
{
#include "input.txt"

    float *arr = (float *)XPAR_PS7_DDR_0_S_AXI_BASEADDR;
    float out_put = (float *)(XPAR_PS7_DDR_0_S_AXI_BASEADDR + 4*sizeof(float));

    for(int i=0;i<32;i++){
    *(arr + i*sizeof(float))=arrt[i];// From input.txt
    }

    Xil_DCacheFlush();
    Xil_DCacheInvalidate();
    printf("***********************************************************************");
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETARR, arr);
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETOUT_PUT, out_put);


       // Trigger the operation by setting the control bit
       Xil_Out32(AXI_BASEADDR + CONTROL_OFFSET, 0x1);

        while (Xil_In32(AXI_BASEADDR + 0x00)!=4 )
       {
        printf("running  \n");
       }
        
for(int i=0;i<4;i++){
       printf("\nthe output is ");
       printf("%f",out_put[i]);;
}
       return 0;
    }
