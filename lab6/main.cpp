#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include "camera.h"
#include "lighting.h"
float vert[] = {1,1,0, 1,-1,0, -1,-1,0, -1,1,0}; //������ ��� ����� ��������� ��� ���������� ����� ����� (x,y,z). �.�.  z=0, ������ ��� ����� ����� � ��������� xy � ��� z "�������" �����
float vert1[] = {1,1,5, 1,-1,5, -1,-1,5, -1,1,5};
float normal[]={-1,-1,3, 1,-1,3, 1,1,3, -1,1,3}; //����� ������� �������� ���� ����������� �� ������ ����� �� � � ������� �� ������


void ShowWorld()
{
    //glNormal3f(0,0,1); //����� ������ �������
    glEnableClientState(GL_VERTEX_ARRAY); //��������� �������� �� ������� ������
    glEnableClientState(GL_NORMAL_ARRAY); //���������� �������� �� ������� ��������

        glVertexPointer(3,GL_FLOAT,0, &vert); //��������� opengl �� ���� ������
        glNormalPointer(GL_FLOAT,0,normal); //��������� �������� ������� ��������, 1-� �����. ��� ���������� ������� �������, ������ �� ������������, 3-� - ������ �������
            for(int i = -5; i<5;i++)
                for (int j = -5; j<5; j++)
            {
                glPushMatrix();
                    if((i+j)% 2 == 0) glColor3f(0,0.7,0.2);
                    else glColor3f(0.5,0.1,0.5);
                    glTranslatef(i*2,j*2, 0); //��� ���������� ������� ���������� ������������ � ��������������� �����
                    glDrawArrays(GL_TRIANGLE_FAN,0,4); //������ :)
                glPopMatrix();
            }

    glDisableClientState(GL_VERTEX_ARRAY);  //��������� �������� �� ������� ������
    glDisableClientState(GL_NORMAL_ARRAY);  //��������� �������� � ��������  ��������

}

void Draw(){
    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, &vert1);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

}
/*void DrawLine(){
    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(1,1,1);
        glVertex3f(1,1,10);

        glColor3f(0,1,0);
        glVertex3f(1,1,1);
        glVertex3f(1,10,1);

        glColor3f(0,0,1);
        glVertex3f(1,1,1);
        glVertex3f(10,1,1);
    glEnd();
}*/

void glDrawStartTriangle(){
    glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(1.0f, 1.0f, 1.0f);

      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f( 2.0f,  3.0f, 1.0f);

      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f( 3.0f, 1.0f, 1.0f);
    glEnd();
}

void Draw_Cube(){
    GLfloat vertices[] = {
     -1.f, -1.f, 0.f,
     1.f, -1.f, 0.f,
     1.f, 1.f, 0.f,
     -1.f, 1.f, 0.f,
     -1.f, -1.f, 2.f,
     1.f, -1.f, 2.f,
     1.f, 1.f, 2.f,
     -1.f, 1.f, 2.f
    };
    GLuint indices[] = {
     0, 1, 2,
     2, 3, 0,
     1, 5, 6,
     6, 2, 1,
     7, 6, 5,
     5, 4, 7,
     4, 0, 3,
     3, 7, 4,
     4, 5, 1,
     1, 0, 4,
     3, 2, 6,
     6, 7, 3
    };
    GLfloat normals[] = {
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, 1.0f,
     0.0f, 0.0f, 1.0f,
     0.0f, 0.0f, 1.0f,
     0.0f, 0.0f, 1.0f,
     -1.0f, 0.0f, 0.0f,
     -1.0f, 0.0f, 0.0f,
     -1.0f, 0.0f, 0.0f,
     -1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 1.0f, 0.0f
    };
    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glEnableClientState(GL_NORMAL_ARRAY);
            glNormalPointer(GL_FLOAT, 0, normals);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}


LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);



int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1080,
                          720,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);
    glMatrixMode(GL_PROJECTION);  // ����� ������� �������, � ������ ������ ������� ��������, �.�. ������������� �������� ���������� ������ � ���
    glLoadIdentity();
    glFrustum(-1,1, -1,1, 2,80);/*�������� ������� ������� �� ������������� �������.  � ��� ��������������� ����������� ���������� ���
����� � ������ ������������ ���������� ���������, ��� ������ �
������� �������������� ���������� ��������� � � ����� ���������� ��
���������� ��������� ������� � ������� �������.*/
    glMatrixMode(GL_MODELVIEW); //��������������� �����������, � ���� ������� �������� ��� ������� � ��������������� ���������
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST); //���� �������

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);




    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //������� ������ ������� � ������ �����

            glPushMatrix(); //��������� ������� ������� ���������
                MoveCamera(); //�������� ��
                ShowWorld();  //������ �����������
                Draw_Cube();

                glPushMatrix();
                    glRotatef(90, 0.0, 0, 1);
                    glRotatef(theta, 0.0, 1.0, 0.0); //������������ ��� �� ������ ��� y
                    on_light();// ������� ��������� �� lighting.h
                    glTranslatef(0.0, 0.0, 1);		//��������� ����� ������� ���������

                    glColor3f(1,1,1);
                    Draw();
                glPopMatrix();
            glPopMatrix();  //��������� ����������� ������� ���������

            SwapBuffers(hDC);

                theta += 1;

            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

