## 1.vector的介绍及使用

### 1.1 vector的介绍

**[vector的文档介绍](https://cplusplus.com/reference/vector/vector/)**

可改变size的顺序表！

### [118.杨辉三角](https://leetcode.cn/problems/pascals-triangle/submissions/)

```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //定义vv
        vector<vector<int>> vv;
        //开空间+初始化，默认0
        vv.resize(numRows);
        for(size_t i = 0;i<numRows;++i)
        {
            //先开空间
            vv[i].resize(i+1);
            //每行第一个和最后一个置1
            vv[i][0] = vv[i][vv[i].size()-1] = 1;
        }
        //访问第一层vector
        for(size_t i = 0;i<vv.size();++i)
        {
            //访问第一层vector里的vector
            for(size_t j = 0;j<vv[i].size();++j)
            {
                if(vv[i][j] == 0)
                {
                    //这个值等于，上列的对应数，和上一列对应数的前一个
                    vv[i][j] = vv[i-1][j] + vv[i-1][j-1];
                }
            }
        }
        //返回vv
        return vv;
    }
};
```

> ![image-20220626110221900](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206261102984.png)

### [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

```
class Solution {
    string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

public:
    void _letterCombinations(const string& digits,size_t i,string combinStr,vector<string>& strV)
    {                       //数字字符串      //标识数字字符串  //取到的字母组合 // 返回的 string类型的vector
        if(i == digits.size())
        {
            strV.push_back(combinStr);// i = 3 后，将 "akt" 存进strV里，
                                    //然后回到 k的那一层(j = 0),这层循环完成，j++，则取到"aku"
            return;
        }
        //例如 digits = "258"
        //取2对应的位置 ,绝对映射 arr的2的校标
        //i 标识 数字字符串
        string str = arr[digits[i] - '0'];//i = 0(0:2)取到"abc" //i+1 = 1 (1:5)后取到"kjl"// i:1+1 = 2 (2:8)后取到"tuv"
        //j标识数字对应的字符串  取到的字符串多长，就递归多少次
        for(size_t j = 0; j<str.size();++j)
        {
            _letterCombinations(digits,i+1,combinStr + str[j],strV);
                                        //取到的"a"因为j是0 // 下一层进来取到 "k" j是0 // 再下一层是 "t" j是0
        }
    }
    vector<string> letterCombinations(string digits) {
        string combinStr;
        vector<string> strV;

        if(digits.empty())
        {
            return strV;
        }
        _letterCombinations(digits,0,combinStr,strV);

        return strV;
    }
};
```

#### ！！！画一下递归展开图，总结后写题解！！！

？？？



### const 修饰的匿名对象，生命周期会延长

当没有构造函数，只有析构函数，对象出了这一行会直接析构，程序结束后 也可能再次调用析构函数。

当构造、析构函数同时存在，对象出了这一行则不会析构，直到出了当前函数作用域，才会析构。

