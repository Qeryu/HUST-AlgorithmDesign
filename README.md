这些题老师上课都带着讲过一遍思路了，就不多解释了，直接上oj和代码

# 动态规划 1D

## 例题1：斐波那契数列F(n)

练习题：[oj | 超级楼梯](http://10.12.162.1:5880/contest/22/problem/P0203)

参考代码：[HUST-AlgorithmDesign/p0203.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0203.cpp)

## 例题3：排队买票问题

练习题：[Problem - 1260 (hdu.edu.cn)](http://acm.hdu.edu.cn/showproblem.php?pid=1260)

参考代码：[HUST-AlgorithmDesign/hdu1260.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/hdu1260.cpp)

## 拓展1：导弹拦截

题目为最长不下降子序列问题变种，需要求全覆盖需要的子序列数量

问题1：求最长不上升子序列长度

问题2：求覆盖所有数据所需的最长上升子序列数量

问题2可以转化为求原序列的最长上升子序列的长度

练习题：[P1020 NOIP1999 普及组 导弹拦截 - 洛谷](https://www.luogu.com.cn/problem/P1020)

参考代码1：[HUST-AlgorithmDesign/luogu1020.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1020.cpp)

这份代码利用DilWorth定理将第二个**求能够覆盖全序列的下降序列数量**转化为**求最长上升子序列的长度**

参考代码2：[HUST-AlgorithmDesign/luogu1020_1.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1020_1.cpp)

使用贪心的思想处理第二个问题，每次新来一个导弹，就找一个当前高度最低且能拦截的系统来拦截

## 拓展2：低价购买

题目为最长不下降子序列问题变种，需要复盘dp过程，统计达成dp结果的方案数量

学院OJ上数据点太弱，没法检测相同方案去重

练习题：[P1108 低价购买 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1108)

参考代码：[HUST-AlgorithmDesign/p0211.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0211.cpp)

## 拓展3：合唱队形

题目为最长不下降子序列问题变种，两个方向各一次dp，枚举最高点获得答案

练习题：[P1091 NOIP2004 提高组 合唱队形 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1091)

参考代码：[HUST-AlgorithmDesign/p0210.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0210.cpp)

# 动态规划 2D

## 例题6：马拦过河卒

学院OJ上数据太弱，没有出现方案数超出int的情况，实际上应该用long long

日常作业题：[oj | 过河卒](http://10.12.162.1:5880/contest/22/problem/P0212)

练习题：[P1002 NOIP2002 普及组 过河卒 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1002)

参考代码：[HUST-AlgorithmDesign/p0212.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0212.cpp)

## 例题7：数字三角形

日常作业题：[oj | 数字三角形](http://10.12.162.1:5880/contest/22/problem/P0200)

练习题：[oj | 数字三角形](http://10.12.162.1:5880/contest/22/problem/P0200)、[P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles - 洛谷](https://www.luogu.com.cn/problem/P1216)

参考代码：[HUST-AlgorithmDesign/p0200.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0200.cpp)

## 例题8：最长公共子序列LCS

练习题：[P1439 【模板】最长公共子序列 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1439)

参考代码1：[HUST-AlgorithmDesign/luogu1439.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1439.cpp)

这份代码是$O(n^2)$复杂度的，只能通过P1439的前50%个测试点，思路是照抄的课件，支持对LCS的输出

参考代码2：[HUST-AlgorithmDesign/luogu1439_1.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1439_1.cpp)

这份代码将LCS问题转换为LIS问题，通过$O(nlogn)$的时间复杂度进行求解

## 拓展1：装箱问题

日常作业题：[oj | 装箱问题](http://10.12.162.1:5880/contest/22/problem/P0216)

练习题：[P1049 [NOIP2001 普及组] 装箱问题 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1049)

参考代码1：[HUST-AlgorithmDesign/p0216.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0216.cpp)

这份代码就是简单的01背包，把剩余空间转换为价值

参考代码2：[HUST-AlgorithmDesign/p0216_1.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0216_1.cpp)

这份代码是在1的基础上做了空间复杂度的优化

## 拓展2：采药

和上一题一模一样，更加标准的模板题，直接上优化后的代码

练习题：[P1048 [NOIP2005 普及组] 采药 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1048)

参考代码：[HUST-AlgorithmDesign/luogu1048.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1048.cpp)

## 拓展3：开心的金明

和上一题基本一致，状态转移方程微调

日常作业题：[oj | 开心的金明](http://10.12.162.1:5880/contest/22/problem/P0217)

练习题：[P1060 [NOIP2006 普及组] 开心的金明 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1060)

参考代码：[HUST-AlgorithmDesign/p0217.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0217.cpp)

## 例题10：完全背包

练习题：[P1616 疯狂的采药 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1616)

参考代码1：[HUST-AlgorithmDesign/luogu1616.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1616.cpp)

这份代码是根据老师的思路，把无穷数量的物品转化为在给定容积下的有限数量，但是显然时间复杂度可能在特制的数据下爆炸（而且还忘了开longlong

参考代码2：[HUST-AlgorithmDesign/luogu1616_1.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1616_1.cpp)

这份是按照完全背包模板写的代码，是在01背包基础上调整内层循环的顺序

**为什么这样一改就行呢？**

01背包问题中按V...0来循环，是为了保证在选第i件物品时，依据的是还未考虑第i件物品的子结果f\[i-1][v-c[i]]。

而现在完全背包是每种物品可选无限件，在考虑第i种物品时，可以从考虑了第i件物品的子结果进行转移，所以循环调整为0...V正好可以满足条件

参考代码3：[HUST-AlgorithmDesign/luogu1616_2.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1616_2.cpp)

其实还是可以对参考代码1进行一些些优化的，比如转化为有限容量的时候用二进制形式的思想进行转换，比如上限是可以塞10件，可以通过放1个8件包、1个2件包来实现，不需要枚举所有10种情况，大大减少复杂度

## 例题11：多重背包

日常作业题：[oj | 宝物筛选](http://10.12.162.1:5880/contest/22/problem/P0220)

练习题：[P1776 宝物筛选 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1776)

参考代码：[HUST-AlgorithmDesign/p0220.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0220.cpp)

需要注意，多重背包的二进制拆分和完全背包的二进制拆分还有些不同，具体见代码

## 例题12：混合背包

日常作业题：[oj | 2021年算法设计与分析](http://10.12.162.1:5880/contest/22/problem/P0221)

练习题：[P1833 樱花 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1833)

参考代码：[HUST-AlgorithmDesign/p0221.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0221.cpp)

实际上就是分情况讨论使用前面的多重背包和完全背包，01背包是多重背包的一种特殊情况

## 例题13：分组背包

日常练习题：[oj | 通天之分组背包](http://10.12.162.1:5880/contest/22/problem/P0219)

练习题：[P1757 通天之分组背包 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1757)

参考代码：[HUST-AlgorithmDesign/p0219.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0219.cpp)

思想比较朴素，所有组在做01背包，每个组可以选择添加一个物品到包里也可以选择不添加，至于组内如何选择，则需要每次在组内选择的时候对一个dp[j]使用所有的组内物品进行1次更新。

## 例题14：有依赖的背包

练习题：[P1064 [NOIP2006 提高组] 金明的预算方案 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1064)

参考代码：

## 例题15：二维费用背包

日常作业题：[oj | NASA的食物计划](http://10.12.162.1:5880/contest/22/problem/P0218)

练习题：[P1507 NASA的食物计划 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1507)

参考代码：

# 动态规划 区间DP

## 石子合并

练习题：[P1880 [NOI1995] 石子合并 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1880)

## 能量项链

练习题：[P1063 [NOIP2006 提高组] 能量项链 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1063)

## 凸多边形的三角剖分

练习题：[1039. 多边形三角剖分的最低得分 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimum-score-triangulation-of-polygon/)

## 多边形（IOI98）

练习题：[1179 -- Polygon (poj.org)](http://poj.org/problem?id=1179)

## 青蛙的烦恼

没找到OJ上的题...

## 棋盘分割

练习题：[1191 -- 棋盘分割 (poj.org)](http://poj.org/problem?id=1191)

# 动态规划总结

## 打家劫舍

练习题：[198. 打家劫舍 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/house-robber/)

## 单词拆分

练习题：[140. 单词拆分 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/word-break-ii/)

## 压缩字符串

练习题：[1531. 压缩字符串 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/string-compression-ii/)

## 石子归并

练习题：[282. 石子合并 - AcWing题库](https://www.acwing.com/problem/content/description/284/)

## 目标和

练习题：[494. 目标和 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/target-sum/)
