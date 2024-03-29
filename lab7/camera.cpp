#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <iostream>

float xAlfa = 20; //����� "������� ������" �� 20 �������� �����
float zAlfa = 0;
POINTFLOAT pos = {0,0}; //���������� ���������� �� ��������� ������ �� �����

void MoveCamera()
{   if(GetKeyState(VK_UP)<0) xAlfa = ++xAlfa > 180? 180 : xAlfa; //�������� ����� �� 180 ��������
    if(GetKeyState(VK_DOWN)<0) xAlfa = --xAlfa < 0? 0 : xAlfa; //c������� ���� �� 0 ��������
    if(GetKeyState(VK_LEFT)<0) zAlfa++; //�������������� ����� (������� �� ������)
    if(GetKeyState(VK_RIGHT)<0) zAlfa--;
    float ugol = -zAlfa / 180 *M_PI;
    float speed = 0;
    if (GetKeyState('W')<0) speed =0.1; //����� ������
    if (GetKeyState('S')<0) speed = -0.1; // ����� �����
    if (GetKeyState('D')<0) {speed = -0.1; ugol -= M_PI*0.5;}
    if (GetKeyState('A')<0) {speed = -0.1; ugol += M_PI*0.5;}

    if (speed !=0)
    {
        pos.x += sin(ugol) * speed;
        pos.y += cos(ugol) * speed;
    }

    glRotatef(-xAlfa, 1,0,0); //������������ �� ����� ������ ��� ������� �� � �� ������ (����������� �� � ���� ������� ������������ ������ � ������)
    glRotatef(-zAlfa, 0,0,1);  //������������ ��� ��� ������ ������ ������������ ��� �� �����������
    glTranslatef(-pos.x, -pos.y, -3); /*������� � �� ������, ������ ��� ���������
    �������� �� �� ����� ������ �������� �� ����� ��������� ������,
    ������ ����� ������ ��� �� ������� �� ������, � ��*/
}
