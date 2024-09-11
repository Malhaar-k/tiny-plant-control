#include <iostream>
#include "tf_descrete.h"
#include "tf_statespace.h"
#include "matrix_helper.h"
#include <stdio.h>

#include <chrono>
#include <fstream>

template <typename T>

void writeFloatToCSV(T value, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << value << ",";
        file.close();
    } else {
        std::cout << "Failed to open file: " << filename << std::endl;
    }
}


int main(){


    // State space tests
    float A_data[]  = {-1.0, -2.0, 1.0, 0.0};
    float B_data[] = {2, 0};
    float C_data[] = {0.5, 1};

    std::chrono::_V2::system_clock::time_point begin, end, loopTime; 

    mat_s * A = mat_new_filled_matrix(2, 2, A_data);
    mat_s * B = mat_new_filled_matrix(2, 1, B_data);   
    mat_s * C = mat_new_filled_matrix(1, 2, C_data);
    mat_s * D = mat_zeros(1, 1);

    // mat_print(A, 2);
    // mat_print(B, 2);
    // mat_print(C, 2);
    // mat_print(D, 2);

    tfStateSpace::tfStateSpace_t mySS = tfStateSpace::tfStateSpace_t(A, B, C, D);
    mat_s * U = mat_zeros(1,1);
    mat_s * Y = mat_zeros(1,1);


    for(int i = 0; i < 1000; i++){
        if(i == 2){
            U->data[0] = 2.0;
        }

        begin = std::chrono::high_resolution_clock::now();
        Y = mySS.tfGetOutput(U, 0.01);
        end = std::chrono::high_resolution_clock::now();

        loopTime += end - begin;
        printf("Y: %f, U: %f, step: %d \n", Y->data[0], U->data[0], i);
        
        writeFloatToCSV<float>(Y->data[0], "output.csv");

    }

    std::chrono::duration<double> timeTaken = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
    unsigned long totalMemory = sizeof(mySS) + sizeof(*U) + sizeof(*Y);

    printf("Total Memory used: %lu\n", totalMemory);
    printf("Total time taken: %lf\n", timeTaken.count()); // This is zero. So it won't exactly be slow.
    return 0; 
}