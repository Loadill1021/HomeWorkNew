// HomeWork20220216GameArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <assert.h>
#include <crtdbg.h>
using DataType = int;

//template<typename DataType>
class GameArray
{
private:
    int Size_;
    DataType* ArrData_;
public:
    int GetSize()
    {
        return Size_;
    }
    DataType& operator[](int _Index)
    {
        if (Size_<=_Index)
        {
            assert(false);
        }
        return ArrData_[_Index];
    }
    //배열에서 한번의 대입만 허용하겠다.
    void operator=(const GameArray& _Other)
    {
        // 이걸 쉘로우 카피
        // 혹은 얕은 복사라고 한다.
        /*this->ArrData_ = _Other.ArrData_;
        this->Size_ = _Other.Size_;*/

        // 이걸 딥 카피
        // 혹은 깊은 복사라고 한다.
        ReSize(_Other.Size_);
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }
    }
    //안전성을 위해서 선생님께서는 안쓰신다.
    //GameArray& operator=(const GameArray& _Other)
    //{
    //    // 이걸 쉘로우 카피
    //    // 혹은 얕은 복사라고 한다.
    //    /*this->ArrData_ = _Other.ArrData_;
    //    this->Size_ = _Other.Size_;*/

    //    // 이걸 딥 카피
    //    // 혹은 깊은 복사라고 한다.

    //    for (size_t i = 0; i < this->Size_; i++)
    //    {
    //        this->ArrData_[i] = _Other.ArrData_[i];
    //    }
    //    return *this;
    //}
    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }
    
    inline void Release()
    {
        if (true)
        {
            delete[]ArrData_;
            ArrData_ = nullptr;
        }
    }
    //무조건 지우고 사이즈를 늘려준다.
    void ReSize(unsigned int _Size)
    {
        //두가지 상황
        //작아질수도 있고 커질수도 있다. 원하는대로 해결
        //기존의 데이터를 보존하고
        
        if (this->Size_ >= _Size)
        {
            return;
        }
        
        
        DataType* Temp = new DataType[_Size];
        for (size_t i = 0; i < this->Size_; i++)
        {
            Temp[i] = ArrData_[i];
        }
        this->Size_ = _Size;
        Release();
        ArrData_ = Temp;
        Temp = nullptr;
    }
public:
    GameArray(unsigned int _Size)
        :ArrData_(nullptr)
        ,Size_(0)
        //:ArrData_(new DataType[_Size])
        //,Size_(_Size)
    {
        ReSize(_Size);//인터페이스 통일
    }
    ~GameArray()
    {
        Release();
        //if (nullptr != ArrData_)
        //{
           // delete[]ArrData_;
            //ArrData_ = nullptr;
        //}
    }
};


int main()
{
    //NewArray2.ReSize(20);
    //오늘의 숙제 ReSize를 해도 기존에 데이터가 있다면 기존의 데이터를 유지 할 수 있도록 만들기
    //GameArray NewArray=GameArray(10)
    //GameArray NewArray2=GameArray(20)
    //NewArray2=NewArray; 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //GameArray NewArray = GameArray(10);
    //GameArray NewArray2 = GameArray(10);

    GameArray NewArray = GameArray(10);
    GameArray NewArray2 = GameArray(20);
    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        NewArray2[i] = i;
    }
    NewArray.AllValueSetting(3);
    NewArray2.AllValueSetting(1);
    NewArray2 = NewArray;


    NewArray2.AllValueSetting(1);
    NewArray2.ReSize(21);

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }

    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
