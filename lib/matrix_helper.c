/*


*/

// Std inlcudes
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// Pvt inlcudes
#include "matrix_helper.h"


// Function just for this file. Allowing me to be lazy tbh 

void swap(float arr[], uint8_t index1, uint8_t index2) {
    float temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

float mul_and_sum(float * arr1, float * arr2, u8 len ){
    float ret_val = 0;
    FORIN(x,len){
        ret_val += arr1[x]*arr2[x];
        // printf("\n current mul : %.1lf , %.1lf  Index: %d", arr1[x], arr2[x], x);
    }

    return ret_val;
}


mat_s* mat_new_matrix(uint8_t row, uint8_t col){
    mat_s* fn_mat = malloc(sizeof(mat_s));
    if(!fn_mat){
        printf("No more memory"); return fn_mat;
    }
        fn_mat->rows = row;
        fn_mat->cols = col;
        fn_mat->data = malloc(sizeof(float) * row* col);
    if(!fn_mat->data) {printf("No more memory"); return fn_mat;}
    return fn_mat;
}

// This might be more useful than I thought

mat_s* mat_new_filled_matrix(u8 row, u8 col, float* arr){
    mat_s* fm = mat_new_matrix(row, col);
    // Aise hi bore ho raha tha 
    uint32_t total_size = sizeof(float )*row*col;
    memcpy(fm->data, arr, total_size);

    return fm;
}


mat_s* mat_duplicate(mat_s * mat){
    mat_s * fnmat = mat_new_matrix(mat->rows, mat->cols); // This function's temp matrix
    for(int m = 0; m< MAT_SIZE(mat); m++){
        fnmat->data[m] = mat->data[m]; //Copying data
    }
    return fnmat;
}

mat_s* mat_ident(uint8_t size){ // I is always square I'm pretty sure
    mat_s* fnmat = mat_new_matrix(size, size);
    for(int m = 0; m < size; m++){
        fnmat->data[m+m*size] = 1;
    }
    return fnmat;
}

mat_s* mat_ones(uint8_t row, uint8_t col){
    mat_s* fnmat = mat_new_matrix(row, col);
    for(int m = 0; m < MAT_SIZE(fnmat); m++){
        fnmat->data[m] = 1;
    }
    return fnmat;
}

mat_s* mat_zeros(uint8_t row, uint8_t col){
    mat_s* fnmat = mat_new_matrix(row, col);
    for(int m = 0; m < MAT_SIZE(fnmat); m++){
        fnmat->data[m] = 0;
    }
    return fnmat;
}


float mat_get(mat_s* mat, uint8_t row, uint8_t col){
    uint8_t a_r = row -1; //Actual row. For 1 indexing
    uint8_t a_c = col -1; //Actual coloumn
    
    return mat->data[a_r*mat->cols + a_c];

}

int mat_set(mat_s* mat, uint8_t row, uint8_t col, float val){
    uint8_t a_r = row -1; //Actual row. For 1 indexing
    uint8_t a_c = col -1; //Actual coloumn
    

    if(mat->rows < a_r|| mat->cols < a_c){
        return -1;
    }
    else{
        mat->data[a_r*mat->cols + a_c] = val;
    }
    return 0;
}

float * mat_get_row(mat_s * imat, u8 row_num){
    u8 a_r = row_num -1;
    float * ret_arr = malloc(sizeof(float) * imat->rows);
    FORIN(c,imat->cols){
        ret_arr[c] = imat->data[MAT_INDEX(imat,a_r,c)];
    }
    return ret_arr;

}

int mat_set_row(mat_s* mat, float* row, uint8_t row_num, uint8_t size){
    uint8_t a_r = row_num -1;
    if(size > mat->cols) return -1;
    for(int m =0 ; m<size; m++){
        mat->data[MAT_INDEX(mat, a_r, m)] = row[m];
    }
    return 0;
}

float * mat_get_col(mat_s* imat, u8 col_num){
    u8 a_c = col_num -1;
    float * ret_arr = malloc(sizeof(float) * imat->rows);
    FORIN(r,imat->rows){
        ret_arr[r] = imat->data[MAT_INDEX(imat,r,a_c)];
    }
    return ret_arr;
}

int mat_set_col(mat_s* mat, float* col, uint8_t col_num, uint8_t size){
     uint8_t a_c = col_num -1;
    if(size > mat->rows) return -1;
    for(int m =0 ; m<size; m++){
        mat->data[MAT_INDEX(mat, m, a_c)] = col[m];
    }
    return 0;
}




int mat_print(mat_s* mat, int prec){
    if(mat == NULL) return -1;
    printf("\n");

    for(int r = 0; r< mat->rows; r++){
        for(int c = 0; c < mat->cols; c++){
            printf(" %.*lf |",prec,  mat->data[r*mat->cols + c]);
        }
        printf("\n");

    }
    return 0;
}


void mat_delete(mat_s * ip){
    free(ip->data);
    free(ip);
}


mat_s* mat_trans_copy(mat_s * mat){ // Not sure how to do it without copying it.
    mat_s * fnmat = mat_new_matrix(mat->cols, mat->rows);
    fnmat->rows = mat->cols;
    fnmat->cols = mat->rows;
    for(int r = 0; r < mat->rows; r++){
        for(int c = 0; c < mat->cols; c++){
            fnmat->data[MAT_INDEX(fnmat, c, r)] = mat->data[MAT_INDEX(mat, r, c)];
        }
    }

    return fnmat;
}


mat_s * mat_get_minor(mat_s* imat, uint8_t drow, uint8_t dcol){
    u8 a_r = drow-1; //Actual row. 1 Indexing
    u8 a_c = dcol-1;
    // I'm going to do something a little disgusting 
    u8 minor_r = 0;
    u8 minor_c = 0;
    
    // TODO := Add error checks here
    mat_s * fnmat = mat_new_matrix(imat->rows-1, imat->cols-1);
    for(int r = 0; r < imat->rows; r++){
        if(r == a_r) continue; // This row gets skipped because this is the one the function removes
        for(int c = 0; c < imat->cols; c++){
            if (c == a_c) continue; // Same with the coloum.
            fnmat->data[MAT_INDEX(fnmat,minor_r, minor_c)] = imat->data[MAT_INDEX(imat,r, c)];
            //printf("\n %d %d %d %d", r , c, minor_r, minor_c); //Debug statement. 
            minor_c ++ ;
        }
        minor_c = 0;
        minor_r++;
    }

    return fnmat;
}


mat_s* mat_inv_copy(mat_s* imat){
    /* 
    Formula: Ainv = Aadj/Adet
    Needed
    - Determinant => DONE
    - Adjoint => DONE
    */
    
    if(imat->cols != imat->rows){
        printf("Inverse failed: Matrix not square");
        return NULL;
    }

    // If determinant is 0, you gotta return.
    if( fabs(mat_get_det(imat)) <= __DBL_EPSILON__ ) return NULL; 

    
    mat_s * fnmat = mat_get_adjoint(imat);
    float det_val = 1/mat_get_det(imat);
    

    // Let's use a different function for creating an adjoint matrix



    mat_scal_mult(fnmat, det_val);
    return fnmat;
}



int mat_scal_mult(mat_s* mat, float gain){
    if(mat == NULL){return -1;}
    
    for(int m = 0; m < MAT_SIZE(mat); m++){
        mat->data[m] = mat->data[m]*gain;
    }
    return 0;
}

float mat_get_det(mat_s* imat){
    float det_value  = 0.0 ; //If not initialised this is going to cause weird asf problems lmao 
    float sign_to_add =1; //yes great name
    if(imat->rows != imat->cols){
    printf(" Determinant failed : Matrix not square");
    return __DBL_EPSILON__;
    }
    if(imat->rows ==1){
        return imat->data[0];
    }
    if(imat->rows == 2){
        // Please delete the code here late I beg. Do not forget
        // printf("\n%.1lf : %d", ((imat->data[0]*imat->data[3]) -(imat->data[1]*imat->data[2])), imat->rows); // Stinky debug statement
        return ((imat->data[0]*imat->data[3]) -(imat->data[1]*imat->data[2]));
    }
    
    // We gon parse through the first row aight?
    for(int c = 0; c < imat->cols; c ++){
        

        mat_s * temp_minor = mat_get_minor(imat, 1, c+1); //Create a minor array
        
        float temp_det = mat_get_det(temp_minor); // Get determinant of the minor array 
        
        mat_delete(temp_minor); // Delete the temporary minor array 
        
        // printf("\n Adding %.2lf to %.2lf", sign_to_add*temp_det*imat->data[c], det_value); // Stinky debug statement.DELETE

        det_value += sign_to_add*temp_det*imat->data[c]; //Append to determinant value based on the sign 
        
        // printf(" Result at %.2lf : %d", det_value, imat->rows); // Stinky debug statement
        // The above line was involved in debugging an error caused by my dumbass not initing a variable.

        sign_to_add = -sign_to_add; // Every other term needs to be subtracted. Basically (-1)**c
        
    }

    return det_value;
}

mat_s * mat_get_adjoint(mat_s* imat){
    mat_s * fm = mat_duplicate(imat);
    // Aij = (-1)**(i+j)|Mij|
    // We done with determinants luckily
    for(int r =0; r < imat->rows; r++){
        for(int c =0; c < imat->cols; c++){
            mat_s * temp_mat = mat_get_minor(imat, c+1, r+1);
            float det = mat_get_det(temp_mat);

            // Going to do something really ugly now please look away
            fm->data[MAT_INDEX(fm,r,c)] = (r+c)%2 == 1 ? -1*det : det;  //If the sum is even, assign the positive vale
                                                                        //If sum is odd, multiply with -1
            mat_delete(temp_mat);
        }
    }


    return fm;
}


//Two matrix operations

mat_s * mat_mult(mat_s * mata, mat_s * matb){
    if(mata->cols != matb->rows){
        printf("Not compatible for multiplication you donut");
        return NULL;
    }
    mat_s * fm = mat_new_matrix(mata->rows, matb->cols);
    
    FORIN(r, fm->rows){
        FORIN(c,fm->cols){
            float * r_vec = mat_get_row(mata, r+1);
            float * c_vec = mat_get_col(matb, c+1);    
            fm->data[MAT_INDEX(fm,r,c)] = mul_and_sum(r_vec, c_vec, mata->cols); 
            // I realise that using heap allocation is quite slow. But I CBA, I like using the struct instead
            // of a float **. 
            free(r_vec);
            free(c_vec);
        }
    }

    return fm;
}

// WIP 
// I just read how this ends up having the same time complexity as the brute force method. 
// So I guess this is just not worth lmao 
mat_s * mat_mult_strassen(mat_s * mata, mat_s * matb){
    printf("\e[1;31m THIS IS WIP AND ALSO NOT WORTH USING \e[0m");
    
    if(mata->cols != matb->rows){
        printf("Not compatible for multiplication you donut");
        return NULL;
    }
    mat_s * fm = mat_new_matrix(mata->rows, matb->cols);
    

    return fm;
}

/// @brief 
/// @param mata 
/// @param matb 
/// @return 
mat_s * mat_add( mat_s * mata, mat_s * matb, mat_s * result){
    if(mata->cols != matb->cols || mata->rows != matb->rows){
        printf("Not compatible for addition you donut");
        return NULL;
    }
    if( result != NULL){
        for(int r = 0; r < result->rows; r++){
        for(int c = 0; c < result->cols; c++){
            result->data[MAT_INDEX(result,r,c)] = mata->data[MAT_INDEX(mata, r, c)] + matb->data[MAT_INDEX(matb, r, c)];
        }
    }
    return NULL;
    
    }else{

    mat_s * fm = mat_new_matrix(mata->rows, mata->cols); 
    for(int r = 0; r < fm->rows; r++){
        for(int c = 0; c < fm->cols; c++){
            fm->data[MAT_INDEX(fm,r,c)] = mata->data[MAT_INDEX(mata, r, c)] + matb->data[MAT_INDEX(matb, r, c)];
        }
    }
    return fm;
    }
}

/// @brief Concatenate two matrices horizontally 
/// @param mata Matrix on the left
/// @param matb Matrix on the right
/// @return `mat_s *` Resulting matrix
mat_s * mat_cat_hor(mat_s* mata, mat_s * matb){
    u8 f_c = mata->cols + matb->cols;
    
    if(mata->rows != matb->rows) return NULL;
    
    mat_s * fm = mat_new_matrix(mata->rows, f_c);

    for(int r = 0; r < fm->rows; r++){
        for(int c = 0; c < fm->cols; c++){
            if(c < mata->cols){
                fm->data[MAT_INDEX(fm,r,c)] = mata->data[MAT_INDEX(mata, r, c)];
            }else{
                fm->data[MAT_INDEX(fm,r,c)] = mata->data[MAT_INDEX(matb, r, c+1-mata->cols)];
            }
        }


    }

    return fm;
}

/// @brief Concatenate two matrices vertically 
/// @param mata Matrix on the top
/// @param matb Matrix on the bottom
/// @return `mat_s *` Resulting matrix
mat_s * mat_cat_ver(mat_s* mata, mat_s * matb){
    u8 f_r = mata->rows + matb->rows;
    
    if(mata->cols != matb->cols) return NULL;
    
    mat_s * fm = mat_new_matrix(f_r,mata->cols);

    for(int r = 0; r < fm->rows; r++){
        for(int c = 0; c < fm->cols; c++){
            if(r < mata->rows){
                fm->data[MAT_INDEX(fm,r,c)] = mata->data[MAT_INDEX(mata, r, c)];
            }else{
                fm->data[MAT_INDEX(fm,r,c)] = mata->data[MAT_INDEX(matb, r+1-mata->rows, c)];
            }
        }


    }

    return fm;
}
