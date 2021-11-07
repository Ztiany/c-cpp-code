/*
 ============================================================================

 Author      : Ztiany
 Description : 基础数据类型

 ============================================================================
 */

#include <iostream>//输入输出
#include <climits>//包含各种整型类型的系统限制
#include <cfloat>//包含各种浮点类型的系统限制
#include <cstdlib>//标准库

void integer_type() {
    /*-----------------short类型-----------------*/
    short sa = 22;
    unsigned short usa = 32u;//u作为后缀表示无符号，用于指定字面值类型


    /*-----------------int类型-----------------*/
    int a; //a是不确定的
    int b(2);
    int c{3};
    int d = {4};
    int e{};// e = 0，C++11的列表初始化
    unsigned int f;
    unsigned quarterback;//不指定类型，默认是int
    int g = 02;//八进制
    int h = 0xF;//十六进制
    //堆中申请int
    int *newInt = new int;
    delete (newInt);


    /*-----------------long类型-----------------*/
    long la = 32;
    long long lla = 332;
    unsigned long long ulla = 32ULL;//ULL是后缀
}

void char_type() {
    /*-----------------char类型-----------------*/
    //char在默认的情况下既不是有符号的，也不是无符号的，是否有符号由c++实现决定。
    //char确保可以表示机器上的所有基本字符集，一个char的大小和一个机器字节大小一样。
    char i = 'a';
    int j = i;

    //字符：wchar_t是一种整数类型，它有足够的空间，可以表示系统的最大扩展字符集
    //wchar_t底层的类型取决于编译器实现，在一种系统中可能是unsigned short，在另一种系统中又可能是int。
    //cin和cout将输入和输出看作是字符流，因此不适合用来处理whcar_t类型。
    wchar_t w_char = L'我';
    wchar_t l_w_char = L'p';//使用L来指示宽字符常量和宽字符串
    wprintf(L"Characters: %lc %lc \n", L'a', w_char);

    //C11：char16_t和char32_t是内置类型，用于处理unicode字符，它们都是无符号的，但是底层类型可能跟随系统
    char16_t char_16 = u'q';
    char32_t char_32 = U'我';
}

void bool_type() {
    /*-----------------布尔类型-----------------*/
    bool is_real = true;
    bool stop = 1;
    bool start = 0;
}

void float_type() {
    /*-----------------浮点类型-----------------*/
    //浮点常量默认为double
    float l = 32.3;
    double n = 32.323;
    float m = 32.333F;
    long double ldm = 323.32L;
    float max = FLT_MAX;
}

void type_conversation() {
    /*-----------------类型转换-----------------*/
    int o = (int) (33.3);//转换为33
    int p = (int) 32.3;
    //int q = {32.3}; //大括号"{}"的方式很严格，不允许这种操作【不会自动转换】。
    int q = {33};//这种才行

    /*-----------------定义常量-----------------*/
    //定义常量，应该使用const来定义常量，而不是#defind
    const int k = 32;
}

void sizeof_and_limitation() {
    /*-----------------数据类型的大小-----------------*/
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "INT_MIN = " << INT_MIN << std::endl;
    std::cout << "INT_MAX = " << INT_MAX << std::endl;
    std::cout << "CHAR_BIT = " << CHAR_BIT << std::endl;
    std::cout << "LONG_MAX = " << LONG_MAX << std::endl;
    std::cout << "LONG_MAX = " << FLT_MAX << std::endl;
}

void unsigned_type() {
    /*-----------------无符号类型计算-----------------*/
    //不要混用有符号类型的数据和无符号类型的数据
    int va = -1;
    unsigned int vb = 1;
    int vc = va * vb;//此时va会自动转为为无符号类型的整数
}

int main() {
    integer_type();
    char_type();
    bool_type();
    float_type();
    type_conversation();
    sizeof_and_limitation();
    unsigned_type();
    return EXIT_SUCCESS;
}