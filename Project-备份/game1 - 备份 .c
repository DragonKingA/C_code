#include <stdio.h>
#include <Windows.h>
#include <string.h>//���ڴ����ַ���
//tic-tac-toe��Ϸ
//  X   O   O
//  O   X   
//  X   O   X
//XӮ

//https://blog.csdn.net/weixin_29938387/article/details/117045031?ops_request_misc=&request_id=&biz_id=102&utm_term=c%E8%AF%AD%E8%A8%80%E5%AE%9E%E7%8E%B0%E7%AA%97%E5%8F%A3%E6%8C%89%E9%92%AE&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-117045031.142^v47^pc_rank_34_default_23,201^v3^control&spm=1018.2226.3001.4187

// void main(){
//     //����3X3������
//     int board[3][3];
// }

/*
����˼·��
1.3x3�������鴴��
2.3x3���̴��ڿ��ӻ�
3.3x3����9����ť�Ĵ���
4.��ť�߼�ʵ�֣�
    a.��ʼ����ť���ı�Ϊ��
    b.��ť����¼���X��O�������ӣ��ı�����ť�ı���Ĭ��X������֣�
5.ʤ���ж�ϵͳ��
    �����ж�����judge()��ÿ������ִ���ж�����judge()
    judge�������ж�ÿ�С�ÿ�м�����б��������������һΪ3��ʤ��������1���򷵻�0
6.���̵��ؽ�
    judge()����1ʱ���ĳ��ʤ����ʾ���������Ƿ�����������ؽ��������������
    �ؽ�����ʼ����ť��������Ϸ������һ����ѭ���£����ؽ������ѭ��������break��
7.���ڵ����٣������˳�
*/








//������������ʵ����Ϸ���幦�ܵĺ���==================================================================================================================
//����һ�����ھ���࣬��Ϊ��ť����ť��һ���Ӵ��ڣ�
static HWND hBtn,hBtn2,hBtn3,hBtn4,hBtn5,hBtn6,hBtn7,hBtn8,hBtn9;

//1.�����������顢��ʼ����������(0��ΪO,1��ΪX,-1��Ϊ��)
int board[3][3];
void BoardInit(void){//���̳�ʼ��Ϊ��
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = -1;
        }
    }
}



//2.���ӽ��� �� ��ť����ϵͳ ,0��������1�򿪷�,��ʼ��Ϊ1
int ButtonLock[3][3];
void BtLockInit(void){
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            ButtonLock[i][j]=1;
        }
    }
}

int X_or_O(HWND button,int time,int n1,int n2){//n1Ϊ��ť������,n2Ϊ��ť������
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
}//���������������Ըı亯�������������ֵ�������ܸı亯���������ֵ��ֻ�ܴ�ֵ���˴�����times++��û��ʵ��Ӱ�쵽�������times��������


//*3.������ʤ���ж� �� ����ѡ��ϵͳ��������ť����ѡMB_YESNO��YES=������Ϸ���ֱ��¼O��X��ʤ����NO=ֹͣ��Ϸ���������Ŀ���һ���飬[i][j]��[j][i]
//����1��Xʤ������2��Oʤ�����������Ϸ
int ret = 0;
int Judger(void){
    int WhoseVictory = -1;
    int amount_X = 0;
    int amount_O = 0;
    for(int i = 0;i<3;i++){
        //�жϺ���
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

        //���³�ʼ��
        amount_O=0;
        amount_X=0;

        //�ж�����
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

        //���³�ʼ��
        amount_O=0;
        amount_X=0;

        //�ж�б������
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
        
        //���³�ʼ��
        amount_O=0;
        amount_X=0;

        //�ж�б������
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
        
        //���³�ʼ��
        amount_O=0;
        amount_X=0;
            
            
        
    }
    return 0;//������Ϸ
}

//4.������Ӧ�¼���ͳ��˫��ʤ��( ������ʤ������Judger()������ )
int O_NumOfVic=0,X_NumOfVic=0;//˫��ʤ�����γ�ʼ��Ϊ0
//��ʼ�����Ӵ���
int times = 1;
void Judge_And_MsgBoxFeedback(int ret,HWND hwnd,int time_s){//hwndΪ���������ߣ�ʹ�����ö���,�������Ӵ���times�ж��Ƿ�������
    int MsgBoxRet;
    ret = Judger();
    char strX[20];//����ַ����X��ʤ����
    char strO[20];//����ַ����O��ʤ����
    char strX_[20]="X���ʤ������Ϊ";
    char strO_[20]="O���ʤ������Ϊ";
    char strX_t[20]="X���ʤ������Ϊ";
    char strO_t[20]="O���ʤ������Ϊ";
    char strDraw[20]="˫��ƽ��";
    char str_result[20];//ʤ�����ͳ��
    //���ж���������߼�����
    if(ret != 0 ){
        if(ret == 1){
            X_NumOfVic++;
            itoa(X_NumOfVic,strX,10);
            strcat(strX_,strX);
            MsgBoxRet = MessageBox(hwnd,strX_,TEXT("Q:XӮ,�Ƿ������Ϸ��"),MB_YESNO);//hwnd��Ϊ������������
        }else if(ret == 2){
            O_NumOfVic++;
            itoa(O_NumOfVic,strO,10);
            strcat(strO_,strO);
            MsgBoxRet = MessageBox(hwnd,strO_,TEXT("Q:OӮ,�Ƿ������Ϸ��"),MB_YESNO);
        }
    }else if(time_s == 10){
            MsgBoxRet = MessageBox(hwnd,strDraw,TEXT("Q:�Ƿ������Ϸ��"),MB_YESNO);
    }
    //�û��ڵ���ѡ��ť���¼���Ӧ(�� ���ʼ����Ϸ���� ���������ͳ�ƽ���������ٴ��ж�����ʤ��)
    if(MsgBoxRet == IDYES){//��� �� ʱ
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
        //****************************������ô�򻯣���ôʹһ�������ܽ��ն������������9����ť�����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    }else if(MsgBoxRet == IDNO){
        //���´����ַ����ı�
        itoa(X_NumOfVic,strX,10);
        strcat(strX_t,strX);
        itoa(O_NumOfVic,strO,10);
        strcat(strO_t,strO);
        strncat(strO_t,"\n",8);
        strncat(strDraw,"\n",8);
        strcat(strO_t,strX_t);
        
        if(X_NumOfVic > O_NumOfVic){
            MessageBox(hwnd,strO_t,TEXT("Judge:X���ʤ��"),MB_OK);
        }else if(X_NumOfVic < O_NumOfVic){
            MessageBox(hwnd,strO_t,TEXT("Judge:O���ʤ��"),MB_OK);
        }else{
            strcat(strDraw,strO_t);
            MessageBox(hwnd,strDraw,TEXT("Judge:"),MB_OK);
        }
        //�ж�����ʤ�ң�Ȼ���������ͳ�ƽ��
        //MessageBox(hwnd,TEXT(""),TEXT("���ͳ��:"),MB_OK);
        //��ʼ����Ϸ����
        O_NumOfVic=0,X_NumOfVic=0;//��������ж����˸���ʼ�� ʤ��
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
//����===============================================================================================================================================





//���� ������Ϣ������
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//����һ�������Լ�¼���ھ�������ڴ�����ť
HINSTANCE hInst;

//һ.���� �����ں���
int WINAPI  WinMain(
    HINSTANCE hInstance,//��ʾ�������ı�
    HINSTANCE hPrevInstance,//��ʾ������ı�
    PSTR szCmdLine,//PSTR�������β���ַ���ָ�룬�൱��CHAR *
    int iCmdShow
){
    //��Ϸ��ʼ�������������ڴ��ڽ���ǰ��===============================================================================================================
    BtLockInit();
    BoardInit();
    //==============================================================================================================================================

    //���� ��������szClassName
    static TCHAR szClassName[]=TEXT("HelloWin");//���е��ַ���������TCHAR�������
    HWND hwnd;//���� ���ھ����Ϊhwnd
    MSG msg;//��Ϣ
    WNDCLASS wndclass;//����һ��������

    //��Ŵ��ھ��,����ť������
    hInst = hInstance;

    //��.ע�ᴰ����wndclass (���Ҫдȫ���в���)  ��ѯAPI�ĵ����˽ⴰ�������
    wndclass.style = CS_HREDRAW | CS_VREDRAW;   //���ڷ��
    wndclass.lpfnWndProc=WndProc;               //���ڽ���
    wndclass.cbClsExtra=0;
    wndclass.cbWndExtra=0;
    wndclass.hInstance=hInstance;//��ǰ���ھ��
    wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);//����ͼ����ʽ
    wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);//�����ʽ��cursor=���
    wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName=NULL;//���ڲ˵�
    wndclass.lpszClassName=szClassName;//��������
    //ע�����
    RegisterClass(&wndclass);

    //��.������ʾ
    hwnd = CreateWindow(
        szClassName,
        TEXT("Welcome"),
        WS_OVERLAPPED | WS_SYSMENU,
        //WS_OVERLAPPEDWINDOW:����Ӧ�ó��������ڵ�ȫ���ص㡣���ķǿͻ�������һ���������Ŀ�ܡ��˵���������������С������󻯰�ť
        //WS_OVERLAPPEDֻʣ�������ڣ�ʲô��û�У����رռ��ͱ�������û��
        //WS_SYSMENU���Ϲرռ��ͱ��������ṩ�ر�Ȩ��
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        186.5,//180+6.5
        210,//180+30
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    //��ʾ����
    ShowWindow(hwnd,iCmdShow);
    //���ڸ���
    UpdateWindow(hwnd);

    //�ģ���Ϣѭ��
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);//������Ϣ
        DispatchMessage(&msg);//������Ϣ
    }
    
    return msg.wParam;

}

//�壺���ڹ���(������Ϣ��������庯����)
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    int wmld;//��ť�¼�
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    //���� �߼�������
    static HFONT hFont;
    

    switch(message){
        case WM_CREATE:
        //Ϊ��ť�ı������߼�����
        hFont = CreateFont(
            -60,//ԭ�߶�-15
            -30,//ԭ���-7.5,һ��ȡ�߶ȵ�1/2
            0,
            0,
            FW_HEAVY,//ԭ��Ϊ200���������ȡֵ��ΧΪ0~1000
            FALSE,//�Ƿ��б��,�˴���
            FALSE,//�Ƿ���»���,�˴���
            FALSE,//�Ƿ��ɾ����,�˴���
            DEFAULT_CHARSET,//ʹ��Ĭ���ַ���
            OUT_CHARACTER_PRECIS,
            CLIP_CHARACTER_PRECIS,//��������ʱ�����
            DEFAULT_QUALITY,//ʹ��Ĭ���������
            FF_DONTCARE,//��ʾ��ָ��������
            TEXT("΢���ź�")//������
        );

        //������ť�ؼ�(�൱�ڴ���һ���Ӵ���)
        hBtn = CreateWindow(
            TEXT("button"),//��ť�ؼ�����
            TEXT(""),//��ť�ı�
            WS_CHILD | WS_VISIBLE ,//��ƽ��ʽ,����ɾ��WS_BORDER �� BS_FLAT
            0,//X����
            0,//Y����
            60,//���
            60,//�߶�
            hwnd,//�����ھ��
            (HMENU)2,//�ؼ�Ψһ��ʶ��
            hInst,//��ť���Ӵ��ڣ����
            NULL
        );
        //�º�����ú����򻯴�����ť�����Խ�ʡ�ڴ棡����������������
        hBtn2=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,60,0,60,60,hwnd,(HMENU)3,hInst,NULL);
        hBtn3=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,120,0,60,60,hwnd,(HMENU)4,hInst,NULL);
        hBtn4=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,0,60,60,60,hwnd,(HMENU)5,hInst,NULL);
        hBtn5=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,60,60,60,60,hwnd,(HMENU)6,hInst,NULL);
        hBtn6=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,120,60,60,60,hwnd,(HMENU)7,hInst,NULL);
        hBtn7=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,0,120,60,60,hwnd,(HMENU)8,hInst,NULL);
        hBtn8=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,60,120,60,60,hwnd,(HMENU)9,hInst,NULL);
        hBtn9=CreateWindow(TEXT("button"),TEXT(""),WS_CHILD | WS_VISIBLE    ,120,120,60,60,hwnd,(HMENU)10,hInst,NULL);
        
        //���߼�����Ӧ�õ���ť
        SendMessage(hBtn,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn2,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn3,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn4,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn5,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn6,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn7,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn8,WM_SETFONT,(WPARAM)hFont,lParam);
        SendMessage(hBtn9,WM_SETFONT,(WPARAM)hFont,lParam);
        //Ϊʲô���һ��������˵��NULL??????����lParam�Ϳ������У�����
        break;


        //��ť�¼�
        case WM_COMMAND:
        wmld = LOWORD(wParam);
        
        switch(wmld){
            //������ť����¼�������
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
            default://���������ϢҪ����DefWindowProc()��������
            return DefWindowProc(hwnd,message,wParam,lParam);
        }
        break;

        //��������WM_PAINT��Ϣ(message = WM_PAINT)ʱ������ƴ���
        case WM_PAINT:
        hdc = BeginPaint(hwnd,&ps);
        GetClientRect(hwnd,&rect);
        /*  ���ڻ��������ڽ����ı�(�ı���)
            DrawText(
                hdc,
                TEXT("���ڳ���"),
                -1,
                &rect,
                DT_SINGLELINE | DT_CENTER | DT_VCENTER            
            );                                          */
        //��ֹ����
        EndPaint(hwnd,&ps);
        return 0;
        //��������WM_DESTROY��Ϣ,�����ٴ���
        case WM_DESTROY:
        DeleteObject(hFont);
        PostQuitMessage(0);
        //��ϵͳ�����и��߳�����ֹ����ͨ��������ӦWM_DESTROY��Ϣ,
        //��������Ĳ�����������ϢWM_QUIT��wParam����
        return 0;
    }

    return DefWindowProc(hwnd,message,wParam,lParam);

}
//���ڴ������
//�ն˱���ָ�gcc game1.c -mwindows

