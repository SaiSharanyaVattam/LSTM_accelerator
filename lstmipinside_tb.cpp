#include <stdio.h>
#include <cmath>
#include<fstream>
void lstmipinside(float* arr, float *out_put);
int main() {
float out_put[3];
FILE *inp;
float line;
float arr_in[100];

inp   = fopen("C:\\Users\\HP\\lstm_final\\lstmip1_input.txt","r");
int i=0;
while(fscanf(inp,"%f",&line)==1){
arr_in[i]=line;
i++;}
fclose(inp);

lstmipinside(arr_in,out_put);
for(int y=0;y<3;y++){
printf("Predicted Output: %f\n",out_put[y]);
}
return 0;
}
