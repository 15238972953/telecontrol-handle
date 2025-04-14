#include "kalman.h"



// 初始化卡尔曼滤波器
void KalmanFilter_Init(KalmanFilter *kf, double q, double r, double initial_x, double initial_p) {
    kf->q = q;
    kf->r = r;
    kf->x = initial_x;
    kf->p = initial_p;
		kf->k = 0;
}

// 卡尔曼滤波更新步骤
double KalmanFilter_Update(KalmanFilter *kf, double measurement) {
    // 预测步骤
    kf->p = kf->p + kf->q;

    // 计算卡尔曼增益
    kf->k = kf->p / (kf->p + kf->r);

    // 更新状态估计值
    kf->x = kf->x + kf->k * (measurement - kf->x);

    // 更新估计误差协方差
    kf->p = (1 - kf->k) * kf->p;

    return kf->x;
}
