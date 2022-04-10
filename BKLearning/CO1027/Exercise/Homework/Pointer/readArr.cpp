/*
Implement the function readArray() that is declared as below syntax:


int** readArray()

The function reads a two-dimensional matrix each of which consists of 10 elements. These elements are entered from the keyboard (from a[0][0] to a[9][9]). If a[i][j] is assigned to 0, all remained element of the row (a[i][k], j<k<10) will automatically assigned to 0, and the function will continue to input the next-row element from the keyboard. Moreover, this function also returns a pointer which points to the two-dimensional matrix just entered.

Input:  The positive integer matrix's elements which not surpass 1000.

Output: The pointer that points to  the two-dimensional matrix just entered.
*/

int** readArray()
{
   //TODO
    int** arr = new int*[10];
    for ( int i = 0; i < 10; i++ )
        arr[i] = new int[10];
        
    for ( int i = 0; i < 10; i++ )
        for ( int j = 0; j < 10; j++ )
        {
            cin >> arr[i][j];
            if ( arr[i][j] == 0 )
            {
                for ( int k = j; k < 10; k++ )
                    arr[i][k] = 0;
                break;
            }
        }
    return arr;
}

