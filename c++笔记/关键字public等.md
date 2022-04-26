>  [C++](http://c.biancheng.net/cplus/)通过 public、protected、private 三个关键字来控制成员变量和成员函数的访问权限，它们分别表示公有的、受保护的、私有的，被称为成员访问限定符。所谓访问权限，就是你能不能使用该类中的成员。

__C++ 中的 public、private、protected 只能修饰类的成员，不能修饰类，C++中的类没有共有私有之分。__

**在类的内部**（定义类的代码内部），无论成员被声明为 public、protected 还是 private，都是可以互相访问的，没有访问权限的限制。

 **在类的外部**（定义类的代码之外），只能通过对象访问成员，并且通过对象只能访问 public 属性的成员，不能访问 private、protected 属性的成员。

~~~c++
    #include <iostream>
    using namespace std;
    //类的声明
    class Student{
    private:  //私有的
        char *m_name;
        int m_age;
        float m_score;
    public:  //共有的
        void setname(char *name);
        void setage(int age);
        void setscore(float score);
        void show();
    };
    //成员函数的定义
    void Student::setname(char *name){
        m_name = name;
    }
    void Student::setage(int age){
        m_age = age;
    }
    void Student::setscore(float score){
        m_score = score;
    }
    void Student::show(){
        cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
    }
    int main(){
        //在栈上创建对象
        Student stu;
        stu.setname("小明");
        stu.setage(15);
        stu.setscore(92.5f);
        stu.show();
        //在堆上创建对象
        Student *pstu = new Student;
        pstu -> setname("李华");
        pstu -> setage(16);
        pstu -> setscore(96);
        pstu -> show();
        return 0;
    }
~~~

`类中的成员变量 m_name、m_age 和m_ score 被设置成 private 属性，在类的外部不能通过对象访问。也就是说，私有成员变量和成员函数只能在类内部使用，在类外都是无效的。`

**类的封装**

根据C++软件设计规范，实际项目开发中的成员变量以及只在类内部使用的成员函数（只被成员函数调用的成员函数）都建议声明为 private，而只将允许通过对象调用的成员函数声明为 public。

> 给成员变量赋值的函数通常称为 set 函数，它们的名字通常以`set`开头，后跟成员变量的名字；读取成员变量的值的函数通常称为 get 函数，它们的名字通常以`get`开头，后跟成员变量的名字。