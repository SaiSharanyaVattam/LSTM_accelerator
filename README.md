Long Short-Term Memory (LSTM) networks, a type of recurrent neural network (RNN) that has proven effective in processing sequential data. In this project, we aim to implement an LSTM model on the Zed board, a versatile platform that combines the power of FPGA and ARM processor cores, to explore its capabilities in handling time-series data and sequential tasks. we leverage the Zed board, which incorporates the Xilinx Zynq-7000 All Programmable SoC, offering a unique combination of FPGA and ARM processor cores. This platform provides both hardware flexibility and computational power, making it ideal for implementing complex algorithms like LSTMs. By utilizing the FPGA for parallel processing and the ARM processor for control and data management, we aim to create a hardware-software co-design that optimizes the LSTM model's performance and resource utilization.![image](https://github.com/SaiSharanyaVattam/LSTM_accelerator/assets/129647350/d2fdd5d8-f746-49e1-b80e-b38ad8ac51d7)

where xt denotes input value at current time step; ht−1 denotes output value
 of hidden layer at previous time step; W denotes corresponding weights in the
 connection and b denotes a bias to be added to the result of sum of weighted inputs;
 ¤ denotes element-wise multiplication; σ denotes sigmoid function. And it, ft, ot,
 gt and ct are the activated result of input gate, forget gate, output gate, cell input
 and cell activation respectively.
