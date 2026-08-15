<h2><a href="https://codeforces.com/contest/1600/problem/E" target="_blank" rel="noopener noreferrer">1600E — Array Game</a></h2>

| | |
|---|---|
| **Difficulty** | 1900 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1600E](https://codeforces.com/contest/1600/problem/E) |

## Topics
`games` `greedy` `two pointers`

---

## Problem Statement

<div class="header"><div class="title">E. Array Game</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Alice and Bob are playing a game. They are given an array $$$A$$$ of length $$$N$$$. The array consists of integers. They are building a sequence together. In the beginning, the sequence is empty. In one turn a player can remove a number from the left or right side of the array and append it to the sequence. The rule is that the sequence they are building must be strictly increasing. The winner is the player that makes the last move. Alice is playing first. Given the starting array, under the assumption that they both play optimally, who wins the game?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$N$$$ ($$$1 \leq N \leq 2*10^5$$$) - the length of the array $$$A$$$.</p><p>The second line contains $$$N$$$ integers $$$A_1$$$, $$$A_2$$$,...,$$$A_N$$$ ($$$0 \leq A_i \leq 10^9$$$)</p></div><div class="output-specification"><div class="section-title">Output</div><p>The first and only line of output consists of one string, the name of the winner. If Alice won, print "Alice", otherwise, print "Bob".</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006610115189821749" id="id008303991440465268" class="input-output-copier">Copy</div></div><pre id="id006610115189821749">1
5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006221269796420187" id="id001331818887922348" class="input-output-copier">Copy</div></div><pre id="id006221269796420187">Alice
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0037136137567887983" id="id008313818189676049" class="input-output-copier">Copy</div></div><pre id="id0037136137567887983">3
5 4 5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004005189274657611" id="id00262340491978049" class="input-output-copier">Copy</div></div><pre id="id004005189274657611">Alice
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006369024173470439" id="id006691928742568273" class="input-output-copier">Copy</div></div><pre id="id006369024173470439">6
5 8 2 1 10 9
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006978236626644978" id="id006961551559580477" class="input-output-copier">Copy</div></div><pre id="id006978236626644978">Bob
</pre></div></div></div>