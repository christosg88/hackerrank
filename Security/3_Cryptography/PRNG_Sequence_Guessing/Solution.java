import java.io.*;
import java.util.Random;
import java.util.Vector;

public class Solution
{
    public static void main(String[] args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try
        {
            int testcases = Integer.parseInt(br.readLine());

            for (int test = 0; test < testcases; test++)
            {
                String[] str_nums = br.readLine().split(" ");
                long start = Long.parseLong(str_nums[0]);
                long end = Long.parseLong(str_nums[1]);

                Vector<Integer> nums = new Vector<Integer>();
                for (int i = 0; i < 10; ++i)
                {
                    nums.add(Integer.parseInt(br.readLine()));
                }

                for (long seed = start; seed <= end; seed++)
                {
                    Random rnd = new Random(seed);
                    boolean foundSeed = true;
                    for (int i = 0; i < 10; ++i)
                    {
                        if (rnd.nextInt(1000) != nums.get(i))
                        {
                            foundSeed = false;
                            break;
                        }
                    }

                    if (foundSeed)
                    {
                        System.out.print(seed + " ");
                        for (int i = 0; i < 10; ++i)
                        {
                            System.out.print(rnd.nextInt(1000) + " ");
                        }
                        System.out.println();
                    }
                }
            }
        }
        catch (IOException e)
        {
            System.out.println(e.toString());
        }
    }
}
