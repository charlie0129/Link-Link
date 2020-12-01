#include "SelectScene.h"
#include "Control.h"
#include "GameScene.h"
extern Control *now;

/**
 * @brief Construct a new Select Scene object
 *
 * @param last_ 上个场景（主场景
 */
SelectScene::SelectScene(Scene *last_) : last{ last_ }
{
    now->scene = this;
}

/**
 * @brief 更新画面
 *
 * 按顺序从底层到顶层逐一更新画面
 */
void SelectScene::update()
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

    /*关卡图片*/
    now->putImage("./Pic/chooseTitle.png", 290, 20, 387, 111);
    now->putImage("./Pic/level/level1_.png", 96, 150, 192, 128);
    now->putImage("./Pic/level/level1.png", 96, 280, 254, 74);
    now->putImage("./Pic/level/level2_.png", 384, 150, 192, 128);
    now->putImage("./Pic/level/level3_.png", 672, 150, 192, 128);
    now->putImage("./Pic/level/level4_.png", 96, 380, 192, 128);
    now->putImage("./Pic/level/level5_.png", 384, 380, 192, 128);
    now->putImage("./Pic/level/level6_.png", 672, 380, 192, 128);
    now->putImage("./Pic/Set/home.png", 455, 585, 50, 50);

    /*选关边框*/
    if (1 == select)
    {
        now->putImage("./Pic/level/level_stroke.png", 90, 140, 210, 220);
    }

    if (2 == select)
    {
        now->putImage("./Pic/level/level_stroke.png", 378, 140, 210, 220);
    }

    if (3 == select)
    {
        now->putImage("./Pic/level/level_stroke.png", 666, 140, 210, 220);
    }

    if (4 == select)
    {
        now->putImage("./Pic/level/level_stroke.png", 90, 370, 210, 220);
    }

    if (5 == select)
    {
        now->putImage("./Pic/level/level_stroke.png", 378, 370, 210, 220);
    }

    if (6 == select)
    {
        now->putImage("./Pic/level/level_stroke.png", 666, 370, 210, 220);
    }

    /*解锁情况*/
    if (1 == now->level)
    {
        now->putImage("./Pic/level/lock.png", 420, 150, 120, 120);
        now->putImage("./Pic/level/lock.png", 708, 150, 120, 120);
        now->putImage("./Pic/level/lock.png", 132, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 420, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 708, 380, 120, 120);
        now->putImage("./Pic/level/locked.png", 384, 280, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 280, 254, 74);
        now->putImage("./Pic/level/locked.png", 96, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 384, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 510, 254, 74);
    }

    if (2 == now->level)
    {
        now->putImage("./Pic/level/lock.png", 708, 150, 120, 120);
        now->putImage("./Pic/level/lock.png", 132, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 420, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 708, 380, 120, 120);
        now->putImage("./Pic/level/level2.png", 384, 280, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 280, 254, 74);
        now->putImage("./Pic/level/locked.png", 96, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 384, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 510, 254, 74);
    }

    if (3 == now->level)
    {
        now->putImage("./Pic/level/lock.png", 132, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 420, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 708, 380, 120, 120);
        now->putImage("./Pic/level/level2.png", 384, 280, 254, 74);
        now->putImage("./Pic/level/level3.png", 672, 280, 254, 74);
        now->putImage("./Pic/level/locked.png", 96, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 384, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 510, 254, 74);
    }

    if (4 == now->level)
    {
        now->putImage("./Pic/level/lock.png", 420, 380, 120, 120);
        now->putImage("./Pic/level/lock.png", 708, 380, 120, 120);
        now->putImage("./Pic/level/level2.png", 384, 280, 254, 74);
        now->putImage("./Pic/level/level3.png", 672, 280, 254, 74);
        now->putImage("./Pic/level/level4.png", 96, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 384, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 510, 254, 74);
    }

    if (5 == now->level)
    {
        now->putImage("./Pic/level/lock.png", 708, 380, 120, 120);
        now->putImage("./Pic/level/level2.png", 384, 280, 254, 74);
        now->putImage("./Pic/level/level3.png", 672, 280, 254, 74);
        now->putImage("./Pic/level/level4.png", 96, 510, 254, 74);
        now->putImage("./Pic/level/level5.png", 384, 510, 254, 74);
        now->putImage("./Pic/level/locked.png", 672, 510, 254, 74);
    }

    if (now->level >= 6)
    {
        now->putImage("./Pic/level/level2.png", 384, 280, 254, 74);
        now->putImage("./Pic/level/level3.png", 672, 280, 254, 74);
        now->putImage("./Pic/level/level4.png", 96, 510, 254, 74);
        now->putImage("./Pic/level/level5.png", 384, 510, 254, 74);
        now->putImage("./Pic/level/level6.png", 672, 510, 254, 74);
    }
}

/**
 * @brief 判定鼠标操作
 *
 * 点击哪一关
 * @param x 鼠标点击的x
 * @param y 鼠标点击的y
 */
void SelectScene::onMouse(Sint32 x, Sint32 y)
{
    if (x >= 96 && x <= 288 && y >= 150 && y <= 280)
    {
        now->scene = new GameScene(last, 6, 5, 8, 1, false);
        delete this;
    }

    if (x >= 384 && x <= 576 && y >= 150 && y <= 280 && now->level >= 2)
    {
        now->scene = new GameScene(last, 8, 6, 9, 2, false);
        delete this;
    }

    if (x >= 672 && x <= 864 && y >= 150 && y <= 280 && now->level >= 3)
    {
        now->scene = new GameScene(last, 10, 7, 10, 3, true);
        delete this;
    }

    if (x >= 96 && x <= 288 && y >= 380 && y <= 510 && now->level >= 4)
    {
        now->scene = new GameScene(last, 12, 8, 12, 4, false);
        delete this;
    }

    if (x >= 384 && x <= 576 && y >= 380 && y <= 510 && now->level >= 5)
    {
        now->scene = new GameScene(last, 14, 9, 16, 5, false);
        delete this;
    }

    if (x >= 672 && x <= 864 && y >= 380 && y <= 510 && now->level >= 6)
    {
        now->scene = new GameScene(last, 16, 11, 20, 6, true);
        delete this;
    }

    if (x >= 455 && x <= 505 && y >= 585 && y <= 625)
    {
        now->scene = last;
        delete this;
    }
}

/**
 * @brief 鼠标移动功能
 *
 * 判断移动到哪一关上方
 * @param x 当前鼠标的x
 * @param y 当前鼠标的y
 */
void SelectScene::onMouseMotion(Sint32 x, Sint32 y)
{
    if (x >= 96 && x <= 288 && y >= 150 && y <= 354)
    {
        select = 1;
    }
    else if (x >= 384 && x <= 576 && y >= 150 && y <= 354)
    {
        select = 2;
    }
    else if (x >= 672 && x <= 864 && y >= 150 && y <= 354)
    {
        select = 3;
    }
    else if (x >= 96 && x <= 288 && y >= 380 && y <= 584)
    {
        select = 4;
    }
    else if (x >= 384 && x <= 576 && y >= 380 && y <= 584)
    {
        select = 5;
    }
    else if (x >= 672 && x <= 864 && y >= 380 && y <= 584)
    {
        select = 6;
    }
    else
    {
        select = 0;
    }
}