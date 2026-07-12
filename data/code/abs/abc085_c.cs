using System;
using System.Linq;

namespace AtcoderPractice;

public class Program
{
    public static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(" ").Select(int.Parse).ToArray();
        int n = input[0], y = input[1];
        var ans = (
            from i in Enumerable.Range(0, n + 1)
            from j in Enumerable.Range(0, n + 1 - i)
            let k = n - i - j
            where 10000 * i + 5000 * j + 1000 * k == y
            select new[] { i, j, k }
        ).ToArray();
        if (ans.FirstOrDefault() != null)
        {
            var a = ans[0];
            Console.WriteLine($"{a[0]} {a[1]} {a[2]}");
        }
        else
        {
            Console.WriteLine("-1 -1 -1");
        }
    }
}