#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include "camera.h"
#include "lighting.h"
float vert[] = {1,1,0, 1,-1,0, -1,-1,0, -1,1,0}; //каждые три числа описывают три координаты одной точки (x,y,z). т.к.  z=0, значит все точки лежат в плоскости xy и ось z "смотрит" вверх
//float normal[]={-1,-1,3, 1,-1,3, 1,1,3, -1,1,3}; //чтобы вектора нормалей были направленны не только вверх но и в стороны от центра


void ShowWorld()
{
    glNormal3f(0,0,1); //задаём вектор нормали
    glEnableClientState(GL_VERTEX_ARRAY); //разрешаем рисовать из массива вершин
    //glEnableClientState(GL_NORMAL_ARRAY); //разрешваем работать из массива нормалей

        glVertexPointer(3,GL_FLOAT,0, &vert); //указываем opengl на этот массив
        //glNormalPointer(GL_FLOAT,0,normal); //позволяет задавать маассив нормалей, 1-й парам. тип переменной вектора нормали, второй не используется, 3-й - адресс массима
            for(int i = -5; i<5;i++)
                for (int j = -5; j<5; j++)
            {
                glPushMatrix();
                    if((i+j)% 2 == 0) glColor3f(0,0.7,0.2);
                    else glColor3f(0.5,0.1,0.5);
                    glTranslatef(i*2,j*2, 0); //при размещении каждого квадратика перемещаемся в соответствующую точку
                    glDrawArrays(GL_TRIANGLE_FAN,0,4); //рисуем :)
                glPopMatrix();
            }

    glDisableClientState(GL_VERTEX_ARRAY);  //запрещаем рисовать из массива вершин
//    glDisableClientState(GL_NORMAL_ARRAY);  //запрещаем работать с массивом  нормалей

}

void drawPrisma(float weight, float height, int storon, float x, float y, float z, float transparency) {
    float angle = (2 * 3.14) / storon;

    glPushMatrix();

        glTranslatef(x, y, z);
        glBegin(GL_TRIANGLES); //определяет границы, внутри которых заданы вершины примитива или группы примитивов
        glEnable(GL_NORMALIZE); //Данная команда также ренормирует векторы нормали, если они изменились при геометрических преобразованиях, таких как масштабирование или сдвиг.
        glEnable(GL_COLOR_MATERIAL);//При включении GL_COLOR_MATERIAL для каждого материала или материалов, указанных лицом, параметр материала или параметры, заданные режимом , отслеживают текущий цвет в любое время.
        for (int i = 0; i < storon; ++i) {
            GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, transparency };
            GLfloat mat_ambient[] = { 1.0f, 1.0f, 1.0f, transparency };
            glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
            glColor4f(0., 0.7, 0.7, transparency);

            float x1 = (weight * cos(i * angle))*0.8;
            float y1 = (weight * sin(i * angle))*0.8;
            float z1 = 0;

            float x2 = (weight * cos((i + 1) * angle))*0.8;
            float y2 = (weight * sin((i + 1) * angle))*0.8;
            float z2 = 0;

            // отрисовка треугольников и низа и верха призмы
            glNormal3f(x1, y1, 0.0f);
            glVertex3f(x1, y1, z1);
            glNormal3f(x2, y2, 0.0f);
            glVertex3f(x2, y2, z2);
            glNormal3f(x1, y1, 0.0f);
            glVertex3f(x1, y1, z1 + height);

            glNormal3f(x1, y1, 0.0f);
            glVertex3f(x1, y1, z1 + height);
            glNormal3f(x2, y2, 0.0f);
            glVertex3f(x2, y2, z2);
            glNormal3f(x2, y2, 0.0f);
            glVertex3f(x2, y2, z2 + height);

            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x1, y1, z1);

            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, z1 + height);
            glVertex3f(x1, y1, z1 + height);
            glVertex3f(x2, y2, z2 + height);
        }

        glEnd();

    glPopMatrix();
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


    glMatrixMode(GL_PROJECTION);  // задаём текущую матрицу, в данном случае матрица проекции, т.к. устанавливать проекцию необходимо именно в ней
    glLoadIdentity();
    glFrustum(-1,1, -1,1, 2,80);/*умножает текущую матрицу на перспективную матрицу.  В ней последовательно указываются координаты для
левой и правой вертикальных плоскостей отсечения, для нижней и
верхней горизонтальных плоскостей отсечения и в конце расстояния до
плоскостей отсечения ближней и дальней глубины.*/
    glMatrixMode(GL_MODELVIEW); //устанавливается поумолчанию, в этот матрице рисуются все объекты и устанавливается освещение
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST); //тест глубины

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
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очистка буфера глубины в каждом кадре

            glPushMatrix(); //сохраняем текущую систему координат

                MoveCamera();//изменяем СК

                drawPrisma(1,2,16,0,0,0,1);
                drawPrisma(1,2,16,0,2,0,0.9);
                drawPrisma(1,2,16,0,4,0,0.6);
                drawPrisma(1,2,16,0,6,0,0.4);
                drawPrisma(1,2,16,0,8,0,0.2);
                drawPrisma(1,2,16,0,10,0,0.1);

                ShowWorld();  //Рисуем изображение

                Init_Material();
                Init_Light();

            glPopMatrix();  //загружаем сохраненную систему координат

            SwapBuffers(hDC);

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

