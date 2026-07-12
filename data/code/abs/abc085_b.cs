using System;
using System.Linq;

namespace AtcoderPractice;

public class Program
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int ans = Enumerable.Range(0, n)
            .Select(_=>Console.ReadLine())
            .Distinct()
            .Count();
        Console.WriteLine(ans);
    }
}