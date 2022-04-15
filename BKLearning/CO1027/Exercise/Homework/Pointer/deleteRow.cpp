/*
Given a dynamic two-dimensional array of size r x c. 
Implement the function 
        bool deleteRow(int**& matrix, int r, int c, int row) 
that can remove a row from the matrix.

Input: 
    The two-dimensional matrix of size r x c and the remove position row.

Output: 
    The two-dimensional matrix after removing the row.

Note: 
    If the final row of the matrix is removed, the matrix parameter will return nullptr value 
    as well as deallocate the memory previously used by the matrix.
*/

bool deleteRow(int**& matrix, int r, int c, int row) 
{
    if ((r<=0 or c<=0) or (row >=r) or row<0){ 
        matrix=nullptr;
        delete []matrix;
        return 0;
    }else{
        if(r == 1) {
            matrix = nullptr;
            delete []matrix; 
            return 1;
        }else{
            for( int i=row ; i < r ; i++)
               matrix[i] = matrix[i+1];
            return 1;
         }
    }
}

int main(){
    
}