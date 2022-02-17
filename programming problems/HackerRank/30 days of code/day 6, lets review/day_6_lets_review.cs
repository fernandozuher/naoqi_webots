using System;

class Solution {
    static void Main(String[] args) {

        for (string word = Console.ReadLine(); (word = Console.ReadLine()) != null; ) {
            
            var word1 = new System.Text.StringBuilder("");
            var word2 = new System.Text.StringBuilder("");
            var flag = true;

            foreach (var ch in word) {
                if (flag)
                    word1.Append(ch);
                else
                    word2.Append(ch);
                flag = !flag;
            }
            Console.WriteLine($"{word1} {word2}");
        }
    }
}
