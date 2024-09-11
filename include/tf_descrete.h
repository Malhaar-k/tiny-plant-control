#ifndef _TF_DESCRETE_H_
#define _TF_DESCRETE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>

namespace tfDescrete {
    class tfDescrete{
        private:
            float * inputs;
            float * outputs;
        public: 
            uint8_t uOrder;
            uint8_t yOrder;
            float * uCoeffs;
            float * yCoeffs;

        
        public:
            tfDescrete(uint8_t uOrder, uint8_t yOrder, float * uCoeffs, float * yCoeffs);
            ~tfDescrete();
            float tfGenerateOutput(float input); // I don't like this

        private: 
            void _pushInput(float output);
            void _pushOutput(float output);


    };

}

#ifdef __cplusplus
}
#endif

#endif