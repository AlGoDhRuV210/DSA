<h2><a href="https://codeforces.com/contest/2172/problem/A" target="_blank" rel="noopener noreferrer">2172A — ASCII Art Contest</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2172A](https://codeforces.com/contest/2172/problem/A) |

## Topics
`implementation`

---

## Problem Statement

<div class="header"><div class="title">A. ASCII Art Contest</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Three leading AI-powered creative assistants—Gemini, ChatGPT, and Claude—enter the first ever ASCII Art Contest, where they must impress a panel of human judges with their text-based masterpieces.</p><p>Each participant receives a score between 80 and 100 (inclusive). The organizers want to announce the final standing only if the judges' opinions are "close enough"; otherwise, they will ask the judges to reconsider.</p><p>Given the three integer scores of Gemini, ChatGPT, and Claude, determine the contest result:</p><ul> <li> If the maximum score and the minimum score differ by at least 10 points, print <span class="tex-font-style-tt">check again</span> (the judging seems inconsistent, so the panel must re-evaluate). </li><li> Otherwise, print <span class="tex-font-style-tt">final X</span>, where <span class="tex-font-style-tt">X</span> is the median of the three scores (the score that would be in the middle if all three were sorted in non-decreasing order). </li></ul></div><div class="input-specification"><div class="section-title">Input</div><p>A single line contains three integers $$$g, c, \ell$$$, representing the scores of Gemini, ChatGPT, and Claude respectively.</p><ul> <li> $$$80\le g, c, \ell \le 100$$$ </li></ul></div><div class="output-specification"><div class="section-title">Output</div><p>Print the required answer in a line.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006342637546445301" id="id00039282757387902434" class="input-output-copier">Copy</div></div><pre id="id006342637546445301">88 94 95
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0041427051471132037" id="id0001907922453416422" class="input-output-copier">Copy</div></div><pre id="id0041427051471132037">final 94
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007134595623383465" id="id00865336912015373" class="input-output-copier">Copy</div></div><pre id="id007134595623383465">100 80 81
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007432235166590299" id="id005167970188578128" class="input-output-copier">Copy</div></div><pre id="id007432235166590299">check again
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id000695026983462983" id="id0022170654551217528" class="input-output-copier">Copy</div></div><pre id="id000695026983462983">98 99 98
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id000758038994311262" id="id0015530360711771696" class="input-output-copier">Copy</div></div><pre id="id000758038994311262">final 98
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002612043249738655" id="id0018898412905057094" class="input-output-copier">Copy</div></div><pre id="id002612043249738655">95 86 85
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006116685293076496" id="id0020719868667381003" class="input-output-copier">Copy</div></div><pre id="id006116685293076496">check again
</pre></div></div></div>