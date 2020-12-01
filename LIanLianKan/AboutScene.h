#pragma once
#include "Scene.h"

/**
 * @brief 关于界面
 *
 * 显示制作人员名单+帮助页面
 */
class AboutScene : public Scene
{
    private:
        Scene *last = nullptr;
        int point[12] = { 150, 1110, 1400, 2110, 2290, 3030, 3245, 3330, 3960, 3960, 4235, 4260 };
        int title[2] = { 290, 1250 };
        int count1 = 0;
        int count2 = 0;
    public:
        /**
         * @brief about页面计数器
         *
         */
        int about = 0;
        /**
         * @brief 关于页面页码
         *
         */
        int page = 1;
        /**
         * @brief 翻页动画是否已完成
         *
         */
        bool isDone = true;

        /**
         * @brief Construct a new About Scene object
         *
         * @param last_ 上一个场景（主场景）
         */
        AboutScene(Scene *last_);

        /**
         * @brief Destroy the About Scene object
         *
         */
        ~AboutScene() = default;

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