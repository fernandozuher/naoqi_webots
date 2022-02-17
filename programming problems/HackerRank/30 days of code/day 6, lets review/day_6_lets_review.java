import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        
        var scanner = new Scanner(System.in);

        for (var word = scanner.nextLine(); scanner.hasNextLine(); ) {

            word = scanner.nextLine();
            var word1 = new StringBuffer();
            var word2 = new StringBuffer();

            boolean flag = true;
            for (var ch : word.toCharArray()) {
                if (flag)
                    word1.append(ch);
                else
                    word2.append(ch);
                flag = !flag;
            }
            System.out.println(word1.toString() + " " + word2.toString());
        }
    }
}
