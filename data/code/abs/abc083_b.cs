using System;
using System.Linq;

namespace AtcoderPractice;

public class Program
{
    public static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ').Select(i=>int.Parse(i)).ToArray();
        int n = input[0], a = input[1], b = input[2];

        int ans = Enumerable.Range(0,n+1)
            .Where(i=>
            {
                int sum = i.ToString().Sum(c => c - '0');
                return a <= sum && sum <= b;
            }).Sum();
        Console.WriteLine(ans);
    }
}