利用哈希表统计两源程序的相似性

1）内容：
对于两个 C 语言的源程序清单，用哈希表的方法分别统计两程序中使用C语言关键字的情况，并最终按定量的计算结果，得出两份源程序的相似性。

2）要求与提示：
C 语言关键字的哈希表可以自建，也可以采用下面的哈希函数昨晚参考：

Hash(key)=(key第一个字符序号\*100+key 最后一个字符序号)%41 

表长m取43。此题的工作主要是扫描给定的源程序，累计在每个源程序中C语言关键字出现的频度。为保证查找效率，建议自建哈希表的平均查找长度不大于2。 扫描两个源程序所统计的所有关键字不同频度， 可以得到两个向量。
