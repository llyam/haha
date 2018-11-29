### string

#### strdup   strcpy

#### strcat

#### strncat

#### strspn(const char *s1, const char *s2)

统计从头开始第一个不来自s2中的字符。

#### strcspn(const char *s1, const char *s2)

从头开始直到第一个来自s2中的字符。



#### strpbrk(const char *s1, const char *s2)

第一个在s1中同时也在s2中的字符位置指针



#### char strncmp(const char *s1, const char *s2, int count)

s1和s2前count个字符字典序比较

#### char strcmp(const char *s1, const char *s2)

*s1 < s2* 小于 0， *s1 = s2* 等于 0, *s1 > s2* 大于 0



#### strchr(char *str, char ch)

找出str指向字符串中第一次出现字符ch的位置

#### char *strrchr(const char *s, int c)

得到字符串s中最后一个含有c字符的位置指针



#### strstr(char *s1, char *s2)

找出s2字符串在s1字符串中第一次出现的位置