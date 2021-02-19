import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();

        int len1 = str1.length();
        int len2 = str2.length();

        int count = 0;
        int start = 0;
        while (start < len1 && start < len2 && str1.charAt(start) == str2.charAt(start)) {
            count += 1;
            start += 1;
        }
        while (start < len1 && start < len2 && str1.charAt(len1 - 1) == str2.charAt(len2 - 1)) {
            count += 1;
            len1 -= 1;
            len2 -= 1;
        }

        System.out.println(count + longest_common_subsequence(str1, len1, str2, len2, start));
    }

    private static int longest_common_subsequence(String str1, int len1, String str2, int len2, int start) {
        // we only need the last two rows to solve the problem, we will use the two
        // rows interchangeably
        int table[][] = new int[2][len2 - start + 1];
        int row = 1;

        for (int i = 0; i < len1 - start; i++) {
            for (int j = 0; j < len2 - start; j++) {
                if (str1.charAt(start + i) == str2.charAt(start + j)) {
                    table[row][j + 1] = table[1 - row][j] + 1;
                }
                else {
                    table[row][j + 1] = Math.max(table[row][j], table[1 - row][j + 1]);
                }
            }
            row = (row + 1) % 2;
        }


        return table[1 - row][len2 - start];
    }
}
