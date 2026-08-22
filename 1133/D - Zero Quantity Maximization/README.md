<h2><a href="https://codeforces.com/contest/1133/problem/D" target="_blank" rel="noopener noreferrer">1133D — Zero Quantity Maximization</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1133D](https://codeforces.com/contest/1133/problem/D) |

## Topics
`hashing` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">D. Zero Quantity Maximization</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given two arrays $$$a$$$ and $$$b$$$, each contains $$$n$$$ integers.</p><p>You want to create a new array $$$c$$$ as follows: choose some real (i.e. not necessarily integer) number $$$d$$$, and then for every $$$i \in [1, n]$$$ let $$$c_i := d \cdot a_i + b_i$$$.</p><p>Your goal is to maximize the number of zeroes in array $$$c$$$. What is the largest possible answer, if you choose $$$d$$$ optimally?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$n$$$ ($$$1 \le n \le 2 \cdot 10^5$$$) — the number of elements in both arrays.</p><p>The second line contains $$$n$$$ integers $$$a_1$$$, $$$a_2$$$, ..., $$$a_n$$$ ($$$-10^9 \le a_i \le 10^9$$$).</p><p>The third line contains $$$n$$$ integers $$$b_1$$$, $$$b_2$$$, ..., $$$b_n$$$ ($$$-10^9 \le b_i \le 10^9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print one integer — the maximum number of zeroes in array $$$c$$$, if you choose $$$d$$$ optimally.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0037785634984988603" id="id0027994220035914597" class="input-output-copier">Copy</div></div><pre id="id0037785634984988603">5
1 2 3 4 5
2 4 7 11 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006622305212244332" id="id007315331950688915" class="input-output-copier">Copy</div></div><pre id="id006622305212244332">2
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0031754805989803214" id="id009165038092913929" class="input-output-copier">Copy</div></div><pre id="id0031754805989803214">3
13 37 39
1 2 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007773412766042563" id="id0016637583853939464" class="input-output-copier">Copy</div></div><pre id="id007773412766042563">2
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006405616351590548" id="id00034005009314642565" class="input-output-copier">Copy</div></div><pre id="id006405616351590548">4
0 0 0 0
1 2 3 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008721373798684227" id="id009068900124236798" class="input-output-copier">Copy</div></div><pre id="id008721373798684227">0
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id001213590831487168" id="id0015070800336397894" class="input-output-copier">Copy</div></div><pre id="id001213590831487168">3
1 2 -1
-6 -12 6
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008036497054657499" id="id007746425305795174" class="input-output-copier">Copy</div></div><pre id="id008036497054657499">3
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, we may choose $$$d = -2$$$.</p><p>In the second example, we may choose $$$d = -\frac{1}{13}$$$.</p><p>In the third example, we cannot obtain any zero in array $$$c$$$, no matter which $$$d$$$ we choose.</p><p>In the fourth example, we may choose $$$d = 6$$$.</p></div>