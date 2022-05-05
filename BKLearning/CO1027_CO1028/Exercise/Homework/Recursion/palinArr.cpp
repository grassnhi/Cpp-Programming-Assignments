int checkPalindrome(int *arr, int n)
{
    
    if (n == 0 || n == 1) {
        return true;
    }
    if (*arr == *(arr + (n-1))) {
        return checkPalindrome(*arr+1, n-2);
    }
    else {
        return false;
    }
}
