<h2><a href="https://codeforces.com/contest/2033/problem/D" target="_blank" rel="noopener noreferrer">2033D — Kousuke's Assignment</a></h2>

| | |
|---|---|
| **Difficulty** | 1300 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2033D](https://codeforces.com/contest/2033/problem/D) |

## Topics
`data structures` `dp` `dsu` `greedy` `math`

---

## Problem Statement

<div class="header"><div class="title">D. Kousuke's Assignment</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>After a trip with Sakurako, Kousuke was very scared because he forgot about his programming assignment. In this assignment, the teacher gave him an array $$$a$$$ of $$$n$$$ integers and asked him to calculate the number of <span class="tex-font-style-bf">non-overlapping</span> segments of the array $$$a$$$, such that each segment is considered <span class="tex-font-style-it">beautiful</span>.</p><p>A segment $$$[l,r]$$$ is considered <span class="tex-font-style-it">beautiful</span> if $$$a_l + a_{l+1} + \dots + a_{r-1} + a_r=0$$$.</p><p>For a fixed array $$$a$$$, your task is to compute the maximum number of non-overlapping <span class="tex-font-style-it">beautiful</span> segments.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of input contains the number $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases. Each test case consists of $$$2$$$ lines. </p><ul> <li> The first line contains one integer $$$n$$$ ($$$1 \le n \le 10^5$$$) — the length of the array.</li><li> The second line contains $$$n$$$ integers $$$a_i$$$ ($$$-10^5 \le a_i \le 10^5$$$) — the elements of the array $$$a$$$. </li></ul><p>It is guaranteed that the sum of $$$n$$$ across all test cases does not exceed $$$3\cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output a single integer: the maximum number of non-overlapping <span class="tex-font-style-it">beautiful</span> segments.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00016794221855103375" id="id003632444156405792" class="input-output-copier">Copy</div></div><pre id="id00016794221855103375"><div class="test-example-line test-example-line-even test-example-line-0">3</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-odd test-example-line-1">2 1 -3 2 1</div><div class="test-example-line test-example-line-even test-example-line-2">7</div><div class="test-example-line test-example-line-even test-example-line-2">12 -4 4 43 -3 -5 8</div><div class="test-example-line test-example-line-odd test-example-line-3">6</div><div class="test-example-line test-example-line-odd test-example-line-3">0 -4 0 3 0 1</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004916910393198869" id="id0012330523169589425" class="input-output-copier">Copy</div></div><pre id="id004916910393198869">1
2
3
</pre></div></div></div>