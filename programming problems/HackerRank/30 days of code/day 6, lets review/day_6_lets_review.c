#include <stdio.h>
#include <stdbool.h>

int main() {

    int n;
    scanf("%d", &n);

    for (char word[10000]; scanf("%s", word) != EOF; ) {
        
        char word1[5001], word2[5001];
        int size_word1 = 0, size_word2 = 0;
        bool flag = true;

        for (int i = 0; word[i] != '\0'; ++i, flag = !flag)
            flag ? (word1[size_word1++] = word[i]) : (word2[size_word2++] = word[i]);
        
        word1[size_word1] = word2[size_word2] = '\0';
        printf("%s %s\n", word1, word2);
    }
    return 0;
}
