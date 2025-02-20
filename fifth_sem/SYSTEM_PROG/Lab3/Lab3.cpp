// Lab3.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Lab3.h"
#include <stdlib.h>

#define MAX_LOADSTRING 100


#define ID_BUTTON_1 1
#define ID_BUTTON_2 2

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

BOOL DrawLine(HDC, int, int, int, int);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB3));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB3));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, (HMENU)NULL, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rc;
    static HWND hButton1;
    static HWND hButton2;
    switch (message)
    {
    case WM_CREATE:
        hButton1 = CreateWindow(L"Button", L"Click", WS_CHILD | WS_VISIBLE |
            BS_OWNERDRAW,
            300, 500, 50, 50,
            hWnd, (HMENU)ID_BUTTON_1, hInst, NULL);
        hButton2 = CreateWindow(L"Button", L"Click", WS_CHILD | WS_VISIBLE |
            BS_OWNERDRAW,
            370, 500, 50, 50,
            hWnd, (HMENU)ID_BUTTON_2, hInst, NULL);
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case ID_BUTTON_1:
            GetClientRect(hWnd, &rc);
            INT width;
            INT height;
            width = rc.right - rc.left;
            height = rc.bottom - rc.top;
            hdc = GetWindowDC(hWnd);
            Ellipse(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            Ellipse(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            Ellipse(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            Ellipse(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            DrawLine(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            DrawLine(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            DrawLine(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            Rectangle(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            Rectangle(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            Rectangle(hdc, rand() % width, rand() % height, rand() % width, rand() % height);
            POINT arr1[3];
            arr1[0] = { rand() % width, rand() % height };
            arr1[1] = { rand() % width, rand() % height };
            arr1[2] = { rand() % width, rand() % height };
            Polyline(hdc, arr1, 3);
            POINT arr2[3];
            arr2[0] = { rand() % width, rand() % height };
            arr2[1] = { rand() % width, rand() % height };
            arr2[2] = { rand() % width, rand() % height };
            Polyline(hdc, arr2, 3);
            POINT arr3[3];
            arr3[0] = { rand() % width, rand() % height };
            arr3[1] = { rand() % width, rand() % height };
            arr3[2] = { rand() % width, rand() % height };
            Polyline(hdc, arr3, 3);
            Arc(hdc, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height);
            Arc(hdc, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height);
            Arc(hdc, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height);
            Arc(hdc, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height);
            break;
        case ID_BUTTON_2:
            GetClientRect(hWnd, &rc);
            InvalidateRect(hWnd, &rc, TRUE);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DRAWITEM:
        LPDRAWITEMSTRUCT lpInfo;
        lpInfo = (LPDRAWITEMSTRUCT)lParam;
        if (lpInfo->CtlID == ID_BUTTON_1) {
            RECT rcItem;
            rcItem = lpInfo->rcItem;
            FillRect(lpInfo->hDC, &rcItem, CreateSolidBrush(RGB(255, 0, 0)));
        }
        if (lpInfo->CtlID == ID_BUTTON_2) {
            RECT rcItem;
            rcItem = lpInfo->rcItem;
            FillRect(lpInfo->hDC, &rcItem, CreateSolidBrush(RGB(0, 10, 0)));
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

BOOL DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
    POINT pt;
    MoveToEx(hdc, x1, y1, &pt);
    return LineTo(hdc, x2, y2);
}