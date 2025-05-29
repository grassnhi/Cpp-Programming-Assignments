void normalize(char str[], char outstr[]) {
    int len = strlen(str);
    int i = 0, j = 0;

    // Bỏ khoảng trắng đầu
    while (i < len && str[i] == ' ') i++;

    bool inWord = false;

    while (i < len) {
        if (str[i] != ' ') {
            outstr[j++] = str[i];
            inWord = true;
        } else if (inWord) {
            // Nếu gặp khoảng trắng sau 1 từ, chèn đúng 1 space
            outstr[j++] = ' ';
            inWord = false;

            // Bỏ các khoảng trắng tiếp theo
            while (i + 1 < len && str[i + 1] == ' ') i++;
        }
        i++;
    }

    // Xóa khoảng trắng cuối nếu có
    if (j > 0 && outstr[j - 1] == ' ') j--;

    outstr[j] = '\0';
}