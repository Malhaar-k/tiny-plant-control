#ifndef      __MAT_HELPER_H_
#define     __MAT_HELPER_H_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>


//Defines 
#define MAT_SIZE(x)         (x->rows*x->cols) //This is a shitty define
#define MAT_INDEX(x,r,c)    (r*x->cols + c)
#define u8                  uint8_t
#define FORIN(x,y)         for(int x = 0; x< y; x++) //This is a lazy define that I like


struct mat_s{
    float* data;
    u8 rows;
    u8 cols;
};

/// @brief Matrix struct. We are dealing with heaps smh but no choice now.
/// @note Uses 1 indexing instead of 0 indexing due to matrix conventions
typedef struct mat_s mat_s;
               
//Creation
// I am assuming all the matrices will be <= 255*255. Changing isn't too hard tho
// TODO:- matrix multiplication

/// @brief Create a matrix :)
/// @param row 
/// @param cols 
/// @return 
mat_s* mat_new_matrix(uint8_t row, uint8_t cols); 

/// @brief Make a new array filled with a flattened version of the matrix you want.
//  Arrange the array as [row1, row2, row3, ...], i.e., Rows arranged successively
/// @param row Number of rows
/// @param col Number of coloumns
/// @param arr Flattened array 
/// @return The new matrix 
mat_s* mat_new_filled_matrix(u8 row, u8 col, float* arr);

/// @brief 
/// @param mat 
/// @return 
mat_s* mat_duplicate(mat_s * mat);

/// @brief 
/// @param size 
/// @return 
mat_s* mat_ident(uint8_t size); // I is always square I'm pretty sure

/// @brief 
/// @param row 
/// @param cols 
/// @return 
mat_s* mat_ones(uint8_t row, uint8_t cols);

/// @brief 
/// @param row 
/// @param cols 
/// @return 
mat_s* mat_zeros(uint8_t row, uint8_t cols);

/// @brief Get the value of a matrix at a given position.
/// @param mat 
/// @param row 
/// @param col 
/// @return 
/// @note We use 1 indexing and not 0 indexing 
float mat_get(mat_s* mat, uint8_t row, uint8_t col);

/// @brief Set the value of a matrix at a given position.
/// @param mat 
/// @param row 
/// @param col 
/// @return 
/// @note We use 1 indexing and not 0 indexing
int mat_set(mat_s* mat, uint8_t row, uint8_t col, float val);

/// @brief Get a row of a matrix
/// @param imat 
/// @param row_num The row number to be extracted
/// @return Extraced row
float * mat_get_row(mat_s * imat, u8 row_num);

/// @brief Set the value of a row in a matrix
/// @param mat matrix to mutate
/// @param row This data gets appended as the row
/// @param row_num Index of the row to append
/// @note We use 1 indexing and not zero indexing 
/// @param size Size of row to append
/// @return -1 on failure
int mat_set_row(mat_s* mat, float* row, uint8_t row_num, uint8_t size);

/// @brief Get a coloumn of a matrix 
/// @param imat 
/// @param col_num The coloumn number to be extracted 
/// @return Extracted coloumn
float * mat_get_col(mat_s* imat, u8 col_num);

/// @brief Set the value of a coloumn in a matrix
/// @param mat matrix to mutate
/// @param col This data gets appended as the coloumn
/// @param col_num Index of the coloumn to append
/// @note We use 1 indexing and not zero indexing 
/// @param size Size of coloumn to append
/// @return -1 on failure
int mat_set_col(mat_s* mat, float* col, uint8_t col_num, uint8_t size);

/// @brief Print out the matrix
/// @param mat The matrix that needs to be printed
/// @param prec Precision of the printing for (Length of float to print)
/// @return 
int mat_print(mat_s* mat, int prec);

/// @brief Delete matrix and the data inside
/// @param ip 
void mat_delete(mat_s * ip);


// Single matrix operations

/// @brief Get a copy of the transpose of a matrix
/// @param mat This matrix will be transposed
/// @return 
mat_s* mat_trans_copy(mat_s * mat);

/// @brief Get the minor of the input matrix without a specified coloumn and row
/// @param imat Input matrix
/// @param drow Row to be deleted 
/// @param dcol Coloumn to be deleted
/// @return `mat_s *` Minor matrix
mat_s * mat_get_minor(mat_s* imat, uint8_t drow, uint8_t dcol);

/// @brief 
/// @param imat 
/// @return NULL if matrix is not invertible;
mat_s* mat_inv_copy(mat_s* imat);


// Scalar stuff 
/// @brief Multiply all elements of the matrix with a value.
/// @param mat Said matrix in question
/// @param gain Value to scale all the elements with
/// @return Fails to -1 when matrix is NULL
int mat_scal_mult(mat_s* mat, float gain); // Control system homies

/// @brief 
/// @param mat 
/// @return 
float mat_get_det(mat_s* mat);

/// @brief 
/// @param imat 
/// @return 
mat_s * mat_get_adjoint(mat_s* imat);



//Two matrix operations

/// @brief Multiplies two matrices in the following order: A*B
/// @param mata Matrix A
/// @param matb Matrix B 
/// @return Resultant matrix
mat_s * mat_mult(mat_s * mata, mat_s * matb);

/// @brief Performs A + B
/// @param mata 
/// @param matb 
/// @return Resultant matrix
mat_s * mat_add( mat_s * mata, mat_s * matb, mat_s * result);


/// @brief WIP DO NOT USE
/// @param mata 
/// @param matb 
/// @return 
mat_s * mat_mult_strassen(mat_s * mata, mat_s * matb);

/// @brief Concatenate two matrices horizontally 
/// @param mata Matrix on the left
/// @param matb Matrix on the right
/// @return `mat_s *` Resulting matrix
mat_s * mat_cat_hor(mat_s* mata, mat_s * matb);

/// @brief Concatenate two matrices vertically 
/// @param mata Matrix on the top
/// @param matb Matrix on the bottom
/// @return `mat_s *` Resulting matrix
mat_s * mat_cat_ver(mat_s* mata, mat_s * matb);


#ifdef __cplusplus
}
#endif

#endif

