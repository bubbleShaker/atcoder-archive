using System;
using System.Linq;

namespace AtcoderPractice;

public class Program
{
    public static void Main(string[] args)
    {
        string?[]? input = Console.ReadLine()?.Split(' ');
        var a = int.Parse(input?[0] ?? string.Empty);
        var b = int.Parse(input?[1] ?? string.Empty);
        Console.WriteLine((a * b) % 2 == 0 ? "Even" : "Odd");
    }
}