#pragma once
#include "Control.h"
/**
 * @brief 选关页面
 *
 * 六个关卡的选择
 */
class SelectScene : public Scene
{
    private:
        Scene *last = nullptr;
        int select = 0;
    public:
        /**
         * @brief Construct a new Select Scene object
         *
         * @param last_ 上个场景（主场景
         */
        SelectScene(Scene *last_);
        /**
         * @brief Destroy the Select Scene object
         *
         */
        ~SelectScene() = default;

        /**
         * @brief 更新画面
         *
         * 按顺序从底层到顶层逐一更新画面
         */
        void update()override;
        /**
         * @brief 判定鼠标操作
         *
         * 点击哪一关
         * @param x 鼠标点击的x
         * @param y 鼠标点击的y
         */
        void onMouse(Sint32 x, Sint32 y) override;
        /**
         * @brief 鼠标移动功能
         *
         * 判断移动到哪一关上方
         * @param x 当前鼠标的x
         * @param y 当前鼠标的y
         */
        void onMouseMotion(Sint32 x, Sint32 y) override;
};
