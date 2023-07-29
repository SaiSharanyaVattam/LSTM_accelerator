#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"

#define AXI_BASEADDR 0x43C00000   // Replace with the base address of your AXI Lite port
#define DATA_OFFSETARR  0x10
#define DATA_OFFSETOUT_PUT 0x18// Replace with the offset of the data register
#define DATA_OFFSETLY1  0x20
#define DATA_OFFSETLY2  0x28
#define DATA_OFFSETLY3  0x30
#define CONTROL_OFFSET 0x00       // Replace with the offset of the control register


int main()
{
#include "lstmip1_wly1.txt"
#include "lstmip1_wly2.txt"
#include "lstmip1_wly3.txt"

    float *arr = (float *)XPAR_PS7_DDR_0_S_AXI_BASEADDR;
    float out_put = (float *)(XPAR_PS7_DDR_0_S_AXI_BASEADDR + 4 sizeof(float));
    float *ly1 = (float *)(XPAR_PS7_DDR_0_S_AXI_BASEADDR + 8 * sizeof(float));
    float *ly2 = (float *)(XPAR_PS7_DDR_0_S_AXI_BASEADDR + 104 * sizeof(float));
    float ly3 = (float *)(XPAR_PS7_DDR_0_S_AXI_BASEADDR + 160 sizeof(float));


    arr[0]=1.0;arr[1]=2.0;arr[2]=3.0;arr[3]=4.0;

    for(int i=0;i<96;i++){
    *(ly1 + i*sizeof(float))=lyy1[i];
    }
    for(int i=0;i<56;i++){
    *(ly2+ i*sizeof(float))=lyy2[i];
    }
    for(int i=0;i<3;i++){
    *(ly3+ i*sizeof(float))=lyy3[i];
    }
    for(int i=0;i<4;i++)
    {
    	out_put[i] = 3.0;
    }
/*
for(int i=0;i<96;i++)
{
	printf("%f\n",*(ly1 + i*sizeof(float)));
}*/
    Xil_DCacheFlush();
    Xil_DCacheInvalidate();
    printf("***********************************************************************");
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETARR, arr);
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETLY1, ly1);
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETLY2, ly2);
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETLY3, ly3);
       Xil_Out32(AXI_BASEADDR + DATA_OFFSETOUT_PUT, out_put);

       printf("the starting control reg is %d \n",Xil_In32(AXI_BASEADDR + 0x00));

       // Trigger the operation by setting the control bit
       Xil_Out32(AXI_BASEADDR + CONTROL_OFFSET, 0x1);
     //  printf("the control reg is %d \n",Xil_In32(AXI_BASEADDR + 0x00));

        while (Xil_In32(AXI_BASEADDR + 0x00)!=4 )
       {
        	printf("the control reg is %d \n",Xil_In32(AXI_BASEADDR + 0x00));
        printf("running  \n");
       }

        while (Xil_In32(AXI_BASEADDR + 0x00)!=4 )
       {
        	printf("the control reg is %d \n",Xil_In32(AXI_BASEADDR + 0x00));
        printf("running  \n");
       }
        printf("the control reg is %d \n",Xil_In32(AXI_BASEADDR + 0x00));
for(int i=0;i<4;i++){
       printf("\nthe output is ");
       printf("%f",out_put[i]);
       printf("the control reg is %f \n",Xil_In32(AXI_BASEADDR + DATA_OFFSETOUT_PUT));


}
       return 0;
    }
