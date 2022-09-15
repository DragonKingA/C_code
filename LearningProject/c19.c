#include <stdio.h>
#include <Windows.h>


/*弹窗
int WINAPI WinMain(
    HINSTANCE hInstance,    //提示框内容文本
    HINSTANCE hPrevInstance,//提示框标题文本
    LPSTR IpCmdLine,
    int nCmdShow)
{
    //MessageBox()弹窗函数
    MessageBox(
    NULL,
    TEXT("Hello World"),
    TEXT("欢迎使用！"),
    MB_OKCANCEL);
    return 0;
}

返回值：如果没有足够的内存来创建消息框，则返回值为零。如果函数调用成功，则返回值为下列对话框返回的菜单项目值中的一个：
　　IDABORT：Abort 按钮被选中。IDCANCEL：Cancel按钮被选中。IDIGNORE：Ignore按钮被选中。
　　IDNO：NO按钮被选中。IDOK：OK按钮被选中。IDRETRY：RETRY按钮被选中。
　　IDYES：YES按钮被选中。
　　如果一个消息框有一个Cancel按钮，且如果Esc键被按下或Cancel键被选择，则函数返回IDCANCEL值。如果消息框没有Cancel按钮，则按Esc键没有作用。
MessageBox的返回值宏有：
#define IDOK                      1
#define IDCANCEL                  2
#define IDABORT                   3
#define IDRETRY                   4
#define IDIGNORE                  5
#define IDYES                     6
#define IDNO                      7


*/

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//这是应用程序与Windows之间交互消息用的 消息处理函数 ，创建窗口进程必写
//WndProc函数的 返回值类型 是LRESULT，该类型等价于LONG，
//而WndProc函数 自身的类型 是CALLBACK
//详情了解 Windows程序结构

//初始操作：定义主窗口函数

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow)
{
    static TCHAR szClassName[]=TEXT("HelloWin");//创建 窗口类名
    HWND hwnd;//窗口句柄,后续会用于一些函数的参数，以定位(识别)该窗口
    //句柄是一种特殊的智能指针.
    //当一个应用程序要引用其他系统（如数据库、操作系统）所管理的内存块或对象时，就要使用句柄。
    MSG msg;//消息
    WNDCLASS wndclass;//创建 窗口类

    //第一步：注册窗口类================================================================================================

    //对创建的窗口类 wndclass 进行注册
    wndclass.style = CS_HREDRAW | CS_VREDRAW;//窗口风格   这样写是 并集 的意思
    wndclass.lpfnWndProc = WndProc;//窗口进程
    wndclass.cbClsExtra = 0;//暂时不需要理解
    wndclass.cbWndExtra = 0;//暂时不需要理解
    wndclass.hInstance = hInstance;//当前窗口句柄
    wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);//窗口图标
    wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);//鼠标样式
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//窗口背景画刷
    //该语句使得编译时可能出问题，无法调用函数GetStockObject
    //故编译时应当输入gcc c19.c -mwindows或gcc c19.c -o a -mwindows
    wndclass.lpszMenuName = NULL;//窗口菜单
    wndclass.lpszClassName = szClassName;//填创建的 窗口类名
    //属性参数输入后，进行窗口注册操作
    RegisterClass(&wndclass);
    /*
    函数 RegisterClass(lpWndClass) :
    RegisterClass注册后再调用CreateWindow函数和CreateWindowEx函数中使用的窗口类。
    RegisterClass函数己经由函数RegisterClassEx函数来代替，
    但是，如果不需要设置小图标则仍然可以使用RegisterClass函数.
    其参数 lpWndClass：指向一个WNDCLASS结构的指针。在将它传递给函数之前，必须在该结构中填充适当的类属性。
    */

    //第二步：创建显示窗口================================================================================================

    hwnd = CreateWindow(
        szClassName,//窗口类的名字,即 窗口类名
        TEXT("Welcome!"),//窗口标题文本
        WS_OVERLAPPEDWINDOW,//窗口风格
        CW_USEDEFAULT,//初始化时x轴位置
        CW_USEDEFAULT,//初始化时y轴的位置
        500,//窗口宽度
        300,//窗口高度
        NULL,//父窗口句柄
        NULL,//窗口菜单句柄
        hInstance,//当前窗口句柄
        NULL//表示不使用该值
    );  

    //显示窗口
    ShowWindow(hwnd,iCmdShow);

    //更新窗口：UpdateWindow()会更新指定窗口的客户区
    UpdateWindow(hwnd);

    //第三步：消息循环===================================================================================================

    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);//翻译消息:将虚拟键消息转换为字符消息
        DispatchMessage(&msg);//分派消息
    }

    return msg.wParam;
}   



//第四步：窗口过程===================================================================================================

LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    HDC hdc;//设备环境句柄
    PAINTSTRUCT ps;
    RECT rect;
    
    switch(message){
        //窗口绘制消息
        case WM_PAINT:
        hdc = BeginPaint(hwnd,&ps);
        GetClientRect(hwnd,&rect);
        DrawText(
            hdc,
            TEXT("第一个窗口程序"),//TEXT()函数会返回ANSI string
            -1,//填入指向字符串中的字符数。如果nCount为-1，则lpString指向的字符串被认为是以\0结束的，DrawText会自动计算字符数。
            &rect,//填入指向结构RECT的指针，其中包含文本将被置于其中的矩形的信息（按逻辑坐标）
            DT_SINGLELINE | DT_CENTER | DT_VCENTER
        );
        EndPaint(hwnd,&ps);//终止绘制
        return 0;

        //窗口销毁消息
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd,message,wParam,lParam);

}

//至此 窗口程序 已经完善
//出现编译错误情况，在左侧.vscode中修改tasks.json
//在"args"下加入"-mwindows"即可
//或编译时应当输入gcc c19.c -mwindows或gcc c19.c -o a -mwindows







// void main(){
 
// }