using System;
using System.Collections.Generic;
using System.IO.IsolatedStorage;
using System.Linq;
using System.Numerics;
using System.Reflection.Metadata.Ecma335;
using AtCoder;

class Program
{
    static void Main(string[] args)
    {
        int h = ConsoleEx.ReadInt();
        int w = ConsoleEx.ReadInt();
        string[] s = ConsoleEx.ReadStringArray(h);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] != '#') continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + Dist.di[k];
                    int nj = j + Dist.dj[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w)
                    {
                        if (s[ni][nj] == '#') cnt++;
                    }
                }

                if (cnt==0||cnt%2==1)
                {
                    ConsoleEx.WriteLine("No");
                    ConsoleEx.Flush();
                    return;
                }
            }
        }
        ConsoleEx.WriteLine("Yes");
        ConsoleEx.Flush();
    }
}

public static class Dist
{
    public static readonly int[] di = { -1, 0, 1, 0 };
    public static readonly int[] dj = { 0, 1, 0, -1 };
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

    public static string[] ReadStringArray(int n)
    {
        var a = new string[n];
        for (int i = 0; i < n; i++) a[i] = Read();
        return a;
    }

    public static void Write(object obj) => _streamWriter.Write(obj);
    public static void WriteLine(object obj) => _streamWriter.WriteLine(obj);
    public static void Flush() => _streamWriter.Flush();
}