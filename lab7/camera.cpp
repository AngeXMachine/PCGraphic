#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <iostream>

float xAlfa = 20; //чтобы "поднять голову" на 20 градусов вверх
float zAlfa = 0;
POINTFLOAT pos = {0,0}; //переменная отвечающая за положение игрока на карте

void MoveCamera()
{   if(GetKeyState(VK_UP)<0) xAlfa = ++xAlfa > 180? 180 : xAlfa; //смотреть вверх до 180 градусов
    if(GetKeyState(VK_DOWN)<0) xAlfa = --xAlfa < 0? 0 : xAlfa; //cмотреть вниз до 0 градусов
    if(GetKeyState(VK_LEFT)<0) zAlfa++; //поворачиваемся влево (двигаем СК вправо)
    if(GetKeyState(VK_RIGHT)<0) zAlfa--;
    float ugol = -zAlfa / 180 *M_PI;
    float speed = 0;
    if (GetKeyState('W')<0) speed =0.1; //ходим вперед
    if (GetKeyState('S')<0) speed = -0.1; // ходим назад
    if (GetKeyState('D')<0) {speed = -0.1; ugol -= M_PI*0.5;}
    if (GetKeyState('A')<0) {speed = -0.1; ugol += M_PI*0.5;}

    if (speed !=0)
    {
        pos.x += sin(ugol) * speed;
        pos.y += cos(ugol) * speed;
    }

    glRotatef(-xAlfa, 1,0,0); //поворачиваем СК минус потому что двигаем СК а не камеру (поворачивая СК в одну сторону поворачиваем камеру в другую)
    glRotatef(-zAlfa, 0,0,1);  //поворачиваем пол под ногами вокруг вертикальной оси до перемещения
    glTranslatef(-pos.x, -pos.y, -3); /*двигаем её от камеры, первые два аргумента
    отвечают за то чтобы камера смотрела на точку положения игрока,
    минусы также потому что мы двигаем не камеру, а СК*/
}
