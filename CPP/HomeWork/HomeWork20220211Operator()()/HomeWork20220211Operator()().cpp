#include <iostream>
#include <conio.h>
#include <random>

int _TT()
{
    //그냥 10을 리턴해줌
    return 10;
}
class Test
{
public:
    using Test_type = int;
    Test() {}

    Test_type operator()()
    {
        return _TT();
    }
};
using Test2 = long;
class Test3
{
private:
    using Test_type = float;
    Test_type t1_;
    Test_type t2_;
public:
    Test3()
        :t1_(0), t2_(0)
    {

    }
    Test3(Test_type _t1, Test_type _t2)
        :t1_(_t1), t2_(_t2)
    {

    }
    Test_type operator()()
    {
        return 2;
    }
    Test2 operator()(Test2 t)
    {
        return t;
    }
};


int main()
{
    Test rd;
    int t = rd.operator()();
    Test2 t2(rd());
    Test3 t3(1.0, 20.0);
    t3(t2);
    //{
    //    std::random_device rd;
    //    //????????
    //    //using mt19937 = 
    //    //mersenne_twister_engine<unsigned int, 32, 624, 397, 31, 0x9908b0df, 11, 0xffffffff, 7, 0x9d2c5680, 15,
    //    //0xefc60000, 18, 1812433253>;
    //   std::mt19937 mt(rd());
    //   int test = 0;
    //   /* std::uniform_int_distribution<double>dist(10);
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        std::cout << dist(mt) << "\n";
    //    }*/
    //}
    //int t3;
    //int t4(t3());
    return 0;
}