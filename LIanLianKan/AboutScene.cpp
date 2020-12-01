#include "AboutScene.h"
#include "Control.h"
extern Control *now;

/**
 * @brief Construct a new About Scene object
 *
 * @param last_ 上一个场景（主场景）
 */
AboutScene::AboutScene(Scene *last_) : last{ last_ }
{
    now->scene = this;
}

/**
 * @brief 更新画面
 *
 * 按顺序从底层到顶层逐一更新画面
 */
void AboutScene::update()
{
    /*背景*/
    now->bgnow++;

    if (now->bgnow == 49)
    {
        now->bgnow = 0;
    }

    char *s = new char[50];
    sprintf_s(s, 50, "./Pic/bgvideo/bgvideo%02d.png", now->bgnow);
    now->putImage(s, 0, 0, 960, 640);
    delete[] s;

    /*图标*/
    now->putImage("./Pic/Set/home.png", 455, 560, 50, 50);
    now->putImage("./Pic/Set/bacward.png", 340, 560, 50, 50);
    now->putImage("./Pic/Set/forward.png", 565, 560, 50, 50);

    if (count1 < 10 && now->click != 0)
    {
        if (21 == now->click)
        {
            now->putImage("./Pic/Set/bacward_.png", 340, 560, 50, 50);
        }

        if (22 == now->click)
        {
            now->putImage("./Pic/Set/forward_.png", 564, 560, 50, 50);
        }

        count1++;
    }

    if (10 == count1)
    {
        count1 = 0;
        now->click = 0;
    }

    /*对于about的处理*/
    if (0 == about)
    {
        now->putImage("./Pic/about.png", title[0], 20, 387, 111);
        now->putImage("./Pic/help.png", title[1], 20, 387, 111);
        now->putImage("./Pic/about0.png", point[0], 200, 450, 325);
        now->putImage("./Pic/about1.png", point[1], 200, 320, 240);
        now->putImage("./Pic/aboutWords1.png", point[2], 150, 480, 320);
        now->putImage("./Pic/about2.png", point[3], 250, 225, 150);
        now->putImage("./Pic/aboutWords2.png", point[4], 150, 480, 320);
        now->putImage("./Pic/about3.png", point[5], 220, 175, 150);
        now->putImage("./Pic/about3.1.png", point[6], 250, 85, 100);
        now->putImage("./Pic/aboutWords3.png", point[7], 150, 480, 320);
        now->putImage("./Pic/about4.png", point[8], 140, 214, 176);
        now->putImage("./Pic/about4.2.png", point[9], 350, 214, 176);
        now->putImage("./Pic/about4.1.png", point[10], 280, 80, 100);
        now->putImage("./Pic/aboutWords4.png", point[11], 170, 480, 320);
    }

    if (1 == about)
    {
        for (int i = 0; i < 12; i++)
        {
            point[i] += 16;
        }

        if (1 == page)
        {
            for (int i = 0; i < 2; i++)
            {
                title[i] += 16;
            }

            now->putImage("./Pic/about.png", title[0], 20, 387, 111);
            now->putImage("./Pic/help.png", title[1], 20, 387, 111);
        }

        if (page >= 2)
        {
            now->putImage("./Pic/help.png", title[1], 20, 387, 111);
        }

        now->putImage("./Pic/about0.png", point[0], 200, 450, 325);
        now->putImage("./Pic/about1.png", point[1], 200, 320, 240);
        now->putImage("./Pic/aboutWords1.png", point[2], 150, 480, 320);
        now->putImage("./Pic/about2.png", point[3], 250, 225, 150);
        now->putImage("./Pic/aboutWords2.png", point[4], 150, 480, 320);
        now->putImage("./Pic/about3.png", point[5], 220, 175, 150);
        now->putImage("./Pic/about3.1.png", point[6], 250, 85, 100);
        now->putImage("./Pic/aboutWords3.png", point[7], 150, 480, 320);
        now->putImage("./Pic/about4.png", point[8], 140, 214, 176);
        now->putImage("./Pic/about4.2.png", point[9], 350, 214, 176);
        now->putImage("./Pic/about4.1.png", point[10], 280, 80, 100);
        now->putImage("./Pic/aboutWords4.png", point[11], 170, 480, 320);
        count2++;
    }

    if (2 == about)
    {
        for (int i = 0; i < 12; i++)
        {
            point[i] -= 16;
        }

        if (2 == page)
        {
            for (int i = 0; i < 2; i++)
            {
                title[i] -= 16;
            }

            now->putImage("./Pic/about.png", title[0], 20, 387, 111);
            now->putImage("./Pic/help.png", title[1], 20, 387, 111);
        }

        if (page > 2)
        {
            now->putImage("./Pic/help.png", title[1], 20, 387, 111);
        }

        now->putImage("./Pic/about0.png", point[0], 200, 450, 325);
        now->putImage("./Pic/about1.png", point[1], 200, 320, 240);
        now->putImage("./Pic/aboutWords1.png", point[2], 150, 480, 320);
        now->putImage("./Pic/about2.png", point[3], 250, 225, 150);
        now->putImage("./Pic/aboutWords2.png", point[4], 150, 480, 320);
        now->putImage("./Pic/about3.png", point[5], 220, 175, 150);
        now->putImage("./Pic/about3.1.png", point[6], 250, 85, 100);
        now->putImage("./Pic/aboutWords3.png", point[7], 150, 480, 320);
        now->putImage("./Pic/about4.png", point[8], 140, 214, 176);
        now->putImage("./Pic/about4.2.png", point[9], 350, 214, 176);
        now->putImage("./Pic/about4.1.png", point[10], 280, 80, 100);
        now->putImage("./Pic/aboutWords4.png", point[11], 170, 480, 320);
        count2++;
    }

    if (60 == count2)
    {
        count2 = 0;
        about = 0;
        isDone = true;
    }
}
/**
 * @brief 判定鼠标操作
 *
 * @param x 鼠标点击的x
 * @param y 鼠标点击的y
 */
void AboutScene::onMouse(Sint32 x, Sint32 y)
{
    if (x >= 455 && x <= 505 && y >= 560 && y <= 610 && isDone == true)
    {
        now->scene = last;
        delete this;
    }

    if (x >= 340 && x <= 390 && y >= 560 && y <= 610 && isDone == true && page > 1)
    {
        now->click = 21;
        about = 1;
        isDone = false;
        page--;
    }

    if (x >= 565 && x <= 615 && y >= 560 && y <= 610 && isDone == true && page < 5)
    {
        now->click = 22;
        about = 2;
        isDone = false;
        page++;
    }
}
/**
 * @brief 鼠标移动功能
 *
 * @param x 当前鼠标的x
 * @param y 当前鼠标的y
 */
void AboutScene::onMouseMotion(Sint32 x, Sint32 y)
{
}