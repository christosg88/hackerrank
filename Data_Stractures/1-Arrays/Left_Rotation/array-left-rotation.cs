using System;
using System.Linq;

class Program
{
	static void Main(string[] args)
	{
		string[] line = Console.ReadLine().Split(' ');
		int count = Int32.Parse(line[0]);
		int left_rotations = Int32.Parse(line[1]) % count;
		line = Console.ReadLine().Split(' ');
		int[] nums = line.Select(x => Int32.Parse(x)).ToArray();

		for (int i = 0; i < nums.Length; i++)
		{
			Console.Write(nums[(i + left_rotations) % count] + " ");
		}
	}
}
