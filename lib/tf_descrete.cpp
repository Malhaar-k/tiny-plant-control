#include "tf_descrete.h"
#include <stdint.h>
#include <string.h>

namespace tfDescrete {
    tfDescrete::tfDescrete(uint8_t uOrder, uint8_t yOrder, float * uCoeffs, float * yCoeffs){
        this->uOrder = uOrder;
        this->yOrder = yOrder;
        this->uCoeffs = uCoeffs;
        this->yCoeffs = yCoeffs;
        this->inputs = new float[uOrder];
        this->outputs = new float[yOrder];
        memset(this->inputs, 0, uOrder*sizeof(float));
        memset(this->outputs, 0, yOrder*sizeof(float));

    }

    tfDescrete::~tfDescrete(){
        delete[] this->inputs;
        delete[] this->outputs;
    }

    float tfDescrete::tfGenerateOutput(float input){
        // Push the input to the input array
        _pushInput(input);
        // Generate the output
        float output = 0;
        for(int i = 0; i < this->uOrder; i++){
            output += this->uCoeffs[i]*this->inputs[i];
        }
        for(int i = 0; i < this->yOrder; i++){
            output += this->yCoeffs[i]*this->outputs[i];
        }
        // Push the output to the output array
        _pushOutput(0);
        return output;
    }

    void tfDescrete::_pushInput(float input){
        // Push the input
        for(int i = this->uOrder-1; i > 0; i--){
            this->inputs[i] = this->inputs[i-1];
        }
        this->inputs[0] = input;
    }
    
    void tfDescrete::_pushOutput(float output){
        // Push the output
        for(int i = this->yOrder-1; i > 0; i--){
            this->outputs[i] = this->outputs[i-1];
        }
        this->outputs[0] = output;
    }
}