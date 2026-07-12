using System;
using System.Linq;

namespace AtcoderPractice;

public class Program
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(int.Parse).OrderDescending().ToArray();
        Console.WriteLine(a.Select((num,ind)=>ind%2==0?num:-num).Sum());
    }
}