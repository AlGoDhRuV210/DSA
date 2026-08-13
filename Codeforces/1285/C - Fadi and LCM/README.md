<h2><a href="https://codeforces.com/contest/1285/problem/C" target="_blank" rel="noopener noreferrer">1285C — Fadi and LCM</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1285C](https://codeforces.com/contest/1285/problem/C) |

## Topics
`brute force` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">C. Fadi and LCM</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Today, Osama gave Fadi an integer $$$X$$$, and Fadi was wondering about the minimum possible value of $$$max(a, b)$$$ such that $$$LCM(a, b)$$$ equals $$$X$$$. Both $$$a$$$ and $$$b$$$ should be positive integers.</p><p>$$$LCM(a, b)$$$ is the smallest positive integer that is divisible by both $$$a$$$ and $$$b$$$. For example, $$$LCM(6, 8) = 24$$$, $$$LCM(4, 12) = 12$$$, $$$LCM(2, 3) = 6$$$.</p><p>Of course, Fadi immediately knew the answer. Can you be just like Fadi and find any such pair?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first and only line contains an integer $$$X$$$ ($$$1 \le X \le 10^{12}$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print two positive integers, $$$a$$$ and $$$b$$$, such that the value of $$$max(a, b)$$$ is minimum possible and $$$LCM(a, b)$$$ equals $$$X$$$. If there are several possible such pairs, you can print any.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005722409068668293" id="id009025249090674725" class="input-output-copier">Copy</div></div><pre id="id005722409068668293">2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008531277455044367" id="id005607062529834279" class="input-output-copier">Copy</div></div><pre id="id008531277455044367">1 2
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0048442894338103615" id="id008705734187378698" class="input-output-copier">Copy</div></div><pre id="id0048442894338103615">6
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008694299125746024" id="id005882175069158829" class="input-output-copier">Copy</div></div><pre id="id008694299125746024">2 3
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004406839484532654" id="id007726273629050343" class="input-output-copier">Copy</div></div><pre id="id004406839484532654">4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009149955854363345" id="id002520816011766026" class="input-output-copier">Copy</div></div><pre id="id009149955854363345">1 4
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005488754479965485" id="id00533136838895854" class="input-output-copier">Copy</div></div><pre id="id005488754479965485">1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009437385603576716" id="id0048941746978745615" class="input-output-copier">Copy</div></div><pre id="id009437385603576716">1 1
</pre></div></div></div>