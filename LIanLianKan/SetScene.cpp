#include "Control.h"
#include "SetScene.h"
extern Control *now;

/**
 * @brief Set the Scene object
 *
 * @param last_ 来源页面
 */
SetScene::SetScene(Scene *last_) : last{ last_ }
{
    now->scene = this;
}

/**
 * @brief 更新画面
 *
 * 按顺序从底层到顶层逐一更新画面
 */
void SetScene::update()
{
    /*动态背景*/
    now->bgnow++;

    if (now->bgnow == 49)
    {
        now->bgnow = 0;
    }

    char *s = new char[50];
    sprintf_s(s, 50, "./Pic/bgvideo/bgvideo%02d.png", now->bgnow);
    now->putImage(s, 0, 0, 960, 640);
    delete[] s;

    /*按钮*/
    now->putImage("./Pic/setTitle.png", 290, 50, 387, 111);
    now->putImage("./Pic/music.png", 40, 210, 127, 37);
    now->putImage("./Pic/voice.png", 40, 360, 127, 37);
    now->putImage("./Pic/Set/music.png", 125, 205, 50, 50);
    now->putImage("./Pic/Set/sound.png", 125, 353, 50, 50);
    now->putImage("./Pic/Set/minus.png", 395, 275, 50, 50);
    now->putImage("./Pic/Set/plus.png", 515, 275, 50, 50);
    now->putImage("./Pic/Set/minus.png", 395, 425, 50, 50);
    now->putImage("./Pic/Set/plus.png", 515, 425, 50, 50);
    now->putImage("./Pic/Set/home.png", 455, 560, 50, 50);

    /*音量*/
    if (0.25 == now->getVolm1())
    {
        now->putImage("./Pic/Set/1.png", 200, 225, 140, 15);
    }

    if (0.50 == now->getVolm1())
    {
        now->putImage("./Pic/Set/1.png", 200, 225, 140, 15);
        now->putImage("./Pic/Set/2.png", 340, 225, 140, 15);
    }

    if (0.75 == now->getVolm1())
    {
        now->putImage("./Pic/Set/1.png", 200, 225, 140, 15);
        now->putImage("./Pic/Set/2.png", 340, 225, 140, 15);
        now->putImage("./Pic/Set/3.png", 480, 225, 140, 15);
    }

    if (1.00 == now->getVolm1())
    {
        now->putImage("./Pic/Set/1.png", 200, 225, 140, 15);
        now->putImage("./Pic/Set/2.png", 340, 225, 140, 15);
        now->putImage("./Pic/Set/3.png", 480, 225, 140, 15);
        now->putImage("./Pic/Set/4.png", 620, 225, 140, 15);
    }

    if (0.25 == now->getVolm2())
    {
        now->putImage("./Pic/Set/5.png", 210, 370, 133, 17);
    }

    if (0.50 == now->getVolm2())
    {
        now->putImage("./Pic/Set/5.png", 210, 370, 133, 17);
        now->putImage("./Pic/Set/6.png", 343, 370, 133, 17);
    }

    if (0.75 == now->getVolm2())
    {
        now->putImage("./Pic/Set/5.png", 210, 370, 133, 17);
        now->putImage("./Pic/Set/6.png", 343, 370, 133, 17);
        now->putImage("./Pic/Set/7.png", 476, 370, 133, 17);
    }

    if (1.00 == now->getVolm2())
    {
        now->putImage("./Pic/Set/5.png", 210, 370, 133, 17);
        now->putImage("./Pic/Set/6.png", 343, 370, 133, 17);
        now->putImage("./Pic/Set/7.png", 476, 370, 133, 17);
        now->putImage("./Pic/Set/8.png", 609, 370, 134, 17);
    }

    /*动画效果*/
    if (count < 10 && now->click != 0)
    {
        if (1 == now->click)
        {
            now->putImage("./Pic/Set/minus_.png", 395, 275, 50, 50);
        }

        if (2 == now->click)
        {
            now->putImage("./Pic/Set/plus_.png", 515, 275, 50, 50);
        }

        if (3 == now->click)
        {
            now->putImage("./Pic/Set/minus_.png", 395, 425, 50, 50);
        }

        if (4 == now->click)
        {
            now->putImage("./Pic/Set/plus_.png", 515, 425, 50, 50);
        }

        count++;
    }

    if (10 == count)
    {
        count = 0;
        now->click = 0;
    }
}

/**
 * @brief 判定鼠标操作
 *
 * @param x 鼠标点击的x
 * @param y 鼠标点击的y
 */
void SetScene::onMouse(Sint32 x, Sint32 y)
{
    if (x >= 395 && x <= 445 && y >= 275 && y <= 325)
    {
        now->decVolume(1);
        now->click = 1;
    }

    if (x >= 515 && x <= 565 && y >= 275 && y <= 325)
    {
        now->addVolume(1);
        now->click = 2;
    }

    if (x >= 395 && x <= 445 && y >= 425 && y <= 475)
    {
        now->decVolume(2);
        now->playSound(2, "./Sound/Touch.wav", 1);
        now->click = 3;
    }

    if (x >= 515 && x <= 565 && y >= 425 && y <= 475)
    {
        now->addVolume(2);
        now->playSound(2, "./Sound/Touch.wav", 1);
        now->click = 4;
    }

    if (x >= 455 && x <= 505 && y >= 560 && y <= 610)
    {
        now->scene = last;
        delete this;
    }
}

/**
 * @brief 鼠标移动功能
 *
 * @param x 当前鼠标的x
 * @param y 当前鼠标的y
 */
void SetScene::onMouseMotion(Sint32 x, Sint32 y)
{
    //pass
    //by wht
}