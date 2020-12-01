#pragma once
#include"Scene.h"

/**
 * @brief 设置页面
 *
 * 设置音量大小
 */
class SetScene : public Scene
{
    private:
        Scene *last = nullptr;/*上一个页面*/
        int count = 0;/*计数器*/
    public:
        /**
         * @brief Set the Scene object
         *
         * @param last_ 来源页面
         */
        SetScene(Scene *last_);
        /**
         * @brief Destroy the Set Scene object
         *
         */
        ~SetScene() = default;

        /**
         * @brief 更新画面
         *
         * 按顺序从底层到顶层逐一更新画面
         */
        void update()override;
        /**
         * @brief 判定鼠标操作
         *
         * @param x 鼠标点击的x
         * @param y 鼠标点击的y
         */
        void onMouse(Sint32 x, Sint32 y) override;
        /**
         * @brief 鼠标移动功能
         *
         * @param x 当前鼠标的x
         * @param y 当前鼠标的y
         */
        void onMouseMotion(Sint32 x, Sint32 y) override;
};