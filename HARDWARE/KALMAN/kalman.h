#ifndef KALMAN_H
#define KALMAN_H

#include "sys.h"

// 定义卡尔曼滤波器结构体
typedef struct {
    double q;  // 过程噪声协方差
    double r;  // 测量噪声协方差
    double x;  // 状态估计值
    double p;  // 估计误差协方差
    double k;  // 卡尔曼增益
}KalmanFilter;

void KalmanFilter_Init(KalmanFilter *kf, double q, double r, double initial_x, double initial_p);
double KalmanFilter_Update(KalmanFilter *kf, double measurement);

#endif

