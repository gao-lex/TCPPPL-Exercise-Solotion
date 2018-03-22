* 1 Take some not-too-large program that uses at least one library that does not use namespaces and modify it to use a namespace for that library.

```C++
//do not use namespcae
#include<iostream>
#include<vector>
int main()
{
    std::vector<int> v {1,2,3,4};
    std::cout<<"hello,world"<<std::endl;
    return 0;
}
```

```C++
//do not use namespcae
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v {1,2,3,4};
    cout<<"hello,world"<<endl;
    return 0;
}
```

---

* 2 Modify the desk calculator program into a module with a simple interface specifying calls and potential errors. Don’t expose implemetation details to users. Don’t make it easy for users to supply bad data. Don’t use any global using-directives. Keep a record of the mistakes you made. Suggest ways of avoiding such mistakes in the future.

修改台式计算器程序与一个简单的接口模块指定调用和潜在的错误。不要让implemetation细节给用户。不方便用户提供错误数据。不要使用任何全局using引用。记录你所犯的错误。建议的方法避免这样的错误在未来。