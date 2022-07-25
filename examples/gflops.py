#!/usr/bin/env python3
import time
import numpy as np

N = 2048

A = np.random.rand(N,N) * 10
B = np.random.rand(N,N) * 10

total_number_of_flop = N * N * (2 * N - 1)
if __name__ == "__main__":
    start = time.time()
    matMul = A @ B
    #print(A @ B)
    end = time.time()
    flops = total_number_of_flop / (float) (end - start)
    gFlops = flops / 1e9
    print("Gflops:",gFlops)
