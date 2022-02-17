package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {

    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    scanner.Text()

    for scanner.Scan() {
        
        var word1, word2 strings.Builder
        flag := true

        for _, ch := range scanner.Text() {
            if flag {
                word1.WriteString(string(ch))
            } else {
                word2.WriteString(string(ch))
            }
            flag = !flag
        }
        fmt.Println(word1.String(), word2.String())
    }
}
