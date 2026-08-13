<h2><a href="https://codeforces.com/contest/1215/problem/B" target="_blank" rel="noopener noreferrer">1215B — The Number of Products</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1215B](https://codeforces.com/contest/1215/problem/B) |

## Topics
`combinatorics` `dp` `implementation`

---

## Problem Statement

<div class="header"><div class="title">B. The Number of Products</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a sequence $$$a_1, a_2, \dots, a_n$$$ consisting of $$$n$$$ non-zero integers (i.e. $$$a_i \ne 0$$$). </p><p>You have to calculate two following values:</p><ol> <li> the number of pairs of indices $$$(l, r)$$$ $$$(l \le r)$$$ such that $$$a_l \cdot a_{l + 1} \dots a_{r - 1} \cdot a_r$$$ is negative; </li><li> the number of pairs of indices $$$(l, r)$$$ $$$(l \le r)$$$ such that $$$a_l \cdot a_{l + 1} \dots a_{r - 1} \cdot a_r$$$ is positive; </li></ol></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$n$$$ $$$(1 \le n \le 2 \cdot 10^{5})$$$ — the number of elements in the sequence.</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ $$$(-10^{9} \le a_i \le 10^{9}; a_i \neq 0)$$$ — the elements of the sequence.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print two integers — the number of subsegments with negative product and the number of subsegments with positive product, respectively.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0029272628657226385" id="id00992499922570711" class="input-output-copier">Copy</div></div><pre id="id0029272628657226385">5
5 -3 3 -1 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006304199043609618" id="id008641943667046944" class="input-output-copier">Copy</div></div><pre id="id006304199043609618">8 7
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005618164371296208" id="id0004206827808864444" class="input-output-copier">Copy</div></div><pre id="id005618164371296208">10
4 2 -4 3 1 2 -4 3 2 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00589285659160009" id="id0012615557068391647" class="input-output-copier">Copy</div></div><pre id="id00589285659160009">28 27
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id001356852088609698" id="id006124590701777887" class="input-output-copier">Copy</div></div><pre id="id001356852088609698">5
-1 -2 -3 -4 -5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0044622521663751613" id="id007723811842895538" class="input-output-copier">Copy</div></div><pre id="id0044622521663751613">9 6
</pre></div></div></div>