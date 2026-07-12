using System;
using System.Collections.Generic;
using System.Linq;

// AHC053 A - Random Sum Game: 等間隔アンカー + 2進調整カード（各ビットM枚）方式
// ・アンカー: [L, U] を端点含め等間隔に M 個配置
// ・Kビット調整: s = ceil(maxGap / ((1<<K)-1))、額面は s * 2^k を各 M 枚
// ・B は昇順に処理して「B以下の最大アンカー」を割当 → 残差を上位ビットから貪欲

public class Program
{
    public static void Main()
    {
        // ---- 1) 入力 ----
        long N = ConsoleEx.ReadLong();   // 500
        int M = (int)ConsoleEx.ReadLong(); // 50
        long L = ConsoleEx.ReadLong();
        long U = ConsoleEx.ReadLong();

        // K = (N - M) / M → 理想的に 9
        int K = (int)((N - M) / M);
        if (K <= 0) K = 1;

        // ---- 2) アンカー生成（端点含む等間隔、重複なし）----
        long range = U - L;
        var anchors = new long[M];
        for (int i = 0; i < M; i++)
        {
            // i=0 -> L, i=M-1 -> U
            anchors[i] = L + (range * i) / (M - 1);
        }
        Array.Sort(anchors);

        // ---- 3) 最大ギャップ → s 決定 ----
        long maxGap = 0;
        for (int i = 0; i + 1 < M; i++)
        {
            long gap = anchors[i + 1] - anchors[i];
            if (gap > maxGap) maxGap = gap;
        }
        long maxSumPerPile = (1L << K) - 1; // 例: K=9 → 511
        if (maxSumPerPile <= 0) maxSumPerPile = 1;
        long s = (maxGap + maxSumPerPile - 1) / maxSumPerPile; // ceil
        if (s <= 0) s = 1;

        // 調整ビット額面 d_k = s * 2^k
        var denoms = new long[K];
        for (int k = 0; k < K; k++) denoms[k] = s << k;

        // ---- 4) A（カード値）を構成 ----
        var cards = new long[N];
        var assign = new int[N]; // X_i（0=捨てる, 1..M=山番号）
        int p = 0;

        // アンカーのカード位置を記録
        var anchorCardIndex = new int[M];
        for (int i = 0; i < M; i++)
        {
            cards[p] = anchors[i];
            anchorCardIndex[i] = p;
            p++;
        }

        // 各ビットの開始位置と在庫ポインタ
        var bitStart = new int[K];
        var bitPtr = new int[K];
        for (int k = 0; k < K; k++)
        {
            bitStart[k] = p;
            bitPtr[k] = p;
            for (int i = 0; i < M; i++)
            {
                cards[p++] = denoms[k];
            }
        }

        // ---- 5) A を出力して flush（ここで B が来る）----
        ConsoleEx.WriteLine(string.Join(" ", cards));
        ConsoleEx.Flush();

        // ---- 6) B を受け取る ----
        var B = ConsoleEx.ReadLongArray(M);

        // (b値, 元のidx) の配列を作り昇順
        var order = new (long b, int idx)[M];
        for (int i = 0; i < M; i++) order[i] = (B[i], i);
        Array.Sort(order, (x, y) => x.b.CompareTo(y.b));

        // B以下のアンカーを最大から使うためのスタック
        var available = new List<int>(M);
        int aPtr = 0; // アンカー走査ポインタ（anchorsは昇順）
        var anchorAssignedToB = new int[M];
        Array.Fill(anchorAssignedToB, -1);

        for (int tIdx = 0; tIdx < M; tIdx++)
        {
            long bVal = order[tIdx].b;
            int bId = order[tIdx].idx;

            while (aPtr < M && anchors[aPtr] <= bVal)
            {
                available.Add(aPtr);
                aPtr++;
            }

            if (available.Count > 0)
            {
                // B以下で最大のアンカーを使う
                int pick = available[available.Count - 1];
                available.RemoveAt(available.Count - 1);
                anchorAssignedToB[bId] = pick;
            }
            else
            {
                // ほぼ起きないが保険：最小の未使用アンカーを割当
                int pick = aPtr < M ? aPtr++ : (M - 1);
                anchorAssignedToB[bId] = pick;
            }
        }

        // ---- 7) アンカーを実カードに割当 ----
        for (int j = 0; j < M; j++)
        {
            int ac = anchorAssignedToB[j];
            int cardIdx = anchorCardIndex[ac];
            assign[cardIdx] = j + 1; // 1始まり
        }

        // ---- 8) 残差を2進額面で貪欲に足し算（各ビットは各山最大1枚）----
        for (int j = 0; j < M; j++)
        {
            int ac = anchorAssignedToB[j];
            long baseVal = anchors[ac];
            long need = B[j] > baseVal ? (B[j] - baseVal) : 0;

            for (int k = K - 1; k >= 0; k--)
            {
                long d = denoms[k];
                if (need >= d)
                {
                    int pos = bitPtr[k]++;
                    if (pos < bitStart[k] + M)
                    {
                        assign[pos] = j + 1;
                        need -= d;
                    }
                    // 在庫は各ビットM枚なので理論上枯渇しない
                }
            }
            // ここで need < s → 各山の誤差は < s
        }

        // ---- 9) X を出力して flush ----
        ConsoleEx.WriteLine(string.Join(" ", assign));
        ConsoleEx.Flush();
    }
}

/// Robust Fast I/O
public static class ConsoleEx
{
    private static readonly System.IO.StreamReader _sr =
        new System.IO.StreamReader(Console.OpenStandardInput());
    private static readonly System.IO.StreamWriter _sw =
        new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };

    private static string[] _buf = Array.Empty<string>();
    private static int _idx = 0;

    public static string ReadLine() => _sr.ReadLine();

    public static string Read()
    {
        while (_idx >= _buf.Length)
        {
            var line = ReadLine();
            while (line != null && line.Length == 0) line = ReadLine();
            if (line == null) throw new InvalidOperationException("EOF");
            _buf = line.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
            _idx = 0;
        }
        return _buf[_idx++];
    }

    public static int ReadInt() => int.Parse(Read());
    public static long ReadLong() => long.Parse(Read());
    public static long[] ReadLongArray(int n)
    {
        var a = new long[n];
        for (int i = 0; i < n; i++) a[i] = ReadLong();
        return a;
    }

    public static void WriteLine(object obj) => _sw.WriteLine(obj);
    public static void Flush() => _sw.Flush();
}
