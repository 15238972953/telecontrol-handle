#ifndef KALMAN_H
#define KALMAN_H

#include "sys.h"

// ���忨�����˲����ṹ��
typedef struct {
    double q;  // ��������Э����
    double r;  // ��������Э����
    double x;  // ״̬����ֵ
    double p;  // �������Э����
    double k;  // ����������
}KalmanFilter;

void KalmanFilter_Init(KalmanFilter *kf, double q, double r, double initial_x, double initial_p);
double KalmanFilter_Update(KalmanFilter *kf, double measurement);

#endif

