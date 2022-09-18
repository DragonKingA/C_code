#include <stdio.h>
#include <Windows.h>
#include <string.h>//用于处理字符串
//tic-tac-toe游戏
//  X   O   O
//  O   X   
//  X   O   X
//X赢

//https://blog.csdn.net/weixin_29938387/article/details/117045031?ops_request_misc=&request_id=&biz_id=102&utm_term=c%E8%AF%AD%E8%A8%80%E5%AE%9E%E7%8E%B0%E7%AA%97%E5%8F%A3%E6%8C%89%E9%92%AE&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-117045031.142^v47^pc_rank_34_default_23,201^v3^control&spm=1018.2226.3001.4187

// void main(){
//     //创建3X3的棋盘
//     int board[3][3];
// }

/*
总体思路：
1.3x3棋盘数组创建
2.3x3棋盘窗口可视化
3.3x3棋盘9个按钮的创建
4.按钮逻辑实现：
    a.初始化按钮，文本为空
    b.按钮点击事件：X与O交替落子，改变点击按钮文本（默认X玩家先手）
5.胜负判定系统：
    定义判定函数judge()，每次落子执行判定函数judge()
    judge函数将判定每行、每列及两种斜向的落子情况，任一为3则胜，并返回1否则返回0
6.棋盘的重建
    judge()返回1时输出某方胜利提示，并决定是否继续，是则重建，否则结束程序
    重建即初始化按钮（整个游戏进行在一个大循环下，若重建则继续循环，否则break）
7.窗口的销毁，程序退出
*/








//以下声明用于实现游戏具体功能的函数==================================================================================================================
//定义一个窗口句柄类，作为按钮（按钮是一种子窗口）
static HWND hBtn,hBtn2,hBtn3,hBtn4,hBtn5,hBtn6,hBtn7,hBtn8,hBtn9;

//1.构建棋盘数组、初始化棋盘数组(0则为O,1则为X,-1则为空)
int board[3][3];
void BoardInit(void){//棋盘初始化为空
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = -1;
        }
    }
}



//2.落子交替 及 按钮锁死系统 ,0则锁死，1则开放,初始化为1
int ButtonLock[3][3];
void BtLockInit(void){
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            ButtonLock[i][j]=1;
        }
    }
}

int X_or_O(HWND button,int time,int n1,int n2){//n1为按钮横向标号,n2为按钮竖向标号
    if(ButtonLock[n1][n2]==1){
        if(time % 2 == 0){
            SetWindowText(button,TEXT("O"));
            board[n1][n2]=0;
        }else{
            SetWindowText(button,TEXT("X"));
            board[n1][n2]=1;
        }
        ButtonLock[n1][n2]=0;
        return 1;
    }
    return 0;
}//？？？：函数可以改变函数外数组变量的值，但不能改变函数外变量的值，只能传值（此处若填times++会没有实际影响到函数外的times变量？）


//*3.单步后胜负判定 及 弹窗选择系统（弹窗按钮参数选MB_YESNO，YES=继续游戏并分别记录O和X的胜场，NO=停止游戏），横竖的可以一起检查，[i][j]和[j][i]
//返回1则X胜，返回2则O胜，否则继续游戏
int ret = 0;
int Judger(void){
    int WhoseVictory = -1;
    int amount_X = 0;
    int amount_O = 0;
    for(int i = 0;i<3;i++){
        //判断横向
        for(int j=0;j<3;j++){
            
            if(board[i][j] == 1){//X
                amount_X++;
            }else if(board[i][j] == 0){//O
                amount_O++;
            }
        }
        if(amount_X == 3){
            return 1;
        }else if(amount_O == 3){
            return 2;
        }

        //重新初始化
        amount_O=0;
        amount_X=0;

        //判断竖向
        for(int z=0;z<3;z++){
            if(board[z][i] == 1){//X
                amount_X++;
            }else if(board[z][i] == 0){//O
                amount_O++;
            }
        }
        if(amount_X == 3){
            return 1;
        }else if(amount_O == 3){
            return 2;
        }

        //重新初始化
        amount_O=0;
        amount_X=0;

        //判断斜向右下
        for(int m=0;m<3;m++){
            if(board[m][m] == 1){//X
                amount_X++;
            }else if(board[m][m] == 0){//O
                amount_O++;
            }
        }
        if(amount_X == 3){
            return 1;
        }else if(amount_O == 3){
            return 2;
        }
        
        //重新初始化
        amount_O=0;
        amount_X=0;

        //判断斜向左上
        for(int h=2,k=0;h>=0;h--,k++){
            if(board[h][k] == 1){//X
                amount_X++;
            }else if(board[h][k] == 0){//O
                amount_O++;
            }
        }
        if(amount_X == 3){
            return 1;
        }else if(amount_O == 3){
            return 2;
        }
        
        //重新初始化
        amount_O=0;
        amount_X=0;
            
            
        
    }
    return 0;//继续游戏
}

//4.弹窗响应事件并统计双方胜负( 包含判胜负函数Judger()的运行 )
int O_NumOfVic=0,X_NumOfVic=0;//双方胜利场次初始化为0
//初始化落子次数
int times = 1;
void Judge_And_MsgBoxFeedback(int ret,HWND hwnd,int time_s){//hwnd为弹窗所有者（使弹窗置顶）,接收落子次数times判定是否已满盘
    int MsgBoxRet;
    ret = Judger();
    char strX[20];//存放字符类的X的胜场次
    char strO[20];//存放字符类的O的胜场次
    char strX_[20]="X玩家胜利场次为";
    char strO_[20]="O玩家胜利场次为";
    char strX_t[20]="X玩家胜利场次为";
    char strO_t[20]="O玩家胜利场次为";
    char strDraw[20]="双方平局";
    char str_result[20];//胜场结果统计
    //对判定结果进行逻辑分析
    if(ret != 0 ){
        if(ret == 1){
            X_NumOfVic++;
            itoa(X_NumOfVic,strX,10);
            strcat(strX_,strX);
            MsgBoxRet = MessageBox(hwnd,strX_,TEXT("Q:X赢,是否继续游戏？"),MB_YESNO);//hwnd作为弹窗的所有者
        }else if(ret == 2){
            O_NumOfVic++;
            itoa(O_NumOfVic,strO,10);
            strcat(strO_,strO);
            MsgBoxRet = MessageBox(hwnd,strO_,TEXT("Q:O赢,是否继续游戏？"),MB_YESNO);
        }
    }else if(time_s == 10){
            MsgBoxRet = MessageBox(hwnd,strDraw,TEXT("Q:是否继续游戏？"),MB_YESNO);
    }
    //用户在弹窗选择按钮的事件响应(是 则初始化游戏；否 则输出最终统计结果，而后再次判断最终胜家)
    if(MsgBoxRet == IDYES){//点击 是 时
        BtLockInit();
        BoardInit();
        times = 1;
        SetWindowText(hBtn,TEXT(""));
        SetWindowText(hBtn2,TEXT(""));
        SetWindowText(hBtn3,TEXT(""));
        SetWindowText(hBtn4,TEXT(""));
        SetWindowText(hBtn5,TEXT(""));
        SetWindowText(hBtn6,TEXT(""));
        SetWindowText(hBtn7,TEXT(""));
        SetWindowText(hBtn8,TEXT(""));
        SetWindowText(hBtn9,TEXT(""));
        //****************************想想怎么简化，怎么使一个函数能接收多个变量（接收9个按钮句柄）!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    }else if(MsgBoxRet == IDNO){
        //以下处理字符串文本
        itoa(X_NumOfVic,strX,10);
        strcat(strX_t,strX);
        itoa(O_NumOfVic,strO,10);
        strcat(strO_t,strO);
        strncat(strO_t,"\n",8);
        strncat(strDraw,"\n",8);
        strcat(strO_t,strX_t);
        
        if(X_NumOfVic > O_NumOfVic){
            MessageBox(hwnd,strO_t,TEXT("Judge:X玩家胜出"),MB_OK);
        }else if(X_NumOfVic < O_NumOfVic){
            MessageBox(hwnd,strO_t,TEXT("Judge:O玩家胜出"),MB_OK);
        }else{
            strcat(strDraw,strO_t);
            MessageBox(hwnd,strDraw,TEXT("Judge:"),MB_OK);
        }
        //判断最终胜家，然后输出最终统计结果
        //MessageBox(hwnd,TEXT(""),TEXT("结果统计:"),MB_OK);
        //初始化游戏参数
        O_NumOfVic=0,X_NumOfVic=0;//比上面的判定多了个初始化 胜场
        BtLockInit();
        BoardInit();
        times = 1;
        SetWindowText(hBtn,TEXT(""));
        SetWindowText(hBtn2,TEXT(""));
        SetWindowText(hBtn3,TEXT(""));
        SetWindowText(hBtn4,TEXT(""));
        SetWindowText(hBtn5,TEXT(""));
        SetWindowText(hBtn6,TEXT(""));
        SetWindowText(hBtn7,TEXT(""));
        SetWindowText(hBtn8,TEXT(""));
        SetWindowText(hBtn9,TEXT(""));
    }
}
//以上===============================================================================================================================================





//声明 窗口消息处理类
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//定义一个变量以记录窗口句柄，便于创建按钮
HINSTANCE hInst;

//一.定义 主窗口函数
int WINAPI  WinMain(
    HINSTANCE hInstance,//提示框内容文本
    HINSTANCE hPrevInstance,//提示框标题文本
    PSTR szCmdLine,//PSTR是以零结尾的字符串指针，相当于CHAR *
    int iCmdShow
){
    //游戏初始化基础参数（在窗口建立前）===============================================================================================================
    BtLockInit();
    BoardInit();
    //==============================================================================================================================================

    //创建 窗口类名szClassName
    static TCHAR szClassName[]=TEXT("HelloWin");//所有的字符串都是用TCHAR来定义的
    HWND hwnd;//定义 窗口句柄名为hwnd
    MSG msg;//消息
    WNDCLASS wndclass;//创建一个窗口类

    //存放窗口句柄,供按钮创建用
    hInst = hInstance;

    //二.注册窗口类wndclass (最好要写全所有参数)  查询API文档，了解窗口类参数
    wndclass.style = CS_HREDRAW | CS_VREDRAW;   //窗口风格
    wndclass.lpfnWndProc=WndProc;               //窗口进程
    wndclass.cbClsExtra=0;
    wndclass.cbWndExtra=0;
    wndclass.hInstance=hInstance;//当前窗口句柄
    wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);//窗口图标样式
    wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);//鼠标样式，cursor=光标
    wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName=NULL;//窗口菜单
    wndclass.lpszClassName=szClassName;//窗口类名
    //注册操作
    RegisterClass(&wndclass);

    //三.窗口显示
    hwnd = CreateWindow(
        szClassName,
        TEXT("Welcome"),
        WS_OVERLAPPED | WS_SYSMENU,
        //WS_OVERLAPPEDWINDOW:具有应用程序主窗口的全部特点。它的非客户区包括一个可伸缩的框架、菜单条、标题栏和最小化、最大化按钮
        //WS_OVERLAPPED只剩下主窗口，什么都没有，连关闭键和标题栏都没有
        //WS_SYSMENU附上关闭键和标题栏，提供关闭权限
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        186.5,//180+6.5
        210,//180+30
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    //显示窗口
    ShowWindow(hwnd,iCmdShow);
    //窗口更新
    UpdateWindow(hwnd);

    //四：消息循环
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);//翻译消息
        DispatchMessage(&msg);//分派消息
    }
    
    return msg.wParam;

}

//五：窗口过程(窗口消息处理类具体函数体)
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    int wmld;//按钮事件
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    //定义 逻辑字体名
    static HFONT hFont;
    

    switch(message){
        case WM_CREATE:
        //为按钮文本创建逻辑字体
        hFont = CreateFont(
            -60,//原高度-15
            -30,//原宽度-7.5,一般取高度的1/2
            0,
            0,
            FW_HEAVY,//原来为200，这里参数取值范围为0~1000
            FALSE,//是否带斜体,此处否
            FALSE,//是否带下划线,此处否
            FALSE,//是否带删除线,此处否
            DEFAULT_CHARSET,//使用默认字符集
            OUT_CHARACTER_PRECIS,
            CLIP_CHARACTER_PRECIS,//这两行暂时不理解
            DEFAULT_QUALITY,//使用默认输出质量
            FF_DONTCARE,//表示不指定字体族
            TEXT("微软雅黑")//字体名
        );

        //创建按钮控件(相当于创建一个子窗口)
        hBtn = CreateWindow(
            TEXT("button"),//按钮控件类名
            TEXT(""),//按钮文本
            WS_CHILD | WS_VISIBLE ,//扁平样式,这里删了WS_BORDER 和 BS_FLAT
            0,//X坐标
            0,//Y坐标
            60,//宽度
            60,//高度
            hwnd,//父窗口句柄
            (HMENU)2,//控件唯一标识符
            hInst,//按钮（子窗口）句柄
            NULL
        );
        //事后可以用函数简化创建按钮过程以节省内存！！！！！！！！！
        hBtn2=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,60,0,60,60,hwnd,(HMENU)3,hInst,NULL);
        hBtn3=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,120,0,60,60,hwnd,(HMENU)4,hInst,NULL);
        hBtn4=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,0,60,60,60,hwnd,(HMENU)5,hInst,NULL);
        hBtn5=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,60,60,60,60,hwnd,(HMENU)6,hInst,NULL);
        hBtn6=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,120,60,60,60,hwnd,(HMENU)7,hInst,NULL);
        hBtn7=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,0,120,60,60,hwnd,(HMENU)8,hInst,NULL);
        hBtn8=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,60,120,60,60,hwnd,(HMENU)9,hInst,NULL);
        hBtn9=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,120,120,60,60,hwnd,(HMENU)10,hInst,NULL);
        
        //将逻辑字体应用到按钮
        SendMessage(hBtn,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn2,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn3,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn4,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn5,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn6,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn7,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn8,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn9,WM_SETFONT,(WPARAM)hFont,lParam);
        //为什么最后一个参数都说填NULL??????但填lParam就可以运行？？？
        break;


        //按钮事件
        case WM_COMMAND:
        wmld = LOWORD(wParam);
        
        switch(wmld){
            //各个按钮点击事件！！！
            case 2:
            if(X_or_O(hBtn,times,0,0)){times++;}           
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 3:
            if(X_or_O(hBtn2,times,0,1)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 4:
            if(X_or_O(hBtn3,times,0,2)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 5:
            if(X_or_O(hBtn4,times,1,0)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 6:
            if(X_or_O(hBtn5,times,1,1)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 7:
            if(X_or_O(hBtn6,times,1,2)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 8:
            if(X_or_O(hBtn7,times,2,0)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 9:
            if(X_or_O(hBtn8,times,2,1)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            case 10:
            if(X_or_O(hBtn9,times,2,2)){times++;}
            Judge_And_MsgBoxFeedback(ret,hwnd,times);
            break;
            default://不处理的消息要交给DefWindowProc()函数处理
            return DefWindowProc(hwnd,message,wParam,lParam);
        }
        break;

        //若发送了WM_PAINT消息(message = WM_PAINT)时，则绘制窗口
        case WM_PAINT:
        hdc = BeginPaint(hwnd,&ps);
        GetClientRect(hwnd,&rect);
        /*  用于绘制主窗口界面文本(文本框)
            DrawText(
                hdc,
                TEXT("窗口程序"),
                -1,
                &rect,
                DT_SINGLELINE | DT_CENTER | DT_VCENTER            
            );                                          */
        //终止绘制
        EndPaint(hwnd,&ps);
        return 0;
        //若发送了WM_DESTROY消息,则销毁窗口
        case WM_DESTROY:
        DeleteObject(hFont);
        PostQuitMessage(0);
        //向系统表明有个线程有终止请求。通常用来响应WM_DESTROY消息,
        //其中填入的参数被用作消息WM_QUIT的wParam参数
        return 0;
    }

    return DefWindowProc(hwnd,message,wParam,lParam);

}
//窗口创建完毕
//终端编译指令：gcc game1.c -mwindows

