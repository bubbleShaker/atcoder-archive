using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using AtCoder;

class Program
{
    static void Main(string[] args)
    {
        string s = ConsoleEx.Read();
        int i = (int)Char.GetNumericValue(s[0]), j = (int)Char.GetNumericValue(s[2]);
        if (j != 8)
        {
            ConsoleEx.WriteLine(i+"-"+(j+1));
        }
        else
        {
            ConsoleEx.WriteLine((i+1)+"-"+1);
        }
        ConsoleEx.Flush();
    }
}

/// <summary>
/// Fast I/O for competitive programming
/// </summary>
public static class ConsoleEx
{
    private static readonly System.IO.StreamReader _streamReader = new System.IO.StreamReader(Console.OpenStandardInput());
    private static readonly System.IO.StreamWriter _streamWriter = new System.IO.StreamWriter(Console.OpenStandardOutput());
    private static string[] _input = new string[0];
    private static int _index = 0;

    public static string ReadLine() => _streamReader.ReadLine();

    public static string Read()
    {
        if (_index >= _input.Length)
        {
            _input = ReadLine().Split(' ');
            _index = 0;
        }
        return _input[_index++];
    }

    public static int ReadInt() => int.Parse(Read());
    public static long ReadLong() => long.Parse(Read());
    public static double ReadDouble() => double.Parse(Read());
    public static BigInteger ReadBigInteger() => BigInteger.Parse(Read());

    public static int[] ReadIntArray(int n)
    {
        var a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ReadInt();
        return a;
    }

    public static long[] ReadLongArray(int n)
    {
        var a = new long[n];
        for (int i = 0; i < n; i++) a[i] = ReadLong();
        return a;
    }

    public static void Write(object obj) => _streamWriter.Write(obj);
    public static void WriteLine(object obj) => _streamWriter.WriteLine(obj);
    public static void Flush() => _streamWriter.Flush();
}