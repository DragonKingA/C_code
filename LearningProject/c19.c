#include <stdio.h>
#include <Windows.h>


/*����
int WINAPI WinMain(
    HINSTANCE hInstance,    //��ʾ�������ı�
    HINSTANCE hPrevInstance,//��ʾ������ı�
    LPSTR IpCmdLine,
    int nCmdShow)
{
    //MessageBox()��������
    MessageBox(
    NULL,
    TEXT("Hello World"),
    TEXT("��ӭʹ�ã�"),
    MB_OKCANCEL);
    return 0;
}
*/

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//����Ӧ�ó�����Windows֮�佻����Ϣ�õ� ��Ϣ������ ���������ڽ��̱�д
//WndProc������ ����ֵ���� ��LRESULT�������͵ȼ���LONG��
//��WndProc���� ��������� ��CALLBACK
//�����˽� Windows����ṹ

//��ʼ���������������ں���

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow)
{
    static TCHAR szClassName[]=TEXT("HelloWin");//���� ��������
    HWND hwnd;//���ھ��,����������һЩ�����Ĳ������Զ�λ(ʶ��)�ô���
    //�����һ�����������ָ��.
    //��һ��Ӧ�ó���Ҫ��������ϵͳ�������ݿ⡢����ϵͳ����������ڴ������ʱ����Ҫʹ�þ����
    MSG msg;//��Ϣ
    WNDCLASS wndclass;//���� ������

    //��һ����ע�ᴰ����================================================================================================

    //�Դ����Ĵ����� wndclass ����ע��
    wndclass.style = CS_HREDRAW | CS_VREDRAW;//���ڷ��   ����д�� ���� ����˼
    wndclass.lpfnWndProc = WndProc;//���ڽ���
    wndclass.cbClsExtra = 0;//��ʱ����Ҫ���
    wndclass.cbWndExtra = 0;//��ʱ����Ҫ���
    wndclass.hInstance = hInstance;//��ǰ���ھ��
    wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);//����ͼ��
    wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);//�����ʽ
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ڱ�����ˢ
    //�����ʹ�ñ���ʱ���ܳ����⣬�޷����ú���GetStockObject
    //�ʱ���ʱӦ������gcc c19.c -mwindows��gcc c19.c -o a -mwindows
    wndclass.lpszMenuName = NULL;//���ڲ˵�
    wndclass.lpszClassName = szClassName;//����� ��������
    //���Բ�������󣬽��д���ע�����
    RegisterClass(&wndclass);
    /*
    ���� RegisterClass(lpWndClass) :
    RegisterClassע����ٵ���CreateWindow������CreateWindowEx������ʹ�õĴ����ࡣ
    RegisterClass���������ɺ���RegisterClassEx���������棬
    ���ǣ��������Ҫ����Сͼ������Ȼ����ʹ��RegisterClass����.
    ����� lpWndClass��ָ��һ��WNDCLASS�ṹ��ָ�롣�ڽ������ݸ�����֮ǰ�������ڸýṹ������ʵ��������ԡ�
    */

    //�ڶ�����������ʾ����================================================================================================

    hwnd = CreateWindow(
        szClassName,//�����������,�� ��������
        TEXT("Welcome!"),//���ڱ����ı�
        WS_OVERLAPPEDWINDOW,//���ڷ��
        CW_USEDEFAULT,//��ʼ��ʱx��λ��
        CW_USEDEFAULT,//��ʼ��ʱy���λ��
        500,//���ڿ��
        300,//���ڸ߶�
        NULL,//�����ھ��
        NULL,//���ڲ˵����
        hInstance,//��ǰ���ھ��
        NULL//��ʾ��ʹ�ø�ֵ
    );  

    //��ʾ����
    ShowWindow(hwnd,iCmdShow);

    //���ƣ����£�����
    UpdateWindow(hwnd);

    //����������Ϣѭ��===================================================================================================

    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);//������Ϣ
        DispatchMessage(&msg);//������Ϣ
    }

    return msg.wParam;
}   



//���Ĳ������ڹ���===================================================================================================

LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    HDC hdc;//�豸�������
    PAINTSTRUCT ps;
    RECT rect;
    
    switch(message){
        //���ڻ�����Ϣ
        case WM_PAINT:
        hdc = BeginPaint(hwnd,&ps);
        GetClientRect(hwnd,&rect);
        DrawText(
            hdc,
            TEXT("��һ�����ڳ���"),//TEXT()�����᷵��ANSI string
            -1,
            &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER
        );
        EndPaint(hwnd,&ps);//��ֹ����
        return 0;

        //����������Ϣ
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd,message,wParam,lParam);

}

//���� ���ڳ��� �Ѿ�����
//���ֱ����������������.vscode���޸�tasks.json
//��"args"�¼���"-mwindows"����








// void main(){
 
// }