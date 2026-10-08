# Infosys SP / DSE Prep Strategy — 5-week sprint

> Target roles: **Specialist Programmer (Trainee)** and **Digital Specialist Engineer (Trainee)**
> **Test: in-person coding assessment — 12 November 2026 (Thu).**
> Written 2026-10-08, revised for the real date. Restarting after a ~10-month gap.
>
> **Window:** Oct 8 → Nov 11 = **35 days**. Minus **3 break days** = **~32 study days (4.5 weeks).**
> Test day (Nov 12) is not a study day.
>
> **Read this first:** The email says "in-person coding assessment." That matches reported
> onsite formats — e.g. *2 coding questions (easy+medium) in ~2 hours*, or *choose 1 of 2 in
> ~45 min followed by a short interview on core subjects*. So this plan is **~90% coding, ~10%
> CS-fundamentals** (for the likely short interview after) and **drops aptitude/verbal/SQL-heavy
> prep**. If the actual format turns out different, re-read the Sources and adjust. Verify details
> against your official Infosys communication.

---

## 1. How realistic is this? (honest answer)

**Short version: clearing an easy–medium in-person coding round is a realistic target if you
hit ~3 focused hours/day consistently. SP-tier difficulty is a stretch. The plan is tight but
not unreasonable — the 10-month gap is the main tax, and your foundation is strong enough to
pay it down fast.**

What's in your favor:
- Your finished topics (Arrays, Two Pointers, Stack, Binary Search, Sliding Window) already
  cover a big share of what easy/medium coding rounds throw at you — you did some *Hard* ones.
- "In-person coding assessment" wording suggests the more tractable onsite format (2 questions,
  easy→medium) rather than the brutal 3-hard HackWithInfy OA.
- No aptitude/verbal to prep means ~all your time compounds on coding.

What's against you / the real risks:
- **Graphs, DP, and Greedy are untouched**, and they're the topics most likely to decide a
  medium problem on test day. 4.5 weeks is enough to reach "can solve a standard medium" in
  these — **not** enough for deep mastery or hard DP/graph problems.
- A **math/modular/implementation-heavy** problem (Infosys likes these) could catch you out.
- If you clear the coding round, a **short interview on core CS + explaining your own code**
  often follows — handled lightly here, may need more after Nov 12 if you advance.

**Honest probability framing (no fake numbers):** if you execute this plan consistently,
clearing an easy–medium coding round is *more likely than not*. If the test runs SP/HackWithInfy-
hard, treat that as the stretch outcome. The single biggest failure mode is **spreading thin** —
go deep on Graphs + 1-D DP + Greedy rather than lightly touching everything.

---

## 2. Current baseline (from this repo)

43/150 on NeetCode (14E / 25M / 4H).

| Status | Topics |
|---|---|
| **Solid / finished** | Arrays & Hashing, Two Pointers, Stack, Binary Search, Sliding Window (incl. some Hard) |
| **In progress** | Linked List (~5), Trees (~5 easy) |
| **Untouched — top priority** | **Graphs, 1-D DP, Greedy, 2-D DP**, Heap/PQ, Backtracking, math/modular, Bit Manipulation, Intervals, Tries |

Primary language **C++** (keep it — know its I/O cold). Keep a little Python for quick work.

---

## 3. Effort split (in-person coding assessment)

1. **DSA coding — ~90%.** Close the Graphs/DP/Greedy gap, then reps + timed practice.
2. **CS fundamentals — ~10%.** OOP, DBMS, OS basics, and *being able to explain your own code*
   — for the short core-subjects interview that often follows an onsite coding round.
3. **Dropped for now:** aptitude, logical, verbal, heavy SQL. (Skim SQL SELECT/JOIN only if
   you have spare time; interviews sometimes ask one.)

Baked-in habits every session:
- **Exact output formatting** — no stray prints, right spacing/newlines. Hidden test cases +
  formatting mismatches fail otherwise-correct code. Build this reflex from Day 1.
- **Re-solve, don't re-read.** A problem is "done" only when you can reproduce it cold.
- **Protect the streak** — one problem minimum, every single day.

---

## 4. The 5-week calendar (Oct 8 – Nov 11, 2026)

Weeks run Thu→Wed. Put your **3 break days** in weeks 2–4 (one each) — **never in the final week.**
Daily load: **~3 new problems + 1 re-solve ≈ 3 hours.** Prioritized by payoff; if you fall
behind, **drop from the bottom** (Tries → Intervals → hard 2-D DP go first).

### Block A — Reactivate · Oct 8 (Thu) – Oct 10 (Sat) · 3 days
- Re-solve **3/day** from finished green topics (arrays, two-pointer, stack, binary search,
  sliding window), from memory, in C++. Goal: write clean C++ fast again. **Restart the streak today.**

### Block B — Close the gap · Oct 11 (Sun) – Nov 2 (Mon) · ~3 weeks
Highest-frequency Infosys topics first:

| Dates | Topic | Key problems |
|---|---|---|
| Oct 11–15 | **Graphs** *(top priority)* | BFS/DFS, number of islands, clone graph, course schedule (topo sort), union-find/connected components |
| Oct 16–19 | **1-D DP** *(top priority)* | climbing stairs, house robber I/II, coin change, longest increasing subsequence, word break |
| Oct 20–22 | **Greedy + Intervals** | jump game, gas station, merge intervals, insert interval, non-overlapping intervals |
| Oct 23–26 | **2-D DP** | unique paths, min path sum, 0/1 knapsack, longest common subsequence, edit distance |
| Oct 27–29 | **Heap/PQ + Backtracking** | kth largest, task scheduler, subsets, combination sum, permutations |
| Oct 30–31 | **Finish Trees + Linked List** | BFS level order, validate BST, LCA; LL merge-k, cycle detection, reverse in groups |
| Nov 1–2 | **Math/modular + Bit manip** | GCD/LCM, sieve of Eratosthenes, fast/modular exponentiation, `x mod 1e9+7`, single number, counting bits |

Target by Nov 2: can solve a **standard medium** in Graphs, 1-D DP, and Greedy unaided.

### Block C — Simulate + interview polish · Nov 3 (Tue) – Nov 11 (Wed) · ~1.5 weeks
- **Timed mock rounds, 4–5 of them:** mimic the real format — *2 problems in 2 hrs* and
  *choose 1 of 2 in 45 min*. Always print exactly what's asked.
- **Codeforces Div 3/4 or CodeChef** — a couple of timed contests for implementation + math speed under pressure.
- **CS-fundamentals light pass** (rotate, ~20 min/day): OOP pillars, DBMS (normalization, ACID,
  SQL basics), OS (process vs thread, deadlock). Prepare to **explain your test solutions out loud.**
- **Re-solve your 15–20 hardest** problems.
- **Nov 10–11: light review only.** No new topics. Sleep, logistics, know the venue/setup.

---

## 5. Daily routine

| Block | Time | What |
|---|---|---|
| Core DSA | ~2 hr | New problems for the current week's topic (Block B order) |
| Re-solve | ~20 min | One past miss, from memory |
| CS note | ~15 min | One fundamental in your own words (Block C weeks especially) |
| Log it | ~5 min | Update README, commit, keep the streak |

Bad day minimum: **one problem + streak. Never zero.**

---

## 6. Resources
- **NeetCode 150** (in use) — primary pattern-based roadmap; follow the section order above.
- **Striver's SDE / A2Z sheet** (takeUforward) — supplement, strong on DP & graphs.
- **Codeforces (Div 3/4), CodeChef** — timed implementation + math practice closest to the OA feel.
- **GeeksforGeeks / InterviewBit** — Infosys-tagged company questions.
- **GitHub: bhasidhshaik/Infosys-SP-DSE-resources** — community SP/DSE prep (verify before trusting).

---

## 7. If time runs short (drop order)
Cut from the bottom up: **Tries → Intervals → hard 2-D DP → Bit manipulation.**
Never cut: **Graphs, 1-D DP, Greedy, and timed mock rounds in Block C.**

---

## Sources
Self-reported / secondary; verify against your official Infosys communication for this drive.

- [Infosys interview questions for freshers 2026: InfyTQ, HackWithInfy, SP vs DSE guide (jobrise.io)](https://jobrise.io/en/blog/infosys-interview-questions-freshers/)
- [Infosys SP role interview experience 2025 — Dev Sharma (Medium)](https://medium.com/@giga_dummy/infosys-sp-role-interview-experience-2025-by-dev-sharma-210bcfa7dfef)
- [Infosys HackWithInfy 2026 (Specialist Programmer L3) interview experience (LeetCode Discuss)](https://leetcode.com/discuss/post/8444640/infosys-hackwithinfy-2026-specialist-pro-o0jw/)
- [Specialist Programmer interview experience, Sep 2025 (LeetCode Discuss)](https://leetcode.com/discuss/interview-experience/7233305)
- [Infosys Specialist Programmer interview experiences (Naukri Code360)](https://www.naukri.com/code360/interview-experiences/infosys-private-limited/infosys-interview-experience-by-gaurav-patel-specialist-programmer-jul-2022-exp-0-2-years)
- [Infosys coding interview questions (Educative)](https://www.educative.io/blog/infosys-coding-interview-questions)
- [What is the Infosys interview process like? Round by round (DesignGurus)](https://www.designgurus.io/answers/detail/what-is-the-infosys-interview-process-like-round-by-round)
- [Infosys recruitment process & job roles (placementpreparation.io)](https://www.placementpreparation.io/infosys/recruitment-process/)
- [Infosys recruitment pattern, important topics (faceprep.in)](https://faceprep.in/article/infosys-recruitment-pattern-important-topics-and-about-the-company/)
- [Community prep repo: bhasidhshaik/Infosys-SP-DSE-resources (GitHub)](https://github.com/bhasidhshaik/Infosys-SP-DSE-resources)
