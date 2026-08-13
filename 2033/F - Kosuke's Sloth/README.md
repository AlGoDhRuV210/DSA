<h2><a href="https://codeforces.com/contest/2033/problem/F" target="_blank" rel="noopener noreferrer">2033F — Kosuke's Sloth</a></h2>

| | |
|---|---|
| **Difficulty** | 1800 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2033F](https://codeforces.com/contest/2033/problem/F) |

## Topics
`brute force` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">F. Kosuke's Sloth</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Kosuke is too lazy. He will not give you any legend, just the task:</p><p>Fibonacci numbers are defined as follows:</p><ul> <li> $$$f(1)=f(2)=1$$$. </li><li> $$$f(n)=f(n-1)+f(n-2)$$$ $$$(3\le n)$$$ </li></ul> We denote $$$G(n,k)$$$ as an index of the $$$n$$$-th Fibonacci number that is divisible by $$$k$$$. For given $$$n$$$ and $$$k$$$, compute $$$G(n,k)$$$.<p>As this number can be too big, output it by modulo $$$10^9+7$$$.</p><p>For example: $$$G(3,2)=9$$$ because the $$$3$$$-rd Fibonacci number that is divisible by $$$2$$$ is $$$34$$$. $$$[1,1,\textbf{2},3,5,\textbf{8},13,21,\textbf{34}]$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input data contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.</p><p>The first and only line contains two integers $$$n$$$ and $$$k$$$ ($$$1 \le n \le 10^{18}$$$, $$$1 \le k \le 10^5$$$).</p><p>It is guaranteed that the sum of $$$k$$$ across all test cases does not exceed $$$10^6$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output the only number: the value $$$G(n,k)$$$ taken by modulo $$$10^9+7$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003155087050742258" id="id0040853465489593976" class="input-output-copier">Copy</div></div><pre id="id003155087050742258"><div class="test-example-line test-example-line-even test-example-line-0">3</div><div class="test-example-line test-example-line-odd test-example-line-1">3 2</div><div class="test-example-line test-example-line-even test-example-line-2">100 1</div><div class="test-example-line test-example-line-odd test-example-line-3">1000000000000 1377</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0019051004498984914" id="id005904409624958857" class="input-output-copier">Copy</div></div><pre id="id0019051004498984914">9
100
999244007
</pre></div></div></div>