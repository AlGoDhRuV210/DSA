<h2><a href="https://codeforces.com/contest/1511/problem/C" target="_blank" rel="noopener noreferrer">1511C — Yet Another Card Deck</a></h2>

| | |
|---|---|
| **Difficulty** | 1100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1511C](https://codeforces.com/contest/1511/problem/C) |

## Topics
`brute force` `data structures` `implementation` `trees`

---

## Problem Statement

<div class="header"><div class="title">C. Yet Another Card Deck</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You have a card deck of $$$n$$$ cards, numbered from top to bottom, i. e. the top card has index $$$1$$$ and bottom card — index $$$n$$$. Each card has its color: the $$$i$$$-th card has color $$$a_i$$$.</p><p>You should process $$$q$$$ queries. The $$$j$$$-th query is described by integer $$$t_j$$$. For each query you should: </p><ul> <li> find the highest card in the deck with color $$$t_j$$$, i. e. the card with minimum index; </li><li> print the position of the card you found; </li><li> take the card and place it on top of the deck. </li></ul></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$q$$$ ($$$2 \le n \le 3 \cdot 10^5$$$; $$$1 \le q \le 3 \cdot 10^5$$$) — the number of cards in the deck and the number of queries.</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$1 \le a_i \le 50$$$) — the colors of cards.</p><p>The third line contains $$$q$$$ integers $$$t_1, t_2, \dots, t_q$$$ ($$$1 \le t_j \le 50$$$) — the query colors. It's guaranteed that <span class="tex-font-style-bf">queries ask only colors that are present in the deck</span>.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print $$$q$$$ integers — the answers for each query.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00400640122955913" id="id0013845607314485475" class="input-output-copier">Copy</div></div><pre id="id00400640122955913">7 5
2 1 1 4 3 3 1
3 2 1 1 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005545861114789594" id="id006302956193807121" class="input-output-copier">Copy</div></div><pre id="id005545861114789594">5 2 3 1 5 </pre></div></div></div><div class="note"><div class="section-title">Note</div><p>Description of the sample: </p><ol> <li> the deck is $$$[2, 1, 1, 4, \underline{3}, 3, 1]$$$ and the first card with color $$$t_1 = 3$$$ has position $$$5$$$; </li><li> the deck is $$$[3, \underline{2}, 1, 1, 4, 3, 1]$$$ and the first card with color $$$t_2 = 2$$$ has position $$$2$$$; </li><li> the deck is $$$[2, 3, \underline{1}, 1, 4, 3, 1]$$$ and the first card with color $$$t_3 = 1$$$ has position $$$3$$$; </li><li> the deck is $$$[\underline{1}, 2, 3, 1, 4, 3, 1]$$$ and the first card with color $$$t_4 = 1$$$ has position $$$1$$$; </li><li> the deck is $$$[1, 2, 3, 1, \underline{4}, 3, 1]$$$ and the first card with color $$$t_5 = 4$$$ has position $$$5$$$. </li></ol></div>