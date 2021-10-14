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

练习题：[P1002 NOIP2002 普及组 过河卒 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1002)

参考代码：[HUST-AlgorithmDesign/p0212.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0212.cpp)

## 例题7：数字三角形

练习题：[oj | 数字三角形](http://10.12.162.1:5880/contest/22/problem/P0200)、[P1216 [USACO1.5\][IOI1994]数字三角形 Number Triangles - 洛谷](https://www.luogu.com.cn/problem/P1216)

参考代码：[HUST-AlgorithmDesign/p0200.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/p0200.cpp)

## 例题8：最长公共子序列LCS

练习题：[P1439 【模板】最长公共子序列 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1439)

参考代码1：[HUST-AlgorithmDesign/luogu1439.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1439.cpp)

这份代码是$O(n^2)$复杂度的，只能通过P1439的前50%个测试点，思路是照抄的课件，支持对LCS的输出

参考代码2：[HUST-AlgorithmDesign/luogu1439_1.cpp at main · Qeryu/HUST-AlgorithmDesign (github.com)](https://github.com/Qeryu/HUST-AlgorithmDesign/blob/main/classPractice/luogu1439_1.cpp)

这份代码将LCS问题转换为LIS问题，通过$O(nlogn)$的时间复杂度进行求解

## 例题9：01背包问题

## 拓展1：装箱问题

## 拓展2：采药

## 拓展3：开心的金明

## 例题10：完全背包

## 例题11：多重背包

## 例题12：混合背包

## 例题13：分组背包

## 例题14：有依赖的背包

## 例题15：二维费用背包