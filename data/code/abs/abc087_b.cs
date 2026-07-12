using System;
using System.Linq;

namespace AtcoderPractice;

public class Program
{
    public static void Main(string[] args)
    {
        if (!int.TryParse(Console.ReadLine(), out int a))
        {
            Console.WriteLine("error");
        }
        if (!int.TryParse(Console.ReadLine(), out int b))
        {
            Console.WriteLine("error");
        }
        if (!int.TryParse(Console.ReadLine(), out int c))
        {
            Console.WriteLine("error");
        }
        if (!int.TryParse(Console.ReadLine(), out int x))
        {
            Console.WriteLine("error");
        }
        int ans = (
            from i in Enumerable.Range(0, a + 1)
            from j in Enumerable.Range(0, b + 1)
            from k in Enumerable.Range(0, c + 1)
            where 500 * i + 100 * j + 50 * k == x
            select 1
            ).Count();
        Console.WriteLine(ans);
    }
}